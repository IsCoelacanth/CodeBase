#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
#define MOD 1000000007

int trailzero(int N)
{
	int count = 0;
	for(int i =5 ; N/i >= 1; i *= 5)
		count += N/i;
	return count;
}

int main()
{
	printf("Enter Number\n");
	int N;
	cin>>N;
	printf("%d has %d trailing zeros\n", N,trailzero(N));

	return 0;
}