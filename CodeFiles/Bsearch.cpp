#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
#define MOD 1000000007

void printa(vector<int> a)
{
	printf("index\n");	
	for(int i = 0 ; i < a.size();i++)
		printf("%4d ", i);
	printf("\n");
	for(int i = 0 ; i < a.size();i++)
		printf("%4d ", a[i]);
	printf("\n");
}

int main()
{
	vector<int>::iterator low,up;
	vector<int> a(10);
	printf("Enter array\n");
	for(int i = 0 ; i <10 ; i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	int n;
	printf("Enter number\n");
	cin>>n;
	printf("Sorted array\n");
	printa(a);
	low = lower_bound(a.begin(),a.end(),n);
	up = upper_bound(a.begin(),a.end(),n);
	printf("Lower bound at %4d\n", (int)(low-a.begin()));
	printf("upper bound at %4d\n", (int)(up-a.begin()));
	printf("Count of number %4d\n", (int)(up-low));
	return 0;
}