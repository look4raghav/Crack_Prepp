#include <stdio.h>

typedef struct node
{
    int value;
    struct node *next;
}mynode;

void add(mynode **head, mynode **tail, int value);
mynode* reverse_recurse(mynode *current, mynode *next);
void print_list(mynode *);

int main() 
{
    mynode *head, *tail;
    head = (mynode *)0;
    add(&head, &tail, 1);
    add(&head, &tail, 2);
    add(&head, &tail, 3);
    print_list(head);
    head = reverse_recurse(head, (mynode *)0);
    print_list(head);
    getch();
    return 0;
}

mynode* reverse_recurse(mynode *current, mynode *next)
{
    mynode *ret;
    if(current==(mynode *)0)
       {
           return ((mynode *)0);
       }
    ret = (mynode *)0;
    if(current->next != (mynode *)0)
    {
        ret = reverse_recurse(current->next, current);
    }
    else
       {
           ret=current;
       }
    current->next = next;
    return ret;
}

void add(mynode **head, mynode **tail, int value)
{
    mynode *temp1, *temp2;
    
    temp1 = (mynode *) malloc(sizeof(struct node));
    temp1->next=(mynode *)0;
    temp1->value=value;
    
    if(*head==(mynode *)0)
    {
        *head = temp1;
        *tail = temp1;
    }
    else
    {
        for(temp2 = *head; temp2->next!= (mynode *)0; temp2=temp2->next);
        temp2->next=temp1;
        *tail=temp1;
    }
}

void print_list(mynode *head)
{
    mynode *temp;
    printf("\n\n");
    for(temp=head; temp!=(mynode *)0; temp=temp->next)
    {
        printf("[%d]->", (temp->value));
    }
    printf("[NULL]\n\n");
}




















