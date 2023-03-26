#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int j,vector<vector<char>>g, vector<vector<bool>>&vis){
    int n=g.size();
    int m=g[0].size();
    if(i>=0 and i<n and j>=0 and j<m and g[i][j]=='O' and !vis[i][j]){
        vis[i][j]=true;
        dfs(i+1,j,g,vis);
        dfs(i-1,j,g,vis);
        dfs(i,j+1,g,vis);
        dfs(i,j-1,g,vis);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>g(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    vector<vector<bool>>vis(n,vector<bool>(m));
    for(int i=0;i<m;i++){
        if(g[0][i]=='O' and !vis[0][i]){
            dfs(0,i,g,vis);
        }
        if(g[n-1][i]=='O' and !vis[n-1][i]){
            dfs(n-1,i,g,vis);
        }
    }
    for(int i=0;i<n;i++){
        if(g[i][0]=='O' and !vis[i][0]){
            dfs(i,0,g,vis);
        }
        if(g[i][m-1]=='O' and !vis[i][m-1]){
            dfs(i,m-1,g,vis);
        }
    }
    vector<vector<char>>ans(n,vector<char>(m,'X'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] and g[i][j]=='O')
            ans[i][j]='O';
        }
    }
    
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}