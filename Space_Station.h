#ifndef SPACE_STATION_H
#define SPACE_STATION_H

#include "Cart_Point.h"
#include "Game_Object.h"

class Space_Station: public Game_Object
{

  //Public members
 public:
  
  void deposit_moonstones(double);

  bool add_astronaut();
  
  int get_astronauts();

  bool update();
  
  void show_status();


//Constructors
  Space_Station();

  Space_Station(Cart_Point , int);


  //mock space destruct
  void Space_destruc();

  //Private members
 private:

  double amount_moonstones;
  int number_astronauts;


  

 

};


#endif
