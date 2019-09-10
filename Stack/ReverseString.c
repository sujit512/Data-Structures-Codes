/*
Reverse a string using stack

 By : Girdhar Gopal   
Given a string, your task is to reverse it using stack.

Input

The first line of input will contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s without spaces.

The function void reverseString() takes the string as input and return the reversed string using stack provided.

Output

For each test case, you have to reverse the string in the array given. You are required to complete the methods given only.

Sample Input

1 // No. of test cases
2 // No. of strings
CodeQuotient
Code
Sample Output

tneitouQedoC
edoC﻿
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

int push(int item)
{
  if (isFull())
  {
    return -1;
  }
  Stack[++top] = item;
}

int pop()
{
  int temp;
  if (isEmpty())
  {
    return -1;
  }
  temp=Stack[top--];
  return temp;
}

char* reverseString(char *s)
{	int len = strlen(s);
	char *str = malloc(len*sizeof(char));
 	for(int i=0;i<len;i++){
      push(s[i]);
    }
 	for(int i=0;i<len;i++){
      str[i] = pop();
    }
 return str;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t!=0){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			char str[20]; 
   			gets(str);
   			char *s = reverseString(str);
   			printf("%s",s);
		}
		t--;
	}
	return 0;
}

