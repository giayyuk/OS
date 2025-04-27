#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------
 * i hope this is sufficently commented
 * ------------------------------------*/
typedef struct Node {
  int value;
  struct Node *next;
} node_t;

// function signatures 
static int insertElement(int value);
static int removeElement(void);
int freeAll(void); // this is not asked of by the assignment 

static node_t *head = NULL; // head of list

int main (int argc, char* argv[]) {
	printf("insert 43: %d\n", insertElement(43));
	printf("insert 43: %d\n", insertElement(43));
	printf("insert 11: %d\n", insertElement(11));
	printf("insert 11: %d\n", insertElement(11)); // value already inserted
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("insert 23: %d\n", insertElement(23));
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("insert 23: %d\n", insertElement(23));
	printf("insert 47: %d\n", insertElement(47));
	printf("insert why? 47: %d\n", insertElement(47)); // value already inserted
	printf("remove: %d\n", removeElement());
	printf("insert -32: %d\n", insertElement(-32)); // negative value test
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement()); // removing from empty list
	printf("insert 42: %d\n", insertElement(42));
  // freeAll(); if list still has elements this function removes them
	exit(EXIT_SUCCESS);
}
static int insertElement(int value) {
  // test to not insert a negative value
  if (value < 0) {
    return -1;
  }
  if (head == NULL) { // if list is empty then create head object
    head = (node_t*) malloc(sizeof(node_t));
    head->value = value;
    head->next = NULL;
    return value;
  }
  // if list is not empty
  // head->next would destroy the list
  // we create *temp and and go to the last element if the values are diffrent 
  node_t *temp = head;
  while (temp->next != NULL) {
    if (temp->value != value) {
      temp = temp->next;
    }
    else {
      return -1;
    }
  }
  if (temp->value == value) {return -1;}
  // when the end of the list is reached we allocate the new node and insert it at the end;
  node_t *new = (node_t*)malloc(sizeof(node_t));
  if (new == NULL) {
    return -1;
  }
  new->value = value;
  new->next = NULL;
  temp->next = new;
	return value;
}

static int removeElement(void) {
  if (head == NULL) { // if list is empty
    return -1;
  }
  else if (head->next == NULL) { // else if list has 1 element
    int ret = head->value;
    free(head);
    head = NULL;
    return ret;
  }
  else {
    node_t *newHead = head->next; // if list has more then 1 element 
    int ret = head->value;
    head = NULL;
    head = newHead;
    return ret;
  }
}

int freeAll() { 
  // normaly you would have to free the entire rest of the list
  // at the end of the program.
  // this is not specified in the assignment. 
  // it could look like this.
  if (head) {
    while (head->next != NULL) {
      removeElement();
    }
    free(head);
    head = NULL;
  }
  return 0;
}
