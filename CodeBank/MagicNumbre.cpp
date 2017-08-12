#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef map<int,int> mint;
#define MOD 1000000007

int main()
{
	printf("Enter the Nth magic number required\n");
	int n;
	scanf("%d",&n);
	int k = n;
	int pow_of_two = 1;
	int ans = 0;
	while(n)
	{
		pow_of_two *= 5;
		if(n&1)
			ans += pow_of_two;
		n >>= 1;
	}
	printf("%dth magic number is %d\n",  k,ans);
	return 0;
}


