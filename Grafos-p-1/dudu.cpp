#include<bits/stdc++.h>

using namespace std;

const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;
vector<int> LA[10010];
int vis[10010]; //variavel global, incia com 0
int n,m,u,v,t;
int hascycle = 0;

//dudu, check atŕ encontrar um vertice que ainda esta sendo explorado - AKA CINZA  || ou ordenação topologica

void dfs(int u){

    vis[u] = CINZA;
    //cout << u << endl;

    for(int v: LA[u]){
        if(vis[v] == BRANCO){
            dfs(v);
        }else if(vis[v] == CINZA){
            hascycle = 1;
        }

    }

    vis[u] = PRETO;
}


int main(){

    cin >> t;

    while(t--){
        hascycle = 0;
        cin >> n >> m;
    
        for(int i=1;i<=n;i++){
            vis[i] = BRANCO;
            LA[i].clear();
        }
    //DFS
    

        for(int i=0;i<=m;i++){
            cin >> u >> v;
            LA[u].push_back(v);
        }

        for(int i=1;i<=n;i++){
            if(vis[i] == BRANCO){
                dfs(i);
                if(hascycle) break;
            }
        }
        if(hascycle) cout << "SIM" << endl;
        else{
            cout << "NAO"<<endl;
        }
    }


}