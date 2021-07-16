/*
 * @Author: your name
 * @Date: 2021-07-13 00:24:37
 * @LastEditTime: 2021-07-14 19:45:49
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /暑期课程2021/test/test1.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 5
char STR[100]="!@#$^&*(){}|[];<>?";
int len;
int main()
{
    srand(time(0));
    len=strlen(STR);
    for(int i=0;i<26;i++)
    STR[len+i]='a'+i,STR[len+26+i]='A'+i;
    len=strlen(STR);
    
    
    //for(;;)
    {
        char temp[100]={0};
        int r=rand()%20+1;
        for(int i=0;i<r;i++)
        temp[i]=STR[rand()%len];
        strcat(temp,".txt");
        FILE *fp=fopen(temp,"w");
        //freopen(temp,"w",stdout);
        for(int i=0;i<N;i++)
        {
            fprintf(fp,"warning\n");
        }
        fclose(fp);
    }
    return 0;
}