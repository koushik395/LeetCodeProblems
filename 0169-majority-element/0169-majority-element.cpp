class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moores voting system
        int n = nums.size();
        int cnt = 0;
        int ele;
        for(int i=0;i < n;i++)
        {
            if(cnt == 0)
            {
                cnt = 1;
                ele = nums[i];
            }
            else if(nums[i] == ele) cnt++;
            else cnt --;
        }
        return ele;
    }
};