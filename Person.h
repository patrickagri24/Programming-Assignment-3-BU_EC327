#ifndef PERSON_H
#define PERSON_H

#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"


//defines class
class Person: public Game_Object
{
  //makes astronaut a friend
  friend class Astronaut;
  public:
  
    //Default constructor
    Person();
    
    //Non-default constructor
    Person(char);
    
    //non-default constructor
    Person(Cart_Point, int, char);
    
    
    //Member functions
    void start_moving(Cart_Point);
    
    void stop();
    
    void show_status();
    
    //virtual classes
    virtual void start_supplying(Oxygen_Depot*);
    virtual void start_depositing(Space_Station*);
    virtual void go_to_station(Space_Station*);
    
    virtual double get_oxygen();
    
    void person_destruc();
    
    
    //now protected
  protected:
  
    bool update_location();
    
    void setup_destination(Cart_Point);
    
    
    //Now private
  private:
  
    double speed;
    
    
    Cart_Point destination;
    
    Cart_Vector delta;
    
};

#endif
    
    
    
