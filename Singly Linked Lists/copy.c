/*
Given a pointer to the head node of a linked list, copy all the elements in another list and return the head of second list.

Input Format

First line contains one integer denoting the number of test cases.

For each test case, first line contains the total number of nodes in list i.e. N and next N lines contains the elements of nodes.

The function copyList() takes the head node of a linked list as a parameter and return the head pointer of copied list.

Note: Do not read any input from stdin/console. Each test case calls the copyList method individually and passes it the head of a list.

Output Format

Print the integer data for each element of the linked list separated by space.
Sample Input

1
3
1
2
3
Sample Output

1 2 3
*/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node* next;
};

struct Node *copyList(struct Node *org)
{
  struct Node* head = NULL;
  struct Node* ptr = org;
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));      	
  while(ptr){
    if(ptr==org){
    	temp->data = ptr->data;
      temp->next=NULL;
      	ptr = ptr->next;
      	head=temp;
    }
    else{
   		struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    	temp->next = new_node;
      	new_node->data = ptr->data;
      	temp = new_node;
      temp->next=NULL;
      	ptr = ptr->next;
    }
  }
  return head;
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
    struct Node* ret = copyList(head);
    myprint(ret);
    t--;
  }
  return 0;
}