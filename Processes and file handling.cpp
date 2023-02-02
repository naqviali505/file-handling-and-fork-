#include<unistd.h>
#include<iostream>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<cstring>
using namespace std;
void removeoccurences(char buff[])
{
for(int i=0;i<strlen(buff);i++)
{
if(buff[i]=='@' || buff[i]=='"' || buff[i]=='&' || buff[i]=='#' || buff[i]=='$' || buff[i]=='*'|| buff[i]=='%')
{
buff[i]=' ';
}
}
}
int main(int argc,char *argv[])
{
int fid1[2],fid2[2];
pid_t pid;
char buf[50];
if(pipe(fid1)<0)
{
cout<<"Pipe1 creation failed"<<endl;
return 1;
}
if(pipe(fid2)<0)
{
cout<<"Pipe2 creation failed"<<endl;
}
pid=fork();
if(pid<0)
{
cout<<"Neither child nor parent process is created"<<endl;
return -1;
}
else if(pid!=0)

{//File Handling through system calls
int fopen=open(argv[1], O_RDONLY);
read(fopen, buf, sizeof (buf));
close(fid1[0]);
write(fid1[1],buf,sizeof(buf));
close(fid1[1]);


wait(NULL);//Wait for child process


int fopen1=open("updated.txt",O_WRONLY|O_CREAT,000777);
close(fid2[1]);
read(fid2[0],buf,sizeof(buf));
close(fid2[0]);
write(fopen1,buf,strlen(buf));
close(fid2[1]);
}
else if(pid==0)
{
close(fid1[1]);
read(fid1[0],buf,sizeof(buf));
close(fid1[0]);
removeoccurences(buf);
close(fid2[0]);
write(fid2[1],buf,sizeof(buf));
close(fid2[1]);
}
return 0;
}
