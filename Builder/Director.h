#pragma once
#include <fstream>
#include "Translator.h"
#include "Sentence.h"
using namespace std;
class Director
{
public:
	void DoTranslate(char* pInFile, Translator& t)
	{
		ifstream ifs(pInFile);
		if (!ifs) {
			cout << "Can't Open File : " << pInFile << endl;
		}
		Sentence next;
		while (!(next = GetSentence(ifs)).GetString().empty())
		{
			switch (next.GetType())
			{
			case NORMAL_SENTENCE : 
				t.TransNormalSentence(next.GetString());
				break;
			case INTERROGATIVE_SENTENCE:
				t.TransInterrogativeSentence(next.GetString());
				break;
			case IMPERATIVE_SENTENCE:
				t.TransImperativeSentence(next.GetString());
				break;
			default:
				cout << "Untranslatable sentence type" << endl;
				return;
			}
		}
	}
protected:
	Sentence GetSentence(ifstream & ifs)
	{
		int c;
		string s;
		Sentence sentence;
		while ((c = ifs.get()) != EOF)
		{
			s += c;
			if (c == '?' || c == '.')
				break;
		}
		sentence.SetSentenceData(s);
		return sentence;
	}
};