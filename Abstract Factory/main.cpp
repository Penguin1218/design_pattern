#include "CompilerFactory.h"


enum COMPANY {
	HP,
	Sun
};

int main()
{
	CompilerFactory* _factory;

	COMPANY company = HP;

	switch (company)
	{
	case HP: _factory = HPCompilerFactory::CreateInstance(); break;
	case Sun: _factory = SunCompilerFactory::CreateInstance(); break;
	}

	Scanner * scanner = _factory->CreateScanner();
	Parser * parser = _factory->CreateParser();
}