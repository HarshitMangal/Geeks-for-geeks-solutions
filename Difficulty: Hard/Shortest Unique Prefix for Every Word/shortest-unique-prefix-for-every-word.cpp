class Solution {
  public:
      struct trieNode{
       bool isendofword;
       int fre;
       trieNode*children[26];
   };
  trieNode*getNode(){
      trieNode*newNode=new trieNode();
      newNode->isendofword=false;
      newNode->fre=0;
      for(int i=0;i<26;i++){
          newNode->children[i]=NULL;
      }
      return newNode;
  }
   void insert(trieNode*root,string&word){
       trieNode*crawler=root;
       for(int i=0;i<word.length();i++){
           char ch=word[i];
           int idx=ch-'a';
           if(crawler->children[idx]==NULL){
               crawler->children[idx]=getNode();
           }
           crawler=crawler->children[idx];
           crawler->fre++;
       }
       crawler->isendofword=true;
   }
   void freeTrie(trieNode* root) {
    if (root == NULL) return;

    for (int i = 0; i < 26; i++) {
        if (root->children[i]!=NULL) {
            freeTrie(root->children[i]);
        }
    }
    delete root;
}
   string getuniqueprefix(trieNode*root,string&word){
       trieNode*crawler=root;
       string prefix="";
       for(char ch:word){
           int idx=ch-'a';
            crawler=crawler->children[idx];
            prefix+=ch;
            if(crawler->fre==1) break;//unique find
       }
       return prefix;
   }
    vector<string> findPrefixes(vector<string>& arr) {
        int n=arr.size();
         trieNode*root=getNode();
      vector<string>ans;
      trieNode*crawler=root;
      for(int i=0;i<n;i++){
          insert(root,arr[i]);
      }
      for(int i=0;i<n;i++){
          ans.push_back(getuniqueprefix(root,arr[i]));
      }
      freeTrie(root);
      return ans;
        
    }
};