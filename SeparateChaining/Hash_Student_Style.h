#ifndef SEPARATECHAINING_HASH_STUDENT_STYLE_H
#define SEPARATECHAINING_HASH_STUDENT_STYLE_H

#include "singly_linked_list.h"
#include "general.h"

#define HASH_TABLE_SIZE 11

int hash_func(int table_size, int key);
BOOL hash_insert(int key);
void print_hash_table();
BOOL hash_find(int keyToFind);

#endif //SEPARATECHAINING_HASH_STUDENT_STYLE_H
