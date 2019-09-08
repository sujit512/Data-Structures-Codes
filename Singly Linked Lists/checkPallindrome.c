/*
Check List for Palindrome

Given a pointer to the head node of a linked list, check it is a palindrome or not.

Complete the function checkPalindrome() which takes the head node of a linked list as a parameter and return 1 if the number represented by list is palindrome, and 0 otherwise.



Input Format

The first line will contains an integer i.e. number of test cases

Each test case contains two line. First line denotes the number of nodes in list and second line contains the node values.

Output Format

Print 1 if list is palindrome and 0 if list is not palindrome.


﻿Sample Input

2
3
1 2 3
3
1 2 ﻿1
Sample Output

0
1
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

int  checkPalindrome(struct Node* head) 
{
  int size=0;
  int flag=0;
	struct Node* tail = NULL;
  struct Node* ptr = head;
  struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
  while(ptr){
    if(ptr==head){
      head2->data = ptr->data;
      head2->next=NULL;
      ptr = ptr->next;
    }
    else{
      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
		new_node->next= head2 ;
      new_node->data = ptr->data;
      head2 = new_node;
      ptr=ptr->next;
    }
  }
  struct Node* ptr2 = head2;
  ptr = head;
  while(ptr&&ptr2){
    if(ptr->data==ptr2->data){
      flag = 1;
      ptr = ptr->next;
      ptr2 = ptr2->next;
    }
    else{
      flag = 0;
      break;
    }
  }
  return flag;
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
    int ret = checkPalindrome(head);
    if(ret == 0)
    	printf("Not a Palindrome");
    if(ret == 1)
    	printf("Palindrome");
    t--;
  }
  return 0;
}