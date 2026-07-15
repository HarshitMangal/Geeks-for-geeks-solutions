class Solution {
  public:
     
      vector<int>parent;
      vector<int>rank;
      int find(int x){
          if(x==parent[x]) return x;
          return parent[x]=find(parent[x]);
      }
      void unio(int x,int y){
           int x_parent=find(x);
           int y_parent=find(y);
           if(x_parent==y_parent) return;
           if(rank[x_parent]>rank[y_parent]){
                parent[y_parent]=x_parent;
           }
           else if(rank[x_parent]<rank[y_parent]){
                   parent[x_parent]=y_parent;
           }
           else{
                parent[x_parent]=y_parent;
                rank[y_parent]++;
           }
      }
       int kruskal(vector<vector<int>>&edges){
           int sum=0;
           for(auto it:edges){
               int u=it[0];
               int v=it[1];
               int w=it[2];
               int parent_u=find(u);
               int parent_v=find(v);
               if(parent_u!=parent_v){
                   unio(u,v);
                   sum+=w;
               }
           }
           return sum;
       }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
           parent.resize(V);
           rank.resize(V,0);
           for(int i=0;i<V;i++){
                    parent[i]=i;
             }
           //sort edge by weight
           sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
                  return a[2]<b[2];
           });
           return kruskal(edges);
           
           
        
    }
};