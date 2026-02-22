#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <pqxx/pqxx>
#include <string>

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

        
};


#endif // DATABASE_MANAGER_H