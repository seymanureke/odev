#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "request.h"

typedef struct {
    Request* arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity);
void insert(MinHeap* heap, Request req);
Request extractMin(MinHeap* heap);
#endif