#include <iostream>
#include "eventQueue.h"
using namespace std;

struct Node{
	Event Payload;
	Node* next;
};

Node* head = 0;
 
bool enqueue(const Event* e) {
	Node *n;
	n = new Node;
	if(e->time<0){
		return false;
	}
	n->Payload = *e;
	n-> next = 0;
	if(head==0){
		head = n;
		return true;
	}
	if (head->Payload.time > e->time){
		n->next = head;
		head = n;
	}
	else{
		Node* curr = 0;
		for(curr = head; curr->next != 0 && (curr->next->Payload.time <= e->time);curr = curr->next);
		Node* temp = curr->next;
		curr->next = n;
		n->next = temp;
	}
	return true;
}

const Event* dequeue(){
	if (head == 0) return 0; //No Elements to Dequeue	
	Event* returnValue = &head->Payload;
	head = head->next;
	return returnValue;
}