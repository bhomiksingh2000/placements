#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// using list STL is very easy because we can pop and push from both sides:
class Queue{
    list<int> l;
    public:
    void push(int val){
        l.push_back(val);
    }
    
    bool isEmpty(){
        return l.size() == 0;
    }
   
    void pop(){
        if(!isEmpty())
            l.pop_front();
    }
    
    void display(){
        list<int>::iterator it;
        for (it = l.begin(); it != l.end(); ++it)
            cout << '\t' << *it;
        
        cout << '\n';
    }
};
int main() {

    Queue q;
    q.push(11);
    q.push(22);
    q.push(33);
    q.push(44);
    q.display();
    
    q.pop();
   
    q.pop();
    
    q.display();
    
}