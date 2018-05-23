#ifndef process_def
#define process_def

class process{
	unsigned int pid;
	unsigned int cpu_burst;
	unsigned int io_burst;
	unsigned int arrive;
	unsigned int priority;
	
	process(){
		pid = 0;
		cpu_burst = 0;
		io_burst = 0;
		arrive = 0;
		priority = 0;
	}

};

#endif
