#include<bits/stdc++.h>
using namespace std;
void bfs(int i, int j, vector<vector<int>>v, vector<vector<bool>>&vis){
    vis[i][j]=true;
    queue<pair<int,int>>q;
    int n=v.size();
    int m=v[0].size();
    q.push({i,j});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int k=-1;k<=1;k++){
            for(int l=-1;l<=1;l++){
               int r=x+k;
                int c=y+l;
                if( (r>=0 and r<n) and (c>=0 and c<m)  ){
                    if(v[r][c]==1){
                        if(!vis[r][c]){
                            vis[r][c]=true;
                            q.push({r,c});
                        }
                    }
                }
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
  
    int counter=0;
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(!vis[i][j] and v[i][j]==1){
                counter++;  
                bfs(i,j,v,vis);
            }
        }
    }
    cout<<counter;
}