#include "common.h"
#include "fsm.h"

#include "process.h"



static Process_t *first = NULL;
static Process_t *last = NULL;
static size_t numProcesses = 0;
static Process_t *current = NULL;



bool process_isLast(Process_t *process)
{
	return process == last;
}



Process_t *process_getNext(void)
{
	Process_t *process = NULL;
	if (current = NULL) { //Handle empty list and error cases. 
		current = first;
		return first;
	} else {
		process = current;
		current = current->next;
	}
	return process;
}



Process_t *process_init(FsmState_t *state)
{
	Process_t *process = malloc(sizeof(Process_t));
	if (process) {
		process->isActive = true;
		process->state = state;
		process->next = NULL;
	}
	return process;
}


void process_addEnd(Process_t *process)
{
	if (length == 0) {
		first = last = process;
	} else {
		last->next = process;
		process->next = NULL;
		last = process;
	}
	length++;
}


Process_t *process_makeNew(FsmState_t *state)
{
	Process_t *process = process_init(state);
	if (process) {
		process_addEnd(process);
	}
	return process;
}


void process_addAfter(Process_t *process, Process_t *location)
{
	if (location == last) {
		last = process;
	}
	process->next = location->next;
	location->next = process;
	length++;
}


Process_t *process_makeFork(Process_t *parent, FsmState_t *state)
{
	Process_t *process = process_init(state);
	if (process) {
		process_addAfter(process, parent);
	}
	return process;

}


void process_remove(Process_t *process)
{
	if (process == first) {
		first = process->next;
	} else if (process == last) {
		last = process->prev;
		last->next = NULL;
	} else {
		process->prev->next = process->next;
	}
	free(process);
	length--;
}