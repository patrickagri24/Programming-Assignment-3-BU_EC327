#include <iostream>


#ifndef CART_VECTOR_H
#define CART_VECTOR_H



//Defines class
class Cart_Vector
{
 public:
  
  //Member variables
  double x;
  double y;

  //Default Constructor
  Cart_Vector();

  //Nondefault Constructor
  Cart_Vector(double, double);

};

//Multiplication operator overload
Cart_Vector operator*(Cart_Vector , double);

//Division operator overload
Cart_Vector operator/(Cart_Vector , double);

//Stream operator overload
std::ostream& operator<<(std::ostream &, Cart_Vector );







#endif

  
