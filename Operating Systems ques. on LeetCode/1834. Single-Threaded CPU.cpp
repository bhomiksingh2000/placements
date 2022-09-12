/*
So this is a question based on shortest job first of CPU 
scheduling therefore we know that if more than one processes
are  in the ready Queue therefore according to shortest job 
first CPU scheduling algorithm the job having the least burst
time will be selected out of all => by using this concept we 
will solve this problem

As we do not know from which index the scheduling of processes will 
start therefore we will push back indices for each of the process 
and then sort them on the basis of their arrival time therefore 
we will get a sorted list  , sorted according to their arrival time 
now we will use a MIN HEAP  which will store the process  having the 
least burst time at the top and who are in the ready queue at a particular
time therefore we will loop through the tasks vector and then we will add the time of the burst time  of each process after its execution and then we will 
add the processes who have arrived in the min heap , till that particular time 
so that we can execute the process with least burst time / execution time
*/
class Solution {
public:
    typedef pair<int, int> pi;
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pi, vector<pi>, greater<pi> > sjf;
        vector<int> ans;
        
        for(int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(), tasks.end());
        long long time=tasks[0][0];
        int i=0;
        
        while(i<tasks.size() || !sjf.empty()){
            
            while(i<tasks.size() && tasks[i][0]<=time){
                sjf.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            
            // this is done when at that time , no process have arrived ,
            // thereofore we will set it to the latest arrival time , i.e the next process
            if(sjf.empty()){
                time=tasks[i][0];
            }
            
            if(sjf.size()){
                pair<int,int> job=sjf.top();
                sjf.pop();
                time+=job.first;
                ans.push_back(job.second);
            }   
        }
         
        while(sjf.size()){
            pair<int,int> job=sjf.top();
            sjf.pop();
            time+=job.first;
            ans.push_back(job.second);
        }
        
        
        return ans;
        
    }
};