#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
#define MOD 1000000007

struct Node
{
	int val;
	Node *left, *right;
};

Node *new_node(int x)
{
	Node *nnode = new Node();
	nnode->val = x;
	nnode->left = NULL;
	nnode->right = NULL;
	return nnode;
}

Node *insert(Node *troot, int x)
{
	if(troot == NULL)
		troot = new_node(x);
	else if(x <= troot->val)
		troot->left = insert(troot->left,x);
	else if(x > troot->val)
		troot->right = insert(troot->right,x);
	return troot;
}

int level(Node *root, Node *node, int lvl)
{
    if (root == NULL)
        return 0;
    if (root == node)
        return lvl;
    int downlevel = level(root->left, node, lvl+1);
    if (downlevel != 0)
        return downlevel;
    return level(root->right, node, lvl+1);
}

void printlvl(Node *troot, Node *n,int lvl)
{
	if(troot == NULL || lvl < 2)
		return;
	if(lvl == 2)
	{
		if(troot->left == n || troot->right == n)
			return;
		if(troot->left)
			printf("%d\n", troot->left->val);
		if(troot->right)
			printf("%d\n", troot->right->val);
	}
	else if(lvl >2)
	{
		printlvl(troot->left, n,lvl-1);
		printlvl(troot->right, n, lvl-1);
	}
}

void printCousin(Node *troot, Node *n)
{
	int lvl = level(troot,n,1);
	printlvl(troot,n,lvl);
}

int main()
{
	Node *root = NULL;
	root = insert(root,1);
    root = insert(root,2);
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,15);
    root = insert(root,6);
    root = insert(root,7);
    root = insert(root,8);
 
    printCousin(root, root->left->right);
	return 0;
}