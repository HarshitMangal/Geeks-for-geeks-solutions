class Solution {
public:
    unordered_map<int, int> pos;

    Node* build(vector<int>& pre, vector<int>& preMirror,
                int preL, int preR,
                int mirL, int mirR) {

        if (preL > preR) return NULL;

        Node* root = new Node(pre[preL]);

        if (preL == preR)
            return root;

        int leftChild = pre[preL + 1];

        int idx = pos[leftChild];

        int rightSize = idx - mirL - 1;
        int leftSize = preR - preL - rightSize;

        root->left = build(pre, preMirror,
                           preL + 1,
                           preL + leftSize,
                           idx,
                           mirR);

        root->right = build(pre, preMirror,
                            preL + leftSize + 1,
                            preR,
                            mirL + 1,
                            idx - 1);

        return root;
    }
                
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        int n = pre.size();

        for (int i = 0; i < n; i++)
            pos[preMirror[i]] = i;

        return build(pre, preMirror, 0, n - 1, 0, n - 1);
       
        
    }
};