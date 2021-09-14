#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<stddef.h>
#include"Headers.h"
int choice;
char login[20],cur_pass[12];
passenger *head;
//input, output functions for structures

void pass_setter()
{
FILE *fip;
fip=fopen("password.dat","r");
while(fgets(cur_pass,15,fip)!=NULL){;}
fclose(fip);
}

void change_pass()
{
char c_pass[15];
FILE *fip;
fip=fopen("password.dat","w");
system("cls");

	printf("\n\n\t\t\t\t\t\033[43;31m -----CHANGE PASSWORD-----  \033[0m\n");
	printf("\t\t\t\t\t\e[35;5m _________________________________\e[0m\n");
	printf("\n\t\t\t\t\t\e[0;1m Current Password :");
	scanf("%s",c_pass);
	if(!strcmp(c_pass,cur_pass))
{
	printf("\t\t\t\t\t\e[0;1m New Password :");
	scanf("%s",cur_pass);

	fputs(cur_pass,fip);
	fclose(fip);
	printf("\n\n\t\t\t\t\t\033[43;31m - PASSWORD CHANGED SUCCESSFULLY -  \033[0m\n");
	system("cls");
	runner();
}
	else if(strcmp(c_pass,cur_pass))
{	printf("\n\n\t\t\t\t\t\033[43;31m - Entered password is wrong!!! TRY AGAIN -  \033[0m\n");
	delay(2);
	change_pass();
}

	fclose(fip);
	printf("\t\t\t\t\t\e[35;5m ___________________________________________ \e[0m\n");
}
char *tooupper(char *string)
{
    int i=0;
    while(string[i]!='\0')
    {
        if(isalpha(string[i]))
            string[i]=toupper(string[i]);
        i++;
    }
    return string;
}
vehicle vinput(vehicle v)
{
	printf("Enter Details:\n");
	printf("Bus Number(UP64XX1011):");
	fgets(v.number_plate,20,stdin);
	strcpy(v.number_plate,tooupper(v.number_plate));
	printf("Driver Name:");
	fgets(v.Dname,30,stdin);
	printf("Contact No.(10 DIGITS):");
    fgets(v.cont_number,11,stdin);
	fflush(stdin);
	printf("Seats:");
	scanf("%s",v.seats);
	getchar();
	printf("Fare:");
	scanf("%f",&v.fare);
	getchar();
	printf("From:");
	fgets(v.from,20,stdin);
	printf("Departure Time:");
	fgets(v.dep_time,10,stdin);
	fflush(stdin);
	printf("To:");
	fgets(v.to,20,stdin);
	printf("Arrival Time:");
	fgets(v.arr_time,10,stdin);
	fflush(stdin);
	return v;
}
void voutput(vehicle v)
{
	printf("\nBus Number(UP64XX1011):%s",v.number_plate);
	printf("Driver Name:%s",v.Dname);
	printf("Contact No.:%s",v.cont_number);
	printf("\nNo. of seats:%s",v.seats);
	printf("\nFare:%f",v.fare);
	printf("\nFrom:%s",v.from);
	printf("Departure Time:%s",v.dep_time);
	printf("To:%s",v.to);
	printf("Arrival Time:%s\n",v.arr_time);

}

passenger pinput(passenger p)
{
	printf("Enter Passenger Details:\n");
	printf("User Id:");
	fgets(p.id,10,stdin);
	printf("Bus number:");
	fgets(p.bus_no,20,stdin);
	strcpy(p.bus_no,tooupper(p.bus_no));
	printf("Name:");
    fgets(p.name,30,stdin);
	fflush(stdin);
	printf("Contact Number(10 DIGITS):");
	fgets(p.cont_number,11,stdin);
	fflush(stdin);
	printf("Age:");
	scanf("%s",p.age);
	getchar();
	printf("Gender(f/m/o):");
	scanf("%s",p.gender);
	getchar();
	printf("Fare:");
	scanf("%f",&(p.fare));
	getchar();
	printf("Status:");
	fgets(p.status,20,stdin);
	fflush(stdin);
	return p;
}
void poutput(passenger p)
{
	printf("\n\nUser Id:%s",p.id);
	printf("Bus Number(UP64XX1011):%s",p.bus_no);
	printf("Name:%s",p.name);
	printf("Age:%s",p.age);
	printf("\nGender:%s",p.gender);
	printf("\nContact No.:%s",p.cont_number);
	printf("\nStatus:%s",p.status);
	printf("Fare:%f",p.fare);
}
char *chop(char *string)
{
    int i, len;
    len = strlen(string);
    if(string[len-1] == '\n')
    	string[len-1] = '\0';
 	return string;
}
int display_ticket(char *id)
{
	int found = 0;
	FILE *in;
	int count = 0;
	passenger p;
 	vehicle v,v1;
	passenger *cur;
	if(isempty(head))
	{
		return -1;
	}
	cur = head;
	printf("\nList is\n");
	while(1)
	{
		system("cls");
		if(cur == NULL)
			return -1;
		if(strcmp(cur->id,id)==0&&(strcmp(cur->status,"alloted\n")==0||strcmp(cur->status,"waiting\n")==0))
		{
			p = *cur;
			found = 1;
			in = fopen("Buses.dat","r");
			if(!in)
			{
				printf("\nError opened file\n");
				delay(3);
				return -1;
			}
			while(fread(&v,sizeof(vehicle),1,in))
			{
				if(strcmp(p.bus_no,v.number_plate)==0)
				{
					v1 = v;
					break;
				}
			}
			fclose(in);
			fflush(stdin);
			strcpy(p.name,chop(p.name));
			strcpy(v.from,chop(v.from));
			strcpy(v.to,chop(v.to));
			strcpy(v.dep_time,chop(v.dep_time));
			strcpy(v.arr_time,chop(v.arr_time));
			strcpy(p.status,chop(p.status));
			strcpy(v.number_plate,chop(v.number_plate));
    		printf("\n\n\t\t\t\t\t\033[43;31m~~~~~~~~~~~~~~~~~~~~TICKET~~~~~~~~~~~~~~~~~~~\033[0m\n");
    		printf("\t\t\t\t\t\e[0;93m|___________________________________________|\e[0m\n");
			printf("\t\t\t\t\t\e[0;93m ___________________________________________ \e[0m\n");
			printf("\t\t\t\t\t\e[0;93m|PASSENGER DETAILS-                        ⇆|\e[0m\n");
			printf("\t\t\t\t\t➼ Name    :%s                                      \n",p.name);
			printf("\t\t\t\t\t\e[0;93m|                                           |\e[0m\n");
			printf("\t\t\t\t\t➼ Gender  :%s                                    \n",p.gender);
			printf("\t\t\t\t\t\e[0;93m|                                           |\e[0m\n");
			printf("\t\t\t\t\t➼ Age     :%s                                       \n",p.age);
			printf("\t\t\t\t\t\e[0;93m|                                           |\e[0m\n");
			printf("\t\t\t\t\t➼ Ph. no. :%s                               \n",p.cont_number);
	  		printf("\t\t\t\t\t\e[0;93m|===========================================|\e[0m\n");
	   		printf("\t\t\t\t\t\e[0;93m|TRAVEL DETAILS-                           ⇆|\e[0m\n");
	   		printf("\t\t\t\t\t➼ From    :%s       ➼ To   :%s                \n",v.from,v.to);
			printf("\t\t\t\t\t\e[0;93m|                                           |\e[0m\n");
			printf("\t\t\t\t\t➼ Dtime   :%s       ➼ Atime:%s      \n",v.arr_time,v.dep_time);
			printf("\t\t\t\t\t\e[0;93m|                                           |\e[0m\n");
			printf("\t\t\t\t\t➼ Bus no.  :%s                              \n",v.number_plate);
    		printf("\t\t\t\t\t\e[0;93m|                                           |\e[0m\n");
			printf("\t\t\t\t\t➼ Status   :%s                              \n",p.status);
    		printf("\t\t\t\t\t\e[0;93m|___________________________________________|\e[0m\n");
    		printf("\t\t\t\t\t\e[0;93m|___________________________________________|\e[0m\n");
    		printf("\n\n\t\t\t\t\tPress Enter");
			found = 1;
			getchar();
		}
		cur=cur->next;
	}
	return found;
}
void new_booking(char *id)
{
			system("cls");
			passenger p;
			int found = 0;
			char number[20];
			vehicle v;
			FILE *in;
			int count = 0;
			int pcount = 0;
			in = fopen("Buses.dat","r");
			if(!in)
			{
				printf("\nError opened file\n");
				delay(3);
				return;
			}
			while(fread(&v,sizeof(vehicle),1,in))
			{
				count++;
				printf("\n%d)",count);
				printf("\nBus No.:%s",v.number_plate);
				printf("From:%sTo:%s",v.from,v.to);

				/*if(count > 0 && count % 3 == 0)
				{
					printf("\n\nPress enter to view more");
					getchar();
					system("cls");
				} */
			}
			fclose(in);
			strcpy(p.id,id);
			printf("\n\t\tNo more data");
			printf("\n\t\tPress Enter");
			getchar();
			printf("\n\n\tEnter Bus No. to book ticket:");
			fgets(number,20,stdin);
			strcpy(number,tooupper(number));
			in = fopen("Buses.dat","r");
			while(fread(&v,sizeof(vehicle),1,in))
				if(strcmp(v.number_plate,number) == 0)
				{
					found = 1;
				}
			fclose(in);
			if(found == 1)
			{
				system("cls");
				printf("\nEnter details");
				printf("\nName:");
   				fgets(p.name,30,stdin);
				fflush(stdin);
				printf("Contact Number(10 DIGITS):");
				fgets(p.cont_number,11,stdin);
				fflush(stdin);
				printf("Age:");
				scanf("%s",p.age);
				getchar();
				printf("Gender(f/m/o):");
				scanf("%s",p.gender);
				getchar();
				strcpy(p.bus_no,number);
				fflush(stdin);
				p.fare = 151;
				p.next = NULL;
				count = get_pcount(number);
				if(count<5)
				{
					strcpy(p.status,"alloted\n");
					appendl(&head,p);
					appendp(p);
				}
				else if(count>=5&&count<8)
				{
					strcpy(p.status,"waiting\n");
					appendl(&head,p);
					appendp(p);
				}
				else if(count>=8)
				{
					printf("\ncould not book limit exceeded");
					printf("\npress enter to go back");
					getchar();
				}
			}
			else
			{
				printf("\n\n\t\tNo Matching Bus found");
				printf("\n\n\t\tPress enter to go back");
				getchar();
				return;
			}
}
int cancel_ticket(char *id)
{
	FILE *out;
	int found = 0;
	char number[20];
	printf("\nEnter Bus NO:");
	fgets(number,20,stdin);
	strcpy(number,tooupper(number));
	if(isempty(head))
	{
		return 0;
	}
	int count=0;
	passenger *cur;
	passenger q;
 	cur = head;
	while(1)
	{
		if(cur == NULL)
		 	break;
		if(strcmp(cur->id,id)==0&&strcmp(cur->bus_no,number)==0)
			if(strcmp(cur->status,"alloted\n")==0||strcmp(cur->status,"waiting\n")==0)
			{
				strcpy(cur->status,"cancelled\n");
				printf("\n\t\tcancellation successful\n\n");
				poutput(*cur);
				printf("\n\nPress Enter to continue");
				getchar();
				found = 1;
				break;
			}
		cur=cur->next;
	}
	cur = head;
	while(1)
	{
		if(cur == NULL)
			break;
		if(strcmp(cur->bus_no,number)==0)
			if(strcmp(cur->status,"alloted\n")==0||strcmp(cur->status,"waiting\n")==0)
			{
				count++;
				if(strcmp(cur->status,"waiting\n")==0&&count<=5)
				strcpy(cur->status,"alloted\n");
			}
			cur=cur->next;
	}
	count = 0;
	out = fopen("temp.dat","w");
	cur = head;

	while (cur && fwrite(cur, offsetof(passenger,next),1,out) == 1)
	{
		cur = cur->next;
	}
	fclose(out);
	remove("Passenger.dat");
	rename("temp.dat","Passenger.dat");

	return found;
}
int isempty(passenger *front)
{
	if (front == NULL)
		{
			printf("%s\n","List is Empty:" );
			return 1;
		}
	else
		return 0;
}

void deleteList(passenger **head)
{

passenger *cur = *head;
passenger *next;

while (cur != NULL)
{
    next = cur->next;
    free(cur);
    cur = next;
}
}
void appendl(passenger **head,passenger p)
{
	passenger *new = (passenger*)malloc(sizeof(passenger));
	new = &p;
	passenger *cur;
	cur = *head;
	if(*head == NULL)
	{
		*head = new;
		return;
	}
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = new;
}
passenger *create_list()
{
	FILE *in;
	passenger p;
	passenger top;
	passenger *head;
	top.next = NULL;
	head = &top;
	int count = 0;
	in = fopen("Passenger.dat","r");
	if(!in)
	{
		printf("\nError opened file\n");
		delay(3);
		return NULL;
	}
	while(fread(&p,offsetof(passenger,next),1,in))
	{

		p.next = NULL;
		head->next =(passenger*) malloc(sizeof(passenger));
		*(head->next) = p;
		head = head->next;
	}
	fclose(in);
	return top.next;
}

int display(passenger *head)
{
	if(isempty(head))
	{
		return 0;
	}

	passenger *cur;
	passenger p;
	cur = head;
	printf("\nList is\n");
	int count=1;
	while(1)
	{

		if(cur == NULL)
			return 0;
        printf("\n\n\n\n%d",count++);
		poutput(*cur);
		cur=cur->next;

	}

}
int check(char *id,passenger *h)
{
	int flag = 0;
	if(isempty(h))
	{
		return -1;
	}

	passenger *cur;
	cur = h;
	while(1)
	{

		if(cur == NULL)
			break;
		//printf("\n%s",cur->id);
		if(strcmp(cur->id, id)==0)
			flag = 1;
		cur=cur->next;
	}
	return flag;
}
int get_pcount(char *number)
{
    char status[20];
    if(isempty(head))
	{
		return 0;
	}
	int count = 0;
	passenger *cur;
	passenger p;
	cur = head;
	while(cur != NULL)
	{
		if(strcmp(cur->bus_no,number)==0)
		{
		if((strcmp(cur->status,"alloted\n")==0)||(strcmp(cur->status,"waiting\n")==0))
			{
				count++;
			}
		}
		cur=cur->next;
	}
	return count;
}
void appendp(passenger q)
{
	system("cls");
	FILE *out;
	out = fopen("Passenger.dat","a");
	if(out == NULL)
	{
		printf("\nError opened file\n");
		delay(3);
		return;
	}
	printf("\n");
	fwrite(&q,offsetof(passenger,next),1,out);
	printf("\n\n\t\tBooked successfully");
	poutput(q);
	printf("\n\n\t\tPress enter to go back");
	getchar();
	fclose(out);
	return;
}
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
    	;
}

void runner()
{	pass_setter();
system("cls");
	printf("\n\n\t\t\t\t\t\033[43;31m WELCOME TO TICKET BOOKING SERVICE  \033[0m\n");
	printf("\t\t\t\t\t\e[35;5m _________________________________ \e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m1)Admin      \e[0m \t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m2)User        \e[0m\t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m3)Exit        \e[0m\t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|_________________________________|\e[0m\n");
	printf("\t\t\t\t\t\e[0;1mEnter your choice:");
	scanf("%d",&choice);

switch(choice)
{

	case 1:
		system("cls");
		admin();
		break;

	case 2:
		system("cls");
		user();
		break;

	case 3:
		system("cls");
		exit(0);
	default:
		printf("\n\n\t\t\t\t\t\e[0;1mWRONG INPUT!!! \n\n\t\t\t\t\t ENTER AGAIN");
		runner();

}
}
void admin()
{
int a;
a=admin_login();
if(a)
{
admin_menu();
}
}
int admin_login()
{
	system("cls");
char pass[12];
	printf("\n\n\t\t\t\t\t\033[43;31m -----LOG IN TO THE SYSTEM-----  \033[0m\n");
	printf("\t\t\t\t\t\e[35;5m _________________________________ \e[0m\n");
	printf("\n\t\t\t\t\t\e[0;1m USERNAME :");
	scanf("%s",login);
	printf("\t\t\t\t\t\e[0;1m PASSWROD :");
	scanf("%s",pass);
	printf("\t\t\t\t\t\e[35;5m _________________________________ \e[0m\n");
	if((!(strcmp(login,"admin")))&&(!(strcmp(pass,cur_pass))))
		return(1);
	else
	{
		printf("\n\n\t\t\t\t\t\e[0;1mWRONG CREDENTIALS \n\n\n");
		delay(3);
		admin_login();
	}
}


void admin_menu()
{
	adminmenu:
	system("cls");
	printf("\n\n\t\t\t\t\t\033[43;31m               ADMIN              \033[0m\n");
	printf("\t\t\t\t\t\e[35;5m _______________________________ \e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                               |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m1)Revenue    \e[0m \t\t\t\e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                               |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m2)Service Update\e[0m\t\t\e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                               |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m3)Passenger Info\e[0m \t\t\e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                               |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m4)change password\e[0m\t\t\e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                               |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m5)Back       \e[0m \t\t\t\e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|_______________________________|\e[0m\n");
	printf("\t\t\t\t\t\e[0;1mEnter your choice:");
	scanf("%d",&choice);
	getchar();
	switch(choice)
	{

		case 1:
			system("cls");
			fflush(stdin);
			head = create_list();
			float revenue = 0;
			if(isempty(head))
			{
				printf("no data");
			}
			else
			{
				passenger *cur;
				passenger p;
				cur = head;
				while(1)
				{

					if(cur == NULL)
						break;
					if(strcmp(cur->status,"alloted\n")==0||strcmp(cur->status,"waiting\n")==0)
						revenue += cur->fare;
					cur=cur->next;
				}
			}
			printf("\n\n\t\t\tRevenue = %f",revenue);
			printf("\n\n\t\t\tPress enter");
			getchar();
			goto adminmenu;

		case 2:
			system("cls");
			service_update();

		case 3:
			system("cls");
			fflush(stdin);
			head = create_list();
			display(head);
			printf("\n\n\t\tPress enter");
			getchar();
			deleteList(&head);
			goto adminmenu;

		case 4:
			system("cls");
			change_pass();
			break;

		case 5:
			system("cls");
			runner();
		default:
			printf("\n\n\t\t\t\t\t\e[0;1mWRONG INPUT!!! \t ENTER AGAIN");
			delay(3);
			admin_menu();

	}
}
void service_update()
{
	vehicle v;
	char check_no[20];
	int found = 0;
	service:
	system("cls");
	printf("\n\n\t\t\t\t\t\033[43;31m              UPDATE              \033[0m\n");
	printf("\t\t\t\t\t\e[35;5m _________________________________ \e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m1)Show Buses \e[0m \t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m2)Update        \e[0m\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m3)Add Bus     \e[0m \t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m4)Remove Bus     \e[0m\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m5)Back       \e[0m \t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|_________________________________|\e[0m\n");
	printf("\t\t\t\t\t\e[0;1mEnter your choice:");
	scanf("%d",&choice);
	getchar();
	switch(choice)
	{

		case 1:
			system("cls");
			FILE *in;
			int count = 0;
			in = fopen("Buses.dat","r");
			if(!in)
			{
				printf("\nError opened file\n");
				delay(3);
				goto service;
			}
			while(fread(&v,sizeof(vehicle),1,in))
			{
				voutput(v);
				count++;
				/*if(count > 0 && count % 3 == 0)
				{
					printf("\n\nPress enter to continue");
					getchar();
					system("cls");
				} */
			}
			printf("\nNo more data\nPress enter to go back");
			getchar();
			fclose(in);
			goto service;


		case 2:
			system("cls");
			printf("\nEnter Bus number to modify record:");
			fgets(check_no,20,stdin);
			strcpy(check_no,tooupper(check_no));
			in = fopen("Buses.dat","r+");
			if(!in)
			{
				printf("\nError opened file\n");
				delay(3);
				goto service;
			}
			while(fread(&v,sizeof(vehicle),1,in))
			{
				if (strcmp (check_no, v.number_plate) == 0)
				{
					printf("\n\n\t\tThe record with requested Bus number found.\n\n");
					voutput(v);
					printf("\n\nEnter new details:\n\n");
					v = vinput(v);
					fseek(in, -1*sizeof(vehicle), SEEK_CUR);
					fwrite(&v,sizeof(vehicle),1,in);
					printf("\n\nFile successfully Modified");
					printf("\nPress enter to go back");
					getchar();
					found=1;
					break;
				}
			}
				if (! found)
				{
					printf("No record(s) found with the given bus number: %s\n\n", check_no);
					printf("Press enter to go back");
					getchar();
				}
				fclose(in);
				goto service;

		case 3:
		    system("cls");
		    vehicle v2;
		    found=0;
			//FILE *in;
			FILE *out;
			//in = fread("Buses.dat")

			//v = vinput(v);
                printf("Enter Details:\n");
            printf("Bus Number(UP64XX1011):");
            fgets(v.number_plate,20,stdin);
           strcpy(v.number_plate,tooupper(v.number_plate));
            fflush(stdin);
            //printf("%sff",v.number_plate);
			in = fopen("Buses.dat","r");
			while(fread(&v2,sizeof(vehicle),1,in))
            {
                if(strcmp(v2.number_plate,v.number_plate)==0)
                {
                    found=1;
                    break;
                }
            }
            fclose(in);
            if(found==1)
            {
                printf("\n Bus already exists\n");
                printf("\nPress enter to go back");
                getchar();
            }
            else
            {
                printf("Driver Name:");
                fgets(v.Dname,30,stdin);
                printf("Contact No.(10 DIGITS):");
                fgets(v.cont_number,11,stdin);
                fflush(stdin);
                printf("Seats:");
                scanf("%s",v.seats);
                getchar();
                printf("Fare:");
                scanf("%f",&v.fare);
                getchar();
                printf("From:");
                fgets(v.from,20,stdin);
                printf("Departure Time:");
                fgets(v.dep_time,10,stdin);
                fflush(stdin);
                printf("To:");
                fgets(v.to,20,stdin);
                printf("Arrival Time:");
                fgets(v.arr_time,10,stdin);
                fflush(stdin);
                out = fopen("Buses.dat","a");
                if(out == NULL)
                {
                    printf("\nError opened file\n");
                    delay(3);
                    goto service;
                }
                printf("\n");
                fwrite(&v,sizeof(vehicle),1,out);
                printf("\n\nAdded successfully");
                printf("\nPress enter to go back");
                getchar();
                fclose(out);
            }
			goto service;

		case 4:
			system("cls");
			FILE *temp;
			printf("\nEnter Bus number to delete record:");
			fgets(check_no,20,stdin);
			strcpy(check_no,tooupper(check_no));
			in=fopen("Buses.dat", "r");
			if (!in)
			{
				printf("Unable to open file");
				delay(2);
				goto service;
			}
			temp=fopen("tmp.dat", "w");
			if (!temp)
			{
				printf("Unable to open file temp file.");
				goto service;
			}

			while (fread(&v,sizeof(vehicle),1,in))
			{
				if (strcmp (check_no, v.number_plate) == 0)
				{
					voutput(v);
					printf("\n\n\t\tThis record with requested Bus Number found and deleted.\n\n");
					printf("\n\n\t\tPress enter to continue");
					getchar();
					found=1;
				}
				else
				{
					fwrite(&v, sizeof(vehicle), 1, temp);
				}
			}
			if (! found)
			{
				printf("No record(s) found with the given bus number: %s\n\n", check_no);
				printf("\nPress enter to go back");
				getchar();
			}
			fclose(in);
			fclose(temp);
			remove("Buses.dat");
			rename("tmp.dat", "Buses.dat");
			goto service;

		case 5:
			system("cls");
			admin_menu();
		default:
			printf("\n\n\t\t\t\t\t\e[0;1mWRONG INPUT!!! \t ENTER AGAIN");
			goto service;
	}

}

void user()
{
	int flag = 0;
	user:

	system("cls");

	head = create_list();
	printf("\t\t\t\t\t\e[35;5m _________________________________ \e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m1)New User   \e[0m \t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m2)Old User    \e[0m\t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m3)Back        \e[0m\t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m4)Exit        \e[0m\t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|_________________________________|\e[0m\n");
	printf("\t\t\t\t\t\e[0;1mEnter your choice:");
	scanf("%d",&choice);
	getchar();
	switch(choice)
	{

		case 1:
			system("cls");
			printf("Enter a User Id:");
			fgets(login,20,stdin);
			if(check(login,head) == 1)
			{
				printf("User Id already exist");
				goto user;
			}
			else
				{
					system("cls");
					printf("\t\t\t\t\t\e[35;5m _________________________________ \e[0m\n");
					printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
					printf("\t\t\t\t\t\e[35;5m|\e[0;1m1)Book Ticket\e[0m \t\t\t  \e[35;5m|\e[0m\n");
					printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
					printf("\t\t\t\t\t\e[35;5m|\e[0;1m2)Back        \e[0m\t\t\t  \e[35;5m|\e[0m\n");
					printf("\t\t\t\t\t\e[35;5m|_________________________________|\e[0m\n");
					printf("\t\t\t\t\t\e[0;1mEnter your choice:");
					scanf("%d",&choice);
					getchar();
					switch(choice)
					{
						case 1:
							system("cls");
							new_booking(login);
							goto user;
						case 2:
							system("cls");
							goto user;
					}
				}
		case 2:
			system("cls");
			printf("\n\n\n\t\tEnter User Id:");
			fgets(login,20,stdin);
			if(check(login,head) == 1)
			{
				printf("\n\t\trecord found");
				printf("\n\t\tpress enter to continue");
				getchar();
				system("cls");
				old(login);
			}
			else
			{
				printf("\n\t\trecord not found");
				getchar();
				goto user;
			}

		case 3:
			system("cls");
			deleteList(&head);
			runner();
		case 4:
			system("cls");
			deleteList(&head);
			exit(0);
		default:
			printf("\n\n\t\t\t\t\t\e[0;1mWRONG INPUT!!! \n\n\t\t\t\t\t ENTER AGAIN");
			goto user;

	}

}
void old(char *id)
{
	old:
	//head = create_list();
	system("cls");
	printf("\t\t\t\t\t\e[35;5m _________________________________ \e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m1)New Booking\e[0m \t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m2)Show Tickets\e[0m\t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m3)Cancel      \e[0m\t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|                                 |\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|\e[0;1m4)Back        \e[0m\t\t\t  \e[35;5m|\e[0m\n");
	printf("\t\t\t\t\t\e[35;5m|_________________________________|\e[0m\n");
	printf("\t\t\t\t\t\e[0;1mEnter your choice:");
	scanf("%d",&choice);
	getchar();
	switch(choice)
	{

		case 1:
			new_booking(id);
			system("cls");
			user();

		case 2:
			system("cls");
			fflush(stdin);
			if(!display_ticket(id))
			{
				fflush(stdin);
				printf("\n\n\t\tNo booked tickets");
				getchar();
			}
			system("cls");
			goto old;

		case 3:
			system("cls");
			if(!cancel_ticket(id))
			{
				printf("\n\n\t\tNO matching record found\n\n\t\tPress enter");
				getchar();
			}
			system("cls");
			goto old;



		case 4:
			system("cls");
			user();
		default:
			printf("\n\n\t\t\t\t\t\e[0;1mWRONG INPUT!!! \n\n\t\t\t\t\t ENTER AGAIN");
			goto old;

	}
}
