#include <stdio.h>
#include <stdlib.h>

// FUNCTIONS
struct queue initQueue(int numberOfItems);
void addToQueue(int item, struct queue queueStruct, struct queue *queueStructPointer); 
int peakQueue(struct queue queueStruct);
void popQueue(struct queue queueStruct, struct queue *queueStructPointer);

// STRUCT
struct queue{
    int queueStartIndex;
    int queueEndIndex;
    int queueSize;
    int* queuePointer;
    int queueLength;
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

    // Adding test items to the queue
    for (int i=0; i<queue.queueSize; i++){
        addToQueue(i, queue, pQueue);
    }



    return 0;
}

void popQueue(struct queue queueStruct, struct queue *queueStructPointer){
    // Checks if there are no items in queue
    if (queueStruct.queueStartIndex != queueStruct.queueEndIndex){
        int returnValue = queueStruct.queuePointer[queueStruct.queueStartIndex];
        queueStruct.queuePointer[queueStruct.queueStartIndex] = 0;
        queueStructPointer->queueStartIndex += 1;
    }
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
        struct queue failedQueueStruct = {0, 0, 0, NULL, 0};
        printf("Error! Failed to allocate memory for the Queue\n");
        return failedQueueStruct;
    }

    struct queue queueStruct = {0, 0, numberOfItems, pQueue, 0};
    return queueStruct;
}
