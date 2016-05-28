    int rob(TreeNode* root)
    {
        auto p = search(root);
        return max(p.first, p.second);
    }

    pair<int, int> search(TreeNode* root)
    {
        if (!root) return { 0 , 0 };

        auto pl = search(root->left);
        auto pr = search(root->right);

        return make_pair(root->val + pl.second + pr.second,
                         max(pl.first, pl.second) + max(pr.first, pr.second));
    }