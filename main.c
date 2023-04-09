#include <stdio.h>
#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    Vector v = createVector(0);
    pushBack(&v, 1);
    if (!(v.size == 1 & v.capacity == 1)) {
        fprintf(stderr, "Test test_pushBack_emptyVector is failed");

        exit(1);
    }
}

void test_pushBack_fullVector() {
    Vector v = createVector(1);
    int startSize = v.capacity;
    pushBack(&v, 10);
    pushBack(&v, 11);
    if (!(v.capacity == startSize * 2 & v.size == 2)) {
        fprintf(stderr, "Test test_pushBack_fullVector is failed");

        exit(1);
    }
}

void test_popBack_notEmptyVector() {
    Vector v = createVector(10);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    if (!(v.capacity == 1 & v.size == 0)) {
        fprintf(stderr, "Test test_popBack_notEmptyVector is failed");

        exit(1);
    }
}

void tests() {
    test_pushBack_fullVector();
    test_pushBack_emptyVector();
    test_popBack_notEmptyVector();
}

int main() {
    tests();

    return 0;
}
