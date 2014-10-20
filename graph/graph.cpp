#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V; // no. of vertices 
	list<int> *adj; // Pointer to an array containing adjacency lists 
  
  public:
	Graph(int V); // Constructer
	void addEdge(int v, int w); // function to add an edge to a graph
	void BFS(int s); // prints BFS traversal from a given source s 
 
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];

}

void Graph::addEdge(int v, int w)
{

	adj[v].push_back(w); // add  w to v's List 
}

void Graph::BFS(int s)
{
	// Mark all veertices as not visited 
	bool *visited = new bool[V];
	for (int i = 0; i <V ;i++)
		visited[i] = false;

	//create a queue for BFS
	list<int> queue;

	//mark the current node visited and enqueue it 
	visited[s]= true;
	queue.push_back(s);

	list<int>::iterator i;
	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		// Get all the adjacent vertices of the dequeued vertex s 
		// If a adjacent has not been visited, then mark it visited 
		// and enqueue it
		for (i =adj[s].begin(); i!= adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}

	}	


}

int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	
	cout<< "Following the BFS search "<<endl;

	g.BFS(2);

	return 0;
}
