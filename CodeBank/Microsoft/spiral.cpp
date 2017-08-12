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

int getel(int N, int R, int C)
{
	if(R != 1 && C != 1 && R != (N) && C!= (N))
		return getel(N-2,R-1,C-1);
	else
	{
		if(R==1)
			return N*N+1-C;
		else if (C==1)
		{
			return N*N - N -(N-1) - (N-2) - (N-R);
		}
		else if (R==N)
		{
			return N*N - N - (N-1) - (N-2) + (C-1);
		}
		else
			return N*N - N - R-2;
	}
}

int main()
{
	int N = 5 , R = 4, C = 1;
	if(N%2==0)
	{
		C = N-C+1;
		R = N-R+1;
	}
	printf("%d\n", getel(N,4,1));
	printf("%d\n", getel(N,4,2));
	printf("%d\n", getel(N,4,3));
	printf("%d\n", getel(N,4,4));
	printf("%d\n", getel(N,5,1));
	return 0;
}