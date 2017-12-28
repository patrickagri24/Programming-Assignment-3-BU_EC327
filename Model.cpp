#include "Model.h"
#include "Game_Object.h"
#include "Person.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Cart_Point.h"
#include "Astronaut.h"
#include "stdlib.h"
#include "View.h"

#include <iostream>
using namespace std;

//Default constructor
Model::Model()
{
  time = 0;
  
  count_down = 10;
 
  //Makes astroanut  1
  Cart_Point one(5,1);
  int idOne = 1;

  Astronaut * Neilptr = new Astronaut(one, idOne);
 
  object_ptrs[0] = Neilptr;
  person_ptrs[0] = Neilptr;

  //Makes astronaut 2
  Cart_Point two(10,1);
  int idTwo = 2;

  Astronaut * Buzzptr = new Astronaut(two, idTwo);
  
  object_ptrs[1] = Buzzptr;
  person_ptrs[1] = Buzzptr;

  //Makes Oxygen Depot 1
  Cart_Point three(1,20);
  int idThree = 1;

  Oxygen_Depot * Moon1ptr = new Oxygen_Depot(three, idThree);

  object_ptrs[2] = Moon1ptr;
  depot_ptrs[0] =  Moon1ptr;


  //Makes Oxygen Depot 2
  Cart_Point four(10,20);
  int idFour = 2;

  Oxygen_Depot * Moon2ptr = new Oxygen_Depot(four, idFour);

  object_ptrs[3] = Moon2ptr;
  depot_ptrs[1] =  Moon2ptr;
  

  //Make space station 1
  Space_Station * Apollo = new Space_Station;

   

  object_ptrs[4] = Apollo;
  station_ptrs[0] = Apollo;
 

  //makes space station2
  Cart_Point five(5,5);
  int idFive = 2;
 
  Space_Station * Apollo11 = new Space_Station(five, idFive);

  object_ptrs[5] = Apollo11;
  station_ptrs[1] = Apollo11;

  //initializes other variables
  num_objects = 5;
  num_persons = 2;
  num_depots = 2;
  num_stations = 2;

  cout << "Model default constructed" << endl;
  
  

  
}


//Default destructor
Model::~Model()
{
  
  //deletes game object pointer
  for(int i = 0; i <= 5; i++)
    {
      delete object_ptrs[i];
    }

  //deletes person pointer
  for(int i = 0; i <= 1; i++)
    {
      delete person_ptrs[i];
    }

  //deletes depot pointer
  for(int i = 0; i <= 1; i++)
    {
      delete depot_ptrs[i];
    }

  //deletes station pointer
  for(int i = 0; i <= 1; i++)
    {
      delete station_ptrs[i];
    }

  

  cout << "Model destructed" << endl;
  
  


}


//gets person pointer
//come here for seg fault errors
Person * Model::get_Person_ptr(int id)
{
  //only two astronauts, so if id num is one, will return astronaut 1
  if(id == 1)
  {
    Person * astro1 = person_ptrs[0];
    return astro1;
  }
  else if(id == 2)
  {
    Person * astro1 = person_ptrs[1];
    return astro1;
  }
  else
  {
    return 0;
  }

}


//gets oxygen depot pointer
//come here for seg fault errors
Oxygen_Depot * Model::get_Oxygen_Depot_ptr(int id)
{
  //only two ox depots, so gets each specifically
  if(id == 1)
  {
    Oxygen_Depot * depot1 = depot_ptrs[0];
    return depot1;
  }
  else if(id == 2)
  {
    Oxygen_Depot * depot1 = depot_ptrs[1];
    return depot1;
  }
  else
  {
    return 0;
  }

}


//gets space station pointers
//come here for seg fault errors
Space_Station * Model::get_Space_Station_ptr(int id)
{
  //only two space stations, so will get each one
  if(id == 1)
  {
    Space_Station * station1 = station_ptrs[0];
    return station1;
  }
  else if(id == 2)
  {
    Space_Station * station1 = station_ptrs[1];
    return station1;
  }
  else
  {
    return 0;
  }
  
}




//update function
bool Model::update()
{
  //increments time and decrements count down
  time++;
  
  //defines variables we will use
  bool out1;
  bool out2;
  bool out3;
  bool out4;
  bool out5;
  bool out6;
  
  int station1_num;
  int station2_num;
  int counter = 0;
  
  double ox1;
  double ox2;
  
  //Manually updates all objects
  /*
  char st1 = object_ptrs[0] -> get_state();
  
  if(st1 == 'l')
  {
    goto next;
  }
  */
  out1 = object_ptrs[0] -> update();
  if(out1 == true){counter++;} 
  
  /*next:
  
  char st2 = object_ptrs[1] -> get_state();
  
  if(st2 == 'l')
  {
    goto next2;
  } 
  */
  out2 = object_ptrs[1] -> update(); 
  if(out2 == true){counter++;}
  
 // next2:
  out3 = object_ptrs[2] -> update();  
  if(out3 == true){counter++;}
  
  out4 = object_ptrs[3] -> update();  
  if(out4 == true){counter++;}
  
  out5 = object_ptrs[4] -> update();  
  if(out5 == true){counter++;}
  
  out6 = object_ptrs[5] -> update();  
  if(out6 == true){counter++;}
  
  //will see if stations are upgrades
  char id1 = station_ptrs[0] -> get_state();
  char id2 = station_ptrs[1] -> get_state();
  
  //seeing if both astronauts have oxygen
  ox1 = person_ptrs[0] -> get_oxygen();
  ox2 = person_ptrs[1] -> get_oxygen();
  
  if(ox1 == 0 && ox2 == 0)
  {
    cout << "Your astronauts are dead! You lose" << endl;
    exit(EXIT_SUCCESS);
  }
  
  //now performs necessary operations
  if(id1 == 'u' && id2 == 'u')
  {
    station1_num = station_ptrs[0] -> get_astronauts();
    station2_num = station_ptrs[1] -> get_astronauts();
    
    if(station1_num > 0 && station2_num > 0)
    {
      if(count_down >= 1)
      {
        cout << "Ready for takeoff? " << count_down << "..." << endl;
        cout << "Blast Off! You Win!" << endl;
        exit(EXIT_SUCCESS);
   	    return true;
      }
      else if(count_down < 1)
      {
        cout << "Unmanned takeoff... You lose!" << endl;
        exit(EXIT_SUCCESS);
      }
    }
    else
    {
      if(count_down < 1)
      {
        cout << "Unmanned takeoff... You lose!" << endl;
        exit(EXIT_SUCCESS);
      }
      
      cout << "Ready for takeoff? " << count_down << "..." << endl;
      cout << "Missing astronauts!" << endl;
      count_down--;
    }
  }
  
  //will evaluate whether or not to return true
  if(counter > 0)
  {
    return true;
  }
  else
  {
    return false;
  }
  
  
  
  
  
  

  
  /*
  //figure out where the count down goes
  //creates a counter for how many times update returns true, if is greater than zero, return true
  int counter = 0;
  
  for(int i = 0; i < num_objects; i++)
  {
    bool out = object_ptrs[i] -> update();
    if(out == 1)
    {
      counter++;
      for(int j = 0; j < num_stations; j++)
      {
        bool out2 = station_ptrs[0] -> Space_Station::update();
        bool out3 = station_ptrs[1] -> Space_Station::update();
        
        if(out2 == 1 && out3 == 1)
        {
          if(person_ptrs[0] -> get_state() == 'l' && person_ptrs[1] -> get_state() == 'l')
          {
            cout << "You win!" << endl;
            //return true;
            exit(EXIT_SUCCESS);
      	    return true;
          }
        }
      }
     // cout << "Something was upgraded" << endl;
    }
  }

  //checks to see if anything was updated
  if(counter > 0)
  {
	return true;
  }

  
  //returns false if found no true statements  
  return false;
  */  
    
}
  

//model display
void Model::display(View &view)
{

    
    view.clear();
    for(int i = 0; i < 6; i++)
    {
	
   	 view.plot(object_ptrs[i]);
    }

    //cout << "Time: " << time << endl;

    view.draw();

return;
}


//Shows status
void Model::show_status()
{

  cout << "Time: " << time << endl;

  for(int i = 0; i <= num_objects;i++)
  {
    object_ptrs[i] -> show_status();
    cout << endl;
  }
  
  
  return;


}












