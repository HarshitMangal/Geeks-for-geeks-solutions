// User function Template for C++

class Solution {
  public:
   bool isanagrame(vector<int>&a,vector<int>&b){
       unordered_map<int,int>fre;
       for(auto  it:a){
           fre[it]++;
       }
       for(auto it:b){
           fre[it]--;
       }
       for(auto it:fre){
           if(it.second!=0) return false;
       }
       return true;
   }
    bool areAnagrams(Node *root1, Node *root2) {
        //using bfs with level order tarversal
        queue<Node*>q1;
        queue<Node*>q2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty()||!q2.empty()){
            vector<int>a;
            vector<int>b;
            int s1=q1.size();
            int s2=q2.size();
            for(int i=0;i<s1;i++){
                Node*temp=q1.front();
                q1.pop();
                a.push_back(temp->data);
                if(temp->left!=NULL) q1.push(temp->left);
                if(temp->right!=NULL) q1.push(temp->right);
            }
            for(int i=0;i<s2;i++){
                Node*temp=q2.front();
                q2.pop();
                b.push_back(temp->data);
                if(temp->left!=NULL)  q2.push(temp->left);
                if(temp->right!=NULL) q2.push(temp->right);
            } 
            if(!isanagrame(a,b))  return 0;
        }
         return 1;
    }
};