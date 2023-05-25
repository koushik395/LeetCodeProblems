class TrieNode{
public:
	char data;
	TrieNode* children[26];
	bool isTerminal;
    int childcount;
	TrieNode(char ch)
	{
		data = ch;
		for(int i = 0;i<26;i++)
		{
			children[i] = NULL;
		}
        childcount = 0;
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

    void insertUtil(TrieNode* root,string word)
	{
		if(word.length() == 0) {
			root->isTerminal = true;
			return;
		}
		//word will be in caps
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
            root->childcount++;
			root->children[index] = child;
		}

		insertUtil(child,word.substr(1));
	}
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root,word);
    }
    
    void LCP(string str,string &ans)
    {
        for(int i = 0;i < str.length();i++)
        {
            char ch = str[i];
            
            if(root->childcount == 1) 
            {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else
                break;
            
            if(root->isTerminal) break;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie();
        
        for(auto& str:strs)
        {
            if(str == "") return "";
            t->insert(str);
        }
        
        string first = strs[0];
        string ans = "";
        
        t->LCP(first,ans);
        return ans;
    }
};