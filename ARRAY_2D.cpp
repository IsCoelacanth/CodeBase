#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > performOps(vector<vector<int> > &A) {
    vector<vector<int> > B;
    B.resize(A.size());
    for (int i = 0; i < A.size(); i++) {
        B[i].resize(A[i].size());
        for (int j = 0; j < A[i].size(); j++) {
            B[i][A[i].size() - 1 - j] = A[i][j];
        }
    }
    return B;
}

int main() {
	vector<vector<int> > A;

	int f[4] = {1,2,3,4};
	int s[4] = {5,6,7,8};
	int t[4] = {9,10,11,12};

	vector<int> first(f, f + sizeof f / sizeof f[0]);
	vector<int> second(s, s + sizeof s / sizeof s[0]);
	vector<int> third(t, t + sizeof t / sizeof t[0]);

	A.push_back(first);
	A.push_back(second);
	A.push_back(third);

	// for (int i = 0; i < A.size(); i++) {
 	// for (int j = 0; j < A[i].size(); j++) cout<<A[i][j]<<" ";
	// }


	vector<vector<int> > B = performOps(A);
	for (int i = 0; i < B.size(); i++) {
    	for (int j = 0; j < B[i].size(); j++) cout<<B[i][j]<<" ";
	}
	return 0;
}