#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef pair<int,int> pint;
#define MOD 1000000007

class Graph
{
	int V;
	vector<pair<int, int> > *adj;
public:
	Graph(int V)
	{
		this->V = V;
		adj = new vector<pint> [V];
	}

	void add_dir_edge(int u, int v, int w)
	{
		adj[v].push_back(make_pair(v,w));
	}

	void add_undir_edge(int u, int v, int w)
	{
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	// void BFS(int s);
	// void DFS(int v, bool *visit);
	// void DFSutil(int v);	
	void Dijkstra(int s);
};

void Graph::Dijkstra(int s)
{
	priority_queue<pint, vector<pint> , greater<pint> > PQ;
	vll dist(V,INT_MAX);

	PQ.push(make_pair(0,s));
	dist[s] = 0;

	while(!PQ.empty())
	{
		int u = PQ.top().second;
		PQ.pop();
		for(int i = 0 ; i<adj[u].size();i++)
		{
			int v = adj[u][i].first;
			int weight = adj[u][i].second;
			if(dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u]+weight;
				PQ.push(make_pair(dist[v],v));
			}
		}
	}

	printf("Dist of vetex from source : \n");
	for(int i = 0 ; i < V ; i++)
		printf("%d \t\t %lld\n", i , dist[i]);
}



int main()
{
	Graph g(9);
    g.add_undir_edge(0, 1, 4);
    g.add_undir_edge(0, 7, 8);
    g.add_undir_edge(1, 2, 8);
    g.add_undir_edge(1, 7, 11);
    g.add_undir_edge(2, 3, 7);
    g.add_undir_edge(2, 8, 2);
    g.add_undir_edge(2, 5, 4);
    g.add_undir_edge(3, 4, 9);
    g.add_undir_edge(3, 5, 14);
    g.add_undir_edge(4, 5, 10);
    g.add_undir_edge(5, 6, 2);
    g.add_undir_edge(6, 7, 1);
    g.add_undir_edge(6, 8, 6);
    g.add_undir_edge(7, 8, 7);
 
    g.Dijkstra(0);
	return 0;
}