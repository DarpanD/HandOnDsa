// Keep it up Champ ;)
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
}

// main code starts

// Approach 1
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

// Finding Middle of LinkList
Node* FindMid(Node* head){

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
    return slow;
    
}


bool isPalindrome(Node* head) {

    if(!head->next) return true; 
    
    Node* mid = FindMid(head);

    mid = mid->next;
    ReverseLL(mid);

    while(mid){

        if(head->data != mid->data){
            return false;
        }
        else{
            head = head->next;
            mid = mid->next;
        }
    }
    return true;

}

// Approach 2
bool checkPalindrome(Node* head){

    vector<int> opt ;

    for(Node* temp = head ; temp != NULL ; temp = temp->next){

        opt.push_back(temp->data);
    }

    int start = 0;
    int end = opt.size() -1;
    while(start <= end){

        if(opt[start] != opt[end]) return false;

        start++;
        end--;
    }
    return true;

}

int main() {

    Node* head = new Node(1);
    InsertionAtHead(head , 2);
    InsertionAtHead(head , 3);
    InsertionAtHead(head , 3);
    InsertionAtHead(head , 3);
    InsertionAtHead(head , 2);
    InsertionAtHead(head , 1);

    PrintLL(head);

    // Approach 1
    // if(isPalindrome(head))
    //     cout << "List is Palindrome"<< endl;  
    // else
    //     cout << "List is not Palindrome" << endl;
    
    
    // Approach 2
    // this approach will only work if approach 1 is not called as that changes the pointers in original list
    if(checkPalindrome(head))
        cout << "List is Palindrome"<< endl;  
    else
        cout << "List is not Palindrome" << endl;


    return 0;

}