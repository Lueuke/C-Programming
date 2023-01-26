#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
  int data;
  struct listnode *next;
} node;

int main(void) {

  int ListLength;
  int i;
  struct listnode *head,*previous,*point;
  
    printf(" Enter Total number of items in Linked List:");
    scanf("%d",&ListLength);
  
  head = NULL;
    for(i = 0; i<ListLength; i++)
      {
        point = malloc(sizeof(struct listnode));
        printf("Enter an Number: ");
        scanf("%d", &point -> data);
        point -> next=NULL;
          if(head == NULL)
              head=point;
            else  
              previous -> next=point;
            previous = point;
      }
      
    struct listnode *temp = head;

    while(temp != NULL)
      {
        printf("%d -> ", temp -> data);
        temp = temp-> next;
      }
  printf("NULL");
  return 0;
}