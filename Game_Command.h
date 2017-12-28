#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include "Model.h"
#include "Cart_Point.h"
#include "Person.h"
#include "Astronaut.h"
#include "Oxygen_Depot.h"

	//includes list of commands we need
	void do_move(Model&,int, Cart_Point);

	void do_work(Model&,int,int);

	void do_deposit(Model&,int,int);

	void do_stop(Model&, int);

	void do_lock(Model&,int,int);

	void do_go(Model&);

	void do_run(Model&);

	void do_quit(Model&);


#endif

