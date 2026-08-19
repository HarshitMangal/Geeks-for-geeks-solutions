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
class Solution {
  public:
    int solve(Node*root,int &ans){
        if(root==NULL) return INT_MAX;
        if(root->left==NULL&&root->right==NULL) return root->data;
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        int mini=min(left,right);
        ans=max(ans,root->data-mini);
        return min(mini,root->data);
    }
    int maxDiff(Node* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
            }
};