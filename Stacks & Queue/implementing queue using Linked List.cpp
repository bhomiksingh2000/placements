/*
so here we use a tail  and a head node whenever we want to pop from the 
queue therefore we will move the head to the next load and for inserting 
into the queue we will just add it to the tale of the link list
*/
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node{
    public:
    int val;
    Node *next;
    
    Node(int x){
        val = x;
        next = NULL;
    }
};

Node * head = NULL;
Node * tail = NULL;

void push(int x){
    // same as insertion at tail:
    if(!head){
        Node * newNode = new Node(x);
        head = newNode;
        tail = head;
    }
    
    else{
        Node *newNode = new Node(x);
        tail -> next = newNode;
        tail = tail -> next;
    }
}

void pop(){
    // simply move head to the next pointer:
    if(head){
        cout<< "front Node deleted 🫡"<<endl;
        Node * curr = head;
        head = head -> next;
        
        delete(curr);
    }
}

void display(){
    Node * temp = head;
    cout<<"the elements of queue are 🥸: ";
    while(temp){
        cout<< temp -> val<<" ";
        temp = temp -> next;
    }
    
    cout<<endl;
}
void front(){
    if(head)
        cout<<"the front element of queue is 🥹"<<head -> val<<" "<<endl;
    
    else
        cout<<"Queue is empty"<<endl;
}

int main() {

    push(11);
    push(22);
    push(33);
    push(44);
    display();
    front();
    pop();
    pop();
    front();
    display();
    

}