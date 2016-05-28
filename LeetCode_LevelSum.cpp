#include <iostream>
using namespace std;

int level = 1, esum = 0, osum = 0;

struct node
{
    int key;
    struct node *left, *right;
};
  
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
  
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    /* return the (unchanged) node pointer */
    return node;
}

void levelSum(struct node *leaf)
{
	if(leaf == NULL)
	{
		level--;
	    return;
	}
	if(leaf->left != NULL && leaf->right != NULL)
	{
	    if(level % 2)
	    {    
	        osum += leaf->key;
	        level++;
	    }
	    else
	    {   
	        esum += leaf->key;
	        level++;
	    }
	    
	    levelSum(leaf->left);
	    levelSum(leaf->right);
	}
	
	if(leaf->left == NULL && leaf->right != NULL)
	{
	    if(level % 2)
	    {    
	        osum += leaf->key;
	        level++;
	    }
	    else
	    {   
	        esum += leaf->key;
	        level++;
	    }
	    levelSum(leaf->right);
	}
	
	if(leaf->left != NULL && leaf->right == NULL)
	{
	    if(level % 2)
	    {    
	        osum += leaf->key;
	        level++;
	    }
	    else
	    {   
	        esum += leaf->key;
	        level++;
	    }
	    
	    levelSum(leaf->left);
	}
	if(leaf->left == NULL && leaf->right == NULL)
	{
		if(level % 2)
	    {    
	        osum += leaf->key;
	        level++;
	    }
	    else
	    {   
	        esum += leaf->key;
	        level++;
	    }
	    level--;
	    return;
	}
	level--;
	return;
}
int main() 
{
	struct node *root = NULL;
    root = insert(root, 3);
    insert(root, 2);
    //insert(root, 20);
    insert(root, 3);
    insert(root, 3);
    //insert(root, 60);
    insert(root, 1);
    
    inorder(root);
    levelSum(root);
    cout<<'\n'<<esum<<" "<<osum;
    
	return 0;
}