#pragma once
// **** Main ****
// Abstract Base Factory

#include "Scanner.h"
#include "Parser.h"

class CompilerFactory
{
public:
	virtual Scanner * CreateScanner() = 0;
	virtual Parser * CreateParser() = 0;
protected:
	CompilerFactory();
	static CompilerFactory * _instance;
};

class HPCompilerFactory : public CompilerFactory
{
public:
	static HPCompilerFactory * CreateInstance()
	{
		if (_instance == 0)
			_instance = new HPCompilerFactory();
		return (HPCompilerFactory*) _instance;
	}
	Scanner * CreateScanner() { return new HPScanner(); }
	Parser * CreateParser() { return new HPParser(); }
protected:
	HPCompilerFactory();
};

class SunCompilerFactory : public CompilerFactory
{
public:
	static SunCompilerFactory * CreateInstance()
	{
		if (_instance == 0)
			_instance = new SunCompilerFactory();
		return (SunCompilerFactory*)_instance;
	}
	Scanner * CreateScanner() { return new HPScanner(); }
	Parser * CreateParser() { return new HPParser(); }
protected:
	SunCompilerFactory();
};