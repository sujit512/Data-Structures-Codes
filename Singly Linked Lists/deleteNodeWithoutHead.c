/*
A linked list is a collection of nodes. Where each node contains some data address of the next node, if it is the last node then it contains the data only. This way we can access all the nodes if we have the address of first node.

Now the task is that given a pointer to some node in a linked list, delete it if it is not the last node of the list.

Complete the function deleteNodeK() which takes the address of the node of a linked list as a parameter and delete this node from the list. (If given node is last node of list then do nothing.)



Input Format

First line will contain the number of test cases T.

Each test case contains 3 lines. First line has the total number of nodes and second line contains the N values for the nodes.

Third line contains the node number after the head node to be deleted.

Output Format

Print the integer data for each element of the modified linked list separated by space.


Sample Input

1
4
1 2 3 4
2
Sample Output

1 2 4
Explanation

2 means 2nd node after head is to be deleted, so node with value 3 is deleted.
*/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node* next;
};

void deleteNodeK(struct Node* n1)
{
  if(n1==NULL){}
  else if(n1->next==NULL){}
  else{
    n1->data = n1->next->data;
    n1->next = n1->next->next;
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
    int k;
    scanf("%d",&k);
    struct Node* ptr = NULL;
    ptr = head;
    for (int i = 0; i < k; ++i)
    {
    	ptr = ptr->next;
    }
    deleteNodeK(ptr);
    myprint(head);
    t--;
  }
  return 0;
}
