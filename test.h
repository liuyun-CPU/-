#ifndef _TEST_H_
#define _TEST_H_

void testprintf(void);
void* threadprintf(void* args);
typedef struct _OP{
    float (*p_add)(float,float);
    float (*p_sub)(float,float);
    float (*p_mul)(float,float);
    float (*p_div)(float,float);
} OP;

float ADD(float a,float b);
float SUB(float a,float b);
float MUL(float a,float b);
float DIV(float a,float b);

void init_op(OP *op);
float arithmetic(float a,float b,float (*op_func)(float,float));

int vaArrayTest(int i,...);
#endif