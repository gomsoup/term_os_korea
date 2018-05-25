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
	unsigned int start_time;
	unsigned int time;
	unsigned int done_time;
}job;

class schedule {
	process *current_job = nullptr;
	process *last_job = nullptr;
	queue <process> done_process; //for get AWT, ATT
	list <job*> progress;
	bool start_flag = false;

	void RRStart();
	void nonPreemptivePriorityStart(ready_queue &r, unsigned int &tick);
	void preemptivePriorityStart(ready_queue &r, unsigned int &tick);
	void FCFSStart(ready_queue &r, unsigned int &tick);
	void nonPreemptiveSJFStart();
	void preemptiveSJFStart();

public:
	void scheduleStart(ready_queue &r,unsigned int &tick, int algorithm); // call-by-value. we don't need reference every scheduling algorithm. 
	void drawGanttChart();
	bool isDone(ready_queue r) {
		return r.isEmpty();
	}
	void getATT();
	void getAWT();
};

class longterm_schedule {
	process *p;
	queue <process*> q;
	//priority_queue<process*, vector<process*>, greater<process*>> q;
	priority_queue<process, vector<process>, less<process>> priority_q;

public:

	longterm_schedule(vector <process*> p_list) {
		vector <process*>::iterator iter;

		for (iter = p_list.begin(); iter != p_list.end(); iter++) {
			q.push((*iter));
	//		priority_q.push(*iter);
		}

	}

	bool isDone(int algorithm) {
		if (algorithm <= 2) {
			return q.empty();
		}
	}

	void pushReadyQueue(ready_queue &r, unsigned int tick, int algorithm);
	void cleanQueue();
};




#endif