#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float A[5][10];
int intersects[5][5];

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
if(strstr(check, "circle")!=0){
 A[num][1]=1;
}
if((int)A[num][1]==1){
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


void intersect(int num){
	float sum, ras;
	for(int i=0; i<num-1;i++){
		for(int j=i+1; j<num;j++){
			sum=A[i][4]+A[j][4];
			ras=sqrt((A[j][2]-A[i][2])*(A[j][2]-A[i][2])+(A[j][3]-A[i][3])*(A[j][3]-A[i][3]));
			if(ras<sum){
				intersects[i][j]=1;
				intersects[j][i]=1;
			}
		}
	}
}



int main(){
	int num=0,stop=0;
	float area[5], perimeter[5];
char fig[20];
	do{
	for(int i=0; fig[i-1]!=41;i++){
		scanf("%c", &fig[i]);
		if(fig[i]=='0'){
			stop=1;
			break;
		}
	}
figure(fig,num);
num++;
}while(stop==0);
for(int i=0;i<num-1;i++){
	for(int j=0; j<num-1; j++){
		intersects[i][j]=0;
	}
}
intersect(num-1);
for(int i=0;i<num-1;i++){
	if((int)A[i][1]==1){
		printf("%d. circle(%.2f %.2f, %.2f)\n",i+1,A[i][2],A[i][3],A[i][4]);
		area[i]=3.14*3.14*A[i][4];
		perimeter[i]=2*3.14*A[i][4];
    printf("perimeter = %.3f\narea = %.3f\nintersects:\n",perimeter[i],area[i]);
    for(int j=0;j<num-1;j++){
      if(intersects[i][j]==1){
      	if(A[j][1]==1){
      	printf("%d. circle\n", j+1);
      }
	  }	
	}
	printf("\n");
	}
}
return 1;
}
