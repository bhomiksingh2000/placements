#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// yha importance hai front aur rear ke -1 ki , by that we will get correct front and rear elements
class Queue{
    int arr[3], n = 3, size = 0, last = -1, front = -1;
    public:

    void push(int x){
        if(size == n)
            cout<<" queue size is Full 🫠"<<endl;
        else{
            if(front == -1){
                arr[0]=x;
                front=0;
                last=0;
            }

            else{
                last = (last + 1)%n;
                arr[last] = x;
            }
            size++;
        }
    }
    
    void pop(){
       if(size == 0)
            cout<<" queue is Empty"<<endl;
        else{
            cout<<" front element deleted 🫡 "<<endl;
            front = ( front + 1 ) % n;
            size--;
        } 
    }
    
    void Front(){
       if(size == 0)
            cout<<" queue is Empty"<<endl;
        else
            cout<<" front element is 🫶 "<<arr[front]<<endl;   
    }
    
    void display(){
        if(size == 0)
            cout<<" queue is Empty"<<endl;
        else{
            cout<<" the elements of queue are 🥸: ";
            for(int i = front; i<size; i++)
                cout<<arr[i]<<" ";
            
            cout<<endl;
        }
    }
};

int main() {
    
    Queue q;
    q.push(11);
    q.push(22);
    q.push(33);

    q.push(44);
    q.display();

    q.Front();
    
    q.pop();
    q.pop();
    q.Front();
    q.display();

}