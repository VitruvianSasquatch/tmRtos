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


bool process_isLast(Process_t *process);



Process_t *process_getNext(void);



/**
 * @brief Dynamically allocates and initialises a process. 
 * 
 * @param state The state the returned process should initially be in. 
 * @return Process_t* A pointer to a dynamically allocated and initialised process, or NULL if one could not be created.  
 */
Process_t *process_init(FsmState_t *state);


/**
 * @brief Appends @param process to the end of the list of processes. 
 * 
 * @param process A pointer to the process to be added. 
 */
void process_addEnd(Process_t *process);


/**
 * @brief Creates a new process and initialises it to the lowest priority. 
 * 
 * @param state The state the returned process should initially be in. 
 * @return Process_t* A pointer to the new process, or NULL if one could not be created. 
 */
Process_t *process_makeNew(FsmState_t *state);


/**
 * @brief Adds @param process to the list of processes immediately after @param location, retaining order in the rest of the list. 
 * 
 * @param process A pointer to the process to be added. 
 * @param location A pointer to the process to add @param process after. 
 */
void process_addAfter(Process_t *process, Process_t *location);


/**
 * @brief Creates a new process of priority immediately below that of @param parent. 
 * 
 * @param parent A pointer to the process being forked; the new process has a priority just below this. 
 * @param state The state the returned process should initially be in. 
 * @return Process_t* A pointer to the new process, or NULL if one could not be created. 
 */
Process_t *process_makeFork(Process_t *parent, FsmState_t *state);


/**
 * @brief Removes @param process from the list of processes and then frees its memory, retaining order in the rest of the list. 
 * 
 * @param process A pointer to the process to be removed/freed. 
 */
void process_remove(Process_t *process);



#endif //PROCESS_H