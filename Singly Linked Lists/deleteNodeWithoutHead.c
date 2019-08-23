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
      printf("%d",ptr->data);
      ptr = ptr->next;
    }
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
    myprint(final);
    t--;
  }
  return 0;
}