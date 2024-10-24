#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Graph{
    int* vertexs;   //顶点集合
    int** adjMatrix; //邻接矩阵
    int vertexNumber; //该图有多少顶点
}Graph;

//初始化图
Graph* initGraph(int vertexNumber){
    Graph* graph = (Graph*)malloc(sizeof(Graph)); //初始化图结构体
    int row = vertexNumber+1,col = vertexNumber+1;
    graph->vertexNumber = vertexNumber; //初始化顶点总数
    graph->vertexs = (int*)malloc(sizeof(int)*row); //初始化顶点集合
    graph->adjMatrix = (int**)malloc(sizeof(int)*row); //初始化顶点二位数组的列数
    for(int i = 0 ; i < row; i++){
        graph->adjMatrix[i] = (int*)malloc(sizeof(int)*col); //初始化邻接表的行数
    }
    return graph; //返回初始化的图
}

//构造图
//规则：先输入顶点集，再输入顶点集合（若用户输入：1 2 3 4，则1和2为一组边，3和4为一组边，每次读取一组数为边）
void createGraph(Graph* graph){
    //输入顶点集
    int v;
    scanf("%d",&v);
    while(v != 888){
        graph->vertexs[v] = 1;
        scanf("%d",&v);
    }
    //输入边集(不带权值)
    int i,j;
    scanf("%d",&i);
    scanf("%d",&j);
    while(i != 999 || j != 999){
        graph->adjMatrix[i][j] = 1;
        scanf("%d",&i);
        scanf("%d",&j);
    }
}

//遍历图 dfs或bfs
bool* visited; //用于dfs遍历图的时候是否访问进行记录，因为这里选择的是递归写法，要使用全局变量数组，如果写在形式参数则无法保存全局的访问记录
void dfs(Graph* graph,int curVertex){
    if(visited[curVertex])return;
    visited[curVertex] = true;
    printf("%d ",curVertex);
    for(int v = 1 ; v <= graph->vertexNumber; v++){
        //如果该顶点没有被访问过，并且与该顶点之间相邻则继续深入
        if(!visited[v] && graph->adjMatrix[curVertex][v] == 1)dfs(graph,v);
    }
}

void bfs(Graph* graph,int curVertex){
    int queue[(graph->vertexNumber)+1]; //顺序队列
    int front = 0,rear = 0; //队头和队尾
    queue[rear++] = curVertex;
    while(front < rear){
        int curV = queue[front++];
        if(visited[curV])continue;
        visited[curV] = true;
        printf("%d ",curV);
        for(int v = 1 ; v <= graph->vertexNumber ; v++){
            if(!visited[v] && graph->adjMatrix[curV][v] == 1){
                queue[rear++] = v;
            }
        }
    }
}

void printfGraph(Graph* graph){
    //初始化访问记录
    visited = (bool*)malloc(sizeof(bool)*(graph->vertexNumber+1));
    for(int i = 0 ; i < graph->vertexNumber+1 ; i++){
        visited[i] = false;
    }
    //直接打印输出邻接表
    printf("打印输出邻接表: \n");
    for(int i = 1 ; i <= graph->vertexNumber ; i++){
        for(int j = 1 ; j <= graph->vertexNumber ; j++){
            printf("%d ",graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("dfs遍历邻接表:\n");
    //两种遍历方式：dfs和bfs
    //对每一个顶点进行dfs（访问过的则跳过）
    for(int v = 1 ; v < graph->vertexNumber+1 ; v++){
        if(graph->vertexs[v]!=0 && !visited[v])dfs(graph,v);
    }
    //重新初始化
    for(int i = 0 ; i < graph->vertexNumber+1 ; i++){
        visited[i] = false;
    }
    printf("\nbfs遍历邻接表:\n");
    //对每一个顶点进行bfs（访问过的则跳过）
    for(int v = 1 ; v < graph->vertexNumber+1 ; v++){
        if(graph->vertexs[v]!=0 &&!visited[v])bfs(graph,v);
    }
    printf("\n");
}
//增加节点
void addVertex(Graph* graph,int vertex){
    if(vertex > graph->vertexNumber+1){
        printf("待新增的顶点，超出了邻接矩阵的顶点范围");
        return;
    }
    graph->vertexs[vertex] = 1;
}
//增加边
void addEdge(Graph* graph,int i,int j){
    //判断顶点是否超出邻接矩阵的大小范围
    if(i > graph->vertexNumber+1 || j > graph->vertexNumber+1){
        printf("该加入的边涉及的顶点超出了邻接矩阵的顶点范围");
        return;
    }
    //如果顶点i或者j不存在则新增顶点
    if(graph->vertexs[i] == 0)graph->vertexs[i] = 1;
    if(graph->vertexs[j] == 0)graph->vertexs[i] = 1;
    graph->adjMatrix[i][j] = 1;
    graph->adjMatrix[j][i] = 1; //如果是无向图就可以有这一行，如果是有向图就得删了
}
//删除顶点:要把涉及的边全部删除，删除第k列和第k行
void deleteVertex(Graph* graph,int vertex){
    if(vertex > graph->vertexNumber+1 || graph->vertexs[vertex]==0){
        printf("待删除的顶点，不再邻接矩阵范围内，或者该顶点还未加入到图当中");
        return;
    }
    //删除顶点
    graph->vertexs[vertex] = 0;
    //删除连接该顶点的所有边
    for(int i = 0 ; i < graph->vertexNumber+1 ; i++){
        graph->adjMatrix[vertex][i] = 0;
        graph->adjMatrix[i][vertex] = 0;
    }
}
//删除边就比较简单，顶点不动，邻接表置为0就行
void deleteEdge(Graph* graph,int i,int j){
    if(i > graph->vertexNumber+1 || j > graph->vertexNumber+1 || graph->vertexs[i]==0 || graph->vertexs[j]==0){
        printf("待删除的边涉及的顶点在该图不存在");
        return;
    }
    graph->adjMatrix[i][j] = 0;
    graph->adjMatrix[j][i] = 0; //有向图就不能有这一行
}

//判断图的连通性：连通图的定义是指无向图当中任意两个顶点均连通，很简单的思路就是dfs一遍如果有没走到的顶点就证明不连通。
bool* visited_;
void dfs_(Graph* graph,int curVertex){
    if(visited_[curVertex])return;
    visited_[curVertex] = true;
    for(int v = 0 ; v < graph->vertexNumber+1 ; v++){
        if(!visited_[v]&&graph->adjMatrix[curVertex][v] == 1)dfs(graph,v);
    }
}
bool isConnected(Graph* graph){
    for(int i = 0 ; i < graph->vertexNumber+1 ; i++){
        visited_[i] = false;
    }
    dfs_(graph,1);
    for(int v = 0 ; v < graph->vertexNumber+1 ; v++){
        if(graph->vertexs[v]!=0 && visited_[v] == false)return false;
    }
    return true;
}
//判断图是否有环：用栈暂存递归路径，如果有遇到栈内元素那证明有环路
bool* visited__;
bool result = false;
void dfs__(Graph* graph,int curVertex,int parent){
    if(visited_[curVertex])return;
    visited_[curVertex] = true;
    for(int v = 0 ; v < graph->vertexNumber+1 ; v++){
        if(visited_[v] && v != parent)result = true; //如果访问道已经访问过的顶点，并且还不是上一层的节点那肯定有环
        if(!visited_[v] && graph->adjMatrix[curVertex][v] == 1)
            dfs__(graph,v,curVertex);
    }
}
bool hasCycle(Graph* graph){
    //初始化访问记录
    visited__ = (bool*)malloc(sizeof(bool)*(graph->vertexNumber+1));
    for(int i = 0 ; i < graph->vertexNumber+1 ; i++){
        visited__[i] = false;
    }
    //对每一个顶点进行dfs（访问过的则跳过）
    for(int v = 1 ; v < graph->vertexNumber+1 ; v++){
        if(graph->vertexs[v]!=0 && !visited__[v])dfs__(graph,v,-1);
    }
    return result;
}

int main(){
    Graph* graph = initGraph(10);
    createGraph(graph);
    addVertex(graph,8);
    addEdge(graph,8,6);
    // deleteVertex(graph,8);
    deleteEdge(graph,8,6);
    printfGraph(graph);
}

//1 2 3 4 5 6 888
//2 3 4 1 6 5 888
//1 2 1 3 2 1 2 3 2 4 3 1 3 5 3 4 4 3 4 5 4 2 5 3 5 4 999 999