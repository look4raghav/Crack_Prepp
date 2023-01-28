struct list *listptr, *nextptr;
for(listptr = head; listptr!=NULL; listptr = nextptr)
{
    nextptr = listptr->next;
    free(listptr);
}
head = NULL;