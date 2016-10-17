#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
int fs(int x);
void game(int numplay);
struct player
{
	int choice,num;
	float betting,balance,winning,loss;
	char name[100],colour[20];
}p[10];
int winloss(int c,int x,int numplay)
	{
		if(x==1)
		{
		p[c].winning=(numplay)*p[c].betting;
        p[c].balance+=p[c].winning;
    	printf("Congratulations you WIN!! Your Balance is: %f\n",p[c].balance);
    	}
    	else
    	{
		p[c].loss=p[c].betting;
        p[c].balance-=p[c].loss;
        printf("Sorry you lose!! Your Balance is: %f\n",p[c].balance);
		}
	}
void main()
{
	int numplay;
	printf("****************************Welcome to the Game of Roullete************************************\n");
	Sleep(1000);
	printf("****************Desinged by Sanket Goutam & Yatharth Gupta*********************\n");
	Sleep(3000);
	while(!)
	{
		printf("0  ");
		Sleep(300);
		printf("1  ");
	}
	system("cls");
	printf("So let Us begin: Press any key to continue\n");
	getch();
	system("cls");
	printf("Here are the rules for the game of roullete:\n\n");
	printf(">There are 38 slots starting from 0 to 37. They have been marked in three colours: Green(0&37), Red(Fibonnaci Series), Black(The Rest).\n\n");
	printf(">You have to bet on either the colour codes or the even and odd number or you may push your luck to a Single Number\n\n");
	printf(">If you win you get as much money you bet from everyone from the table, but of you lose you simply lose the amount bet.\n\n");
	printf("So stack up your cash and Let's Play the GAME........\n\n");
	Sleep(5000);
	system("cls");
	printf("Enter the number of players\t");
	scanf("%d",&numplay);
	game(numplay);
	getch();
}
int fs(int x)
{
    int i,ser[40]={0,1};		
    for(i=0;i<40;i++)
    {
                      ser[i+2]=ser[i]+ser[i+1];
                      ser[i]=ser[i+1];
                      ser[i+1]=ser[i+2];
    }
    for(i=0;i<40;i++)
    {
                     if(ser[i]==x)
                     return 1;
                     else
                     return 0;
    }
}

void game(int numplay)
{
	char ch;
	int i,j,spin;
	int dealerbal=10000;
	for(i=0;i<numplay;i++)
	{
		printf("Player No. %d\n",i+1);
		printf("Enter your name:\n");
		scanf("%s",&p[i].name);
		printf("Enter your Balance amount\t");
		scanf("%f",&p[i].balance);
	}
	while(dealerbal>0)
	{
		for(i=0;i<numplay;i++)
		{
			printf("%s\n",p[i].name);
			printf("Enter your betting amount:\n");
			scanf("%f",&p[i].betting);
			printf("Enter your choice for bet\n 1.Odd 2.Even 3.Colour 4.Number\n");
			scanf("%d",&p[i].choice);
			switch(p[i].choice)
			{
				case 1:
					printf("You chose to bet on Odd no.s:\n");
					break;
				case 2:
					printf("You chose to bet on Even no.s:\n");
					break;
				case 3:
					printf("You chose to bet on the colours\n Enter the colour you chose to bet on\t");
					scanf("%s",&p[i].colour[20]);
					break;
				case 4:
					printf("Enter the number you chose to bet on(between 0 and 37):\t");
					scanf("%d",&p[i].num);
					break;
				default:
					printf("It seems you wish to stay put for now.\n");
					break;
			}
		}
		printf("Spinning the wheel!! Get ready with your chips!!");
		spin=rand()%38;
		printf("The ball has landed on %d\t",spin);
		for(i=0;i<numplay;i++)
		{
                                switch(p[i].choice)
                                {
                                                 case 1:
                                                      if(spin%2!=0)
                                                         	winloss(i,1,numplay);
                                                      else if(spin==0||spin==37)                           
                                                      		winloss(i,0,numplay);
                                                      else
                                                      		winloss(i,0,numplay);
                                                      break;
                                                 case 2:
                                                 	   if(spin%2==0)
                                                         	winloss(i,1,numplay);
                                                      else if(spin==0||spin==37)
                                                      		winloss(i,0,numplay);
                                                      else
                                                      		winloss(i,0,numplay);
                                                      break;
                                                 case 3:
                                                 	    if(strcmp(p[i].colour,"Red")==0)
                                                 	    {
                                                 	    	if(fs(spin))
                                                         			winloss(i,1,numplay);
                                                 	    	else
                                                 	    		winloss(i,0,numplay);
                                                 	    }
                                                 	    else if(strcmp(p[i].colour,"Green")==0)
                                                 	    {	
                                                 	    	if(spin==0||spin==37)
                                                         		winloss(i,1,numplay);
                                                 	    	else
                                                      			winloss(i,0,numplay);
                                                 	    }
                                                 	    else
                                                 	    {
                                                 	    	if(spin==0||spin==37||fs(spin))
                                                      				winloss(i,0,numplay);
                                                 	    	else
                                                         			winloss(i,1,numplay);
                                                 		}
                                                 	    break;
                                                 case 4:
												        if(p[i].num==spin)
                                                         	winloss(i,1,numplay);
												        else
                                                      		winloss(i,0,numplay);
												        break;
												default:
														break;
								}
					dealerbal+=(p[i].loss-p[i].winning);
					ch=getch();
					if(ch=='q'||ch=='Q')
						break;
					if(p[i].balance<=0)
						{
							int j;
							for (j=i;j<=numplay;j++)
								p[j]=p[j+1];
							numplay--;
							printf("Sorry but you are out of money and we don't encourage debts.\nContinuing the game with %d players",numplay);
						}	
		}
	}
}
