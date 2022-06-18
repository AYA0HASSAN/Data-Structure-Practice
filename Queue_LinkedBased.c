#include<stdio.h>
#include <stdlib.h>
typedef struct QueueNode{
    int Data;
    struct QueueNode *Next;
}QueueNode;

typedef struct Queue {
    QueueNode* Front;
    QueueNode* Rare;
    int size;
}Queue;

void Queue_voidintQueue(Queue *pq);
void Queue_voidEnQueue(Queue *pq,int num);
void Queue_voidDeQueue(Queue *pq,int *dequeued);
int Queue_intIsEmpty(Queue *pq);
int Queue_intIsFull(Queue *pq);
int Queue_intReturnFirstValue(Queue *pq);
int Queue_intReturnSize(Queue *pq);
void Queue_voidPrint(Queue *pq);
void Queue_voidClear(Queue *pq);
void Queue_voidSort(Queue *pq);



int main()
{
    Queue q;
    Queue *pq = &q;
    int size;
    int first; 
    int deq;
    Queue_voidintQueue(pq);
    Queue_voidEnQueue(pq,8);
    Queue_voidEnQueue(pq,10);
    Queue_voidEnQueue(pq,6);
    Queue_voidEnQueue(pq,2);
    Queue_voidEnQueue(pq,0);
    Queue_voidPrint(pq);
    size = Queue_intReturnSize(pq);
    printf("\nThe Size Of The Queue = %d",size);
    first = Queue_intReturnFirstValue(pq);
    printf("\nThe First Element In The Queue = %d",first);
    Queue_voidDeQueue(pq,&deq);
    printf("\nThe DeQueued Element From The Queue = %d",deq);
    Queue_voidPrint(pq);
    Queue_voidSort(pq);
    printf("The Sorted Elements");
    Queue_voidPrint(pq);

    return 0;
}

void Queue_voidintQueue(Queue *pq)
{
    pq->Front = NULL;
    pq->Rare = NULL;
    pq->size = 0;
}
void Queue_voidEnQueue(Queue *pq,int num)
{
    //Create New Node;
    QueueNode *qn = (QueueNode*)malloc(sizeof(QueueNode));
    qn->Data = num;
    qn->Next = NULL;
    pq->size++;
    //check for Inserting First Node
    if(pq->Front == NULL)
    {
        pq->Front = qn;
        pq->Rare = qn;
    }
    else{
        pq->Rare->Next = qn;
        pq->Rare = qn;
    }

}
void Queue_voidDeQueue(Queue *pq,int *dequeued)
{
    *dequeued = pq->Front->Data;
    QueueNode *qn = pq->Front;
    if(pq->Front->Next == NULL){
       pq->Rare = NULL;
    }
    pq->Front = pq->Front->Next;
    pq->size--;
    free(qn);
}
int Queue_intIsEmpty(Queue *pq)
{
    return pq->Rare == NULL && pq->Front == NULL;
}
int Queue_intIsFull(Queue *pq)
{
    return 0;
}
int Queue_intReturnFirstValue(Queue *pq)
{
    return pq->Front->Data;
}
int Queue_intReturnSize(Queue *pq)
{
    return pq->size;
}
void Queue_voidPrint(Queue *pq)
{
    if(!Queue_intIsEmpty(pq))
    {
        QueueNode* iter = pq->Front;
        while (iter != NULL )
        {
            printf("\n%d",iter->Data);
            iter = iter->Next;
        }
    }
    else
        printf("\nNO Elements Found");
    
}

void Queue_voidClear(Queue *pq)
{
    QueueNode *qn = pq->Front;
    while(qn != NULL)
    {
        if(pq->Front->Next == NULL)
        {
            pq->Rare = NULL;
        }
        pq->Front = pq->Front->Next;
        pq->size--;
        free(qn); 
        qn= qn->Next;

    }
  
}

void Queue_voidSort(Queue *pq)
{
    QueueNode *qn = pq->Front;
    QueueNode *temp = NULL;
    QueueNode *node = NULL;
    int hold;
    while(qn != NULL)
    {
        node = qn;
        temp = qn->Next;
        while(temp!=NULL)
        {
            if(node->Data > temp->Data){
                node=temp;
            }
            temp = temp->Next;
        }
        if(qn->Data > node->Data)
        {
            hold = qn->Data;
            qn->Data = node->Data;
            node->Data = hold;
        }
        qn = qn->Next;
    }
}

