

#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <pqxx/pqxx>
#include <string>
#include <vector>
#include <map>

// Category map structure
using cat_map = std::map<int, std::string>;

/**
 * @brief The Database_Manager class connects to and queries 
 * the PostgreSQL database that stores tasks.
 * 
 */
class Database_Manager
{
    private:
        pqxx::connection *conn;

    public:
        /**
         * @brief Constructor.
         * 
         * @param conn_string Connection string.
         */
        Database_Manager(const std::string &conn_string);

        /**
         * @brief Destroy the Database_Manager object
         * and close Connection.
         * 
         */
        ~Database_Manager();

        /**
         * @brief Loops through vector of categories and streams them into 
         * Postgres DB.
         * 
         * @param cat_name  Vector of categories.
         * @return true     If insertion successful.  
         * @return false    If insertion failed.
         */
        bool insert_category(std::vector<std::string> cat_names);

        /**
         * @brief Adds single category value to Categories table.
         * 
         * @param name      Const string of category name.
         * @return true     Returns true if insert successful. 
         * @return false    Returns false if insert failed.
         */
        bool add_category(const std::string& name);
};


#endif // DATABASE_MANAGER_H