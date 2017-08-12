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

Node* findMinAdd(Node *troot)
{
    if(troot -> left == NULL)
    {
        return troot;
    }
    return findMinAdd(troot->left);
}

Node *Delete(Node *troot, int x)
{
	if(troot == NULL)
		return troot;
	else if(x< troot->val)
		troot->left = Delete(troot->left,x);
	else if(x> troot->val)
		troot->right = Delete(troot->right,x);
	else
	{
		if(troot->left == NULL && troot->right == NULL)
		{
			delete troot;
			troot = NULL;
		}
		else if(troot->left == NULL)
		{
			Node *temp = troot;
			troot = troot->right;
			delete temp;
		}
		else if(troot->right == NULL)
		{
			Node *temp = troot;
			troot = troot->left;
			delete temp;
		}
		else
		{
			Node *temp = findMinAdd(troot->right);
			troot->val = temp->val;
			troot->right = Delete(troot->right,temp->val);
		}
	}
	return troot;

}

void Print_Pre_Order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout<<root -> val <<"  ";
    Print_Pre_Order(root -> left);
    Print_Pre_Order(root -> right);
}

void Print_In_Order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Print_In_Order(root -> left);
    cout<<root -> val <<"  ";
    Print_In_Order(root -> right);
}
 
void Print_Post_Order(Node *root)
{
    if (root == NULL)
        return;
    Print_Post_Order(root -> left);
    Print_Post_Order(root -> right);
    cout<<root -> val <<"  ";
}

int height(Node *troot)
{
	if(troot == NULL)
			return -1;
	return max(height(troot->left),height(troot->right)) + 1;
}

Node *make_tree(Node *root, vll vec, int l, int r)
{
	if(l>r)
		return NULL;
	int mid = l + (r-l)/2;
	root = insert(root, vec[mid]);
	make_tree(root,vec,l,mid-1);
	make_tree(root,vec,mid+1,r);
	return root;
}

bool checkBalance(Node *root)
{
	return (abs(height(root->left)-height(root->right)) < 2 );
}

Node *LCA(Node *root, int n1, int n2)
{
	if(root == NULL)
		return NULL;
	if(root->val == n1 || root->val == n2)
		return root;
	Node *l = LCA(root->left,n1,n2);
	Node *r = LCA(root->right,n1,n2);
	if(l != NULL && r != NULL)
		return root;
	return l != NULL ? l:r;
}

void printSpiralIter(Node *root)
{
	if(root == NULL)
			return;
	stack<Node *> s1;
	stack<Node *> s2;
	s1.push(root);

	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			Node *temp = s1.top();
			s1.pop();
			cout<<temp->val<<' ';
			if(temp->left)
			s2.push(temp->left);
			if(temp->right)
			s2.push(temp->right);
		}
		while(!s2.empty())
		{
			Node *temp = s2.top();
			s2.pop();
			cout<<temp->val<<' ';
			if(temp->left)
			s1.push(temp->left);
			if(temp->right)
			s1.push(temp->right);
		}
	}
}

int diameter(Node *troot, int *Height)
{
	int lh = 0, rh = 0;
	if(troot == NULL)
	{
		*Height = 0;
		return 0;
	}
	int ldia = diameter(troot->left, &lh);
	int rdia = diameter(troot->right, &rh);

	*Height = max(lh,rh)+1;
	return max((lh+rh+1), max(ldia,rdia));
}

int minHeight(Node *troot)
{
	if(troot == NULL)
			return -1;
	return min(height(troot->left),height(troot->right)) + 1;
}

int search(vint arr, int strt, int en, int value)
{
    int i;
    for (i = strt; i <= en; i++)
    {
        if (arr[i] == value)
            break;
    }
    return i;
}

Node* build(vint in, vint post, int inStrt, int inEnd, int *pIndex)
{
    if (inStrt > inEnd)
        return NULL;
    Node *node = new_node(post[*pIndex]);
    (*pIndex)--;
    if (inStrt == inEnd)
        return node;
    int iIndex = search(in, inStrt, inEnd, node->val);
    node->right= build(in, post, iIndex+1, inEnd, pIndex);
    node->left = build(in, post, inStrt, iIndex-1, pIndex);
 
    return node;
}

Node *buildTree(vint in,vint post,int K)
{
	int pin = K-1;
	build(in,post,0,K-1,&pin);
}

int main()
{
	Node *root = NULL;
	vint in;
	vint post;
	int N;
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin>>tmp;
		in.push_back(tmp);
	}
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin>>tmp;
		post.push_back(tmp);
	}
	root = buildTree(in,post,N);
	Print_In_Order(root);
}