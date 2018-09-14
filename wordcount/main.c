#include <stdio.h>
#include <stdlib.h>

int main()
{
 int charcount(char *filename);
 int wordcount(char *filename);
 int linecount(char *filename);
 int emplinecount(char *filename);
 int comlinecount(char *filename);
 int codelinecount(char *filename);
 FILE *fp;
 int c_count,w_count,l_count,e_count,cm_count,cd_count;
 char ch[3],filename[100];
 printf("输入用户命令.exe ");
 scanf("%s %s",ch,filename);
 if((fp=fopen(filename,"r"))==NULL)
 {
     printf("filenull.\n");
     exit(-1);
 }
 //获取命令和输出
 if(ch[1]=='c')
 {
    c_count=charcount(filename);
    printf("charcalculate=%d\n",c_count);
 }
 if(ch[1]=='w')
 {
    w_count=wordcount(filename);
    printf("wordcalculate=%d\n",w_count);
 }
 if(ch[1]=='l')
 {
    l_count=linecount(filename);
    printf("linecalculate=%d\n",l_count);
 }
 if(ch[1]=='a')
 {
     e_count=emplinecount(filename);
     cm_count=comlinecount(filename);
     cd_count=codelinecount(filename);
     printf("emptyline=%d\ncommentline=%d\n",e_count,cm_count,cd_count);
 }
    return 0;
}

 int charcount(char *filename)//统计字符数
{
    int n1=0;
    char ch;
    FILE *fp;
    if((fp=fopen(filename,"r"))==NULL)
    {
        exit(-1);
    }
    ch=fgetc(fp);
    while(!feof(fp))
    {
        ch=fgetc(fp);
        n1++;
    }
    fclose(fp);
    return n1;
}
int wordcount(char *filename)//统计单词数
{
    int n2=0,word=0;
    char ch;
    FILE *fp;
    if((fp=fopen(filename,"r"))==NULL)
    {
        exit(-1);
    }
    ch=fgetc(fp);
    while(!feof(fp))
    {
        ch=fgetc(fp);
        if(ch<'A'||(ch>'Z'&&ch<'a')||ch>'z')
            word=0;
        else if(word==0)
        {
            word=1;
            n2++;
        }
    }
    fclose(fp);
    return n2;
}
int linecount(char *filename)//统计行数
{
    int n3=0;
    char ch,lc=0;
    FILE *fp;
    if((fp=fopen(filename,"r"))==NULL)
    {
        exit(-1);
    }
    ch=fgetc(fp);
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')
            n3++;
        lc=ch;
    }
    fclose(fp);
    if(lc!='\n')
        n3++;
    return n3;
}
int emplinecount(char *filename)//统计空行数
{
    int n4=0,len;
    char *str;
    FILE *fp;
    if((fp=fopen(filename,"r"))==NULL)
    {
        exit(-1);
    }
    while((fgetc(fp))!=EOF)
    {
    fgets(str,sizeof(str),filename);
    if(str[0]=='\n'||str[0]=='{'||str[0]=='}')
        n4++;
    }
    fclose(fp);
    return n4;
}
int comlinecount(char *filename)//统计注释行数
{
    int n5=0,len,i;
    char *str;
    FILE *fp;
    if((fp=fopen(filename,"r"))==NULL)
    {
        exit(-1);
    }
    while((fgetc(fp))!=EOF)
    {
        fgets(str,sizeof(str),filename);
        len=sizeof(str);
        for(i=0;i<len;i++)
        {
            if(str[i]=='/'&&str[i+1]=='/')
                n5++;
        }
    }
    fclose(fp);
    return n5;
}
int codelinecount(char *filename)//统计代码行
{
    int n6,n4,n5;
    FILE *fp;
    if((fp=fopen(filename,"r"))==NULL)
    {
        exit(-1);
    }
    n4=emplinecount(filename);
    n5=comlinecount(filename);
    n6=linecount(filename);
    n6=n6-n4-n5;
    fclose(fp);
    return n6;
}

