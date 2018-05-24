#include <iostream>
#include <vector>
#include <thread>
#include "process.h"
#include "config.h"
#include "schedule.h"

using namespace std;


void scheduleStart(longterm_schedule ls, schedule s, ready_queue r) {
	for (int i = 0; i < 6; i++) {
		longterm_schedule temp = ls;
		schedule stemp = s;
		ready_queue rtemp = r;
		unsigned int tick = 0;

		while ( !(temp.isDone() && stemp.isDone(rtemp)) ) {
			temp.pushReadyQueue(rtemp, tick);
			stemp.scheduleStart(rtemp, tick, i);
			tick++;
		}

		stemp.drawGanttChart();
	}
}


int main(){
	ready_queue r;
	vector <process> p_list;
	srand(time(NULL));

	// process create
	createProcess(p_list, 5);
	// push ready queue
//	pushProcessReadyQueue(r, p_list);
	// scheduler create
	longterm_schedule ls(p_list);
	schedule s;

	scheduleStart(ls, s, r);
	//s.scheduleStart(r);
	// scheduling start
	// random i/o
	// scheduling done. get AWT, ATT
	getAWT(p_list);
	getATT(p_list);
	// draw Gantt chart

	return 0;
}

