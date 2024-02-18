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
    Node(int data=0){
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
void PrintLL(Node* head){ 

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

    cout << endl << endl;
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

// spliting LinkList from middle
void SplitList(Node* head , Node** first , Node** second ){

    Node* slow = head;
    Node* fast = head;

    while (fast->next)
    {
        fast = fast->next;
        if(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *first = head;
    *second = slow->next;
    slow->next = NULL;
    
}

// merging two list
Node* mergeTwoLists(Node* list1, Node* list2) {
        
    if(!list1) return list2;
    if(!list2) return list1;

    Node* car = new Node();
    Node* carHead = car;
    while(list1 && list2){
        if(list1->data < list2->data){
            car->next = list1;
            list1 = list1->next;
        }
        else{
            car->next = list2;
            list2 = list2->next;
        }
        car = car->next;
    }
    if(list1){
        car->next = list1;
    }
    if(list2){
        car->next = list2;
    }

    return carHead->next;
}

// merge sort
void MergeSort(Node** ans){
    
    Node* head = *ans;
    Node* first;
    Node* second;

    if(!head || !head->next) return ;

    // split list into two halfs
    SplitList(head , &first , &second);

    // recurrsive call 
    MergeSort(&first);
    MergeSort(&second);

    // merging two list
    *ans = mergeTwoLists(first , second); 
}

int main(){

    Node* head = new Node(7);
    Node* tail  = head;

    AddNewNodes(tail , 13);
    AddNewNodes(tail , 8);
    AddNewNodes(tail , 11);
    AddNewNodes(tail , 10);
    AddNewNodes(tail , 1);

    cout << "before" << endl;
    PrintLL(head);

    MergeSort(&head);

    cout << "after" << endl;
    PrintLL(head);

    return 0;
}