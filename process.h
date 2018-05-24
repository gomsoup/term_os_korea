#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef process_def
#define process_def

static unsigned int pid_cnt = 0;
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
		pid = pid_cnt + 1; pid_cnt++;
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
	}
	~process() {

	}

	bool operator> (const process& l) const {
		return arrive > l.arrive;
	}

};

void createProcess(vector <process> &p, int amount);
void deleteProcess(vector <process> &p);

#endif
