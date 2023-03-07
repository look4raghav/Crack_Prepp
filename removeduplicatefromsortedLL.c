void removeduplicates(struct node* head)

{
    struct node* current = head;
    if(current == NULL) return;

    while(current->next!=NULL)
    {
        if(current->data == current->next->data)
        {
            struct node* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        }
        else
        {
            current = current->next;
        }
    }
}