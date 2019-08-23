/*An n-digit number can be expressed using a linked list of n nodes, where each node can be used to represent a digit.

Now given two numbers represented by two singly linked lists, compute the sum of these numbers, provided that the digits are stored in reverse order, such that the digit of 1’s place is at the head of the list.

Complete the function addListNumbers() which takes the head nodes of two linked lists as parameters and return the head of the list which contains the computed sum.

Input Format

First line contains an integer denoting the number of test cases.

Each test cases has 4 lines. First line contains the digits of first number and second lines contains the digits.

Third line contains the digits of second number and fourth lines contains the digits.

Output

Print the integer data for each element of the sum list separated by space.
Sample Input

2
3
3 1 5
3
5 9 2
3
3 1 3
2
2 1
Sample Output

8 0 8
5 2 3
Explanation

For first two numbers, they are 513 and 295 so the sum will be 808
For second two numbers, they are 313 and 12 so the sum will be 325*/


#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node* next;
};
int reverse(int num)
{
  int rev = 0;
  int n = num;
  while(n!=0){
    rev = rev*10;
    rev = rev + n%10;
    n = n/10;
  }
  return rev;
}
struct Node* create(int n){
  struct Node* head = NULL;
  struct Node* temp = NULL;
  struct Node* first = (struct Node*)malloc(sizeof(struct Node));
  while(n!=0){
    if(head==NULL){
      first->data = n%10;
      temp = first;
      head = first;
      n = n/10;
    }
    else{
      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
      temp->next = new_node;
      new_node->data = n%10;
      new_node->next = NULL;
      temp = new_node;
      n = n/10;
    }
  }
  return head;
}
struct Node* addListNumbers(struct Node* head1, struct Node* head2)
{
  struct Node* ptr1 = head1;
  struct Node* ptr2 = head2;
  int num1=0;
  int num2=0;
  while(ptr1){
    num1 = num1 * 10;
    num1 = num1 + ptr1->data;
    ptr1=ptr1->next;
  }
  num1 = reverse(num1);
  while(ptr2){
    num2 = num2 * 10;
    num2 = num2 + ptr2->data;
    ptr2=ptr2->next;
  }
  num2 = reverse(num2);
  int c = num1+num2;
  struct Node* h1 = create(c);
  return h1;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t!=0){
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = NULL;
    int n1;
    scanf("%d",&n1);
    for (int i = 0; i < n1; i++){
      if(ptr == NULL)
      {
        scanf("%d",&head1->data);
        ptr = head1;
      }
      else{
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        ptr->next=new_node;
        scanf("%d",&new_node->data);
        ptr = new_node;
        ptr->next = NULL;
      }
    }
    ptr = NULL;
    int n2;
    scanf("%d",&n2);
    for (int i = 0; i < n2; i++){
      if(ptr == NULL)
      {
        scanf("%d",&head2->data);
        ptr = head2;
      }
      else{
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        ptr->next=new_node;
        scanf("%d",&new_node->data);
        ptr = new_node;
        ptr->next = NULL;
      }
    }
    struct Node* final = addListNumbers(head1,head2);
    ptr = final;
    while(ptr){
      printf("%d",ptr->data);
      ptr = ptr->next;
    }
    t--;
  }
  return 0;
}
