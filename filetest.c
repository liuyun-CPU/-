#include <stdio.h>
#include <string.h>
//const int ReadLength =1000;
#define ReadLength 1000
void FileRW(void)
{
    FILE *fil;
    const char* content="hello world!";
    char content1[15]="lwj said hello";
    char readbuff[ReadLength];
    fil=fopen("test1.txt","a+");
    int length=strlen(content);
    int length1=sizeof(content1)/sizeof(content1[0]);
    //printf("length = %d\r\n",length);
    //int len=sizeof(content)/sizeof(content[0]);
    if(fil!=NULL)
    {
        puts("create ok");
        //fwrite(content1,sizeof(content1[0]),length1,fil);
        fwrite(content,sizeof(content[0]),length,fil);
        fclose(fil);
    }

    fil=fopen("test1.txt","r");
    if(fil!=NULL)
    {
        int readlen=fread(readbuff,sizeof(char),ReadLength,fil);
        printf("read num is %d\r\n",readlen);
        puts(readbuff);
        //fclose(fil);
    }
//逆序输出
    puts("file rw end!");
    fseek(fil,0,SEEK_END);
    long int size=ftell(fil);
    for(long int i=1;i<=size;i++)
    {
        fseek(fil,-i,SEEK_END);
        char ch=getc(fil);
        putchar(ch);
}

    fclose(fil);
    //rename("test1.txt","test2.md");
}

void FileIO(void)
{

}