#include <stdio.h>

int main(void) {
  // Intilize Variables and Create the original and tranpose array
  int i,j;
  int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  int tranmat[3][3];

  // Print out the elements in the first matrix
  printf("The original matrix is: \n");
  for(i = 0; i < 3; i++)
      {
        for(j = 0; j < 3; j++)
          {
            printf("%d\t",matrix[i][j]);
          }
        printf("\n");
      }
  
  // Tranpose the elememets of the orignial matrixs by  just switching the rows and columns
  for(i = 0; i < 3; i++)
    {
      for(j = 0; j < 3; j++)
        {
          tranmat[j][i] = matrix[i][j]; 
        }
    }
  
  // Create Space between both matrixs 
  printf("The New Matrix is \n");
  
  // Print the elements of the transpose matrixs
  for(i = 0; i < 3; i++)
      {
        for(j = 0; j < 3; j++)
          {
            printf("%d\t",tranmat[i][j]);
          }
        printf("\n");
      }

  return 0;
}