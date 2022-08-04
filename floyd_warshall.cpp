#include <bits/stdc++.h>
#define inf 1000
using namespace std;
int min(int num1,int num2){
    if(num1 > num2)return num2;
    return num1;
}
void printGraph(int graph[][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(graph[i][j] == 1000)cout<<"inf ";
            else{
            cout<<graph[i][j]<<"   ";}
        }cout<<"\n";
    }
}

void floyd_warshall(int graph[][4]){
    for(int k=0;k<4;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }
    
    printGraph(graph);
}

int main() {
    int graph[4][4] = {
        {0,       5,       inf, 10},
        {inf, 0,       3,       inf},
        {inf, inf, 0,       1},
        {inf, inf, inf, 0}
    };
    
    floyd_warshall(graph);
    return 0;
}
