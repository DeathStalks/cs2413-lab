// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in Student.h.
//
// You are designing a fixed-size queue with capacity k.
// The queue supports enqueue/dequeue in O(1) time using a circular array.
//
// Recommended invariants (simple + robust):
// - Use an integer `size` to track how many elements are currently stored.
// - Queue is empty  <=> size == 0
// - Queue is full   <=> size == capacity
// - `head` points to the current front element
// - `tail` points to the next insertion position
// - Wrap indices using modulo: (idx + 1) % capacity
//
// Examples (k = 3):
//   enQueue(1) -> true    queue: [1]
//   enQueue(2) -> true    queue: [1,2]
//   enQueue(3) -> true    queue: [1,2,3]
//   enQueue(4) -> false   (full)
//   Rear()     -> 3
//   isFull()   -> true
//   deQueue()  -> true    queue: [2,3]
//   enQueue(4) -> true    queue: [2,3,4]
//   Rear()     -> 4
//   Front()    -> 2
//
// Return values rules:
// - Front / Rear should return -1 if the queue is empty.
//
// How to run tests (from the folder containing the Makefile):
//   make run2
// ------------------------------------------------------------

#include "Student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool

MyCircularQueue* myCircularQueueCreate(int k) {
    // Allocate the queue structure itself
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (!obj) return NULL; // Safety check
    
    // Allocate the internal buffer `data` of length k
    obj->data = (int*)malloc(k * sizeof(int));
    if (!obj->data) {
        free(obj);
        return NULL;
    }
    
    // Initialize variables
    obj->capacity = k;
    obj->head = 0;
    obj->tail = 0;
    obj->size = 0;
    
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    // If full, return false
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    
    // Write value at tail, advance tail (wrap), size++
    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->size++;
    
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    // If empty, return false
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    
    // Advance head (wrap), size--
    obj->head = (obj->head + 1) % obj->capacity;
    obj->size--;
    
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    // Return -1 if empty
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    
    // Otherwise return data[head]
    return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    // Return -1 if empty
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    
    // tail points to the *next* insertion position.
    int last_index = (obj->tail - 1 + obj->capacity) % obj->capacity;
    return obj->data[last_index];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    // Return true if size == 0
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    // Return true if size == capacity
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    // Free internal buffer then free obj
    if (obj != NULL) {
        if (obj->data != NULL) {
            free(obj->data);
        }
        free(obj);
    }
}