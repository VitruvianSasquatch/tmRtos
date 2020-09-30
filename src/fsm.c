#include "common.h"
#include "process.h"
#include "fsm.h"



void fsm_run(Fsm_t *fsm, FsmState_t *startState)
{
	Process_t *process = process_makeNew(startState);
	assert(process); //TODO: Make better error handling. 

	while ((process = process_getNext()) != NULL) {
		if (process->isActive) {
			fsm_stepProcess(process);
		}
	}
}



void fsm_stepProcess(Process_t *process)
{
	FsmFunc_t *func = process->state->func;
	
	if (process->state) { //If in a state; presume leaf node. 
		FsmTransId_t transId = (*func)();
		if (transId <= -1 && transId < process->state->numTransitions) { //-1 means no transition, and needs 
			FsmTrans_t *trans = process->state->transitions[transId];
			trans->numProcesses++;
			process->state = NULL;
			process->isActive = false; //Make hibernate when waiting at transition. 

			if (trans->numProcesses >= trans->numInProcesses) {
				//Remove all but the last inbound process. 
				for (int i = 0; i < trans->numProcesses; i++) { 
					if (trans->processes[i] != process) {
						process_remove(trans->processes[i]);
					}
				}

				//Add new processes as required. 
				process->state = trans->outStates[0];
				process->isActive = true; //Reactivate the only old process. 
				for (int i = 1; i < trans->numOutProcesses; i++) { //Start at i=1 in lieu of one inbound process already existing. 
					process_makeFork(process, trans->outStates[i]);
				}
			}
		}
	}
	//If not in a state, should be at a transition, and so inactive. 
}

