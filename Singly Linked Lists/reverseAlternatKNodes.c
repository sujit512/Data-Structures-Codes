/*
Reverse Alternate K nodes of Linked List

Given a pointer to the head node of a linked list and an integer K, reverse every alternate K nodes in an efficient way.

Complete the function revAltKNodes() which takes the head node of a linked list & an integer K as parameters and return the head of modified list after reversing all alternative K nodes of the list.



﻿Input Format

First line of input contains the number of test cases i.e. T.

Each test case consists of 3 lines. First line contains the number of nodes in the list, second lines contains the node values.

Third line contains one integer i.e. K.

Output Format

Print the integer data for each element of the linked list separated by space.


Sample Input

1
6
1 2 3 4 5 6
2
Sample Output

2 1 3 4 6 5
Explanation

K=2, so every 2 nodes are reversed i.e. 1 2 becomes 2 1, 3 4 becomes 4 3 and so on
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

struct Node* revAltKNodes (struct Node* head, int k) 
{
  struct Node* current = head; 
    struct Node* next; 
    struct Node* prev = NULL; 
    int count = 0;    

    while (current != NULL && count < k) 
    { 
       next  = current->next; 
       current->next = prev; 
       prev = current; 
       current = next; 
       count++; 
    } 

    if(head != NULL) 
      head->next = current;    

    count = 0; 
    while(count < k-1 && current != NULL ) 
    { 
      current = current->next; 
      count++; 
    } 

    if(current !=  NULL) 
       current->next = revAltKNodes(current->next, k);  
  
    return prev; 
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
    int k;
    scanf("%d",&k);
    struct Node* ret = revAltKNodes(head,k);
    myprint(ret);
    t--;
  }
  return 0;
}