//
// Created by Марина on 09.04.2023.
//
#include "vector.h"

Vector getVectorFromArray(const int* const a, int size){
    Vector v;
    v.data = (int*)malloc(sizeof(int)*size);
    memcpy(v.data, a, sizeof(int) * size);
    v.size = size;
    v.capacity = size;

    return v;
}

void outputVector(Vector v){
    printf("[");
    if (v.size) {
        for (int i = 0; i < v.size - 1; i++)
            printf("%d, ", v.data[i]);
        printf("%d",v.data[v.size - 1]);
    }
    printf("]");
}

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

bool isEmpty(Vector *v){
    return v->size == 0;
}

bool isFull(Vector *v){
    return v->size == v->capacity;
}

int getVectorValue(Vector *v, size_t i){
    return v->data[i];
}

void pushBack(Vector *v, int x) {
    if (v->size == v->capacity) {
        int newCapacity = v->capacity == 0 ? 1 : v->capacity * 2;
        reserve(v, newCapacity);
    }
    v->data[v->size] = x;
    v->size++;
}

void popBack(Vector *v){
    if (isEmpty(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }
    v->size--;

}