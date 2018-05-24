#include "config.h"
#include <vector>
void pushProcessReadyQueue(ready_queue &r, vector <process> p_list) {
	vector <process>::iterator iter;

	for (iter = p_list.begin(); iter != p_list.end(); iter++) {
		r.QueuePush(*iter);
	}
}

void ready_queue::addWaitingTime(process *except) {
	queue <process> temp = q;
	QueueClear();

	while (!temp.empty()) {
		process p = temp.front(); 
		if(p.pid != except->pid)
			p.waiting_time++;
		temp.pop();
		q.push(p);
	}
}
