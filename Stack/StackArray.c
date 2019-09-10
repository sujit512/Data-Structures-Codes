/*
Implement the stack using array representation



Input

First line of input contains an integer Q denoting the number of queries.

A Query is of 2 Types

(a) 1 item  (a query of this type means push 'item' onto the stack)

(b) 2   (a query of this type means to pop element from stack and print the popped element)

The second line of each test case contains Q queries separated by space.



Output

The output for each test case will be space separated integers having -1 if the stack is empty else the element popped out from the stack.

You are required to complete the methods given.



Sample Input

8
1 3 2 1 4 1 2 2 1 6 2 2


Sample Output

3 2 6 4
*/

#include<stdio.h>

#define SIZE 10

int Stack[SIZE], top=-1;

int isFull()
{
  return top==(SIZE-1);
}

int isEmpty()
{
  return top==-1;
}

// Function to add an item to stack.  It increases top by 1
int push(int item)
{
  if (isFull())
  {
    printf("OVERFLOW");
    return -1;
  }
  printf("%d pushed to stack\n",item);
  Stack[++top] = item;
  printf("Top is now at %d\n", top);
}

// Function to remove an item from stack.  It decreases top by 1
int pop()
{
  int temp;
  if (isEmpty())
  {
    printf("UNDERFLOW \n");
    return -1;
  }
  temp=Stack[top--];
  printf("%d popped from stack\n", temp);
  printf("Top is now at %d\n", top);
  return temp;
}

int main()
{
  int temp;
  push(12);
  push(23);
  temp=pop();
  push(54);
  temp=pop();
  temp=pop();
  temp=pop();
  return 0;
}