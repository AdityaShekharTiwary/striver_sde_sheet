/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> solve(TreeNode<int>* root, vector<int> &arr) {
    if (root) {
        solve(root->left, arr);
        arr.push_back(root->data);
        solve(root->right, arr);
    }
    return arr;
}

int kthSmallest(TreeNode<int> *root, int k)
{
    vector<int>arr;
    if (!root) return 0;
    solve(root, arr);
    return arr[k - 1];
}