//��������� ��� �������� �������� � �������� �����������.
#include<stdio.h>;
#include<locale.h>
#include<ctype.h>;
#include<stdbool.h>;

#define STOP '|'

int main(void){
	setlocale(LC_ALL,"Rus");
	char c;//����������� ������.
	char prev;//���������� ������.
	long kol_chars = 0;//�������.
	int kol_lines = 0;//������
	int kol_words = 0;//�����.
	int kol_notlines = 0;//�������� ������.
	bool inwords = false;
	printf("������� ����� ��� �������� (| ��� ���������� ������ ���������.)\n");
	prev = '\n';
	
	while ((c=getchar()) != STOP)
	{
		c++;
		//������� �����.
		if (c=='\n')
		{
			kol_lines++;
		}
		//������� ����.
		if (!isspace(c) && !inwords)//������ �����.
		{
			inwords = true;
			kol_words++;
		}
		if (isspace(c) && inwords)//����� �����.
		{
			inwords = false;
		}
		prev = c;
	}
	if (prev !='\n')
	{
		kol_notlines = 1;
	}
	printf("�������� = %ld, ���� = %d, ����� = %d,",kol_chars,kol_words,kol_lines);
	printf("�������� ����� = %d\n",kol_notlines);
	return 0;
}