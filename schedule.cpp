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
	else if (algorithm == 1) { //non preemptive priority
		if (!start_flag) {
			start_flag = true;
			cout << "non preemptive priority Start!!" << endl;
		}
		nonPreemptivePriorityStart(r, tick);
	}
	else if (algorithm == 2) { // preemptive priority
		if (!start_flag) {
			start_flag = true;
			cout << "preemptive priority Start!!" << endl;
		}
		preemptivePriorityStart(r, tick);
	}
	else if (algorithm == 3) { // RR
		if (!start_flag) {
			start_flag = true;
			cout << "RR Start!!" << endl;
		}
		RRStart(r, tick);
	}
	else if (algorithm == 4) { // non preemptive SJF
		if (!start_flag) {
			start_flag = true;
			cout << "non preemptive SJF Start!!" << endl;
		}
		nonPreemptiveSJFStart(r, tick);
	}
	else if (algorithm == 5) { // preemptive SJF
		if (!start_flag) {
			start_flag = true;
			cout << "preemptive SJF Start!!" << endl;
		}
		preemptiveSJFStart(r, tick);
	}
}

void schedule::nonPreemptiveSJFStart(ready_queue &r, unsigned int &tick) {
	if (current_job == nullptr) {
		if (r.isEmpty()) {
			return;
		}
		else {
			current_job = &r.returnSJFProcess();
			if (current_job == nullptr) {
				return;

			}
		}
	}

	if (progress.empty() || progress.back()->pid != current_job->pid) {
		job *temp = new job();
		temp->pid = current_job->pid;
		temp->start_time = tick;
		progress.push_back(temp);
	}
	else if (current_job->bursted == current_job->cpu_burst) {
		r.deleteProcess(current_job);
		current_job->done_time = tick;
		progress.back()->time = tick;
		progress.back()->done_time = tick;
		done_process.push(*current_job);


		current_job = nullptr;
		tick--;
		return;
	}
	else {
		progress.back()->time = tick;
	}

	r.addWaitingTime(current_job);
	current_job->bursted++;
}

void schedule::preemptiveSJFStart(ready_queue &r, unsigned int &tick) {
	if (r.isEmpty())
		return;
	current_job = &r.returnSJFProcess();
	if (current_job == nullptr)
		return;
	else if (last_job != nullptr && current_job != last_job) {
		progress.back()->done_time = tick;
	}


	if (progress.empty() || progress.back()->pid != current_job->pid) {
		job *temp = new job();
		temp->pid = current_job->pid;
		temp->start_time = tick;
		progress.push_back(temp);
	}
	else if (current_job->bursted == current_job->cpu_burst) {
		r.deleteProcess(current_job);
		current_job->done_time = tick;
		progress.back()->time = tick;
		progress.back()->done_time = tick;
		done_process.push(*current_job);


		current_job = nullptr;
		tick--;
		return;
	}
	else {
		progress.back()->time = tick;
	}

	r.addWaitingTime(current_job);
	current_job->bursted++;
	last_job = current_job;
}

void schedule::nonPreemptivePriorityStart(ready_queue &r, unsigned int &tick){
	if (current_job == nullptr) {
		if (r.isEmpty()) {
			return;
		}
		else {
			current_job = &r.returnPriorityProcess();
			if (current_job == nullptr) {
				return;

			}
		}
	}

	if (progress.empty() || progress.back()->pid != current_job->pid) {
		job *temp = new job();
		temp->pid = current_job->pid;
		temp->start_time = tick;
		progress.push_back(temp);
	}
	else if (current_job->bursted == current_job->cpu_burst) {
		r.deleteProcess(current_job);
		current_job->done_time = tick;
		progress.back()->time = tick;
		progress.back()->done_time = tick;
		done_process.push(*current_job);


		current_job = nullptr;
		tick--;
		return;
	}
	else {
		progress.back()->time = tick;
	}

	r.addWaitingTime(current_job);
	current_job->bursted++;
}

void schedule::preemptivePriorityStart(ready_queue &r, unsigned int &tick) {
	if (r.isEmpty())
		return;
	current_job = &r.returnPriorityProcess();
	if (current_job == nullptr)
		return;
	else if (last_job != nullptr && current_job != last_job) {
		progress.back()->done_time = tick;
	}


	if (progress.empty() || progress.back()->pid != current_job->pid) {
		job *temp = new job();
		temp->pid = current_job->pid;
		temp->start_time = tick;
		progress.push_back(temp);
	}
	else if (current_job->bursted == current_job->cpu_burst) {
		r.deleteProcess(current_job);
		current_job->done_time = tick;
		progress.back()->time = tick;
		progress.back()->done_time = tick;
		done_process.push(*current_job);


		current_job = nullptr;
		tick--;
		return;
	}
	else {
		progress.back()->time = tick;
	}

	r.addWaitingTime(current_job);
	current_job->bursted++;
	last_job = current_job;
}

void schedule::FCFSStart(ready_queue &r, unsigned int &tick) {
	if (current_job == nullptr) {
		if (r.isEmpty()) {
			return;
		}
		else {
			current_job = r.getFirstMember();
		}
	}

	if (progress.empty() || progress.back()->pid != current_job->pid) {
		job *temp = new job();
		temp->pid = current_job->pid;
		temp->start_time = tick;
		temp->done_time = tick;
		progress.push_back(temp);
	}
	else if (current_job->bursted == current_job->cpu_burst) {
		r.deleteProcess(current_job);
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

void schedule::RRStart(ready_queue &r, unsigned int &tick) {
	if (r.isEmpty())
		return;

	if (current_job != nullptr && current_job->quantum >= quantum && current_job->cpu_burst != current_job->bursted) {
		progress.back()->done_time = tick;
		r.deleteProcess(current_job);
		r.QueuePush(current_job);

		current_job = &r.returnRRProcess();
	}
	else if (current_job == nullptr)
		current_job = &r.returnRRProcess();
	
	if (current_job == nullptr)
		return;

	if (progress.empty() || progress.back()->pid != current_job->pid) {
		job *temp = new job();
		temp->pid = current_job->pid;
		temp->start_time = tick;
		progress.push_back(temp);
	}
	else if (current_job->bursted == current_job->cpu_burst) {
		r.deleteProcess(current_job);
		current_job->done_time = tick;
		progress.back()->time = tick;
		progress.back()->done_time = tick;
		done_process.push(*current_job);


		current_job = nullptr;
		tick--;
		return;
	}
	else {
		progress.back()->time = tick;
	}

	r.addWaitingTime(current_job);
	current_job->bursted++;
	current_job->quantum++;
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

	cout << "Total Waiting Time : " << wt << endl;
	cout << "Average Waiting Time : " << (double)wt / cnt << endl;
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

	cout << "Total Turnarund Time : " << tt << endl;
	cout << "Average Turnaround Time : "  << (double)tt / cnt << endl;
}

void schedule::drawGanttChart()
{
	int i, j, n = 10;
	list <job*> temp = progress;
	job *p;

	while (!temp.empty()) { // top bar
		p = temp.front();
		temp.pop_front();

		for (int i = p->start_time; i < p->done_time; i++) cout << ("--");
		cout << " ";
	}
	cout << endl << "|";

	temp = progress;
	while (!temp.empty()) {
		p = temp.front();
		temp.pop_front();

		for (int i = p->start_time; i < p->done_time - 1; i++) cout << " ";
		cout << "P" << p->pid;
		for (int i = p->start_time; i < p->done_time - 1; i++) cout << " ";
		cout << "|";
	}
	cout << endl;

	temp = progress;
	while (!temp.empty()) {
		p = temp.front();
		temp.pop_front();

		for (int i = p->start_time; i < p->done_time; i++) cout << "--";
		cout << " ";
	}
	cout << endl;


	temp = progress;
	cout << "0";
	int last= 0;
	while (!temp.empty()) {
		p = temp.front();
		temp.pop_front();
		
		if (last != p->start_time) {
			for (int i = last; i < p->start_time; i++)cout << " ";
			cout << p->start_time;
			for (int i = p->start_time; i < p->done_time; i++) cout << "  ";
			if (p->done_time > 9) cout << "\b";
			cout << p->done_time;
		}
		else {
			for (int i = p->start_time; i < p->done_time; i++) cout << "  ";
			cout << p->done_time;
		}
		last = p->done_time;
	}
	cout << endl;

}

// long term scheduler

void longterm_schedule::pushReadyQueue(ready_queue &r, unsigned int tick, int algorithm) {
	queue<process*> temp = q;
	queue<process*> temp2;
	while (!temp.empty()) {
		process *p = temp.front();
		if (p->arrive == tick) {
			temp.pop();
			r.QueuePush(p);
		}
		else {
			temp2.push(temp.front());
			temp.pop();
		}
	}

	q = temp2;
}

void longterm_schedule::cleanQueue() {
	queue<process*> temp;
	
	while (!q.empty()) {
		process *p = q.front();
		p->bursted = 0;
		p->waiting_time = 0;
		p->done_time = 0;

		temp.push(p);
		q.pop();
	}

	q = temp;
}
