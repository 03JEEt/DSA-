
from typing import List

class Solution:
    def numberOfEnclaves(self, grid: List[List[int]]) -> int:
        # code here
        n=len(grid)
        m=len(grid[0])
        vis=[[False for i in range(m)]for i in range(n)]
        q=[]
        for i in range(n):
            if(grid[i][0]==1 and vis[i][0]==False):
                q.append([i,0])
                vis[i][0]=True
            if(grid[i][m-1]==1 and vis[i][m-1]==False):
                q.append([i,m-1])
                vis[i][m-1]=True
        for i in range(m):
            if(grid[0][i]==1 and vis[0][i]==False):
                q.append([0,i])
                vis[0][i]=True
            if(grid[n-1][i]==1 and vis[n-1][i]==False):
                q.append([n-1,i])
                vis[n-1][i]=True
        while len(q)!=0:
            a=q[0][0]
            b=q[0][1]
            q.pop(0)
            drow=[-1,0,0,1]
            dcol=[0,-1,1,0]
            for i in range(4):
                nrow=a+drow[i]
                ncol=b+dcol[i]
                
                if nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1 and vis[nrow][ncol]==False:
                    q.append([nrow,ncol])
                    vis[nrow][ncol]=True
            
        cnt=0
        for i in range(n):
            for j in range(m):
                if vis[i][j]==False and grid[i][j]==1:
                    cnt+=1
        return cnt

if __name__=="__main__":
    n,m=map(int,input().split())
    grid=[]
    for i in range(n):
        grid.append([int(i) for i in input().strip().split()])
    obj=Solution()
    print(obj.numberOfEnclaves(grid))