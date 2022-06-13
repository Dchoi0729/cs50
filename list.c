#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

void end(node **head, int value);
void display(node *head);

int main(void)
{
    // List of size NULL
    node *list = NULL;

    end(&list, 1);
    end(&list, 3);
    end(&list, 2);

    display(list);
    free(list);

    return 0;
}

// Adds a node at the end of a linked list
// head --> list pointer --> first node ...
void end(node **head, int value)
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

// Frees all memory given by malloc
void free_memory(node *head)
{
    while (head != NULL)
    {
        node *tmp = head -> next;
        free(head);
        head = tmp;
    }
}