//convert an infix expression to prefix expression using array implementation of stack...

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 40

int top = -1;
char *arraystack = NULL;

int isFull()
{
    return top == MAX-1;
}

int isEmpty()
{
    return top == -1;
}

void push(char element)
{
    if(isFull())
        printf("stack is full.\n");
    else
        top++;
        arraystack[top] = element;    
}

int pop()
{
    if(isEmpty())
        return -1;
    return arraystack[top--];
}

int peek()
{
    if(isEmpty())
        return -1;
    return arraystack[top];    
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

int getPostfix(char *expressionArray)
{
    int currindex,j;
    for(currindex = 0,j=-1;expressionArray[currindex];++currindex)
    {
        if(isOperand(expressionArray[currindex]))
            expressionArray[++j] = expressionArray[currindex];
            //printf("%c",expressionArray[currindex]);

        else if(expressionArray[currindex] == '(')
            push(expressionArray[currindex]);

        else if(expressionArray[currindex] == ')')
        {
            while(!isEmpty() && peek() != '(')
                expressionArray[++j] = pop();
            if(!isEmpty() && peek() != '(')
                return -1;
            else       
                pop();    
        }

        else
        {
            while(!isEmpty() && precedence(expressionArray[currindex]) <= precedence(peek()))
            {
                expressionArray[++j] = pop();
            }
            push(expressionArray[currindex]);
        }
    }
    while(!isEmpty())
    {
        expressionArray[++j] = pop();
    }
    expressionArray[++j] = '\0';
}

void brackets(char *expressionArray)
{
    int i = 0;
    while(expressionArray[i] != '\0')
    {
        if(expressionArray[i] == '(')
            expressionArray[i] = ')';
        else if(expressionArray[i] == ')')
            expressionArray[i] = '(';  
        i++;     
    }
}

void reverse(char *expressionArray)
{
    int len = strlen(expressionArray);
    int j = len,i=0;
    char temp[len];
    temp[j--] = '\0';
    while(expressionArray[i] != '\0')
    {
        temp[j] = expressionArray[i];
        j--;
        i++;
    }
    strcpy(expressionArray,temp);
}

void InfixToPrefix(char *expressionArray)
{
    //reverse the string
    reverse(expressionArray);
    printf("reverse string is : %s\n",expressionArray);
    //change brackets 
    brackets(expressionArray);
    printf("string after brackets cahnge: %s\n",expressionArray);
    //get the postfix expression
    getPostfix(expressionArray);
    printf("postfix string is : %s\n",expressionArray);
    //reverse the string
    reverse(expressionArray);
    printf("expression after reverse : %s\n",expressionArray);
}

int main()
{
    char expressionArray[MAX];
    arraystack = (char *)malloc(sizeof(char) * MAX);

    printf("the infix expression is : \n");
    scanf("%s",expressionArray);

    printf("the infix expression you entered is %s \n",expressionArray);
    InfixToPrefix(expressionArray);

    printf("the prefix expression is : %s\n",expressionArray);
    return 0;
}
