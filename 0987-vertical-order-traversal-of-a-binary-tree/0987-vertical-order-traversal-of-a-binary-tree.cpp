/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> fin;

    void levelOrderRecursive(TreeNode* root, int x, int y, map<int,map<int,vector<int>>>& levels) {
        if (root == nullptr) {
            return;
        }

        levels[x][y].push_back(root->val);

        levelOrderRecursive(root->left, x - 1, y + 1, levels);
        levelOrderRecursive(root->right, x + 1, y + 1, levels);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> levels;
        levelOrderRecursive(root, 0, 0, levels);

        for (auto& [x, levelNodes] : levels) {
            vector<int> column;
            for (auto& [y, nodes] : levelNodes) {
                sort(nodes.begin(), nodes.end());
                column.insert(column.end(), nodes.begin(), nodes.end());
            }
            fin.push_back(column);
        }

        return fin;
    }
    // for the i/p [1,2,3,4,5,6,7]
    // The data is stored in the map in the following way
    /*
    -2{
     2:[4];
    }
    -1{
     1:[2];
    }
    0{
     0:[1];
     2:[5,6];
    }
    1{
     1:[3];
    }
    2{
     2:[7];
    }*/
    
    /*We are the storing the corresponding column number with the rows in order to sort the 
    individual rows if they occur in same column*/

};