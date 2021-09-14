#include<stdio.h>
void main()
{
FILE *filep;
char pass[20];
filep=fopen("password.dat","w");
printf("enter new password: ");
scanf("%s",pass);
fputs(pass,filep);
fclose(filep);
char rpass[20];
filep=fopen("password.dat","r");
while(fgets(rpass,20,filep)!=NULL)
{
;
}
printf("%s is set as new password\n",rpass);
fclose(filep);

}
