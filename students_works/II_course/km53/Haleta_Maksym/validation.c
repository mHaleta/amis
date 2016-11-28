#include<stdio.h>
#include<stdbool.h>
#include "windows.h"
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>

typedef struct Examiner
{
	char surname[25];
	char name[25];
	char father_name[25];
	struct Examiner *next_1;
} examiner;

examiner *head_1=NULL;

typedef struct Student
{
	char surname[25];
	char name[25];
	char father_name[25];
	char group[6];
	int mark_quantity;
	char mark;
	struct Student *next_2;
} student;

student *head_2=NULL;

void gotoxy(int xpos, int ypos)
{
	COORD scrn;    
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput,scrn);
}

void textcolor(int text)
{
   HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut,(WORD)(text));
}

examiner *new_examiner();

void add_new_examiner(examiner *);

student *new_student();

void add_new_student(student *);

void list_examiner();

void list_student();

void free_memory();

void menu()
{
	char key;
	while(1)
	{
		textcolor(15);
		system("cls");
		printf("\n 1) Press '1' to add new examiner into the list of examiners");
		printf("\n 2) Press '2' to add new student into the list of students");
		printf("\n 3) Press '3' to show the list of examiners");
		printf("\n 4) Press '4' to show the list of students");
		printf("\n 5) Press 'ESC' to quit");
		printf("\n\n Press the necessary key: ");
		key=getch();
		switch(key)
		{
			case '1':
				add_new_examiner(new_examiner());
				break;
			case '2':
				add_new_student(new_student());
				break;
			case '3':
				list_examiner();
				break;
			case '4':
				list_student();
				break;
			case 27:
				free_memory();
				exit(0);
			default:
				gotoxy(1,7);
				textcolor(12);
				printf("Press the necessary key: ");
				Sleep(100);
				break;
		}
	}
}

bool check_pib(const char *string)
{
	bool b=true;
	int i=0;
	while(i!=strlen(string))
	{
		if(isalpha(string[i])==false)
		{
			b=false;
			break;
		}
		i+=1;
	}
	return b;
}

bool check_group(const char *string)
{
	bool b=true;
	if((isalpha(string[0])==false)||(isalpha(string[1])==false)||(string[2]!='-')||(isdigit(string[3])==false)||(isdigit(string[4])==false))
		b=false;
	return b;
}

examiner *new_examiner()
{
	examiner *element_1=(examiner*)malloc(sizeof(examiner));
	while(1)
	{
		system("cls");
		textcolor(15);
		printf("\n Enter the surname of examiner: ");
		gets(element_1->surname);
		if((strlen(element_1->surname)>25)||(strlen(element_1->surname)<2)||(check_pib(element_1->surname)==false))
		{
			system("cls");
			textcolor(12);
			printf("\n Enter the surname of examiner: ");
			Sleep(100);
		}
		else
			break;
	}
	while(1)
	{
		system("cls");
		textcolor(15);
		printf("\n Enter the name of examiner: ");
		gets(element_1->name);
		if((strlen(element_1->name)>25)||(strlen(element_1->name)<2)||(check_pib(element_1->name)==false))
		{
			system("cls");
			textcolor(12);
			printf("\n Enter the name of examiner: ");
			Sleep(100);
		}
		else
			break;
	}
	while(1)
	{
		system("cls");
		textcolor(15);
		printf("\n Enter the father_name of examiner: ");
		gets(element_1->father_name);
		if((strlen(element_1->father_name)>25)||(strlen(element_1->father_name)<2)||(check_pib(element_1->father_name)==false))
		{
			system("cls");
			textcolor(12);
			printf("\n Enter the father_name of examiner: ");
			Sleep(100);
		}
		else
			break;
	}
	return element_1;
}

void add_new_examiner(examiner *element_1)
{
	examiner *current_1;
	if(head_1==NULL)
	{
		element_1->next_1=NULL;
		head_1=element_1;
	}
	else
	{
		current_1=head_1;
		while(current_1->next_1!=NULL)
			current_1=current_1->next_1;
		current_1->next_1=element_1;
		element_1->next_1=NULL;
	}
	system("cls");
	return;
}

student *new_student()
{
	student *element_2=(student*)malloc(sizeof(student));
	while(1)
	{
		system("cls");
		textcolor(15);
		printf("\n Enter the surname of student: ");
		gets(element_2->surname);
		if((strlen(element_2->surname)>25)||(strlen(element_2->surname)<2)||(check_pib(element_2->surname)==false))
		{
			system("cls");
			textcolor(12);
			printf("\n Enter the surname of student: ");
			Sleep(100);
		}
		else
			break;
	}
	while(1)
	{
		system("cls");
		textcolor(15);
		printf("\n Enter the name of student: ");
		gets(element_2->name);
		if((strlen(element_2->name)>25)||(strlen(element_2->name)<2)||(check_pib(element_2->name)==false))
		{
			system("cls");
			textcolor(12);
			printf("\n Enter the name of student: ");
			Sleep(100);
		}
		else
			break;
	}
	while(1)
	{
		system("cls");
		textcolor(15);
		printf("\n Enter the father_name of student: ");
		gets(element_2->father_name);
		if((strlen(element_2->father_name)>25)||(strlen(element_2->father_name)<2)||(check_pib(element_2->father_name)==false))
		{
			system("cls");
			textcolor(12);
			printf("\n Enter the father_name of student: ");
			Sleep(100);
		}
		else
			break;
	}
	while(1)
	{
		system("cls");
		textcolor(15);
		printf("\n Enter the academic group: ");
		gets(element_2->group);
		if((strlen(element_2->group)!=5)||(check_group(element_2->group)==false))
		{
			system("cls");
			textcolor(12);
			printf("\n Enter the academic group: ");
			Sleep(100);
		}
		else
			break;
	}
	while(1)
	{
		int y;
		system("cls");
		textcolor(15);
		printf("\n Enter the mark quantity (0..100): ");
		fflush(stdin);
		y=scanf("%d",&element_2->mark_quantity);
		if((y==0)||(element_2->mark_quantity<0)||(element_2->mark_quantity>100))
		{
			system("cls");
			textcolor(12);
			printf("\n Enter the mark quantity (0..100): ");
			Sleep(100);
		}
		else
			break;
	}
	if(element_2->mark_quantity<60)
		element_2->mark='F';
	if((element_2->mark_quantity>=60)&&(element_2->mark_quantity<=64))
		element_2->mark='E';
	if((element_2->mark_quantity>=65)&&(element_2->mark_quantity<=74))
		element_2->mark='D';
	if((element_2->mark_quantity>=75)&&(element_2->mark_quantity<=84))
		element_2->mark='C';
	if((element_2->mark_quantity>=85)&&(element_2->mark_quantity<=94))
		element_2->mark='B';
	if((element_2->mark_quantity>=95)&&(element_2->mark_quantity<=100))
		element_2->mark='E';
	return element_2;
}

void add_new_student(student *element_2)
{
	student *current_2;
	if(head_2==NULL)
	{
		element_2->next_2=NULL;
		head_2=element_2;
	}
	else
	{
		current_2=head_2;
		while(current_2->next_2!=NULL)
			current_2=current_2->next_2;
		current_2->next_2=element_2;
		element_2->next_2=NULL;
	}
	system("cls");
	return;
}

void list_examiner()
{
	if(head_1==NULL)
	{
		system("cls");
		printf("\n\n  Empty list");
		printf("\n\n  Press any key");
		getch();
		return;
	}
	int counter_1=1;
	examiner *tmp_1=head_1;
	system("cls");
	while(tmp_1!=NULL)
	{
		printf("\n %d) %s %s %s",counter_1,tmp_1->surname,tmp_1->name,tmp_1->father_name);
		tmp_1=tmp_1->next_1;
		counter_1+=1;
	}
	printf("\n\n Press any key");
	getch();
	return;
}

void list_student()
{
	if(head_2==NULL)
	{
		system("cls");
		printf("\n\n  Empty list");
		printf("\n\n  Press any key");
		getch();
		return;
	}
	int counter_2=1;
	student *tmp_2=head_2;
	system("cls");
	while(tmp_2!=NULL)
	{
		printf("\n %d) %s %s %s   %s   %d   %c",counter_2,tmp_2->surname,tmp_2->name,tmp_2->father_name,tmp_2->group,tmp_2->mark_quantity,tmp_2->mark);
		tmp_2=tmp_2->next_2;
		counter_2+=1;
	}
	printf("\n\n Press any key");
	getch();
	return;
}

void free_memory()
{
	if((head_1==NULL)&&(head_2==NULL))
		return;
	examiner *prev_1=head_1;
	student *prev_2=head_2;
	while(prev_1!=NULL)
	{
		head_1=prev_1;
		prev_1=prev_1->next_1;
		free(head_1);
		head_1=NULL;
	}
	while(prev_2!=NULL)
	{
		head_2=prev_2;
		prev_2=prev_2->next_2;
		free(head_2);
		head_2=NULL;
	}
}

int main()
{
	menu();
}
