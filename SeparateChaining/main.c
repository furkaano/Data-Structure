#include <stdio.h>
#include "hash_student_style.h"

#define DATA_SIZE 11

typedef struct _HashTable {
    SLLI** pTable;
    int tableSize;
    //double loadFactor;
    int itemCount;
}HashTable;

HashTable* CreateHashTable(int tableSize);
void DestroyHashTable(HashTable* pHashTable);
void InsertHashTable(HashTable* pHashTable, int key);
int HashFunc(HashTable* pTable, int key);
void PrintHashTable(HashTable* pTable);

void PrintHashTable(HashTable* pHashTable)
{
    int i;

    for (i = 0; i < pHashTable->tableSize; ++i) {
        printf("HashTable[%d] --> ", i);
        PrintList(pHashTable->pTable[i]);
        printf("\n");
    }
}

int HashFunc(HashTable* pTable, int key)
{
    return (key % pTable->tableSize);
}

void InsertHashTable(HashTable* pHashTable, int key)
{
    int index;

    index = HashFunc(pHashTable, key);
    pHashTable->pTable[index] = AddItemToFront(pHashTable->pTable[index], key);
    pHashTable->itemCount++;
}

HashTable* CreateHashTable(int tableSize)
{
    HashTable* pHashTable;
    int i;

    pHashTable = AllocateMemory(sizeof(HashTable), "CreateHashTable - 1", TRUE);
    pHashTable->tableSize = tableSize;
    pHashTable->pTable = AllocateMemory(sizeof(SLLI) * tableSize, "CreateHashTable - 2", TRUE);
    for (i = 0; i < tableSize; ++i)
        pHashTable->pTable[i] = NULL;
    pHashTable->itemCount = 0;
    return pHashTable;
}

void DestroyHashTable(HashTable* pHashTable)
{
    int i;

    for (i = 0; i < pHashTable->tableSize; ++i)
        if (NULL != pHashTable->pTable[i])
            // Free each and every single item!
            DestroyList(pHashTable->pTable[i]);

    free(pHashTable->pTable);
    free(pHashTable);
}

int main()
{
//    SLLI* pHead = NULL;
    int i;
    int data[] = { 44, 666, 27, 102, 58, 90, 30, 63, 24, 11, 2 };
    int toFind;
    HashTable* pHashTable;

    pHashTable = CreateHashTable(HASH_TABLE_SIZE);


    for (i = 0; i < DATA_SIZE; ++i)
        InsertHashTable(pHashTable, data[i]);

    PrintHashTable(pHashTable);

    DestroyHashTable(pHashTable);

#if 0
    // STUDENT-STYLE HASH TABLE!!!
    for (i = 0; i < DATA_SIZE; ++i)
        hash_insert(data[i]);

    print_hash_table();

    toFind = 2;
    if (hash_find(toFind))
        printf("%d is IN the table :)\n", toFind);
    else
        printf("%d is NOT in the table :)\n", toFind);

    toFind = 13;
    if (hash_find(toFind))
        printf("%d is IN the table :)\n", toFind);
    else
        printf("%d is NOT in the table :)\n", toFind);
#endif


#if 0
    for (i = 0; i < 10; ++i)
        pHead = AddItemToFront(pHead, i + 1);

    printf("PrintList ITERATIVE\n");
    PrintList(pHead);
    printf("PrintList RECURSIVE\n");
    PrintList_recursive(pHead);

    printf("PrintList REVERSE RECURSIVE\n");
    PrintListReverse_recursive(pHead);
#endif

    return 0;
}

