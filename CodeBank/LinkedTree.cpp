#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
#define MOD 1000000007

struct Node
{
	int val;
	Node *left, *right, *LinkRight;
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

void linkinNodes(Node *root)
{
	if(root== NULL)
			return;
	queue<pair<Node *,int> > Q;
	Q.push(make_pair(root,0));
	root->LinkRight = NULL;
	while(!Q.empty())
	{
		pair<Node *,int> P = Q.front();
		if(P.first->left!=NULL)
			Q.push(make_pair(P.first->left,P.second+1));
		if(P.first->right!=NULL)
			Q.push(make_pair(P.first->right,P.second+1));
		Q.pop();
		if(P.second == Q.front().second)
			P.first->LinkRight = Q.front().first;
		else
			P.first->LinkRight = NULL;
	}
}

void Print_Level_Order(Node* root)
{
    if (root ==  NULL)
        return;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node *curr = Q.front();
        cout<< curr -> val;
        if(curr->LinkRight != NULL)
        	cout<<" And Right = "<<curr->LinkRight->val<<'\n';
        if (curr -> left != NULL)
            Q.push(curr->left);
        if(curr -> right != NULL)
            Q.push(curr->right);
        Q.pop();
        if(Q.front()->LinkRight == NULL)
	        printf("\n");
    }
    cout<<endl;
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
// void SendNudes(Node *root)
// {
// 	//Adds 80085 to all nodes;
// 	if(root == NULL)
// 		return;
// 	root->val+=80085;
// 	SendNudes(root->left);
// 	SendNudes(root->right);
// }

int main()
{
	Node *root = NULL;
	printf("Enter the array size : \n");
	int s;	
	vll numbers;
	cin>>s;
	for (int i = 0; i < s; ++i)
	{
		int tmp;
		cin>>tmp;
		numbers.push_back(tmp);
	}
	sort(numbers.begin(),numbers.end());
	root = make_tree(root,numbers,0,s);
	linkinNodes(root);
	Print_Level_Order(root);
	// root2 = make_tree(root2,numbers,s/2+1,s);
	// printf("Height = %d\n",min(height(root1),height(root2)));

	return 0;
}