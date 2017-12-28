#include "Cart_Point.h"
#include "Cart_Vector.h"

#include <iostream>

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H



class Game_Object
{

 //public members
 public:

  //Default operator
  Game_Object(char);

  //non -default
  Game_Object(Cart_Point , int, char);


//member functions
Cart_Point get_location();

int get_id();


char get_state();


virtual void show_status();

virtual bool update() = 0;

void drawself(char *);

//mock game object destructor
virtual void Game_Obj_destruc();



 protected:

  //Protected members
  Cart_Point location;

  int id_num;

  char display_code;

  char state;

 
  
};

#endif
