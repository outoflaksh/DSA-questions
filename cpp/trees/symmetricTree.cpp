// Leetcode 101

class Solution
{
public:
    bool checkSymmetry(TreeNode *leftNode, TreeNode *rightNode)
    {
        // if both left and right children are null then symmetric
        if (!leftNode && !rightNode)
        {
            return true;
        }

        // if one of the child is missing or if the values of the immediate children doesn't match then not symmetric
        if (!leftNode || !rightNode || leftNode->val != rightNode->val)
        {
            return false;
        }

        // now we check symmetry between left node's left and right node's right node
        return checkSymmetry(leftNode->left, rightNode->right) && checkSymmetry(leftNode->right, rightNode->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        return checkSymmetry(root->left, root->right);
    }
};