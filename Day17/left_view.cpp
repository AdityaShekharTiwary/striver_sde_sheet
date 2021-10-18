/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> res;
    queue<Node*> q;
    if (!root) return res;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        res.push_back(q.front()->data);
        while (sz--) {
            Node* temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return res;
}