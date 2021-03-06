class Solution
{
public:
    //Function to serialize a tree and return a list containing nodes of tree.

    vector<int> ret;
    void shelper(Node *root) {
        if (!root) {
            ret.push_back(-1);
            return ;
        }
        ret.push_back(root->data);
        shelper(root->left);
        shelper(root->right);
    }
    vector<int> serialize(Node *root)
    {
        ret.clear();
        shelper(root);
        return ret;
    }
    Node* dhelper(vector<int> &A, int &ind) {
        if (ind >= A.size() or A.size() == 0)
            return NULL;
        if (A[ind] == -1)
            return NULL;
        Node *temp = new Node(A[ind]);
        ind ++;
        temp->left = dhelper(A, ind);
        ind++;
        temp->right = dhelper(A, ind);
        return temp;
    }
    Node * deSerialize(vector<int> &A)
    {
        int ind = 0;
        return dhelper(A, ind);
    }

};