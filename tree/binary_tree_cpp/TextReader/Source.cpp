/* Author: Erii Sugimoto
   Date: 11/21/2016
   Professor: Anna Salvati
   Assignment: Project #2
   Class: CSC 430
   School: Borough of Manhattan Community College
   File Name: Source.cpp
   Description Of the Program: A main class of the TextReaderBST.h
                               a. Creates two TextReader objects:
                               1. words <string>: an object of a binary search tree list with each node containing 
							      a unique word and a counter to indicate the dubplicates
							   2. sentenceLength <int>: an object of a binary search tree list with each node containing
							      a length of each sentence; thus, the total number of nodes indicates
								  the totoal number of sentences in the report.
                               b. Promts the user to enter the name of the file to be analyzed.
							   c. Writes the report on a file named "report.txt".

*/

#include "TextReaderBST.cpp"
#include "BinaryTree2.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
	TextReaderBST<string> words;
	TextReaderBST<int> sentenceLength;

	int accum = 0; //increments 1 every insertion. Reset upon period encounter.
	int averageWL, averageSL; //variables to hold the average word length and average sentence length.

	string line;
	string inputFileName;
	ofstream file;

	std::cout << "Enter the name of your file: ";
	cin >> inputFileName;
	ifstream myfile(inputFileName);
	
	file.open("report.txt");

	if (myfile.is_open())
	{
		myfile >> line;

		while (!myfile.eof())
		{
			if (!line.empty())
			{
				while (line.length() > 0 && line.front() < ' ')
					line.erase(0, 1);

				  if (line.length() > 0 && line.front() > ' ')
				   {
						while (line.length() > 0 && line.front() > ' ' && ispunct(line.front()))
							line.erase(0, 1);

					if (line.length() > 0 && line.back() > ' ' && line.back() == '.' || line.back() == '?' || line.back() == '!')
					{
						sentenceLength.insert(++accum);
						accum = 0;
					}

					while (line.length() > 0 && line.back() > ' ' && ispunct(line.back()))
						line.erase(line.length() - 1, 1);

					while (line.length() > 0 && line.back() < ' ')
						line.erase(line.length() - 1, 1);
						
					int i = 0;

					while (i < line.length())
					{
						if (line[i] > ' ' && isalpha(line[i]) && isupper(line[i]))
							line[i] = tolower(line[i]);
						i++;
					}

					if (line.length() > 0)
					{
						accum++;
						words.insert(line);
					}					
				}
			}
			myfile >> line;
		}
		myfile.close();
	}
	else
	{
		std::cout << "can't open the file.";
		return 0;
	}

	file << "\nFile Name: " << inputFileName;
	file << "\n\n--------------STATISTICAL SUMMARY--------------";

	file << "\nTotal Number Of Words: ";
	file << words.getTotalNumOfWordsDummy();

	file << "\nTotal Number Of Unique Words: ";
	file << words.getNumOfUniqueWordDummy();

	file << "\nTotal Number Of Unique Words With More Than Three Characters: ";
	file << words.getNumOfUniqueWordMoreThanThreeCharDummy();

	file << "\nAverage Length Of Words: ";
	averageWL = words.getAverageWordLengthDummy();
	file << averageWL;

	file << "\nTotal Number Of Sentences: ";
	averageSL = sentenceLength.getNumOfSentencesDummy();
	file << averageSL;

	file << "\nAverage sentence Length: ";
	file << sentenceLength.getAverageSentenceLength();

	file << "\n\n-------------STYLE WARNINGS-------------";

	words.printFrequentlyUsedWordDummy(file);

	if (averageSL > 10)
		file << "\nAverage Sentence Length Too Long --- " << averageSL << " words";

	if(averageWL > 5)
		file << "\nAverage Word Length Too Long --- " << averageWL << " characters";

	file << "\n\n----------INDEX OF UNIQUE WORDS----------\n";
	words.printIndecesDummy(file);

	std::cout << "The report has been written on report.txt" << endl;

	file.close();
	return 0;
}