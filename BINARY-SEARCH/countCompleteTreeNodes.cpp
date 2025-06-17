#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=0,rh=0;
        TreeNode *l=root,*r=root;
        while(l){ lh++; l=l->left; }
        while(r){ rh++; r=r->right; }
        if(lh==rh) return pow(2,lh)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};

// time complexity = O(log n * log n) for exploring te ht of tree - log n and you are not going to explore every node, because one part of tree will be surely a lh==rh so it wont invoked the next function, so exploring only log n nodes.
// space complexity = o(log n) - recursion stack space

