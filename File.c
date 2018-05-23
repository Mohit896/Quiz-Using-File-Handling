#define _GNU_SOURCE
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#define QNO 30
#define totques 10
#define size 200


void asked(char option[size], const char option1[size], const char option2[size],
	const char option3[size], const char option4[size],const char correct[size], const char category[size],FILE * fp,int *);
	
void Display();
	
void main()
{
	 char text[size],option1[size], option2[size], option3[size], option4[size], option[size], correct[size], category[size];
	char empty[256][256];
	int i,j,k;
	int arr[QNO],x,loc;
	time_t t;
	char line[256];
	int score = 0;
	
    FILE * fp;
    FILE * output;
    fp = fopen("Quiz.txt","r");
    output = fopen("NewText.txt","w");
    if(fp == NULL)
    {
    	printf("\n\n\n \t\t\t Quiz File Can't Be OPENED \t\t\t \n\n\n");
	}
	if(output == NULL)
	{
		printf("\n\n\n \t\t\t NewText File Can't Be CREATED \t\t\t \n\n\n");
	}

	Display();


	k = 0;
	
	for (i = 0; i < 30; i++)
	{
		arr[i] = 10 * i + 1;
	}

	for (j = 0; j < totques; j++)
	{
		srand((unsigned)time(&t));
		x = rand() % 3;
		loc = (3 * j) + x;

		for (i = arr[3 * j]; i < arr[loc]; i++)
		{
		fgets(empty[k],sizeof(empty[k]),fp);
			k++;
		}

		for (i = 1; i <= 10; i++)
		{
			fgets(line,sizeof(line),fp);	
			if(i==1)
			{
			  printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
			  fprintf(output,"Q%d) %s",j+1,line);
			  	
			}
			
				if(i==2)
				{
					fputs(line,output);	
				}
				
				if(i == 3)
			strncpy(option1,line,30);
			
				if(i == 4)
			strncpy(option2,line,30);
			
				if(i == 5)
			strncpy(option3,line,30);
			
				if(i == 6)
			strncpy(option4,line,30);	
	 	
			if (i >1&&i<=7)
			{
				printf("%s",line);
				
			}
			if (i == 8)
			strncpy(correct,line,30);	
				
			if (i == 9)
			strncpy(category,line,30);
		}

		
		asked(option, option1, option2, option3, option4, correct, category,output,&score);
		
		if(j!=9)
		{
			
		if (arr[loc] + 10 < arr[3 * (j + 1)])
		  {  
			for (i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
			{
			fgets(empty[k],sizeof(empty[k]),fp);
				k++;
			}
		  }
		}
		
		
		system("cls");
	}
	
	fprintf(output," \n You got total %d out of 40 ",score);
	
	fclose(fp);
	
	fclose(output);
	
	output = fopen("Newtext.txt","r");
	
	while(fgets(line,sizeof(line),output))
	{
		printf(" %s",line);
	}
	
	fclose(output);
	system("pause");
}



	void asked(char option[size], const char option1[size], const char option2[size], const char option3[size], const char option4[size],
	 const char correct[size], const char category[size],FILE * fp,int *score)
	{
		printf("Your Option : ");
		scanf("%str",&option[0]);
		option[1] = '\0';
		strupr(option);
		
			char correctanswer[size];
			char wronganswer[size];
			
			fprintf(fp,"%s \n",category);
			
		if (option[0] == correct[0])
		{
			if (option[0] == option1[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option1);
			if (option[0] == option2[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option2);
			if (option[0] == option3[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option3);
			if (option[0] == option4[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option4);
				
				*score += 4;
				
			fprintf(fp," \n You are awarded 4 marks for this correct answer \n ");
		}
		else
		{
		
			if (correct[0] == option1[0])
				strncpy(correctanswer, option1,24);
			if (correct[0] == option2[0])
				strncpy(correctanswer, option2,24);
			if (correct[0] == option3[0])
				strncpy(correctanswer, option3,24);
			if (correct[0] == option4[0])
				strncpy(correctanswer, option4,24);
			
			correctanswer[24] = '\0';
		
			if (option[0] == option1[0])
				strncpy(wronganswer, option1,24);
			if (option[0] == option2[0])
				strncpy(wronganswer, option2,24);
			if (option[0] == option3[0])
				strncpy(wronganswer, option3,24);
			if (option[0] == option4[0])
				strncpy(wronganswer, option4,24);

			wronganswer[24] = '\0';
			
			fprintf(fp," You entered     : %s \n", wronganswer);
			fprintf(fp," Correct answer  : %s \n", correctanswer);
			fprintf(fp," \n You are awarded 0 marks for this wrong answer \n ");
		}
		
			fprintf(fp," -----------------------------------------------------------------------------\n");		
			fprintf(fp," -----------------------------------------------------------------------------\n");	
	}
	

	void Display()
	{
		printf("\n\n\n\n\n\n");
		printf("\n\t   +-------+                          _______       _______                             ");
		printf("\n\t   |       |      |         |            |                /                              ");
		printf("\n\t   |       |      |         |            |               /                               ");
		printf("\n\t   |       |      |         |            |              /                                ");
		printf("\n\t   |    // |      |         |            |             /                                 ");
		printf("\n\t   |   //  |      |         |            |            /                                  ");
		printf("\n\t   +--//---+      |_________|         ___|___        /_______                          ");
		printf("\n\n\n\n\n\n\t\t\t   PRESS ENTER TO PLAY     ");
		printf("\n\n\n\t\t\t\t   RULES OF THE GAME   :     \n");
		printf("\t\t\t\t   1) 4 MARKS WILL BE AWARDED FOR CORRECT     \n");
		printf("\t\t\t\t   2) NO MARKS WILL AWARDED FOR INCORRECT     \n");
		printf("\t\t\t\t   3) SCORE CARD WILL BE GIVEN AT END         \n");
		system("pause");
		system("cls");				
	}
	







