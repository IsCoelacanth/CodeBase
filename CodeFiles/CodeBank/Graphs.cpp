#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
#define MOD 1000000007

class Graph
{
	int V;
	int E;
	vll *adj;
public:
	Graph(int V)
	{
		this->V = V;
		E = 0;
		adj = new vll[V];
	}
	void add_dir_edge(int v, int w)
	{
		adj[v].push_back(w);
	}
	void add_undir_edge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
	}
	void BFS(int s);
	void DFS(int v, bool *visit);
	void DFSutil(int v);	
};

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	memset(visited,0,sizeof(visited));

	queue<int> Q;
	visited[s] = true;
	Q.push(s);
	while(!Q.empty())
	{
		s = Q.front();
		cout<<s<<' ';
		Q.pop();
		for(int i = 0 ; i< adj[s].size() ; i++)
		{
			if(!visited[adj[s][i]])
			{
				visited[adj[s][i]]=true;
				Q.push(adj[s][i]);
			}
		}
	}
}

void Graph::DFS(int v, bool *visit)
{
	visit[v] = true;
	cout << v << ' ';
	for(int i = 0 ; i < adj[v].size() ; i++)
	{
		if(!visit[adj[v][i]])
			DFS(adj[v][i],visit);
	}
}

void Graph::DFSutil(int v)
{
	bool visit[V];
	memset(visit,0,sizeof(visit));
	for(int i = 0 ; i < V ; i++)
		if(visit[i] == false)
			DFS(v,visit);
}

int main()
{
	Graph g(4);
    g.add_dir_edge(0, 1);
    g.add_dir_edge(0, 2);
    g.add_dir_edge(1, 2);
    g.add_dir_edge(2, 0);
    g.add_dir_edge(2, 3);
    g.add_dir_edge(3, 3);

    printf("BFS = \n");
    g.BFS(0);
    printf("\n");
    printf("DFS = \n");
    g.DFSutil(2);
    printf("\n");
	return 0;
}