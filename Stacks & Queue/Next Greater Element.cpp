vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> res(arr.size());
        stack<long long> st;
        
        for(int i = arr.size() - 1; i>=0; i--){
            while(!st.empty() && st.top() <= arr[i])
                st.pop();
            
            if(st.empty())
                res[i] = -1;
            
            else
                res[i] = st.top();
            
            st.push(arr[i]);
            
        }
        
        return res;
    }