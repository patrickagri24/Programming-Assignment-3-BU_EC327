#include "Astronaut.h"
#include "Cart_Point.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"


#include <iostream>
using namespace std;

//Default astronaut
Astronaut::Astronaut(): Person('A')
{
  amount_moonstones = 0;
  amount_oxygen = 20;
  
  this -> depot = NULL;
  this -> home = NULL;

  cout << "Astronaut default constructed" << endl;
}

//Non default astronaut
Astronaut::Astronaut(Cart_Point in_loc, int in_id): Person(in_loc, in_id, 'A')
{
  amount_moonstones = 0;
  amount_oxygen = 20;
  
  this -> depot = NULL;
  this -> home = NULL;
  
  cout << "Astronaut constructed" << endl;
}

//Update function
bool Astronaut::update()
{
  switch(state)
  {
    case 's':
      {
      return false;
      }
      
    case 'm':
      {         
        bool out = update_location();
        
        if(out == true)
        {
          state = 's';
         // amount_moonstones++;
         // amount_oxygen--;
          return true;
        }
        
        else
        {
          if(amount_oxygen == 0)
	      {
	        cout << "I can't move, I'm out of oxygen" << endl;
	        state = 'l';
	        return true;
	      }
	        amount_moonstones++;
          amount_oxygen--;
          return false;
        }
      }
    
    
    case 'o':
      {
        bool out = update_location();
        if(out == true)
        {
          state = 'g';
        //  amount_moonstones++;
         // amount_oxygen--;
          return true;
        }
        else
        {
          amount_moonstones++;
          amount_oxygen--;
          return false;
        }
      }
      
      
    case 'g':
      {
        double out = depot -> extract_oxygen();
      
        cout << display_code << id_num << ":  Got " << out << " more oxygen" << endl;
      
        Astronaut::amount_oxygen = Astronaut::amount_oxygen + out;
        
        state = 's';
            
        return true;
      }
        
    case 'i':
       {
         bool out = update_location();
         if(out == true)
         {
           state = 'd';
           //amount_moonstones++;
           //amount_oxygen--;
           return true;
         }
         else 
         {
           amount_moonstones++;
           amount_oxygen--;
           return false;
         }
    
      }
      
    case 'd':
      {
        cout << display_code << id_num << ": Deposit " << amount_moonstones << " moonstones" << endl;
        
        home -> deposit_moonstones(amount_moonstones);
        amount_moonstones = 0;
        
        state = 's';
        
        return true;
      }
      
    case 'l':
      {
        bool out = update_location();
        if(out == true)
        {
          //amount_moonstones++;
          //amount_oxygen--;
          int test = home -> get_astronauts();
          if(test == 0)
          {
            home -> add_astronaut();
            return true;
          }
        }
        else 
        {
          amount_moonstones++;
          amount_oxygen--; 
          return false;
        }
      }
      
  }
      
}

//starts supplying
//come back
void Astronaut::start_supplying(Oxygen_Depot* inputDepot)
{
  
  //makes depot point to input depot
  depot = inputDepot;

  Cart_Point location1 = (inputDepot -> get_location());
  setup_destination(location1);
  
  state = 'o';
  
  cout << "Astronaut " << id_num << " supplying from Oxygen Depot" << inputDepot -> get_id() << endl;
  
  cout << display_code << id_num << ": Yes, my lord" << endl;
  
}

//starts depositing
//come back 
void Astronaut::start_depositing(Space_Station* inputStation)
{

  //makes home point to input station
  home = inputStation;

  Cart_Point location1 = (inputStation -> get_location());
  setup_destination(location1);
  
  state = 'i';
  
  cout << "Astronaut" << id_num << " depositing to Space Station " << inputStation -> get_id() << endl;
  
  cout << display_code << id_num << ": Yes, my lord" << endl;
  
}

//go to station
void Astronaut::go_to_station(Space_Station* inputStation)
{
  
  //makes home point to input station
  home = inputStation;

  //Tell the astronaut to go to station
  Cart_Point location1 = (inputStation -> get_location());

  setup_destination(location1);

  cout << "Astonaut " << id_num << " locking into Space Station " << inputStation -> get_id() << endl;
  
  //Come back to add a point where the state gets changed to l
  state = 'l';
  
}


//getter for oxygen
double Astronaut::get_oxygen()
{
  return amount_oxygen;
}










//shows astronaut status
void Astronaut::show_status()
{

  cout << "Astonaut status: ";
  
  Person::show_status();
  
  
  
  //switch statement
  switch(state)
  {
  
    case 's':
    {
      cout << " is stopped with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones";
      break;
    }
    case 'm':
    {
      cout << " moving at speed of " << speed << " towards " << "(" << destination.x << "," << destination.y << ") at each step of <" << delta.x << "," << delta.y << ">";
      break;
    }
    case 'o':
    {
      cout << " moving at speed of " << speed << " towards (" << destination.x << "," << destination.y << ") at each step of <" << delta.x << "," << delta.y << "> is outbound to a Depot with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones.";
      break;
    }
    case 'g':
    {
      cout << " moving at speed of " << speed << " towards (" << destination.x << "," << destination.y << ") at each step of <" << delta.x << "," << delta.y << "> is getting oxygen from Depot.";
      break;
    }
    case 'i':
    {
      cout << " moving at speed of " << speed << " towards (" << destination.x << "," << destination.y << ") at each step of <" << delta.x << "," << delta.y << "> is outbound to home with load: " << amount_moonstones << " moon stones and " << amount_oxygen << " oxygen.";
      break;
    }
    case 'd':
    {
      cout << " moving at speed of " << speed << " towards (" << destination.x << "," << destination.y << ") at each step of <" << delta.x << "," << delta.y << "> is depositing " << amount_moonstones << " moon stones.";
      break;
    }
    case 'l':
    {
	if(amount_oxygen == 0)
	{      
	   cout << " is locked. Out of oxygen";
	}
	else
	{
	   cout << " is locked at Space Station";
	}
        break;
    }
  
  }
  return;
}
    
    

//astronaut destruct
void Astronaut::Ast_destruc()
{
 
	//Game_Object::Game_Obj_destruc();

	Person::person_destruc();
 
	cout << "Astronaut destructed" << endl;

	return;
}
      
     
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
