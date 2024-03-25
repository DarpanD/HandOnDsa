// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int findMinimumCost(string str)
{

    if (str.length() % 2 != 0)
        return -1;
    stack<char> st;
    char ch;
    for (int i = 0; i < str.length(); i++)
    {
        ch = str[i];

        if (ch == '}' && !st.empty() && st.top() == '{')
        {
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }

    int opencount = 0, closecount = 0;
    while (!st.empty())
    {
        char ch = st.top();
        if (ch == '{')
            opencount++;
        else if (ch == '}')
            closecount++;
        st.pop();
    }

    return ((opencount + 1) / 2 + (closecount + 1) / 2);
}

int main()
{

    string hello[] = {"{{{}",
                      "{{}",
                      "{}}",
                      "{{}{}}",
                      "{}}{}}",
                      "{{{{",
                      "{{{}}",
                      "}}}}{}}",
                      "}}}}}{",
                      "}}}{{}}}}}",
                      "}{}{}{{{}{",
                      "{{{{{{{}}"};

    for (string s : hello)
    {
        cout << s << " -> " << findMinimumCost(s) << endl;
    }

    return 0;
}