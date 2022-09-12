class Foo {
    
public:
    std::mutex m;
    std::condition_variable cv;
    int turn;
    Foo() {

// Because Sabse Pehle turn thread 1 Ki Hogi that's why Humne turn ko 0 kara h
        turn =0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        turn =1; // ab thread 2 ki chance ho jaegi
        
        cv.notify_all();  
        // Means  thread2 wait kar rha the thread1 ke execute hone kaa , vo sab ko aage jaane ki permission h ab.
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(m);
        
        // jab tak iski turn na aae , tab tak wait karoo
        while(turn!=1){
            cv.wait(lock);
            
        }
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        turn =2; // ab thread 3 ki chance ho jaegi
        
        cv.notify_all();  
        // Means  thread2 wait kar rha the thread1 ke execute hone kaa , vo sab ko aage jaane ki permission h ab.
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(m);
        
        // jab tak iski turn na aae , tab tak wait karoo
        while(turn!=2){
            cv.wait(lock);
            
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};