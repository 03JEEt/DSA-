#include<bits/stdc++.h>
using namespace std;
bool bfs(int node, vector<int>g[], vector<int>&c){
    c[node]=0;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(auto i:g[a]){
            if(c[i]==-1){
                c[i]=!c[a];
                q.push(i);
            }
            else if(c[i]==c[a])
            return false;
        }
    }
    return true;
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<int>g[v+1];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool t=true;
    vector<int>c(v+1,-1);
    for(int i=1;i<=v;i++){
        if(c[i]==-1){
            if(!bfs(i,g,c)){
                t=false;
                break;
            }

        }
    }
    cout<<t;
}