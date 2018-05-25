#include <queue>
#include "process.h"

using namespace std;

#ifndef config_def
#define config_def

class ready_queue{
public:
	queue <process*> q;

	ready_queue() {

	}

	ready_queue(const ready_queue& r) {
		queue <process*> temp = r.q;

		while (!temp.empty()) {
			process *p = new process(*temp.front());
			q.push(p);

			temp.pop();
		}
	}

	ready_queue& operator=(const ready_queue r) {
		q = r.q;
	}

	void QueuePush(process *p){
		q.push(p);
	}

	void QueuePop(){
		q.pop();
	}

	void QueueClear(){
		while(!q.empty()){
			q.pop();
		}
	}

	process *getFirstMember() {
		return q.front();
	}

	bool isEmpty(){
		return q.empty();
	}

	void addWaitingTime(process *except);
	process &returnPriorityProcess();
	process &returnRRProcess();
	void quantumZero();
	void popPriorityProcess(process p);
	void deleteProcess(process *p);
};

void pushProcessReadyQueue(ready_queue &r, vector <process> p_list);


#endif