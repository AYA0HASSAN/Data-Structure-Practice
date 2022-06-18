#include<stdio.h>
#include <stdlib.h>


typedef struct ListNode{
    int Data;
    struct ListNode *Next;
}ListNode;

typedef struct List{
    ListNode* Head;
    int size;
}List;

/////////////////////////////////////Function ProtoType///////////////////////////////////////////////////////////
void List_voidIntList(List *pl);
void List_voidInsertNode(List *pl , int position , int num);
void List_voidReplaceData(List *pl , int position , int num);
void List_voidDeleteNode(List *pl , int position , int *data);
void List_voidRetriveData(List *pl , int position , int *data);
void List_voidDestroyList(List *pl);
int List_intIsEmpty(List *pl);
int List_intIsFull(List *pl);
int List_intSize(List *pl);
void List_voidPrint(List *pl);


int main()
{
    List l;
    List *pl = &l;
    int retrev,size,del;
    List_voidIntList(pl);
    List_voidInsertNode(pl,0,10);
    List_voidInsertNode(pl,1,4);
    List_voidInsertNode(pl,2,7);
    List_voidInsertNode(pl,3,3);
    printf("List Element:");
    List_voidPrint(pl);
    List_voidRetriveData(pl,1,&retrev);
    printf("\nRetrive of Index 1: %d",retrev);
    List_voidReplaceData(pl,3,9);
    printf("\nList After Replaceing Data Of Index 3 (3->9)");
    List_voidPrint(pl);
    size = List_intSize(pl);
    printf("\nThe Size Of List = %d",size);
    List_voidDeleteNode(pl,0,&del);
    printf("\nElements After Deleting Index 0 :");
    List_voidPrint(pl);
    List_voidDestroyList(pl);
    size = List_intSize(pl);
    printf("\nThe Size Of List After Destruction = %d",size);

    
    return 0;
}

void List_voidIntList(List *pl)
{
    pl->Head = NULL;
    pl->size = 0;
}

void List_voidInsertNode(List *pl , int position , int num)
{
    //Create New Node
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->Data = num;
    node->Next = NULL;
    //condition if it Illogical Position
    if(position>pl->size)
    {
        printf("Invalied Position of Insertion");
    }
    else{
        if(position==0){
            ListNode* temp = pl->Head;
            node->Next=temp;
            pl->Head=node;

        }
        else{
            ListNode *iter;
            int i;
            for(iter = pl->Head,i=0 ; i<position-1 ; i++){
                iter = iter->Next;
            }
            ListNode *temp = iter->Next;
            node->Next = temp;
            iter->Next = node;

        }
        pl->size++;
    }
}
void List_voidReplaceData(List *pl , int position , int num)
{
    if(position==0){
        pl->Head->Data = num;
    }
    else{
        ListNode *iter;
        int i;
        for(iter = pl->Head,i=0 ; i<position ;i++){
            iter = iter->Next;
        }
        iter->Data = num;
    }
}
void List_voidDeleteNode(List *pl , int position , int *data)
{
    if(position>pl->size){
        printf("\nNo Such Position!!!!!!!");

    }
    else{
        if(position==0){
            ListNode *temp = pl->Head->Next;
            *data =pl->Head->Data;
            free(pl->Head);
            pl->Head = temp;
        }
        else{
            ListNode *iter;
            int i;
            for(iter = pl->Head,i=0; i<position-1 ; i++){
                iter = iter->Next;
            }
            *data = iter->Next->Data;
            ListNode *temp = iter->Next->Next;
            free(iter->Next);
            iter->Next = temp;
        }
        pl->size--;
    }
}
void List_voidRetriveData(List *pl , int position , int *data)
{
    if(position == 0){
        *data = pl->Head->Data;
    }
    else{
        ListNode *iter;
        int i;
        for(iter = pl->Head,i=0; i<position ;i++){
            iter = iter->Next;
        }
        *data = iter->Data;
    }
}
void List_voidDestroyList(List *pl)
{
    ListNode *iter=pl->Head;
    while(iter!=NULL)
    {
        iter = pl->Head->Next;
        pl->size--;
        free(pl->Head);
        pl->Head = iter;

    }
}
int List_intIsEmpty(List *pl)
{
    return pl->Head == NULL;
}
int List_intIsFull(List *pl)
{
    return 0;
}
int List_intSize(List *pl)
{
    return pl->size;
}
void List_voidPrint(List *pl)
{
    ListNode *iter = pl->Head;
    while(iter!=NULL)
    {
        printf("\n%d",iter->Data);
        iter = iter->Next;
    }
}