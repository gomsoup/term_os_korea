#include <queue>
#include <vector>
#include <list>
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
	unsigned int tick = 0;
	process *current_job;
	process *next_job;
	vector <process> p_list;
	list <job*> progress;

	void RRStart();
	void nonPreemptivePriorityStart();
	void preemptivePriorityStart();
	void FCFSStart(ready_queue r);
	void nonPreemptiveSJFStart();
	void preemptiveSJFStart();

public:
	schedule(vector <process> p_list) {
		this->p_list = p_list; // p_list may not disappear while program is running. shallow copy will be fine.
	}
	void scheduleStart(ready_queue r); // call-by-value. we don't need reference every scheduling algorithm. 
};


#endif