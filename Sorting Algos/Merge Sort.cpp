class Solution {
public:
    void merge (vector<int>& nums, int s, int e){
        int mid = (s + e)/2;
        // as the nums is sorted from s to mid & mid+1 to e
        
        int len1 = mid - s + 1;
        int len2 = e - mid;
        vector<int> first (len1);
        vector<int> second (len2);
        
        int x = s;
        for(int i=0; i<len1; i++)  // s se len1 tak first mai bharo
            first[i] = nums[x++];
        
        int m = mid + 1;
        for(int i=0; i<len2; i++)  // e se len2 tak second mai bharo
            second[i] = nums[m++];
        
        // merge 2 sorted arrays:
        
        int i = len1 -1;
        int j = len2 -1;
        int k = e;
       
        
        // int k = m + n - 1;
        
        while(i>=0 && j>=0){
            if(first[i]>second[j]){
                nums[k]=first[i];
                i--;
            }
            
            else{
                nums[k]=second[j];
                j--;
            }
            
            k--;
        }
        
        while(i>=0){
            nums[k]=first[i];
            i--;
            k--;
        }
        
        while(j>=0){
            nums[k]=second[j];
            j--;
            k--;
        }
    }
    void mergeSort(vector<int>& nums, int s, int e){
        if(s>=e)
            return ;
        
        int mid = s+ (e - s)/2;
        
        mergeSort(nums, s, mid);
        mergeSort(nums, mid + 1, e);
        
        
        merge(nums, s, e);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};


