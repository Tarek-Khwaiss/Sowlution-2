#include "stdlib.h"

typedef struct node
{
    int data;
    struct node *next;
} node;

node *initialize(int data)
{

    node *head = NULL;
    head->data = data;
    head->next = NULL;
}

void addNode(node *head, node *new)
{
    node *curr = head;

    // loop over
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    // link to the last node
    curr->next = new;
}

void removeNodes(node *head, int limit)
{

    // a temp node for switching the nodes
    node *temp = NULL;
    node *curr = head;

        node *curr2 = head;
    // check if linked list is empty
    if (!curr)
    {
        return;
    }

    int i = 0;
    while (curr)
    {
        // checking if the linked list is at the head position
        if (!i)
        {
            curr = curr->next;
            i++;
        }

        // any other case
        if (curr->next != NULL)
        {
            if (curr->next->data > limit)
            {

                // using a temp to switch
                temp = curr;
                curr = curr->next;
                temp->next = curr->next;

                curr = temp;
            }
            curr = curr->next;
        }
    }