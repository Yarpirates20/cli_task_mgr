#include "Database_Manager.hpp"

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

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

/** @copydoc Database_Manager::insert_category(std::string cat_name) */
bool Database_Manager::insert_category(std::vector<std::string> cat_names)
{
    try
    {
        pqxx::work tx{*conn};
        auto stream = pqxx::stream_to::table(tx, {"Category"}, {"Name"});

        for (const auto &cat : cat_names)
        {
            stream << cat;
        }

        stream.complete();
        tx.commit();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}
