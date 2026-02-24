#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <pqxx/pqxx>
#include <string>
#include <vector>

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
         * @brief Insert a category into DB.
         * 
         * @param cat_name  Name of category.
         * @return true     If insertion successful.  
         * @return false    If insertion failed.
         */
        bool insert_category(std::vector<std::string> cat_names);
};


#endif // DATABASE_MANAGER_H