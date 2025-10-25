#include <stdio.h>
#include <stdlib.h>

// FUNCTIONS
struct queue initQueue(int numberOfItems);
void addToQueue(int item, struct queue queueStruct, struct queue *queueStructPointer); 
int peakQueue(struct queue queueStruct);

// STRUCT
struct queue{
    int queueStartIndex;
    int queueEndIndex;
    int queueSize;
    int* queuePointer;
};

// MAIN
int main(){
    // INITIALIZATION
    struct queue queue = initQueue(5);
    struct queue *pQueue = &queue;

    // ERROR HANDLING
    if (queue.queuePointer == NULL){
        return 1;
    }

    return 0;
}

int peakQueue(struct queue queueStruct){
    return queueStruct.queuePointer[queueStruct.queueStartIndex];
}

void addToQueue(int item, struct queue queueStruct, struct queue *queueStructPointer){
    queueStruct.queuePointer[queueStruct.queueEndIndex] = item;
    queueStructPointer->queueEndIndex = queueStruct.queueEndIndex + 1;
}

struct queue initQueue(int numberOfItems){
    int *pQueue = (int *)malloc(numberOfItems * sizeof(int));
    if (pQueue == NULL){
        struct queue failedQueueStruct = {0, 0, 0, NULL};
        printf("Error! Failed to allocate memory for the Queue\n");
        return failedQueueStruct;
    }

    struct queue queueStruct = {0, 0, numberOfItems, pQueue};
    return queueStruct;
}
