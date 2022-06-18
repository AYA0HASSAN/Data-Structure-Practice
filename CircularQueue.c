
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Queue {
    int Front;
    int Rare;
    int size;
    int Array[MAX];
}Queue;
void Queue_voidintQueue(Queue *pq);
void Queue_voidEnQueue(Queue *pq,int num);
void Queue_voidDeQueue(Queue *pq,int *dequeued);
int Queue_intIsEmpty(Queue *pq);
int Queue_intIsFull(Queue *pq);
int Queue_intReturnFirstValue(Queue *pq);
int Queue_intReturnSize(Queue *pq);
void Queue_voidPrint(Queue *pq);

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
    return 0;
}

void Queue_voidintQueue(Queue *pq)
{
    pq->Front =-1;
    pq->Rare =-1;
    pq->size = 0;
}
void Queue_voidEnQueue(Queue *pq,int num)
{
{
    if(Queue_intIsEmpty(pq)){
        pq->Front = pq->Rare =0;
        pq->Array[pq->Front]=num;
         pq->Array[pq->Rare]=num;
    }
    else{
        if(pq->Rare == MAX-1 && pq->Front != 0){
        pq->Rare = 0;
        pq->Array[pq->Rare]=num;

        }
        else{
        pq->Rare++;
        pq->Array[pq->Rare]=num;        
    }
    }
    pq->size++;
}
}
void Queue_voidDeQueue(Queue *pq,int *dequeued)
{
     if(!Queue_intIsEmpty(pq))
    {
        *dequeued = pq->Array[pq->Front];
        pq->size--;
        
        if(pq->Front == pq->Rare)
        {
            pq->Front = pq->Rare = -1;
        }
        else {
            if(pq->Front == MAX-1){
            pq->Front = 0;
        }else pq->Front++;

        }
    }   
}
int Queue_intIsEmpty(Queue *pq)
{
    return pq->Front == -1;
}
int Queue_intIsFull(Queue *pq)
{
    return (pq->Front == pq->Rare-1 || pq->Front ==0 && pq->Rare == MAX-1);
}
int Queue_intReturnFirstValue(Queue *pq)
{
    return pq->Array[pq->Front];
}
int Queue_intReturnSize(Queue *pq)
{
    return pq->size;
}
void Queue_voidPrint(Queue *pq)
{
    int iter ;
    if(pq->Rare > pq->Front){
        iter = pq->Front;
        while(iter <= pq->Rare)
        {
            
            printf("\n%d",pq->Array[iter]);
            iter++;
        }
    }
    else{
        iter = pq->Front;
        while(iter < pq->size)
        {
           
            printf("\n%d",pq->Array[iter]);
            iter++;
        }
        /*iter = 0;
        while(iter<=pq->Rare)
        {
            printf("\n%d",pq->Array[iter]);
            iter++;
        }*/
    }
}