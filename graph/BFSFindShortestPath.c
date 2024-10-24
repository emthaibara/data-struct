#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Graph{
    int* v;
    int** edge;
    int size;
}Graph;

Graph* initGraph(int size){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = size;
    graph->v = (int*)malloc(sizeof(int)*(size+1));
    graph->edge = (int**)malloc(sizeof(int*)*(size+1));
    for(int i = 0 ; i < size+1 ; i++){
        graph->edge[i] = (int*)malloc(sizeof(int)*(size+1));
    }
    return graph;
}

void genGraph(Graph* graph){
    int i,j;
    scanf("%d",&i);
    scanf("%d",&j);
    while(i != 999 || j != 999){
        graph->v[i] = 1;
        graph->v[j] = 1;
        graph->edge[i][j] = 1; //拓扑排序针对的是有向图，[i][j],[j][i]意义不同
        scanf("%d",&i);
        scanf("%d",&j);
    }
}

//BFS算法求单源最短路径：传入一个无权图和一个顶点u，该算法会求解u到其他顶点的最短路径
//思路如下：我们以u为bfs的起点，又因为bfs是逐层遍历，每一次到达的顶点与u的距离肯定是最短的。
void bfsFindShortestPath(Graph* g,int u){
    int size = g->size;
    int dist[size+1];
    int queue[size+1];
    int front = 0 , rear = 0;
    bool visited[size+1];
    for(int i = 0 ; i < size+1 ; i++)visited[i] = false; 
    queue[rear++] = u;
    int level = 1; //记录当前在第几层，即为u到顶点i的最短路径长度
    while(front < rear){
        int v = queue[front++];
        visited[v] = true;
        for(int i = 1 ; i < size+1 ; i ++){
            if(!visited[i] && g->edge[v][i] == 1){
                printf("u=%d与顶点%d的最短路径长度为:%d\n",u,i,level);
                queue[rear++] = i;
            }
        }
        level ++;
    }
}
// 有向图无权图：1 2 1 3 2 1 2 4 2 5 3 1 3 6 4 2 4 7 5 2 5 8 5 9 6 3 7 4 8 5 9 5 999 999 

int main(){
    Graph* graph = initGraph(10);
    genGraph(graph);
        //直接打印输出邻接表
    printf("打印输出图: \n");
    for(int i = 1 ; i <= graph->size ; i++){
        for(int j = 1 ; j <= graph->size ; j++){
            printf("%d ",graph->edge[i][j]);
        }
        printf("\n");
    }
    bfsFindShortestPath(graph,1);
}