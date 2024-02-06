// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node{

    public:
    Node* prev;
    int data;
    Node* next;

    Node(int data){
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
};

// Printing 
void PrintDLL(Node* head){ 

    Node* temp = head;
    int i = 0 ;
    while (temp != NULL)
    {
        cout << i <<". "<< temp-> prev << "  "<<temp-> data << "  " << temp->next << endl;
        temp = temp->next;
        i++;
    }
    cout << endl;
}

// insertion at head
void InsertAtHead(Node* &head , int data){

    Node* temp = new Node(data);
    // if empty list first node is formed
    if(head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp ;
    }
}

// insertion at end // adding nodes (no tail given)
void AddingNode(Node* head , int data){

    Node* tomato = new Node(data);
    // if empty list ,head and tail will be NULL
    if(head == NULL){
        head = tomato;
    }
    else{
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        // now temp is last node with next == NULL
        temp->next = tomato;
        tomato->prev = temp;
    }


}
// insertion at end with tail given
// if tail is used AddingNode func wont work before calling this
void InsertionAtEnd(Node* &tail, int data){

    Node* tomato = new Node(data);

    // if empty list ,head and tail will be NULL
    if(tail == NULL){
        tail = tomato;
    }
    else{
        tail->next = tomato;
        tomato->prev = tail;
        tail = tomato; // update the tail to last node
    }
    
}

// insertion at n position
void InsertAtPosition(Node* &head ,int position , int data){

    if(position == 1 ){
        InsertAtHead(head,data);
    }
    else{
        Node* temp = head;
        position--;
        while(position){
            temp = temp->next;
            position--;
        }
        Node* tomato = new Node(data);
        Node* orange  = temp->next;

        tomato->next = orange;
        orange->prev = tomato; 
        // OR 
        // temp->next->prev = tomato;

        temp->next = tomato;
        tomato->prev = temp;
    }
}

// deletion of node
void deleteNode(Node* &head ,  int position){

    Node* bettaGayaTuAbb = head;
    Node* uskePheleWala = NULL;
    
    if(position == 1){
        head = bettaGayaTuAbb->next;
        head->prev = NULL;
        bettaGayaTuAbb->next = NULL;
        delete bettaGayaTuAbb;
    }
    else{
        position-- ;
        while(position){
            uskePheleWala = bettaGayaTuAbb;
            bettaGayaTuAbb = bettaGayaTuAbb->next;
            position--;
        }

        uskePheleWala->next = bettaGayaTuAbb->next;
        bettaGayaTuAbb->next->prev = uskePheleWala;

        bettaGayaTuAbb->next = NULL;
        bettaGayaTuAbb->prev = NULL;

        delete bettaGayaTuAbb;

    }
}

// reverse a link list
void reverseDLL(Node* &head ){
    
    Node* car1 = head;
    Node* car2 = car1->next;
    car1->next = NULL;
    while(car2 != NULL){
        Node* temp = car2->next;
        car2->next = car1;
        car1->prev = car2;
        car1 = car2;
        car2 = temp;
    }
    car1->prev = NULL;

    head = car1;
}

int main() {

    Node* phela = new Node(10);

    cout << "First Printing" << endl;
    Node* head = phela;
    PrintDLL(head);

    // insertion at head 
    cout << "Insertion at head , 20 and 30 " << endl;
    InsertAtHead(head , 20 );
    InsertAtHead(head , 30);
    PrintDLL(head);

    // insertion at end
    cout << "Insertion at end , 40 and 50 " << endl;

    // AddingNode(head , 50 ); // wont work since tail is not updated in this func
    Node* tail = phela;
    InsertionAtEnd(tail , 40);
    AddingNode(head , 50 );
    PrintDLL(head);


    // insertion at position
    cout << "Insertion at Position , 60 at 1 and 70 at 3" << endl;
    InsertAtPosition(head , 1 , 60);
    InsertAtPosition(head , 3 , 70);
    PrintDLL(head);

    // deletion of node
    cout << "deletion of Position 3" << endl;
    deleteNode(head , 3);
    PrintDLL(head);

    // reverse a link list
    cout << "before reversing " << endl; 
    PrintDLL(head);
    cout << "head data = " << head->data<<endl<<endl;

    reverseDLL(head);

    cout << "after reversing " << endl; 
    PrintDLL(head);
    cout << "head data = " << head->data<<endl<<endl;


    return 0;

}