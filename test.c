#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void add(HASH_MAP* m, int key, char* value) {
    char*p = hash_add(m, key, value);
//    printf("add hash key:%d value:%s", key, value);
    if (p) {
//        printf(" replace old val %s", p);
    }
//    printf("\n");
}

void query(HASH_MAP* m, int key) {
    char*p = hash_query(m, key);
    if (p) {
//        printf("query hash key:%d value:%s\n", key, p);
    }else {
//        printf("query invalid hash key:%d\n", key);
    }
}

void delete(HASH_MAP* m, int key) {
    char* p = hash_delete(m, key);
    if (p) {
//        printf("delete hash key %d value %s\n", key, p);
    }else {
//        printf("delete invalid hash key %d\n", key);
    }
}

int main() {
    int64_t num = 10*1024*1024;
    int64_t max_val = num*8;
    HASH_MAP* m = new_hashmap(num);
    char a[] = "1234567";
    clock_t start = clock();
    int64_t i = 1;
    while ((i++) <= num) {
        int64_t key = random() & max_val;
        add(m, key, a);
    }
    clock_t finish = clock();
    printf("--num %ld-cost time:%f---\n", num, (double)(finish-start)/CLOCKS_PER_SEC);
    delete_hashmap(m);
    return 0;
}