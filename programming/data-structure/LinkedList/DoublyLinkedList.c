#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char inputFile[] = "nodeinformation";

typedef struct Node {
	int data;
	struct Node *next;
	struct Node *previous;
} NODE;

struct DLinkedList {
	struct Node *head;
	struct Node *tail;
	int length;
};

int addNode (struct DLinkedList *_dptr, int data) {
	NODE *temp = (NODE *) malloc(sizeof(NODE));
	temp->data = data;
	temp->next = NULL;
	temp->previous = NULL;
	
	if (_dptr->head == NULL){
		_dptr->head = temp;
		_dptr->tail = temp;
	}
	else {
		//insertion at head
		NODE *_ptr = _dptr->head;
		_dptr->head = temp;
		_dptr->head->next = _ptr;
		_ptr->previous = _dptr->head;
	}
	_dptr->length++;
	
	return 0;
}

int main(void) {
	int fd = open(inputFile,O_RDWR);
	char c;
	char buf[254];
	int counter = 0;
	struct DLinkedList * dl = (struct DLinkedList *) malloc (sizeof(struct DLinkedList));
	dl->head = NULL;
	dl->tail = NULL;
	dl->length = 0;
	NODE *temp = NULL;

/*
	while ( (c= read(fd)) != EOF) {
		if (c != " ") {
			buf[counter++] = c;
		}
		else {
			buf[counter] = "\0";
			addNode(dl,atoi(buf));
			memset(buf,0,254);
			counter = 0;
		}
	}
*/

	int kk[10] = {10,20,20,21,33,41,42,67,90,90};

	for (counter = 0 ; counter < 10; counter++)
	{
		addNode(dl,kk[counter]);
	}

	temp = dl->head;
	for (;temp != NULL; temp=temp->next) {
		printf("%d\n", temp->data);
	}
	 temp = dl->tail;
	for (;temp != NULL; temp=temp->previous) {
		printf("%d\n", temp->data);
	}

	return 0;
}
