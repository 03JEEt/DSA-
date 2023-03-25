#include<bits/stdc++.h>
using namespace std;
int oranges(vector<vector<int>>&v){
    int n=v.size();
    int m=v[0].size();

    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(v[i][j]==2){
                q.push({{i,j},0});
            }
        }
    }
    
    int tm=0;
    while(!q.empty()){
        int i=q.front().first.first;
        int j=q.front().first.second;
        int t=q.front().second;
        //cout<<i<<j<<" ";
        q.pop();
        tm=max(tm,t);
        int dcol[]={0,-1,1,0};
        int drow[]={-1,0,0,1};
        for(int k=0;k<4;k++){
            int ncol=j+dcol[k];
            int nrow=i+drow[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(v[nrow][ncol]==1){
                    //cout<<nrow<<ncol<<" ";
                    q.push({{nrow,ncol},t+1});
                    v[nrow][ncol]=2;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==1)
            return -1;
        }
        
    }
    return tm;
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
    cout<<oranges(v);
}