#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct bt
{
	bt *left;
	int data;
	bt *right;
};

void InOrderRecursion(bt *leaf)
{
	if(leaf)
	{
		InOrder(leaf->left);
		cout<<leaf->data;
		InOrder(leaf->right);
	}
}

void InOrderNonRecursion(bt *leaf)
{
	stack<bt*> st;
	while(1)
	{
		while(leaf)
		{
			st.push(leaf);
			leaf = leaf->left;
		}
		if (st.empty())
			break;
		leaf = st.top();
		st.pop();
		cout<<leaf->data;
		leaf = leaf->right;
	}
	st.erase();
}

void levelOrderTraversal(bt *leaf)
{
	bt *temp;
	queue<bt*> q;	
	if(!root)
		return;
	q.push(leaf);
	while(!q.empty())
	{
		temp = q.pop();
		cout<<temp->data;
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	q.erase();
}