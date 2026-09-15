/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
       vector<int> cost;
              queue<Node*> q;

              q.push(root);
              int level = 1;

              while (!q.empty()) {
                  int sz = q.size();

                  while (sz--) {
                      Node* node = q.front();
                      q.pop();

                      // leaf node
                      if (node->left == NULL && node->right == NULL) {
                          cost.push_back(level);
                      }

                      if (node->left)
                          q.push(node->left);

                      if (node->right)
                          q.push(node->right);
                  }

                  level++;
              }

              sort(cost.begin(), cost.end());

              int ans = 0;

              for (int c : cost) {
                  if (c <= k) {
                      k -= c;
                      ans++;
                  } else {
                      break;
                  }
              }

              return ans;
        
    }
};