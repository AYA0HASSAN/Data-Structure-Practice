#include <stdio.h>
#include <stdlib.h>
typedef struct StackNode
{
    int Data;
    struct StackNode *Next;
}StackNode;


typedef struct Stack
{
    StackNode* Top;
    int size;

}Stack;


void Stack_voidintStack(Stack *ps);
void Stack_voidPush(Stack *ps,int num);
void Stack_voidPop(Stack *ps,int *popped);
int Stack_intIsEmpty(Stack *ps);
int Stack_intIsFull(Stack *ps);
int Stack_intReturnTopValue(Stack *ps);
void Stack_voidPrint(Stack *ps);
int Stack_Size(Stack *ps);
void Stack_Clear(Stack *ps);
int Stack_GetMin(Stack *ps);

int main()
{
    int i,j ,k;
    Stack s ;
    
    Stack_voidintStack(&s);
    Stack_voidPush(&s,10);
    Stack_voidPush(&s,5);
    Stack_voidPush(&s,11);
    Stack_voidPop(&s,&k);
    Stack_voidPush(&s,4);
    Stack_voidPush(&s,1);
    Stack_voidPush(&s,0);
    Stack_voidPrint(&s);
    i=Stack_Size(&s);
    printf("\nThe Size of the Stack = %d",i);
    printf("\nThe Popped Element of the Stack = %d",k);
    j=Stack_GetMin(&s);
    printf("\nThe Min Number In The Stack = %d",j);

    return 0;
}

void Stack_voidintStack(Stack *ps)
{
    ps->Top = NULL;
    ps->size = 0;
}


int Stack_intIsEmpty(Stack *ps)
{
    return (ps->Top->Next == NULL); 
}

int Stack_Size(Stack *ps)
{
    return ps->size;
}
int Stack_intIsFull(Stack *ps)
{
    return 0;
}
void Stack_voidPop(Stack *ps,int* popped)
{
    if(!Stack_intIsEmpty(ps))
    {   
        *popped =ps->Top->Data ;
        //pointer To the Poped Node
        StackNode * pn = ps->Top;
        ps->Top = ps->Top->Next;
        ps->size--;
        free(pn);
    }
    
}
int Stack_intReturnTopValue(Stack *ps)
{
    return ps->Top->Data;
}

void Stack_voidPush(Stack *ps,int num)
{
    //Create New Node;
    StackNode *pn = (StackNode*) malloc(sizeof(StackNode));
    //Make The Node Pointer To Point at the same as Top
    pn->Next = ps->Top;
    // Add New Value
    pn->Data = num;
    //Make The Top See The New Node
    ps->Top = pn ;
    ps->size++;

}
void Stack_Clear(Stack *ps)
{
    StackNode * pn = ps->Top;
    while (pn != NULL)
    {
        
        pn =ps->Top;
        free(ps->Top);
        ps->Top =pn;
    }
    ps->size=0;
    
}


void Stack_voidPrint(Stack *ps)
{
    StackNode * pn = ps->Top;
    while (pn != NULL)
    {
        printf("\n%d",pn->Data);
        pn = pn->Next;
    }
}
int Stack_GetMin(Stack *ps)
{
    StackNode *pn = ps->Top;
    int min = ps->Top->Data;
    while (pn != NULL)
    {
        if(pn->Data<min)
        {
            min = pn->Data;
        }
        pn = pn->Next;
    }
    return min;
    
}