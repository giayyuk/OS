#include <stdio.h>
#include <stdlib.h>

// TODO: structs, global variables, etc.
typedef struct Node {
  int value;
  struct Node *next;
} node_t;

static int insertElement(int value);
static int removeElement(void);
static node_t *head = NULL;

int main (int argc, char* argv[]) {
	printf("insert 47: %d\n", insertElement(23));
	printf("insert 11: %d\n", insertElement(11));
	printf("insert 23: %d\n", insertElement(23));
	printf("insert 11: %d\n", insertElement(11));
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("insert 23: %d\n", insertElement(23));
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("insert 23: %d\n", insertElement(23));
	printf("insert 47: %d\n", insertElement(47));
	printf("remove: %d\n", removeElement());
	printf("insert -32: %d\n", insertElement(-32));
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());

	// TODO: add more tests

	exit(EXIT_SUCCESS);
}
static int insertElement(int value) {
  // we could recurs if malloc failes (could lead to stackoverflow).
  // we interpete the problem spesification that -1 sould be returned.
  if (head == NULL) {
    head = (node_t*) malloc(sizeof(node_t));
    return -1;
  }
  // test to not insert a negative value
  if (value < 0) {
    return -1;
  }
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
  // go to end of list using head would destroy the list
  if (head == NULL) {
    return -1;
  }
  if (head->next == NULL) {
    return -1;
  }
  node_t *temp = head;
  while(temp->next != NULL) {
    if(temp->next->next == NULL) {
      break;
    }
    temp = temp->next;
  }
  int ret = temp->next->value;
  free(temp->next);
  temp->next = NULL;
	return ret;
}

