#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	unsigned int i;
	printf("Enter a number\n");
	cin>>n;
	for ( i = 1<<31; i > 0; i = i/2)
	{
		// printf("%d\n", i);
		if(n & i)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}
