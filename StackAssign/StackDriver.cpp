//File name: StackDriver.cpp
//
//Author: Nicole Runas
//assignment number: 6
//cs2308 spring 2018
//instructor: Yijuan Lu
//
//This is the driver for the object stack, which detects simple
//syntax erros involving the matching and complete presence of (, {, and [
//
#include <iostream>
#include <fstream>
#include "IntStack.h"

using namespace std;

int main()
{
    ifstream fin;
    string filename;
    cout << "Please enter a file name." << endl;
    getline (cin, filename);
    fin.open(filename.c_str());
    IntStack stack;    

    if(!fin)
    {
        cout << "The file you named, " << filename << ", does not open.";
        return -1;
    }

    char symbol, popSymbol;

    while( !fin.eof() )
    {
        fin.get(symbol);
        if(symbol == '(' || symbol == '{' || symbol == '[')
        {
            stack.push(symbol);
        }
        else if(symbol == ')' || symbol == '}' || symbol == ']')
        {
            if(stack.isEmpty())
            {
                cout << "error: unmatched " << symbol << endl;
                return 0;
            }
            else
            {
                popSymbol = stack.pop();
                switch(popSymbol)
                {
                    case '(':
                          if(symbol != ')')
                          {
                              cout << "error: expected ) but found " << symbol << endl;
                              return 0;
                          }
                          else
                             break;
                    case '{':
                          if(symbol != '}')
                          {
                              cout << "error: expected } but found " << symbol << endl;
                              return 0;
                          }
                          else
                             break;
                    case '[':
                          if(symbol != ']')
                          {
                              cout << "error: expected ] but found " << symbol << endl;
                              return 0;
                          }
                          else
                             break;
                }
            }
        }
    }

    if(!stack.isEmpty())
    {
        popSymbol = stack.pop();
        if(popSymbol == '(')
            cout << "error: missing )" << endl;
        else if(popSymbol == '{')
            cout << "error: missing }" << endl;
        else if(popSymbol == '[')
            cout << "error: missing ]" << endl;
        return 0;
    }
return 0;
}
