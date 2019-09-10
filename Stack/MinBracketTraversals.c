/*

Find the minimum bracket reversals for balanced expression

Given an expression having only square brackets ‘[‘ and ‘]’. Find the minimum number of brackets reversals required to make the expression balanced. If expression cannot be made balanced, print -1 and if it is already balanced, print 0.



Input

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case contains an expression consisting of square brackets only.

Output

The output for each test case will be the minimum number of bracket reversals required to make the expression balanced if possible.

Sample Input 1

2
2 //size of the expression
[]
2 //size of the expression
][
Sample Output 1

0
2
Explanation 1

First expression is already balanced, so print 0.
Second expression requires 2 reversals (both the brackets needs to be changed as []) so prints 2.
Sample Input 2

1
4
[[[[
Sample Output 2

2
*/
#include<stdio.h>
#include<string.h>

#define SIZE 

int Stack[SIZE],top = -1;
int bcount = 0;
int fcount = 0;

void push(int data){
  Stack[++top] = data;
}

int pop(){
  if(top==-1){
    return -1;
  }
  int temp = Stack[top];
  top-=1;
  return temp;
}

int minReversal(char* expr)
{
  int n = strlen(expr);
  if(n%2==1){
    return -1;
  }
  for(int i=0;i<n;i++){
    if(expr[i]=='['){
      push(0);
      ++fcount;
    }
    if(expr[i]==']'){
      int val = pop();
      if(val==-1){
        ++bcount;
      }
      else{
        --fcount;
      }
    }
  }
  if(bcount==0){
    return fcount/2;
  }
  else if(fcount==0){
    return bcount/2;
  }
  else{
    return (fcount+bcount)/2+1;
  }
}
int main(){
	int t;
	scanf("%d",&t);
	while(t!=0){
		int n;
		scanf("%d",&n);
		char str[n+1];
        scanf("%[^\n]%*c", str);
		int ret = minReversal(str);
		printf("%d\n",ret);
		t--;
	}
	return 0;
}