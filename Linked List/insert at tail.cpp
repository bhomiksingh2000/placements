#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Node{
    public:
        int val;
        Node * next;
        Node(int data){
            val=data;
            next=NULL;
        }
};

Node * head;
void insertAtTail(Node * &tail, int val){
    if(!tail){
        tail=new Node(val);
        head=tail;
    }
    
    else{
        Node * newNode= new Node(val);
        tail->next=newNode;
        tail=newNode;
    }
    
}

void printList(Node * head){
    while(head){
        cout<<head->val<<"->";
        head=head->next;
    }
}

int main() {
    Node* tail=NULL;
    insertAtTail(tail,3);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    insertAtTail(tail,0);
    printList(head);

}