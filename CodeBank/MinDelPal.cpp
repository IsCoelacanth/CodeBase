#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef map<int,int> mint;
#define MOD 1000000007

int lps(string str)
{
	int n = str.length();
	int i,j,cl;
	int L[n][n];
	for (i = 0; i < n; ++i)
	{
		L[i][i] = 1;
	}

	for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
	return L[0][n-1];
}

int minDelete(string S)
{
	int pal = lps(S);
	return S.length()-pal;
}

int main()
{
	string S;
	getline(cin,S);
	cout<<"minimum deletes = "<<minDelete(S);
	return 0;
}