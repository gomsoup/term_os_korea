#include <queue>
#include "process.h"

class ready_queue{
	queue <process> q;
	
	void ready_queue_push(process p){
		q.push(p);
	}

	void ready_queue_pop(){
		q.pop();
	}

	void ready_queue_clear(){
		while(!q.empty()){
			q.pop();
		}
	}
}

class waiting_queue{
	queue <process> q;
	
	void waiting_queue_push(process p){{
		q.push(p);
	}
	
	void waiting_queue_pop(){
		q.pop();
	}
	
	void waiting_queue_clear(){
		while(!q.empty()){
			q.pop();
		}
	}
}

