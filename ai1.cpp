#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	vector<list<int> > adj;

public:
	Graph(int V); 
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::BFS(int s)
{
	vector<bool> visited;
	visited.resize(V, false);

	list<int> queue;
	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty()) {
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (auto adjacent : adj[s]) {
			if (!visited[adjacent]) {
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}

class Graphdfs {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	void addEdge(int v, int w);

	void DFS(int v);
};

void Graphdfs::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graphdfs::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}


int main(){
    cout<<"1. BFS"<<endl;
    cout<<"2. DFS"<<endl;
    cout<<"3. EXIT"<<endl;
    int x;
    cin>>x;
    while(x!=3){
        	if(x==1){
				int v,e;
				cout<<"Enter the Number of Vertices"<<endl;
				cin>>v;
				cout<<"Enter the Number of Edges"<<endl;
				cin>>e;

				Graph g(v);
				for(int i=0;i<e;i++){
					int n,m;
					cin>>n>>m;
					g.addEdge(n, m);
				}
	
				cout<<"Enter the Vertex from which Traversal is needed"<<endl;
				int d;
				cin>>d;
				cout << "Following is Breadth First Traversal "
					<< "(starting from vertex "<<d<<") \n";
				g.BFS(d);
				cout<<endl;
			}
        	else if(x==2){
				int vd,ed;
	
    			cout<<"Enter the Number of Vertices"<<endl;
    			cin>>vd;
    
    			cout<<"Enter the Number of Edges"<<endl;
    			cin>>ed;

				Graphdfs gd;
    			for(int i=0;i<ed;i++){
        			int nd,md;
        			cin>>nd>>md;
        			gd.addEdge(nd,md);
    			}

    			cout<<"Enter Node from which Traversal is Required"<<endl;
    			int dd;
    			cin>>dd;

				cout << "Following is Depth First Traversal"
						" (Starting From Vertex"<<dd<<")"<<endl;

				gd.DFS(dd);
				cout<<endl;
        	}
        	else{
            	cout<<"Wrong Choice"<<endl;
        	}

        cout<<"1. BFS"<<endl;
        cout<<"2. DFS"<<endl;
        cout<<"3. EXIT"<<endl;
        cin>>x;
    }
	return 0;
}

// For BSF
// Graph g(4);
//     g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 2);
//     g.addEdge(2, 0);
//     g.addEdge(2, 3);
//     g.addEdge(3, 3);

// For DFS
// 	   g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 2);
//     g.addEdge(2, 0);
//     g.addEdge(2, 3);
//     g.addEdge(3, 3);