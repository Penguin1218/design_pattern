#pragma once
#include <iostream>
#include <string>
using namespace std;

const int UNDEF_SENTENCE = 0;
const int NORMAL_SENTENCE = 1;
const int INTERROGATIVE_SENTENCE = 2;
const int IMPERATIVE_SENTENCE = 3;
class Sentence
{
public:
	Sentence() { _data = ""; _type = UNDEF_SENTENCE; }

	int GetType() { return _type; }
	string GetString() { return _data; }
	void SetSentenceData(string s)
	{
		SetSentenceType(s);
		_data = s;
	}
protected:
	void SetSentenceType(string s) {_type = NORMAL_SENTENCE;};
private:
	string _data;
	int _type;
};

