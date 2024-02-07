// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{ // a class node is made for linklist

    public:
    int data;
    Node* next; // a node type of pointer is created to point nest node
    // next keyword is used to point next node

    // default constructor so that date can be filled at the time of creation
    Node(int data){
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
    cout << endl << endl ;
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

Node* reverseKGroup(Node* head, int k) {

    // base case - check if last node is reached
    if(head == NULL || head->next == NULL) return head;

    // if  nu of remaining node less then k  , return so that it is not reversed
    int checkcount = 1;
    Node* travelnode = head;
    while(checkcount < k){
        travelnode = travelnode->next;
        if(!travelnode)return head;
        checkcount++;
    }

    // basic reverse operation of k nodes

    Node* prev = head;
    Node* curr = head->next;
    
    int count = 1;
    while (count < k  && curr != NULL)
    {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++ ;
    }


    // attacking the reverse list ahead
    head->next = reverseKGroup(curr , k);

    // prev will be the first node after reverse ,so it will be attached to resaining list
    return prev;
}

int main(){

    Node* haha = new Node(101);
    Node* head = haha;
    Node* tail = haha;

    AddNewNodes(tail , 102);
    AddNewNodes(tail , 103);
    AddNewNodes(tail ,104);
    AddNewNodes(tail ,105);
    AddNewNodes(tail ,106);
    AddNewNodes(tail ,107);
    AddNewNodes(tail ,108);
    AddNewNodes(tail ,109);
    AddNewNodes(tail ,110);
    PrintLL(head);

    Node* newhead = reverseKGroup(head , 3);

    PrintLL(newhead);

    return 0;
}