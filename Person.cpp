#include "Person.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"


#include <iostream>
#include <cmath>
using namespace std;

//Default constructor
Person:: Person(): Game_Object('P')
{
  speed = 5.0;
  
  cout << "Person default constructed" << endl;
}


//Non default one
Person:: Person(char in_code): Game_Object('P')
{
  speed = 5.0;
  state = 's';
  display_code = in_code;
  
  cout << "Person constructed" << endl;
  
}

//Non default two
Person:: Person(Cart_Point in_loc, int in_id, char in_code): Game_Object(in_loc, in_id, 'P')
{
  speed = 5.0;
  display_code = in_code;
  location = in_loc;
  id_num = in_id;
  
  
  cout << "Person constructed" << endl;
  
}

//NOT DONE
void Person::start_moving(Cart_Point dest)
{

  //sets up destination
  setup_destination(dest);

  


  state = 'm';
  
  cout << "Moving " << id_num << " to " << destination << endl;
  cout << display_code << id_num << ": On my way." << endl;
  
  return;
}


//stop NOT DONE
void Person::stop()
{
  state = 's';
  
  cout << "Stopping " << id_num << endl;
  cout << display_code << id_num << ": All right" << endl;
  
  return;
  
}

//shows person status
void Person::show_status()
{
  //shows game object show status
  Game_Object::show_status();
  
/*
  if(state == 's')
  {
    cout << " is stopped";
  }
  else if(state == 'l')
  {
    cout << " is locked";
  }
  else
  {
     cout << " speed is: " << speed << "  destination is: " << destination << "  delta is: " <<     delta;
  }
  */
  
}



//updates location
//check equations
bool Person::update_location()
{
  if((abs(destination.x - location.x) <= abs(delta.x)) && (abs(destination.y - location.y) <= abs(delta.y)))
  {
    location.x = destination.x;
    location.y = destination.y;
    
    cout << display_code << id_num << ": I'm there!" << endl;
    
    return true;
  }
 
  else 
  {
    location.x = location.x + delta.x;
    location.y = location.y + delta.y;
    
  
    
    cout << display_code << id_num << ": step..." << endl;
    return false;
  }
  
  
}

//Setup destination
void Person::setup_destination(Cart_Point dest)
{
  
   destination = dest;
   
   delta = ((destination - location ) * (speed / cart_distance(destination, location)));
  
  
 return; 
}

//Virtual functions
void Person::start_supplying(Oxygen_Depot*)
{
  cout << "Sorry, I can't work a depot" << endl;
  
  return;
}

void Person::start_depositing(Space_Station*)
{
  cout << "Sorry, I can't work a station" << endl;

  return;
}

void Person::go_to_station(Space_Station*)
{
  cout << "Sorry, I can't lock into a station" << endl;
  
  return;
}

  
double Person::get_oxygen()
{
  cout << "Sorry, I have no oxygen" << endl;
  
  return 10.0;
}  

  
//virutal person destruc
void Person::person_destruc()
{

  cout << "Astronaut destructed" << endl;

	cout << "Person destructed" << endl;
 
  Game_Object::Game_Obj_destruc();
	
	return;
}





  
  
  
