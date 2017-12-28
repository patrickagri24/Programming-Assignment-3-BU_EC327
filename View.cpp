#include "View.h"
#include "Game_Object.h"
#include "Cart_Point.h"

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

//default constructor
View::View() 
{
  size = 11;
  
  scale = 2;
  
  origin.x = 0;
  origin.y = 0;
  

}

//member function
void View::clear()
{
  
   //creates empty board
   for(int i = size; i > 0;i--)
   {
     for(int j = 0; j < size;j++)
     {
       grid[i][j][0] = '.';
       grid[i][j][1] = ' ';
     }
     //cout << endl;
   }
   

return;
}


//get subscripts
bool View::get_subscripts(int& ix,int& iy, Cart_Point location)
{

  //dummy variables
  double x;
  double y;

  //calculates ix and iy
  x = ((location.x - origin.x)/scale);
  y = ((location.y - origin.y)/scale);

  
  //casts to integers
  ix = static_cast<int>(x);
  iy = static_cast<int>(y);

 // cout << ix << endl;
 // cout << iy << endl;
  
  //checks to see if true
  if(origin.x <= ix && ix <= origin.x + (size-1) && origin.y <= iy && iy <= origin.y + (size - 1))
  {
    return true;
  }
  else //if(origin.x < ix < scale*size || origin.y < iy < scale*size)
  {
    cout << "An object is outside the display" << endl;
    return false;
  }

}





//plot function
void View::plot(Game_Object * ptr)
{
  //ints we need, set to default
   int ix = 0;
   int iy = 0;

 
   
   bool out = get_subscripts(ix,iy,ptr -> get_location());
  // cout << ix << endl;
  // cout << iy << endl;
   
   if(out == true && grid[iy+1][ix][0] == '.')
   {
     ptr -> drawself(grid[iy+1][ix]);
    
     return;
   }
   else if(out == true)
   {
      	grid[iy+1][ix][0] = '*';
        grid[iy+1][ix][1] = ' ';

  	return;
   }
  
}


//draw function
void View::draw()
{
  int scale = 20;
  for(int i = size; i > 0;i--)
   {
     if(scale < 10)
     {
	cout << scale << "   ";
	goto next;
     } 	
     cout << scale << "  ";
     next: scale = scale -2;
     
     for(int j = 0; j < size;j++)
     {
      
       cout << grid[i][j][0] << grid[i][j][1];
     
     }
     cout << endl;
   }
   cout << "   0 " << "  4 "<< "  8 " <<  "  12 " <<  " 16 " << " 20 ";
   cout << endl << endl;
   

  return;
  
}




