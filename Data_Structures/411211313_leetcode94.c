void inOrder(struct TreeNode *tree, int *array, int *returnSize){
    if (tree == NULL) return;
    inOrder(tree->left, array, returnSize);
    array[*returnSize] = tree->val;
    (*returnSize)++;
    inOrder(tree->right, array, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *array = (int *)malloc(sizeof(int)*101);
    inOrder(root, array, returnSize);
    return array;
}