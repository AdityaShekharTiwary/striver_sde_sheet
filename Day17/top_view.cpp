/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> res;
        queue<pair<Node*, int>> q;
        map<int, int> hash;
        if (!root) return res;
        q.push({root, 0});
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                Node* temp = q.front().first;
                int h = q.front().second;
                q.pop();
                if (!hash[h]) hash[h] = temp->data;
                if (temp->left) q.push({temp->left, h - 1});
                if (temp->right) q.push({temp->right, h + 1});
            }
        }
        for (auto it : hash) res.push_back(it.second);
        return res;
    }

};

