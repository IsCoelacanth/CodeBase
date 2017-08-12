#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int i;
	cin>>n;
	for ( i = 1<<31; i > 0; i = i/2)
	{
		(n&i)?printf("1"):printf("0");
	}
}