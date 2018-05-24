#include <iostream>
#include <vector>
#include <thread>
#include "process.h"
#include "config.h"
#include "schedule.h"

using namespace std;

int main(){
	ready_queue r;
	vector <process> p_list;

	// process create
	createProcess(p_list, 5);
	// push ready queue
//	pushProcessReadyQueue(r, p_list);
	// scheduler create
	longterm_schedule ls(p_list);
	schedule s();

	ls.printQueue();


	//s.scheduleStart(r);
	// scheduling start
	// random i/o
	// scheduling done. get AWT, ATT
	getAWT(p_list);
	getATT(p_list);
	// draw Gantt chart

	return 0;
}

