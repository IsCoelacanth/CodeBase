#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef map<int,int> mint;
#define MOD 1000000007


void findNext(char *str, int n)
{
	int i , j;
	for (i = n-1; i >= 0; --i)
	{
		if(str[i] > str[i-1])
			break;
	}

	if(i==0)
	{
		printf("Not possible\n");
		return;
	}

	int x = str[i-1],smallest = i;
	for (j = i+1; j < n; ++j)
		if(str[j] > x && str[j]<str[smallest])
			smallest = j;

	swap(str[smallest],str[i-1]);
	sort(str+i, str+n);
	printf("Next number is %s\n",str);
	return;
}

int main()
{
	char text[128];
	scanf("%s",text);
	findNext(text,strlen(text));
	return 0;
}