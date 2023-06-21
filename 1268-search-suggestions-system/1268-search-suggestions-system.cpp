class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)     {
        sort(begin(products), end(products));
        int left = 0, right = products.size()-1;
        vector<vector<string>> suggestions;
        int n = searchWord.size();
        for(int i=0; i<n; i++)
        {
            char ch = searchWord[i];
            vector<string> suggestion;
            while(left <= right && ch != products[left][i])
            {
                left++;
            }
            while(left <= right && ch != products[right][i])
            {
                right--;
            }
            for(int start = left; start<left+min(3, right-left+1); start++)
            {
                suggestion.push_back(products[start]);
            }
            suggestions.push_back(suggestion);
        }
        return suggestions;
    }
};