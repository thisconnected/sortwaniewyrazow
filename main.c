#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXWORDLEN 256

char word[MAXWORDLEN];
int nChars=0;
int nWords=0;
char* pTextData;
char** ppWords;
int temp;

/*int counter()
{
    FILE *file;
    if(file=fopen())

    while(fscanf(file,"%255s",word)>0) {
    nChars+=strlen(word);
    nWords++;
}
}*/
int SortFileWords(const char* inFileName, const char* outFileName)
{
    //otwieranie pliku
    FILE *infile;
    if((infile=fopen(inFileName,"r"))==NULL)
    {
        printf("Blad");
        return 0;
    }
    //liczenie
    while(fscanf(infile,"%255s",word)>0) {
    nChars+=strlen(word);
    nWords++;
    }
    printf ("Wyrazy %d\n",nWords);
    printf ("Znaki %d\n",nChars);
    //alokacja
    pTextData=(char*)malloc((nChars+nWords)*sizeof(char));
    ppWords=(char**)calloc(nWords,sizeof(char*));
    //uzupe�nianie


    for(int i=0;i<nChars+nWords;i++)
    {
        pTextData[i]=fgetc(infile);
        pTextData[i]=tolower(pTextData[i]);
        if(pTextData[i]==' '||pTextData[i]=='\n'||pTextData[i]=='\t')
        {
            pTextData[i]='\0';
        }
        printf ("%c",pTextData[i]);
    }
    
    //dodawania wska�nik�w na s�owa
    ppWords[0]=pTextData[0];
    printf ("%c",ppWords[0]);
    int a=1;
    for(int i=1;i<nChars+nWords-1;i++)
    {
        if(pTextData[i]=='\0')
        {
            ppWords[a]=pTextData[i+1];
            printf ("%c",ppWords[a]);
            a++;
        }
	printf("\n");
    }

    //sortowanie wsyep
    //sortowanie
    for(int i=0;i<nWords;i++)
    {
        int k=i;
        for(int j=i+1;j<nWords;j++)
        {

        }
    }
    //zapisywanie do pliku
    fclose(infile);
    FILE* outfile;
    infile=fopen(inFileName,"r");


}
int main()
{
    SortFileWords("dane.txt","sorted.txt");
    return 0;
}