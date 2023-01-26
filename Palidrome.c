#include <stdio.h>
#include <string.h>
int main(void) {
  // Intialize the Variables we are going to use  
  char word[25];
  int string;
  int palidrome = 0;
  int i; 
  
  // Ask the user for the word 
  printf("Type in word :");
  scanf("%s",word);
  // Get the string length 
  string = strlen(word);
  
  // See if each letter is the same in the reverse order 
  for(i = 0;i < string; i++){
    if(word[i] != word[string - i - 1]){
      palidrome = 1;
      break;
    }
  }
    
  // Based off of the statement we either say it is a palindrome or not 
  if (palidrome){
      printf("This word is Not a Palindrome");
      }
    else {
      printf("This word is a Palindrome");
    }
      
  return 0;
}