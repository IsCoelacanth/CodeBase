#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvll;
typedef pair<int,int> pint;
typedef map<int,int> mint;
// typedef unordered_map<int,int> omint;
#define MOD 1000000007




int main()
{
	vvint V;
	int m,n;
	cin>>m>>n;
	for (int i = 0; i < m; ++i)
	{
		vint tmpv;
		for (int j = 0; j < n; ++j)
		{
			int tmp;
			cin>>tmp;
			tmpv.push_back(tmp);
		}
		V.push_back(tmpv);
	}

	mint matcout;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(matcout.find(V[i][j]) == matcout.end())
				matcout[V[i][j]] = 1;
			else
				matcout[V[i][j]]++;
		}
	}
	int count = 0;
	for (map<int,int>::iterator i = matcout.begin(); i != matcout.end(); ++i)
	{
		if(i->second == m)
		{
			count++;
		}
	}
	cout<<count<<'\n';
	return 0;
}