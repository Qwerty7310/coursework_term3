#include <filesystem>
#include "output_to_file.h"

void enter_to_file(Exam *list_of_exams)
{
//    setlocale(LC_ALL, "Russian");

    if (list_of_exams->next == nullptr)
    {
        cout << "Невозможно записать Базу данных в файл. База данных пуста.\n\n";
        return;
    }
    //инициализация пути к файлу
    char path[ARRAY_SIZE] = {};
    while (true)
    {
        //ввод пути к файлу
        system("cls");
        cout << "\nДля выхода в главное меню введите 0.\n\n";
        cout << "Введите имя файла: ";
        int i = 0;
        //ввод имени файла
        while (true)
        {
            path[i] = getchar();
            if (path[i] == '\n' || path[i] == '\r')
            {
                path[i] = '\0';
                break;
            }
            i++;
        }
        if (strcmp(path, "0") == 0) return;
        //проверка имени файла
        if (!check_file(path)) {
            cout << "\nИмя файла \"" << path << "\" некорректно.\n\n";
            system("pause");
            continue;
        }
        break;
    }
    //инициализация файловой переменной
    ofstream file( path, ios_base::binary | ios_base::out );
    bool first_iteration = true; //флаг первого прохода цикла
    Exam *ptr_to_exam = list_of_exams;
    ptr_to_exam = list_of_exams;
    while (ptr_to_exam != list_of_exams || first_iteration)
    {
        file << ptr_to_exam->group << '\t'
        << ptr_to_exam->subject << '\t'
        << ptr_to_exam->lecturer << '\t'
        << ptr_to_exam->classroom << '\t'
        << ptr_to_exam->consultation_day << '\t'
        << ptr_to_exam->consultation_time << '\t'
        << ptr_to_exam->exam_day << '\t'
        << ptr_to_exam->exam_time << endl;
        ptr_to_exam = ptr_to_exam->next;
        first_iteration = false;
    }
    cout << "\nДанные успешно загружены в файл \"" << path << "\".\n\n";
}
