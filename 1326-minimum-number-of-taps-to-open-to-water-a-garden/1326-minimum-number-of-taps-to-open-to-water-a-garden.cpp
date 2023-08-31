class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min   = 0;
        int max   = 0;
        int count = 0;
        while(max < n) {
            
            //Choose the tap with maximum range it can reach to right
            //For a given min value (to left)
            for(int i = 0; i < n + 1; i++) {
                if(i-ranges[i] <= min && i+ranges[i] > max)
                    max = i+ranges[i];
            }
            
            //It means we couldn't expand our range to right
            if(max == min)
                return -1;
            
            //Now, we have reached till max, next we want to cover more than this max
            //starting from min
            min = max;
            count++;
        }
        
        return count;
    }
};