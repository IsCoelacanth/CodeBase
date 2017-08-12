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



int getlevel(Node *troot,int data, int lvl)
{
	if(troot == NULL)
		return 0;
	if(troot->val == data)
		return lvl;
	int dlvl = getlevel(troot->left,data,lvl+1)
	if(dlvl != 0)
		return dlvl;
	dlvl = getlevel(troot->right,data,lvl+1)
	return dlvl;
}

int level(Node *troot,int val)
{
	return getlevel(troot,val,1);
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

int search(vint arr, int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            break;
    }
    return i;
}

Node *build(vint in, vint post, int instr,int inend, int *pin)
{
	if(instr>inend)
		return NULL;
	Node *Node = new_node(post[*pin]);
	(*pin)--;

	if(instr == inend)
		return node;

	int iInd = search(in,instr,inend,node->val);

	node->right = build(in,post,iInd+1,inend,pin);
	node->left = build(in,post,instr,iInd-1,pin);
	return node;
}

Node *buildTree(vint in,vint post,int K)
{
	int pin = K-1;
	buildTree(in,post,0,n-1,&pin);
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
	// printf("Enter the array size : \n");
	// int s;	
	// vll numbers;
	// cin>>s;
	// for (int i = 0; i < s; ++i)
	// {
	// 	int tmp;
	// 	cin>>tmp;
	// 	numbers.push_back(tmp);
	// }
	// sort(numbers.begin(),numbers.end());
	// root = make_tree(root,numbers,0,s);
	// printf("Enter numbers to find LCA\n");
	// int n,m;
	// cin>>n>>m;
	// Node *lca = LCA(root,n,m);
	// printf("LCA OF %d and %d is %d\n", n,m,lca->val);
	// root2 = make_tree(root2,numbers,s/2+1,s);
	// printf("Height = %d\n",min(height(root1),height(root2)));
	// if(checkBalance(root)){
	// 	printf("balanced\n");
	// }

	return 0;
}