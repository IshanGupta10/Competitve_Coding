bool countUnivalSubtree(node* leaf, int& count)
{
    if(leaf == NULL) 
        return true;

    int leftUnival = countUnivalSubtree(leaf->left, count);
    int rightUnival = countUnivalSubtree(leaf->right, count);

    if(leftUnival && rightUnival)
        if((leaf->left == NULL) || leaf->left->val == leaf->val) 
            if((leaf->right == NULL) || leaf->right->val == leaf->val)
            {    ++count;
                return true;
            }
    return false;
}
int countUnivalSubtrees(node* leaf) 
{
    int count = 0;
    if(countUnivalSubtree(leaf, count))
        return count;
    else
        return 0;
}
