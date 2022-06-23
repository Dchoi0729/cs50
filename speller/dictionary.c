// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Number of words in loaded dictionary
unsigned int number = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Load dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];
    char c;
    int index = 0;

    while(fread(&c, sizeof(char), 1, file))
    {
        // Stores characters into word
        if (c != '\n')
        {
            word[index] = c;
            index++;
        }
        else
        {
            // Add word to hashtable
            add(&table[hash(word)], word);
            number++;

            // Reset index for next word
            index = 0;
        }
    }

    // Close file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return number;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i < 0; i < N; i++)
    {
        destroy(table[i]);
    }

    return true;
}

// Given the address of the head pointer to a linked list, adds s as first node to that list
void add(node **head, const char *s)
{
    node *tmp = malloc(sizeof(node));
    tmp -> word = s;
    tmp -> next = *head;

    *head = tmp;
}

// Frees memory for linked list with head as first pointer node
void destroy(node *head)
{
    if (head == NULL)
    {
        return;
    }

    destory(head -> next);
    free(head);
}