/*
 ============================================================================
 Name        : pointer.c
 Author      : aman
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int Fadd(int *pa,int *pb)
{
	int sum=0;
	sum=*pa + *pb;
	return sum;
}
int main(void) {
	int a =2;
	int b =3;
	printf(" sum is %d",Fadd(& a,&b));
	return 0;
}
