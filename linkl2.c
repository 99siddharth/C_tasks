// Linked list operations in C
#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node {
  int data;
  struct Node* next;
};
int count=0;

// Insert at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
  // Allocate memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the data
  new_node->data = new_data;

  new_node->next = (*head_ref);

  // Move head to new node
  (*head_ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node* prev_node, int new_data) {
  if (prev_node == NULL) {
  printf("the given previous node cannot be NULL");
  return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Insert the the end
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref; /* used in step 5*/

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

// Delete a node
void deleteNode(struct Node** head_ref, int key) {
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

// Search a node
int searchNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;

  while (current != NULL) {
  if (current->data == key) return 1;
  current = current->next;
  }
  return 0;
}

// Sort the linked list
void sortLinkedList(struct Node** head_ref) {
  struct Node *current = *head_ref, *index = NULL;
  int temp;

  if (head_ref == NULL) {
  return;
  } else {
  while (current != NULL) {
    // index points to the node next to current
    index = current->next;

    while (index != NULL) {
    if (current->data > index->data) {
      temp = current->data;
      current->data = index->data;
      index->data = temp;
    }
    index = index->next;
    }
    current = current->next;
  }
  }
}

// Print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
  printf(" %d ", node->data);
  node = node->next;
  }
}

// Driver program
int main() {
  struct Node* head = NULL;
   int choice,num,a;

  /*
  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  printf("Linked list: ");
  printList(head);

  printf("\nAfter deleting an element: ");
  deleteNode(&head, 3);
  printList(head);

  int item_to_find = 3;
  if (searchNode(&head, item_to_find)) {
  printf("\n%d is found", item_to_find);
  } else {
  printf("\n%d is not found", item_to_find);
  }

  sortLinkedList(&head);
  printf("\nSorted List: ");
  printList(head);
  */
  printf("Linkedlist menu\n1.Insertion at front\n2.Insertion at end\n3.Insert after a particular node\n4.Delete a node\n5.Sort the linkedlist\n6.Searching a node\n7.Print the list");
  while(1)
 {
  printf("\nEnter the choice:");	 
  scanf("%d",&choice);
  if(choice == 1)
  {
	  printf("\nEnter the number:");
	  scanf("%d",&num);
	  insertAtBeginning(&head, num);
  	  printList(head);
  }
  else if(choice == 2)
  {
	  printf("\nEnter the number:");
	  scanf("%d",&num);
	  insertAtEnd(&head, num);
  	  printList(head);
  }
  else if(choice == 3)
  {
	  printf("\nEnter the number:");
	  scanf("%d",&num);
	  insertAfter(head->next, num);  
  	  printList(head);
  }
  else if(choice == 4)
  {
	  printf("\nEnter the node to be deleted:");
	  scanf("%d",&num);
	  deleteNode(&head, num);
  	  printList(head);
  }
  else if(choice == 5)
  {
	  sortLinkedList(&head);
  	  printList(head);
  }
  else if(choice == 6)
  {
	 printf("Enter the number to be searched for:");
	 scanf("%d",&num);
	 //a=searchNode(&head, num);
	 //int item_to_find = 3;
  	 if (searchNode(&head, num)) 
	 {
   		printf("\n%d is found", num);
  	 } 
	 else 
	 {
  	 	printf("\n%d is not found", num);
  	 }

 	 printList(head);
  }
  else if(choice == 7)
	  printList(head);
  else
	  exit(0);
 }






 
}
