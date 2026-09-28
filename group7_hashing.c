#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11
#define EMPTY -1

int hashTable[TABLE_SIZE];

/* Statistics */
int totalCollisions = 0;
int totalInsertProbes = 0;

/* Division method hash function */
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

/* Initialize hash table */
void initializeTable()
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = EMPTY;
}

/* Insert using linear probing */
void insert(int key)
{
    int index = hashFunction(key);
    int start = index;
    int probes = 0;

    while (hashTable[index] != EMPTY)
    {
        totalCollisions++;
        probes++;

        index = (index + 1) % TABLE_SIZE;

        if (index == start)
        {
            printf("Hash table is full. Cannot insert %d.\n", key);
            return;
        }
    }

    hashTable[index] = key;
    totalInsertProbes += probes;
}

/* Display hash table */
void displayTable()
{
    int i;

    printf("\n================ HASH TABLE ================\n");
    printf("Index\tSong ID\n");
    printf("---------------------------------------------\n");

    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == EMPTY)
            printf("%d\tEMPTY\n", i);
        else
            printf("%d\t%d\n", i, hashTable[i]);
    }

    printf("=============================================\n");
}

/* Hashing search using the same probing sequence */
int hashingSearch(int key, int *comparisons)
{
    int index = hashFunction(key);
    int start = index;

    *comparisons = 0;

    while (hashTable[index] != EMPTY)
    {
        (*comparisons)++;

        if (hashTable[index] == key)
            return index;

        index = (index + 1) % TABLE_SIZE;

        if (index == start)
            break;
    }

    return -1;
}

/* Linear search through the stored song IDs */
int linearSearch(int key, int values[], int n, int *comparisons)
{
    int i;

    *comparisons = 0;

    for (i = 0; i < n; i++)
    {
        (*comparisons)++;

        if (values[i] == key)
            return i;
    }

    return -1;
}

/* Display search result */
void compareSearch(int key, int values[], int n)
{
    int hashComparisons, linearComparisons;
    int hashPosition, linearPosition;

    hashPosition = hashingSearch(key, &hashComparisons);
    linearPosition = linearSearch(key, values, n, &linearComparisons);

    printf("\nSearch for Song ID: %d\n", key);

    if (hashPosition != -1)
        printf("Hashing Search : FOUND at table index %d (%d comparison(s))\n",
               hashPosition, hashComparisons);
    else
        printf("Hashing Search : NOT FOUND (%d comparison(s))\n",
               hashComparisons);

    if (linearPosition != -1)
        printf("Linear Search  : FOUND at array position %d (%d comparison(s))\n",
               linearPosition, linearComparisons);
    else
        printf("Linear Search  : NOT FOUND (%d comparison(s))\n",
               linearComparisons);
}

int main()
{
    int songIDs[] = {105, 210, 315, 420, 525, 630, 735, 840};
    int n = sizeof(songIDs) / sizeof(songIDs[0]);

    int i;
    int choice;
    int key;

    float loadFactor = (float)n / TABLE_SIZE;

    initializeTable();

    /* Insert all given song IDs */
    for (i = 0; i < n; i++)
        insert(songIDs[i]);

    printf("GROUP 7 - HASHING ASSIGNMENT\n");
    printf("=============================================\n");
    printf("Song IDs: 105, 210, 315, 420, 525, 630, 735, 840\n");
    printf("Hash method: Division Method + Linear Probing\n");
    printf("Table size: %d\n", TABLE_SIZE);

    displayTable();

    printf("\nCollision Analysis\n");
    printf("------------------\n");
    printf("Total collisions during insertion: %d\n", totalCollisions);
    printf("Additional probes due to collisions: %d\n", totalInsertProbes);
    printf("Load factor = n/m = %d/%d = %.3f (%.2f%%)\n",
           n, TABLE_SIZE, loadFactor, loadFactor * 100.0f);

    printf("\nSample Search Analysis\n");
    printf("----------------------\n");

    /* Present IDs */
    compareSearch(105, songIDs, n);
    compareSearch(420, songIDs, n);
    compareSearch(840, songIDs, n);

    /* An absent ID */
    compareSearch(999, songIDs, n);

    /* Interactive search */
    printf("\n=============================================\n");
    printf("Interactive Search\n");
    printf("Enter -1 to stop.\n");

    while (1)
    {
        printf("\nEnter Song ID to search: ");
        if (scanf("%d", &key) != 1)
        {
            printf("Invalid input.\n");
            break;
        }

        if (key == -1)
            break;

        compareSearch(key, songIDs, n);
    }

    printf("\nProgram completed successfully.\n");

    return 0;
}
