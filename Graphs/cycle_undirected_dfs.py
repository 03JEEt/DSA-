from collections import defaultdict
def dfs(s,v,d,par):
    v[s]=True
    
    for i in range(len(d[s])):
        if(v[d[s][i]]==True and par[s]!=d[s][i]):
            return True
        if(v[d[s][i]]==False):
            par[d[s][i]]=s
            if(dfs(d[s][i],v,d,par)):
                return True
    return False
def connected(d):
    n=len(d)
    v=[False]*(n)
    p=[None]*(n)
    for i in range(n):
        if(v[i]==False):
            if(dfs(i,v,d,p)):
                return True
    return False

if __name__=="__main__":

    v,e=map(int,input("Enter vertices no. and edge").split())
    d=defaultdict(list)
    for i in range(e):
        x,y=map(int,input("Enter edges").split())
        d[x].append(y)
        d[y].append(x)
   
    print(connected(d))