

void linkedListInsertSorted(struct node** headReference, struct node* newNode)
{
    if(*headReference == NULL || (*headReference)->data >= newNode->data)
    {
        newNode->next = *headReference;
        *headReference = newNode;
    }
    else
    (
        struct node* current = *headReference;
        while (current->next!=NULL && current->next->data < newNode->data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    )
}