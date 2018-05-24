#include "schedule.h"

void schedule::scheduleStart(ready_queue &r, waiting_queue &q){
	FCFSStart();
	RRStart();
	nonPreemptivePriorityStart();
	preemptivePriorityStart();
	nonPreemptiveSJFStart();
	preemptiveSJFStart();
}

void nonPreemptiveSJFStart() {

}

void preemptiveSJFStart() {

}

void nonPreemptivePriorityStart() {

}

void preemptivePriorityStart() {

}

void FCFSStart() {

}

void RRStart() {

}
