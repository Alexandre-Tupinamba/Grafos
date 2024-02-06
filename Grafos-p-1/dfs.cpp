#include<bits/stdc++.h>

using namespace std;

const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;
vector<int> LA[100];
int vis[100]; //variavel global, incia com 0
int n,m,u,v;

//dudu, check atŕ encontrar um vertice que ainda esta sendo explorado - AKA CINZA  || ou ordenação topologica

void dfs(int u){

    vis[u] = CINZA;
    cout << u << endl;

    for(int v: LA[u]){
        if(vis[v] == CINZA){
            cout << "SIM" << endl;
            break;
        }
        if(vis[v] == BRANCO){
            dfs(v);
        }

    }

    vis[u] = PRETO;
}


int main(){

    cin >> n >> m;

    //DFS

    for(int i=0;i<=m;i++){
        cin >> u >> v;
        LA[u].push_back(v);
        LA[v].push_back(u);

    }

    dfs(0);

    /*
    //BFS
    queue<int> fila;

    fila.push(0);
    vis[0] = CINZA;

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        cout << u << endl;

        

        for(int v: LA[u]){
            if(vis[v] == BRANCO){
                vis[v] = CINZA;
                fila.push(v);
            }
        }

        vis[u] = PRETO;
    }
    */
}