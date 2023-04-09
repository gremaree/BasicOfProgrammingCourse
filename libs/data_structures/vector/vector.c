//
// Created by Марина on 09.04.2023.
//
#include "vector.h"

void checkMemory(Vector *v) {
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

Vector createVector(size_t n) {
    Vector v;
    if (n) {
        v.data = (int *) malloc(sizeof(int) * n);
        checkMemory(&v);
        v.size = 0;
        v.capacity = n;
    } else {
        v.data = NULL;
        v.size = 0;
        v.capacity = 0;
    }

    return v;
}

void reserve(Vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
    } else {
        v->size = newCapacity < v->size ? newCapacity : v->size;
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        checkMemory(v);
    }
    v->capacity = newCapacity;
}

void clear(Vector *v) {
    v->size = 0;
}

void shrinkToFit(Vector *v) {
    v->capacity = v->size;
}

void deleteVector(Vector *v) {
    free(v->data);

    v->size = 0;
    v->capacity = 0;
}

