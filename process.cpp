#include "process.h"
#include <iostream>
using namespace std;

void createProcess(vector <process> &p, int amount) {
	for (int i = 0; i < amount; i++) {
		process *proc = new process();
		p.push_back(*proc);
	}
}

void printProcess(vector <process> p_list) {
	vector <process>::iterator iter;

	for (iter = p_list.begin(); iter != p_list.end(); iter++) {
		cout << "pid : " << (*iter).pid << endl;
		cout << "arrive : " << (*iter).arrive << endl;
		cout << "burst : " << (*iter).cpu_burst << endl;
		cout << "priority : " << (*iter).priority << endl << endl;
	}
}