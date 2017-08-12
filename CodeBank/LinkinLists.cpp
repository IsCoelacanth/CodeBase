#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef map<int,int> mint;
#define MOD 1000000007

struct Node
{
	int val;
	Node *next;
};

void printList(Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->val);
        node = node->next;
    }
}

Node *newNode(int c)
{
	Node *tmp = new Node();
	tmp->val = c;
	tmp->next = NULL;
	return tmp ;
}

Node *Push_back(Node *head, int x)
{
	if(head == NULL)
	{
		head = newNode(x);
		return head;
	}
	Node *curr = head;
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = newNode(x);
	return head;
}

Node *Push_front(Node *head, int x)
{
	if(head == NULL)
	{
		head = newNode(x);
		return head;
	}
	Node *tmp = newNode(x);
	tmp->next = head;
	head = tmp;
	return head;
}

Node *seperate(Node *head)
{
	Node *odd = NULL, *odds = NULL;
	Node *curr = head, *prev = NULL;
	while(curr->next != NULL)
	{
		if(curr->val%2 != 0)
		{
			Node *tmp = curr->next;
			if(curr == head)
			{
				head = tmp;
			}
			if(odd == NULL)
			{
				odd = curr;
				odds = curr;
				odd->next=NULL;
			}
			else
			{
				odd->next = curr;
				odd=odd->next;
				odd->next = NULL;
			}
			prev->next = tmp;
			curr = tmp;
		}
		else
		{
			prev = curr;
			curr=curr->next;
		}
	}
	curr->next = odds;
	return head;
}

Node *RevK_rec(Node *troot, int k)
{
	Node *curr = troot;
	Node *prev = NULL;
	Node *nxt = NULL;
	int cnt = 0;

	while(curr != NULL && cnt<k)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
		cnt++;
	}
	if(nxt != NULL)
		troot->next = RevK_rec(nxt,k);
	return prev;
}

int main()
{
	Node *head = NULL;
	printf("Enter list size\n");
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int tmp;
		scanf("%d",&tmp);
		head = Push_back(head,tmp);
	}
	printList(head);
	head = RevK_rec(head,3);
	printf("\n");
	printList(head);
	return 0;
}