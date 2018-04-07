/* Author: Erii Sugimoto
   Date: 11/21/2016
   Professor: Anna Salvati
   Assignment: Project #2
   Class: CSC 430
   School: Borough of Manhattan Community College
   File Name: TextReaderBST.h
   Description Of the Program: A text reader class that reads a file, insert each word in a list of a binary search tree,
                               and writes the followings on a file:
							   1. stastistical summary
							   2. style warning
							   3. index of words in the input file							                              
  */

#pragma once
#ifndef TextReaderBST_hpp
#define TextReaderBST_hpp
#include "BinaryTree2.h"

template <class x>
class TextReaderBST:public BinaryTree2<x>
{
public:
	TextReaderBST(); //constructor 

	//Function that inserts a word into a binary search tree.
	void insert(x item);

	//Dummy function for the getNumOfUniqueWord
	int getNumOfUniqueWordDummy();
	//Function that returns the total number of unique words in the list
	int getNumOfUniqueWord(binaryTreeNode<x> *p);

	//Function that returns true if the word has more than three characters and false otherwise
	bool wordMoreThanThreeChar(binaryTreeNode<x> *p);

	//Dummy function for the getNumOfUniqueWordAtLeastThreeChar
	int getNumOfUniqueWordMoreThanThreeCharDummy();
	//Function that returns the total number of unique words that has more than three characters
	int getNumOfUniqueWordMoreThanThreeChar(binaryTreeNode<x> *p, int &accum);

	//Function that return the length of a word
	int getLength(binaryTreeNode<x> *p);

	//Dummy function for the getAverageWordLength
	int getAverageWordLengthDummy();
	//Function that returns the average length of words in the list
	int getAverageWordLength(binaryTreeNode<x> *p, int &totalLength, int &totalWords);

	//Dummy function for the getTotalNumOfWords
	int getTotalNumOfWordsDummy();
	//Function that returns the total number of words in the list
	int getTotalNumOfWords(binaryTreeNode<x> *p, int &totalNumOfWords);

	//Dummy function for the getNumOfSentences
	int getNumOfSentencesDummy();
	//Function that returns the total number of sentences in the list
	int getNumOfSentences(binaryTreeNode<x> *p);

	//Function that returns the average length of sentences in the list by dthe getTotalNumOfWordsSentence
	int getAverageSentenceLength();
	int getTotalNumOfWordsSentence(binaryTreeNode<x> *p);

	//Dummy function for the printIndecesDummy
	void printIndecesDummy(ofstream &file);
	//Function that prints the indeces of words.
	void printIndeces(binaryTreeNode<x> *p, char &initial, ofstream &file);

	//Function that returns the smallest value in the smallest
	void getSmallestIndex(binaryTreeNode<x> *p, char &smallest);

	//Dummy function for the printFrequentUsedWordDummy
	void printFrequentlyUsedWordDummy(ofstream &file);
	//Function that prints unique words that were used more than 5% of the total number of words.
	void printFrequentlyUsedWord(binaryTreeNode<x> *p, int NumOfUniqueWord, ofstream &file);

};
#endif // !TextReaderBST_hpp

