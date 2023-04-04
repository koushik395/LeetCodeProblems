class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for(auto i: operations)
        {
            if(i=="C")
                scores.pop_back();
            else if(i == "+")
                scores.push_back(scores.at(scores.size()-1) + scores.at(scores.size()-2));
            else if(i=="D")
                scores.push_back(scores.back()*2);
            else
                scores.push_back(stoi(i));
        }
        return accumulate(scores.begin(),scores.end(),0);
    }
};