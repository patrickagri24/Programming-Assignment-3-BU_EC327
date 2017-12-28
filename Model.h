#ifndef MODEL_H
#define MODEL_H

#include "Person.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Game_Object.h"
#include "Astronaut.h"
#include "Cart_Point.h"
#include "View.h"


//Model class
class Model
{
  //public members
  public:
    
    //Default constructor
    Model();
    
    //Default destructor
    ~Model();
    
    //Pointers
    Person * get_Person_ptr(int);
    
    Oxygen_Depot * get_Oxygen_Depot_ptr(int);
    
    Space_Station * get_Space_Station_ptr(int);
    
    bool update();
    
    //come back when can
   void display(View&);
   
   void show_status();
   
   
   //Private
   private:
   
   int time;
   
   int count_down;
   
   Game_Object * object_ptrs[10];
   
   int num_objects;
   
   Person * person_ptrs[10];
   
   int num_persons;
   
   Oxygen_Depot * depot_ptrs[10];
   
   int num_depots;
   
   Space_Station * station_ptrs[10];
   
   int num_stations;
   
   
};

#endif
   
   
   
