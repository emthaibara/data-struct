#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Graph{
    int* v; //顶点集（这里不带信息，带信息的是aov网，这里只研究拓扑排序）
    int** edge; //边带权值就是aoe网、不带权值就是aov网
    int size; //顶点数量
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

//判断某个顶点的入度是否为1
bool inDegreeIsZero(Graph* graph,int i){
    bool tag = true;
    for(int j = 1 ; j < graph->size+1 ; j++){ //找到所有入度为0的作为拓扑排序的起点
        if(graph->edge[j][i] == 1){
            tag = false;
             break;
        }
    }
    return tag;
}
//每次找入度为0的顶点，然后删除该顶点并输出
int* topologicalSort(Graph* graph){
    int size = graph->size;
    int* res = (int*)malloc(sizeof(int)*(size+1));
    int count = 0;
    int stack[size];
    int top = 0;
    //找到所有入度为0的顶点并加入队列,作为拓扑排序的起点
    for(int i = 1 ; i < size+1 ; i++){
        if(graph->v[i] == 0)continue; //如果顶点不存在就跳过
        if(inDegreeIsZero(graph,i)){
            stack[top++] = i; //将入度为0的顶点加入队列
        }
    }
    //pop一个入度为0的顶点，并加入拓扑排序的结果数组中，并删除v相邻的边，然后再判断相邻顶点是否入度为1，重复上述步骤
    while(top > 0){ //队列为空则结束
        int v = stack[--top]; //出列
        res[count++] = v; //加入拓扑排序结果里
        for(int i = 1 ; i < size+1 ; i++){
            if(i == v || graph->v[i] == 0)continue;
            graph->edge[v][i] = 0; //v到任何顶点的边都要删除
            //再判断该顶点是不是入度为1
            if(inDegreeIsZero(graph,i)){
                stack[top++] = i;
                printf("v=%d i=%d top=%d \n",v,i,top);
            }
        }
        //删除顶点
        graph->v[v] = 0;
    }
    //如果结果长度小于顶点数，存在环
    if(count < size){
        printf("拓扑排序失败，该有向图存在环路\n");
        return res;
    }else{
        return res;
    }
}

int main(){
    Graph* graph = initGraph(5);
    genGraph(graph);
        //直接打印输出邻接表
    printf("打印输出邻接表: \n");
    for(int i = 1 ; i <= graph->size ; i++){
        for(int j = 1 ; j <= graph->size ; j++){
            printf("%d ",graph->edge[i][j]);
        }
        printf("\n");
    }
    int* res = topologicalSort(graph);
    printf("拓扑排序结果为：");
    for(int i = 0 ; i < graph->size ; i++){
        printf("%d ",res[i]);
    }
    printf("\n");
}
// 1 4 1 2 2 4 2 3 3 5 4 5 4 3 999 999