/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
     void inorder(Node*root,vector<int>&ans){
          if(root==NULL) return ;
          inorder(root->left,ans);
          ans.push_back(root->data);
          inorder(root->right,ans);
      }
    int absDiff(Node *root) {
         vector<int>ans;
            inorder(root,ans);
           int mindiff=INT_MAX;
           for(int i=0;i<ans.size()-1;i++){
               int  diff=abs(ans[i+1]-ans[i]);
               mindiff=min(mindiff,diff);
           }
           return mindiff;
        
    }
};