//Written by Jordan Karpan - 5041823

#include "includes.h"

DICT dictionary;  //the dictionary 
WORD word;        
int count[MAX];   //tracks word frequencies

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