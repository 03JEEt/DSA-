#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&v,int i, int j, int c, int m){
    int n=v.size();
    int x=v[0].size();
    if(i<0 or i>=n or j<0 or j>=x)
    return;
    if(v[i][j]!=m or v[i][j]==c)
    return;
    v[i][j]=c;
    dfs(v,i,j+1,c,m);
    dfs(v,i-1,j,c,m);
    dfs(v,i,j-1,c,m);
    dfs(v,i+1,j,c,m);
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            v[i][j]=x;
        }
    }
    int sr,sc;
    cin>>sr>>sc;
    int c;
    cin>>c;
    dfs(v,sr,sc,c,v[sr][sc]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}