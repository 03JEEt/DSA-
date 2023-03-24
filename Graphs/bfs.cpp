#include<bits/stdc++.h>

using namespace std;
vector<int>bfs(int x, int n, vector<int>v[]){
    vector<int>ans;
    queue<int>q;
    q.push(x);
    vector<bool>vis(n+1,false);
    vis[0]=true;
    vis[x]=true;
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto i:v[node]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
    }
    return ans;
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
   for(int i=0;i<=n;i++){
    cout<<i<<" : ";
    for(int j=0;j<g[i].size();j++){
        cout<<g[i][j]<<" ";
    }
    cout<<endl;
   }
   vector<int>ans=bfs(6,n,g);
   for(auto i:ans)
   cout<<i<<" ";
}
// 8
// 8
// 1 2
// 1 6
// 2 3
// 2 4
// 6 7
// 6 8
// 4 5
// 7 5