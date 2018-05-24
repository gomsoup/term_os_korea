#include <queue>
#include "process.h"

using namespace std;

#ifndef config_def
#define config_def

class ready_queue{
public:

	queue <process> q;

	void QueuePush(process p){
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
};

class waiting_queue{
	queue <process> q;
	
	void QueuePush(process p){
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
};

void pushProcessReadyQueue(ready_queue &r, vector <process> p_list);


#endif