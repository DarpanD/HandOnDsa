// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

class Stack
{
private:
     int top = -1;

     bool isFull()
     {
          if (top == size - 1) // size-1 coz we have started top from -1 instead of 0
               return true;
          return false;
     }

     bool isEmpty()
     {
          if (top == -1)
               return true;
          return false;
     }

public:
     int *stackArr;
     int size;
     Stack(int size)
     {
          stackArr = new int[size];
          // int StackArr[size];
          this->size = size;
     }
     ~Stack()
     {
          delete[] stackArr;
     }

     void push(int data)
     {
          if (isFull())
          {
               cout << "Stack OverFlow" << endl;
               return;
          }
          top++;
          stackArr[top] = data;
          cout << data << " pushed " << endl;
     }

     void pop()
     {
          if (isEmpty())
          {
               cout << "Stack UnderFlow" << endl;
               return;
          }
          cout << stackArr[top] << " poped" << endl;
          stackArr[top] = 0;
          top--;
     }

     void peek()
     {
          cout << "\nPEEK Operation Results \n";
          if (isEmpty())
          {
               cout << " Stack is Empty" << endl;
               return;
          }
          cout << "Top element     : " << stackArr[top] << endl;
          cout << "top index       : " << top << endl;
          cout << "Remaining size  : " << size - top - 1 << endl
               << endl;
     }
};

int main()
{

     // ======================
     //  STL functions of pre-built class STACK
     // ======================
     /*
     // creation of stack
     stack<int> plates;

     // basic stl operations
     cout << "Pushing 10 ,20 ,30 " << endl;
     plates.push(10);
     plates.push(20);
     plates.push(30);

     cout << "Top of Stack : " << plates.top() << endl;

     cout << "Size of Stack : " << plates.size() << endl
          << endl;

     cout << "Poping once " << endl;
     plates.pop();

     cout << "Top of Stack : " << plates.top() << endl;

     cout << "Size of Stack : " << plates.size() << endl
          << endl;

     if (plates.empty())
         cout << "Stack is empty" << endl
              << endl;
     else
         cout << "Stack is not empty" << endl
              << endl;

     cout << "Poping twice " << endl;
     plates.pop();
     plates.pop();

     if (plates.empty())
         cout << "Stack is empty" << endl
              << endl;
     else
         cout << "Stack is not empty" << endl
              << endl;
     cout << "Size of Stack : " << plates.size() << endl
          << endl;

     */

     // ======================
     // Building a Class Stack i.e. Implimentation of Stack Class
     // ======================
     Stack dish(5);

     dish.push(10);
     dish.push(20);
     dish.push(30);
     dish.push(40);
     dish.push(50);
     dish.push(60); // OverFlow

     dish.peek();

     dish.pop();
     dish.pop();
     dish.pop();

     dish.peek();

     dish.pop();
     dish.pop();

     dish.peek();
     return 0;
}