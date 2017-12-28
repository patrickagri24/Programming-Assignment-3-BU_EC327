#include <iostream>
#include <cmath>
#include "stdlib.h"
#include <string>


#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "Model.h"
#include "Game_Command.h"
#include "View.h"

using namespace std;

int main()
{

//outputs the main header
cout << "EC327: Introduction to Software Engineering" << endl;
cout << "Fall 2017" << endl;
cout << "Programming Assignment 3" << endl;



//Begins the game
Model model;
View view;

//creates all the variables we will need
char code;
int id1;
int id2;
double locationx;
double locationy;
Cart_Point locationMain;



//shows all the statuses

model.show_status();
model.display(view);

//creates do while loop, will have dummy variable that will not change so loop will keep iterating
int dummy = 1;
while(dummy == 1)
{
	cout << "Enter command: ";
	cin >> code;

	//generates switch statement for whatever is inputted
	switch(code)
	{
		case 'm':
		{
		  cin >> id1 >> locationx >> locationy;

		  locationMain.x = locationx;
		  locationMain.y = locationy;

		  do_move(model,id1, locationMain);
	 	  model.display(view);
	
		  break;
		}
		case 'w':
		{
		  cin >> id1 >> id2;

		  do_work(model,id1,id2);

		  model.display(view);

		  break;
		}
		case 'd':
		{
		  cin >> id1 >> id2;

		  do_deposit(model,id1,id2);

		  model.display(view);
		
		  break;
		}
		case 's':
		{
		  cin >> id1;

		  do_stop(model,id1);

      model.display(view);

		  break;
		}
		case 'l':
		{
		  cin >> id1 >> id2;

		  do_lock(model,id1,id2);

		  model.display(view);

		  break;
		}
		case 'g':
		{
		  do_go(model);

		  model.show_status();
		  
		  model.display(view);

		  //do_go(model);

		  break;
		}
		case 'r':
		{
		  do_run(model);

		  model.show_status();

		  model.display(view);

      

		  break;
		}
		case 'q':
		{
		  
		  do_quit(model);
		  break;
		}

	}

	//cout << "Enter command: ";
	//cin >> code;


}


return 0;
}
