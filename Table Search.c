#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Create a struture node to help store values 
typedef struct node
{

  char mpnid[6];

  char mptable[4];

  char number1[4];

  char number2[4];

} MPN_data;

int main(void) {
  // Open the File with all the values in it
  FILE *mpn_table;
  mpn_table = fopen("mpn_table.txt","r");
  // Set up the Array we are going to store our values in 

  char row[1000],userinput[5] = "none";

  // Create the pointer 
  
  char *pointer;

  // setup the count as well as the i variable we use 
  
  int count = 0,i;

  // Call back to the stucture node and set it to the number of rows 
  MPN_data data[16];
  

  // Read the txt file line by line  
  while(fgets(row,1000, mpn_table))
    {
      
       pointer = strtok(row,",");
      
      for(i = 0; pointer != NULL; i++)
    {
       
      // Run through each case for all of the values we need to print out 
       switch(i)
         {
           // Case 0 uses the combination 
           case 0:
             
               memset(data[count].mpnid, 0,sizeof(data[count].mpnid));
               strcpy(data[count].mpnid,pointer);
                break;


           case 1:
             
               memset(data[count].mptable, 0, sizeof(data[count].mptable));
               strcpy(data[count].mptable,pointer);
                break;
            // Case 2 uses the first value 
           case 2:
             
               memset(data[count].number1, 0, sizeof(data[count].number1));
               strcpy(data[count].number1,pointer);
                break;
              // Case 3 uses the second value 
           case 3:
              
               memset(data[count].number2, 0, sizeof(data[count].number2));
                
               strcpy(data[count].number2,pointer);
                break;
         }
        pointer = strtok(NULL,",");
      }
      
      count++;
    }

// Get the Users input for searching  through the file 
    
  while(userinput != NULL)
    {
      printf("Enter a combination of Positive triplets :");
      scanf("%s",userinput);
      for(i = 0; i < 16; i++) 
      {
        // Printing the values asscosiated with the Combination of Positives they selected 
        
        if(strcmp(data[i].mpnid, userinput) == 0)
        {
          
          printf("For %s the combination you entered MPN = %s; 95 percent of samples have between  %s and %s bacteria /100 ml.  \n",data[i].mpnid,data[i].mptable,data[i].number1, data[i].number2);
        }
      }
    }
  fclose(mpn_table);
   return 0;
}