class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size()-1;
        int cap = 0;
        while(i<j)
        {
            cap = max(cap,(j-i)*min(height[i],height[j]));
            
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return cap;
    }
};