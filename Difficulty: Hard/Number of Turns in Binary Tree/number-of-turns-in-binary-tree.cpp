class Solution {
  public:

    Node* lca(Node* root, int n1, int n2) {
        if (root == NULL) return NULL;

        if (root->data == n1 || root->data == n2)
            return root;

        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);

        if (left && right)
            return root;

        return left ? left : right;
    }

    bool findNode(Node* root, int target) {
        if (root == NULL) return false;

        if (root->data == target)
            return true;

        return findNode(root->left, target) ||
               findNode(root->right, target);
    }

    void countNode(Node* root, int turns, int &ans,
                   char dir, int target) {

        if (root == NULL) return;

        if (root->data == target) {
            ans = turns;
            return;
        }

        if (dir == 'L') {
            countNode(root->left, turns, ans, 'L', target);
            countNode(root->right, turns + 1, ans, 'R', target);
        }
        else {
            countNode(root->left, turns + 1, ans, 'L', target);
            countNode(root->right, turns, ans, 'R', target);
        }
    }

    int numberOfTurns(Node* root, int first, int second) {

        // If either node doesn't exist
        if (!findNode(root, first) ||
            !findNode(root, second))
            return -1;

        Node* Lca = lca(root, first, second);

        int turns1 = 0;
        int turns2 = 0;

        // LCA -> first
        if (Lca->data != first) {
            countNode(Lca->left, 0, turns1, 'L', first);
            countNode(Lca->right, 0, turns1, 'R', first);
        }

        // LCA -> second
        if (Lca->data != second) {
            countNode(Lca->left, 0, turns2, 'L', second);
            countNode(Lca->right, 0, turns2, 'R', second);
        }

        int totalTurns = turns1 + turns2;

        // LCA is between both nodes
        if (Lca->data != first &&
            Lca->data != second) {
            totalTurns++;
        }

        // GFG: straight-line path => -1
        if (totalTurns == 0)
            return -1;

        return totalTurns;
    }
};