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

void printvec(vll A)
{
	for (int i = 0; i < A.size(); ++i)
	{
		printf("%lld ", A[i]);
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

void vecin(vll &A,ll N)
{
	ll tmp;
	for (ll i = 0; i < N; ++i)
	{
		cin>>tmp;
		A.push_back(tmp);
	}
}

int main()
{
	return 0;
}