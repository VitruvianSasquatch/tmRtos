#include "common.h"
#include "fsm.h"

#include "process.h"



static Process_t *first = NULL;
static Process_t *last = NULL;
static size_t length = 0;



Process_t *process_init(FsmState_t *state)
{
	Process_t *process = malloc(sizeof(Process_t));
	process->isActive = true;
	process->state = state;
	process->next = NULL;
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


void process_addAfter(Process_t *process, Process_t *location)
{
	if (location == last) {
		last = process;
	}
	process->next = location->next;
	location->next = process;
	length++;
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