#include <iostream>
#include <cmath>
#include "Cart_Vector.h"

#ifndef CART_POINT_H
#define CART_POINT_H



class Cart_Point
{
  //Declares Public
  public:
  
  double x;
  double y;
  
  
  //Default constructor
  Cart_Point();

  
  //Non- default constructor
  Cart_Point (double, double);

};

//Nonmember function
double cart_distance(Cart_Point , Cart_Point );

//Overloaded << operator
std::ostream& operator<<(std::ostream &, Cart_Point );


//Overloaded addition operator
Cart_Point operator+(Cart_Point , Cart_Vector );


//Overload subtraction operator
//will not work until cart vector is made
Cart_Vector operator-(Cart_Point , Cart_Point );





#endif
