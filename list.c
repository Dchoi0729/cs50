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

void print_list(node *list);

int main(void)
{
    node *list = NULL;
    add_node(list, 1);
}

void add_node(node *list, int n)
{
    node *temp = malloc(sizeof(node));
    if (temp != NULL)
    {
        temp -> number = n;
        temp -> next = NULL;
    }

    list = temp;
}

void print_list(node *list)
{
    while(true)
    {
        node *go = list
        if ()
    }
}


