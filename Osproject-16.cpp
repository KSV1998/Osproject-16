#include<conio.h>
#include<iostream>
using namespace std;
int at[50], bt[50], ct[50]={0}, qt, ready_que[50]={0}, c=0, st, flag_set=0, tm=0, noe=0, p=0, btm[50]={0}, tt, wt,a,b;
float att, awt;
int jk;
void s_stack(int p, int tm){
for(a=p+1;a<jk;a++){
int fl=0;
for(b=0;b<noe;b++)
if(ready_que[b]==a+1)
fl++;
if(at[a]<=tm && fl==0 && btm[a]!=0){
ready_que[noe]=a+1;
noe++;}
}
}
void f_stack(int p,int tm){
for(a=p+1;a<jk;a++){
if(at[a]<=tm){
ready_que[noe]=a+1;
noe++;}
}
}
void push_Que(int p){
ready_que[noe]=p+1;
noe++;
}
main()
{
printf("\n\t\tRound Robin Scheduling Algorithm.......\n\n");
printf("Attributes Used are :\n\t Arrival Time:AT\tBurst Time:BT\n\n");
printf("Enter The Number of Processes to Schedule : ");
scanf("%d",&jk);
for(a=0;a<jk;a++){
printf("\nValues of Process P%d :",a+1);
printf("\n\tAT :");
scanf("%d",&at[a]);
printf("\tBT :");
scanf("%d",&bt[a]);
btm[a]=bt[a];}
printf("\nEnter time quantum :");
scanf("%d",&qt);
system("CLS");
printf("\nGANTT CHART\n |%d",at[0]);
do{
if(flag_set==0){
st=at[0];
if(btm[0]<=qt){
tm=st+btm[0];
btm[0]=0;
f_stack(p,tm);}
else{
btm[0]=btm[0]-qt;
tm=st+qt;
f_stack(p,tm);
push_Que(p);}
}
else{
p=ready_que[0]-1;
st=tm;
for(a=0;a<noe && noe!=1;a++)
ready_que[a]=ready_que[a+1];
noe--;
if(btm[p]<=qt){
tm=st+btm[p];
btm[p]=0;
s_stack(p, tm);}
}
