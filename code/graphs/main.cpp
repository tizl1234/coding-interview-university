#include <iostream>
#include <list>
#include <queue>
#include <stack>

class Graph {
public:
    Graph(int V);
    ~Graph();
    void AddEdge(int v, int w);
    void BFS(int vertex);
    void DFS(int source);
    void DFSRecursive(int source);
private:
    int vertices;
    bool* visited;
    std::list<int>* adjLists;//ptr of array of adj lists
    void DFSUtil(int vertex);
};

Graph::Graph(int V) {
    vertices = V;
    adjLists = new std::list<int>[vertices];
    visited = new bool[vertices];
}

Graph::~Graph() {
    delete[] adjLists;
}

void Graph::AddEdge(int v, int w) {
    //bot oriented graph
    adjLists[v].push_back(w);
    adjLists[w].push_back(v);
}

void Graph::DFS(int source) {
    std::stack<int> stack;
    stack.push(source);

    while(!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (visited[v] == false) {
            std::cout << v << " ";
            visited[v] = true;
        }

        for (const auto& s : adjLists[v]) {
            if (visited[s] == false) {
                stack.push(s);
            }
        }        
    }
}

void Graph::DFSRecursive(int vertex) {
    for (int i = 0; i < vertices; ++i) {
        if(visited[i] == false) {
            DFSUtil(i);
        }
    }
}

void Graph::DFSUtil(int vertex) {
    visited[vertex] = true;
    std::cout << vertex << " ";

    for (const auto& v : adjLists[vertex]) {
        if (visited[v] == false) {
            DFSUtil(v);
        }
    }
}

void Graph::BFS(int vertex) {
    std::list<int> queue;

    visited[vertex] = true;
    queue.push_back(vertex);

    while (!queue.empty()) {
        vertex = queue.front();

        std::cout << vertex << " ";
        queue.pop_front();

        for (const auto& v : adjLists[vertex]) { 
            if (visited[v] == false) {
                visited[v] = true;
                queue.push_back(v);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Graph g(5);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(0, 3);
    g.AddEdge(1, 2);
    g.AddEdge(2, 4);

    g.BFS(0);
    return 0;
}
