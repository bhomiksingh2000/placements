/*
So this is a question on concurrency therefore we will have
to synchronise the two threads where  one thread is printing
foo and the other is printing bar 

Therefore we will have to manage we will use turn  variable which is part of critical section  section therefore  synchronisation should be done 
in a way that no  reader writer  problem is there or mutual exclusion is not violated  therefore we will use conditional variables and locks 
for synchronisation
*/
class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool turn;
    

public:
    FooBar(int n) {
        this->n = n;
        this->turn=0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock (m);
            while(turn==1)
                cv.wait(lock);
            
            
        	printFoo();
            turn =1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
             unique_lock<mutex> lock (m);
            while(turn==0)
                cv.wait(lock);
            
            
        	printBar();
            turn =0;
            cv.notify_all();
        }
    }
};