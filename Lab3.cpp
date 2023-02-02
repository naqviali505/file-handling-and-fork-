#include<unistd.h>
#include<iostream>
#include"Student.h"
#include<cstring>
#include<sstream>
#include<sys/wait.h>
#include<fcntl.h>
using namespace std;
void grading(Student &obj)
{
	if (obj.getmarks() >= 80 && obj.getmarks() <= 100)
		obj.setgrade('A');
	if (obj.getmarks() >= 70 && obj.getmarks() <= 79)
		obj.setgrade('B');
	if (obj.getmarks() >= 60 && obj.getmarks() <= 69)
		obj.setgrade('C');
	if (obj.getmarks() >= 50 && obj.getmarks() <= 59)
		obj.setgrade('D');
	if ( obj.getmarks() < 50)
		obj.setgrade('F');
}
int main(int argc,char** argv)
{
Student obj[5];
string str;
int marks;
char grade;
char buf[1000];
string  roll;
pid_t pid;
pid=fork();
if(pid<0)
cout<<"Unable to create any process"<<endl;
else if(pid==0)
{
int fileopen=open(argv[1],O_RDONLY);
if(fileopen==-1)
return 1;
else
{
int i=0;
int n=read(fileopen,buf,1000);
buf[n]='\0';
stringstream strs(buf);
while(strs>>roll)
{
obj[i].setrollno(roll);
strs>>marks;
obj[i].setmarks(marks);
strs>>grade;
obj[i].setgrade(grade);
i++;
}

//updating values
for(int j=0;j<i;j++)
{
grading(obj[j]);
}
for(int p=1,j=0;p<strlen(buf);p++)
{
//cout<<buf[p]<<endl;
if(buf[p-1]==' '&& buf[p]>='A' && buf[p]<='F')
{

buf[p]=obj[j++].getgrade();
}
}
int fd=open("Output.txt",O_WRONLY);
for(int j=0;j<5;j++)
{
write(fd,buf,sizeof(buf));
}
}
}
else if(pid>0)
{//Parent Process
wait(NULL);
int f=open("Output.txt",O_RDONLY);
if(f==-1)
return 1;
else
{
read(f,buf,sizeof(buf));
cout<<buf<<endl;


}
}
return 0;
}

