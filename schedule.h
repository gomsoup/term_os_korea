#include <queue>
#include <vector>
#include <list>
#include <iostream>
#include "process.h"
#include "config.h"
using namespace std;

#ifndef schedule_def
#define schedule_def

typedef struct {
	unsigned int pid;
	unsigned int time;
}job;

class schedule {
	/*
		how to make random i/o?
		shoud consider about preemptive.
		inheritence? 
		how can we manage scheduling queue?
		burst counter?
		preemptive?
	*/
	process *current_job;
	process *next_job;
	vector <process> p_list;
	list <job*> progress;

	void RRStart();
	void nonPreemptivePriorityStart();
	void preemptivePriorityStart();
	void FCFSStart(ready_queue r, unsigned int tick);
	void nonPreemptiveSJFStart();
	void preemptiveSJFStart();



public:
	void scheduleStart(ready_queue r,unsigned int tick); // call-by-value. we don't need reference every scheduling algorithm. 
};

class longterm_schedule {
	process *p;
	priority_queue<process, vector<process>, greater<process>> q;

public:

	longterm_schedule(vector <process> p_list) {
		vector <process>::iterator iter;

		for (iter = p_list.begin(); iter != p_list.end(); iter++) {
			q.push(*iter);
		}

	}

	void printQueue() {
		priority_queue<process, vector<process>, greater<process>> temp = q;
		process p;
		while (!q.empty()) {
			p = q.top();
			cout << p.arrive << endl;
			q.pop();
		}

	}


	void pushReadyQueue(ready_queue r);
};




#endif