#include <stdio.h>
#include <stdlib.h>
// Linked List Node
struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;
  

// Function to traverse the linked list
void traverse()
{
    struct node* temp;
  
    // List is empty
    if (start == NULL)
        printf("List is empty\n");
  
    // Else print the LL
    else {
        temp = start;
	printf("List is: ");
        while (temp != NULL) {
            printf(" %d ", temp->info);
            temp = temp->link;
        }
    }
}
  
// Function to insert at the front of the linked list
void insertAtFront()
{
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->info = data;
  
    // Pointer of temp will be assigned to start
    temp->link = start;
    start = temp;
}
  
// Function to insert at the end of the linked list
void insertAtEnd()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
  
    // Enter the number
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
  
    // Changes links
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}
  
// Function to insert at any specified position in the linked list
void insertAtPosition(int count)
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
  
    // Enter the position and data
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
    if(pos<=count){
    // Change Links
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos-1 ) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
    }
    else
	    printf("Invalid node point");
}
  
// Function to delete from the front of the linked list
void deleteFirst()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->link;
        free(temp);
    }
}
  
// Function to delete from the end of the linked list
void deleteEnd()
{
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        while (temp->link != 0) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}
  
// Function to delete from any specified position from the linked list
void deletePosition(int count)
{
    struct node *temp, *position;
    int i = 1, pos;
  
    // If LL is empty
    if (start == NULL)
        printf("\nList is empty\n");
  
    // Otherwise
    else {
        printf("\nEnter index : ");
  
        // Position to be deleted
        scanf("%d", &pos);
	if(pos<=count){
        position = malloc(sizeof(struct node));
        temp = start;
  
        // Traverse till position
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
  
        // Change Links
        position = temp->link;
        temp->link = position->link;
  
        // Free memory
        free(position);
        }
	else
		printf("Invalid Node");
      }

}
void sort()
{
    struct node* current = start;
    struct node* index = NULL;
    int temp;
  
    // If LL is empty
    if (start == NULL) {
        return;
    }
  
    // Else
    else {
  
        // Traverse the LL
        while (current != NULL) {
            index = current->link;
  
            // Traverse the LL nestedly
            // and find the minimum
            // element
            while (index != NULL) {
  
                // Swap with it the value
                // at current
                if (current->info > index->info) {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }
  
            // Update the current
            current = current->link;
        }
    }
}
// Driver Code
int main()
{
    int choice,count=0;
        printf("----------------------------------------------LinkedList Menu-------------------------------------------------------------------");
        printf("\n1  To see list\n");
        printf("2  For insertion at starting\n");
        printf("3  For insertion at end\n");
        printf("4  For insertion at any position\n");
        printf("5  For deletion of first element\n");
        printf("6  For deletion of last element\n");
        printf("7  For deletion of element at any position\n");
        printf("8  To sort element\n");
        printf("9  To exit");
 
    while (1) {
       printf("\nEnter Choice :");
        scanf("%d", &choice);
  
        switch (choice) {
        case 1:
	    {
	     traverse();
             break;
	    }
 
 	case 2:
	    {
            count++;
            insertAtFront();
	    break;
	    }
        case 3:
	    {
	    count++;
            insertAtEnd();

	    break;
	    }
        case 4:
	    {
            insertAtPosition(count);
            count++;
	    break;
	    }
        case 5:
	    {
	    count--;
            deleteFirst();
	    break;
	    }
        case 6:
	    {
	    count--;
            deleteEnd();
	    break;
	    }
        case 7:
	    {
            deletePosition(count);
            count--;
	    break;
	    }
        case 8:
            sort();
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}
