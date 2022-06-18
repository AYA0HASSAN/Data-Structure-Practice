
#include <iostream>
#include <string>
using namespace std;

#define MAX 30

class Stack
{
    public:
    //string strArray[MAX];
    char  CharArray[MAX];
    int Top;
    Stack()
    {
        Top=-1;
    }
    void Stack_Pop()
    {
        if(Top!=-1)
        {
            Top--; 
        }
        else
            cout<<"There are No Elements ";
    }
    void Stack_Push(char character)
    {
        if(Top==MAX-1)
            cout<<"You Can't Add New Element";
        else
        {
            Top++;
            CharArray[Top]=character;
        }
    }
    bool Stack_IsEmpty()
    {
        return (Top==-1);
    }
     bool Stack_IsFull()
    {
        return (Top==MAX-1);
    }
    void Stack_Print()
    {
        int i = Top;
        while(i != -1)
        {
            cout<<CharArray[i];
            i--;

        }
    }
    void Stack_ReturnTopValue(string *character)
    {
        if(Top!=-1)
        {
            *character = CharArray[Top];
        }
        else
            cout<<"There are No Elements ";
            
        
    }

    bool Stack_IsBalanced()
    {
        int iter = Top;
        Stack openB;
        while(iter!= -1)
        {
            switch (CharArray[Top])
            {
                 case '(':
                    openB.Stack_Push(CharArray[Top]);
                    Stack_Pop();
                    iter--;
                    break;
                case '{':
                    openB.Stack_Push(CharArray[Top]);
                    Stack_Pop();
                    iter--;
                    break;
                case '[':
                    openB.Stack_Push(CharArray[Top]);
                    Stack_Pop();
                    iter--;
                    break;
            }
            iter--;
            
            if(CharArray[Top]==')' && openB.CharArray[Top]=='(')
            {
                Stack_Pop();
                openB.Stack_Pop();
                continue;
            }
            else break;
            if(CharArray[Top]=='}' && openB.CharArray[Top]=='{')
            {
                Stack_Pop();
                openB.Stack_Pop();
                continue;
            }
             else break;
            if(CharArray[iter]==']' && openB.CharArray[Top]=='[')
            {
                Stack_Pop();
                openB.Stack_Pop();
                continue;
                
            }
             else break;
        
            
        }
        //if(openB.Stack_IsEmpty()) 
       return openB.Stack_IsEmpty();  
        
    }

};
 

int main()
{
    Stack s1 ;
    string str;
    bool balance;
    int i;
    cout<<"Enter your String";
    cin>>str;
    for(i=0;i<str.length();i++)
    {
        s1.Stack_Push(str[i]);
    }
    s1.Stack_Print();
    cout<<"\n";
    balance=s1.Stack_IsBalanced();
    if(balance==true)
        cout<<"\nBalanced";
    else
        cout<<"\nNOT Balanced";


    return 0;
}