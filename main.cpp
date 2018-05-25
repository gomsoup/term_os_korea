#include <iostream>
#include <vector>
#include <thread>
#include "process.h"
#include "config.h"
#include "schedule.h"

using namespace std;

void scheduleStart(longterm_schedule ls, schedule s, ready_queue r) {
	for (int i = 0; i < 6; i++) { // 6 algorithms
		longterm_schedule temp = ls;
		schedule stemp = s;
		unsigned int tick = 0;

		while ( !(temp.isDone() && stemp.isDone(r)) ) {
			temp.pushReadyQueue(r, tick, i);
			stemp.scheduleStart(r, tick, i);
			tick++;
		}

		stemp.drawGanttChart();
		stemp.getAWT();
		stemp.getATT();
		cout << endl;

		ls.cleanQueue();
	}
}


int main(int argc, char* argv[]){
	if (argc < 2) {
		cout << "usage : ./term [process amount]" << endl;
		exit(0);
	}

	ready_queue r;
	vector <process*> p_list;
	srand(time(NULL));

	int p_num = atoi(argv[1]);

	// process create
	createProcess(p_list, p_num);
	printProcess(p_list);
	// scheduler create
	longterm_schedule ls(p_list);
	schedule s;
	// scheduling start
	scheduleStart(ls, s, r);

	return 0;
}

