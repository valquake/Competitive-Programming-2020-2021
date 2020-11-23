/*
	Author: Valeria Montagna

	Solution Description:
	This is a recursive solution. At the beginning, we have two base cases: when we reach an empty node or when
	we have a leaf. The other two cases represents when we have an internal node and when we have a node with
	at most one subtree. In the former, we have to check if we have a new global maximum sum and in case update it. Then it is returned the
	local maximum sum. In the latter, we have to return the root sum for that particular case.


	Time Complexity:
	O(n), with n number of nodes.

*/

#include <iostream>
#include <bits/stdc++.h>

int maxPathSumR(Node* root, int &max)
{ 
	// Two base cases
    if (root == NULL) 
        return 0; 

    if (!root->left && !root->right)
    	return root->data;
  
    int ls = maxPathSumR(root->left, max);
    int rs = maxPathSumR(root->right, max);

    // 
    if(root->left && root->right){
    	max = std::max(max, root->data + ls + rs);

    	return std::max(ls, rs) + root->data;
    }

    return (!root->left)? rs + root->data : ls + root->data;
}

int maxPathSum(Node* root)
{
	int max = INT_MIN;
	maxPathSum(root, max);
	return max;
}