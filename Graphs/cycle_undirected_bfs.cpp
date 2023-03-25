#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<int>g[],vector<bool>&vis,int node){
    queue<pair<int,int>>q;
    q.push({node,-1});
    vis[node]=true;
    while(!q.empty()){
        int val=q.front().first;
        int p=q.front().second;
        q.pop();
        for(auto i:g[val]){
            if(!vis[i]){
                q.push({i,val});
                vis[i]=true;
            }
            else if(i!=p)
            return true;
        }
    }
    return false;
}
bool check(vector<int>g[], int v){
    vector<bool>vis(v+1,false);
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            if(bfs(g,vis,i))
            return true;
        }
    }
    return false;
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<int>g[v+1];
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout<<check(g,v);
}