from collections import defaultdict
def dfs(node, g, c, col):
    c[node]=col
    if col==0:
        col=1
    else:
        col=0
    for i in g[node]:
        if(c[i]==-1):
            
            if(dfs(i,g,c, col)==False):
                return False
        if(c[i]==c[node]):
            return False
    return True
if __name__=="__main__":
    x,y=map(int,input().split())
    d=defaultdict(list)
    for i in range(y):
        u,v=map(int,input().split())
        d[u].append(v)
        d[v].append(u)
    l=[-1]*(x+1)
    t=True
    for i in range(1,v+2):
        if(l[i]==-1):
           if( dfs(i,d,l,0)==False):
               t=False
               break
    print(l)
    print(t)