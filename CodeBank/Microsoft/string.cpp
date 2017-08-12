#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<vector<ll> > vvll;
typedef pair<int,int> pint;
typedef map<int,int> mint;
#define MOD 1000000007

void TheReverser(string &str, int i ,int j)
{
	reverse(str.begin(), (str.begin()+i+1));
	cout<<"rev 0,i \n"<<str<<endl;
	reverse(str.begin()+j, str.end());
	cout<<"rev j,N \n"<<str<<endl;
	reverse(str.begin()+i+1, str.begin()+j);
	cout<<"rev i+1,j-1\n"<<str<<endl;
	reverse(str.begin(), str.end());
}


int main()
{
	string s;
	cin>>s;
	int i,j;
	cin>>i>>j;
	TheReverser(s,i,j);
	cout<<s<<endl;
	return 0;
}