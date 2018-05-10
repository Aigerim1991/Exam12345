#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <iostream>
#include "Header.h"
void AddPassLoginAdmin()
{
	int p;
	char true_dat[10] = { 'A','d','m','i','n','1','2','3','4' };
	char pass[4], login[6];
	int count = 0;
	bool log_login = true, log_pass = true;
	printf("Введите логин:");
	scanf("%s", login);
	//login check
	while (count < 3)
	{
		for (int i = 0; i < 5; i++)
			if (login[i] != true_dat[i])
			{
				log_login = false;
				break;
			}
		if (log_login == false)
		{
			printf("Ошибка при входе в систему, пожалуйста, повторите попытку");
			scanf("%s", login);
			count++;
		}
		else
			break;
		if (count == 3)
		{
			printf("Вы провысили количество своих попыток");
			system("Pause");

		}
	}
	//pass check
	if (log_login == true)
	{
		printf("Введите пароль");
		scanf("%s", pass);
		count = 0;
		while (count < 3)
		{
			for (int i = 0; i < 4; i++)
				if (pass[i] != true_dat[i + 5])
				{
					log_pass = false;
					break;
				}
			if (log_pass == false)
			{
				printf("Вы ввели неправильный пароль, пожулуйста повторите попытку еще раз");
				scanf("%s", pass);
				count++;
			}
			else
				break;
			if (count == 3)
			{
				printf("Вы ограничиваете количество своих попыток");
				system("Pause");
			}
		}
	}
	else
	{
		printf("Вы ограничиваете количество своих попыток");
		system("Pause");

	}
	if (log_login == true && log_pass == true)
		printf("Вход в систему успешно завершен");


	clear();
	MainMenu(&p);
	clear();
}
void AddPassLoginUser()
{
	int p;
	char true_dat[10] = { 'U','s','e','r','1','2','3','4' };
	char pass[4], login[6];
	int count1 = 0;
	bool log_login = true, log_pass = true;
	printf("Введите логин:");
	scanf("%s", login);
	//login check
	while (count1 < 3)
	{
		for (int i = 0; i < 4; i++)
			if (login[i] != true_dat[i])
			{
				log_login = false;
				break;
			}
		if (log_login == false)
		{
			printf("Ошибка при входе в систему, пожалуйста, повторите попытку");
			scanf("%s", login);
			count1++;
		}
		else
			break;
		if (count1 == 3)
		{
			printf("Вы провысили количество своих попыток");
			system("Pause");

		}
	}
	//pass check
	if (log_login == true)
	{
		printf("Введите пароль");
		scanf("%s", pass);
		count1 = 0;
		while (count1 < 3)
		{
			for (int i = 0; i < 4; i++)
				if (pass[i] != true_dat[i + 4])
				{
					log_pass = false;
					break;
				}
			if (log_pass == false)
			{
				printf("Вы ввели неправильный пароль, пожулуйста повторите попытку еще раз");
				scanf("%s", pass);
				count1++;
			}
			else
				break;
			if (count1 == 3)
			{
				printf("Вы ограничиваете количество своих попыток");
				system("Pause");
			}
		}
	}
	else
	{
		printf("Вы ограничиваете количество своих попыток");
		system("Pause");

	}
	if (log_login == true && log_pass == true)
		printf("Вход в систему успешно завершен");
	clear();
	MainMenu(&p);
	system("Pause");

}