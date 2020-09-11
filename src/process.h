#ifndef PROCESS_H
#define PROCESS_H


#include "common.h"

#include "fsm.h"

typedef struct process_s Process_t;
typedef struct process_s {
	bool isActive;
	FsmState_t *state;
	Process_t *prev;
	Process_t *next;
};




/**
 * @brief Dynamically allocates and initialises a process. 
 * 
 * @param state The state the returned process should initially be in. 
 * @return Process_t* A pointer to a dynamically allocated and initialised process. 
 */
Process_t *process_init(FsmState_t *state);


/**
 * @brief Appends @param process to the end of the list of processes. 
 * 
 * @param process A pointer to the process to be added. 
 */
void process_addEnd(Process_t *process);


/**
 * @brief Adds @param process to the list of processes immediately after @param location, retaining order in the rest of the list. 
 * 
 * @param process A pointer to the process to be added. 
 * @param location A pointer to the process to add @param process after. 
 */
void process_addAfter(Process_t *process, Process_t *location);


/**
 * @brief Removes @param process from the list of processes and then frees its memory, retaining order in the rest of the list. 
 * 
 * @param process A pointer to the process to be removed/freed. 
 */
void process_remove(Process_t *process);



#endif //PROCESS_H