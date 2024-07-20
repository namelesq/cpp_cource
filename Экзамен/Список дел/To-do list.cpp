#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

enum Actions
{
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    ELEVEN = 11,
    TWELVE = 12,
};

struct Task
{
    std::string name;
    int priority;
    std::string description;
    std::string deadline;
};

void InputTaskToTasks(std::vector<Task>& tasks)
{
    Task newTask;
    std::cout << "Enter name: ";
    std::cin >> newTask.name;
    std::cout << "Enter priority(1-5): ";
    std::cin >> newTask.priority;
    std::cout << "Enter description: ";
    std::cin >> newTask.description;
    std::cout << "Enter deadline (day/week): ";
    std::cin >> newTask.deadline;
    tasks.push_back(newTask);
}

void PrintTaskInProcess(Task& task)
{
    std::cout << "Name: " << task.name << " ";
    std::cout << "Priority: " << task.priority << " ";
    std::cout << "Description: " << task.description << " ";
    std::cout << "Deadline: " << task.deadline << "\n";
}

void PrintTasksByMonth(std::vector<Task>& tasks)
{
    for (const Task& task : tasks)
    {
        std::cout << "Name: " << task.name<<" ";
        std::cout << "Priority: " << task.priority << " ";
        std::cout << "Description: " << task.description << " ";
        std::cout << "Deadline: " << task.deadline << "\n";
    }
}

void EditTask(std::vector<Task>&tasks)
{
    std::string name;
    std::cout << "Enter name task for edit: ";
    std::cin >> name;
    for (Task& task : tasks)
    {
        if (name == task.name)
        {
            std::cout << "Enter name: ";
            std::cin >> task.name;
            std::cout << "Enter priority(1-5): ";
            std::cin >> task.priority;
            std::cout << "Enter description: ";
            std::cin >> task.description;
            std::cout << "Enter deadline (day/week): ";
            std::cin >> task.deadline;
        }
    }
}

void PrintTasksByWeek(std::vector<Task> & tasks)
{
    int week;
    std::cout << "Enter week: ";
    std::cin >> week;
    std::cout << "Tasks for the week: \n";
    for (Task& task : tasks)
    {
        if (task.deadline.size() == 4) 
        {
            for (int i = 0; i < task.deadline.size()+1; i++)
            {
                if (i == 3)
                {
                    int week_n;
                    std::stringstream week_k;
                    week_k << task.deadline[i];
                    week_k >> week_n;
                    if (week_n == week)
                    {
                        PrintTaskInProcess(task);
                    }
                }
            }
        }
        else if (task.deadline.size() == 3)
        {
            for (int i = 0; i < task.deadline.size()+1; i++)
            {
                if (i == 2)
                {
                    int week_n;
                    std::stringstream week_k;
                    week_k << task.deadline[i];
                    week_k >> week_n;
                    if (week_n == week)
                    {
                        PrintTaskInProcess(task);
                    }
                }
            }
        }
    }
}

void PrintTasksByDay(std::vector<Task>& tasks)
{
    int day;
    std::cout << "Enter day: ";
    std::cin >> day;
    std::cout << "Tasks for the day: \n";
    for (Task& task : tasks)
    {
        if (task.deadline.size() == 4)
        {
            for (int i = 0; i < task.deadline.size()+1; i++)
            {
                if (i == 0)
                {
                    int number;
                    std::stringstream num;
                    num << task.deadline[i] << task.deadline[i + 1];
                    num >> number;
                    if (number == day)
                    {
                        PrintTaskInProcess(task);
                    }
                }
            }
        }
        else if (task.deadline.size() == 3)
        {
            for (int i = 0; i < task.deadline.size()+1; i++)
            {
                if (i == 0)
                {
                    int num;
                    std::stringstream number;
                    number << task.deadline[i];
                    number >> num;
                    if (num == day)
                    {
                        PrintTaskInProcess(task);
                    }
                }
            }
        }
    }
}

void SearchBynameTask(std::vector<Task>& tasks)
{
    std::string name;
    std::cout << "Enter name task: ";
    std::cin >> name;
    int k = 0;
    for (Task& task : tasks)
    {
        for (int i = 0; i < name.size()+1; i++)
        {
            if (name.size()+1 == task.name.size()+1)
            {

                if (name[i] == task.name[i])
                {
                    k++;
                }
            }
            else
            {
                break;
            }
           
        }
        if (k == name.size()+1)
        {
            PrintTaskInProcess(task);
            break;
        }

    }
}

void SearchByPriority(std::vector<Task>& tasks)
{
    int priority;
    std::cout << "Enter priority: ";
    std::cin >> priority;
    for (Task& task : tasks)
    {
        if (task.priority == priority)
        {
            PrintTaskInProcess(task);
        }
    }
}

void SearchByDescription(std::vector<Task>& tasks)
{
    std::string description;
    std::cout << "Enter description: ";
    std::cin >> description;
    int k = 0;
    for (Task& task : tasks)
    {
        for (int i = 0; i < description.size()+1; i++)
        {
            if (description.size()+1 == task.description.size()+1)
            {
                if (description[i] == task.description[i])
                {
                    k++;
                }
            }
            else
            {
                break;
            }

        }
        if (k == description.size()+1)
        {
            PrintTaskInProcess(task);
            break;
        }
    }
}

void SearchByDeadline(std::vector<Task>& tasks)
{
    std::string deadline;
    std::cout << "Enter deadline: ";
    std::cin >> deadline;
    for (Task& task : tasks)
    {
        bool flag = false;
        if (deadline.size() == 3)
        {
            for (int i = 0; i < deadline.size(); i++)
            {
                if (deadline.size() == task.deadline.size())
                {

                    if (deadline[i] == task.name[i])
                    {
                        flag = true;
                    }
                }
                else
                {
                    break;
                }
            }
            PrintTaskInProcess(task);
            break;
        }
        else if (deadline.size() == 4)
        {
            for (int i = 0; i < deadline.size(); i++)
            {
                if (deadline.size() == task.deadline.size())
                {

                    if (deadline[i] == task.name[i])
                    {
                        flag = true;
                    }
                }
                else
                {
                    break;
                }
            }
            PrintTaskInProcess(task);
            break;
        }
        else
        {
            std::cerr << "Uncorrect deadline\n";
            break;
        }
    }
}

void DeleteTask(std::vector<Task>& tasks)
{
    std::string taskName;
    std::cout << "Enter task name for delete: ";
    std::cin >> taskName;
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [&](Task const& task) {return task.name == taskName; }), tasks.end());

    PrintTasksByMonth(tasks);
}

void SortedTasksByPriority(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) { return a.priority < b.priority; });
    
    std::cout << "Tasks sorted by priority\n";
    
    PrintTasksByMonth(tasks);
}

void SortedTasksBydeadline(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) 
    {
            int day1 = std::stoi(a.deadline.substr(0, a.deadline.find('/')));
            int day2= std::stoi(b.deadline.substr(0, b.deadline.find('/')));
            return day1 < day2;
    });

    std::cout << "Tasks sorted by deadline\n";

    PrintTasksByMonth(tasks);
}

int main()
{
    std::cout << "--------------------You tasks list--------------------\n\n";
    std::vector<Task> Tasks;
    std::cout << "Enter 1 for add task\n";
    std::cout << "Enter 2 for delete task\n";
    std::cout << "Enter 3 for edit task\n";
    std::cout << "Enter 4 for search by name\n";
    std::cout << "Enter 5 for search by priority\n";
    std::cout << "Enter 6 for search by description\n";
    std::cout << "Enter 7 for search by deadline\n";
    std::cout << "Enter 8 for print tasks from a day\n";
    std::cout << "Enter 9 for print tasks from a week\n";
    std::cout << "Enter 10 for print tasks from a month\n";
    std::cout << "Enter 11 for sorted tasks by priority\n";
    std::cout << "Enter 12 for sorted by deadline\n";
    std::cout << "Enter 0 for exit\n";
    bool flag=true;
    do
    {
        Actions action;
        int number;
        std::cout << "\nEnter action: ";
        std::cin >> number;
        action = (Actions)number;
        switch (action)
        {
        case ONE:
            InputTaskToTasks(Tasks);
            break;
        case TWO:
            DeleteTask(Tasks);
            break;
        case THREE:
            EditTask(Tasks);
            break;
        case FOUR:
            SearchBynameTask(Tasks);
            break;
        case FIVE:
            SearchByPriority(Tasks);
            break;
        case SIX:
            SearchByDescription(Tasks);
            break;
        case SEVEN:
            SearchByDeadline(Tasks);
            break;
        case EIGHT:
            PrintTasksByDay(Tasks);
            break;
        case NINE:
            PrintTasksByWeek(Tasks);
            break;
        case TEN:
            PrintTasksByMonth(Tasks);
            break;
        case ELEVEN:
            SortedTasksByPriority(Tasks);
            break;
        case TWELVE:
            SortedTasksBydeadline(Tasks);
            break;
        case 0:
            std::cout << "Good bye!";
            flag = false;
            break;
            return 0;
        default:
            std::cout << "Uncorrect action!";
        }

    } while (flag != false);
    return 0;
}

    
