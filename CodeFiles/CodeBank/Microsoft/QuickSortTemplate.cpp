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

template <class T>
T partition( T arr[], int start, int end)
{
	T i = start+1;
	T piv = arr[start];

	for(int j = start+1; j <= end;j++)
	{
		if(arr[j] < piv)
		{
			swap(arr[i],arr[j]);
			i++;
		}
	}
	swap(arr[start],arr[i-1]);
	return i-1;
}

template <class T>
T qsort( T arr[], int s, int e)
{
	if(s<e)
	{
		int p = partition(arr,s,e);
		qsort(arr,s,p-1);
		qsort(arr,p+1,e);
	}
}

int main()
{
	int a[] = {4,2,5,61,1,6,123,65};
	qsort(a,0,8);
	for (int i = 0; i < 8; ++i)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}