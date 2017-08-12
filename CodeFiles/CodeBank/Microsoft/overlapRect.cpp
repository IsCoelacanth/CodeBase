#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> point;

bool overlap(point l1, point l2, point r1, point r2)
{
    if(l1.first > r2.first || l2.first > r1.first)
        return false;
    if(l1.second < r2.second || l2.second < r1.second)
        return false;
    return true;
}

int main()
{
    point l1,l2,r1,r2;
    cout<<"Enter points";
    int x,y;
    cin>>x>>y;
    l1 = make_pair(x,y);
    cin>>x>>y;
    r1 = make_pair(x,y);
    cin>>x>>y;
    l2 = make_pair(x,y);
    cin>>x>>y;
    r2 = make_pair(x,y);
    if(overlap(l1,l2,r1,r2))
        printf("over lap\n");
    else
        printf("no over lap\n");
        return 0;

}
