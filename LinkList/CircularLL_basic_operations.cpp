// Keep it up Champ ;)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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

void PrintCLL(Node* tail){ 

    Node* temp = tail;
    if(tail == NULL){
        cout << "List is Empty" << endl<< endl << endl;
        return ;
    }
    int i = 0 ; // to see no of node during print 
    do{
        cout << i <<". "<< temp-> data << "  " << temp->next << endl;
        temp = temp->next;
        i++;
    }while (temp != tail);

    cout <<endl << endl;
}

// insertion is done with respect of value
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
        tomato->next = temp->next;
        temp->next = tomato;
    }

}

// deletion with respect of value
void deleteNode(Node* &tail , int checkdata ){

    Node* curr = tail->next;
    Node* pre = tail;
    // check if empty list
    if(tail == NULL){
        cout << "List is empty" << endl;
    }
    else{
        // assuming checkdata is present in list
        while(curr->data !=  checkdata){
            pre = curr;
            curr = curr->next;
        }
        // check if tail is not getting deleted
        pre->next = curr->next;
        
        //if single node is present in list
        if(curr == pre){
            tail == NULL;
        }
        // >1 nodes in List
        else if(curr == tail ){
            tail = pre;
        }

        curr->next = NULL;
        delete curr;
    }

}

// to check if list is circular 
bool isCircular(Node* tail){
    
    // Empty List
    if(tail == NULL ){
        return false;
    }

    Node* car = tail->next;

    while (car != NULL  && car != tail)
    {
        car = car->next;
    }
    if(car == tail){
        return true;
    }
    return false ;
    
}
int main() {

    // in circular LL we dont use head pointer 
    // tail is used to traver and tail -> next is head
    Node* tail = NULL;
    // empty list check
    cout <<  "Is List a Circular Links List : " << isCircular(tail) << endl;
    PrintCLL(tail);

    // no node is present
    InsertNodeAfterValue(tail, 3, 10); // kuch bhi chalega coz list is empty 
    // 1 node check , outout true coz node pointing itself
    cout <<  "Is List a Circular Links List : " << isCircular(tail) << endl;

    // now list has node with data 10
    InsertNodeAfterValue(tail , 10 , 20 ); // 10 20
    InsertNodeAfterValue(tail , 10 , 30 ); // 10 30 20 
    InsertNodeAfterValue(tail , 20 , 40 ); // 10 30 20 40 
    PrintCLL(tail);


    // deletion of node
    cout << "Deletion of nodes " << endl;  
    cout << "tail : " <<  tail->data << "  " << tail <<endl;
    deleteNode(tail , 20);
    PrintCLL(tail);
    cout << "tail : " <<  tail->data << "  " << tail <<endl;
    // deleting tail
    deleteNode(tail , 10);
    PrintCLL(tail);
    cout << "tail : " <<  tail->data << "  " << tail <<endl;

    cout <<  "Is List a Circular Links List : " << isCircular(tail) << endl;

    return 0;

}