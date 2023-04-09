//
// Created by Марина on 09.04.2023.
//

#ifndef LAB18_VECTOR_H
#define LAB18_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <assert.h>

typedef struct Vector {
    int *data;       // указатель на элементы вектора
    size_t size;     // размер вектора
    size_t capacity; // вместимость вектора
} Vector;

//возвращает структуру-дескриптор вектор из n значений
Vector createVector(size_t n);

//изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(Vector *v, size_t newCapacity);

//удаляет элементы из вектора v, но не освобождает выделенную память
void clear(Vector *v);

//освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(Vector *v);

//очищает память, предназначенную для хранения вектора v
void deleteVector(Vector *v);


#endif //LAB18_VECTOR_H
