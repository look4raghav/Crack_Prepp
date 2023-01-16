#include <stdio.h>

typedef struct node
{
    int value;
    struct node *next;
}mynode;

mynode *head, *tail, *temp;
void add(int value);
mynode* reverse_recurse(mynode *root);
void print_list();

int main() 
{
    head = (mynode *)0;
    add(1);
    add(2);
    add(3);
    print_list();
    
    if (head != (mynode *)0)
    {
        temp = reverse_recurse(head);
        temp->next = (mynode *)0;
    }
    print_list();
    return 0;
}

mynode* reverse_recurse(mynode *root)
{
    if(root->next != (mynode *)0)
       {
           reverse_recurse(root->next);
           root->next->next=root;
           return (root);
       }
    else
       {
           head=root;
       }
}

void add(int value)
{
    temp = (mynode *) malloc(sizeof(struct node));
    temp->next=(mynode *)0;
    temp->value=value;
    
    if(head==(mynode *)0)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void print_list()
{
    printf("\n\n");
    for(temp=head; temp!=(mynode *)0; temp=temp->next)
    {
        printf("[%d]->", (temp->value));
    }
    printf("[NULL]\n\n");
}
