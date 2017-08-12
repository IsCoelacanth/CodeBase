#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
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

bool RootToLeafSum(Node *root, int sum)
{
	if(root == NULL)
		return (sum == 0);
	else
	{
		bool ans = false;
		int tsum = sum - root->val;
		if(tsum == 0 && root->left == NULL && root->right == NULL)
			return true;

		if(root->left)
			ans = ans || RootToLeafSum(root->left,tsum);
		if(root->right)
			ans = ans || RootToLeafSum(root->right,tsum);
		return ans;
	}
}

void RootSumPath(Node *root, int sum, int tsum,vll &paths, vvll &path)
{
	if(root == NULL)
		return;
	tsum += root->val;
	paths.push_back(root->val);
	if(tsum == sum)
	{
		path.push_back(paths);
	}

	if(root->left)
		RootSumPath(root->left,sum,tsum,paths,path);
	if(root->right)
		RootSumPath(root->right,sum,tsum,paths,path);
	paths.pop_back();
}

void printpath(vvll &path)
{
	for(int i = 0; i < path.size(); i++)
	{
		for(int j = 0 ; j < path[i].size();j++)
			printf("%lld", path[i][j]);
		printf("\n");
	}
}

int main()
{
	Node *root = NULL;
	printf("Enter the tree size : \n");
	int s;	
	// vll numbers;
	cin>>s;
	for (int i = 0; i < s; ++i)
	{
		int tmp;
		cin>>tmp;
		root = insert(root,tmp);
	}
	// sort(numbers.begin(),numbers.end());
	// root = make_tree(root,numbers,0,s);
	if(RootToLeafSum(root,17))
		printf("yes\n");
	vvll ans;
	vll path;
	RootSumPath(root,17,0,path,ans);
	printpath(ans);
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