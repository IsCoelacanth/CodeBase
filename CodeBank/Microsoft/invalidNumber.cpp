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

void bubbleOutZeros(vint &V)
{
	int p = 0;
	for(int i = 0 ; i < V.size() ; i++)
	{
		if(V[i] == 0)
		{
			p = i;
			while(V[i] == 0 && i < V.size())
				i++;
			swap(V[p],V[i]);
			i = p;
		}
	}
}

int main()
{
	vint V;
	printf("Enter size of array\n");
	int N;
	scanf("%d",&N);
	vecin(V,N);
	int i = 0;
	int p;
	while(V[i] == 0)
		i++;
	p = i;
	bool zflag = false;
	for (i ; i < N; ++i)
	{
		if(V[i] == 0)
		{
			zflag = true;
			p = i-1;
			while(V[i]==0)
				i++;
			if(V[p] == V[i])
			{
				V[p] *= 2;
				V[i] = 0;
			}
		}
		else if(zflag)
		{
			if(V[p] == V[i])
			{
				V[p] *= 2;
				V[i] = 0;
			}
			else
				zflag = false;
		}
	}
	bubbleOutZeros(V);
	printvec(V);
	return 0;
}