#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <iostream>
#include "Header.h"
FILE * pt;
struct  Place
{
	
	char city[200];
	char region[200];
};
struct Date
{
	int m;
	int d;
	int y;
	int h;
	int min;
};
struct Person
{
	char Name[100];
	Date dob;
	char iin[12];
};
struct Information
{
	int id;
	char desriptionInformation[300];
	Place place;
	Date date;
	Person person;
	int status;
	Person responce;
	Date dateAnswer;
};
struct Realtor
{
	int id;
	char path[300];
	int status;
};
void ds(char *pt)
{
	char Des[10][50] = { "Однокомнатная","Двухкомнатная","Трехкомнатная","Свободные", "Забронированные"};
	int N = 1 + rand() % 10;
	strcpy(pt, Des[N]);
}

void clear()
{
	system("cls");
}
void MainMenu(int *p)
{
	printf("0. Выберите усулугу.\n");
	printf("1. Введите пароль и логин для Администрации.\n");
	printf("2. Введите пароль и логин для Пользователя.\n");
	scanf("%d", p);
}

void NewName(char *pt)
{
	char Des[10][50] = { "Айгерим","Канат","Сергей","Слава", "Иван","Артур","Рустам","Петр","Марат","Арман" };
	int N = 1 + rand() % 10;
	strcpy(pt, Des[N]);
}
void NewRegion(char *pt)
{
	char Des[10][50] = { "Орбита","Коктем","Самал","Нурлытау", "Ерменсай","Шанырак","Абай","Думан","Жайлау","Ремизовка" };
	int N = 1 + rand() % 10;
	strcpy(pt, Des[N]);
}
int IdNew()
{
	return 100000 + rand() % 9999;
}
void NewDate(Date *pt)
{
	pt->d = 1 + rand() % 20;
	pt->m = 1 + rand() % 12;
	pt->y = 2018;
}
void NewHour(Date*pt)
{
	pt->h = 1 + rand() % 24;
	pt->min = 1 + rand() % 59;
}
void iin(Information *pt)
{
	sprintf(pt->person.iin, "%d%d%d%d", pt->person.dob.y, pt->person.dob.d, pt->person.dob.m, pt->person.iin);
}
void main()
{
	int p;
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	char past[200] = "Admin.txt";
	char comand[200] = "User.txt";
	MainMenu(&p);
	if (p == 2)
	{
		AddPassLoginUser();
		for (int i = 0; i < 10; i++)
	{
			Realtor New;
		New.id = IdNew();
		char md[300];
		sprintf(md, "md %s\\%d", past, New.id);
		system(md);
		sprintf(New.path, "%s\\%d\\information_%d.txt", past, New.id, New.id);
		if ((pt = fopen(New.path, "a+")) != NULL)
		{
			Information information;
			information.id = New.id;

			ds(information.desriptionInformation);
						
			NewRegion(information.place.region);
			NewDate(&information.date);
			NewHour(&information.date);
			NewName(information.person.Name);
			NewDate(&information.person.dob);
			iin(&information);
			fwrite(&information, sizeof(Information), 1, pt);
		}
		fclose(pt);
		AddPassLoginAdmin();
		if (p == 1)
		{
			if ((pt = fopen(comand, "a+")) != NULL)
		{

			fwrite(&New, sizeof(Realtor), 1, pt);
		}
		fclose(pt);
		}
		
	}
	
		
	}
}