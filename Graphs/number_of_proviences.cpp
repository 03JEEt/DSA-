#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>g[],vector<int>&vis){
    vis[node]=true;
    for(auto i:g[node]){
        if(!vis[i]){
            dfs(i,g,vis);
        }
    }
}
int proviences(int n, vector<int>g[]){
    int counter=0;
    vector<int>vis(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            counter++;
            dfs(i,g,vis);
        }
    }
    return counter;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<int>g[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=proviences(n,g);
    cout<<ans;
}