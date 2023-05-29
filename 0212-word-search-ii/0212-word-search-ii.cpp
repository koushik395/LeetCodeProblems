class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';

        TrieNode* child;
        if (root->children[index] != NULL) {
            // child is present
            child = root->children[index];
        } else {
            // child is absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }
};

class Solution {
public:
    bool isPerimeter(int i, int j, int rows, int cols) {
        return (i >= 0 && i < rows && j >= 0 && j < cols);
    }

    void searchWords(vector<vector<char>>& board, TrieNode* node, int i, int j, int rows, int cols, string& word,vector<string>& ans) {
        if (node->isTerminal) {
            ans.push_back(word);
            node->isTerminal = false; // Mark word as found (optional)
        }

        if (!isPerimeter(i, j, rows, cols) || board[i][j] == ' ' || node->children[board[i][j] - 'a'] == nullptr) {
            return;
        }

        char ch = board[i][j];
        board[i][j] = ' ';
        node = node->children[ch - 'a'];
        word += ch;
        
        searchWords(board, node, i - 1, j, rows, cols, word, ans); // Go up
        searchWords(board, node, i + 1, j, rows, cols, word, ans); // Go down
        searchWords(board, node, i, j - 1, rows, cols, word, ans); // Go left
        searchWords(board, node, i, j + 1, rows, cols, word, ans); // Go right

        board[i][j] = ch;
        word.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        int cols = board[0].size();
        vector<string> ans;

        Trie* t = new Trie();
        for (auto& word : words) {
            t->insert(word);
        }
        
        string word;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                searchWords(board, t->root, i, j, rows, cols, word,ans);
            }
        }
        return ans;
    }
};