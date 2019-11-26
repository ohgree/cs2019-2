#include <iostream>
#include <list>
#define NIL -1
using namespace std;

class Graph {

private:
  int V;
  list<int> *adj;
  void APUtil(int v, bool visited[], int disc[], int post[], int low[], int parent[], bool ap[]);

public:
  Graph(int V); 
  void addEdge(int v, int w);
  void AP();
  void Print();
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
  adj[w].push_back(v);
}

// u: the vertex to be visited next
void Graph::APUtil(int u, bool visited[], int disc[], int post[], int low[], int parent[], bool ap[]) {
  static int time = 0;

  int children = 0;

  printf("visiting node [%2d]...\n", u);

  // mark the node as visited
  visited[u] = true;

  // record discovery time and the 'low' value
  disc[u] = low[u] = ++time;
  printf("disc[%2d] becomes %2d\n", u, disc[u]);
  printf(" low[%2d] becomes %2d\n", u, low[u]);

  // go through all vertices adjacent to this node
  list<int>::iterator i;
  for(i = adj[u].begin(); i != adj[u].end(); ++i) {
    int v = *i;

    printf("checking [%2d]'s neighbor [%2d]...\n", u, v);

    // if v is not visited yet, then make it a child of u and visit the node
    if(!visited[v]) {
      children++;
      parent[v] = u;
      APUtil(v, visited, disc, post, low, parent, ap);

      // check if the subtree rooted with v has a connection to one of the ancestors of u
      low[u] = min(low[u], low[v]);
      printf("low[%2d] becomes %2d\n", u, low[u]);

      // u is an articulation point in the following cases.
     
      // (1) u is root of the DFS tree and has two or more children
      if(parent[u] == NIL && children > 1) ap[u] = true;
 
      // (2) if u is not the root and low value of one of its children is larger than discovery value of u.
      if(parent[u] != NIL && low[v] >= disc[u]) ap[u] = true;
    }

    // update low value of u for parent function calls.
    else if(v != parent[u]) {
      low[u] = min(low[u], disc[v]);
      printf(" low[%2d] becomes %2d\n", u, low[u]);
    }
  }

  post[u] = ++time;
  printf("post[%2d] becomes %2d\n", u, post[u]);
  printf("exiting node [%2d]...\n", u);
  
}

void Graph::AP() {
 
  // create and initialize data structure for finding articulation points
  bool *visited = new bool[V];
  int *disc = new int[V];
  int *post = new int[V];
  int *low = new int[V];
  int *parent = new int[V];
  bool *ap = new bool[V];

  // initialize parent and visited, and ap(articulation point) arrays
  for(int i=0; i<V; i++) {
    parent[i] = NIL;
    visited[i] = false;
    ap[i] = false;
  }

  // call the recursive helper function to find articulation points in DFS tree rooted at vertex 'i'
  for(int i=0; i<V; i++) {
    if(visited[i] == false) {
      APUtil(i, visited, disc, post, low, parent, ap);
    }
  }

  // print graph information
  printf(" v     parent     entry_time  exit_time     low  \n");
  printf("-------------------------------------------------\n");
  for(int i=0; i<V; i++) {
    printf("%2d      %2d            %2d          %2d         %2d  \n", i, parent[i], disc[i], post[i], low[i]);
  }
  printf("\n");

  // print articulation points
  printf("articulation points: ");
  for(int i=0; i<V; i++) {
    if(ap[i] == true) printf("%d ", i);
  }
  printf("\n");
}


int main(int argc, char *argv[]) {

  /*
  Graph g1(5);
  g1.addEdge(1, 0);
  g1.addEdge(0, 2);
  g1.addEdge(2, 1);
  g1.addEdge(0, 3);
  g1.addEdge(3, 4);
  g1.AP();
  */

  Graph g2(13);
  g2.addEdge(0, 1);
  g2.addEdge(0, 2);
  g2.addEdge(0, 5);
  g2.addEdge(0, 6);
  g2.addEdge(2, 6);
  g2.addEdge(3, 4);
  g2.addEdge(3, 5);
  g2.addEdge(4, 5);
  g2.addEdge(4, 6);
  g2.addEdge(6, 7);
  g2.addEdge(6, 9);
  g2.addEdge(7, 8);
  g2.addEdge(9, 10);
  g2.addEdge(9, 11);
  g2.addEdge(9, 12);
  g2.addEdge(11, 12);
  g2.AP();
}






