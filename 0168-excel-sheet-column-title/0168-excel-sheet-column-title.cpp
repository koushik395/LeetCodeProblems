class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title = "";
        while (columnNumber > 0){
            columnNumber -= 1;
            title = (char)(columnNumber % 26 + 65) + title;
            columnNumber /= 26;
        }
        return title;
    }
};