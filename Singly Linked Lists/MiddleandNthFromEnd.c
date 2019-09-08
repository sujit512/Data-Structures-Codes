/*
Find the Middle and Nth from Last of the list

Given a pointer to the head node of a linked list, find the middle node & Nth node from end of the list.

findMiddle(head) : Return the middle node if number of nodes in linked list in odd, otherwise there will be two middle nodes and return the second middle node (return -1 if list is empty).

findNLast(head, n): Return the Nth node from end of the list. If N is greater than size of the list, return the last node of list (return -1 if list is empty).

Input

The functions int findMiddle() & int findNLast() takes the head node of a linked list as a parameter and returns the required integer elements.

Note: Each test case calls the findMiddle & findNLast method individually and passes it the required arguments.

Output

Print middle element and Nth from end element in separate lines.
Sample Input

2                    // Total number of test cases
5                    // Total elements in the list for test-case-1
1 2 3 4 5            // Elements of the list for test-case-1
2                    // Value of N
6                    // Total elements in the list for test-case-2
1 2 3 4 5 6          // Elements of the list for test-case-2
8                    // Value of N
Sample Output

3
4
4
6
Explanation

In first list, middle element is 3 and 2nd last element is 4.
In second list, second middle element is 4 and last element is 6.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

int findMiddle(struct Node* head) 
{
  if(head==NULL){
    return -1;
  }
  int size=0;
  struct Node* ptr = head;
  while(ptr){
    ptr=ptr->next;
    size++;
  }
  ptr=head;
  if(size%2==1){
    	for(int i=1;i<=size/2;i++){
          ptr = ptr->next;
        }
    	return ptr->data;
	}
    if(size%2==0){
    	for(int i=1;i<size/2+1;i++){
          ptr = ptr->next;
        }
    	return ptr->data;
	}
}

int findNLast(struct Node* head, int n)
{
  if(head==NULL){
    return -1;
  }
  int size=0;
  int count;
  struct Node* ptr = head;
  while(ptr->next){
    ptr=ptr->next;
    size++;
  }
  if(n>size+1){
    return ptr->data;
  }
  else
  {
    count = size+1-n;
    ptr=head;
    for(int i=1;i<=count;i++){
      ptr=ptr->next;
    }
    return ptr->data;
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
    int mid = findMiddle(head);
    printf("%d\n",mid);
    int ret = findNLast(head);
    printf("%d\n",ret);
    t--;
  }
  return 0;
}