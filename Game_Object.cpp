#include "Game_Object.h"
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include <iostream>

using namespace std;

//Default Constructor
Game_Object::Game_Object(char in_code)
{
  display_code = in_code;
  id_num = 1;
  state = 's';

  cout << "Game_Object constructed" << endl;
}

//Non Default Constructor
Game_Object::Game_Object(Cart_Point in_loc, int in_id, char in_code)
{
  location = in_loc;
  id_num = in_id;
  display_code = in_code;
  state = 's';

  cout << "Game_Object constructed" << endl;
}



//Member functions
Cart_Point Game_Object::get_location()
{
    return location;
}


int Game_Object::get_id()
{
    return id_num;
}


char Game_Object::get_state()
{
    return state;
}

//virtual show status
void Game_Object::show_status()
{
    std::cout << display_code << id_num << " at " << location;

    return;
}


//virtual update function 
bool Game_Object::update()
{



}


//draw self
void Game_Object::drawself(char * ptr)
{

  *(ptr) = display_code;
  *(ptr + 1) = '0' + id_num;
 
 // cout << *(ptr) << endl;
  
  //if to find id numbers
 /*
  if(id_num == 1)
  {
    ptr[1] = '1';
  }
  else if(id_num == 2)
  {
    ptr[1] = '2';
  } */
  
  
  return;

}

//Mock game object destructor
void Game_Object::Game_Obj_destruc()
{
	cout << "Game_Object destructed" << endl;
	return;
}






