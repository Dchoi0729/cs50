#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

void add_node(node *list, int n);

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

    add_node(list, 1);

    /***
    add_node(list, 3);
    add_node(list, 2);
    ***/

    printf("hi\n");

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


void add_node(node *list, int n)
{
    node *curr = list;
    node *tmp = (node *) malloc(sizeof(node));
    tmp -> number = n;
    tmp -> next = NULL;

    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = tmp;
}