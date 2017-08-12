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

void Union(vint &A, vint &B, vint &C)
{
	if(A.size() > B.size())
	{
		C = B;
		sort(B.begin(),B.end());
		for (int i = 0; i < A.size(); ++i)
		{
			if(binary_search(B.begin(),B.end(),A[i]))
				continue;
			else
				C.push_back(A[i]);
		}
	}
	else
	{
		C = A;
		sort(A.begin(),A.end());
		for (int i = 0; i < B.size(); ++i)
		{
			if(binary_search(A.begin(),A.end(),B[i]))
				continue;
			else
				C.push_back(B[i]);
		}
	}	
}

void Inter(vint &A, vint &B, vint &C)
{
	if(A.size() > B.size())
	{
		sort(B.begin(),B.end());
		for (int i = 0; i < A.size(); ++i)
			if(binary_search(B.begin(),B.end(),A[i]))
				C.push_back(A[i]);
	}
	else
	{
		sort(A.begin(),A.end());
		for (int i = 0; i < B.size(); ++i)
			if(binary_search(A.begin(),A.end(),B[i]))
				C.push_back(B[i]);
		
	}	
}

int main()
{
	vint A;
	vint B;
	int a,b;
	printf("Enter the sizes of the array\n");
	scanf("%d %d",&a,&b);
	for (int i = 0; i < a; ++i)
	{
		int tmp;
		scanf("%d",&tmp);
		A.push_back(tmp);
	}
	for (int i = 0; i < b; ++i)
	{
		int tmp;
		scanf("%d",&tmp);
		B.push_back(tmp);
	}
	vint inter;
	vint uni;
	Union(A,B,uni);
	Inter(A,B,inter);
	printf("Intersection = \n");
	printvec(inter);
	printf("Union = \n");
	printvec(uni);
	return 0;
}