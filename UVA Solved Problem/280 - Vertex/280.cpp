#include<bits/stdc++.h>

using namespace std;

vector<vector<int> >g(102);
int n,starting;
int visited[102];
int ans[102];

void dfs(int u,int visited[]){
    visited[u] = 1;
    int sz=g[u].size();
    for(int i=0; i<sz; i++){
        int v=g[u][i];
        if(visited[v] == 0){
            ans[v] = 1;
            dfs(v,visited);
        }
        else if(visited[v]==1 && v==starting){
            ans[v] = 1;
        }
    }
    visited[u] = 2;
}

void initDfs(int u){
    for(int i=0; i<=n; i++){
        visited[i]=0;
        ans[i] = 0;
    }
    starting = u;
    dfs(u,visited);
    int total = 0;
    vector<int>res;
    for(int i=1;i<=n; i++) if(ans[i]==0){
        res.push_back(i);
        total++;
    }
    printf("%d",total);
    for(int i=0; i<total; i++) printf(" %d",res[i]);
    printf("\n");
}

int main(){

    while(scanf("%d",&n) && n){
        int a,b,tot;
        while(scanf("%d",&a) && a){
            while(scanf("%d",&b) && b){
                g[a].push_back(b);
            }
        }
        scanf("%d",&tot);
        while(tot--){
            int st;
            scanf("%d",&st);
            initDfs(st);
        }
        for(int i=0; i<=n; i++) g[i].clear();
    }
    return 0;
}
