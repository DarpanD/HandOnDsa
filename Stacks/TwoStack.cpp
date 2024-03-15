// Keep it up Champ ;)

// codding ninja problem Two Stacks
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class TwoStack
{

public:
    int *st;
    int size;
    int top1;
    int top2;
    int count;

    // Initialize TwoStack.
    TwoStack(int s)
    {
        st = new int[s];
        this->size = s - 1;
        this->top1 = -1;
        this->top2 = -1; // can be done by top2 = size , so count will not be requiered
        this->count = 0;
    }

    // Push in stack 1.
    void push1(int num)
    {
        if (top1 >= size || count >= size + 1) // (top+1 == top2 )condition if decleared top2 = size
        {
            return;
        }

        top1++;
        st[top1] = num;
        count++;
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (top2 >= size || count >= size + 1)
        {
            return;
        }

        top2++;
        st[size - top2] = num;
        count++;
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (top1 == -1 || count == 0)
        {
            return -1;
        }

        top1--;
        count--;
        return st[top1 + 1];
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (top2 == -1 || count == 0)
        {

            return -1;
        }

        top2--;
        count--;
        return st[size - (top2 + 1)];
    }
};

int main()
{

    TwoStack sts(3);

    sts.push1(3);
    sts.push2(4);
    sts.push1(5);

    cout << sts.pop1() << endl;
    cout << sts.pop2() << endl;

    return 0;
}