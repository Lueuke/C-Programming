#include <stdio.h>
#include <stdbool.h>
int main(void) {
   
  
  int input;

  printf("Enter the length of the array: ");
  scanf("%d", &input);

  int values[input];
  bool duplicate = false;

  // Taking User input
  printf("Now enter the values of the array");
  for(int i = 0; i < input; ++i) {
    scanf("%d", &values[i]);
  }
  printf("The unique values are: ");
  for (int i = 0; i < input; ++i) {
    for (int j = 0;  j < input; ++j) {
      if (i != j) {
        if (values[j] == values[i]){
          duplicate = true;
        }
      }
    }
    if(duplicate == false) {
        printf("%d ",values[i]);
    }
    duplicate = false;
  }
  return 0;
}