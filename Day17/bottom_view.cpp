class Solution {
public:
    vector <int> bottomView(Node *root) {
        vector<int> res;
        if (!root) return res;
        queue<pair<Node*, int>> q;
        map<int, int> hash;
        q.push({root, 0});
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                Node* temp = q.front().first;
                int h = q.front().second;
                q.pop();
                hash[h] = temp->data;
                if (temp->left) q.push({temp->left, h - 1});
                if (temp->right) q.push({temp->right, h + 1});
            }
        }
        for (auto it : hash) {
            res.push_back(it.second);
        }
        return res;
    }
};