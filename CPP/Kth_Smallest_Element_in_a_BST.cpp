#ifndef KTH_SMALLEST_ELEMENT_IN_A_BST_H_INCLUDED
#define KTH_SMALLEST_ELEMENT_IN_A_BST_H_INCLUDED

#include<vector>
#include<cstdlib>
#include<algorithm>

#endif // KTH_SMALLEST_ELEMENT_IN_A_BST_H_INCLUDED

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void midorder_traversal(TreeNode* root, vector<int>& array_midorder){
        if (root == nullptr){
            return ;
        }

        midorder_traversal(root->left, array_midorder);
        array_midorder.push_back(root->val);
        midorder_traversal(root->right, array_midorder);

    }

    vector<int> midorder_array(TreeNode* root){
        vector<int> array_midorder;
        midorder_traversal(root, array_midorder);
        return array_midorder;
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr = midorder_array(root);

        TreeNode* p_left = root;
        TreeNode* p_right = root;

        while(p_left->left != nullptr){
            p_left = p_left->left;
        }

        while(p_right->right != nullptr){
            p_right = p_right->right;
        }

        int start = p_left->val;
        int end = p_right->val;

        while(start < end){
            int mid = (start + end) / 2;
            int cnt = 0;

            cnt += (upper_bound(arr.begin(), arr.end(), mid) - arr.begin());

            if (k > cnt){
                start = mid + 1;
            }else{
                end = mid;
            }
        }

        return start;

    }

};
