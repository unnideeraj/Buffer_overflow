#include<stdio.h> 
#include<stdlib.h> 
void func2() 
{ 
int a; 
printf("Inside func2\n"); 
exit(0); 
} 
void func3() 
{ 
printf("Inside func3()\n"); 
exit(0); 
} 
void func() 
{ 
char b[10]; 
scanf("%s",b); 
} 
void main() 
{ 
int a,b; 
scanf("%d%d",&a,&b); 
func(); 
int c=a+b; 
}

// compile with flags: ' gcc prog.c -fno-stack-protector -g -no-pie '