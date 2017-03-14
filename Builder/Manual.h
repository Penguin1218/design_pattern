#pragma once
#include <string>
using namespace std;
class Manual {
public :
	string GetContents() { return _contents; }
	void AddContents(string s) { _contents += s; }
private:
	string _contents;
};