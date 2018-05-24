#include "process.h"

void createProcess(vector <process> &p, int amount) {
	for (int i = 0; i < amount; i++) {
		process *proc = new process();
		p.push_back(*proc);
	}
}