// //convert an infix expression to postfix expression using array based stack implementation..

#include<stdio.h>
#include<stdlib.h>
#define MAX 40

char *arrayStack = NULL;

int top = -1;

int isEmpty()
{
    return top == -1;    
}

int isFull()
{
    return top == MAX-1;   
}

char peek()
{
    return arrayStack[top];    
}

char pop()
{
    if(isEmpty())
        return -1;
    char ch = arrayStack[top];
    top--;
    return ch;
}

void push(char element)
{
    if(isFull())
    {
        printf("stack is already full.\n");
    }
    else
    {
        top++;
        arrayStack[top] = element;
    }
}

int isOperand(char element)
{
    if(element >= 'A' && element <= 'Z' || element >= 'a' && element <= 'z' || element >= '1' && element <= '9')
        return 1;
    else
        return 0;    
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

void InfixToPostfix(char *expressionArray)
{
    printf("resultant postfix expression is: ");
    int currindex = 0;
    while(expressionArray[currindex] != '\0')
    {
        if(isOperand(expressionArray[currindex]))
            printf("%c",expressionArray[currindex]);

        else if(expressionArray[currindex] == '(')
            push(expressionArray[currindex]);

        else if(expressionArray[currindex] == ')')
        {
            while(peek() != '(')
                printf("%c",pop());
            pop();    
        }

        else
        {
            while(precedence(peek()) >= precedence(expressionArray[currindex]))
            {
                printf("%c",pop());
            }
            push(expressionArray[currindex]);
        }
        currindex++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
    printf("\n");
}

void main()
{
    char expressionArray[40];
    arrayStack = (char *)malloc(sizeof(char)* 40);
    printf("Enter the Infix Expression: \n");
    scanf("%s",expressionArray);
    printf("entered infix expression is: %s\n",expressionArray);

    InfixToPostfix(expressionArray);
}


