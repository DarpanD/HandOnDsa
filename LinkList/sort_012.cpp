// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// 1st Class node for Link List Node creation
class Node{ // a class node is made for linklist

    public:
    int data;
    Node* next; // a node type of pointer is created to point nest node
    // next keyword is used to point next node

    // default constructor so that date can be filled at the time of creation
    Node(int data = 0){
        this->data = data; 
        this->next = NULL; // by deafult save nest node to point at null
    }

    // destructor to delete a node 
    ~Node() {
        // delete the next pointing at next node
        // this deletes the entire LL
        if(this->next != NULL) {
            delete next;
            this->next = NULL; // this way you make next to point at null
        }
    }
};

//2nd Instertion new node at first
void InsertionAtHead(Node* &head , int data){ // need to send head by address '&' because we are updating it later

    // I - Create a new node
    Node* temp = new Node(data);
    //  II - point head to next
    temp->next = head;
    // III - point head at temp to make it first node
    head = temp;
}

// 3rd Printing 
void PrintLL(Node* &head){ // no need to send add of head (&head) , only head can be sent (node* head), done to reduce space

    // I - create a temp so that head is not changed
    Node* temp = head;
    // II - traverse LL till null / last node is found
    int i = 0 ; // to see no of node during print 
    while (temp != NULL)
    {
        cout << i <<" "<< temp-> data << "  " << temp->next << endl;
        temp = temp->next;
        i++;
    }
}

// 4th Adding new nodes at end 
void AddNewNodes(Node* &tail , int data){ // need to send last node with address '&' because we are updating it later 

    // I - create new node
    Node* temp = new Node(data);
    // II - pointing tail node with new temp node
    tail->next = temp;
    // III- making temp as tail
    tail = temp;
}

// sort 0 1 2 func
void Sort012(Node* car){
    
    Node* zero = new Node();
    Node* zeroHead = zero;
    Node* one = new Node();
    Node* oneHead = one;
    Node* two = new Node();
    Node* twoHead = two;

    while (car)
    {
        Node*temp = car->next;
    
        if(car->data == 0){
            zero->next = car;
            car->next = NULL;
            zero = car;
        }
        else if(car->data == 1){
            one->next = car;
            car->next = NULL;
            one = car;
        }
        else if(car->data == 2){
            two->next = car;
            car->next = NULL;
            two = car;
        }
        car = temp;
    }

    if(oneHead->next ){
        zero->next = oneHead->next;
    }   
    else {
        //1s list -> empty
        zero-> next = twoHead -> next;
    }
    one->next = twoHead->next;

    car = zeroHead->next;
    PrintLL(car);
}


int main() {

    Node* head = new Node(1);
    Node* tail = head;
    AddNewNodes(tail, 0);
    AddNewNodes(tail, 2);
    AddNewNodes(tail, 1);
    AddNewNodes(tail, 0);
    AddNewNodes(tail, 2);
    AddNewNodes(tail, 1);

    Sort012(head);

    return 0;

}