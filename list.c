#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

void end(node *head, int value);

int main(void)
{
    // List of size NULL
    node *list = NULL;

    end(list, 1);

    // Print numbers;
    for (node *tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        printf("%i\n", tmp -> number);
    }

    while (list != NULL)
    {
        node *tmp = list -> next;
        free(list);
        list = tmp;
    }

    return 0;
}


void end(node *head, int value)
{
    node *tmp;
    tmp = malloc(sizeof(node));
    tmp -> number = value;
    tmp -> next = NULL;

    if (head == NULL)
    {
        head = tmp;
    }
}