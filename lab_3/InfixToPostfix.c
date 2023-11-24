#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "StructNode.h"

struct Node *top = NULL;

int main()
{
    printf("\n\nTHIS PROGRAM CONVERTS AN INFIX EXPRESSION TO A POSTFIX EXPRESSION. THE PROGRAM MAKES USE OF STACK FUNCTIONALITY WHICH IS IMPLEMENTED USING LINKED LISTS.\n\n");
    char infixExpression[100];
    while (1)
    {
        int x;
        printf("\n1. Convert Infix Expression to Postfix Expression\n2. Exit\n\nEnter your choice:");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nEnter an infix expression: ");
            scanf("%s", infixExpression);
            infixToPostfix(infixExpression);
            break;
        case 2:
            return 0;
        case 3:
            printf("Invalid Choice.");
        }
    }
    return 0;
}

void push(char value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char pop()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return '\0';
    }
    else
    {
        struct Node *temp = top;
        char popped = temp->data;
        top = temp->next;
        free(temp);
        return popped;
    }
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[])
{
    int i, j;
    char postfix[100];
    for (i = 0, j = -1; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[++j] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != NULL && top->data != '(')
            {
                postfix[++j] = pop();
            }
            if (top != NULL && top->data != '(')
            {
                printf("Invalid expression.\n");
                return;
            }
            else
            {
                pop();
            }
        }
        else
        {
            while (top != NULL && precedence(infix[i]) <= precedence(top->data))
            {
                postfix[++j] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != NULL)
    {
        postfix[++j] = pop();
    }
    postfix[++j] = '\0';
    printf("Converted infix to postfix: %s\n", postfix);
}

void display()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
