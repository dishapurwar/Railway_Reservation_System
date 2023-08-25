/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

 struct passenger{
    int id;
	char name[50];
	int age;
	char gen[50];
	int train_num;
	int num_of_seats;
}pd;

/*****************************FUNCTION PROTOTYPE**********************************************************/

void login();
void book(void);							                   //ticket booking function
void viewtrain(void);							               // to view details of all the trains
void cancel(void);								               //to cancel ticket
void print(int,char name[],int,char gen[],int,int,float);	   //to print ticket 
void particulartrain(int);						               //to print details of particular train
float charge(int,int);							               //to calculate total fare of the journey


/**************************************MAIN() FUNCTION DECLARATION*****************************************/

int main()
{
     
    printf("\t\t====================================================================\n");
	printf("\t\t|                                                                  |\n");
	printf("\t\t|     ------------------------------------------------------       |\n");
	printf("\t\t|     ************ RAILWAY RESERVATION  SYSTEM *************       |\n");
	printf("\t\t|     ------------------------------------------------------       |\n");
	printf("\t\t|                                                                  |\n");
    printf("\t\t====================================================================\n\n\n");

    login();                                      //function call
	int ch;	
	start:
	system("clear");
	printf("\n\n\t\t            *************  WELCOME USERS ***********\n\n");
	printf("\t\t=======================================================================");
	printf("\n\n");
	printf("\t\t             ||             MAIN MENU                  ||\n");
	printf("\t\t             ||----------------------------------------||\n");
	printf("\t\t             ||            [1] VIEW TRAINS             ||\n");
	printf("\t\t             ||            [2] BOOK A TICKET           ||\n");
	printf("\t\t             ||            [3] CANCEL TICKET           ||\n");
	printf("\t\t             ||            [4] BACK                    ||\n");
	printf("\t\t             ||            [5] EXIT                    ||\n");
	printf("\n\n");
	printf("\t\t========================================================================\n\n");
	printf("\n\t\t                  Enter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
				viewtrain();
				printf("\n\n\t\t                   Press Enter to go to Main Menu......");
			getchar();
			getchar();
			goto start;
			break;
			case 2:
				book();
				break;
				   case 3:
						cancel();
						break;
						case 4:
						system("clear");
						getchar();
			
						login();                                   //function call
						break;
						case 5:
						return(0);
						   default:
							getchar();
							printf("\n\t\t\t<<<<<<<<< INVALID CHOICE >>>>>>>>>>");
							
	}
							
		goto start;
		return 0;
	

}

/***********************************LOGIN() FUNCTION DECLARATION******************************************/

void login()
{
	char uname[10]; 
    char pword[10];
    char user[10]="user";
    char pass[10]="pass";
    
    	printf("\n\n\t\t            <<<<<<<<<<<<   LOGIN WINDOW   >>>>>>>>>>>             \n");
	printf("\t\t                   ****************************                   \n\n");
	printf("\t\t                  ENTER USERNAME:- ");
	scanf("%s",uname); 
	printf("\t\t                  ENTER PASSWORD:- ");
	scanf("%s",pword);
	if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
		printf("\n\n\t\t\t    <<<<<  YOUR LOGIN IS SUCCESSFULL  >>>>>");
	
		getchar();
	    
		
	}
	
	else
	{
		printf("\n\n\t\t\t\t   ERROR!!!!!");
		printf("\n\n\t\t\t          <<<<<  WRONG PASSWORD   >>>>>");
		printf("\n\n\t\t         Please Enter To Try Again   ");
		getchar();
		getchar();
		system("clear");
		main();                                            //function call
		
	}
	printf("\n\n     Press Enter to continue......");
	getchar();
	system("clear");
}
    
    /************************************VIEW TRAIN() FUNCTION DECLARATION************************************/

void viewtrain(void)
{
    system("clear");	
	printf("-----------------------------------------------------------------------------");	
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n101\tTejas Express\t\tLucknow to New Delhi\tRs.5000\t\t9am");
	printf("\n102\tTejas Express\t\tNew Delhi To Lucknow\tRs.5000\t\t12pm");
	printf("\n103\tGarib Rath Express\tLucknow To Raipur\tRs.2000\t\t8am");
	printf("\n104\tGarib Rath Express\tRaipur To Lucknow\tRs.2000\t\t11am");
	printf("\n105\tSabarmati Express\tLucknow To Ujjain\tRs.3000\t\t7am");
	printf("\n106\tSabarmati Express\tUjjain To Lucknow\tRs.3000\t\t9.30am");
    printf("\n107\tDurgiana Express\tLucknow To Kolkata\tRs.5500\t\t1pm");	
    printf("\n108\tDurgiana Express\tKolkata To Lucknow\tRs.5500\t\t4pm");
    
    
}

/***********************************BOOK() FUNCTION DECLARATION*******************************************/

void book(void)
{
    char confirm;
	int i=0;
	float charges;
	printf("\nEnter User ID :> ");
	scanf("%d",&pd.id);
	printf("\nEnter Your Name:> ");
	scanf("%s",pd.name);
	printf("\nEnter your age:> ");
	scanf("%d",&pd.age);
	printf("\nEnter your gender:> ");
	scanf("%s",pd.gen);
    printf("\nEnter Number of seats:> ");
	scanf("%d",&pd.num_of_seats);
	printf("\n\n\t\t           >> Press Enter To View Available Trains << ");
	getchar();
	getchar();
	system("clear");
	viewtrain();                                                                        //function call
	start: 
	printf("\n\nEnter train number:> ");
	scanf("%d",&pd.train_num);
	if(pd.train_num>=101 && pd.train_num<=108)
	{
		charges=charge(pd.train_num,pd.num_of_seats);                                    //function call
		print(pd.id,pd.name,pd.age,pd.gen,pd.num_of_seats,pd.train_num,charges);      	 //function call
	    }
	    else
	    {
	        printf("\n\t\t    Invalid Train Number !!  ");
	        printf("\n\t\t    Enter Correct Train Number ");
	        goto start;
	    }
	
	
	printf("\n\n\n\t\t To Confirm Ticket Enter 'Y' Or To Go back to main Menu Enter 'N' ---> ");
	
	start2:
	scanf(" %c",&confirm);
	if(confirm == 'Y')
	{
	    printf("=================================================================");
		printf("\n\t\t               Reservation Done\n");
		printf("=================================================================");
		printf("\n\nPress Enter to go back to Main menu");
	}
	else
	{
	    	if(confirm=='N')
	    	{
			printf("\n\t\t     Reservation Not Done!!!\n\t\t     Press Enter to go back to  Main menu!");
		}
		else
		{
			printf("\n\t\t     Invalid choice !!! Enter Again...... ");
			goto start2;
		}
	}
	getchar();
	getchar();
		
}

/**************************************CHARGE FUNCTION DECLARATION()********************************************/

float charge(int train_num,int num_of_seats)
{
		if (train_num==101)
	{
		return(5000.0*num_of_seats);
	}

	else if (train_num==102)
	{
		return(5000.0*num_of_seats);
	}
	
	else if (train_num==103)
	{
		return(2000.0*num_of_seats);
	}
	
	else if (train_num==104)
	{
		return(2000.0*num_of_seats);
	}
	else if (train_num==105)
	{
		return(3000.0*num_of_seats);
	}
	else if (train_num==106)
	{
		return(3000.0*num_of_seats);
	}
	else if (train_num==107)
	{
		return(5500.0*num_of_seats);
	}
	else if (train_num==108)
	{
		return(5500.0*num_of_seats);
	}
	
}

/***************************************PRINT FUNCTION DECLARATION()******************************************/

void print(int id,char name[],int age,char gen[],int num_of_seats,int train_num,float charges)
{
	system("clear");
	printf("|-------------------------------------------------------------|\n");
	printf("\t\t              TICKET                                     \n");
	printf("|-------------------------------------------------------------|\n\n");
	printf("User ID:\t\t%d",id);
	printf("\n\nName:   \t\t%s",name);
	printf("\n\nAge :    \t\t%d",age);
	printf("\n\nGender :    \t\t%s",gen);
	printf("\n\nNumber Of Seats:\t%d",num_of_seats);
	printf("\n\nTrain Number:\t\t%d",train_num);
	particulartrain(train_num);                                             //function call
	printf("\n\nCharges:\t\t%.2f",charges);
}

/**********************************PARTICULARTRAIN FUNCTION DECLARATION()*************************************/

void particulartrain(int train_num)
{
	
	if (train_num==101)
	{
		printf("\n\nTrain:\t\t\tTejas Express");
		printf("\n\nDestination:\t\tLucknow to Mumbai");
		printf("\n\nDeparture:\t\t9am ");
	}
	if (train_num==102)
	{
		printf("\n\nTrain:\t\t\tTejas Express");
		printf("\n\nDestination:\t\tMumbai to Lucknow");
		printf("\n\nDeparture:\t\t12pm");
	}
	if (train_num==103)
	{
		printf("\n\nTrain:\t\t\tGarib Rath Express");
		printf("\n\nDestination:\t\tLucknow to Raipur");
		printf("\n\nDeparture:\t\t8am");
	}
	if (train_num==104)
	{
		printf("\n\nTrain:\t\t\tGarib Rath Express");
		printf("\n\nDestination:\t\tRaipur to Lucknow");
		printf("\n\nDeparture:\t\t11am ");
	}
	if (train_num==105)
	{
		printf("\n\nTrain:\t\t\tSabarmati Express");
		printf("\n\nDestination:\t\tLucknow to Ujjain");
		printf("\n\nDeparture:\t\t7am");
	}
	if (train_num==106)
	{
		printf("\n\ntrain:\t\t\tSabarmati Express");
		printf("\n\nDestination:\t\tUjjain to Lucknow");
		printf("\n\nDeparture:\t\t9.30am ");
	}
	if (train_num==107)
	{
		printf("\n\ntrain:\t\t\tDurgiana Express");
		printf("\n\nDestination:\t\tLucknow to Kolkata");
		printf("\n\nDeparture:\t\t1pm ");
	}
	if (train_num==108)
	{
		printf("\n\ntrain:\t\t\tDurgiana Express");
		printf("\n\n Destination:\t\tKolkata to Lucknow");
		printf("\n\nDeparture:\t\t4pm ");
	}
	
}

/************************************CANCEL() FUNCTION DECLARATION****************************************/

void cancel(void)
{
    system("clear");
	int id;
	printf("\n\n------------------------------------------------------------------\n");
		printf("\n\t<<<<<<<<<<<<   CANCELLATION WINDOW   >>>>>>>>>>>             \n");
		printf("\n------------------------------------------------------------------\n");
	printf("\nEnter User ID:  ");
     scanf("%d",&id);
		printf("\n\n   <<<< Your Ticket Has Been Cancelled Successfully  >>>>");
		printf("\n\n     Press Enter to Go Back To Main Menu");
		getchar();
		getchar();
}





