#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void merge_sort(pair list[]);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidate[i]) == 0)
        {
            ranks[rank] = name;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // An array with the index of candidates at each rank
    // The candidate_index[0] is the index of the first ranking candidate
    int candidate_index[candidate_count];

    for(int i = 0; i < candidate_count; i ++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(strcmp(ranks[i], candidate[j]) == 0)
            {
                candidate_index[i] = j;
                break;
            }
        }
    }

    // For each candidate above the second lowerst rank
    for (int i = 0; i < candidate_count - 1; i++)
    {
        int winner_index = candidate_index[i];

        // For all the candidate below rank i
        for (int j = i + 1; j < candidate_count; j++)
        {
            int loser_index = candidate_index[j];
            preferences[winner_index][loser_index]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if(preferences[i][j] > preferences[j][i])
            {
                pair_count++;
                pairs[i][j].winner = i;
                pairs[i][j].loser = j;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pair_count++;
                pairs[i][j].winner = j;
                pairs[i][j].loser = i;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    merge_sort(pairs, 0, pair_count - 1);
}

// Recursive merge sort algorithm for pair list
void merge_sort(pair arr[], int start, int end)
{
    if (end > start)
    {
        int middle = start + (end - 1) / 2
        merge_sort(arr[], start, middle);
        merge_sort(arr[], middle + 1, end);

        merge(arr[], start, middle, end);
    }
}

// Merges arr[start:middle] with arr[middle+1:end]
void merge(pair arr[], int start, int middle, int end)
{
    int left_size = middle - start + 1;
    int right_size = end - middle;

    pair temp_left[left_size], temp_right[right_size];

    // Populate temporary arrays with appropriate values
    for (int i = 0; i < left_size; i ++)
    {
        temp_left[i] = arr[i + start]
    }

    for (int i = 0; i < right_size; i ++)
    {
        temp_right[i] = arr[i + middle + 1]
    }

    int left_counter = 0, right_counter = 0;

    while ()
    {
        int left_score = preferences[temp_left[left_counter].winner][temp_left[left_counter].loser];
        int right_score = preferences[temp_right[right_counter].winner][temp_right[right_counter].loser];

        if(left_score > right_score)
    }
    preferences[temp_left[i].winner][temp_left[i].loser]
}


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}