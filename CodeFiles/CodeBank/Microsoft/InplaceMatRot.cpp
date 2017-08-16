#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvll;
typedef pair<int,int> pint;
typedef map<int,int> mint;
#define MOD 1000000007

void printvecvec(vvint V)
{
	for (int i = 0; i < V.size(); ++i)
	{
		for (int j = 0; j < V[i].size(); ++j)
		{
			printf("%d ", V[i][j]);
		}
		printf("\n");
	}
}

void invecvec(vvint &V, int n)
{
	for (int i = 0; i < n; ++i)
	{
		vint Vt;
		for (int j = 0; j < n; ++j)
		{
			int tmp;
			scanf("%d",&tmp);
			Vt.push_back(tmp);
		}
		V.push_back(Vt);
	}
}

void Rotate(vvint &V, int N)
{
	for(int i = 0 ; i < N/2 ; i++)
	{
		for(int j = i; j < N-1-i ; j++)
		{
			int temp = V[i][j];
			V[i][j] = V[j][N-i-1];
			V[j][N-i-1] = V[N-i-1][N-j-1];
			V[N-i-1][N-j-1] = V[N-j-1][i];
			V[N-j-1][i] = temp;
		}
	}
}

int main()
{
	vvint V;
	int n;
	cin>>n;
	invecvec(V,n);
	Rotate(V,n);
	printvecvec(V);
	return 0;
}