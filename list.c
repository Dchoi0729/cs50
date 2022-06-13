#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

void add_node(node *tmp, node *list, int n);

int main(void)
{
    // List of size NULL
    node *list = NULL;

/***
    // Add a number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n -> number = 1;
    n -> next = NULL;

    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n -> number = 2;
    n -> next = NULL;

    list -> next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list -> next);
        free(list);
        return 1;
    }
    n -> number = 3;
    n -> next = NULL;

    list -> next -> next = n;
    ***/

    node *a = NULL;
    add_node(a, list, 1);
    add_node(a, list, 3);
    add_node(a, list, 2);


    // Print numbers;
    for (node *tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        printf("%i\n", tmp -> number);
    }
}


void add_node(node *tmp, node *list, int n)
{
    if (list != NULL)
    {
        if (list -> next != NULL)
        {
             add_node(tmp, list->next, n);
        }
    }
    else
    {
        tmp = malloc(sizeof(node));
        tmp -> number = n;
        tmp -> next = NULL;

        list = tmp;
    }
}