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

bool ninecheck(vint V)
{
	for (int i = 0; i < V.size(); ++i)
	{
		if(V[i] != 9)
			return false;
	}
	return true;
}

void gennextpal(vint &V)
{
	int n = V.size();
	int mid = n/2;
	bool left = false;
	int i = mid - 1;
	int j = (n%2)? mid+1:mid;
	while( i >= 0 && V[i] == V[j])
		i--,j++;
	if(i<0 || V[i] < V[j])
		left = true;
	while( i >= 0)
	{
		V[j] = V[i];
		j++;
		i--;
	}

	if(left)
	{
		int carry = 1;
		i = mid - 1;

		if(n%2 == 1)
		{
			V[mid] += carry;
			carry = V[mid]/10;
			V[mid] %= 10;
			j = mid+1;
		}
		else
			j = mid;
		while( i >= 0)
		{
			V[i] += carry;
			carry = V[i]/10;
			V[i] %= 10;
			V[j++] = V[i--];
		}
	}
}

void nextpal(vint &V)
{
	if(ninecheck(V))
	{
		printf("1");
		for (int i = 0; i < V.size(); ++i)
		{
			printf("0");
		}
		printf("1\n");
	}
	else
	{
		gennextpal(V);
		printvec(V);
	}
}

int main()
{
	vint pal;
	vecin(pal,10);
	nextpal(pal);
	return 0;
}