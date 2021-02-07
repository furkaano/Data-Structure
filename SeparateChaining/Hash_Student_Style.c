#include "Hash_Student_Style.h"

SLLI* pHashTable[HASH_TABLE_SIZE];

int hash_func(int table_size, int key)
{
    return (key % table_size);
}

BOOL hash_insert(int key)
{
    int index;

    index = hash_func(HASH_TABLE_SIZE, key);
    pHashTable[index] = AddItemToFront(pHashTable[index], key);
    return TRUE;
}

void print_hash_table()
{
    int i;

    for (i = 0; i < HASH_TABLE_SIZE; ++i) {
        printf("HASH_TABLE INDEX : %d --> ", i);
//        printf("---------------------\n");
        PrintList(pHashTable[i]);
        printf("\n");
//        printf("------------\n");
    }
}

BOOL hash_find(int keyToFind)
{
    int index;
    SLLI* pItem;

    index = hash_func(HASH_TABLE_SIZE, keyToFind);
    pItem = Find(pHashTable[index], keyToFind);
    if (NULL == pItem)
        return FALSE;
    else
        return TRUE;
}

