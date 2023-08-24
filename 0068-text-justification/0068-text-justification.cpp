class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;

        while (i < words.size()) {
            int j = i, curLen = 0;

            // Calculate the total length of words that can fit in the current line.
            while (j < words.size() && curLen + words[j].length() + (j - i) <= maxWidth) {
                curLen += words[j].length();
                j++;
            }

            int spaces = maxWidth - curLen;
            int numWords = j - i;

            // Handle the last line separately (left-justified, no extra spaces between words).
            if (numWords == 1 || j == words.size()) {
                string line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                line += string(maxWidth - line.length(), ' '); // Pad with spaces to reach maxWidth.
                result.push_back(line);
            } else {
                int spacesBetweenWords = spaces / (numWords - 1);
                int extraSpaces = spaces % (numWords - 1);

                string line = words[i];
                for (int k = i + 1; k < j; k++) {
                    int spacesToAdd = spacesBetweenWords + (extraSpaces-- > 0 ? 1 : 0);
                    line += string(spacesToAdd, ' ') + words[k];
                }

                result.push_back(line);
            }

            i = j;
        }

        return result;
    }
};