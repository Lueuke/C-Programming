/*
Author: Luke Dekan
Filename : BST. C
Implementation: Take inputs from the user and input into a binary tree and be able search for elements and check if the tree is balanced or not and return the left most node 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node Structure
typedef struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
}node;

        // Create the Binary Search Tree 
    struct treenode *insertNode(int value) {
           struct treenode *new_node = (struct treenode *)malloc(sizeof(struct treenode));
            new_node->data = value;
            new_node->left = NULL;
            new_node->right = NULL;
            return new_node;
        }

          // Insert Values into the tree
          struct treenode *insert(struct treenode *root, int value) {
               if (root == NULL) {
                return insertNode(value);
              }          
            if (value < root->data) {
               root->left = insert(root->left, value);
                  }       
            else {
              root->right = insert(root->right, value);
                }
        return root;
      }

      // Get the left most node by travserving the left tree until it points to a null value
          struct treenode *leftNode(struct treenode *root) {
              while (root->left != NULL) {
                root = root->left;
                }
            return root;
          }

          // Search for the user input values 
          bool search(struct treenode *root, int value) 
            {
             if (root == NULL) 
                {
                 return false;
                }
              if (root->data == value) 
                  {
                  return true;
                  } 
            else if (value < root->data) 
                  {
                      return search(root->left, value);
                  } 
            else 
            {
              return search(root->right, value);
          }
}

          // Find the Height of the Binary Search tree 
      int height(struct treenode* root) 
           {
            if (root == NULL) 
            {
              return 0;
            }
          int height_left = height(root->left);
          int height_right = height(root->right);
          return 1 + (height_left > height_right ? height_left : height_right);
        }

        // Using the height in the above function we can figure out if the tree is balanced in the function
      bool balanceCheck(struct treenode* root) {
           if (root == NULL)
            {
              return true;
            }
          int height_left = height(root->left);
          int height_right = height(root->right);
         if (abs(height_left - height_right) > 1) 
         {
              return false;
         }
         return balanceCheck(root->left) && balanceCheck(root->right);
      }


        int main() {
    // Create the empty Binary tree
             struct treenode *root = NULL;

    // Get values for the tree from the user 
               int n;
          printf("Enter the  number of values you want in the Binary Search tree: ");
              scanf("%d", &n);
          
              printf("Enter %d values into the Binary Search Tree: ", n);
              for (int i = 0; i < n; i++) {
                 int value;
                  scanf("%d", &value);
                  root = insert(root, value);
                }

          // Search for the left most value in the tree
          struct treenode *leftmost = leftNode(root);
      
          // Print the left most value 
          printf("The leftmost value is %d\n", leftmost->data);
      
          // Search for a value in the BST
          int number_search;
          
          printf("Enter the value you want to search for in the Tree: ");
          scanf("%d", &number_search);
          
          bool exists = search(root, number_search);
          
          if (exists) {
              printf(" %d does exists in the Binary Search Tree\n", number_search);
          } 
          else 
          {
              printf(" %d does not exist in the tree\n", number_search);
          }
      
          if (balanceCheck(root)) 
          {
          printf("The Binary Search Tree is Balanced\n");
           } 
          else 
            {
          printf("The Binary Search Tree is not Balanced \n");
      
          return 0;
          }
      }
      