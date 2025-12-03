#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// FUNCTIONS
struct queue initQueue(int numberOfItems);
bool addToQueue(int item, struct queue queueStruct, struct queue *queueStructPointer); 
int peakQueue(struct queue queueStruct);
bool popQueue(struct queue queueStruct, struct queue *queueStructPointer);
bool freeQueue(struct queue queueStruct, struct queue *queueStructPointer);

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

    freeQueue(queue, pQueue);
    pQueue = NULL;

    return 0;
}

bool freeQueue(struct queue queueStruct, struct queue *queueStructPointer){
    // Error Handling
    if (queueStructPointer == NULL){
        printf("Error! queueStructPointer is Null.");
        return false;
    }
    
    if (queueStruct.queuePointer == NULL){
        printf("Error! queuePointer is Null.");
        return false;
    }

    free(queueStruct.queuePointer);
    queueStructPointer->queuePointer = NULL;
    queueStructPointer->queueLength = -1;
    queueStructPointer->queueStartIndex = -1;
    queueStructPointer->queueEndIndex = -1;
    queueStructPointer->queueSize = -1;
    return true;
}

bool popQueue(struct queue queueStruct, struct queue *queueStructPointer){
    // Error if you atempt to access a freed queue
    if (queueStruct.queueSize == -1){
        printf("Error! The queue you are atempting to access has been freed from memory.\n");
        return false;
    }

    // Checks if there are no items in queue
    if (queueStruct.queueLength == 0){
        printf("Queue is empty!\n");
        return false;
    } 

    queueStructPointer->queueStartIndex = (queueStruct.queueStartIndex > queueStruct.queueSize) ? 0 : queueStruct.queueStartIndex + 1;
    int returnValue = queueStruct.queuePointer[queueStruct.queueStartIndex];
    queueStruct.queuePointer[queueStruct.queueStartIndex] = 0;
    queueStructPointer->queueLength -= 1;
    return true;
}

int peakQueue(struct queue queueStruct){
    // Error if you atempt to access a freed queue
    if (queueStruct.queueSize == -1){
        printf("Error! The queue you are atempting to access has been freed from memory.\n");
    }
    else{
        return queueStruct.queuePointer[queueStruct.queueStartIndex];
    }
}

bool addToQueue(int item, struct queue queueStruct, struct queue *queueStructPointer){
    // Error if you atempt to access a freed queue
    if (queueStruct.queueSize == -1){
        printf("Error! The queue you are atempting to access has been freed from memory.\n");
        return false;
    }
    
    // Returns false if queue is full
    if (queueStruct.queueLength + 1 > queueStruct.queueSize){
        printf("Error! Queue is Full.\n");
        return false;
    }

    queueStruct.queuePointer[queueStruct.queueEndIndex] = item;
    queueStructPointer->queueLength += 1;
    queueStructPointer->queueEndIndex = (queueStruct.queueEndIndex > queueStruct.queueSize) ? 0 : queueStruct.queueEndIndex + 1;
    return true;
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
