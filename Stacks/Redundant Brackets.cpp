// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;

void printStack(stack<char> temp)
{
    cout << endl;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;
}

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    bool ans = false;
    // cout << typeid(s[i]).name() << endl;
    char ch;
    for (int i = 0; i < s.length(); i++)
    {
        ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            ans = true;
            while (st.top() != '(')
            {
                char topelement = st.top();
                if (topelement == '+' || topelement == '-' || topelement == '*' || topelement == '/')
                    ans = false;

                st.pop();
            }
            if (ans == true)
                return ans;
            st.pop();
        }
    }
    return false;
}

int main()
{
    string s = "(a+c*b)+(c))";
    // string s = "(a+b)";
    // string s = "(a+c*b)+(c)";
    // string s = "(a*b+(c/d))";
    // string s = "((a/b))";

    if (findRedundantBrackets(s))
    {
        cout << " yes redundant brackets are present" << endl;
    }
    else
    {
        cout << " No , redundant brackets are not present" << endl;
    }
    return 0;
}