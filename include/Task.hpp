#ifndef TASK_H
#define TASK_H

#include <string>

struct Task
{
    int id;
    std::string description;
    std::string due_date;   \\ YYYY-MM-DD format
    int category_id;
    bool is_completed;
};

#endif // TASK_H