#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float A[3][10];

void figure(char* fig, int num){
int k=0, yes=0;
float metka=1;

   for(int i=0; fig[i]!='(';i++){
k=i+1;
}
char check[k];
for(int i=0; i<k;i++){
   check[i]=fig[i];
}
if(strcmp(check,"circle@")==0){
 A[num][1]=1;
}
if(A[num][1]==1){
	A[num][2]=0;
	A[num][3]=0;
	A[num][4]=0;
	yes=0;
	metka=1;
for(int i=k+1; (float)fig[i]>45 && (float)fig[i]<58;i++){
	k=i+1;
if(fig[i]>47){
A[num][2]=A[num][2]*10+(float)fig[i]-48;
metka/=10;
}else {
yes=1;	
metka=1;
}
}
if(yes==1){
A[num][2]=A[num][2]*metka;
}
yes=0;
metka=1;
for(int i=k+1; (float)fig[i]>45 && (float)fig[i]<58;i++){
	k=i+1;
if(fig[i]>47){
A[num][3]=A[num][3]*10+(float)fig[i]-48;
metka*=10;
}else {
yes=1;
metka=1;
}
}
if(yes==1){
A[num][3]=A[num][3]/metka;
}
yes=0;
metka=1;
for(int i=k+2; (float)fig[i]>45 && (float)fig[i]<58;i++){
	k=i+1;
	if(fig[i]>47){
A[num][4]=A[num][4]*10+(float)fig[i]-48;
metka*=10;
}else {
	yes=1;
metka=1;
}
}
if(yes==1){
A[num][4]=A[num][4]/metka;
}
yes=0;
metka=1;
}
}




int main(){
	int num=0,stop=0;
char fig[20];
	do{
	for(int i=0; fig[i-1]!=')' || fig[i-1]!='0';i++){
		scanf("%c", &fig[i]);
		if(fig[i-1]=='0'){
			stop=1;
			break;
		}
	}
figure(fig,num);
num++;
}while(stop==0);
for(int i=0;i<num;i++){
	if((int)A[i][1]==1){
		printf("%d circle(%.2f %.2f, %.2f)\n",i,A[i][2],A[i][3],A[i][4]);
	}
}
return 1;
}
