#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <set>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus
{
    NEW,         // новая
    IN_PROGRESS, // в разработке
    TESTING,     // на тестировании
    DONE         // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;
// Объявляем тип-синоним для map<TaskStatus, int>
// позволяющего сопоставлять разработчика и количество задач каждого статуса
using PersonTasks = map<string, TasksInfo>;

class TeamTasks
{
public:
    // принимает текущий статус и возвращает следующий по приоритету статус
    TaskStatus Another(TaskStatus task_status)
    {
        return (TaskStatus)((int)(task_status) + 1);
    }

    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo &GetPersonTasksInfo(const string &person) const
    {
        // по ключу person возвращаем кол-во задач каждого статуса
        return person_tasks.at(person);
    };

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string &person)
    {
        // по двум ключам инкрементируем количество задач
        ++person_tasks[person][TaskStatus::NEW];
    };

    // Обновить статусы по данному количеству задач конкретного разработчика
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string &person, int task_count)
    {
        // создаём словарь обновлённых и необновлённых задач
        TasksInfo updated_tasks, untouched_tasks;

        // создаём ссылку типа TasksInfo и передаём в неё по умолчанию по ключу разработчика
        // количество задач определённого статуса (объект TasksInfo)
        TasksInfo &tasks = person_tasks[person];
        // итерируемся по статусам задач
        for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Another(status))
        {
            // считаем обновлённые задачи
            updated_tasks[Another(status)] = min(task_count, tasks[status]);
            // считаем сколько задач осталось обновить
            task_count -= updated_tasks[Another(status)];
        }
        // обновляем статус текущих задач
        for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Another(status))
        {
            // считаем нетронутые задачи
            untouched_tasks[status] = tasks[status] - updated_tasks[Another(status)];
            tasks[status] += updated_tasks[status] - updated_tasks[Another(status)];
        }
        // задачи со статусом DONE не возвращаем в необновлённых задачах
        tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

        // удаляем нулевые статусы из словарей
        DelNull(updated_tasks);
        DelNull(untouched_tasks);
        DelNull(person_tasks.at(person));
        return {updated_tasks, untouched_tasks};
    };

private:
    // словарь: <разработчик <статус, кол-во задач>>
    PersonTasks person_tasks;
    // удаляет нули
    void DelNull(TasksInfo &tasks)
    {
        // статусы для удаления
        set<TaskStatus> del_status;
        for (const auto &task : tasks)
        {
            // проверяем количество нулевых статусов
            if (task.second == 0)
            {
                del_status.insert(task.first);
            }
        }
        for (const auto status : del_status)
        {
            tasks.erase(status);
        }
    }
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь.
void PrintTasksInfo(TasksInfo tasks_info)
{
    cout << tasks_info[TaskStatus::NEW] << " new tasks"s
         << ", "s << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"s
         << ", "s << tasks_info[TaskStatus::TESTING] << " tasks are being tested"s
         << ", "s << tasks_info[TaskStatus::DONE] << " tasks are done"s << endl;
}

int main()
{
    TeamTasks tasks;
    tasks.AddNewTask("Ilia"s);
    for (int i = 0; i < 3; ++i)
    {
        tasks.AddNewTask("Ivan"s);
    }
    cout << "Ilia's tasks: "s;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"s));
    cout << "Ivan's tasks: "s;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"s));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 2);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan"s, 2);
    cout << "Updated Ivan's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: "s;
    PrintTasksInfo(untouched_tasks);
}




/*
Задание 1


Для работы над текущими задачами тимлид Матвей нанял нескольких разработчиков. Чтобы лучше следить за тем, как продвигаются работы, Матвею нужен трекер задач. Каждая задача привязана к определённому разработчику и проходит четыре статуса: NEW → IN_PROGRESS → TESTING → DONE. Матвей хочет быстро узнавать статистику задач своих коллег: сколько задач находится в каждом из статусов.
Реализуйте:

    Класс TeamTasks, трекер задач. Он может хранить только статистику — сколько задач какого разработчика находится в каком статусе. Количество разработчиков может быть любым целым положительным числом.
    Метод GetPersonTasksInfo класса TeamTasks, принимающий имя разработчика и возвращающий статистику его задач.
    Метод AddNewTask класса TeamTasks. Позволяет добавить одну задачу в статусе NEW указанному разработчику.
    Метод PerformPersonTasks класса TeamTasks. Он принимает имя разработчика и число N и вызывается, когда разработчик выполнил N задач. Считается, что разработчик выполняет вначале задачи с самым низким статусом, и эти задачи переходят в следующий статус.

Точные сигнатуры методов описаны в заготовке кода.
Метод PerformPersonTasks принимает параметры: person — имя разработчика, task_count — количество выполненных задач. Его алгоритм таков:

    Рассмотреть все невыполненные задачи разработчика person.
    Упорядочить их по статусам: сначала все задачи в статусе NEW, затем все задачи в статусе IN_PROGRESS и, наконец, задачи в статусе TESTING.
    Рассмотреть первые task_count задач и перевести каждую из них в следующий статус в соответствии с естественным порядком: NEW → IN_PROGRESS → TESTING → DONE.

Этот метод возвращает пару из двух элементов:

    Словарь со статусами обновившихся задач: количество обновившихся задач по каждому статусу.
    Информацию о невыполненных задачах — тех, статус которых не DONE и не изменился. Также в виде словаря, хранящего количество по статусу.

Для словаря, хранящего количество задач по статусам, предусмотрен псевдоним TasksInfo.
Ограничения
В словари, возвращаемые методом PerformPersonTasks, не добавляйте лишние значения, то есть статусы, имеющие ноль задач.
В методе PerformPersonTasks не обновляйте статус одной и той же задачи дважды.
Также в методе PerformPersonTasks второй элемент возвращаемого кортежа не должен содержать задач со статусом DONE.
Если разработчика с именем person нет, метод PerformPersonTasks возвращает кортеж из двух пустых TasksInfo.
Как будет тестироваться программа
Будет проверена корректность класса TeamTasks и его методов.
Гарантируется, что параметр task_count метода PerformPersonTasks — положительное число. Если task_count превышает текущее количество невыполненных задач разработчика, достаточно считать, что task_count равен количеству невыполненных задач. Дважды обновлять статус какой-либо задачи в этом случае не нужно.
Гарантируется, что метод GetPersonTasksInfo не будет вызван для разработчика, не имеющего задач.
Пример работы метода PerformPersonTasks
Допустим, у конкретного разработчика десять задач со следующими статусами:

    NEW — 3 задачи,
    IN_PROGRESS — 2 задачи,
    TESTING — 4 задачи,
    DONE — 1 задача.

Поступает команда PerformPersonTasks с параметром task_count, равным 4. Это означает, что нужно обновить статус c NEW до IN_PROGRESS для трёх задач и с IN_PROGRESS до TESTING для одной задачи. Новые статусы задач:

    NEW — нет задач,
    IN_PROGRESS — 4 задачи: 3 обновлённых, 1 старая,
    TESTING — 5 задач: 1 обновлённая, 4 старых,
    DONE — 1 старая.

В этом случае нужно вернуть кортеж из двух словарей:

    Обновлённые задачи: IN_PROGRESS — 3, TESTING — 1.
    Необновлённые задачи, исключая задачи со статусом DONE: IN_PROGRESS — 1, TESTING — 4.

Статусы, которым соответствует ноль задач, в словари не добавляем.
Пример ввода:

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
    TasksInfo updated_tasks, untouched_tasks;
  
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);
  
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);
} 

Пример вывода:

Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done 

Терминал

*/




/*
// Решение от авторов:


#include <algorithm>
#include <map>
#include <string>
#include <tuple>
#include <vector>
 
using namespace std;
 
// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};
 
// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;
 
// Выделим в отдельную функцию получение следующего по приоритету типа задачи
// Функция налагает требование на входной параметр: он не должен быть равен DONE
// При этом task_status явно не сравнивается с DONE, что позволяет
// сделать эту функцию максимально эффективной
TaskStatus Next(TaskStatus task_status) {
      return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}
 
// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;
 
class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
      const TasksInfo& GetPersonTasksInfo(const string& person) const;
    
      // Добавить новую задачу (в статусе NEW) для конкретного разработчика
      void AddNewTask(const string& person);
    
      // Обновить статусы по данному количеству задач конкретного разработчика
      tuple<TasksInfo, TasksInfo> PerformPersonTasks(
                  const string& person, int task_count);
 
private:
      map<string, TasksInfo> person_tasks_;
};
 
const TasksInfo& TeamTasks::GetPersonTasksInfo(const string& person) const {
      return person_tasks_.at(person);
}
 
void TeamTasks::AddNewTask(const string& person) {
      ++person_tasks_[person][TaskStatus::NEW];
}
 
// Функция для удаления нулей из словаря
void RemoveZeros(TasksInfo& tasks_info) {
      // Соберём те статусы, которые нужно убрать из словаря
      vector<TaskStatus> statuses_to_remove;
      for (const auto& task_item : tasks_info) {
            if (task_item.second == 0) {
                  statuses_to_remove.push_back(task_item.first);
            }
      }
      for (const TaskStatus status : statuses_to_remove) {
            tasks_info.erase(status);
      }
}
 
 
tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(
            const string& person, int task_count) {
      TasksInfo updated_tasks, untouched_tasks;
      
      // Здесь и далее мы будем пользоваться тем фактом, что в std::map оператор [] 
      // в случае отсутствия ключа инициализирует значение по умолчанию,
      // если это возможно.
      // std::map::operator[] ->
      // http://ru.cppreference.com/w/cpp/container/map/operator_at
      TasksInfo& tasks = person_tasks_[person];
    
      // Посчитаем, сколько задач каждого из статусов нужно обновить, 
      // пользуясь тем фактом, что по умолчанию enum class инциализирует значения
      // от нуля по возрастанию.
      // enum class -> http://ru.cppreference.com/w/cpp/language/enum
      for (TaskStatus status = TaskStatus::NEW;
           status != TaskStatus::DONE;
           status = Next(status)) {
            // Считаем обновлённые
            updated_tasks[Next(status)] = min(task_count, tasks[status]);
            // Считаем, сколько осталось обновить
            task_count -= updated_tasks[Next(status)];
      }
    
      // Обновляем статус текущих задач в соответствии с информацией об обновлённых 
      // и находим количество нетронутых
      for (TaskStatus status = TaskStatus::NEW;
           status != TaskStatus::DONE;
           status = Next(status)) {
            untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
            tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
      }
      // По условию, DONE задачи не нужно возвращать в необновлённых задачах
      tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];
    
      // По условию в словарях не должно быть нулей
      RemoveZeros(updated_tasks);
      RemoveZeros(untouched_tasks);
      RemoveZeros(person_tasks_.at(person));
    
      return {updated_tasks, untouched_tasks};
}
*/