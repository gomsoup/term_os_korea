#include "schedule.h"

void schedule::scheduleStart(ready_queue &r, unsigned int tick, int algorithm){
	if (algorithm == 0) // FCFS
		FCFSStart(r, tick);

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

void schedule::FCFSStart(ready_queue &r, unsigned int tick) {
	if (current_job == nullptr) {
		if (r.isEmpty())
			return;
		else
			current_job = &r.q.front();
	}

	
	if (progress.empty() || progress.back()->pid != current_job->pid) {
		job *temp = new job();
		temp->pid = current_job->pid;
		temp->start_time = tick;
		progress.push_back(temp);
	}
	else if (current_job->bursted == current_job->cpu_burst) {
		r.QueuePop();
		current_job->done_time = tick;
		progress.back()->done_time = tick;
		current_job = nullptr;

		return;
	}
	else{
		progress.back()->time = tick;
	}

	current_job->bursted++;
}

void schedule::RRStart() {

}

void schedule::drawGanttChart() {
	while (!progress.empty()) {
		cout << "pid : " << progress.front()->pid << endl; // for debugging now
		cout << "done : " << progress.front()->done_time << endl;
		cout << endl;

		progress.pop_front();
	}


}


// long term scheduler

void longterm_schedule::pushReadyQueue(ready_queue &r, unsigned int tick) {
	while (!q.empty()) {
		process p = q.top();
		if (p.arrive == tick) {
			q.pop();
			r.QueuePush(p);
		}
		else
			return;
	}

}



void drawGattChart() {

}