//File name: IntStack.cpp
//
//author: Nicole Runas
//assignment number:6 
//cs2308 spring 2018
//instructor: Yijuan Lu
//
//this is all of the function definions for the stack
#include <iostream>
#include "IntStack.h"
#include <cassert>


using namespace std;

//constructor
IntStack :: IntStack ()
{
    head = NULL;
}

//deconstructor
IntStack :: ~IntStack()
{
    Node * p1;
    Node * p2;
    p1 = head;
 
    while(p1!=NULL)
    {
        p2 = p1;
        p1 = p1 -> next;
        p2 -> next = NULL;
        delete p2;
    }
}

//name: isFull
//no parameters
//returns nothing, returns false when the stack is not full
bool IntStack :: isFull()
{
    return false;
}

//name: isEmpty
//no parameters
//returns nothing, sets the head to null to check if the stack is empty
bool IntStack :: isEmpty()
{
    return head == NULL;
}

//name: push
//parameters: symbol, an integer that gets pushed into the top of the stack
//returns nothing
void IntStack :: push (int symbol)
{
    assert (!isFull());

    Node * temp = new Node;
    temp -> data = symbol;
    temp -> next = head;
    head = temp;
}

//name: pop
//no parameters
//returns the value sitting at the top of the stack
int IntStack :: pop()
{
    assert (!isEmpty());
 
    int result = head -> data;
    Node * temp = head;
    head = head -> next;
    delete temp;
    return result;
}
