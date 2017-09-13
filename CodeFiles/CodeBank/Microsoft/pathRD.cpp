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
#define MAX 100
void printMat(int V[MAX][MAX] , int n , int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%4d ", V[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void paths(int n, int m)
{
	int count[MAX][MAX];

	for (int i = 0; i < n; ++i)
	{
		count[i][0] = 1;
	}

	for (int j = 0; j < m; ++j)
	{
		count[0][j] = 1;
	}
	printMat(count,n,m);
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			count[i][j] = count[i-1][j] + count[i][j-1];
		}
		printMat(count,n,m);
	}
	printf("%d\n", count[n-1][m-1]);
}

int main()
{
	int n,m;
	printf("Enter n and m\n");
	scanf("%d %d",&n,&m);
	paths(n,m);
	return 0;
}