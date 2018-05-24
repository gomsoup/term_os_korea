#include "config.h"
#include <vector>
void pushProcessReadyQueue(ready_queue &r, vector <process> p_list) {
	vector <process>::iterator iter;

	for (iter = p_list.begin(); iter != p_list.end(); iter++) {
		r.QueuePush(*iter);
	}
}

