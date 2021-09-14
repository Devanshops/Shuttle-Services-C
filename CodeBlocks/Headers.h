typedef struct vehicle //structure which defines  vehicle info.
{
	char number_plate[20];
	char Dname[30];
	char cont_number[11];
	char from[20];
	char to[20];
	char arr_time[10];
	char dep_time[10];
	char seats[5];
	float fare;

}vehicle;
typedef struct passenger //structure which defines passenger info.
{
	char id[10];
	char bus_no[20];
	char name[30];
	char gender[2];
	char cont_number[11];
	char status[20];
	char age[5];
	float fare;
	struct passenger *next;
}passenger;
char *tooupper(char*); // function to convert alphabets in a string to upper case.
vehicle vinput(vehicle ); //function to input vehicle details.
void voutput(vehicle );   //function to print all the details of vehicle.
passenger pinput(passenger ); //function to input passenger details.
void poutput(passenger ); //function to print all the details of passenger.
char *chop(char *);
int display_ticket(char *);
void new_booking(char *);
int cancel_ticket(char *);
int isempty(passenger *); //function to check if the list of passengers is empty or not.
void deleteList(passenger **); //function to delete the entire list of passengers.
void appendl(passenger **,passenger );
passenger *create_list(); //function to create list of passenger from file.
int display(passenger *); //function to display details of all passenger in the present queue.
int check(char *,passenger *); //function to check if passenger is registered or not.
int get_pcount(char *);
void appendp(passenger );
void delay(int ); //function to pause the program for a while.
void runner();     //function to initiate main screen.
void admin();     //function t check and initiate admin login.
int admin_login(); //function to check admin login credentials.
void admin_menu(); //function to avail admin services.
void service_update(); //function to deal with data files related to vehicles.
void user();      //function to print user menu and avail all the services.
void old(char *);














