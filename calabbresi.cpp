#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define N 5000
int PointerVector(char* pword[N],char text[N], int textCounter)
{
    int pwordCounter=0;
    for (int i=1; i<textCounter; i++)
    {
        if(text[i-1]==' ' || text[i-1]=='\n')
            {
                pword[pwordCounter]=&text[i]; 
                pwordCounter++;
            }

    }
    return pwordCounter;
}

void TextVectorFiller(char text[N], int &n)
{   
    n=0;
    fstream fin;
    fin.open("text.txt", ios::in);
    while (!fin.eof())
    {   
        text[n]=fin.get();
        n++; 
    }
    fin.close();
}
void RandomWords(char* pword[N],int p) // funzione per generare 30 parole casuali di 6 caratteri, con le iniziali delle parole del file di testo
{
    for (int i=0; i<30; i++)
    { 
        for (int j=0; j<6; j++)
            {
                int n=rand()%p;
                cout<<*pword[n];
            }
        cout<<endl;
    }
}

void RandomPhrases(char* pword[N], char text[N], int p)
{
    for(int i =0; i< 30;i++)
    {
        for(int j=0; j<10; j++)
        {
            int n=rand()%p;
            int counter=0;
            do
            {
                cout<<*(pword[n]+counter);
                counter++;
            } while (*(pword[n]+counter+1)!=' ');
            cout<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int textCounter,i,pwordCounter;
    char text[N];
    char* pword[N];
    for (i=0;i<N; i++)
        pword[i]=NULL;
    TextVectorFiller(text, textCounter);
    pwordCounter=PointerVector(pword, text, textCounter);
    RandomWords(pword, pwordCounter);
    RandomPhrases(pword, text, pwordCounter);
    for (i=0;i <textCounter; i++)
        cout<<text[i]<<" ";
    cout<<endl;
    for (i=0;i <pwordCounter; i++)
        cout<<*pword[i]<<endl;
    return 0;
}