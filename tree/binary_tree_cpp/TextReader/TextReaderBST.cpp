/* Author: Erii Sugimoto
   Date: 11/21/2016
   Professor: Anna Salvati
   Assignment: Project #2
   Class: CSC 430
   School: Borough of Manhattan Community College
   File Name: TextReaderBST.cpp
   Description Of the Program: An implementation file for the TextReaderBST.h
*/

#include "BinaryTree2.h"
#include "TextReaderBST.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class x>
TextReaderBST<x>::TextReaderBST() :BinaryTree2()
{
}

template <class x>
void TextReaderBST<x>::insert(x item)
{
	binaryTreeNode<x> *current;
	binaryTreeNode<x> *trailing;
	binaryTreeNode<x> *newNode;

	newNode = new binaryTreeNode<x>;
	newNode->info = item;
	newNode->count = 1;
	newNode->left = NULL;
	newNode->right = NULL;

	if (root == NULL)
		root = newNode;
	else
	{
		current = root;

		while (current != NULL)
		{
			trailing = current;

			if (current->info == item)
			{
				current->count += 1;
				return;
			}
			else if (current->info > item)
				current = current->left;
			else
				current = current->right;
		}

		if (trailing->info > item)
			trailing->left = newNode;
		else
			trailing->right = newNode;
	}
}

template <class x>
int TextReaderBST<x>::getNumOfUniqueWordDummy()
{
	if (root != NULL)
		getNumOfUniqueWord(root);
	else
		return 0;
}

template <class x>
int TextReaderBST<x>::getNumOfUniqueWord(binaryTreeNode<x> *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + getNumOfUniqueWord(p->left) + getNumOfUniqueWord(p->right);		
}

template <class x>
bool TextReaderBST<x>::wordMoreThanThreeChar(binaryTreeNode<x> *p)
{
	if (p != NULL)
	{
		string temp;
		temp = p->info;

		if (temp.length() > 3)
			return true;
		else
			return false;
	}
	else
		return false;
}

template <class x>
int TextReaderBST<x>::getNumOfUniqueWordMoreThanThreeCharDummy()
{
	int accum = 0;

	if (root != NULL)
	{
		getNumOfUniqueWordMoreThanThreeChar(root, accum);
	}
	return accum;		
}

template <class x>
int TextReaderBST<x>::getNumOfUniqueWordMoreThanThreeChar(binaryTreeNode<x> *p, int &accum)
{
	if (p != NULL)
	{
		getNumOfUniqueWordMoreThanThreeChar(p->left, accum);
		getNumOfUniqueWordMoreThanThreeChar(p->right, accum);
		if (wordMoreThanThreeChar(p))
			accum++;
	}
	return accum;
}

template <class x>
int TextReaderBST<x>::getLength(binaryTreeNode<x> *p)
{
	if (p == NULL)
		return 0;
	else
		return p->info.length();
}

template <class x>
int TextReaderBST<x>::getAverageWordLengthDummy()
{
	if (root != NULL)
	{
		int totalLength, totalWords;
		totalLength = totalWords = 0;
		return getAverageWordLength(root, totalLength, totalWords);
	}
	else
		return 0;
}

template <class x>
int TextReaderBST<x>::getAverageWordLength(binaryTreeNode<x> *p, int &totalLength, int &totalWords)
{
	if (p != NULL)
	{
		totalLength += p->info.length();
		totalWords++;
		getAverageWordLength(p->left, totalLength, totalWords);
		getAverageWordLength(p->right, totalLength, totalWords);
	}

	return (totalLength / totalWords);
}

template <class x>
int TextReaderBST<x>::getTotalNumOfWordsDummy()
{
	if (root != NULL)
	{
		int totalNumOfWords = 0;
		return getTotalNumOfWords(root, totalNumOfWords);
	}	
	else
		return 0;
}

template <class x>
int TextReaderBST<x>::getTotalNumOfWords(binaryTreeNode<x> *p, int &totalNumOfWords)
{
	if (p != NULL)
	{
		totalNumOfWords += p->count;
		getTotalNumOfWords(p->left, totalNumOfWords);
		getTotalNumOfWords(p->right, totalNumOfWords);
	}
	else
		return totalNumOfWords;
}

template <class x>
int TextReaderBST<x>::getNumOfSentencesDummy()
{
	if (root != NULL)
		return getNumOfSentences(root);
	else
		return 0;
}

template <class x>
int TextReaderBST<x>::getNumOfSentences(binaryTreeNode<x> *p)
{
	if (p == NULL)
		return 0;
	else
		return p->count + getNumOfSentences(p->left) + getNumOfSentences(p->right);
}

template <class x>
int TextReaderBST<x>::getAverageSentenceLength()
{
	if (root != NULL)
	{
		int totalNumOfWords = getTotalNumOfWordsSentence(root);
		int totalNumOfSentences = getNumOfSentences(root);
		return (totalNumOfWords / totalNumOfSentences);
	}
	else
		return 0;
}

template <class x>
int TextReaderBST<x>::getTotalNumOfWordsSentence(binaryTreeNode<x> *p)
{
	if (p == NULL)
		return 0;
	else
		return p->info + getTotalNumOfWordsSentence(p->left) + getTotalNumOfWordsSentence(p->right);
		
}

template <class x>
void TextReaderBST<x>::getSmallestIndex(binaryTreeNode<x> *p, char &smallest)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right == NULL)
			smallest = p->info.front();
		else
			getSmallestIndex(p->left, smallest);
	}
}

template <class x>
void TextReaderBST<x>::printIndecesDummy(ofstream &file)
{
	if (root != NULL)
	{

		char i;
		getSmallestIndex(root, i);
		file << i << ":\n";
		printIndeces(root, i, file);
	}
		
}

template <class x>
void TextReaderBST<x>::printIndeces(binaryTreeNode<x> *p, char &initial, ofstream &file)
{
	if (p != NULL)
	{
		printIndeces(p->left, initial, file);

		if (p->info.front() != initial)
		{
			file << endl;
			file << p->info.front() << ": " << endl;
			initial = p->info.front();
		}
		file << p->info << endl;

		printIndeces(p->right, initial, file);
	}
}


template <class x>
void TextReaderBST<x>::printFrequentlyUsedWordDummy(ofstream &file)
{
	if (root != NULL)
	{
		file << "\nWords Used Too Often: " << endl;
		int NumOfUniqueWord = getNumOfUniqueWordMoreThanThreeCharDummy();
		printFrequentlyUsedWord(root, NumOfUniqueWord, file);
	}
		
}


template <class x>
void TextReaderBST<x>::printFrequentlyUsedWord(binaryTreeNode<x> *p, int NumOfUniqueWord, ofstream &file)
{
	if (p != NULL)
	{
		if (p->info.length() > 3)
			if (p->count > (NumOfUniqueWord*0.05))
				file << p->info << endl;

		printFrequentlyUsedWord(p->left, NumOfUniqueWord, file);
		printFrequentlyUsedWord(p->right, NumOfUniqueWord, file);
	}
}

