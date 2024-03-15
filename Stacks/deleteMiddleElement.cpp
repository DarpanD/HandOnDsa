// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

void deleteMiddle(stack<int> &inputStack, int N)
{
    int limit = (N % 2 == 0) ? (N / 2) - 1 : (N / 2);

    stack<int> temp;

    // store the above elements of middle element in temp stack
    for (int i = 0; i < limit; i++)
    {
        temp.push(inputStack.top());
        inputStack.pop();
    }

    // removing the middle element
    inputStack.pop();

    // reloading the elements in main stack
    for (int i = 0; i < limit; i++)
    {
        inputStack.push(temp.top());
        temp.pop();
    }
}

int main()
{

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << " Size : " << st.size() << " top : " << st.top() << endl;

    deleteMiddle(st, st.size());

    cout << " Size : " << st.size() << " top : " << st.top() << endl;

    return 0;
}