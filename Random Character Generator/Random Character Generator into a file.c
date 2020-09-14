#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	char c[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char random=c[rand()%26];
	char word[15],line[255];
	int f=0;
	fp = fopen("dictionary.txt", "w");
	fclose(fp);
	printf("Hey!!!! Welcome...\n\nEnter a word which starts with the character %c",random);
	gets(word);
	if(word[0]>='a'&&word[0]<='z')
		word[0]=word[0]-32;
	back:if(word[0]!=random)
		{
			printf("Please enter a word whose first letter is %c", random);
			gets(word);
			if(word[0]>='a'&&word[0]<='z')
				word[0]=word[0]-32;
		}
	if(word[0]!=random)
		goto back;
	fp=fopen("dictionary.txt","r");
	while(fgets(line, 255, fp))
	{
		char *ptr = strstr(line, word);
		if(ptr!=NULL)
		{
			f=1;
			break;
		}
	}
	fclose(fp);
	if(f==1)
		printf("Oops!!.....Words already exists in Dictionary");
	else
	{
		fp= fopen("dictionary.txt", "a");
		fputs(word,fp);
		fprintf(fp, "\n");
		fclose(fp);
		printf("Your word is added into Dictionary");
	}
	return 0;
}
