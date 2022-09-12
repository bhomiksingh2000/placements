void deleteMid(stack<int>&s, int sizeOfStack)
    {
        vector<int>  temp;
        int mid;
       if(sizeOfStack%2==0)
       {
           mid=(sizeOfStack+2)/2;
       }
       else
       {
           mid=(sizeOfStack+1)/2;
       }
       while(mid-1)
       {
           temp.push_back(s.top());
           s.pop();
           
           mid--;
       }
       s.pop();
       for(int i=temp.size()-1;i>=0;i--)
       {
           s.push(temp[i]);
       }
       
    }