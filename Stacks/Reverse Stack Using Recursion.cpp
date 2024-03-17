// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &stack, int num)
{

    if (stack.empty())
    {
        stack.push(num);
        return;
    }

    int top = stack.top();
    stack.pop();

    insertAtBottom(stack, num);

    stack.push(top);
}

void reverseStack(stack<int> &stack)
{

    if (stack.empty())
    {
        return;
    }

    int top = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, top);
}

int main()
{

    stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << " Size : " << stack.size() << " top : " << stack.top() << endl;

    reverseStack(stack);

    cout << " Size : " << stack.size() << " top : " << stack.top() << endl;

    return 0;
}