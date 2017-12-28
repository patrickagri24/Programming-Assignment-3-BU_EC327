#ifndef OXYGEN_DEPOT_H
#define OXYGEN_DEPOT_H

#include "Cart_Point.h"
#include "Game_Object.h"




class Oxygen_Depot: public Game_Object
{
  
//public member functions
 public:

  bool is_empty();

  double extract_oxygen(double amount_to_extract = 20.0);
  
  bool update();

  void show_status();  


  //Default constructor
  Oxygen_Depot();

  //Non default constructor
  Oxygen_Depot(Cart_Point , int);

  //destruct mock
  void Ox_destruc();



//private members
 private:

  double amount_oxygen;
 
 
  


};

#endif

  
