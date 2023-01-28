#include <stdio.h>


struct node
{
    int data;
    struct node *next;
}mynode;

mynode * nthNode(mynode *head, int n)    /* pass 0 fpr last node */
{
    mynode *ptr1, *ptr2;
    int count;

    if(!head)
    {
        return NULL;
    }
    ptr1 = head;
    ptr2 = head;
    count = 0;

    while(count < n)
    {
        count ++;
        if((ptr1=ptr2->next)==NULL)
        {
            return(NULL);
        }
    }

    while((ptr1=ptr1->next)!=NULL)
    {
        ptr2=ptr2->next;
    }
    return (ptr2);
}