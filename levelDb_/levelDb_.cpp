
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include "leveldb/db.h"

using namespace std;
int main(int argc, char** argv)
{
	// Set up database connection information and open database
	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;

	leveldb::Status status = leveldb::DB::Open(options, "./badr_db", &db);

	if (false == status.ok())
	{
		cerr << "Unable to open/create test database './badr_db'" << endl;
		cerr << status.ToString() << endl;
		return -1;
	}

	else {
		cout << "DB successfully opened" << endl;
	}

  // add key value to the LevelDB database
 		string key, value;
		leveldb::WriteOptions writeOptions;
	
		cout << "insert the key" << endl;
		cin >> key;
		cout << "insert the corresoinding value" << endl;
		cin >> value;
		db->Put(writeOptions, key, value);
 
	// Iterate over each item in the database and print them
	leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());

	cout << "Retrive values from DB"<< endl;

	std::string v;
	std::getline(std::cin, v);
	for (it->SeekToFirst(); it->Valid(); it->Next())
	{
		cout << it->key().ToString() << " : " << it->value().ToString() << endl;
	}
	if (false == it->status().ok())
	{
		cerr << "An error was found during the scan" << endl;
		cerr << it->status().ToString() << endl;
	}
	std::string s;
	std::getline(std::cin, s);
	delete it;
	// Close the database
	delete db;

}
