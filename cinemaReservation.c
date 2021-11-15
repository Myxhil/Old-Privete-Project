#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//REMEMBER 0 = AVAILABLE, 1 = SOLD

int studio[26][121] = {0}; //Studio seat array

int sell[2401][6] = {0};
int s = 1;

float show[5][4] = { //Schedule
{12.00,14.30,17.30,19.45},
{12.30,15.00,18.00,20.00},
{12.00,13.45,15.15,18.00},
{12.15,15.00,16.30,19.00},
{12.15,14.00,16.00,17.45}
};
int a,maincmd = '0',i,j,k,l,smov,smovie,sshow,ssho,xstudio,seatcmd,available,seatqt,seatingcmd,xseat,xr,rval,srow,sseat,rn,sloc,savail;
int me,day,price,cp=1;

char movie1[50] = "The Wonderful Manspider 2";
char movie2[50] = "The Not So Bright Knight";
char movie3[50] = "Disnep - Molten";
char movie4[50] = "Captain Argentina : Summer Rebel";
char movie5[50] = "Dogzilla : Such Atomic Very Breath Wow";

void showday(day){
	if(day==1){
		printf("\nToday is Monday\n");
	}
	else if(day==2){
		printf("\nToday is Tuesday\n");
	}
	else if(day==3){
		printf("\nToday is Wednesday\n");
	}
	else if(day==4){
		printf("\nToday is Thrusday\n");
	}
	else if(day==5){
		printf("\nToday is Friday\n");
	}
	else if(day==6){
		printf("\nToday is Saturday\n");
	}
	else if(day==7){
		printf("\nToday is Sunday\n");
	}
	else{
		printf("\nToday is HOLIDAY\n");
	}
}

void seatavail(xmovie,xshow,xsloc){
	savail = 0;
	xstudio = (5*xmovie-1) + xshow + 1;
	if(studio[xstudio][xsloc] == 0){
		savail = 1;
	}
}

void rowvalid(xr){ //Row letter validation (must be ABCDEFGHIJ or abcdefghij)
	rval = 0;
	if(xr==65 || xr==66 || xr == 67 || xr == 68 || xr == 69 || xr == 70 || xr == 71 || xr == 72 || xr == 73 || xr == 74){
		rval = 1;
	}
	else if(xr == 97 || xr == 98 || xr == 99 || xr == 100 || xr == 101 || xr == 102 || xr == 103 || xr == 104 || xr == 105 || xr == 106){
		rval = 1;
	}
}

void rownum(xrow){
	if(xrow>90){
		rn = xrow - 96;}
	else if(xrow<90){
		rn = xrow - 64;}
}

void seatmapping(xrow,xcol){
	if(xrow>90){
		sloc = xcol + (xrow - 97)*12;
	}
	else if(xrow<90){
		sloc = xcol + (xrow - 65)*12;
	}
}

void seatmanage(smcmd,xmovie,xshow,xsloc){
	xstudio = (5*xmovie-1)+xshow+1;
	if(smcmd==1){
		studio[xstudio][xsloc] = 1;
	}
	else if(smcmd==0){
		studio[xstudio][xsloc] = 0;
	}
}

void moviedisp(int smov){
	if(smov==1){
		printf("Studio %d - %s\n",smov,movie1);
	}
	else if(smov==2){
		printf("Studio %d - %s\n",smov,movie2);
	}
	else if(smov==3){
		printf("Studio %d - %s\n",smov,movie3);
	}
	else if(smov==4){
		printf("Studio %d - %s\n",smov,movie4);
	}
	else if(smov==5){
		printf("Studio %d - %s\n",smov,movie5);
	}
}

void chardisp(letternum){
	if(letternum == 1){
		printf("A");
	}
	else if (letternum == 2){
		printf("B");
	}
	else if (letternum == 3){
		printf("C");
	}
	else if (letternum == 4){
		printf("D");
	}
	else if (letternum == 5){
		printf("E");
	}
	else if (letternum == 6){
		printf("F");
	}
	else if (letternum == 7){
		printf("G");
	}
	else if (letternum == 8){
		printf("H");
	}
	else if (letternum == 9){
		printf("I");
	}
	else if (letternum == 10){
		printf("J");
	}
}

void stat(int a){
	if(a==1){
		printf("X");	//SOLD
	}
	else if(a==0){
		printf("O");	//AVAILABLE
	}
}

void showdisplay(){
	for(i=0;i<5;i++){
		printf("\n\n");
		moviedisp(i+1);
		printf("\n\t%.2f\t%.2f\t%.2f\t%.2f",show[i][0],show[i][1],show[i][2],show[i][3]);
		}
	}

void seatstatus(xmovie,xshow){
	xstudio = (5*xmovie-1) + xshow+1;
	available = 120;
	for(j=1;j<=120;j++){
		if(studio[xstudio][j] == 1){
			available = available - 1;
		}
	}
}

void seatdisplay(xmovie,xshow){
	xstudio = (5*xmovie-1) + xshow+1;
	moviedisp(xmovie);
	printf("\nShow %d - %.2f\n\n",xshow+1,show[xmovie-1][xshow]);
	printf("=========================SCREEN=========================\n\n\n");
	for(i=0;i<24;i=i+12){
		chardisp((i+12)/12);
		printf("   ");
		for(j=1;j<=6;j++){
			stat(studio[xstudio][i+j]);
			printf("   ");}
		printf("   ");
		for(j;j<=12;j++){
			stat(studio[xstudio][i+j]);
			printf("   ");}
		chardisp((i+12)/12);
		printf("\n\n");
	}
	printf("\n\n");
	for(i;i<120;i=i+12){
		chardisp((i+12)/12);
		printf("   ");
		for(j=1;j<=6;j++){
			stat(studio[xstudio][i+j]);
			printf("   ");}
		printf("   ");
		for(j;j<=12;j++){
			stat(studio[xstudio][i+j]);
			printf("   ");}
		chardisp((i+12)/12);
		printf("\n\n");
	}
	printf("    1   2   3   4   5   6      7   8   9  10  11  12");
	seatstatus(xmovie,xshow);
	printf("\n\nAvailable seat(s) : %d\n\n",available);
}

int main(void){
printf("1. Monday\n");
printf("2. Tuesday\n");
printf("3. Wednesday\n");
printf("4. Thursday\n");
printf("5. Friday\n");
printf("6. Saturday\n");
printf("7. Sunday\n");
printf("Else - Holiday\n");
printf("Today is : ");
scanf("%d",&day);

system("cls");
if(day==1 || day==2 || day==3 || day==4){
	price = 40000;
}
else if(day == 5){
	price = 50000;
}
else{
	price = 60000;
}

srand (time(NULL)); //Seat availability declaration

for(i=0;i<=26;i++){
	for(j=1;j<=120;j++){
		studio[i][j] = rand()%2;
	}
}

	printf("25BLITZGIGAPLEX - TICKETING APPLICATION\n");
	showday(day);
	printf("\n");
	showdisplay();
	printf("\n\n");
	printf("1.Ticketing\n");
	printf("2.Seats display\n");
	printf("3.Pricing\n");
	printf("4.Help menu\n");
	printf("5.Ticket selling history\n");
	printf("9.EXIT\n");
	printf("\n\n\nEnter your selection command : ");
	
	while ( ( maincmd = getchar() ) != '9' ) {
	
	system("cls");
 	
 	switch ( maincmd ) {
	
	case '1'://TICKETING =======================================================================================================================================
	//Movie selection==================================================
	system("cls");
	printf("TICKETING \n");
	showdisplay();
	printf("\n\nSelect a movie...");
	printf("\nEnter movie code	: ");
	scanf("%d",&smovie);
	
	while(smovie<1 || smovie>5){
		if(smovie==-1){break;}
		system("cls");
		printf("TICKETING \n");
		showdisplay();
		printf("\n\nInvalid movie code....");
		printf("\n\nSelect a movie...");
		printf("\nEnter movie code	: ");
		scanf("%d",&smovie);
	}
	if(smovie==-1){break;}
	
	//Show selection====================================================
	system("cls");
	printf("TICKETING \n\n");
	moviedisp(smovie);
	printf("\n\tShow 1 - %.2f\n\tShow 2 - %.2f\n\tShow 3 - %.2f\n\tShow 4 - %.2f",show[smovie-1][0],show[smovie-1][1],show[smovie-1][2],show[smovie-1][3]);
	printf("\n\nSelect a show time...");
	printf("\nEnter show time code	: ");
	scanf("%d",&sshow);
	
	while(sshow<1 || sshow>4){
		if(sshow==-1){break;}
		system("cls");
		printf("TICKETING \n");
		printf("\n\tShow 1 - %.2f\n\tShow 2 - %.2f\n\tShow 3 - %.2f\n\tShow 4 - %.2f",show[smovie-1][0],show[smovie-1][1],show[smovie-1][2],show[smovie-1][3]);
		printf("\n\nInvalid show time code....");
		printf("\n\nSelect a show time...");
		printf("\nEnter show time code	: ");
		scanf("%d",&sshow);
	}
		if(sshow==-1){break;}
	
	//Seat selection====================================================
	system("cls");//Seat quantity===========
	printf("TICKETING \n\n");
	seatdisplay(smovie,sshow-1);
	printf("How many seat(s) do you want to book?	: ");
	scanf("%d",&seatqt);
	
	while(seatqt>available||seatqt<1){
		if(seatqt==-1){break;}
		system("cls");
		printf("TICKETING \n\n");
		seatdisplay(smovie,sshow-1);
		if(seatqt>available){
		printf("Sorry that's more than the seats available...\nHow many seat(s) do you want to book?	: ");}
		else if(seatqt<1){
		printf("Please be serious this time...\nHow many seat(s) do you want to book?	: ");}
		scanf("%d",&seatqt);
	}
	if(seatqt==-1){break;}
	
	for(k=1;k<=seatqt;k++){//SEATBUYING ITERATION=====================

	rval = 0;
	while(rval!=1){
		system("cls");
		printf("TICKETING \n\n");
		seatdisplay(smovie,sshow-1);
		printf("\nEnter ROW IN ALPHABET (A-J)\nSelect seat %d ROW : ",k);
		srow = getchar();
		rowvalid(srow);
	}
	
	rownum(srow);
	
	system("cls");//Seat number selection====
	printf("TICKETING \n\n");
	seatdisplay(smovie,sshow-1);
	printf("\nEnter ROW IN ALPHABET (A-J)\nSelect seat %d ROW : ",k);
	chardisp(rn);
	printf("\nSelect seat %d NUMBER : ",k);
	scanf("%d",&sseat);
	
	while(sseat<1 || sseat>12){
		system("cls");
		printf("TICKETING \n\n");
		seatdisplay(smovie,sshow-1);
		printf("\nEnter ROW IN ALPHABET (A-J)\nSelect seat %d ROW : ",k);
		chardisp(rn);
		printf("\nInvalid seat NUMBER\nSelect seat %d NUMBER : ",k);
		scanf("%d",&sseat);
	}
	seatmapping(srow,sseat);
	seatavail(smovie,sshow-1,sloc);
	
	while(savail!=1){ //CHECK IF THE SEAT AVAILABLE

	rval = 0;
	
	while(rval!=1){
		system("cls");
		
		printf("TICKETING \n\n");
		seatdisplay(smovie,sshow-1);
		printf("\nSorry seat ");
		chardisp(rn);
		printf("%d is SOLD... Select another seat...\n",sseat);
		printf("\nEnter ROW IN ALPHABET (A-J)\nSelect seat %d ROW : ",k);
		srow = getchar();
		rowvalid(srow);
	}
	
	rownum(srow);
	
	system("cls");//Seat number selection====
	printf("TICKETING \n\n");
	seatdisplay(smovie,sshow-1);
	printf("\nEnter ROW IN ALPHABET (A-J)\nSelect seat %d ROW : ",k);
	chardisp(rn);
	printf("\nSelect seat %d NUMBER : ",k);
	scanf("%d",&sseat);
	
	while(sseat<1 || sseat>12){
		system("cls");
		printf("TICKETING \n\n");
		seatdisplay(smovie,sshow-1);
		printf("\nEnter ROW IN ALPHABET (A-J)\nSelect seat %d ROW : ",k);
		chardisp(rn);
		printf("\nInvalid seat NUMBER\nSelect seat %d NUMBER : ",k);
		scanf("%d",&sseat);
	}
	seatmapping(srow,sseat);
	seatavail(smovie,sshow-1,sloc);
	}
	
	seatmanage(1,smovie,sshow-1,sloc);
	sell[s][1] = xstudio;
	sell[s][2] = rn;
	sell[s][3] = sseat;
	sell[s][4] = smovie;
	sell[s][5] = sshow;
	s++;
	}
	
	system("cls");
	printf("TICKETING \n\n");
	seatdisplay(smovie,sshow-1);
	printf("\n\nBought seat(s) : ");
	for(l=cp;l<s;l++){
		printf("\n- ");
		chardisp(sell[l][2]);
		printf("%d, ",sell[l][3]);
	}
	
	system("pause");
	
	system("cls");
	printf("TICKETING \n\nTICKETS : \n");

	for(l=cp;l<s;l++){
		printf("\n===================================================\n");
		moviedisp(sell[l][4]);
		printf("\nShowtime	: %.2f\n",show[sell[l][4]-1][sell[l][5]-1]);
		printf("Seat		: ");
		chardisp(sell[l][2]);
		printf("%d",sell[l][3]);
		printf("\nTicket price - %d",price);
		printf("\n===================================================\n");
	}
	cp = s;
	//===========================================================================================================================================================
	printf("\n\nPress ENTER key to continue... \n");
	printf("or Select another operation : ");
	getchar();
	break;
	
	case '2': //SEAT DISPLAY=====================================================================================================================================
	seatcmd = 0;
	while(seatcmd!=-1){
	system("cls");
	printf("SEATS DISPLAY \n\n");
	showdisplay();
	printf("\n\nSelect studio	: ");
	scanf("%d",&seatcmd);
	smovie = seatcmd;
	while(seatcmd<1 || seatcmd>5){
		if(seatcmd==-1){break;}
		system("cls");
		printf("SEATS DISPLAY \n\n");
		showdisplay();
		printf("\n\nInvalid studio code...\n");
		printf("Select studio	: ");
		scanf("%d",&seatcmd);
		smovie = seatcmd;
	}
	if(seatcmd==-1){break;}
	printf("Select showtime	: ");
	scanf("%d",&seatcmd);
	sshow = seatcmd-1;
	while(seatcmd<1 || seatcmd>4){
		if(seatcmd==-1){break;}
		system("cls");
		printf("SEATS DISPLAY \n\n");
		showdisplay();
		printf("\n\nSelect studio	: %d",smovie);
		printf("\nInvalid showtime code...\n");
		printf("Select showtime	: ");
		scanf("%d",&seatcmd);
		sshow = seatcmd-1;
	}
	if(seatcmd==-1){break;}
	system("cls");
	printf("SEATS DISPLAY \n\n");
	seatdisplay(smovie,sshow);
	system("pause");
	}
	if(seatcmd==-1){break;}
	printf("Press ENTER key to continue... \n");
	printf("or Select another operation : ");
	getchar();
	break;//=====================================================================================================================================================
	
	case '3': //PRICING==========================================================================================================================================
	printf("PRICING \n\n");
	printf("Monday - Thursday : Rp 40.000,-\n\n");
	printf("Friday            : Rp 50.000,-\n\n");
	printf("Weekend / Holiday : Rp 60.000,-\n\n");
	printf("Press ENTER key to continue... \n");
	printf("or Select another operation : ");
	getchar();
	break;//=====================================================================================================================================================
	
	case '4':
	printf("HELP MENU \n\n");
	printf("Just contact me... Andreas Pratama Aji\n\n");
	printf("Press ENTER key to continue... \n");
	printf("or Select another operation : ");
	getchar();
	break;
	
	case '5':
	printf("TICKET SELLING HISTORY \n\n");
	for(l=1;l<s;l++){
		printf("\n===================================================\n");
		moviedisp(sell[l][4]);
		printf("\nShowtime	: %.2f\n",show[sell[l][4]-1][sell[l][5]-1]);
		printf("Seat		: ");
		chardisp(sell[l][2]);
		printf("%d",sell[l][3]);
		printf("\nTicket price - %d",price);
		printf("\n===================================================\n");
	}
	printf("Press ENTER key to continue... \n");
	printf("or Select another operation : ");
	getchar();
	break;
	
	case 10: // ENTER key
	printf("25BLITZGIGAPLEX - TICKETING APPLICATION\n");
	showday(day);
	printf("\n");
	showdisplay();
	printf("\n\n");
	printf("1.Ticketing\n");
	printf("2.Seats display\n");
	printf("3.Pricing\n");
	printf("4.Help menu\n");
	printf("5.Ticket selling history\n");
	printf("9.EXIT\n");
	printf("\n\n\nEnter your selection command : ");
	break;
	 
	default:
	printf("25BLITZGIGAPLEX - TICKETING APPLICATION\n");
	showday(day);
	printf("\n");
	showdisplay();
	printf("\n\n");
	printf("1.Ticketing\n");
	printf("2.Seats display\n");
	printf("3.Pricing\n");
	printf("4.Help menu\n");
	printf("5.Ticket selling history\n");
	printf("9.EXIT\n");
	printf("\n\n\nINCORRECT selection entered. \n" );
	printf("Enter your selection command : ");
	getchar();
	break;
	}

	}
	system("cls");
	printf("THANKYOU! COME AGAIN!");
}
