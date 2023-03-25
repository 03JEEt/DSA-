#include<bits/stdc++.h>
using namespace std;
void make(vector<vector<int>>v, vector<vector<bool>>&vis, vector<vector<int>>&ans){
   int n=v.size();
   int m=v[0].size();
   queue<pair<pair<int,int>,int>>q;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(v[i][j]==1){
            vis[i][j]=true;
            q.push({{i,j},0});
        }
    }
   }
   int drow[]={-1,0,0,1};
   int dcol[]={0,-1,1,0};
   while(!q.empty()){
    int a=q.front().first.first;
    int b=q.front().first.second;
    int d=q.front().second;
    q.pop();
    ans[a][b]=d;
    for(int i=0;i<4;i++){
        int nrow=drow[i]+a;
        int ncol=dcol[i]+b;
        if(nrow>=0  and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol]){
            vis[nrow][ncol]=true;
            q.push({{nrow,ncol},d+1});
        }
    }
    
   }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            v[i][j]=x;
        }
    }
    vector<vector<bool>>vis(n,vector<bool>(m));
    vector<vector<int>>ans(n,vector<int>(m));
    make(v,vis,ans);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}