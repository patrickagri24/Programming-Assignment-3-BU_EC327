#include "Cart_Point.h"
#include "Cart_Vector.h"
#include <cmath>
using namespace std;

Cart_Point::Cart_Point()
{
  x = 0.0;
  y = 0.0;
}

Cart_Point::Cart_Point(double inputx, double inputy)
{
  x = inputx;
  y = inputy;
}

//Nonmember function
double cart_distance(Cart_Point p1, Cart_Point p2)
{
  double distance;

  //calculates distance using square root function
  distance = sqrt(pow( (p2.x - p1.x), 2) + pow( (p2.y -p1.y), 2 ) );

  return distance;

}


//Define overloaded << operator
ostream& operator<<(ostream &os, Cart_Point data_pt)
{
    
  os << "(" << data_pt.x << "," << data_pt.y << ")";

  return os;

}




//Define overloaded + operator
Cart_Point operator+(Cart_Point pt1, Cart_Vector pt2)
{
  //Defines result cart point
  Cart_Point result;

  result.x = pt1.x + pt2.x;

  result.y = pt1.y + pt2.y;

  return result;

}



//Define Overloaded Subtraction Operator
Cart_Vector operator-(Cart_Point pt1, Cart_Point pt2)
{

  //Defines result cart point
  Cart_Vector result;

  result.x = pt1.x - pt2.x;

  result.y = pt1.y - pt2.y;

  return result;

}
    

