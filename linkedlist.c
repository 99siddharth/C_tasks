#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertStart(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;


    *head = newNode;
}

void insertLast(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    
    if(*head==NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct Node* node){

    
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    int i,num;
    struct Node* head = NULL;

    while(1)
    {
        printf("\nEnter the choice:\n1: For Insertion in first\n2: For insertion in last\n3: For Exit: ");
        scanf("%d",&i);
        if(i==1)
        {
            printf("\nEnter the number: ");
            scanf("%d",&num);
            insertStart(&head,num);
		printf("\n");            
		display(head);		
        }
        else if(i==2)
        {
            printf("\nEnter the number: ");
            scanf("%d",&num);
            insertLast(&head,num);
		printf("\n");            
		display(head);
        }
        else if(i==3)
            break;
        else
	{
            printf("Wrong input");
		printf("\n");
	}
    }
     
    return 0; 
}

