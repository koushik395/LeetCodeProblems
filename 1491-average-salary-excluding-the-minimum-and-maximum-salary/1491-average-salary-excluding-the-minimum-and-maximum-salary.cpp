class Solution {
public:
    double average(vector<int>& salary) {
        int minNum = *min_element(salary.begin(),salary.end());
        int maxNum = *max_element(salary.begin(),salary.end());
        int negativeSum = minNum + maxNum;
        int NormalSum = accumulate(salary.begin(),salary.end(),0);
        int sum = NormalSum - negativeSum;
        return (sum*1.0)/(salary.size()-2);
    }
};