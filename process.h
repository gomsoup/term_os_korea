#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef process_def
#define process_def

static int pid_count = 1; // constructor 

class process{
public:
	unsigned int pid;
	unsigned int cpu_burst;
	unsigned int arrive;
	unsigned int priority;
	unsigned int waiting_time;
	unsigned int done_time;
	unsigned int bursted;

	process(){
		pid = pid_count++;
		cpu_burst = rand()%2 + 1;
		bursted = 0;
		arrive = rand()%5;
		priority = rand()%5 + 1;
		waiting_time = 0;
		done_time = 0;
	}

	process(const process& p) {
		pid = p.pid;
		cpu_burst = p.cpu_burst;
		arrive = p.arrive;
		priority = p.priority;
		waiting_time = p.waiting_time;
		done_time = p.done_time;
		bursted = p.bursted;
		pid_count--;
	}
	~process() {

	}

	process& operator= (const process &p) {
		pid = p.pid;
		cpu_burst = p.cpu_burst;
		arrive = p.arrive;
		priority = p.priority;
		waiting_time = p.waiting_time;
		done_time = p.done_time;
		bursted = p.bursted;
	}

	bool operator> (const process& l) const { // for FIFO
		return arrive > l.arrive;
	}

	bool operator< (const process& l) const {
		return priority > l.priority;
	}

};

void createProcess(vector <process> &p, int amount);
void printProcess(vector <process> p_list);

#endif
