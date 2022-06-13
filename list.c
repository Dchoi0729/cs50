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
    add_node(list, 3);
    add_node(list, 2);
    print_list(list);
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
    node current = NULL;
    int counter = 0;
    while(true)
    {
        if (list == NULL)
        {
            break;
        }
        current = *list;
        printf("Node %i is: %i\n", counter, current.number);
        count++;
    }
}


