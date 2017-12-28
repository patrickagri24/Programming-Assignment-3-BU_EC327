#include "Cart_Vector.h"
#include <cmath>

//Default Constructor
Cart_Vector::Cart_Vector()
{
  x = 0.0;
  y = 0.0;
}

//Non default constructor
Cart_Vector::Cart_Vector(double inputx, double inputy)
{
  x = inputx;
  y = inputy;
}


//Nonmember overloaded multiplication operator
Cart_Vector operator*(Cart_Vector v1, double d)
{
  Cart_Vector result;
  
  result.x = v1.x * d;
  result.y = v1.y * d;

  return result;
}

//Nonmember overloaded division operator
Cart_Vector operator/(Cart_Vector v1, double d)
{
  Cart_Vector result;

  result.x = v1.x / d;
  result.y = v1.y / d;

  return result;
}


//Nonmember overloaded stream output operator
std::ostream& operator<<(std::ostream &os, Cart_Vector data_pt)
{
  
  os << "<" << data_pt.x << "," << data_pt.y << ">";

  return os;
}




