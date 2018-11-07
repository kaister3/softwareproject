#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#define size 100


char* classname[]={"语文","数学","英语"};
int N=0,falg=0; //定义全局变量 N代表人数，falg代表信息保存的标识。
int arrysize=size; //arrysize代表结构体数组的大小。
struct stu{
char num[10];
char name[10];
float score[3];
float sum;
};
typedef struct stu STU; //定义新类型的结构体。
STU*pro=NULL; // pro保存信息的结构体数组。


int chack(int a,int b,int c) //条件判断函数，c代表条件号。
{
	if(c==1||c==2)
	{
		if(pro[a].sum !=pro[b].sum )
		if(c==1)
 		return pro[a].sum >pro[b].sum ;
		else
		return pro[a].sum <pro[b].sum;
		else return strcmp(pro[a].num ,pro[b].num)<0;
	}
	if(c==3||c==4)
	{
 		if(c==3) return strcmp(pro[a].num,pro[b].num )<0;
	 	else return strcmp(pro[a].num,pro[b].num )>0;
	}
	else printf("没有该条件的选项!\n");
	return 0;
}


void incharge(int a,int b) //交换函数。
{
 	struct stu t;
	t=pro[a];
	pro[a]=pro[b];
	pro[b]=t;
}


void het(int m,int n,int c) //快排函数
{
	if(m>n) return;
	int i=m-1;
	for(int j=m;j<n;j++)
	{
		if(chack(j,n,c))
		incharge(++i,j);
	}
	incharge(i+1,n);
	het(1,i,c);
	het(i+2,n,c);
}


void newsect(int i) //添加记录函数
{ float s=0;
 printf("请输入学生学号:");
 scanf("%s",&pro[i].num);
 printf("请输入学生姓名:");
 scanf("%s",&pro[i].name);
 for(int j=0;j<3;j++)
{
 printf("请输入%s成绩:",classname[j]);
 scanf("%f",&pro[i].score[j]);
 s+=pro[i].score[j];
}
 pro[i].sum=s;
 falg=0;
}


void showlist()  //全体打印表函数
{ 
	if(N==0){printf("记录为空!\n");return;};
 	printf("\n┏┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┓\n");
	 printf("┃学号 姓名 总成绩 语文 数学 英语 ┃ \n");
 	for(int i=1;i<=N;i++)
 	{
 		printf("┃%-11s %-10s %-9.1f ",pro[i].num,pro[i].name,pro[i].sum);
 		for(int j=0;j<3;j++)
 		printf(j==2?"%-5.1f":"%-8.1f",pro[i].score[j]);
 		printf("┃\n");
 		if(i==N)
		printf("\n┗┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┛\n");
 	}
}


void showtable(int n)   //个体打印列表函数
{
	printf("\n┏┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┓\n");
 	printf("┃学号:%-11s姓名:%-10s总成绩:%-6.1f",pro[n].num,pro[n].name,pro[n].sum);
	for(int j=0;j<3;j++)
	{
		printf("%s:%-4.1f",classname[j],pro[n].score[j]);
		printf(" ┃ \n");
		printf("┗┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┛\n");
	}
}
int lookout( ) //查找函数
{
	int tar;
	char num[10],name[10];
	if(N==0)
	{
	printf("记录表为空!\n");
	return 0;
	}
	printf("1.按学号 2.按姓名\n请选择相应数字:");
	scanf("%d",&tar);
	getchar();
	if(tar!=1&&tar!=2)
	{
		printf("选择无效!\n");return 0;
	}
 	if(tar==2)
	{
		printf("请输入查找人的姓名:");
 		scanf("%s",&name);
 		for(int i=1;i<=N;i++)
		if(strcmp(name,pro[i].name)==0)
		{
			showtable(i);
		return i;
		}
	}
	else
	{
		printf("请输入查找人的学号:");
 		gets(num);
		for(int i=1;i<=N;i++)
			if(strcmp(num,pro[i].num)==0)
			{
				showtable(i);
				return i;
			}
	}
		printf("无该记录\n");
		return 0;
}


void copyrecored(STU *p,STU *q) //复制函数.
{
strcpy(q->num,p->num);
strcpy(q->name,p->name);
for(int j=0;j<3;j++)
q->score[j]=p->score[j];
 q->sum=p->sum;
}


void remove() //删除个人信息函数
{ int b;
 char tag[10];
if(N==0){
printf("记录表为空!\n");
return;
}
b=lookout();
if(b)
{
printf("是否要删除(y/n):");
 gets(tag);
if(tag[0]=='y'||tag[0]=='Y')
{
N--;
for(int j=b;j<=N;j++)
copyrecored(&pro[j+1],&pro[j]);
printf("删除成功！\n");
falg=0;
}
else printf("删除失败!\n");
}
}
void change() //修改个人信息函数
{ int m,k,f;
 if(N==0)
{printf("记录表为空!\n");return;}
 k=lookout();
 if(k)
 {
 printf("1.学号 2.姓名 3科目成绩 4.全部修改 0.退出\n请输入要修改的信息:");
scanf("%d",&f);
switch(f)
{
case 1:printf("请重新输入学号:");
 scanf("%s",&pro[k].num );falg=0;break;
case 2:getchar();
 printf("请重新输入姓名:");
 scanf("%s",&pro[k].name);falg=0;break;
case 3:printf("0.语文 1.数学 2.英语\n请选择科目:");
 scanf("%d",&m);
 if(m==0||m==1||m==2)
{
printf("请输入%s成绩:",classname[m]);
 scanf("%f",&pro[k].score[m]);
falg=0;
}
 else printf("输入无效!\n");
 pro[k].sum=pro[k].score[0]+pro[k].score[1]+pro[k].score[2];
 break;
case 4:newsect(k);break;
default:printf("修改失败!"); break;
}
 }
}


void save()  //文件保存函数
{
FILE *fp;
 char fname[30];
if(N==0)
{
printf("没有记录可存!\n");return;
}
loop:printf("请输入要存入的文件(直接回车保存在默认文件中):");
gets(fname);
if(strlen(fname)==0)
 strcpy(fname,"stu_info");
 if((fp=fopen(fname,"wb"))==NULL){
 printf("不能存入文件!\n");goto loop;
 }
 printf(" 文件保存中....\n");
 for(int i=1;i<=N;i++)
 if((fwrite(&pro[i],sizeof(STU),1,fp))==0)
 {printf("保存失败!\n");break;}
 fclose(fp);
 printf("文件已保存!\n");
 falg=1;
}


void loadrecords() //读取文件函数
{
FILE *fp;
void abc(int s);
char fname[10];
int c;
struct stu records[100];
printf("请输入要打开的文件名(直接回车打开默认文件):");
gets(fname);
if(strlen(fname)==0)
strcpy(fname,"stu_info");
if((fp=fopen(fname,"rb"))==NULL)
{
printf("文件打不开!\n");return;
}
printf("1.覆盖新建的信息 2.添加到新的信息中 3.查看保存的信息\n请选择:");
scanf("%d",&c);
if(c==3){
printf("\n┏┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┓\n");
 printf("┃学号 姓名 总成绩 语文 数学 英语 ┃ \n");
for(int i=0;fread(&records[i],sizeof(STU),1,fp)!=0;i++)
{
printf("┃%-12s% -11s% -9.1f ",records[i].num ,records[i].name,records[i].sum );
for(int j=0;j<3;j++)
printf(j==2?"%-5.1f":"%-8.1f",records[i].score [j]);
printf(" ┃\n");
}
printf("\n┗┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┛\n");
}
if(c==1){
abc(0);
for( N=1;fread(&pro[N],sizeof(STU),1,fp)!=0;N++);
N--;    //跳出循环，N实际比得到人数要大一，故要减一。
falg=0;
fclose(fp);
showlist();
}
if(c==2){falg=0;
for(++N;fread(&pro[N],sizeof(STU),1,fp)!=0;N++)
if(N>arrysize){
pro=(STU*)realloc(pro,sizeof(STU)*(arrysize+size));  //超出内存，就分配新的内存。
}
arrysize+=size;
N--;     //跳出循环，N实际比得到人数要大一，故要减一。
fclose(fp);
showlist();
}
}


void abc(int s) //信息保存判断函数 s代表要进行的相应操作。
{ char v[10];
if(N!=0&&falg!=1)
{
 printf("新建信息尚未保存!,继续将会使新建的信息消失,");
 printf("是否先保存(y/n):");
 while(1){
gets(v);
if(v[0]=='y'||v[0]=='Y') {save();break;}
if(v[0]=='n'||v[0]=='N') break;
else printf("输入有误!请重新输入:");
 }
}
if(s==1){
printf("请输入统计人的个数:");
 scanf("%d",&N);
gets(v); //消除违规数据。
for(int i=1;i<=N;i++)
 newsect(i);
}
else return;
}


void main() //主函数
{ char v[10];
 int choice,c;
pro=(STU*)malloc(size*sizeof(STU));
if(pro==NULL)
{
printf("内存分配出错!\n");
return;
}
printf("\t\t\t\t学生成绩管理系统\n\n");
do
{ choice=-1;
printf("\n0.新建\t\t1.添加\t\t\t2.查找\t3.删除\n4.列表输出\t5.排序\t\t\t6修改\n7.文件保存\t8.读取保存的记录文件\t9退出\n请选择相应的操作:");
scanf("%d",&choice);
gets(v);  //消除违规数据，防止变成死循环
switch(choice)
{case 0:abc(1);break;
case 1:++N;newsect(N);break;
case 2:lookout();break;
case 3:remove();break;
case 6:change();het(1,N,1);break;
case 5:if(N==0){printf("记录为空!\n");break;}
 else {printf("1.按成绩降序 2.按成绩升序 3.按学号升序 4.按学号降序\n请选择相应功能:");
 scanf("%d",&c);het(1,N,c);}
case 4:showlist();break;
case 7:save();break;
case 8:loadrecords();break;
case 9:abc(0);printf("谢谢使用!\n");break;
default:printf("选择无效!\n");break;
}
}
while(choice!=9);
}
