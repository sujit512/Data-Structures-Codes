/*
Move the Smallest and largest to head and tail of list

Given a pointer to the head node of a linked list, find the smallest and largest of this list. Now move the smallest node to the front and move the largest node to the end of the list.

Input Format

First line contains one integer denoting the number of test cases.

For each test case, first line contains the total number of nodes in list i.e. N and next N lines contains the elements of nodes.

The function shiftSmallLarge() takes the head node of a linked list as a parameter and returns the head pointer after doing both shifts.

Note: Do not read any input from stdin/console. Each test case calls the shiftSmallLarge method individually and passes it the head of a list.

Output Format

Print the integer data for each element of the linked list separated by space.
Sample Input

1
7
12
8
6
20
1
50
16
Sample Output

1 12 8 6 20 16 50
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

struct Node * shiftSmallLarge(struct Node *org)
{
	struct Node* ptr = org;
  struct Node* head = NULL;
  struct Node* temp = NULL;
  struct Node* temp2 = NULL;
  struct Node* min = (struct Node*)malloc(sizeof(struct Node));
  struct Node * max = (struct Node*)malloc(sizeof(struct Node));
  if(org==NULL){
    return NULL;
  }
  else{
    //Find Max and Min Node
    min->data = org->data;
    max->data = org->data;
    while(ptr){
      if(ptr->data <= min->data){
       	min=ptr;
      }
      if(ptr->data >= max->data){
        max=ptr;
      }
      ptr = ptr->next;
    }
    //Remove Max and Min from Original
    struct Node* prev = NULL;
    ptr = org;
    prev = NULL;
    while(ptr){
      if(ptr==org){
        if(ptr==min||ptr==max){
          org=org->next;
          ptr=org;
//           prev=org;
        }
        else{
          prev = ptr;
          ptr=ptr->next;
        }
      }
      else{
        if(ptr==min||ptr==max){
          prev->next = ptr->next;
          ptr=ptr->next;
        }
        else{
          prev = ptr;
          ptr = ptr->next;
          
        }
      }
    }
    //Add Max and Min to the beginning and end
    head = min;
    head->next = org;
    ptr=head;
    while(ptr->next!=NULL){
      ptr=ptr->next;
    }
    ptr->next = max;
    max->next = NULL;
    //printf("%d %d\n",min->data,max->data);
    return head;
  }
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
    struct Node* ret = shiftSmallLarge(head);
    myprint(ret);
    t--;
  }
  return 0;
}