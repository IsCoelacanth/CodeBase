#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
#define MOD 1000000007

ll hamDist(vll A)
{
	ll ans = 0;
	for(int i = 0 ; i < 32 ; i++)
	{
		ll count = 0;
		for(int j = 0 ; j < A.size() ; j++)
			if(A[j] & (1<<i))
				count++;
		ans = (ans+(count*(A.size()-count)*2))%MOD;
	}
	return ans;
}

int main()
{

	int N;
	printf("Enter the number of digits\n");
	cin>>N;
	vll arr;
	for(int i = 0 ; i < N ; i++)
	{
		int t;
		cin>>t;
		arr.push_back(t);
	}
	printf("Ans = %lld\n", hamDist(arr));
}