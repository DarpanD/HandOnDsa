// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;

// class 
class Node{

    public:
    int data ;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

// singular ll
void InsertionAtHead(Node* &head , int data){ // need to send head by address '&' because we are updating it later

    // I - Create a new node
    Node* temp = new Node(data);
    //  II - point head to next
    temp->next = head;
    // III - point head at temp to make it first node
    head = temp;
}

// singular ll
void AddNewNodes(Node* &tail , int data){ // need to send last node with address '&' because we are updating it later 

    // I - create new node
    Node* temp = new Node(data);
    // II - pointing tail node with new temp node
    tail->next = temp;
    // III- making temp as tail
    tail = temp;
}

// singular link list
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

// circular link list
void InsertNodeAfterValue(Node* &tail ,int checkdata , int inputdata){

    Node* temp = tail;
    Node* tomato = new Node(inputdata);
    // check if empty list
    if(tail == NULL){
        tail = tomato;
        tomato->next = tomato; // pointing itself 
    }
    else{
        // assuming checkdata is present in list
        while(temp->data != checkdata){
            temp = temp->next;
        }
        tomato->next = tail; // changed this line from default to create loop in non loop list
        temp->next = tomato;
    }


}

// printing 
void printll(Node* head ){

    if(head ==  NULL ) return ;

    // map <key , value > map_name
    map<Node*, bool> visited;

    Node* temp = head;
    
    int i = 0;
    while(temp != NULL ){
        
        if(visited[temp] == 1) return ;

        cout << i << ". " << temp->data << "  " << temp->next <<  endl;

        visited[temp] = 1;
        temp = temp->next;
    }

}

// check if circle is present is not (normal method)
bool iscircular(Node* head){

    // empty list 
    if(head == NULL ){
        cout << "list is empty" << endl;
        return false;
    }

    map<Node* , bool> visited;
    Node* temp = head;

    while(temp!=NULL ){

        if(visited[temp ] == 1) {
            cout << "loop present at data " << temp->data << endl;

            return true;
        }

        visited[temp ] = 1;
        temp = temp->next;
    }

    // out of while loop that means NULL found and not a circulat loop
    return false;
}

// check if circle is present is not (floyd's method)
bool haveCircle(Node* head){

    // empty list
    if(!head ) return false;

    Node* car1 = head;
    Node* car2 = head;

    while(car1 != NULL && car2 != NULL && car2->next != NULL){ 

        car1 = car1->next;
        car2 = car2->next->next;

        if(car1 == car2 ) return true;
    }

    return false;
}

//loop starts from
Node* loopStartsfrom(Node* head){

    // empty list
    if(!head ) return NULL;

    Node* car1 = head;
    Node* car2 = head;

    while(car1 != NULL && car2 != NULL && car2->next != NULL){  

        car1 = car1->next;
        car2 = car2->next->next;

        if(car1 == car2 ) break;
    }

    // no loop exist and while loop over
    if (car1 != car2) return NULL;

    // reseting car1 to head so that it travel only till loop starting point
    car1 = head;
    while(car1 != car2){
        car1 = car1->next;
        car2 = car2->next;
    }
    return car2;
}

// converting circular loop to singular loop
void breakCircularloop(Node* head){

    // empty list
    if(!head ) return ;

    Node* car1 = head;
    Node* car2 = head;

    while(car1 != NULL && car2 != NULL && car2->next != NULL){ 
        car1 = car1->next;
        car2 = car2->next->next;

        if(car1 == car2 ) break;
    }

    // no loop exist and while loop over
    if (car1 != car2) return ;

    car1 = head;
    // temp node will be last node of loop
    Node* temp = car2;
    while(car1 != car2){
        car1 = car1->next;
        // line cannot catch in case of perfect circular loop
        // temp = car2;
        car2 = car2->next;
    }

    // re-traverse the coz temp = car2 cannot catch if the last node is connecting to first node of ll
    while(temp->next != car2) {
        temp = temp->next;
    }
    temp->next = NULL ;

    temp->next = NULL ;

    return ;
}

 


int main(){

    Node* hello = new Node(10 );
    Node* head = hello;
    Node* tail = hello;

    AddNewNodes(tail, 20);
    AddNewNodes(tail, 30);
    AddNewNodes(tail, 40);
    AddNewNodes(tail, 50);
    AddNewNodes(tail, 60);

    InsertNodeAfterValue(tail , 60 , 70);
    InsertNodeAfterValue(tail , 70 , 80);
    InsertNodeAfterValue(tail , 80 , 90);
    InsertNodeAfterValue(tail , 90 , 100);

    printll(head);



    if(iscircular(head)){
        cout << "it is circluar loop"<<endl;
    }
    else{
        cout << "is not a circluar loop " << endl;
    }


    if(haveCircle(head)){
        cout << "it is circluar loop using floyd"<<endl;
    }
    else{
        cout << "is not a circluar loop using floyd" << endl;
    }


    cout << endl; 
    cout << endl;


    cout << "the loop starts at point : " << loopStartsfrom(head)->data << endl; 

    cout << "breaking loop (circular loop to singular loop )" << endl;
    breakCircularloop(head);
    printll(head);


    return 0 ;
}