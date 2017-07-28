#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SIZE 15
#define UNIQ_SIZE 9

void add(HASH_MAP* m, int key, char* value) {
    char*p = hash_add(m, key, value);
    printf("add hash key:%d value:%s", key, value);
    if (p) {
        printf(" replace old val %s", p);
    }
    printf("\n");
}

void query(HASH_MAP* m, int key) {
    char*p = hash_query(m, key);
    if (p) {
        printf("query hash key:%d value:%s\n", key, p);
    }else {
        printf("query invalid hash key:%d\n", key);
    }
}

void delete(HASH_MAP* m, int key) {
    char* p = hash_delete(m, key);
    if (p) {
        printf("delete hash key %d value %s\n", key, p);
    }else {
        printf("delete invalid hash key %d\n", key);
    }
}

struct {
    int id;
    char* name;
    int add_cost;
    int del_cost;
} DATA[TOTAL_SIZE] = {
    {1, "a", 1, 3},
    {2, "b", 1, 1},
    {3, "c", 1, 2},
    {4, "d", 1, 2},
    {5, "e", 1, 3},
    {6, "f", 1, 2},
    {7, "g", 1, 2},
    {8, "h", 1, 2},
    {9, "i", 1, 2},

    {3,"cc", 1, 1},
    {4,"dd", 1, 1},
    {3,"ccc", 1, 3},
    {17, "q", 1, 3},
    {33, "r", 1, 2},
    {25, "w", 1, 2},
};

int main() {
    HASH_MAP* m = new_hashmap(UNIQ_SIZE);
    int i = 1;
    int j;
    while (i <= 3) {
        printf("------loop:%d-----\n",i);
        for (j=0; j<TOTAL_SIZE; j++) {
            if (i == DATA[j].add_cost) {
                add(m, DATA[j].id, DATA[j].name);
            }
            if (i == DATA[j].del_cost) {
                delete(m, DATA[j].id);
            }
        }
        printf("query result:\n");
        for (j=0; j<UNIQ_SIZE; j++) {
            query(m, DATA[j].id);
        }
        printf("trace map:\n");
        trace_hashmap(m);
        i++;
    }
    delete_hashmap(m);
    return 0;
}