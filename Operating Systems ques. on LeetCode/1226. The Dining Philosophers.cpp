class Semaphore{
    mutex m;
    condition_variable cv;
    int count;
    public:
    Semaphore() {};
    Semaphore(int c) : count(c){};
    
    void setCount(int a){
        count =a;
    }
    
    inline void signal(){
        std::unique_lock<std::mutex> lock(m);
        count++;
        if(count>=0)
            cv.notify_one();
    }
    inline void wait(){
        std::unique_lock<std::mutex> lock(m);
        count--;
        if(count<0)
            cv.wait(lock);
    }
};
class DiningPhilosophers {
public:
    Semaphore fork[5];
    mutex m;
    condition_variable cv;
    
    DiningPhilosophers() {
        for(int i=0;i<5;i++)
            fork[i].setCount(1);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
		std::lock_guard<std::mutex> lock(m);
        fork[(philosopher+1)%5].wait();
        fork[philosopher].wait();
        
        pickLeftFork();
        pickRightFork();
        
        eat();
        
        putLeftFork();
        fork[(philosopher+1)%5].signal();
        putRightFork();
        fork[philosopher].signal();
        
    }
};