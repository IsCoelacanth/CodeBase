#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
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

int part(vint V,int l , int h)
{
	int p = l,r=h,x=V[r],i=p-1;
	for (int j = p; j < r-1; ++j)
	{
		if(V[j] <= x)
		{
			i++;
			swap(V[i],V[j]);
		}
	}
	swap(V[i+1],V[r]);
	return i+1;
}

int select(vint V, int l, int r, int k)
{
	for(;;)
	{
		int pin = part(V,l,r);
		int len = pin-l+1;
		if(k==len)
			return pin;
		else if(k < len)
			r = pin-1;
		else
		{
			k = k-len;
			l = pin+1;
		}
	}
}

int main()
{
	int n;
	vint V;
	printf("Enter size of array : \n");
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		scanf("%d",&tmp);
		V.push_back(tmp);
	}

	int medOrder = n/2;
	if(n%2==0)
	{
		int med_1 = select(V,1,n,medOrder);
		printf("Median = %f\n", (float)(V[med_1]+V[med_1-1])/2 );
	}
	else
		printf("Median = %d\n", V[select(V,1,n,medOrder)]);
	return 0;
}