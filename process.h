#include <vector>
using namespace std;

#ifndef process_def
#define process_def

static unsigned int pid_cnt = 0;

class process{
public:
	unsigned int pid;
	unsigned int cpu_burst;
	unsigned int io_burst;
	unsigned int arrive;
	unsigned int priority;
	unsigned int waiting_time;
	unsigned int done_time;

	process(){
		pid = pid_cnt + 1; pid_cnt++;
		cpu_burst = 0;
		io_burst = 0;
		arrive = 0;
		priority = 0;
		waiting_time = 0;
		done_time = 0;
	}

	process(const process& p) {
		pid = p.pid;
		cpu_burst = p.cpu_burst;
		io_burst = p.io_burst;
		arrive = p.arrive;
		priority = p.priority;
		waiting_time = p.waiting_time;
		done_time = p.done_time;
	}
	~process() {

	}
};

void createProcess(vector <process> p, int amount);
void getAWT(vector <process> p);
void getATT(vector <process> p);

#endif
