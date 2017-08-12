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
	int x;
	int y;
	Node *next;
};

Node *NewNode(int a, int b)
{
	Node *t = new Node();
	t->x = a;
	t->y = b;
	t->next = NULL;
}

Node *insert(Node *thead, int x,int y)
{
	if(thead == NULL)
	{
		thead = NewNode(x,y);
		return thead;
	}
	Node *tmp = NewNode(x,y);
	tmp->next = thead;
	thead = tmp;
	return tmp;
}

void deleteN(Node *thead, Node *target)
{
	thead->next = target->next;
	target->next = NULL;
	delete(target);
}

Node *deleteMid(Node *thead)
{
	if(thead == NULL || thead->next == NULL || thead->next->next == NULL)
	{
		return thead;
	}
	Node *nxt = thead->next;
	Node *nnxxtt = nxt->next;

	if (thead->x == nxt->x)	
	{
		while(nnxxtt != NULL && nxt->x == nnxxtt->x)
		{
			deleteN(thead,nxt);
			nxt = nnxxtt;
			nnxxtt = nnxxtt->next;
		}
	}
	else if (thead->y == nxt->y)	
	{
		while(nnxxtt != NULL && nxt->y == nnxxtt->y)
		{
			deleteN(thead,nxt);
			nxt = nnxxtt;
			nnxxtt = nnxxtt->next;
		}
	}
	else
		return NULL;
	deleteMid(thead->next);
	return thead;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("(%d,%d)-> ", temp->x,temp->y);
        temp = temp->next;
    }
    printf("\n");
 
}

int main()
{
	Node *root = NULL;
	root = insert(root, 40,5);
    root = insert(root, 20,5);
    root = insert(root, 10,5);
    root = insert(root, 10,8);
    root = insert(root, 10,10);
    root = insert(root, 3,10);
    root = insert(root, 1,10);
    root = insert(root, 0,10);
    printf("LL = \n");
    printList(root);
    root = deleteMid(root);
    if(root!=NULL)
    {
    	printf("List is now\n");
    	printList(root);

    }
	return 0;
}