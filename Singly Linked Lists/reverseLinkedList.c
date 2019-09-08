/*
Reverse a linked list

A linked list is a collection of nodes. First node is called head node and last node called the tail node.

Now, given a pointer to the head node of a linked list, can you reverse the linked list i.e. New list must start with tail node and end at head node. So it becomes the reverse of the original list.

Complete the function reverseList() which takes the head node of a linked list as a parameter and return the new head of reversed list.



Input Format

First line contains an integer i.e. Number of test cases.

Each test case have two lines. First line has the total number of nodes and second line has the node values.

Output Format

Print the integer data for each element of the linked list separated by space.



Sample Input

1
3
1 2 3
Sample Output

3 2 1
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

struct Node* addFirst(struct Node* temp,int val){
  struct Node* head = (struct Node*)malloc(sizeof(struct Node));
  head->data = val;
  head->next = temp;
  return head;
}
struct Node*  reverseList(struct Node* head) 
{
  if(head==NULL){
   return head; 
  }
  struct Node* ptr = head;
  struct Node* temp = NULL;
  while(ptr){
    temp = addFirst(temp,ptr->data);
    ptr = ptr->next;
  }
  return temp;
}

void myprint(struct Node* final){
	struct Node* ptr = final;
    while(ptr){
      printf("%d ",ptr->data);
      ptr = ptr->next;
    }
    printf("\n");
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
    struct Node* ret = reverseList(head);
    myprint(ret);
    t--;
  }
  return 0;
}