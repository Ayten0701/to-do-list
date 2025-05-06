#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TodoList {
private:
    vector<string> tasks;  // Список задач

public:
    // Функция для добавления задачи
    void addTask(const string& task) {
        tasks.push_back(task);
    }

    // Функция для удаления задачи
    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Неверный индекс задачи!" << endl;
        }
    }

    // Функция для вывода всех задач
    void viewTasks() {
        if (tasks.empty()) {
            cout << "Список задач пуст!" << endl;
        } else {
            cout << "Ваши задачи:" << endl;
            for (int i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i] << endl;
            }
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string task;

    while (true) {
        // Меню
        cout << "\nМеню:\n";
        cout << "1. Добавить задачу\n";
        cout << "2. Удалить задачу\n";
        cout << "3. Посмотреть все задачи\n";
        cout << "4. Выход\n";
        cout << "Введите номер действия: ";
        cin >> choice;

        // Очистка буфера ввода
        cin.ignore();

        if (choice == 1) {
            cout << "Введите задачу: ";
            getline(cin, task);
            todoList.addTask(task);
        }
        else if (choice == 2) {
            todoList.viewTasks();
            cout << "Введите номер задачи для удаления: ";
            int index;
            cin >> index;
            todoList.removeTask(index - 1);
        }
        else if (choice == 3) {
            todoList.viewTasks();
        }
        else if (choice == 4) {
            cout << "Выход из программы.\n";
            break;
        } else {
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
