#include <iostream>
#include <fstream>
#include <map>
using namespace std;

#define UNDEF_DOCUMENT 0 
#define HWP_DOCUMENT 1
#define MSWORD_DOCUMENT 2
#define ANOTHER_DOCUMENT 3

class Document
{
public:
	virtual bool Open(char* pFileName) = 0;
};

class HWPDocument : public Document
{
public:
	bool Open(char* pFileName) {
		ifstream ifs(pFileName);

		if (!ifs)
			return false;
		//HWP 고유 prosseing
		return true;
	}
};

class MsWordDocument : public Document
{
public:
	bool Open(char* pFileName)
	{
		ifstream ifs(pFileName);

		if (!ifs)
			return false;
		//MsWord 고유 prosseing
		return true;
	}
};

class AnotherDocument : public Document
{
public:
	bool Open(char* pFileName)
	{
		ifstream ifs(pFileName);

		if (!ifs)
			return false;
		//Antother Document 고유 prosseing
		return true;
	}
};

class Application
{
public:
	void NewDocument(char* pFileName)
	{
		Document* pDoc = CreateDocument(GetDocType(pFileName));
		if (pDoc == NULL)
			exit(0);
		_docs[pFileName] = pDoc;
		pDoc->Open(pFileName);
	}
	virtual Document* CreateDocument(int docType)
	{
		switch (docType)
		{
		case HWP_DOCUMENT:
			return new HWPDocument;
		case MSWORD_DOCUMENT:
			return new MsWordDocument;
		}
		return 0;
	}
protected:
	int GetDocType(char* pFileName)
	{
		char* pExt = strrchr(pFileName, '.');
		if (strcmp(pExt, ".hwp") == 0)
			return HWP_DOCUMENT;
		else if (strcmp(pExt, ".doc") == 0)
			return MSWORD_DOCUMENT;
		else
			return UNDEF_DOCUMENT;
	}
private:
	map<string, Document*> _docs;
};

class HwpApplication : public Application {};
class MsWordApplication : public Application {};
class AnotherApplication : public Application
{
public:
	Document* CreateDocument(int docType)
	{
		if (docType == ANOTHER_DOCUMENT)
			return new AnotherDocument;
		else
			return Application::CreateDocument(docType);
	}
};

int main()
{
	AnotherApplication another;
	another.NewDocument("input.dat");
}