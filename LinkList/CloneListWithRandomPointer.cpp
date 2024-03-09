// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <map>

using namespace std;

// 1st Class node for Link List Node creation
class Node
{ // a class node is made for linklist

    // chheck last
public:
    int data;
    Node *next;
    Node *random;

    // default constructor so that date can be filled at the time of creation
    Node(int data)
    {
        this->data = data;
        this->next = NULL; // by deafult save nest node to point at null
        this->random = NULL;
    }

    // destructor to delete a node
    ~Node()
    {
        // delete the next pointing at next node
        // this deletes the entire LL
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL; // this way you make next to point at null
        }
    }
};

// 3rd Printing
void PrintLL(Node *head)
{ // no need to send add of head (&head) , only head can be sent (node* head), done to reduce space

    // I - create a temp so that head is not changed
    Node *temp = head;
    // II - traverse LL till null / last node is found
    while (temp != NULL)
    {
        cout << temp->data << " next: " << temp->next << " random: " << temp->random << "  ";
        if (temp->random)
            cout << temp->random->data << endl;
        else
            cout << "NAN" << endl;
        temp = temp->next;
    }
}

// 4th Adding new nodes at end
void AddNewNodes(Node *&tail, int data)
{ // need to send last node with address '&' because we are updating it later

    // I - create new node
    Node *temp = new Node(data);
    // II - pointing tail node with new temp node
    tail->next = temp;
    // III- making temp as tail
    tail = temp;
}

// PROBLEM CODE

// first code made by me
Node *copyRandomList(Node *head)
{
    if (!head)
        return head;

    // dummy head
    Node *newHead = new Node(0);
    Node *car = newHead;

    unordered_map<int, Node *> visited;

    while (head)
    {

        auto data = visited.find(head->data);
        if (data == visited.end())
        {
            Node *naya = new Node(head->data);
            car->next = naya;
            car = car->next;

            // adding element in map
            visited[head->data] = naya;
        }
        else if (data != visited.end())
        {
            car->next = visited[head->data];
            car = car->next;
        }

        if (head->random)
        {

            auto data = visited.find(head->random->data);
            if (data == visited.end())
            {
                Node *naya = new Node(head->random->data);
                car->random = naya;

                // adding element in map
                visited[head->random->data] = naya;
            }
            else if (data != visited.end())
            {
                car->random = visited[head->random->data];
            }
        }

        head = head->next;
    }

    return newHead->next;
}

// code optimised by chatgpt of my first code
Node *copyrandomlist(Node *head)
{

    if (!head)
        return head;

    Node *dummyHead = new Node(0);
    Node *car = dummyHead;

    unordered_map<Node *, Node *> visited;

    while (head)
    {

        if (!visited.count(head))
            visited[head] = new Node(head->data);

        car->next = visited[head];
        car = car->next;

        if (head->random)
        {
            if (!visited.count(head->random))
                visited[head->random] = new Node(head->random->data);

            car->random = visited[head->random];
        }
        head = head->next;
    }
    return dummyHead->next;
}

// love baber approachs , TC : o(n) SC : O(1)
Node *ccopyRandomList(Node *head)
{

    Node *future = NULL;
    Node *car = head;

    // adding new node
    // original : 1->2->3->4->x
    // after : 1->1->2->2->3->3->4->4->x
    while (car)
    {
        future = car->next;
        car->next = new Node(car->data);
        car->next->next = future;
        car = future;
    }

    // adding randoms in the clone part of list
    car = head;

    while (car)
    {
        if (car->random)
            car->next->random = car->random->next;
        car = car->next->next;
    }

    Node *realHead = head;
    car = head->next;
    Node *copyHead = car;
    while (realHead)
    {
        realHead->next = realHead->next ? realHead->next->next : nullptr;
        car->next = car->next ? car->next->next : nullptr;
        realHead = realHead->next;
        car = car->next;
    }

    return copyHead;
}

int main()
{

    // DRIVER CODE
    // ============================

    Node *head = new Node(7);
    Node *tail = head;

    AddNewNodes(tail, 13);
    Node *thirteen = tail;
    AddNewNodes(tail, 11);
    Node *eleven = tail;
    AddNewNodes(tail, 10);
    Node *ten = tail;
    AddNewNodes(tail, 1);
    Node *one = tail;

    thirteen->random = head;
    eleven->random = one;
    ten->random = eleven;
    one->random = head;

    PrintLL(head);
    // ===============================

    cout << endl
         << endl;
    Node *newhead = ccopyRandomList(head);
    PrintLL(newhead);
}