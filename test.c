#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include <stdarg.h>

float arithmetic(float a,float b,float (*op_func)(float,float))
{
    return (*op_func)(a,b);
}

float ADD(float a,float b)
{
    return a+b;
}

float SUB(float a,float b)
{
    return a-b;
}

float MUL(float a,float b)
{
    return a*b;
}

float DIV(float a,float b)
{
    if(b!=0.0)
        return a/b;
    else
        return 0;
}

void init_op(OP *op)
{
        op->p_add=ADD;
        op->p_sub=SUB;
        op->p_mul=MUL;
        op->p_div=DIV;
}

void testprintf(void)
{
    printf("test!\r\n");
}

void* threadprintf(void* args)
{
    int i;
    char* name=(char*)args;
    for(i=0;i<50;i++)
    {
        printf("%s:%d\n",name,i);
    }
    return NULL;
}

int vaArrayTest(int i,...)
{
    printf("total test!\n");
    int k=0;
    va_list ap;
    va_start(ap,i);
    for(int j=0;j<i;j++)
    {
        k+=va_arg(ap, int);
    }
     printf("total is %d\r\n",k);
     va_end(ap);
     return k;
    
}
