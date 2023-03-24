#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>v[], vector<bool>&vis,vector<int>&l){
    vis[node]=true;
    l.push_back(node);
    for(auto i:v[node]){
        if(!vis[i])
        dfs(i,v,vis,l);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool>vis(n+1,false);
    vector<int>ans;
    dfs(3,g,vis,ans);
    for(auto i:ans)
    cout<<i<<" ";
}