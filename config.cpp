#include "config.h"
#include <vector>

void ready_queue::addWaitingTime(process *except) {
	queue <process*> temp = q;
	QueueClear();

	while (!temp.empty()) {
		process *p = temp.front(); 
		if(p->pid != except->pid)
			p->waiting_time++;
		temp.pop();
		q.push(p);
	}
}

void ready_queue::deleteProcess(process *proc) {
	queue <process*> temp = q;
	QueueClear();

	while (!temp.empty()) {
		process *p = temp.front();
		if (p->pid != proc->pid)
			q.push(p);
		temp.pop();
	}
}

process &ready_queue::returnPriorityProcess() {
	process *p=nullptr;
	queue <process*> temp = q;
	queue <process*> temp2;

	if (q.empty()) return *p;

	p = q.front();


	while (true) {
		temp2.push(q.front());
		q.pop();
		if (q.empty())
			break;

		if (p->priority > q.front()->priority)
			p = q.front();
	}

	q = temp2;
	return *p;
}

void pushProcessReadyQueue(ready_queue &r, vector <process> p_list) {
	vector <process>::iterator iter;

	for (iter = p_list.begin(); iter != p_list.end(); iter++) {
		r.QueuePush(&(*iter));
	}
}

void ready_queue::popPriorityProcess(process p) {
	queue <process*> temp = q;
	queue <process*> temp2;

	while (!temp.empty()) {
		if (p.pid != temp.front()->pid)
			temp.pop();
		else {
			temp2.push(temp.front());
			temp.pop();
		}
	}
	q = temp;
}