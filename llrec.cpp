#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(head > pivot && head != NULL){
		larger = head;
		llpivot(head->next, smaller, larger); 
	}
	else if(head <= pivot && head != NULL){
		smaller = head;
		llpivot(head->next, smaller, larger);
	}
	if(head == NULL){
		return nullptr;
	}
}

