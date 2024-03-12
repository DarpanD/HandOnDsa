// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL; // this way you make next to point at null
        }
    }
};

class Stack
{
public:
    Node *top;
    int size;
    int topIndex;

    Stack(int size)
    {
        top = nullptr;
        this->size = size;
        topIndex = -1;
    }

    bool isEmpty();

    void PUSH(int data);

    void POP();

    void PEEK();

    void PrintStack();

    ~Stack()
    {
        delete top;
    }
};

bool Stack::isEmpty()
{
    if (topIndex <= -1)
        return true;
    return false;
}

void Stack::PUSH(int data)
{
    if (topIndex >= size - 1)
    {
        cout << "Stack OverFlow" << endl;
        return;
    }
    Node *temp = new Node(data);
    temp->next = top;
    top = temp;
    topIndex++;
}

void Stack::POP()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return;
    }

    Node *temp = top;
    top = top->next;
    topIndex--;

    // deletes the useless node
    temp->next = NULL;
    delete temp;
}

void Stack::PEEK()
{
    if (isEmpty())
    {
        cout << "Stack UnderFlow" << endl;
    }
    else
    {
        cout << "\nTop Element of Stack   : " << top->data << endl;
        cout << "Index of top           : " << topIndex << endl;
        cout << "Remaining Space        : " << size - topIndex - 1 << endl;
    }
}

void Stack::PrintStack()
{
    cout << "\nPrinting Stack\n";
    if (isEmpty())
    {
        cout << "   Stack Underflow" << endl;
        return;
    }

    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << "  " << temp->next << endl;
        temp = temp->next;
    }
}

int main()
{
    Stack plates(4);

    plates.PUSH(10);
    plates.PUSH(20);
    plates.PUSH(30);
    plates.PUSH(40);
    plates.PUSH(50);

    plates.PrintStack();

    plates.PEEK();

    plates.POP();
    plates.POP();
    plates.POP();
    plates.POP();

    plates.PrintStack();

    return 0;
}