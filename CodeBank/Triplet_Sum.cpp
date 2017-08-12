#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
#define MOD 1000000007

int triplets(vint a, int sum)
{
	int ans = 0;
	sort(a.begin(),a.end());
	int n = a.size();

	for (int i = 0; i < n-2; ++i)
	{
		int j = i+1 , k = n-1;
		while(j<k)
		{
			if(a[i]+a[j]+a[k] >= sum)
				k--;
			else
			{
				ans += (k-j);
				j++;
			}
		}
	}
	return ans;
}


int main()
{
	printf("Enter size of array\n");
	int n;
	scanf("%d",&n);
	vint A(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	printf("Enter sum\n");
	int sum;
	scanf("%d",&sum);
	printf("The array has : %d triplets\n", triplets(A,sum));

	return 0;
}