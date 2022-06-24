#include<stdio.h>
int v;

void bfs(int adj[][v], int visited[], int start){
    int queue[v];
    int front = -1;
    int rear = -1;
    for(int i=0;i<v;i++){
        visited[i] = 0;
    }
    queue[++rear] = start;
    front++;
    visited[start] = 1;
    while(rear >= front){
        start = queue[front++];
        printf("%c ", start + 65);
        
        for(int j=0;j<v;j++){
            if(adj[start][j] && !visited[j]){
                queue[++rear]  = j;
                visited[j] = 1;
            }
        }
    }
    printf("\n");
}

int dfs(int adj[][v], int visited[], int start){
    int stack[v];
    int top = -1;

    for(int i=0;i<v;i++){
        visited[i] = 0;
    }
    stack[++top] = start;
    visited[start] = 1;
    while(top != -1){

        printf("%c ",start + 65);
        start = stack[top--];
       
        for(int j=0;j<v;j++){
            if(!visited[j] && adj[start][j] == 1){
                stack[++top] = start;
                visited[j] = 1;
                
            }
        }
    }
}

int main(){
    int start,choice;
    printf("Enter number of verices : ");
    scanf("%d",&v);
    int adj[v][v];
    int visited[v] ;
    printf("Enter adjacency matrix : \n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    do{
        printf("Enter choice: \n1.bfs \n2.dfs\n3.exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter start node : (A - 0, B - 1, ...) : ");
            scanf("%d",&start);
            bfs(adj,visited,start);
            break;
           case 2:
            dfs(adj,visited,start);
            break;     
         
            
            case 3:
            break;
        }
    }while(choice!=3);
}
