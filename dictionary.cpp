//Written by Jordan Karpan - 5041823

#include "includes.h"

BOOL InsertWord(DICT dict, WORD word)//Inserts the word into the dictionary at the next available position.
{
	if (FullDictionary(dict) == 1)//First, check if the dictionary is full. No point in inserting the word if it's full!
	{
		return 0;
	}
	else 
	{
		int pos;
		for (int i = 0; i < MAX; i ++)
		{
			if (dict[i].empty())//find the next available empty space
			{
				dict[i] = word;//put the word in and increse its counter.
				count[i]++;
				return 1;
			}
		}
		
	}
}

void DumpDictionary(DICT dict, int count[]) {
	/*
		Prints the dictionary to the screen.
		
		Sorts in Alphabetical order via first letter, capital letters first then lower case.
	*/
	cout << "Word		Frequency\n---------------------\n";
	for (int i = 65; i <= 90; i++)
	{
		char tmp = i;//assigns the decimal version of the char, starting with capital A.
		for (int j = 0; j < MAX; j++)
		{
			if (dict[j] != "" && dict[j].at(0) == tmp)
			{
				cout << dict[j] << " - " << count[j] << " occurances.\n";
			}
			else
			{
				tmp = (i + 32);//Add 32 to the decimal version to get the lower case version. Thanks Libero!
				if (dict[j] != "" && dict[j].at(0) == tmp)
				{
					cout << dict[j] << " - " << count[j] << " occurances.\n";
				}
			}
		}
	}
}

WORD GetNextWord(void){
	char ch;
	string tmp = "";
	
	while (cin.good())//read until the end of the file.
	{
		ch = cin.get();
		if (isalpha(ch))//if it's a letter, we append it to the temporary string.
		{
			tmp += ch;
		}
		else if (isdigit(ch))//Otherwise, if it's a number...
		{
			//do nothing and advance to the next position.
		}
		else//If it's not a number or a letter, we can assume we've finished reading what we need to.
		{
			if (tmp.empty()) //if we have an empty string to return, just recursively search for the next word and return that
			{
				return GetNextWord();
			}
			tmp += '\0';
			return tmp;//Return the word pulled from the file.
		}
	}
	//if you get down here, you have hit the end of the file because cin.good fails, so we return a null string to force the dictionary to dump.
	return "";
}

BOOL FullDictionary(DICT dict) {//checks if the dictionary is full by checking if the last dictionary slot is occupied.
	if (dict[MAX - 1].empty() == 0) return 1;
	else return 0;
}

int LocateWord(DICT dict, WORD word) {//returns the position of a given word if it's an exact match, or -1 if not found.
	for (int i = 0; i < MAX; i++)
	{
		if (dict[i].compare(word) == 0)
		{
			return i;
		}
	}
	return -1;
}