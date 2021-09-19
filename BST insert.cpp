/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//BST IMPLEMENTATION
#include <iostream>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    
};
TreeNode* InsertIntoBST(TreeNode* root, int value)
{
    TreeNode * cur = root;
    if(root == NULL)
    {
        return new TreeNode(value);
    }
    while(true)
    {
        if(cur->val<=value)
        {
            if(cur -> right != NULL)
            cur = cur -> right;
            else
            {
                cur->right = new TreeNode(value);
                break;
            }
        }
        else
        {
            if(cur->left!=NULL)
            cur = cur -> left;
            else
            {
                cur -> left = new TreeNode(value);
                break;
            }
        }
    }
    return root;
}
