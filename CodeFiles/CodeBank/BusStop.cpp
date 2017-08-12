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


int main()
{
	vector<pint> event;
	int Bus;
	printf("Enter the number of busses\n");
	scanf("%d",&Bus);
	printf("Enter arrivals\n");
	for (int i = 0; i < Bus; ++i)
	{
		int tmp;
		scanf("%d",&tmp);
		event.push_back(make_pair(tmp,0));
	}
	for (int i = 0; i < Bus; ++i)
	{
		int tmp;
		scanf("%d",&tmp);
		event.push_back(make_pair(tmp,1));
	}
	int maxStands = 0;
	int stat = 0;
	sort(event.begin(), event.end());
	for (int i = 0; i < event.size(); ++i)
	{
		if(event[i].second == 0)
		{
			stat++;
			maxStands = max(maxStands,stat);
		}
		else
		{
			stat--;
			maxStands = max(maxStands,stat);
		}
	}
	printf("Max stands needed = %d\n", maxStands);
	return 0;
}