//Программа для подсчета символов в введеном предложении.
#include<stdio.h>;
#include<locale.h>
#include<ctype.h>;
#include<stdbool.h>;

#define STOP '|'

int main(void){
	setlocale(LC_ALL,"Rus");
	char c;//Прочитанный символ.
	char prev;//Предыдущий символ.
	long kol_chars = 0;//символы.
	int kol_lines = 0;//строки
	int kol_words = 0;//Слова.
	int kol_notlines = 0;//Неполные строки.
	bool inwords = false;
	printf("Введите текст для подсчета (| для заврешения работы программы.)\n");
	prev = '\n';
	
	while ((c=getchar()) != STOP)
	{
		c++;
		//Подсчет строк.
		if (c=='\n')
		{
			kol_lines++;
		}
		//Подсчет слов.
		if (!isspace(c) && !inwords)//Начало слова.
		{
			inwords = true;
			kol_words++;
		}
		if (isspace(c) && inwords)//конец слова.
		{
			inwords = false;
		}
		prev = c;
	}
	if (prev !='\n')
	{
		kol_notlines = 1;
	}
	printf("символов = %ld, слов = %d, строк = %d,",kol_chars,kol_words,kol_lines);
	printf("неполных строк = %d\n",kol_notlines);
	return 0;
}