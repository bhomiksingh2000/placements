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

void insertAtHead(Node * &head, int val){
    if(!head){
        head=new Node(val);
        
    }
    
    else{
        Node * newNode= new Node(val);
        newNode->next=head;
        head=newNode;
    }
    
}

// yha pe by refernce pass nhi kia h
void printList(Node * head){
    while(head){
        cout<<head->val<<"->";
        head=head->next;
    }
}

int main() {
    Node* head=NULL;
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    printList(head);

}