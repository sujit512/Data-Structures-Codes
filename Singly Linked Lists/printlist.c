/*
Given a pointer to the head node of a linked list, print its elements in forward and backward order, separated by hyphen. If the head pointer is null (indicating the list is empty), don’t print anything.

The functions void forwardPrint() & void backwardPrint() takes the head node of a linked list as a parameter.

Note: Do not read any input from stdin/console. Each test case calls the forwardPrint & backwardPrint method individually and passes it the head of a list.

Input Format

First line contains the number of test cases.
Each test case contains an integer denoting the number of elements in list, followed by the numbers in new lines.
Output Format

Print the integer data for each element of the linked list separated by hyphen.
Sample Input

1
3
1
2
3
Sample Output

1-2-3-
3-2-1-
*/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node* next;
};

void forwardPrint(struct Node* head)
{
	if(head==NULL){
      //printf("Empty List");
    }
  else{
    struct Node* ptr = head;
    while(ptr!=NULL){
      printf("%d-",ptr->data);
      ptr=ptr->next;
    }
  }
}

void backwardPrint(struct Node* head)
{
	if(head==NULL){
      //printf("Empty List");
    }
  else{
    struct Node* ptr = head;
    backwardPrint(ptr->next);
    printf("%d-",ptr->data);
  }
}

struct Node* makelist(int n){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = NULL;

  for (int i = 0; i < n; i++){
      if(ptr == NULL)
      {
        scanf("%d",&temp->data);
        ptr = temp;
      }
      else{
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        ptr->next=new_node;
        scanf("%d",&new_node->data);
        ptr = new_node;
        ptr->next = NULL;
      }
    }
    return temp;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t!=0){
    struct Node* head = NULL;
    int n;
    scanf("%d",&n);
    if(n==0){
        printf("Cannot execute Function as their will be No List");
        break;
    }
    head = makelist(n);
    int k;
    scanf("%d",&k);
    struct Node* ptr = NULL;
    ptr = head;
    for (int i = 0; i < k; ++i)
    {
      ptr = ptr->next;
    }
    forwardPrint(head);
    backwardPrint(head);
    t--;
  }
  return 0;
}
