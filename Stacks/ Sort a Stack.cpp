// Keep it up Champ ;)

/*
Problem statement
You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

We can only use the following functions on this stack S.

is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
Note :
1) Use of any loop constructs like while, for..etc is not allowed.
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive or zero.
*/

#include <iostream>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

void SortedInsertion(stack<int> &stack, int element)
{

    int yo = stack.empty() ? 0 : stack.top();
    cout
        << "element " << element << " top " << yo << endl;

    if (stack.empty() || stack.top() <= element)
    {
        cout << element << " pushed in stack" << endl;
        stack.push(element);
        return;
    }

    // if top is bigger then element , that means element must be one place lower to top
    int topelement = stack.top();
    stack.pop();

    cout << topelement << " pop out " << endl;

    // now rechecking is element can be placed
    SortedInsertion(stack, element);

    // returned that means element is placed
    //  now pushing the removed topelement
    cout << "   All elements smaller than " << topelement << " pushed , now pushing it" << endl
         << endl;

    stack.push(topelement);
}

void sortStack(stack<int> &stack)
{

    if (stack.empty())
        return;

    // storing top
    int topelement = stack.top();
    stack.pop();

    cout << "Poped " << topelement << endl;

    // recursive call
    sortStack(stack);

    // now stack is empty . now insertion should be in sorted order
    cout << "   calling sortedInsertion... " << endl;

    SortedInsertion(stack, topelement);
}
void printStack(stack<int> temp)
{
    cout << endl;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;
}

int main()
{

    stack<int> st;
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);

    printStack(st);

    cout << "Working... " << endl;
    sortStack(st);

    printStack(st);

    return 0;
}