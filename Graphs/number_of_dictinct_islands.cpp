#include<bits/stdc++.h>
using namespace std;
void dfs(int r, int c,vector<vector<bool>>&vis,vector<vector<int>>g, vector<pair<int,int>>&temp,int ro, int co ){
    int n=g.size();
    int m=g[0].size();
    vis[ro][co]=true;
    temp.push_back({ro-r, co-c});
    int drow[]={-1,0,0,1};
    int dcol[]={0,-1,1,0};
    for(int i=0;i<4;i++){
        int nrow=drow[i]+ro;
        int ncol=dcol[i]+co;
        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and g[nrow][ncol]==1){
            dfs(r,c,vis,g,temp,nrow,ncol);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>g(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    set<vector<pair<int,int>>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==1 and !vis[i][j]){
                vector<pair<int,int>>temp;
                dfs(i,j,vis,g,temp,i,j);
                s.insert(temp);
            }
        }
    }
    cout<<s.size();
}