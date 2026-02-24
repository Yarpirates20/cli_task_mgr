/**
 * @file    Database_Manager.cpp
 * @brief   Implementation of CRUD operations.
 *
 * @details Standard CRUD approach to use:
 *
 * void Database_Manager::CRUD_OPERATION(const TYPE& variable_name)
 * {
 *      // Create transaction locally
 *      pqxx::work tx(*conn);
 *
 *      // Execute SQL
 *      tx.exec_params("INSERT INTO Tasks (TaskDesc) VALUES ($1)", task.
 *      description);
 *
 *      // Finalize the work
 *      tx.commit();
 * }
 *
 *
 */
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
       
        for (const auto &cat : cat_names)
        {
            tx.exec_params(
                "INSERT INTO Category (CategoryName) VALUES ($1) "
                "ON CONFLICT (CategoryName) DO NOTHING",
                cat
            );
        }

        tx.commit();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    std::cout << "Successfully inserted all categories.\n";
    return true;
}

/** @copydoc Database_Manager::add_category(const std::string &name) */
bool Database_Manager::add_category(const std::string &name)
{
    try
    {
        pqxx::work tx(*conn);

        tx.exec_params("INSERT INTO category (CategoryName) VALUES ($1)", name);

        tx.commit();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    std::cout << "Successfully added Category: " << name << "\n";
    return true;
}
