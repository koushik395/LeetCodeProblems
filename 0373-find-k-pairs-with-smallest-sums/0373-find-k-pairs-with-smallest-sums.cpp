class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p,vector<p>,greater<p>> minh;
        vector<vector<int>> ans;
        
        for(int i = 0;i < nums1.size();i++)
        {
            minh.push({nums1[i]+nums2[0],{i,0}});
        }
        
        while(!minh.empty() && k--)
        {
            int topF = minh.top().second.first;
            int topS = minh.top().second.second;
            minh.pop();
            
            ans.push_back({nums1[topF],nums2[topS]});
            
            if(topS+1<nums2.size())
            {
                minh.push({nums1[topF]+nums2[topS+1],{topF,topS+1}});   
            }
        }
        
        return ans;
    }
};