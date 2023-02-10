#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
}mynode;

void add_node(struct node **head, int value);
void print_list(char *list_name, struct node *head);
void mergesort(struct node **headRef);
struct node *merge2SortedLLs(struct node *head1, struct node *head2);
void splitLLInto2(struct node* source, struct node** frontRef, struct node** backRef);

int main()
{
    mynode *head;
    head = (struct node *)NULL;

    add_node(&head, 1);
    add_node(&head, 10);
    add_node(&head, 5);
    add_node(&head, 70);
    add_node(&head, 9);
    add_node(&head, -99);
    add_node(&head, 0);

    print_list("mylist", head);
    mergesort(&head);
    print_list("mylist", head);

    getch();
    return 0;
}

void mergeSort(struct node** headRef)
{
 struct node* head = *headRef;
 struct node* a;
 struct node* b;
 if ((head == NULL) || (head->next == NULL))
 {
     return;
 }
splitLLInto2(head, &a, &b);
 mergeSort(&a);
 mergeSort(&b);
 *headRef = merge2SortedLLs(a, b);
}
struct node *merge2SortedLLs(struct node *head1, struct node *head2)
{
 struct node *a, *b, *c, *newHead, *temp;
 a = head1;
 b = head2;
 c = (struct node *)NULL;
 newHead = (struct node*)NULL;

 if(a==NULL)return(b);
 else if(b==NULL)return(a);
 while(a!=NULL && b!=NULL)
 {
 if(a->value < b->value)
 {
 if(c==NULL)
 {
 c = a;
 }
 else
 {
 c->next = a;
 c = c->next;
 }
 a = a->next;
 }
 else if(a->value > b->value)
 {
 if(c==NULL)
 {
 c = b;
 }
 else
 {
 c->next = b;
 c = c->next;
 }
 b = b->next;
 }
 else
 {
 if(c == NULL)
 {
 c = a;
 }
 else
 {
 c->next = a;
 c = c->next;
 }
 a = a->next;
 b = b->next;
 }
 if(newHead == NULL)
 newHead = c;
 }

 if(a==NULL && b==NULL)
 return(newHead);

 if(a==NULL)
 c->next = b;
 else if(b==NULL)
 c->next = a;

 return(newHead);
}

void splitLLInto2(struct node* source, struct node** frontRef, struct node** backRef)
{
 struct node* fast;
 struct node* slow;

 if (source==NULL || source->next==NULL)
 {
 *frontRef = source;
 *backRef = NULL;
 }
 else
 {
 slow = source;
 fast = source->next;
 while (fast != NULL)
 {
 fast = fast->next;
 if (fast != NULL)
 {
 slow = slow->next;
 fast = fast->next;
 }
 }
 *frontRef = source;
 *backRef = slow->next;
 slow->next = NULL;
 }
}
void add_node(struct node **head, int value)
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


/*d&c*/