#include <queue>
#include "process.h"

using namespace std;

#ifndef config_def
#define config_def

class ready_queue{
public:
	queue <process> q;
	process last;

	void QueuePush(process p){
		q.push(p);
		last = q.front();
	}

	void QueuePop(){
		q.pop();
	}

	void QueueClear(){
		while(!q.empty()){
			q.pop();
		}
	}


	bool isEmpty(){
		return q.empty();
	}
};

void pushProcessReadyQueue(ready_queue &r, vector <process> p_list);


#endif