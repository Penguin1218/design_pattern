#include <iostream>
#include <string>
#include <map>
#include <list>
#include <iterator>
using namespace std;

class SearchCond {
public:
	SearchCond(map<string, string> nvList)
	{
		_condList = nvList;
	}
	bool CheckCond() {
		// name, value 쌍들에 대해 검색조건을 검사한다.
		// age에 대해 숫자가 아닌 값이 설정되면 안되며,
		// 음수값 등이 설정되면 안 된다.
		return true;
	}
private:
	map<string, string> _condList;
};

class ListData {
	// 데이터베이스에서 검색되는 결과 레코드가 저장되기 위한 자료구조
};

class ListDBResult {
public:
	int GetCount()
	{
		return _result.size();
	}
	void InitIterator() {
		_iter = _result.begin();
	}
	ListData GetNextData() {
		return *_iter++;
	}
private:
	list<ListData> _result;
	list<ListData>::iterator _iter;
};

class Database {
public:
	Database() {
		// 데이터 베이스 관리 시스템과 연결을 수행함.
	}
	bool Execute(string sql, ListDBResult& result) {
		// sql 수행 결과를 result에 설정하되, sql 수행 과정에서 문제가 있으면 false를 return하며
		// 그렇지 않은 경우에는 true 를 return한다.
		return true;
	}
};

class SQLGenerator {
public:
	string GenerateSQL(SearchCond cond) {
		string sql;

		return sql;
	}
};

class DBHandler {
public:
	bool Search(map<string, string> nvList, ListDBResult& result)
	{
		SearchCond cond(nvList);
		if (!cond.CheckCond()) {
			cout << "wrong search condtion" << endl;
			return false;
		}
		SQLGenerator generator;
		string sql = generator.GenerateSQL(cond);

		return _db.Execute(sql, result);
	}
private:
	Database _db;
};

int main()
{
	map<string, string> nvList;
	ListDBResult result;
	
	DBHandler handler;
	handler.Search(nvList, result);
}