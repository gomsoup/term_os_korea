#include "schedule.h"
#include <string>

void schedule::scheduleStart(ready_queue &r, unsigned int &tick, int algorithm){
	if (algorithm == 0) { // FCFS
		if (!start_flag) {
			start_flag = true;
			cout << "FCFS Start!!" << endl;
		}
		FCFSStart(r, tick);
	}
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
		else {
			current_job = &r.getFirstMember();
		}
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
		done_process.push(*current_job);


		current_job = nullptr;
		tick--;
		return;
	}
	else{
		progress.back()->time=tick;
	}
	
	r.addWaitingTime(current_job);
	current_job->bursted++;
}

void schedule::RRStart() {

}

void schedule::getAWT() {
	queue <process> temp = done_process;
	int wt = 0; int cnt = 0;
	process p;
	while (!temp.empty()) {
		p = temp.front();
		wt += p.waiting_time;
		
		temp.pop();
		cnt++;
	}

	cout << "AWT : " << (double)wt / cnt << endl;
}

void schedule::getATT() {
	queue <process> temp = done_process;
	int tt = 0; int cnt = 0;
	process p;

	while (!temp.empty()) {
		p = temp.front();
		tt = tt + p.done_time - p.arrive;

		temp.pop();
		cnt++;
	}

	cout << "ATT : " << (double)tt / cnt << endl;
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

		while (cnt < p->start_time) {
			a += " ";
			b += " ";
			cnt++;
		}

		if (last_time != p->start_time) {
			a += "| ";
			b += to_string(p->start_time);
		}
		for (int i = 0; i < p->done_time; i++) {
			if (i == p->done_time / 2) {
				a += to_string(p->pid) + " ";
				b += " ";
			}
			else {
				a += " ";
				b += " ";
			}
		}


		a += "| ";
		if (p->done_time > 9)
			a += " ";

		b += to_string(p->done_time);
		if (p->done_time < 9)
			b += " ";
		last_time = p->done_time;

		temp.pop_front();
	}
	cout << a << endl;
	cout << b << endl;
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