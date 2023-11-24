#ifndef STRUCTNODE_H
#define STRUCTNODE_H

struct Node
{
    char data;
    struct Node *next;
};

void push(char);
char pop();
int precedence(char);
void infixToPostfix(char[]);
void display();

#endif
