#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct node
{
    void *data;
    struct node *next;
}mynode;

mynode * find_loop(mynode * head)
{
    mynode * current = head;
    while(current->next != NULL)
    {
        mynode *temp = head;
        while (temp->next != NULL && temp != current)
        {
            if(current->next == temp)
            {
                printf("\nFound a loop.");
                return current;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return NULL;
}


/* 
p=head;
q=head->next;
while(p!=NULL && q!=NULL)
{
 if(p==q)
 {
 //Loop detected!
 exit(0);
 }
 p=p->next;
 q=(q->next)?(q->next->next):q->next;
} 
*/

