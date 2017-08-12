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
	Node *next;
};

class LinkedList
{
	Node *root;
public:
	LinkedList(){root = NULL;}
	void push(int x);
	void pushback(int x);
	Node *getnode(int x);
	void print();
	void seggregate();	
};

Node* LinkedList::getnode(int n)
{
	Node *temp = new Node();
	temp->x = n;
	temp->next = NULL;
	return temp;
}

void LinkedList::push(int x)
{
	if(root == NULL)
	{
		root = getnode(x);
	}
	else
	{
		Node *a = getnode(x);
		a->next = root;
		root = a;
	}
}
void LinkedList::pushback(int x)
{
	if(root == NULL)
	{
		root = getnode(x);
	}
	else
	{
		Node *a = getnode(x);
		Node *tmp = root;
		while(tmp->next!= NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = a;
	}
}

void LinkedList::print()
{
	Node *tmp = root;
	while(tmp != NULL)
	{
		printf("%d ", tmp->x);
		tmp=tmp->next;
	}
	printf("\n");
}

void LinkedList::seggregate()
{
	Node *troot = root;
	Node *end = root;
	Node *prev = NULL;
	Node *curr = root;


	while(end->next != NULL)
		end = end->next;
	Node *newEnd = end;

	while(curr->x < 0 && curr!=end)
	{
		newEnd->next = curr;
		curr = curr->next;
		newEnd->next->next = NULL;
		newEnd = newEnd->next;
	}

	if(curr->x > 0)
	{
		while(curr != end)
		{
			if(curr->x > 0)
			{
				prev = curr;
				curr = curr->next;
			}
			else
			{
				prev->next = curr->next;
				curr->next = NULL;
				newEnd->next=curr;
				newEnd = curr;
				curr = prev->next;
			}
		}
	}
	else
		prev = curr;
	if (newEnd != end && end->x < 0)
	{
		prev->next = end->next;
		end->next = NULL;
		newEnd->next = end;
	}
}

int main()
{
	LinkedList L;
	L.pushback(1);
	L.pushback(-1);
	L.pushback(5);
	L.pushback(3);
	L.pushback(-7);
	L.pushback(8);
	L.pushback(9);
	L.print();
	L.seggregate();
	L.print();
	return 0;
}