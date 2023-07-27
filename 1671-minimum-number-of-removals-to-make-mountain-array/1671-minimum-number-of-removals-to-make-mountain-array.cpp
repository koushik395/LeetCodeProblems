class Solution {
public:
    int LongestBitonicSequence(vector<int>arr)
	{
	    int n = arr.size();
        vector<int> prefix(n,1),suffix(n,1);
    
        for(int i=0; i<=n-1; i++){
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){
    
                if(arr[prev_index] < arr[i] && 1 + prefix[prev_index] > prefix[i]){
                    prefix[i] = 1 + prefix[prev_index];
                }
            }
        }
        
        int maxi = 1;
        for(int i=n-1; i>=0; i--){
            for(int prev_index = n-1; prev_index > i; prev_index--){
    
                if(arr[prev_index] < arr[i] && 1 + suffix[prev_index] > suffix[i]){
                    suffix[i] = 1 + suffix[prev_index];
                }
            }
            if(prefix[i] > 1 && suffix[i] > 1) 
                maxi = max(maxi,prefix[i] + suffix[i]-1);
        } 

        return maxi;
	}
    
    int minimumMountainRemovals(vector<int>& nums) {
        return nums.size() - LongestBitonicSequence(nums);
    }
};