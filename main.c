#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float A[3][10];

void figure(char* fig, int num){
int k=0;

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
for(int i=k+1; (float)fig[i]>47 && (float)fig[i]<58;i++){
	k=i+1;
A[num][2]=A[num][2]*10+(int)fig[i]-48;
}

}
}



int main()
{
	int num=0;
char fig[20];
	scanf("%s", fig);
figure(fig,num);
printf("\n%f ", A[0][2]);
return 1;
}
