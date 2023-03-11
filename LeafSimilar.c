/*
Author: Luke Dekan
Filename : LeafSimilar. C
Implementation: Test if Two Binary trees are Leaf Similar  
*/

#include<stdio.h>
#include<stdlib.h>


typedef struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
}node;

    
      // Function to create a new binary tree node
    struct treenode* InsertNode(int data) 
    {
        struct treenode* node = (struct treenode*)malloc(sizeof(struct treenode));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return(node);
    }
    
// Function to traverse the tree function and store each value in a hash table 
    void PreOrdertraverse(struct treenode* root, int hash[]) 
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            hash[root->data]++;

             PreOrdertraverse(root->left, hash);
             PreOrdertraverse(root->right, hash);
    }

// Function to check if two binary trees are leaf similar
int leafComparison(struct treenode* root1, struct treenode* root2) 
  {
    if (root1 == NULL || root2 == NULL)
        return 0;
  
        //Create the hash tables 
         int hash1[10000] = {0}, hash2[10000] = {0};
          int i;
  
      // Traverse the first tree and store the values in the first hash table 
     PreOrdertraverse(root1, hash1);

      // traverse the second tree and store the values in the second hash table 
      PreOrdertraverse(root2, hash2);

    // Compare the two hash tables
    for (i = 0; i < 10000; i++) {
        if (hash1[i] != hash2[i])
            return 0;
    }

    return 1;
}

// Main Function to instert our nodes in the right place and run all of the previous funcions 
int main() {
  // Insert the elements for the first Binary Tree
    struct treenode *root1 = InsertNode(3);
    root1->left = InsertNode(5);
    root1->right = InsertNode(1);
    root1->left->left = InsertNode(6);
    root1->left->right = InsertNode(2);
    root1->left->right->left = InsertNode(7);
    root1->left->right->right = InsertNode(4);
    root1->right->left = InsertNode(9);
    root1->right->right = InsertNode(8);

    // Insert all the elements for the second Binary Tree 
    struct treenode *root2 = InsertNode(3);
    root2->left = InsertNode(5);
    root2->right = InsertNode(1);
    root2->left->left = InsertNode(6);
    root2->left->right = InsertNode(7);
    root2->right->left = InsertNode(4);
    root2->right->right = InsertNode(2);
    root2->right->right->left = InsertNode(9);
    root2->right->right->right = InsertNode(8);

   // Print out the end result after running it through the function 
if (leafComparison(root1, root2))
        printf("The Binary trees are Leaf Similar \n");
    else
        printf("The Binary trees are not Leaf Similar.\n");

    return 0;
  }