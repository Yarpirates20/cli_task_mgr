#include "Database_Manager.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

/** @copydoc Database_Manager::Database_Manager(const std::string &conn_string) */
Database_Manager::Database_Manager(const std::string &conn_string)
{
    conn = new pqxx::connection(conn_string.c_str());

    if (conn->is_open())
    {
        cout << "Successfully connected to " << conn->dbname() << endl;
    }
    else
    {
        cerr << "Connection to database failed" << endl;
    }
}

/** @copydoc Database_Manager::~Database_Manager() */
Database_Manager::~Database_Manager()
{
    delete conn;
}
