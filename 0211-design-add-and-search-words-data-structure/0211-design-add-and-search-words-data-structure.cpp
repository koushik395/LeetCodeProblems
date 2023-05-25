class TrieNode{
public:
	char data;
	TrieNode* children[26];
	bool isTerminal;

	TrieNode(char ch)
	{
		data = ch;
		for(int i = 0;i<26;i++)
		{
			children[i] = NULL;
		}
		isTerminal = false;
	}

};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root,string word)
	{
		if(word.length() == 0) {
			root->isTerminal = true;
			return;
		}
		int index = word[0] - 'a';

		TrieNode* child;
		if(root->children[index]!=NULL)
		{
			//child is present
			child = root->children[index];
		}
		else
		{
			//child absent
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}

		insertUtil(child,word.substr(1));
	}
    
    void addWord(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root, string word) {
        for (int i = 0; i < word.length() && root; i++) {
            if (word[i] != '.') {
                int index = word[i] - 'a';
                root = root->children[index];
            } else {
                for (int j = 0; j < 26; j++) {
                    
                    if (root->children[j] && searchUtil(root->children[j], word.substr(i + 1))) {
                        return true;
                    }
                }
                return false;
            }
        }
        return root && root->isTerminal;
    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */