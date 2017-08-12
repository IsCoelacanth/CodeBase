#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

class linklist {
private:


public:
    Node *head,*tail;
    linklist (){head = NULL;tail = NULL;}
    void insertc(int);
    Node * newnode(int);
    bool checkcirc();
};

Node * linklist::newnode(int n)
{
    Node *temp = new Node();
    temp->val = n;
    temp->next = NULL;
    return temp;
}

void linklist::insertc(int n)
{
    Node *temp = newnode(n);
    if(head == NULL)
    {
        head = temp;
        tail = head;
        tail->next = head;
    }
    temp->next = head;
    head = temp;
    tail->next = head;
}


bool linklist::checkcirc()
{
    Node *tmp = head->next;
    while(tmp != NULL && tmp != head)
        tmp = tmp->next;
    return (tmp == head);
}

int main()
{
    linklist L;
    L.insertc(1);
    L.insertc(1);
    L.insertc(1);
    L.insertc(1);
    L.insertc(1);
    L.insertc(1);
    if(L.checkcirc())
        printf("Circular\n");
    else
        printf("Not circular\n");
    L.tail->next = NULL;
    if(L.checkcirc())
        printf("Circular\n");
    else
        printf("Not circular\n");
}
