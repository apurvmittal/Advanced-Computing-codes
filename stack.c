//Author: Apurv Mittal

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

int N;
int ptr0 = 0; 
int ptr1 = 0;
#define EMPTY -2 
 
int push(int a, int b, int *stack)
{
  if(N == ptr0+ptr1)
    return -1;
  else
  {
    if(a == 0)
    {
      stack[ptr0] = b;
      ptr0 += 1;
    }
    else
    {
      stack[N-ptr1-1] = b;
      ptr1 += 1;
    }
   return 1;
  }
}

int isEmpty(int a, int *stack)
{
  if(a == 0)
  {
    if(stack[0] == EMPTY)
      return 1;
    else 
      return 0;
  }
  else
  {
    if(stack[N-1] == EMPTY)
      return 1;
    else
      return 0;  
  } 
}

int peek(int a, int *stack)
{
  if(isEmpty(a,stack))
    return -1;
  else
  {
    if(a == 0)
      return stack[ptr0-1];
    else
      return stack[N-ptr1];
  }
}

int pop(int a, int *stack)
{
  int data;
  if(isEmpty(a,stack))
    return -1;

 else
  {
    if(a == 0)
    {
      data = stack[ptr0-1];
      ptr0 -= 1;
      if(ptr0 == 0)
        stack[0] = EMPTY;
    }
    else
    {
      data = stack[N-ptr1];
      ptr1 -= 1;
      if(ptr1 == 0)
        stack[N-1] = EMPTY;
    }
   return data;
  }
}

//int push(int,int,int*); 
int main(int argc, char **argv)
{
  
  char line[20];
  int r,t,d,i,status;

  if(argc != 2){
	printf("Enter the command with appropriate input file\n");
	exit(-1);
  }
  
  FILE *fp = fopen(argv[1],"r");
  if(fp == NULL){
	printf("The input file %s does not exist\n", argv[1]);
  }
  
  fgets(line, 20, fp);
  sscanf(line,"%d", &r);
  N = r;
  int stack[N];
  for(i=0; i<N; i++){
	stack[i] = EMPTY;
  }
  
  while(fgets(line, 20, fp) != NULL){
 	sscanf(line,"%d %d %d", &r, &t, &d);
   	switch(r){
		case 0: status = push(t, d, stack); printf("%d\n", status); break;
 		case 1: status = pop(t, stack); printf("%d\n",status); break;
		case 2: status = peek(t, stack); printf("%d\n",status); break;
		case 3: status = isEmpty(t, stack); printf("%d\n",status); break;
	}
  }
  fclose(fp);
  return 0;
}

