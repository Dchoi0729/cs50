// Speller using trie instead of hashtable

#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

#define ALPHABET_SIZE 26

// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[ALPHABET_SIZE];
}
node;

// Prototypes for helper functions
void add(node *head, const char *s);
void destroy_trie(node *head);
node *new_node(void);
int char_to_int(char c);

// Global pointer to the parent node of trie
// Initiallized to null
node *trie;

// Number of words in loaded trie
unsigned int number = 0;

// Returns true if word is in trie, else false
bool check(const char *word)
{
    node *crawler = trie;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int index = char_to_int(word[i]);
        crawler = crawler -> children[index];
        if (crawler == NULL)
        {
            return false;
        }
    }

    return (crawler -> is_word);
}

// Loads trie into memory, returning true if successful, else false
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

    // Initialize node to NULL
    trie = new_node();

    while (fread(&c, sizeof(char), 1, file))
    {
        // Stores characters into word
        if (c != '\n')
        {
            word[index] = c;
            index++;
        }
        else
        {
            // Terminate current word
            word[index] = '\0';

            // Add word to trie
            add(trie, word);
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
    destroy_trie(trie);

    return true;
}

// Given the address of the head pointer to a trie, adds word to trie
void add(node *head, const char *word)
{
    node *crawler = head;

    // Goes through trie, adding the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int index = char_to_int(word[i]);
        if (crawler -> children[index] == NULL)
        {
            crawler -> children[index] = new_node();
        }
        crawler = crawler -> children[index];
    }

    // Marks the end of word
    crawler -> is_word = true;
}

// Frees memory for trie with head as first pointer node
void destroy_trie(node *head)
{
    // Base case
    if (head == NULL)
    {
        return;
    }

    // Free all children
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        destroy_trie(head -> children[i]);
    }

    // Free itself
    free(head);
}

// Converts a-z to 0-25
int char_to_int(char c)
{
    return tolower(c) - 'a';
}

// Gives a new node initialized to null
node *new_node(void)
{
    node *tmp = malloc(sizeof(node));
    if (tmp != NULL)
    {
        trie -> is_word = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            trie -> children[i] = NULL;
        }
    }
    return tmp;
}
