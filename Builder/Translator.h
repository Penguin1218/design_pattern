#pragma once
#include "Manual.h"
class Translator
{
public:
	Manual GetResult() { return _result; }

	virtual void TransNormalSentence(string s) = 0;
	virtual void TransInterrogativeSentence(string s) = 0;
	virtual void TransImperativeSentence(string s) = 0;
protected:
	Manual _result;
};

class EnglishTranslator : public Translator
{
public:
	void TransNormalSentence(string s)
	{
		string output;
		_result.AddContents(output);
	}
	void TransInterrogativeSentence(string s)
	{
		string output;
		_result.AddContents(output);
	}
	void TransImperativeSentence(string s)
	{
		string output;
		_result.AddContents(output);
	}
};

class JapaneseTranslator : public Translator
{
public:
	void TransNormalSentence(string s)
	{
		string output;
		_result.AddContents(output);
	}
	void TransInterrogativeSentence(string s)
	{
		string output;
		_result.AddContents(output);
	}
	void TransImperativeSentence(string s)
	{
		string output;
		_result.AddContents(output);
	}
};
