#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<int>g[],vector<int>&vis,vector<int>&p){
    vis[node]=true;
    p[node]=true;
    for(auto i :g[node]){
        if(!vis[i]){
            if(dfs(i,g,vis,p))
            return true;
        }
        if(p[i])
        return true;
    }
    p[node]=false;
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(auto i:g){
        
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    bool t=false;
    vector<int>vis(n+1,false);
    vector<int>p(n+1,false);
    for(int i=1;i<=n+1;i++){
        if(!vis[i]){
            if(dfs(i,g,vis,p)){
                t=true;
                break;
            }
        }
    }
    cout<<t;
}