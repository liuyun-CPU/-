#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>

#include "test.h"
#include ".\serialport.h"
#include "arraytest.h"
#include ".\filetest.h"

#define printk(...) printf(__VA_ARGS__);\
					printf("\n")
// 
int s=0;
int s1=0;
pthread_mutex_t lock;
void* myfunc(void* args)
{
	int i=0;
	for(i=0;i<100000;i++){
		s++;
	}
	return NULL;
}

void* myfunclock(void* args)
{
	pthread_mutex_lock(&lock);
	int i=0;
	for(i=0;i<100000;i++){
		s1++;
	}
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main(int argc,const char *argv[])
{
	printf("start!\r\n");
	// //测试gcc -o hello  ./hello.c ./test.c
    // testprintf();

	// //测试回调函数
    // OP *op=(OP *)malloc(sizeof(OP));
    // init_op(op);
    // printf("ADD=%f,\tSUB=%f,\tMUL=%f,\tDIV=%f\n",(op->p_add(1.3,2.2)),(op->p_sub(1.3,2.2)),(op->p_mul(1.3,2.2)),(op->p_div(1.3,2.2)));
    // printf("callback function test:\r\n");
    // printf("ADD=%f,\tSUB=%f,\tMUL=%f,\tDIV=%f\n",(arithmetic(1.3,2.2,op->p_add)),(arithmetic(1.3,2.2,op->p_sub)),(arithmetic(1.3,2.2,op->p_mul)),(arithmetic(1.3,2.2,op->p_div)));
    // printf("div=%f,\tdiv=%f\n",(op->p_div(1.3,0)),(arithmetic(1.3,0,op->p_div)));
    
	// //测试串口
    // HANDLE h = openSerialPort("COM4",B115200,one,off);
	// char at[] = "hello world\r\n";
	// char readbuffer[1024];
	// int bytesRead;
	// /*把数据发送至串口*/
	// //writeToSerialPort(h,at,strlen(at));
	// /*阻塞式，等待接收到数据*/
	// bytesRead = readFromSerialPort(h,readbuffer,1024);
	// readbuffer[bytesRead]='\0';
	// printf("%s\n",readbuffer);
	// /*关闭串口*/
	// closeSerialPort(h);

	//测试多线程
	pthread_t th1;
	pthread_t th2;
	pthread_t th3;
	pthread_t th4;

	pthread_mutex_init(&lock,NULL);
	// pthread_create(&th1,NULL,threadprintf,"th1");
	// pthread_create(&th2,NULL,threadprintf,"th2");

	pthread_create(&th1,NULL,myfunc,NULL);
	pthread_create(&th2,NULL,myfunc,NULL);

	pthread_create(&th3,NULL,myfunclock,NULL);
	pthread_create(&th4,NULL,myfunclock,NULL);

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);
	pthread_join(th4,NULL);

	printf("s=%d,s1=%d\n",s,s1);

	// setbuf(stdin,NULL);
	// int num1,num2;
	// scanf("%d,%d\r\n",&num1,&num2);
	// printf("num1=%d,num2=%d\r\n",num1,num2);

	// printf("argc=%i\r\n",argc);
	// printf("argv=%s\r\n",argv[0]);
	// printf("argv=%s\r\n",argv[1]);
	// Sleep(2000);
	// printk("test");

	 //int d= vaArrayTest(4,1,2,3,4);
	// printf("d is %d\r\n",d);

	// FileRW();
	// int a=0;
	// char *b;
	// int *c=&a;
	// printk("\r\nc=%d,%d",c,c+5);
	// printk("b=%d,%d",b,b+5);
	// int a=2;
	// int b=3;
	// a=a^b;
	// b=b^a;
	// a=a^b;
	// printk("a=%d\tb=%d",a,b);
	int d=0;
	float e=0;
	float (*test_func)(float input1,float input2);
	for(d=0;d<4;d++)
	{
		switch(d)
		{
			case 0: test_func=ADD;break;
			case 1: test_func=SUB;break;
			case 2: test_func=MUL;break;
			case 3: test_func=DIV;break;
			default:break;
		}
		e=test_func(1.2,3.3);
		printk("d is %d and e is %f",d,e);
	}
	return 0;
}
