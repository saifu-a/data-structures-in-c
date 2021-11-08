/*
 * This is an implementation of Hash Table.
 * The hash function used here is: n mod k
 * The time complexity to store a value: O(1)
 * The time complexity to retrieve a value: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hash(int value);
void put(int *hashTable, int value);
int get(int *hashTable, int index);
int display(int *hashTable);

int main(int argc, char *argv[])
{
    int hashTable[SIZE] = {0};
    int i, ch, value, key;

    while (1)
    {
        printf("\n\n1. Store");
        printf("\n2. Fetch");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the value to be stored: ");
            scanf("%d", &value);
            put(hashTable, value);
            break;

        case 2:
            printf("\nEnter the key to be fetched: ");
            scanf("%d", &key);
            printf("\n%d", get(hashTable, key));
            break;

        case 3:
            display(hashTable);
            break;

        case 4:
            exit(1);

        default:
            printf("Wrong choice. Try again.");
        }
    }

    return 0;
}

int hash(int value)
{
    int key;
    key = value % SIZE;
    return key;
}

void put(int *hashTable, int value)
{
    int key;
    key = hash(value);
    hashTable[key] = value;
}

int get(int *hashTable, int key)
{
    return hashTable[key];
}

int display(int *hashTable)
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("\n%d -> %d", i, hashTable[i]);
    }
}
