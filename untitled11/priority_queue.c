#include "priority_queue.h"
#include <stdlib.h>
#include <stdio.h>

// Bellek ayırma ve başlatma (Mühendislik yaklaşımı)
MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    if (heap == NULL) return NULL;

    heap->arr = (Request*)malloc(sizeof(Request) * capacity);
    if (heap->arr == NULL) {
        free(heap);
        return NULL;
    }

    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// İki isteğin yerini değiştiren yardımcı fonksiyon (Swap)
void swap(Request* a, Request* b) {
    Request temp = *a;
    *a = *b;
    *b = temp;
}

// Yeni eleman eklendiğinde yukarı doğru düzenleme (O(log n))
void heapifyUp(MinHeap* heap, int index) {
    if (index == 0) return;

    int parent = (index - 1) / 2;

    // RFC 9213: Küçük değer (priority) daha yüksek önceliktir
    if (heap->arr[index].priority < heap->arr[parent].priority) {
        swap(&heap->arr[index], &heap->arr[parent]);
        heapifyUp(heap, parent);
    }
}

// Eleman çıkarıldığında aşağı doğru düzenleme (O(log n))
void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left].priority < heap->arr[smallest].priority)
        smallest = left;

    if (right < heap->size && heap->arr[right].priority < heap->arr[smallest].priority)
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Kuyruğa yeni istek ekleme (malloc/realloc gerektirebilir ama burada kapasite sabit tutuldu)
void insert(MinHeap* heap, Request req) {
    if (heap->size == heap->capacity) {
        printf("Hata: Kuyruk dolu!\n");
        return;
    }

    heap->arr[heap->size] = req;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// En yüksek öncelikli (en küçük değerli) elemanı çekme
Request extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        Request empty = {-1, 99, 99};
        return empty;
    }

    Request root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    heapifyDown(heap, 0);

    return root;
}
