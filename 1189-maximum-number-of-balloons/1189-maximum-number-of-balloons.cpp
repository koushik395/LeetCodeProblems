class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> let;
        for(auto &i:text)
            let[i]++;
        
        return min(let['b'],min(let['a'],min(let['l']/2,min(let['o']/2,let['n']))));
        
    }
};