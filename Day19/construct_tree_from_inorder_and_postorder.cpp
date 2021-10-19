int idx;
unordered_map<int, int> hm;

Node* solve(int in[], int post[], int l, int r) {
    if (l > r) return nullptr;
    Node* res = new Node(post[idx--]);
    int mid = hm[res->data];
    res->right = solve(in, post, mid + 1, r);
    res->left = solve(in, post, l, mid - 1);
    return res;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    idx = n - 1;
    hm.clear();
    for (int i = 0; i < n; i++) hm[in[i]] = i;
    Node* root = solve(in, post, 0, n - 1);
    return root;
}