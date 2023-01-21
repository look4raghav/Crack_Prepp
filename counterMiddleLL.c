#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
}mynode

void add_node(struct node **head, int value);
void print_list(char *listName, struct node *head);
void getTheMiddle(mynode *head);

int main() 
{
    mynode *head, *middle;
    head = (struct node *)NULL;

    add_node(&head, 1);
    add_node(&head, 10);
    add_node(&head, 5;
    add_node(&head, 70);
    add_node(&head, 9;
    add_node(&head, -99);
    add_node(&head, 0);
    add_node(&head, 555);
    add_node(&head, 55);

    print_list("myList", head);
    middle = getTheMiddle(head);
    printf("\nMiddle Node -> [%d]\n\n", middle->value);

    getch();
    return 0;
}

mynode *getTheMiddle(node *head)
{
    mynode *middle = (mynode *)NULL;
    int i;

    for(i=1; head!=(mynode *)NULL; head=head->next, i++)
    {
        if(i==1)
            middle=head;
        else if((i%2)==1)
            middle=middle->next;
    }
    return middle;
}

void add_node(struct node, **head, int value)
{
    mynode *temp, *cur;
    temp = (mynode *)malloc(sizeof(mynode));
    temp->next=NULL;
    temp->prev=NULL;

    if(*head == NULL)
 {
 *head=temp;
 temp->value=value;
 }
 else
 {
 for(cur=*head;cur->next!=NULL;cur=cur->next);
 cur->next=temp;
 temp->prev=cur;
 temp->value=value;
 }
}
void print_list(char *listName, struct node *head)
{
 mynode *temp;
 printf("\n[%s] -> ", listName);
 for(temp=head;temp!=NULL;temp=temp->next)
 {
 printf("[%d]->",temp->value);
 }

 printf("NULL\n");
}
}