// Keep it up Champ ;)



// Problem 1 : (leetcode addtwoNumbers)
// l1 =  2 -> 3 -> 4 
// l2 =  3 -> 4 
// opt = (2+3) -> (3+4) -> (4+0) = 5 -> 7 -> 4 

// Problem 2 : (gfg Add two numbers represented by linked lists)
// l1 =  2 -> 3 -> 4 
// l2 =  3 -> 4 
// opt = (2+0) -> (3+3 ) -> (4+4) = 2 -> 6 -> 8


#include <iostream>
#include <bits/stdc++.h>
#include <vector>

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

// reversing a link list
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


// Problem Code 1 
// approach 1  (~16ms leetcode)
 Node* addTwoNumbers(Node* l1, Node* l2) {

    if(!l2) return l1;
    Node* head = l1;
    Node* pre = l1;

    int carry = 0;
    while (l1)
    {
        if(!l2){
            l1->data = l1->data +  carry;
        }else{
            l1->data = l1->data + l2->data + carry;
        }

        if(l1->data >= 10){
            l1->data = l1->data - 10;
            carry = 1;
        }else{
            carry = 0;
        }

        pre = l1;
        l1 = l1->next;
        if(l2)
            l2 = l2->next;
        if(!l1 && l2 ){
            pre->next = l2;
            l1 = l2;
            l2 = NULL;
        }

    }


    if(carry){
        Node* extra = new Node(carry);
        pre->next = extra;
    }
    return head;
    
}

// approach 2 (learnt suggestion tab  ~24ms leetcode)
Node* add2Numbers(Node* l1 , Node* l2){

    Node* dummy  = new Node();
    Node* car = dummy;
    int carry = 0;
    int data1 , data2 , sum ;

    while (l1 || l2 || carry )
    {
        // if l1 exist data1 = data of l1 or 0
        data1 = l1 ? l1->data : 0; 
        data2 = l2 ? l2->data : 0;

        sum = data1 + data2 + carry;

        // updating carry for next interation
        carry = sum / 10;
        // storing data in new node after carry removal
        car->next = new Node(sum % 10 );

        car = car->next;

        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }

    return dummy->next;

}


// Problem Code 2
/*
 approach =     i. reverse both list  
                ii. apply problem 1 code
                iii. reverse the result list 
*/
/*
another approach is to store the data of link list into a int and add it and create another list having single digits of this int
*/
Node* addTwoLists( Node* first,  Node* second){
    
    // step 1
    ReverseLL(first);
    ReverseLL(second);

    // step 2
    Node* opt = add2Numbers(first , second);

    // step 3 
    ReverseLL(opt);

    return opt;
}

int main() {

    // First Link List 
    Node* l1 = new Node(5);
    InsertionAtHead(l1 , 2);
    InsertionAtHead(l1 , 4);
    InsertionAtHead(l1 , 3);
    cout << "l1" << endl;
    PrintLL(l1);

    // Second Link List
    Node* l2 = new Node(9);
    InsertionAtHead(l2 , 4);
    InsertionAtHead(l2 , 3);
    cout << "l2" << endl;  
    PrintLL(l2);

    // after addition

    // Problem 1
    // // approcah 1
    // cout << "problem 1 approach 1 " << endl;
    // Node* head1 = addTwoNumbers(l1,l2);
    // PrintLL(head1);

    // approach 2 
    // - approach 2 wont work if approach 1 is rum cause app 1 change the data in 1st list
    cout << "problem 1 approach 2 " << endl;
    Node* head2 = add2Numbers(l1,l2);
    PrintLL(head2);


    // Problem 2 
    cout << "problem 2 approach 1 " << endl;
    Node* head3 = addTwoLists(l1 , l2);
    PrintLL(head3);


    return 0;

}