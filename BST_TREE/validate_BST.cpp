
class Solution
{
public:
    bool Solve(TreeNode *root, long long int lb, long long int ub)
    {
        // base case
        if (root == NULL)
            return true;

        if (root->val > lb && root->val < ub)
        {
            bool leftAns = Solve(root->left, lb, root->val);
            bool rightAns = Solve(root->right, root->val, ub);
            return leftAns && rightAns;
        }
        else
        {
            return false;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        long long int lowerBound = -4294967296;
        long long int upperBound =  4294967296;
        bool ans = Solve(root, lowerBound, upperBound);
        return ans;
    }
};