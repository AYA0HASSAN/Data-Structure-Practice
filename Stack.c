#include<stdio.h>

#define MAX 100

typedef struct Stack{
	int Array[MAX];
	int Top;

}Stack;

void Stack_voidintStack(Stack *ps);
void Stack_voidPush(Stack *ps,int num);
void Stack_voidPop(Stack *ps);
int Stack_intIsEmpty(Stack *ps);
int Stack_intIsFull(Stack *ps);
int Stack_intReturnTopValue(Stack *ps);
void Stack_voidPrint(Stack *ps);
void Stack_Reverse(Stack *ps ,char *name ,int len);

int main(){

    Stack s;
    int i;
    Stack *ptr= &s;

    Stack_voidintStack(ptr);
    
    char name[6] = "hassan";
    
    for(i=0;i<6;i++)
    {
        printf("%c",name[i]);
    }
    
    printf("\n");
    Stack_Reverse(ptr,name,6);
   
    for(i=0;i<6;i++)
    {
        printf("%c",name[i]);
    }
    

    return 0;
}

void Stack_voidintStack(Stack *pc)
{
    pc -> Top = -1;
}

int Stack_intIsFull(Stack *ps)
{
    if(ps -> Top == MAX-1)
        return 1;
    else
        return 0;
}

int Stack_intIsEmpty(Stack *ps)
{
    if(ps -> Top == -1)
        return 1;
    else
        return 0;
}

void Stack_voidPush(Stack *ps,int num)
{
    if(! Stack_intIsFull(ps)){
        ps->Top ++;
        ps->Array[ps->Top]=num;
    }
    else 
    printf("The Stack is Full , You can't Add Elements");
}
void Stack_voidPop(Stack *ps)
{
    if(! Stack_intIsEmpty(ps))
        ps->Top--;
    else
        printf("The Stack is Already Empty");
}

void Stack_voidPrint(Stack *ps)
{
    int iterator = ps->Top;
    while (iterator!=-1)
    {
        printf("%c\n",ps->Array[iterator]);
        iterator--;
    }
    
}

int Stack_intReturnTopValue(Stack *ps)
{
    if(! Stack_intIsEmpty(ps))
        return ps->Array[ps->Top];
    else
        printf("The Stack is Already Empty");
}

void Stack_Reverse(Stack *ps,char* name,int len)
{
    int i,j;
    for(i=0;i<len;i++){
        Stack_voidPush(ps,name[i]); 
    }
    for (j=0;j<len;j++)
    {
        name[j]=Stack_intReturnTopValue(ps);
        Stack_voidPop(ps);
    }
}
