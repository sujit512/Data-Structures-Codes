/*

Implement the stack using array which supports, push, pop and getmin functions with constant time complexity.

Input

First line of input contains an integer Q denoting the number of queries.

A Query is of 3 Types

(a) 1 item  (a query of this type means push 'item' onto the stack)

(b) 2 (a query of this type means to pop element from stack and print the popped element)

(c) 3 (a query of this type means to print the minimum of the stack, it will not remove the element from stack)

The second line of each test case contains Q queries separated by space.

Output

The output for each test case will be space separated integers having -1 if the stack is empty else the element popped out from the stack.

You are required to complete the methods given.

﻿

Sample Input

8
1 4 1 3 3 2 3 1 1 3 2
Sample Output

3 3 4 1 1
Explanation

First query is push 4, then 2nd is push 3. So stack is { 3 4 }
3rd query is getmin which prints 3, then pop will print 3. So stack is { 4 }
5th query is getmin which prints 4, then push 1 on stack. So stack is { 1 4 }
7th query is getmin which prints 1, then last query is pop which prints 1.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int min = 100;
int Min[SIZE],mtop = -1;
void push(int item)
{
	if(isFull()){
      return;
    }
  if(item<=min){
    Min[++mtop] = item;
    min=item;
  }
  Stack[++top] = item;
}

// Function to remove an item from stack.
int pop()
{
  if(isEmpty()){
    return -1;
  }
	int temp = Stack[top];
  top-=1;
  mtop-=1;
  return temp;
}

// Function to return the minimum item from stack.
int mpop(){
  if(mtop<0){
    return -1;
  }
  int mmin = Min[mtop];
  return mmin;
}

int getMin()
{
  int ret = mpop();
	return ret;
}

int main()
{
	int t;
	printf("Enter the no. of elements you want to Enter\n");
	scanf("%d",&t);
	while(t!=0){
		int n;
		printf("Please enter 1 for push 2 for pop and 3 for getting current minimum\n");
		scanf("%d",&n);
		switch(n){
			case 1 : {
				int num;
				scanf("%d",&num);
				push(num);
				break;
			}
			case 2 : {
				int temp = pop();
				printf("%dNumber Popped out from the Stack is: \n",temp);
				break;
			}
			case 3 : {
				int min = getMin();
				printf("%dMinimum number present in the Stackm is: \n",min);
				break;
			}
			default : {
				printf("Please enter 1 for push 2 for pop and 3 for getting current minimum\n");
				break;
			}
		}
		t--;
	}
	return 0;
}