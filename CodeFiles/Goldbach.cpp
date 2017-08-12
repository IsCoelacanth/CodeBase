#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int,int> > vecpair;
typedef pair<int,int> pr;

bool prime[10000007];

void makeseive(int N)
{
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=N; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=N; i += p)
                prime[i] = false;
        }
    }
}

pr goldbach(int N)
{
	makeseive(N);
	pr res;
	for(int i = 2 ; i < N ; i++)
	{
		if(prime[i])
		{
			if(prime[N-i])
			{
				res = (make_pair(i,(N-i)));
				return res;
			}
		}
	}
	return res;
}

int main()
{
	int N;
	printf("Enter a number\n");
	cin>>N;
	pr r = goldbach(N);
	printf("%d,%d\n", r.first,r.second );
}