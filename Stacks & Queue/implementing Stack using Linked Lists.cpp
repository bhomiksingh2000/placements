/*
we will just use insertion at head, because as head (top) Node will indicate 
the top element ,and if at any point we would like to pop any element,
then we will just move head to its next 
*/
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


Node* top = NULL;
void push(int val){
    // same as insert at head:
    if(!top){
        top =new Node (val);
    }
  
    else{
        Node * newNode= new Node(val);
        newNode -> next = top;
        top = newNode;
    }
    
}

bool isEmpty(){
  if (top == NULL)
      return true;
  else
      return false;
}

void pop(){
    if(isEmpty())
        cout<<"stack is empty"<<endl;
    
    else{
        Node *temp = top;
        top = top -> next;
        // temp -> next = NULL;
        delete(temp);
    }
   
}

void display(){
    Node* curr = top;
    while(curr){
        cout<<curr -> val<< " ";
        curr = curr -> next;
    }
    cout<< endl;
}

void top_element(){

  if (top == NULL)
  {
      cout << "stack is empty" << endl;
  }
  else
      cout << "top element of stack is " <<top -> val<<endl;
}

int main() {

    push(11);
    push(22);
    push(33);
    push(44);
    display();
    
    pop();
    top_element();
    pop();
    top_element();
    display();
    

}