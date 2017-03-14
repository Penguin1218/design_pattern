#include "Director.h"

int main()
{
	Director d;
	EnglishTranslator t;
	d.DoTranslate("Input.txt", t);
	Manual out = t.GetResult();
	cout << out.GetContents() << endl;
}