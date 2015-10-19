/*Notes:

Compiling in the makefile:
main: dictionary.o main.o
	g++ dictionary.o main.o -o main
	
dictionary.o: dictionary.cpp dictionary.h
	g++ -c dictionary.cpp
	
main.o: main.cpp dictionary.h
	g++ -c main.cpp
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

/*
  you will have to write code for these 5 functions. 
*/

int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);

/*
  note that these are global variables so that they are already initialized to 0
*/

DICT dictionary;  //your dictionary 
WORD word;        // 
int count[MAX];   //tracks word frequencies


BOOL InsertWord(DICT dict, WORD word)
{
	if (FullDictionary(dict) == 1)
	{
		return 1;
	}
	else 
	{
		int pos;
		for (int i = 0; i < MAX; i ++)
		{
			if (dict[i] == "")
			{
				dict[i] = word;
				count[i]++;
				break;
			}
		}
		
	}
}

void DumpDictionary(DICT dict, int count[]) {
	cout << "Word		Frequency\n---------------------\n";
	for (int i = 0; i < MAX; i++)
	{
		if (count[i] != 0)
		{
			cout << dict[i] << " - " << count[i] << " occurances.\n";
		}
	}
}

WORD GetNextWord(void){
	char ch;
	string tmp;
	
	while (cin.good())
	{
		ch = cin.get();
		if (isalpha(ch))
		{
			tmp += ch;
		}
		else return tmp;
	}
}

BOOL FullDictionary(DICT dict) {
	for (int i = 0; i < MAX; i++)
	{
		if (dict[i] != "") return 1;
	}
	return 0;
}

int LocateWord(DICT dict, WORD word) {
	for (int i = 0; i < dict[i].length(); i++)
	{
		if (word.compare(dict[i]) == 0)
			return i;
	}
	return 0;
}

int main (void) {
    int pos;

    while (1) {
       word = GetNextWord();
       if ( word.empty() )  {
           DumpDictionary(dictionary,count);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >=  0 ) 
           count[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}