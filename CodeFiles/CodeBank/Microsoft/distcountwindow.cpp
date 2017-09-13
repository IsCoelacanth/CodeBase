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

void printvec(vint A)
{
	for (int i = 0; i < A.size(); ++i)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

void vecin(vint &A,int N)
{
	int tmp;
	for (int i = 0; i < N; ++i)
	{
		cin>>tmp;
		A.push_back(tmp);
	}
}

void distcount(vint V, int K)
{
	map<int, int> M;
	int dst_cnt = 0;

	for(int i = 0 ; i < K ;i++)
	{
		if(M[V[i]] == 0)
			dst_cnt++;
		M[V[i]]++;
	}
	printf("%d\n", dst_cnt);

	for (int i = K; i < V.size(); ++i)
	{
		if(M[V[i-K]]==1)
			dst_cnt--;
		M[V[i-K]]--;

		if(M[V[i]]==0)
			dst_cnt++;
		M[V[i]]++;
		printf("%d\n", dst_cnt);
	}
}

int main()
{
	vint V;
	int n,k;
	printf("Enter size of array and K\n");
	scanf("%d %d",&n,&k);
	vecin(V,n);
	distcount(V,k);
	return 0;
}