#include<stdlib.h>

struct testlink
{
   // int key;
    int value;
    struct testlink *next;
};
typedef struct testlink TEST;

char* smallestSubsequence(char* s) {
        int a[26]={0};
        int len=strlen(s);
        if(len==0)
        return 0;
        char *b=(char*)malloc(27 * sizeof(char));
        for(int i=0;i<len;i++)
        {
            a[s[i]-'a']++;
        }
        int pos=0;
        for(int i=0;i<26;i++)
        {
            if(a[i]!=0)
            {
                b[pos]=i+'a';
                pos++;
            }
        }
        b[pos]='\0';
        return b;
    }


// void main(void)
// {
//     // TEST a,b,c,*h,*p;
//     // a.value=10;
//     // b.value=20;
//     // c.value=30;
//     // h=&a;
//     // a.next=&b;
//     // b.next=&c;
//     // c.next='\0';
//     // p=h;
//     // while(p)
//     // {
//     //     printf("%d\t",p->value);
//     //     p=p->next;
//     // }
//     // printf("\r\n");
//     char *s="cbacdcbc";
//     char *d;
//     d=smallestSubsequence(s); 
//     printf("ok");
// }
