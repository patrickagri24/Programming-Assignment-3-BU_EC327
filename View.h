#ifndef VIEW_H
#define VIEW_H

#include "Game_Object.h"
#include "Cart_Point.h"

using namespace std;

//creates the class
class View
{
  //public members
  public:
  
  //default constructor
  View();
  
  void clear();
  
  void plot(Game_Object * ptr);
  
  void draw();
  
  static const int view_maxsize = 20;
  
  //private members
  private:
  
  int size;
  
  double scale;
  
  Cart_Point origin;
  
  char grid[view_maxsize][view_maxsize][2];
  
  bool get_subscripts(int&, int&, Cart_Point);
  
};

#endif  
  
  
  
  
  
  
  
  
  
  
  