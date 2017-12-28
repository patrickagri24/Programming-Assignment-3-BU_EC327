#include "Game_Command.h"
#include "Model.h"
#include "Cart_Point.h"
#include "Person.h"
#include "Astronaut.h"
#include "Oxygen_Depot.h"

#include <iostream>
#include "stdlib.h"
using namespace std;



//move function
void do_move(Model& model,int id, Cart_Point loc )
{
  //gets the person we NEED
	Person * astro = model.get_Person_ptr(id);
  char state = astro -> get_state();
 
  if(astro != 0 && state == 'l')
  {
    cout << "I can't move, I'm locked in!" << endl;
    return;
  }
  else if(astro != 0)
  {
    //checks location parameter
    Cart_Point out;
    out = astro -> get_location();

    if(out.x == loc.x  && out.y == loc.y)
    {
	      cout << "A1: I'm already there. See?" << endl;
        return;
    }

    astro -> start_moving(loc);
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }
  
}

//work a depot function
void do_work(Model& model,int id1,int id2)
{
  //gets the person and depot we NEED
	Person * astro = model.get_Person_ptr(id1);
  Oxygen_Depot * depot = model.get_Oxygen_Depot_ptr(id2);
 
  if(astro != 0 && depot != 0)
  {
    astro -> start_supplying(depot);
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }
}
  
  
//deposit moonstone function
void do_deposit(Model& model,int id1, int id2)
{
  //gets the person and station we NEED
	Person * astro = model.get_Person_ptr(id1);
  Space_Station * station = model.get_Space_Station_ptr(id2);
 
  if(astro != 0 && station != 0)
  {
    astro -> start_depositing(station);
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }

}
  
  
//stop command
void do_stop(Model& model,int id)
{
  //gets the person and station we NEED
  Person * astro = model.get_Person_ptr(id);

 
  if(astro != 0)
  {
    astro -> stop();
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }
  
}

//lock into station command
void do_lock(Model& model, int id1, int id2)
{
    //gets the person and station we NEED
	Person * astro = model.get_Person_ptr(id1);
  Space_Station * station = model.get_Space_Station_ptr(id2);
 
  if(astro != 0 && station != 0)
  {
    astro -> go_to_station(station);
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }

}

//go functin
void do_go(Model& model)
{
  cout << "Advancing one tick." << endl;  

  model.update();
  return;
}


//run function
void do_run(Model& model)
{
  cout << "Advancing to next event" << endl;

  for(int i = 0;i < 5;i++)
  {
    bool out = model.update();
    if(out == true)
    {
      goto finish;
    }
  }finish:
  
  return;
      
}


//quit program function
void do_quit(Model& model)
{
  int id1 = 1;
  int id2 = 2;
  
  cout << "Terminating program" << endl;
    
  Person * per1 = model.get_Person_ptr(id1);
  Person * per2 = model.get_Person_ptr(id2);
  
  per1 -> person_destruc();
  per2 -> person_destruc();
  
  
  Oxygen_Depot * depot1 = model.get_Oxygen_Depot_ptr(id1);
  Oxygen_Depot * depot2 = model.get_Oxygen_Depot_ptr(id2);
  
  depot1 -> Ox_destruc();
  depot2 -> Ox_destruc();
  
  
  Space_Station * station1 = model.get_Space_Station_ptr(id1);
  Space_Station * station2 = model.get_Space_Station_ptr(id2);
  
  station1 -> Space_destruc();
  station2 -> Space_destruc();
  
  cout << "Model destructed" << endl;
  
  

  exit(EXIT_SUCCESS);
  return;
}  

  
  
  


