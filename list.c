#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

void push(node **head, int value);
void append(node **head, int value);
void insert_pos(node **head, int pos, int value);
void display(node *head);
void free_list(node *head);

int main(void)
{
    // List of size NULL
    node *list = NULL;

    append(&list, 1);
    append(&list, 3);
    append(&list, 2);
    push(&list, 500);
    insert_pos(&list, 2, 725);

    display(list);
    free_list(list);

    return 0;
}

// Adds a node at given pos (zero indexing)
// If list is 2 --> 7 --> 1 --> 4, adding 3 to pos 2 will give
// 2 --> 7 --> 3 --> 1 --> 4
void insert_pos(node **head, int pos, int value)
{
    if (pos == 0)
    {
        printf("Use push instead");
        return;
    }

    node *tmp = malloc(sizeof(node));
    tmp -> number = value;


    node *beforeNode = *head;
    for (int n = 0; n < pos; n++)
    {
        beforeNode = beforeNode -> next;
    }

    tmp -> next = beforeNode -> next;
    beforeNode -> next = tmp;
}


// Adds a node at the start of the linked list
void push(node **head, int value)
{
    node *tmp = malloc(sizeof(node));
    tmp -> number = value;

    // If linked list contains nothing
    if (*head == NULL)
    {
        tmp -> next = NULL;
        *head = tmp;
    }
    else
    {
        tmp -> next = *head;
        *head = tmp;
    }
}


// Adds a node at the end of a linked list
// head --> list pointer --> first node ...
void append(node **head, int value)
{
    node *tmp, *last;
    tmp = malloc(sizeof(node));
    tmp -> number = value;
    tmp -> next = NULL;

    // If linked list contains nothing
    if (*head == NULL)
    {
        *head = tmp;
    }
    else
    {
        last = *head;
        while(last -> next != NULL)
        {
            last = last -> next;
        }

        last -> next = tmp;
    }
}

// Prints each node of linked list
void display(node *head)
{
    int count = 0;

    // Print numbers;
    for (node *tmp = head; tmp != NULL; tmp = tmp -> next)
    {
        printf("Node %i: %i\n", count, tmp -> number);
        count++;
    }
}

// Frees all memory given by malloc for linked list
void free_list(node *head)
{
    while (head != NULL)
    {
        node *tmp = head -> next;
        free(head);
        head = tmp;
    }
}