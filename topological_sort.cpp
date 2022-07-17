/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[],vector<int>& visited,int v,stack<int> & s){
    visited[v] = 1;
    for(auto it: adj[v]){
        if(!visited[it]){
            dfs(adj,visited,it,s);
        }
    }
    s.push(v);
    
}

void topo(vector<int> adj[],vector<int>& visited,int n){
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,visited,i,s);
        }
    }
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main()
{
    int n,m,u,v;
    cout<<"Enter number of vertices and edges : ";
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> visited(n,0);
    topo(adj,visited,n);
    return 0;
}
