#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include "Cart_Point.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"


//defines class
class Astronaut: public Person
{

  public:
  
    //default constructor
    Astronaut();
    
    //non default constructor
    Astronaut(Cart_Point,int);
    
    //public member functions
    bool update();
    
    void start_supplying(Oxygen_Depot*);
    
    void start_depositing(Space_Station*);
    
    void go_to_station(Space_Station*);
    
    void show_status();
    
    double get_oxygen();

    //virtual destructor
    void Ast_destruc();
    
    
  //private members
  private:
  
    double amount_moonstones;
    
    double amount_oxygen;
    
    Oxygen_Depot* depot;
    
    Space_Station* home;
    
    
    
};


#endif
