//Use only the following three libraries:
#include "parserClasses.h"
#include <iostream>
#include <fstream>

using namespace std;

//Example Test code for interacting with your Token, TokenList, and Tokenizer classes
//Add your own code to further test the operation of your Token, TokenList, and Tokenizer classes
int main() {
	ifstream sourceFile;
	TokenList tokens;

  //Lists for types of tokens
  TokenList operatorTokens;
  TokenList identifierTokens;
  TokenList literalTokens;
  TokenList commentBodyTokens;
  TokenList otherTokens;

	Tokenizer tokenizer;

	//Read in a file line-by-line and tokenize each line
	sourceFile.open("trickyCombinations.vhd");
	if (!sourceFile.is_open()) {
		cout << "Failed to open file" << endl;
		return 1;
	}

	while(!sourceFile.eof()) {
		string line;
		getline(sourceFile, line);

		tokenizer.setString(&line);
		while(!tokenizer.isComplete()) {
			tokens.append(tokenizer.getNextToken());
		}
	}


	/*Test your tokenization of the file by traversing the tokens list and printing out the tokens*/
	Token *t = tokens.getFirst();
	while(t) {
		cout << t->getStringRep() << " ";
		t = t->getNext();
	}

  /* For your testing purposes only */


    cout << endl << endl << endl << endl << endl << "LIST OF CONDITIONAL TOKENS" << endl;
    TokenList *conditional_ptr;
    conditional_ptr = findAllConditionalExpressions(tokens);
    t = conditional_ptr->getFirst();

    while(t)
    {
        cout << t->getStringRep() << " ";
        t = t->getNext();
    }


    cout << endl << endl << endl << endl << endl << "LIST OF TOKEN TYPES" << endl;

    t = tokens.getFirst();
    while(t)
    {
        tokens.findAndSetTokenDetails(t);
        t = t->getNext();
    }

    t = tokens.getFirst();
    while(t)
    {
        cout << t->getTokenType() << " ";
        t = t->getNext();
    }

  /* Ensure that tokens have all type information set*/

  /* Create operator,identifier,literal, etc. tokenLists from the master list of tokens */


	return 0;
}
