#include "schedule.h"

void schedule::scheduleStart(ready_queue r, unsigned int tick){
/*	FCFSStart(r, tick);
	RRStart();
	nonPreemptivePriorityStart();
	preemptivePriorityStart();
	nonPreemptiveSJFStart();
	preemptiveSJFStart();
*/
}

void schedule::nonPreemptiveSJFStart() {

}

void schedule::preemptiveSJFStart() {

}

void schedule::nonPreemptivePriorityStart() {

}

void schedule::preemptivePriorityStart() {

}

void schedule::FCFSStart(ready_queue r, unsigned int tick) {
	while (!r.isEmpty()) {
		current_job = &r.q.front();
		r.QueuePop();


		for (int i = 0; i < current_job->cpu_burst; i++) {
			tick++;
			current_job->waiting_time++;
		}
		current_job->done_time = tick;

		job *temp = new job();
		temp->pid = current_job->pid;
		temp->time = tick;
		progress.push_back(temp);
	}

}

void schedule::RRStart() {

}


// long term scheduler

void longterm_schedule::pushReadyQueue(ready_queue r) {
	

}



void drawGattChart() {

}