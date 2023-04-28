/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
using namespace std;
#include <stack>

void sortedInsert(stack<int> &s, int element)
{
    if (s.empty() || s.top() < element)
    {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();
    sortedInsert(s, element);
    s.push(top);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int top = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, top);
}

void printStack(stack<int> stack)
{
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> stack;
    stack.push(5);
    stack.push(1);
    stack.push(2);
    stack.push(6);
    stack.push(4);

    cout << "Stack before sorting: ";
    printStack(stack);

    sortStack(stack);

    cout << "Stack after sorting: ";
    printStack(stack);

    return 0;
}