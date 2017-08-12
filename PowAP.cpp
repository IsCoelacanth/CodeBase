#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
#define MOD 1000000007

bool expressApowP(int A)
{
	for(int i = 2 ; i < sqrt(A) ; i++)
	{
		for(int j = 2; j < 32 ; j++)
			if(pow(i,j)==A)
				return true;
	}
	return false;
}

int main()
{
	int A;
	printf("Enter a number\n");
	cin>>A;
	if(expressApowP(A))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}