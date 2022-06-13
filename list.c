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
    int end = 1;
    if (list == NULL)
    {
        node *temp = malloc(sizeof(node));
        if (temp != NULL)
        {
            temp -> number = n;
            temp -> next = NULL;
        }

        list = temp;
    }
    else
    {
        add_node(list -> next, n);
    }
}

void print_list(node *list)
{
    if (list -> next == NULL)
    {
        printf("%i\n", list ->number);
    }
    else
    {
        print_list(list -> next);
    }
}


