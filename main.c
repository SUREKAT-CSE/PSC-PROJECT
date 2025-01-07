#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DATA_FILE "airline.txt"
int dp1[100]={0},dp2[100]={0},dp3[100]={0},dp4[100]={0},dp5[100]={0},dp6[100]={0},dp7[100]={0},dp8[100]={0},dp9[100]={0};
typedef struct
{
    char name[100];
    char dateofbirth[10];
    int phnumber;
    char email[100];
    char destination[100];
    char classservice[20];
    int seatnumber;
    int passportnumber;
    char mealpreference[10];
    int airlinenumber;
    int departuretime;
    int arrivaltime;
    int route;
    int flightticketnumber;
}Airline;
int generateflightticketnumber()
{
    static int ticketnumber=2501001;
    return ++ticketnumber;
}
void bookticket()
{   Airline airline;
    int nseats;
    printf("Number of tickets to be booked:");
    scanf("%d",&nseats);
    for(int i=1;i<=nseats;i++)
    {
    airline.flightticketnumber=generateflightticketnumber();
    printf("TICKET NUMBER:%d\n",airline.flightticketnumber);
    printf("Name:");
    scanf("%s",airline.name);
    printf("Date of birth(00.00.0000):");
    scanf("%s",airline.dateofbirth);
    printf("Phone number:");
    scanf("%d",&airline.phnumber);
    printf("Email:");
    scanf("%s",airline.email);
    printf("Passport number:");
    scanf("%d",&airline.passportnumber);
    printf("Destination(Tokyo/Dubai/Paris):");
    scanf("%s",airline.destination);
    printf("Class of service(economy/business/first class):");
    scanf("%s",airline.classservice);
    if(airline.destination=="Tokyo")
    {
        if(airline.classservice=="economy")
        {
            checkseatsavailable(dp1);
            printf("Seat number:");
            scanf("%d",&airline.seatnumber);
            if(dp1[airline.seatnumber]==0)
            {
                dp1[airline.seatnumber]++;
            }

        }
        else if(airline.classservice=="business")
        {
            checkseatsavailable(dp2);
            printf("Seat number:");
            scanf("%d",&airline.seatnumber);
            if(dp2[airline.seatnumber]==0)
            {
                dp2[airline.seatnumber]++;
            }

        }
        else if(airline.classservice=="first class")
        {
            checkseatsavailable(dp3);
            printf("Seat number:");
            scanf("%d",&airline.seatnumber);
            if(dp3[airline.seatnumber]==0)
            {
                dp3[airline.seatnumber]++;
            }

        }
    }
    else if(airline.destination=="Dubai")
    {
        if(airline.classservice=="economy")
        {
            checkseatsavailable(dp4);
            printf("Seat number:");
            scanf("%d",&airline.seatnumber);
            if(dp4[airline.seatnumber]==0)
            {
                dp4[airline.seatnumber]++;
            }

        }
        else if(airline.classservice=="business")
        {
            checkseatsavailable(dp5);
            printf("Seat number:");
            scanf("%d",&airline.seatnumber);
            if(dp5[airline.seatnumber]==0)
            {
                dp5[airline.seatnumber]++;
            }

        }
        else if(airline.classservice=="first class")
        {
            checkseatsavailable(dp6);
            printf("Seat number:");
            scanf("%d",&airline.seatnumber);
            if(dp6[airline.seatnumber]==0)
            {
                dp6[airline.seatnumber]++;
            }

        }
    }
    else if(airline.destination=="Paris")
    {
        if(airline.classservice=="economy")
        {
            checkseatsavailable(dp7);
            printf("Seat number:");
            scanf("%d",&airline.seatnumber);
            if(dp7[airline.seatnumber]==0)
            {
                dp7[airline.seatnumber]++;
            }

        }
        else if(airline.classservice=="business")
        {
            checkseatsavailable(dp8);
            printf("Seat number:");
            scanf("%d",&airline.seatnumber);
            if(dp8[airline.seatnumber]==0)
            {
                dp8[airline.seatnumber]++;
            }

        }
        else if(airline.classservice=="first class")
        {
            checkseatsavailable(dp9);
            printf("Seat number:");
           scanf("%d",&airline.seatnumber);
           if(dp9[airline.seatnumber]==0)
            {
                dp9[airline.seatnumber]++;
            }
        }
    }
    printf("Meal preference:");
    scanf("%s",airline.mealpreference);
    FILE *file=fopen(DATA_FILE,"ab");
    if(!file)
    {
        printf("ticket booking not saved");
        return;
    }
    fwrite(&airline,sizeof(Airline),1,file);
    fclose(file);
    }
    printf("TICKET BOOKING SUCCESSFUL");
}
void checkseatsavailable(int *arr)
{
    for(int i=1;i<=100;i++)
    {
        printf("%d\t",i);
    }printf("\n");
    for(int i=0;i<100;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void ifseatsavailable()
{
    int s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0,s9=0;
    printf("Seats available in flight Tokyo:");
    for(int i=0;i<100;i++)
    {
        if(dp1[i]==0)
        {
            s1++;
        }
        if(dp2[i]==0)
        {
            s2++;
        }
        if(dp3[i]==0)
        {
            s3++;
        }
    }printf("%d",s1+s2+s3);
    printf("Seats available in flight Dubai:");
    for(int i=0;i<100;i++)
    {
        if(dp4[i]==0)
        {
            s4++;
        }
        if(dp5[i]==0)
        {
            s5++;
        }
        if(dp6[i]==0)
        {
            s6++;
        }
    }printf("%d",s4+s5+s6);
    printf("Seats available in flight Paris:");
    for(int i=0;i<100;i++)
    {
        if(dp7[i]==0)
        {
            s7++;
        }
        if(dp8[i]==0)
        {
            s8++;
        }
        if(dp9[i]==0)
        {
            s9++;
        }
    }printf("%d",s7+s8+s9);

}
void passengerlist()
{
     Airline airline;
     FILE *file=fopen(DATA_FILE,"r+b");
     if(!file)
     {
         printf("no data stored");
         return;
     }
     printf("\tAIRLINE PASSENGERS\n");
     printf("TICKET NUMBER|NAME|DESTINATION|CLASS|MEAL\n");
     printf("___________________________________________\n");
     while(fread(&airline,sizeof(Airline),1,file))
     {
         printf("%d|%s|%s|%s|%s",airline.flightticketnumber,airline.name,airline.destination,airline.classservice,airline.mealpreference);
     }
     fclose(file);
}
void onepassengerdetail()
{
   Airline airline;
   FILE *file=fopen(DATA_FILE,"r+b");
   if(!file)
   {
       printf("no data stored");
       return;
   }
   int tc;
   printf("enter the ticket number:");
   scanf("%d",&tc);
   while(fread(&airline,sizeof(Airline),1,file))
   {
       if(tc==airline.flightticketnumber)
       {
           printf("%d|%s|%s|%s|%s",airline.flightticketnumber,airline.name,airline.destination,airline.classservice,airline.mealpreference);
       }break;
   }
   fclose(file);
}
void cancelticket()
{    int tc,sn;
     char a[50],b[50];
     printf("enter the ticket number to be cancelled:");
     scanf("%d",&tc);
     printf("enter the destination(Tokyo,Dubai,Paris)and class(economy,business,first class):");
     scanf("%s%s",a,b);
     if(a=='Tokyo')
    {
        if(b=='economy')
        {
            printf("Seat number:");
            scanf("%d",&sn);
            if(dp1[sn]==1)
            {
                dp1[sn]--;
            }

        }
        else if(b=='business')
        {

            printf("Seat number:");
            scanf("%d",&sn);
            if(dp2[sn]==1)
            {
                dp2[sn]--;
            }

        }
        else if(b=='first class')
        {

            printf("Seat number:");
            scanf("%d",&sn);
            if(dp3[sn]==1)
            {
                dp3[sn]--;
            }

        }
    }
    else if(a=='Dubai')
    {
        if(b=='economy')
        {

            printf("Seat number:");
            scanf("%d",&sn);
            if(dp4[sn]==1)
            {
                dp4[sn]--;
            }

        }
        else if(b=='business')
        {

            printf("Seat number:");
            scanf("%d",&sn);
            if(dp5[sn]==1)
            {
                dp5[sn]--;
            }

        }
        else if(b=='first class')
        {

            printf("Seat number:");
            scanf("%d",&sn);
            if(dp6[sn]==1)
            {
                dp6[sn]--;
            }

        }
    }
    else if(a=='Paris')
    {
        if(b=='economy')
        {

            printf("Seat number:");
            scanf("%d",&sn);
            if(dp7[sn]==1)
            {
                dp7[sn]--;
            }

        }
        else if(b=='business')
        {

            printf("Seat number:");
            scanf("%d",&sn);
            if(dp8[sn]==1)
            {
                dp8[sn]--;
            }

        }
        else if(b=='first class')
        {

            printf("Seat number:");
           scanf("%d",&sn);
           if(dp9[sn]==1)
            {
                dp9[sn]--;
            }
        }
    }
printf("the ticket cancelled successfully");
}

int main()
{   int choice;
    do
    {
    printf("\t\t\t\t\tAIRLINE MANAGEMENT SYSTEM\n");
    printf("\t\t\t\t\t_________________________\n");
    printf("SELCET ONE:\n");
    printf("1.NO OF SEATS AVAILABLE(TOTAL SEATS PER FLIGHT 300)\n");
    printf("2.BOOK TICKET\n");
    printf("3.CANCEL TICKET\n");
    printf("4.PASSENGER LIST\n");
    printf("5.DETAIL OF ONE PASSENGER\n");
    printf("6.EXIT\n\n\n");
    printf("enter a choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
           ifseatsavailable();
           break;
        case 2:
           bookticket();
           break;
        case 3:
            cancelticket();
            break;
        case 4:
            passengerlist();
            break;
        case 5:
            onepassengerdetail();
            break;
        case 6:
            return 0;
        default:
            printf("INVALID CHOICE:");

    }
    }while(choice!=6);
return 0;
}
