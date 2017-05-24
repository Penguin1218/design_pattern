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
		// name, value �ֵ鿡 ���� �˻������� �˻��Ѵ�.
		// age�� ���� ���ڰ� �ƴ� ���� �����Ǹ� �ȵǸ�,
		// ������ ���� �����Ǹ� �� �ȴ�.
		return true;
	}
private:
	map<string, string> _condList;
};

class ListData {
	// �����ͺ��̽����� �˻��Ǵ� ��� ���ڵ尡 ����Ǳ� ���� �ڷᱸ��
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
		// ������ ���̽� ���� �ý��۰� ������ ������.
	}
	bool Execute(string sql, ListDBResult& result) {
		// sql ���� ����� result�� �����ϵ�, sql ���� �������� ������ ������ false�� return�ϸ�
		// �׷��� ���� ��쿡�� true �� return�Ѵ�.
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