#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
}mynode;

void add_node(struct node **head, int *count, int value);
void print_list(char *list_name, struct node *head);
mynode *bubblesort(mynode *head, int count);

int main()
{
mynode *head;
int count = 0;
head = (struct node *)NULL;

add_node(&head, &count, 100);
add_node(&head, &count, 3);
add_node(&head, &count, 90);
add_node(&head, &count, 70);
add_node(&head, &count, 9);

print_list("mylist(BEFORE)", head);
head = bubblesort(head, count);
print_list("mylist(AFTER)", head);

getch();
return 0;
}

mynode *bubblesort(mynode *head, int count)
{
    int i,j;
    mynode *p0, *p1, *p2, *p3;

    for(i=1; i<count; i++)
    {
        p0 = (struct node*)NULL;
        p1 = head;
        p2 = head->next;
        p3 = p2->next;

        for(j=1; j<=(count-1); j++)
        {
            if(p1->value, p2->value)
            {
                p1->next = p3;
                p2->next = p1;
                if(p0)p0->next=p2;

                if(head==p1)head=p2;

                p0=p2;
                p2=p1->next;
                p3=p3->next!=(struct node *)NULL?p3->next: (struct node *)NULL;
            }
            else
            {
                p0=p1;
                p1=p2;
                p2=p3;
                p3=p3->next != (struct node *)NULL?p3->next: (struct node *)NULL;
            }
        }
    }
    return (head);
}

void add_node(struct node **head, int *count, int value)
{
    mynode *temp, *cur;
    temp = (mynode *)malloc(sizeof(mynode));
    temp->next=NULL;
    temp->prev=NULL;

    if(*head == NULL)
    {
        *head = temp;
        temp->value = value;
    }
    else
    {
        for(cur=*head; cur->next!=NULL; cur=cur->next);
        cur->next=temp;
        temp->prev=cur;
        temp->value=value;
    }
    *count = *count + 1;
}

void print_list(char *list_name, struct node *head)
{
    mynode *temp;
    printf("\n[%s] -> ", list_name);
    for(temp=head; temp!=NULL; temp=temp->next)
    {
        printf("[%d] -> ", temp->value);
    }
    printf("NULL\n");
}