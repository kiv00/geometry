#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int figure(char* fig){

int k=0, swt;
   for(int i=0; fig[i]!='(';i++){
k++;
}
char check[k];
for(int i=0; i<k;i++){
   check[i]=fig[i];
}
if(!strcmp(check,"circle")){
 swt=1;
}
return swt;
}



int main()
{
char fig[20];
scanf("%s", fig);
int swt=figure(fig);
printf("%d", swt);
return 0;
}
