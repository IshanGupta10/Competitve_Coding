#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

vector<int> v;

typedef struct node Node;  
#define pb push_back

Node *newNode(int item)
{
    Node *temp =  new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
  
Node *insert(Node *node, int key)
{
    if (node == NULL) return newNode(key);
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    return node;
}
  
void findParent(Node *leaf)
{
	if(leaf == NULL)
		return;

	if(leaf->left != NULL && leaf->right == NULL)
	{
		v.pb(leaf->key);
		findParent(leaf->left);
	}

	if (leaf->right != NULL && leaf->left == NULL)
	{
		v.pb(leaf->key);
		findParent(leaf->right);
	}

	if (leaf->left && leaf->right)
	{
		v.pb(leaf->key);
		findParent(leaf->left);
		v.pb(leaf->key);
		findParent(leaf->right);
	}

	if(leaf->left == NULL && leaf->right == NULL)
		return;

	return;
}


int main()
{
	int n, t;
    Node *root = NULL;

    cin>>n;

    for (int i = 0; i < n; ++i)
    {
    	cin>>t;
    	if(i == 0)
    		root = insert(root, t);
    	else
    		insert(root, t);
    }	

	findParent(root);  

//    inorder(root);
	
	for(int i = 0; i < v.size(); ++i)
		cout<<v[i]<<" ";
    return 0;
}