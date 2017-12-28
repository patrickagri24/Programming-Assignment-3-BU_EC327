#include "Oxygen_Depot.h"
#include "Game_Object.h"
#include <iostream>

using namespace std;

//Defines default constructor
Oxygen_Depot::Oxygen_Depot():Game_Object('O')
{
  display_code = 'O';
  state = 'f';
  amount_oxygen = 50;

  cout << "Oxygen_Depot default constructed" << endl;
}

//Non default constructor
Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputId)  :  Game_Object(inputLoc, inputId, 'O')
{
  display_code = 'O';
  amount_oxygen = 50;
  state = 'f';
  id_num = inputId;
  location = inputLoc;

  cout << "Oxygen_Depot constructed" << endl;
}

//function for managing oxygen level
bool Oxygen_Depot::is_empty()
{
  if(amount_oxygen == 0.0)
    {
      return true;
    }
  else
    {
      return false;
    }
}

//for oxygen extraction
double Oxygen_Depot::extract_oxygen(double amount_to_extract)
{
  if(amount_oxygen > amount_to_extract)
    {
      amount_oxygen = amount_oxygen - amount_to_extract;
      
      //amount_oxygen = amount_to_extract;
      
      return amount_to_extract;
    }
  else 
    { 
      double testamt = amount_oxygen;
      amount_oxygen = 0.0;
      return testamt;
      
    }
}

//for updating
bool Oxygen_Depot::update()
{
  if(amount_oxygen == 0.0 && state != 'e')
    {
      state = 'e';
      display_code = 'o';
      cout << "Oxygen_Depot (" << id_num << ") has been depleted" << endl;
      return true;
    }
  else
    {
      return false;
    }
}

//for status update
void Oxygen_Depot::show_status()
{
  cout << "Oxygen Depot status: " << display_code << id_num << " at location ";
  cout << location;
  cout << " contains " << amount_oxygen << ".";

  return;
}




//ox destruct
void Oxygen_Depot::Ox_destruc()
{

	cout << "Oxygen_Depot destructed" << endl;
 
  Game_Object::Game_Obj_destruc();

	return;
}
	





