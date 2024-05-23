//convert an infix to postfix expression using a struct based stack approach..

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int maxSize;
    char *arrayStack;
};

struct stack *stk;

int isEmpty()
{
    return stk->top == -1;
}

int isFull()
{
    return stk->top == stk->maxSize - 1;
}

char peek()
{
    if(isEmpty())
        return -1;
    return stk->arrayStack[stk->top];    
}

char pop()
{
    if(isEmpty())
        return -1;
    char ch = stk->arrayStack[stk->top];
    stk->top--;
    return ch; 
}

void push(char element)
{
    if(isFull())
        printf("stack is full.\n");
    else
        stk->top++;
        stk->arrayStack[stk->top] = element;    
}

int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
                return 1;

        case '*':
        case '/':
                return 2;

        case '^':
                return 3;                        
    }
    return -1;
}

int isOperand(char element)
{
    if(element >= 'A' && element <= 'Z' || element >= 'a' && element <= 'z' || element >= '1' && element <= '9')
        return 1;
    else
        return 0;    
}

void InfixToPostfix(char *expressionArray)
{
    printf("resultant postfix expression is: \n");
    int currindex = 0;

    while(expressionArray[currindex] != '\0')
    {
        if(isOperand(expressionArray[currindex]))
            printf("%c",expressionArray[currindex]);

        else if(expressionArray[currindex] == '(' || expressionArray[currindex] == '{' || expressionArray[currindex] == '[')
            push(expressionArray[currindex]);

        else if(expressionArray[currindex] == ')' || expressionArray[currindex] == '}' || expressionArray[currindex] == ']')
        {
            if(expressionArray[currindex] == ']')
                while(peek() != '[')
                    printf("%c",pop());

            if(expressionArray[currindex] == '}')
                while(peek() != '{')
                    printf("%c",pop());

            if(expressionArray[currindex] == ')')
                while(peek() != '(')
                    printf("%c",pop());                
            pop();
        }
        else
        {
            while(precedence(peek()) >= precedence(expressionArray[currindex]))
                printf("%c",pop());
            push(expressionArray[currindex]);    
        }  
        currindex++;        
    }
    while(stk->top != -1)
    {
        printf("%c",pop());
    }
}

int main()
{
    char expressionArray[40];

    stk = (struct stack*)malloc(sizeof(struct stack));

    stk->maxSize = 40;
    stk->top == -1;
    stk->arrayStack = (char *)malloc(sizeof(char)*stk->maxSize);

    printf("enter the infix expression: \n");
    scanf("%s",expressionArray);

    printf("entered expression is %s .\n",expressionArray);

    InfixToPostfix(expressionArray);
    return 0;
}