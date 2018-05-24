#include "schedule.h"
#include <string>

void schedule::scheduleStart(ready_queue &r, unsigned int &tick, int algorithm){
	if (algorithm == 0) // FCFS
		FCFSStart(r, tick);

}

void schedule::nonPreemptiveSJFStart() {

}

void schedule::preemptiveSJFStart() {

}

void schedule::nonPreemptivePriorityStart() {

}

void schedule::preemptivePriorityStart() {

}

void schedule::FCFSStart(ready_queue &r, unsigned int &tick) {
	if (current_job == nullptr) {
		if (r.isEmpty()) {
			return;
		}
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
		progress.back()->time = tick;
		progress.back()->done_time = tick;
		current_job = nullptr;
		tick--;
		return;
	}
	else{
		progress.back()->time=tick;
	}

	current_job->bursted++;
}

void schedule::RRStart() {

}

void schedule::drawGanttChart() {
	list <job *> temp = progress;
	int cnt = 0;
	string a, b;

	a += "| ";
	b += "0";

	int last_time = 0; // for 0


	while (!temp.empty()) { // draw graph start
		job *p = temp.front();

		while (cnt > p->start_time) {
			a += " ";
			b += " ";
		}

		if (last_time != p->start_time) {
			a += "| ";
			b += to_string(p->start_time);
		}
		for (int i = 0; i < p->done_time; i++) {
			if (i == p->done_time / 2) {
				a += to_string(p->pid) + " ";
				b += "  ";
			}
			else {
				a += " ";
				b += " ";
			}
		}


		a += "| ";
		b += to_string(p->done_time);
		if (p->done_time < 9)
			b += " ";
		last_time = p->done_time;

		temp.pop_front();
	}
	cout << a << endl;
	cout << b << endl;

	/*
	temp = progress; // draw time start

	cout << "0";
	while (!temp.empty()) {
		job *p = temp.front();
		while (cnt < p->done_time) {
			if (cnt == p->start_time && last_time != p->start_time)
				cout << p->start_time << "  ";
			else
				cout << "  ";

			cnt++;
		}
		cout << p->done_time << "  ";
		last_time = p->done_time;
		temp.pop_front();
		cnt++;
	}
	cout << endl;
	*/
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