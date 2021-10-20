/************************************************************
    Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> solve(TreeNode<int>* root, vector<int> &arr) {
    if (root) {
        solve(root->left, arr);
        arr.push_back(root->data);
        solve(root->right, arr);
    }
    return arr;
}

int KthLargestNumber(TreeNode<int>* root, int k)
{
    vector<int>arr;
    if (!root) return 0;
    solve(root, arr);
    reverse(arr.begin(), arr.end());
    int n = arr.size();
    if (k > n) return -1;
    return arr[k - 1];
}
