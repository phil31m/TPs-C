#include <iostream>
using namespace std;
class Graph {
private:
    struct AdjListNode {
        int dest;
        AdjListNode* next;
        AdjListNode(int d) : dest(d), next(nullptr) {}
    };

    int V;
    AdjListNode** adjLists;
    
    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";
        AdjListNode* current = adjLists[v];
        while (current != nullptr) {
            if (!visited[current->dest]) {
                DFSUtil(current->dest, visited);
            }
            current = current->next;
        }
    }

public:
    Graph(int V) : V(V) {
        adjLists = new AdjListNode*[V];
        for (int i = 0; i < V; ++i) {
            adjLists[i] = nullptr;
        }
    }

    ~Graph() {
        for (int i = 0; i < V; ++i) {
            AdjListNode* current = adjLists[i];
            while (current != nullptr) {
                AdjListNode* temp = current->next;
                delete current;
                current = temp;
            }
        }
        delete[] adjLists;
    }

    void addEdge(int src, int dest) {
        AdjListNode* newNode = new AdjListNode(dest);
        newNode->next = adjLists[src];
        adjLists[src] = newNode;
    }

    void DFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
        cout << "Parcours en profondeur à partir du sommet " << start << " :" << endl;
        DFSUtil(start, visited);
        cout << endl;
        delete[] visited;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 2);
    g.DFS(0);
    return 0;
}