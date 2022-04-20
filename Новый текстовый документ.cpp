#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int zakr_kluch[] = { 1, 2, 4, 9, 20, 38, 76, 152 };
int otkr_kluch[8];
int c, sum;
int n = 11, m = 317, nmin1 = 173;
int ASCII[8] = { 0 };
int i, j, k;
int st = 0;
int length;
int zashifrtext = 0;
int razshifrtext[100] = { 0 };
int result1[100] = { 0 };
unsigned int a = 0;
char textin[101] = { 'a' };
char output[101] = { 'a' };
char polnrashifrovka[100];
char s1[50];
char s2[50];


void Zashifrovka()
{
	printf("Введите количество букв\n");
	scanf("%d", &length);
	printf("Введите текст\n");
	scanf("%s", &textin);
	for (i = 0; i < length; i++) {
		a = textin[i];
		printf("ASCII-кодировкa: %d\n", a);
		for (j = 7; j != -1; j--)
		{
			ASCII[j] = a % 2;
			a = a / 2;
		}
		printf("Бинарный код  %c:", textin[i]);
		for (j = 0; j < 8; j++)
		{
			printf("%d", ASCII[j]);

		}
		j = 0;
		for (k = 0; k < 8; k++) {
			if (ASCII[j] == 1) zashifrtext += otkr_kluch[k];
			j++;
		}
		printf("\nШифрограмма: %d\n", zashifrtext);
		_itoa(zashifrtext, s1, 10);
		strcat(s2,s1);
		
	
		
		zashifrtext = 0;
	}
	printf("\nИтоговое шифрование: %s", s2);
	
}
void Razshifrovka()
{
	printf("Введите количество букв\n");
	scanf("%d", &length);
	printf("Введите шифрограммы через пробел\n");
	for (i = 0; i < length; i++)
	{
		scanf("%d", &razshifrtext[i]);
	}
	for (i = 0; i < length; i++)
	{
		result1[i] = razshifrtext[i] * nmin1 % m;
		printf("Суммарный вес %d символа: %d\n", i + 1, result1[i]);
	}
	for (j = 0; j < length; j++)
	{
		for (i = 7; i != -1; i--)
		{
			if (result1[j] >= zakr_kluch[i])
			{
				result1[j] -= zakr_kluch[i];
				ASCII[i] = 1;
			}
			else
				ASCII[i] = 0;
		}
		printf("Бинарный код для %d буквы: ", j + 1);
		for (i = 0; i < 8; i++)
		{
			printf("%d", ASCII[i]);

		}
		printf("\nБуква в ASCII-кодировке: ");
		sum = 0;
		st = 0;
		for (i = 7; i != -1; i--)
		{
			if (ASCII[i] == 1)
				sum = sum + (int)(pow(2, st) + 0.5);
			st++;
		}
		printf("%d\n", sum);
		printf("Полученная буква при дешифровании: %c\n\n", sum);
		output[j] = (char)sum;
	}
	printf("Полученный текст: %s", output);
}

int main() {
	
	system("chcp 1251");
	system("cls");
	for (i = 0; i < 8; i++) 
	{
		otkr_kluch[i] = zakr_kluch[i] * n % m;
		
	}
	
	
	printf("Выберите:\n1.Зашифровать\n2.Расшифровать\n3.Выход\n");
	scanf("%d", &c);
	if (c == 1)
	{
		
		system("cls");

		Zashifrovka();

	}
	else if (c == 2)
	{
		system("cls");
		Razshifrovka();

	}
	else if (c == 3)
	{
		return 0;

	}
	else
	{
		system("cls");
		printf("Неправильный ввод\n\n\n\n");
	}

	
	return 0;
}

