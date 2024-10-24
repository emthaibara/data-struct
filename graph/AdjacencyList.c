#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

MAX_VERTEX=999;

//边节点
typedef struct SideNode{
    int v;
    struct SideNode* next;
}SideNode;
//顶点
typedef struct VertexNode{
    int v;
    struct SideNode* firstSide;
}VertexNode;

typedef struct Graph{
    //顶点集
    struct VertexNode* vertexs[MAX_VERTEX];
}Graph;
/*
    图（不带权边）的连通性判断
 */

bool visited[MAX_VERTEX];

//dfs
void isConnectedGraph(Graph* graph){
        //初始化记录表，记录每个顶点是否被访问
    for(int i = 0 ; i < MAX_VERTEX ; i++){
        visited[i] = false;
    }
    //该图的第一个顶点是1
    //这里不需要对每个点dfs因为只是判断连通性，如果是遍历图的话就要dfs每一个顶点，确保某些单独连通的子图没被遍历
    dfs(graph,1);
    for(int i = 0 ; i < MAX_VERTEX ; i++){
        if(visited[i] == false){
            printf("该图非连通图");
            break;
        }
    }
    printf("该图为连通图");
}

void dfs(Graph* graph,int cur_vertex){
    if(visited[cur_vertex])return; //访问过就跳过
    visited[cur_vertex] = true; //没访问就设置为访问过
    SideNode* side = graph->vertexs[cur_vertex]->firstSide; //取当前节点的第一个相邻边
    while(side != NULL){ //遍历相邻边
        if(!visited[side->v])dfs(graph,side->v); //如果该边的顶点没被访问过就继续深入dfs
        side = side->next; //遍历 边 链表
    }
}

//bfs
void bfs(Graph* graph,int cur_vertex){
    int queue[MAX_VERTEX]; //暂存某个顶点的所有相邻顶点
    int front = 0; 
    int rear = 0;
    //首节点入列
    queue[rear++] = 1;
    while(front < rear){ //队列空则结束
        int cur_vertex = queue[front++]; //出列
        if(visited[cur_vertex])continue; //判断当前顶点是否访问过，访问过就跳过
        visited[cur_vertex] = true; //没访问就设置为访问过
        SideNode* side = graph->vertexs[cur_vertex]->firstSide; //取当前节点的第一个相邻边
        while(side != NULL){ //遍历相邻边
            if(!visited[side->v])queue[rear++] = side->v; //没被访问过就入列
            side = side->next; //遍历 边 链表
        }
    }
}

int main(){

}