// http://adventofcode.com/2017/day/1

#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <iostream>
#include <fstream>

using namespace std;

void solveOne();
void solveTwo();

 int _tmain(int argc, _TCHAR* argv[])
{
	printf("Enter 1 to solve Part 1. Enter 2 to solve Part 2.\nAny other input to exit.\n" );
	char c = getchar();
	if( c == '1')
		solveOne();
	else if(c == '2')
		solveTwo();
	return 0;
}

void solveOne()
{
	int first, previous, answer = 0;
	char c;
	ifstream f ("PuzzleInput.txt");
	if (!f)
	{
		cerr << "Can't open " << "input.txt" << "\n";
		exit (1);
	}

	if(f.get(c).good())
	{
		first = c - '0';     //normalize char against 0
		previous = first;
	}
	else    cerr << "Invalid Input\n";

	while(f.get(c).good())
	{
		if(c - '0' == previous)
			answer += previous;
		previous = c - '0';
	}
	//last step, check against first.
	if(previous == first)
		answer+= previous;

	printf("Answer is: %d\nEnter any input to exit\n", answer ); //answer is an integer.  1171
	getchar(); // clear out new line
	getchar();
	f.close();
}


void solveTwo()
{
	int first, previous, answer = 0;
	char s[8196]; //randomness of file length, but won't be bigger than this.
	ifstream f ("PuzzleInput.txt");
	if (!f)
	{
		cerr << "Can't open " << "input.txt" << "\n";
		exit (1);
	}

	//get entire file this time.
	f.get(s,8196,'\n');
	int len = strlen(s);
	int offset = len/2; // what we need to compare, by definition of the problem.
	for (int i = 0; i < len; i++)
	{
		if(s[i] == s[(i+offset)%len])  // use modulo to wrap around the buffer
			answer +=   s[i] - '0';
	}
	printf("Answer is: %d\nEnter any input to exit\n", answer ); //answer is an integer. 1024
	getchar(); // clear out new line
	getchar();
	f.close();

}


//sample input
/*
7385764686251444473997915123782972536343732657517834671759462795461213782428342931896181695578996274321317419242
*/
