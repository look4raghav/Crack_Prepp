#include <stdio.h>
#include <stdlib.h>

int compare_linked_lists(struct node *q, struct node *r)
{
    static int flag;
    if((q==NULL)&&(r==NULL))
    {
        flag=1;
    }
    else
    {
        if(q=NULL || r==NULL)
        {
            flag=0;
        }
        if(q->data!=r->data)
        {
            flag=0;
        }
        else
        {
            compare_linked_lists(q->link,r->link)
        }
    }
    return (flag);

}