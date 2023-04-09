//
// Created by Марина on 09.04.2023.
//

#ifndef LAB18_VECTOR_H
#define LAB18_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Vector {
    int *data;       // указатель на элементы вектора
    size_t size;     // размер вектора
    size_t capacity; // вместимость вектора
} Vector;

//возвращает структуру-дескриптор вектор из n значений
Vector createVector(size_t n);

//возвращает структуру-дескриптор вектор,
//полученную из массива a размера size
Vector getVectorFromArray(const int* const a, int size);

//выводит вектор v
void outputVector(Vector v);

//изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(Vector *v, size_t newCapacity);

//удаляет элементы из вектора v, но не освобождает выделенную память
void clear(Vector *v);

//освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(Vector *v);

//очищает память, предназначенную для хранения вектора v
void deleteVector(Vector *v);

//возвращает значение "истина", если вектор пустой,
//иначе - "ложь"
bool isEmpty(Vector *v);

//возвращает значение "истина", если вектор заполнен,
//иначе - "ложь"
bool isFull(Vector *v);

//возвращает i-ый элемент вектора v
int getVectorValue(Vector *v, size_t i);

//добавляет элемент x в конец вектора v
void pushBack(Vector *v, int x);

//удаляет последний элемент из вектора v
void popBack(Vector *v);

#endif //LAB18_VECTOR_H
