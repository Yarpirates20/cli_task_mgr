/**
 * @file main.cpp
 * @brief 
 * 
 */

#include "Database_Manager.hpp"

#include <iostream>
#include <string>

// Prototypes
std::string get_WSL_gateway();

int main()
{
    // Retrieves host IP for WSL to connect to Postgres DB.
    std::string host_ip = get_WSL_gateway();

    if (host_ip.empty())
    {
        std::cerr << "Error: Could not determine Windows Host IP. " << std::endl;
        return 1;
    }

    std::string conn_str = "host=" + host_ip + " port=5432 user=postgres dbname=task_mgr password=Tyty5454@";

    std::cout << "Connecting to Windows Host at: " << host_ip << std::endl;

    // Connect to DB
    Database_Manager db(conn_str);
    std::string db_conn("dbname=task_mgr user=postgres ");

    // Add Categories
    std::vector<std::string> categories { "Career", "Personal", "School", "Development", "Finance", "Backlog" };

    db.insert_category(categories);


    return 0;
}

/**
 * @brief Reads the /proc/net/route file to grab the gateway IP.
 *
 * @return std::string Returns hostname as string.
 */
std::string get_WSL_gateway()
{
    std::array<char, 128> buffer;
    std::string result;

    // Command to find default gateway IP
    std::unique_ptr<FILE, int (*)(FILE *)> pipe(popen("ip route | grep default | awk '{print $3}'", "r"), pclose);

    if (!pipe)
        throw std::runtime_error("popen() failed!");

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }

    // Remove trailing newline
    if (!result.empty() && result[result.length() - 1] == '\n')
    {
        result.erase(result.length() - 1);
    }

    return result;
}