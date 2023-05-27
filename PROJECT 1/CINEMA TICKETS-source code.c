#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define NUM_ROWS 5
#define NUM_SEATS_PER_ROW 10
#define SEAT_CAPACITY 50

/*
format for movie info
title
MTRCB rate
genre
showtime hour
showtime minute
*/
typedef struct {
    char title[50];
    char rating[20];
    char genre[50];
    int hour;
    char minute;
    int price;
} Movie_info;

// Define a 2D array to represent the seating chart
int seatingChart1[NUM_ROWS][NUM_SEATS_PER_ROW];
int seatingChart3[NUM_ROWS][NUM_SEATS_PER_ROW];
int seatingChart2[NUM_ROWS][NUM_SEATS_PER_ROW];

int seats1[SEAT_CAPACITY];
int seats2[SEAT_CAPACITY];
int seats3[SEAT_CAPACITY];

int numSeats;

int totalSeats;

int finalSeats1 [SEAT_CAPACITY];
int finalSeats2 [SEAT_CAPACITY];
int finalSeats3 [SEAT_CAPACITY];

int records1 = 0;
int records2 = 0;
int records3 = 0;

void records(Movie_info movies[], int records1, int records2, int records3)
{
	int totalsales;
	float totalamount;
	FILE *ofp5;
	ofp5 = fopen("Recordofsales.txt", "wt");
	
	fprintf(ofp5, "\n\n");
	fprintf(ofp5, "RECORD OF SALES\n");
    fprintf(ofp5, "--------------------------------------------------------------------------------------------------------\n");
    fprintf(ofp5, "MOVIE TITLE\t\t\t\t\t\t\t| Number of Seats\t\t| Total Amount\n");
    fprintf(ofp5, "--------------------------------------------------------------------------------------------------------\n");
    fprintf(ofp5, "%-20s\t\t\t\t\t\t%-5s%02d\t\t%-5s%02d.00\n\n", movies[0].title, " ", records1, " ", records1 * movies[0].price);
    fprintf(ofp5, "%-20s\t\t\t\t\t\t%-5s%02d\t\t%-5s%02d.00\n\n", movies[1].title, " ", records2, " ", records2 * movies[1].price);
    fprintf(ofp5, "%-20s\t\t\t\t\t\t%-5s%02d\t\t%-5s%02d.00\n\n", movies[2].title, " ", records3, " ", records3 * movies[2].price);
	fprintf(ofp5, "--------------------------------------------------------------------------------------------------------\n\n");
	totalsales = records1 + records2 + records3;
	totalamount = records1 * movies[0].price + records2 * movies[1].price + records3 * movies[2].price;
	fprintf(ofp5, "Total Seats: %d\n\n", totalsales);
	fprintf(ofp5, "Total Sales: %.2f\n",  totalamount);
	
	

}

void output_receipt1 (Movie_info movies[], int numSeats, int seats1[], int answer1) {
	int i;
	float totalPrice = totalSeats * movies[answer1-1].price;
	
	FILE * ofp4;
    ofp4 = fopen("Receipts.txt","at");
    
    fprintf(ofp4, "\n\n");
    fprintf(ofp4, "\t\t\t\t------------------------------------------------------------------------------------\n");
    fprintf(ofp4, "\t\t\t\t\t\t                    MOVIE TICKET                   \n");
    fprintf(ofp4, "\t\t\t\t------------------------------------------------------------------------------------\n");
    fprintf(ofp4, "\t\t\t\tTitle: %s\n", movies[answer1-1].title);
    fprintf(ofp4, "\t\t\t\tRating: %s\n", movies[answer1-1].rating);
    fprintf(ofp4, "\t\t\t\tGenre: %s\n", movies[answer1-1].genre);
    fprintf(ofp4, "\t\t\t\tShowtime: %d:%02d\n", movies[answer1-1].hour, movies[answer1-1].minute);
    fprintf(ofp4, "\t\t\t\tNumber of seats: %d\n", totalSeats);
    fprintf(ofp4, "\t\t\t\tSeats: ");
    for (i = 0; i < totalSeats; i++) {
    		fprintf (ofp4, "%d ", seats1[i]); 	
	}
	fprintf(ofp4, "\n");

    fprintf(ofp4, "\t\t\t\tTotal price: PHP %.2f\n\n", totalPrice);
    fprintf (ofp4, "\n\t\t\t\tKindly provide this ticket to the designated security officers at the theater!\n");
    fprintf(ofp4, "\t\t\t\t------------------------------------------------------------------------------------\n");
    fprintf (ofp4, "\t\t\t\t\t\t\tTHIS SERVES AS YOUR OFFICIAL RECEIPT\n");
    fprintf (ofp4, "\t\t\t\t\t\tThank you for purchasing tickets from BYTE THEATER!\n");
    fprintf (ofp4, "\t\t\t\t\t\t\t    Enjoy watching your movie!\n\n\n");
}

void output_receipt2 (Movie_info movies[], int numSeats, int seats2[], int answer1) {
	int i;
	float totalPrice = totalSeats * movies[answer1-1].price;
	
	FILE * ofp4;
    ofp4 = fopen("Receipts.txt","at");
    
    fprintf(ofp4, "\n\n");
    fprintf(ofp4, "\t\t\t\t------------------------------------------------------------------------------------\n");
    fprintf(ofp4, "\t\t\t\t\t\t                    MOVIE TICKET                   \n");
    fprintf(ofp4, "\t\t\t\t------------------------------------------------------------------------------------\n");
    fprintf(ofp4, "\t\t\t\tTitle: %s\n", movies[answer1-1].title);
    fprintf(ofp4, "\t\t\t\tRating: %s\n", movies[answer1-1].rating);
    fprintf(ofp4, "\t\t\t\tGenre: %s\n", movies[answer1-1].genre);
    fprintf(ofp4, "\t\t\t\tShowtime: %d:%02d\n", movies[answer1-1].hour, movies[answer1-1].minute);
    fprintf(ofp4, "\t\t\t\tNumber of seats: %d\n", totalSeats);
    fprintf(ofp4, "\t\t\t\tSeats: ");
	for (i = 0; i < totalSeats; i++) {
    	fprintf (ofp4, "%d ", seats2[i]); 	
	}
	fprintf(ofp4, "\n");

    fprintf(ofp4, "\t\t\t\tTotal price: PHP %.2f\n\n", totalPrice);
    fprintf (ofp4, "\n\t\t\t\tKindly provide this ticket to the designated security officers at the theater!\n");
    fprintf(ofp4, "\t\t\t\t------------------------------------------------------------------------------------\n");
    fprintf (ofp4, "\t\t\t\t\t\t\tTHIS SERVES AS YOUR OFFICIAL RECEIPT\n");
    fprintf (ofp4, "\t\t\t\t\t\tThank you for purchasing tickets from BYTE THEATER!\n");
    fprintf (ofp4, "\t\t\t\t\t\t\t    Enjoy watching your movie!\n\n\n");
}

void output_receipt3 (Movie_info movies[], int numSeats, int seats3[], int answer1) {
	int i;
	float totalPrice = totalSeats * movies[answer1-1].price;
	
	FILE * ofp4;
    ofp4 = fopen("Receipts.txt","at");
    
    fprintf(ofp4, "\n\n");
    fprintf(ofp4, "\t\t\t\t------------------------------------------------------------------------------------\n");
    fprintf(ofp4, "\t\t\t\t\t\t                    MOVIE TICKET                   \n");
    fprintf(ofp4, "\t\t\t\t------------------------------------------------------------------------------------\n");
    fprintf(ofp4, "\t\t\t\tTitle: %s\n", movies[answer1-1].title);
    fprintf(ofp4, "\t\t\t\tRating: %s\n", movies[answer1-1].rating);
    fprintf(ofp4, "\t\t\t\tGenre: %s\n", movies[answer1-1].genre);
    fprintf(ofp4, "\t\t\t\tShowtime: %d:%02d\n", movies[answer1-1].hour, movies[answer1-1].minute);
    fprintf(ofp4, "\t\t\t\tNumber of seats: %d\n", totalSeats);
    fprintf(ofp4, "\t\t\t\tSeats: ");
	for (i = 0; i < totalSeats; i++) {
    	fprintf (ofp4, "%d ", seats3[i]); 	
	}
	fprintf(ofp4, "\n");

    fprintf(ofp4, "\t\t\t\tTotal price: PHP %.2f\n\n", totalPrice);
    fprintf (ofp4, "\n\t\t\t\tKindly provide this ticket to the designated security officers at the theater!\n");
    fprintf(ofp4, "\t\t\t\t------------------------------------------------------------------------------------\n");
    fprintf (ofp4, "\t\t\t\t\t\t\tTHIS SERVES AS YOUR OFFICIAL RECEIPT\n");
    fprintf (ofp4, "\t\t\t\t\t\tThank you for purchasing tickets from BYTE THEATER!\n");
    fprintf (ofp4, "\t\t\t\t\t\t\t    Enjoy watching your movie!\n\n\n");
}

void print_receipt1(Movie_info movies[], int numSeats, int seats1[], int answer1) {
	int i;
   float totalPrice = totalSeats * movies[answer1-1].price;
    
    printf("\n\n");
    printf("\t\t\t\t------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t                    MOVIE TICKET                   \n");
    printf("\t\t\t\t------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tTitle: %s\n", movies[answer1-1].title);
    printf("\t\t\t\tRating: %s\n", movies[answer1-1].rating);
    printf("\t\t\t\tGenre: %s\n", movies[answer1-1].genre);
    printf("\t\t\t\tShowtime: %d:%02d\n", movies[answer1-1].hour, movies[answer1-1].minute);
    printf("\t\t\t\tNumber of seats: %d\n", totalSeats);
    printf("\t\t\t\tSeats: ");
	for (i = 0; i < totalSeats; i++) {
    	printf("%d ", seats1[i]); 
	}
	printf("\n");

    printf("\t\t\t\tTotal price: PHP %.2f\n\n", totalPrice);
    printf ("\n\t\t\t\tKindly provide this ticket to the designated security officers at the theater!\n");
    printf("\t\t\t\t------------------------------------------------------------------------------------\n");
    printf ("\t\t\t\t\t\t\tTHIS SERVES AS YOUR OFFICIAL RECEIPT\n");
    printf ("\t\t\t\t\t\tThank you for purchasing tickets from BYTE THEATER!\n");
    printf ("\t\t\t\t\t\t\t    Enjoy watching your movie!\n\n\n");
}

void print_receipt2(Movie_info movies[], int numSeats, int seats2[], int answer1) {
    int i;
    float totalPrice = totalSeats * movies[answer1-1].price;
    
    printf("\n\n");
    printf("\t\t\t\t------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t                    MOVIE TICKET                   \n");
    printf("\t\t\t\t------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tTitle: %s\n", movies[answer1-1].title);
    printf("\t\t\t\tRating: %s\n", movies[answer1-1].rating);
    printf("\t\t\t\tGenre: %s\n", movies[answer1-1].genre);
    printf("\t\t\t\tShowtime: %d:%02d\n", movies[answer1-1].hour, movies[answer1-1].minute);
    printf("\t\t\t\tNumber of seats: %d\n", totalSeats);
    printf("\t\t\t\tSeats: ");
	for (i = 0; i < totalSeats; i++) {
    	printf("%d ", seats2[i]); // Add 1 to the seat number to display it as 1-based index
	}
	printf("\n");

    printf("\t\t\t\tTotal price: PHP %.2f\n\n", totalPrice);
    printf ("\n\t\t\t\tKindly provide this ticket to the designated security officers at the theater!\n");
    printf("\t\t\t\t------------------------------------------------------------------------------------\n");
    printf ("\t\t\t\t\t\t\tTHIS SERVES AS YOUR OFFICIAL RECEIPT\n");
    printf ("\t\t\t\t\t\tThank you for purchasing tickets from BYTE THEATER!\n");
    printf ("\t\t\t\t\t\t\t    Enjoy watching your movie!\n\n\n");
}

void print_receipt3(Movie_info movies[], int numSeats, int seats3[], int answer1) {
    int i;
    float totalPrice = totalSeats * movies[answer1-1].price;
    
    printf("\n\n");
    printf("\t\t\t\t------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t                    MOVIE TICKET                   \n");
    printf("\t\t\t\t------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tTitle: %s\n", movies[answer1-1].title);
    printf("\t\t\t\tRating: %s\n", movies[answer1-1].rating);
    printf("\t\t\t\tGenre: %s\n", movies[answer1-1].genre);
    printf("\t\t\t\tShowtime: %d:%02d\n", movies[answer1-1].hour, movies[answer1-1].minute);
    printf("\t\t\t\tNumber of seats: %d\n", totalSeats);
    printf("\t\t\t\tSeats: ");
	for (i = 0; i < totalSeats; i++) {
    	printf("%d ", seats3[i]); // Add 1 to the seat number to display it as 1-based index
	}
	printf("\n");

    printf("\t\t\t\tTotal price: PHP %.2f\n\n", totalPrice);
    printf ("\n\t\t\t\tKindly provide this ticket to the designated security officers at the theater!\n");
    printf("\t\t\t\t------------------------------------------------------------------------------------\n");
    printf ("\t\t\t\t\t\t\tTHIS SERVES AS YOUR OFFICIAL RECEIPT\n");
    printf ("\t\t\t\t\t\tThank you for purchasing tickets from BYTE THEATER!\n");
    printf ("\t\t\t\t\t\t\t    Enjoy watching your movie!\n\n\n");
}
void intro() 
{	
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t___        ___ _____  ___      _____   _____    ____  ____  _______             ___   ___   ___\n");
	printf("\t\t\t\t\t\\  \\      /  /  ____||  |     /  ___\\ /     \\  |    \\/    ||  _____|           |  |  |  |  |  |\n");
	printf("\t\t\t\t\t \\  \\    /  /	|__  |  |    /  /    / /     \\ |          ||  |___             |  |  |  |  |  |\n");
	printf("\t\t\t\t\t  \\  \\/\\/  / |   __| |  |   |  |    | |       ||  |\\  /|  ||   __|             |__|  |__|  |__|\n");
	printf("\t\t\t\t\t   \\	  /  |  |____|  |___ \\  \\___ \\ \\___/ / |  | \\/ |  ||  |____             ___   ___   ___\n");
	printf("\t\t\t\t\t    \\_/\\_/   |______||______| \\_____/ \\_____/  |__|    |__||_______|           |__|  |__|  |__|\n");
	  
	
	
    printf("\n\n\n\t\t\t\t\t\t\t\t=========================================\n");
    printf("\t\t\t\t\t\t\t\t|              CS1-A CINEMA             |\n");
    printf("\t\t\t\t\t\t\t\t=========================================\n");


    printf("\n\n\t\t\t\t\t\t\t    Experience the magic of movies at CS 1-A's cinema!\n");
    printf("\t	Comfortable seating, high-quality sound systems, and wide&clear screens that will transport you to a world ofcinematic beauty.\n");
    printf("\t\t\t\t\tA selection of the latest blockbusters and classics, there's something for every taste and mood.\n");
    printf("\t\t\t\t\t\tPlus, we offer reasonable pricing, tasty snacks, and a welcoming atmosphere.\n");
    printf("\t\t\t\t\t\t\t  Come on in and let us bring you to the world of film!\n\n\n\n\n");
    
}

void seat_plan1(Movie_info movies){
	
	int i, j;
	printf ("O - available.\n");
	printf ("X - unavailable.\n");
    printf("\t\t\t\t          _______________________________________________________________\n");
    printf("\t\t\t\t         |                             SCREEN                            |\n");
    printf("\t\t\t\t         |_______________________________________________________________|\n");
    printf("\n\n\n");
    
    for (i = 0; i < NUM_ROWS; i++) {
        printf("\t\t\t\t | ");
        
        for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            int seatNumber = i * NUM_SEATS_PER_ROW + j + 1;
            if (j == 3 || j == 7) {
                printf("        | ");
            }
            if (seatNumber < 10) {
                printf("0");
            }
            printf("%d", seatNumber);
            printf(" |  ");
            
        }

        printf("\n");
        printf("\t\t\t\t |");

		for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            if (j == 3 || j == 7) {
                printf("         |");
            }
            printf("____| ");
        }

        printf("\n");
        printf("\t\t\t\t | ");

        for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            if (j == 3 || j == 7) {
                printf("        | ");
            }
            if (seatingChart1[i][j] == 0) {
                printf(" O |  ");
            } else {
                printf(" X |  ");
            }
        }
		
        printf("\n");
        printf("\t\t\t\t |");

        for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            if (j == 3 || j == 7) {
                printf("         |");
            }
            printf("____| ");
        }
        printf("\n");

    }
}

void seat_plan2(Movie_info movies){
	
	int i, j;
	printf ("O - available.\n");
	printf ("X - unavailable.\n");
    printf("\t\t\t\t          _______________________________________________________________\n");
    printf("\t\t\t\t         |                             SCREEN                            |\n");
    printf("\t\t\t\t         |_______________________________________________________________|\n");
    printf("\n\n\n");
    
    for (i = 0; i < NUM_ROWS; i++) {
        printf("\t\t\t\t | ");
        
        for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            int seatNumber = i * NUM_SEATS_PER_ROW + j + 1;
            if (j == 3 || j == 7) {
                printf("        | ");
            }
            if (seatNumber < 10) {
                printf("0");
            }
            printf("%d", seatNumber);
            printf(" |  ");
            
        }

        printf("\n");
        printf("\t\t\t\t |");

		for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            if (j == 3 || j == 7) {
                printf("         |");
            }
            printf("____| ");
        }

        printf("\n");
        printf("\t\t\t\t | ");

        for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            if (j == 3 || j == 7) {
                printf("        | ");
            }
            if (seatingChart2[i][j] == 0) {
                printf(" O |  ");
            } else {
                printf(" X |  ");
            }
        }
		
        printf("\n");
        printf("\t\t\t\t |");

        for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            if (j == 3 || j == 7) {
                printf("         |");
            }
            printf("____| ");
        }
        printf("\n");

    }
}

void seat_plan3(Movie_info movies){
	
	int i, j;
	printf ("O - available.\n");
	printf ("X - unavailable.\n");
    printf("\t\t\t\t          _______________________________________________________________\n");
    printf("\t\t\t\t         |                             SCREEN                            |\n");
    printf("\t\t\t\t         |_______________________________________________________________|\n");
    printf("\n\n\n");
    
    for (i = 0; i < NUM_ROWS; i++) {
        printf("\t\t\t\t | ");
        
        for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            int seatNumber = i * NUM_SEATS_PER_ROW + j + 1;
            if (j == 3 || j == 7) {
                printf("        | ");
            }
            if (seatNumber < 10) {
                printf("0");
            }
            printf("%d", seatNumber);
            printf(" |  ");
            
        }

        printf("\n");
        printf("\t\t\t\t |");

		for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            if (j == 3 || j == 7) {
                printf("         |");
            }
            printf("____| ");
        }

        printf("\n");
        printf("\t\t\t\t | ");

        for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            if (j == 3 || j == 7) {
                printf("        | ");
            }
            if (seatingChart3[i][j] == 0) {
                printf(" O |  ");
            } else {
                printf(" X |  ");
            }
        }
		
        printf("\n");
        printf("\t\t\t\t |");

        for (j = 0; j < NUM_SEATS_PER_ROW; j++) {
            if (j == 3 || j == 7) {
                printf("         |");
            }
            printf("____| ");
        }
        printf("\n");

    }
}

void read_moviedata(Movie_info movies[], FILE* openf) {
    int i;
	for (i = 0; i < 3; i++) {
        fscanf(openf, " %[^\n]", movies[i].title); //reads unitl the new line
        fscanf(openf, " %[^\n]", movies[i].rating);//reads unitl the new line
        fscanf(openf, " %[^\n]", movies[i].genre);//reads unitl the new line
        fscanf(openf, " %d", &movies[i].hour);
        fscanf(openf, " %d", &movies[i].minute);
        fscanf(openf, " %d", &movies[i].price);
    }
}

void stat_seat1() {
    int i, j, k, choice, seat;
	int condition = 1;

    printf("Enter number of seats you want to booked: ");
    scanf("%d", &numSeats);
	
    for (i = 0; i < numSeats; i++) {
		seat1:
		printf("Enter number for seat %d: ", i + 1);
	    scanf("%d", &choice);
        if(choice > 50){
            printf("invalid seat number\n");
            goto seat1;
		}
	    do
	    {
	    	for(k = 0; k < SEAT_CAPACITY; k++)
	    	{
	    		if(finalSeats1 [k] == choice)
	    		{
	    			printf("SEAT IS UNAVAILABLE.\n");
	    			printf("Choose another seat %d: ", i + 1);
					scanf("%d", &choice);
				}
				else
				{
					condition = 0;
				}
			}
				    	
		}while (condition == 1);
		
		
        if(choice > 0 && choice <=10)
        {
			if(finalSeats1[i] == 0)
        	{
        		finalSeats1[i] = choice;
        		seats1[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats1[j] == 0)
					{
						finalSeats1[j] = choice;
						seats1[j] = choice;
						break;
					}
					
				}
			}	
			
			finalSeats1 [i] = choice;	
        	seatingChart1[0][choice - 1] = 1;	
		}
		else if(choice > 10 && choice <=20)
		{
        	if(finalSeats1[i] == 0)
        	{
        		finalSeats1[i] = choice;
        		seats1[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats1[j] == 0)
					{
						finalSeats1[j] = choice;
						seats1[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart1[1][choice - 11] = 1;
						
		}
		else if(choice > 20 && choice <=30)
		{
        	if(finalSeats1[i] == 0)
        	{
        		finalSeats1[i] = choice;
        		seats1[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats1[j] == 0)
					{
						finalSeats1[j] = choice;
						seats1[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart1[2][choice - 21] = 1;	
					
		}
		else if(choice > 30 && choice <=40)
		{
        	if(finalSeats1[i] == 0)
        	{
        		finalSeats1[i] = choice;
        		seats1[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats1[j] == 0)
					{
						finalSeats1[j] = choice;
						seats1[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart1[3][choice - 31] = 1;	
					
		}
		else if(choice > 40 && choice <=50)
		{
        	if(finalSeats1[i] == 0)
        	{
        		finalSeats1[i] = choice;
        		seats1[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats1[j] == 0)
					{
						finalSeats1[j] = choice;
						seats1[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart1[4][choice - 41] = 1;		
				
		}

    }
}

void stat_seat2() {
    int i, j, k, choice, seat;
	int condition = 1;

    printf("Enter number of seats you want to booked: ");
    scanf("%d", &numSeats);
	
    for (i = 0; i < numSeats; i++) {
		seat2:
		printf("Enter number for seat %d: ", i + 1);
	    scanf("%d", &choice);
        if(choice > 50){
            printf("invalid seat number\n");
            goto seat2;
		}
	    do
	    {
	    	for(k = 0; k < SEAT_CAPACITY; k++)
	    	{
	    		if(finalSeats2 [k] == choice)
	    		{
	    			printf("SEAT IS UNAVAILABLE.\n");
	    			printf("Choose another seat %d: ", i + 1);
					scanf("%d", &choice);
				}
				else
				{
					condition = 0;
				}
			}
				    	
		}while (condition == 1);
		
        if(choice > 0 && choice <=10)
        {	
        	if(finalSeats2[i] == 0)
        	{
        		finalSeats2[i] = choice;
        		seats2[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats2[j] == 0)
					{
						finalSeats2[j] = choice;
						seats2[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart2[0][choice - 1] = 1;	
        	
		}
		else if(choice > 10 && choice <=20)
		{
        	if(finalSeats2[i] == 0)
        	{
        		finalSeats2[i] = choice;
        		seats2[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats2[j] == 0)
					{
						finalSeats2[j] = choice;
						seats2[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart2[1][choice - 11] = 1;	
				
		}
		else if(choice > 20 && choice <=30)
		{
        	if(finalSeats2[i] == 0)
        	{
        		finalSeats2[i] = choice;
        		seats2[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats2[j] == 0)
					{
						finalSeats2[j] = choice;
						seats2[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart2[2][choice - 21] = 1;
					
		}
		else if(choice > 30 && choice <=40)
		{
        	if(finalSeats2[i] == 0)
        	{
        		finalSeats2[i] = choice;
        		seats2[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats2[j] == 0)
					{
						finalSeats2[j] = choice;
						seats2[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart2[3][choice - 31] = 1;	
					
		}
		else if(choice > 40 && choice <=50)
		{
        	if(finalSeats2[i] == 0)
        	{
        		finalSeats2[i] = choice;
        		seats2[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats2[j] == 0)
					{
						finalSeats2[j] = choice;
						seats2[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart2[4][choice - 41] = 1;	
					
		}

    }
}
void stat_seat3() {
    int i, j, k, choice, seat;
	int condition = 1;

    printf("Enter number of seats you want to booked: ");
    scanf("%d", &numSeats);
	
    for (i = 0; i < numSeats; i++) {
    	seat3:
		printf("Enter number for seat %d: ", i + 1);
	    scanf("%d", &choice);
        if(choice > 50){
            printf("invalid seat number\n");
            goto seat3;
        }
	    do
	    {
	    	for(k = 0; k < SEAT_CAPACITY; k++)
	    	{
	    		if(finalSeats3 [k] == choice)
	    		{
	    			printf("SEAT IS UNAVAILABLE.\n");
	    			printf("Choose another seat %d: ", i + 1);
					scanf("%d", &choice);
				}
				else
				{
					condition = 0;
				}
			}
				    	
		}while (condition == 1);
		
        if(choice > 0 && choice <=10)
        {
        	if(finalSeats3[i] == 0)
        	{
        		finalSeats3[i] = choice;
        		seats3[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats3[j] == 0)
					{
						finalSeats3[j] = choice;
						seats3[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart3[0][choice - 1] = 1;	
        	
		}
		else if(choice > 10 && choice <=20)
		{
        	if(finalSeats3[i] == 0)
        	{
        		finalSeats3[i] = choice;
        		seats3[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats3[j] == 0)
					{
						finalSeats3[j] = choice;
						seats3[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart3[1][choice - 11] = 1;	
			
		}
		else if(choice > 20 && choice <=30)
		{
        	if(finalSeats3[i] == 0)
        	{
        		finalSeats3[i] = choice;
        		seats3[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats3[j] == 0)
					{
						finalSeats3[j] = choice;
						seats3[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart3[2][choice - 21] = 1;	
				
		}
		else if(choice > 30 && choice <=40)
		{
        	if(finalSeats3[i] == 0)
        	{
        		finalSeats3[i] = choice;
        		seats3[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats3[j] == 0)
					{
						finalSeats3[j] = choice;
						seats3[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart3[3][choice - 31] = 1;
					
		}
		else if(choice > 40 && choice <=50)
		{
        	if(finalSeats3[i] == 0)
        	{
        		finalSeats3[i] = choice;
        		seats3[i] = choice;
			}
        	else
			{
				for(j = 0; j < SEAT_CAPACITY; j++)
				{
					if(seats3[j] == 0)
					{
						finalSeats3[j] = choice;
						seats3[j] = choice;
						break;
					}
					
				}
			}	
        	seatingChart3[4][choice - 41] = 1;		
				
		}

    }
}
void display_moviedata(Movie_info movies[]) {
    int i;
    
	for (i = 0; i < 1; i++) {
        printf("\t\t[%d]\t\t\t\t[%d]\t\t\t\t[%d]\n", i + 1, i + 2, i + 3);
		printf("Title:\t\t%-32s%-32s%-32s\n", movies[i].title, movies[i+1].title, movies[i+2].title);
        printf("Rating:\t\t%-32s%-32s%-32s\n", movies[i].rating, movies[i+1].rating, movies[i+2].rating);
        printf("Genre:\t\t%-32s%-32s%-32s\n", movies[i].genre, movies[i+1].genre, movies[i+2].genre);
        printf("Showtime:\t%d:%02d\t\t\t\t%d:%02d\t\t\t\t%d:%02d\n", movies[i].hour, movies[i].minute, movies[i+1].hour, movies[i+1].minute, movies[i+2].hour, movies[i+2].minute);
        printf("Price:\t\t%d.00\t\t\t\t%d.00\t\t\t\t%d.00\n", movies[i].price, movies[i+1].price, movies[i+2].price);
    }
}
void cs1a() 
{
	printf("\t    ______       _____        _____         _________          ______    ____ ____   ____ ________  _____  _____   _________                     \n");
	printf("\t   /      \\     /     \\      /     |       /   __    \\        /      \\  |   ||    \\ |   ||        ||     \\/     | /   __    \\     \n");
	printf("\t  /    ____\\   |       \\    /__    |      |   /__\\    |      /    ____\\ |   ||     \\|   ||   _____||            ||   /__\\    |    \n");
	printf("\t |    /      ___\\   \\___|      |   | ____ |           |     |    /      |   ||          ||   __|   |            ||           | \n");
	printf("\t |    \\ ____|   \\   \\          |   ||____||    ___    |     |    \\ ___ _|   ||   |\\     ||  |_____ |    |\\/|    ||    ___    |         \n");
	printf("\t  \\        / \\       |   _     |   |      |   |   |   |      \\        / |   ||   | \\    ||        ||    |  |    ||   |   |   |  \n");
	printf("\t   \\______/   \\_____/   |_|    |___|      |___|   |___|       \\______/  |___||___|  \\___||________||____|  |____||___|   |___|   \n\n\n\n");	
}

int main() { 
    
    Movie_info movies[10]; //it can store 10 movie entries
    int i, j;
    int answer1;
    char answer2;
    int reserved;
    FILE * ifp;
    
    ifp = fopen("MovieInfo.txt","rt"); 
start:
do{
	
	totalSeats = 0;
	numSeats = 0;
	system("@cls||clear");
	intro();
	printf("Press any key to continue: ");
	answer2 = getch(); //gets the user input and store it in a variable answer2
	
	do{
        if(answer2 == 'X' || answer2 == 'x'  )
		{
            system("@cls||clear");
			printf("Employee input detected\n");
			printf("End program?Y/N: ");
			answer2 = getch();
            if(answer2 == 'Y'|| answer2 == 'y'){
            	records(movies, records1, records2, records3);
                return 0;
            }
            else{
                goto start;
            }
		}
		else if(answer2 != 'X' || answer2 != 'x')
		{
			system("@cls||clear");
			cs1a();
			read_moviedata(movies, ifp);
	    	display_moviedata(movies);
    
    		do
			{
				system("@cls||clear");
				cs1a();
				display_moviedata(movies);
				printf("\n\nChoose a movie to watch (1, 2, 3): ");
	    		scanf("%d", &answer1); //answer1 variable is for the chosen movie number
				if( answer1 == 1)
    			{
    				if (finalSeats1[49] == 0)
					{
    				do
   		 			{	
						
    					system("@cls||clear");
    					cs1a();
    					seat_plan1(movies[0]);
    					printf("\n");
						stat_seat1();
						totalSeats += numSeats;
						system("@cls||clear");
						cs1a();
						seat_plan1(movies[0]);
						printf("\nSeat was successfully reserved.\n");
						printf("Do you want to reserved another seats(Y/N)? ");
						answer2 = getch();
					} while ( answer2 == 'Y' || answer2 == 'y');
					}
					else {
						printf ("ALL SEATS ARE UNAVAILABLE.\n");
					}
					
				}
				else if(answer1 == 2)
				{
    				do
    				{		
										
    					system("@cls||clear");
    					seat_plan2(movies[0]);
    					printf("\n");
						stat_seat2();
						totalSeats += numSeats;
						system("@cls||clear");
						cs1a();
						seat_plan2(movies[0]);	
						printf("\nSeat was successfully reserved.\n");
						printf("Do you want to reserved another seats(Y/N)? ");
						answer2 = getch();
					} while ( answer2 == 'Y' || answer2 == 'y');
					
				}
				else if(answer1 == 3)
				{
    				do
    				{	
											
    					system("@cls||clear");
    					seat_plan3(movies[0]);
    					printf("\n");
						stat_seat3();
						totalSeats += numSeats;
						system("@cls||clear");
						cs1a();
						seat_plan3(movies[0]);	
						printf("\nSeat was successfully reserved.\n");
						printf("Do you want to reserved another seats(Y/N)? ");
						answer2 = getch();

					} while ( answer2 == 'Y' || answer2 == 'y');
					
				}
				else		
				{
					printf("Invalid choice.\n");
				}
				printf("\nDo you want to cancel(Y/N)?");
				answer2 = getch();
				if(answer2 == 'Y' || answer2 == 'y')
				{
					if(answer1 == 1)
					{
						for(i = 0; i < 5; i++)
							for(j = 0; j < 10; j++){
								seatingChart1[i][j] = 0;
							}
						for(i = 0; i < SEAT_CAPACITY; i++)
						{
							seats1[i] = 0;
							finalSeats1[i] = 0;
						}	
						totalSeats = 0;
						numSeats = 0;
						
					}
					else if(answer1 == 2)
					{
						for(i = 0; i < 5; i++)
							for(j = 0; j < 10; j++){
								seatingChart2[i][j] = 0;
							}
						for(i = 0; i < SEAT_CAPACITY; i++)
						{
							seats2[i] = 0;
							finalSeats2[i] = 0;
						}	
						totalSeats = 0;
						numSeats = 0;
						
					}
					else if(answer1 == 3)
					{
						for(i = 0; i < 5; i++)
							for(j = 0; j < 10; j++){
								seatingChart3[i][j] = 0;
							}
						for(i = 0; i < SEAT_CAPACITY; i++)
						{
							seats3[i] = 0;
							finalSeats3[i] = 0;
						}	
						totalSeats = 0;
						numSeats = 0;
					}
				}
					else if (answer2 == 'N' || answer2 == 'n')	
					{
						if (answer1 == 1)
						{
							system("@cls||clear");
							cs1a();
							print_receipt1(movies, numSeats, seats1, answer1);
							output_receipt1(movies, numSeats, seats1, answer1);
							records1 += totalSeats;
								
						}
						else if(answer1 == 2)
						{
							system("@cls||clear");
							cs1a();
							print_receipt2(movies, numSeats, seats2, answer1);
							output_receipt2(movies, numSeats, seats2, answer1);
							records2 += totalSeats;
						}
						else if(answer1 == 3)
						{
							system("@cls||clear");
							cs1a();
							print_receipt3(movies, numSeats, seats3, answer1);
							output_receipt3(movies, numSeats, seats3, answer1);
							records3 += totalSeats;
						}
					}
	
			}while (answer2 == 'Y' || answer2 == 'y');
			
   			break;
	
		}	
		
		

	}while (answer2 != 'Y' || answer2 != 'y');	
	printf("\nClick any key if done.");
	getch();
	for(i = 0; i < SEAT_CAPACITY; i++)
		{
			seats1[i] = 0;
			seats2[i] = 0;
			seats3[i] = 0;
		}
	
} while(1);

    
    fclose(ifp);
    return 0;
}
