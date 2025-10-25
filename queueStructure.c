#include <stdio.h>
#include <stdlib.h>

// FUNCTIONS
struct queue initQueue(int numberOfItems); 

// STRUCT
struct queue{
    int queueStartIndex;
    int queueEndIndex;
    int queueSize;
    int* queuePointer;
};

// MAIN
int main(){
    struct queue queue = initQueue(2);
    if (queue.queuePointer == NULL){
        return 1;
    }

    return 0;
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
