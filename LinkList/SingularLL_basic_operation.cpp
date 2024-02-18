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

// 5th - Instersion in middle (node pre-declared)
void InsertionInMiddle(Node* &AfterThis ,int data ){

    // I- create a temp node
    Node* temp = new Node(data);
    // II- making temp next same as AfterThis's next so that they point same next node
    temp->next = AfterThis->next;
    // III- making AfterThis's next pointing to temp 
    AfterThis->next = temp;

}

// 6th - Insertion at particlur position
void InsertionAtPosition(Node* &head,Node* &tail,int position , int data){


    // this will not work for 1st position as we need one element before not insert at given position
    // To make this work
    // special case 1 - insertion at head
    if(position == 1){
        InsertionAtHead(head,data);
        return; // return to avoid further compilation
    }
    // I - create a new temp node
    Node* temp = head;
    // II - position -1 one sinve we are travelling till that value not pass that value
    position--;
    // III - travel till that position
    while (position)
    {
        temp = temp->next;
        position--;
    }
    // special case 2- check if insertion is for last index
    // not needed 
    if(temp->next == NULL){
        AddNewNodes(tail , data);
        return ;
    }
    // IV - creating a new node to insert data
    Node* tomato = new Node(data);
    // V - making tomato and temp pointing same next node
    tomato->next = temp->next;
    // VI - updating temp node so that it points at tomato now
    temp->next = tomato;
    
}

// 7th Part 1 - Deletion of node (My method)
void DeletionOfNode(Node* &head ,  int position ){
    
    // I - check if first position has to be deleted
    if(position == 1 ){
        // move head on position ahead an saving last head for deeletion
        Node* temp = head;
        head = head->next;
        // memory free of last head
        temp->next = NULL;
        delete temp ;
        return ;  
    }
    // II - create a pointer for head
    Node* temp = head;
    // III - traverse till n-1 position
    position--;
    while(position){
        temp = temp->next;
        position--;
    }
    // IV - create new node pointer to delete that
    Node* yeWalaDeleteHoga = temp->next;
    // V - point temp next to yeWalaDeleteHoga's next 
    temp->next = yeWalaDeleteHoga->next;
    // VI - delete yeWalaDeleteHoga through delete destructor 
    yeWalaDeleteHoga->next = NULL; // necessary to point deleting node to null else full LL ahead of this will be deleted
    delete yeWalaDeleteHoga;

}
// 7th Part 2 - Love babber method
void deleteNode(Node* &head, int position){

    // I- check if first position has to be deleted
    if(position == 1 ){
        // move head on position ahead an saving last head for deeletion
        Node* temp = head;
        head = head->next;
        // memory free of last head
        temp->next = NULL;
        delete temp ;  
        return ;
    }
    // if not first node
    // create a current and previous pointing node
    Node* CurrentNode = head;
    Node* PreviousNode = NULL;
    // traverse to (n-1) position
    int count = 1;
    while(count < position){
        PreviousNode = CurrentNode;
        CurrentNode = CurrentNode->next;
        count++ ;
    }
    // making previous node pointing at current node's next
    PreviousNode->next = CurrentNode->next;
    // deleting current node through destructor
    CurrentNode->next = NULL;
    delete CurrentNode;

}

// 8th Part 1 - Reverse a Link List (iterative)
void ReverseLL(Node* &head ){

    // I - if empty or single element list
    if(head == NULL || head->next == NULL) return ;
    
    // II - >1 element cases
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    // III - repointing head back to first node
    head = prev;
}

// 8th Part 2 - (Recursive)
Node* revLL(Node* head){

    // base case - recursion stops at last node
    // also returns if list is empty
    if (head == NULL || head->next == NULL ) return head;

    // temp stores the last node as it will be new head 
    Node* temp = revLL(head->next);
    // actual reversing pointers
    head->next->next = head;
    // done so that last node is pointing towards null
    // making last node NULL also allows the print func to work
    head->next = NULL;

    return temp;

}

int main() {

    // INSERTION OF NODES

    // 1st 
    // Node* phela = new Node(); // making a pointer object of LL
    // phela-> data = 20; // to insert data 
    // // to insert data at the time of making

    Node* phela = new Node(69); // making a pointer object of LL
    {
    cout <<"Data : " <<phela-> data << endl;
    cout <<"Next node address(pointer) : " <<phela-> next << endl;

    cout << endl << endl;

    }

    // 2nd and 3rd 
    Node* head = phela; // pointing head to first node of LL
    {
    cout << "before Insertion " << endl;
    PrintLL(head);

    InsertionAtHead(head , 30); // 30 will be first now
    InsertionAtHead(head , 40); // 40 became first and 30 second
    InsertionAtHead(head , 50);

    cout << "After Insertion " << endl;
    PrintLL(head);

    cout << endl<<endl;

    }

    //4th 
    Node* tail = phela; // declaring a new pointer for last node
    {
    cout<< "before addition " << endl;
    PrintLL(head);

    AddNewNodes(tail,79);
    AddNewNodes(tail,89);
    AddNewNodes(tail,99);

    cout<< "after addition " << endl;
    PrintLL(head); 

    cout << endl << endl;

    }

    //5th
    {
    cout << "before insertion at middle " << endl;
    PrintLL(head);

    // adding new nodes after "phela" node
    InsertionInMiddle(phela, 100);

    cout << "after insertion at middle " << endl;
    PrintLL(head);

    cout << endl << endl;

    }
    
    //6th
    {

    cout<< "before insertion at position"<<endl;
    PrintLL(head);

    InsertionAtPosition(head,tail, 4 , 45);
    InsertionAtPosition(head,tail, 6 , 55);
    InsertionAtPosition(head,tail, 1 , 65); // speacial case 1
    InsertionAtPosition(head,tail, 11 , 75); // speacial case 2


    cout<< "after insertion at position"<<endl;
    PrintLL(head);

    cout << endl<<endl;

    }

    // DELETION OF NODES
    
    //7th
    {

    cout<< "before deletion at position"<<endl;
    PrintLL(head);

    DeletionOfNode(head , 4 ); // My method 
    DeletionOfNode(head , 1 ); // check for first index
    deleteNode(head , 6 ); // Love babber approach

    cout<< "after deletion at position"<<endl;
    PrintLL(head);

    cout << endl<<endl;

    }

    // OTHER OPERATIONS

    //8th 
    {
        
    cout << "before reversing " << endl; 
    PrintLL(head);
    cout << "head data = " << head->data<<endl<<endl;

    ReverseLL(head);

    cout << "after reversing " << endl; 
    PrintLL(head);
    cout << "head data = " << head->data<<endl<<endl;
        


    cout << "before reversing using reccursion" << endl; 
    PrintLL(head);
    cout << "head data = " << head->data<<endl<<endl;

    head = revLL(head);

    cout << "after reversing using reccursion" << endl; 
    PrintLL(head);
    cout << "head data = " << head->data<<endl<<endl;

    }

    return 0;

}