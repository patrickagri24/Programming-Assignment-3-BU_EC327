#include "Space_Station.h"
#include "Cart_Point.h"

#include <iostream>
using namespace std;


//constructors
Space_Station::Space_Station() : Game_Object('s')
{

  state = 'o';
  amount_moonstones = 0.0;
  number_astronauts = 0.0;

  cout << "Space_Station default constructed" << endl;
}

//next constructor
Space_Station::Space_Station(Cart_Point inputLoc, int inputId) : Game_Object(inputLoc, inputId, 's')
{
  id_num = inputId;
  location = inputLoc;
  state = 'o';
  amount_moonstones = 0;
  number_astronauts = 0;

  cout << "Space_Station constructed" << endl;
}

//Public functions
void Space_Station::deposit_moonstones(double deposit_amount)
{
  amount_moonstones = amount_moonstones + deposit_amount;

  //cout << amount_moonstones << endl;

  return;
}

//Adds astronaut
//Must come back later
bool Space_Station::add_astronaut()
{
  if(state == 'u')
  {
    number_astronauts++;
    return true;
  }
  
  else
  {
    return false;
  }
  
}




//returns number of astronauts
int Space_Station::get_astronauts()
{
  return number_astronauts;
}


//updates
bool Space_Station::update()
{
  if(amount_moonstones >= 10 && state != 'u')
    {
      state = 'u';
      display_code = 'S';
      
      cout << display_code << id_num << " has been upgraded" << endl;

      return true;
    }
  else
    {
      return false;
    }

}

//shows status
//come back to edit
void Space_Station::show_status()
{

  cout << "Space Station status: ";

  Game_Object::show_status();

  if(state == 'u' && display_code == 'S')
  {
	cout << " contains " << amount_moonstones << " moon stones and contains " << number_astronauts << " astronauts." << " Upgraded";
  }
  else
  { 
	cout << " contains " << amount_moonstones << " moon stones and contains " << number_astronauts << " astronauts." << " Not yet upgraded";
  }
  
  return;
}


//space destruct
void Space_Station::Space_destruc()
{

	cout << "Space_Station destructed" << endl;
 
  Game_Object::Game_Obj_destruc();

	return;
}









