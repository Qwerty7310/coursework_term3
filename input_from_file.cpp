#include "input_from_file.h"

void enter_from_file(Exam **list_of_exams, Group **list_of_groups)
{
    //инициализация переменной пути файла
    char path[ARRAY_SIZE] = {};
    cout << "Введите имя файла с расширением: ";
    int i = 0;
    //Ввод пути файла
    while (true)
    {
        path[i] = getchar();
        if (path[i] == '*') return;
        if (path[i] == '\n')
        {
            path[i] = '\0';
            break;
        }
        i++;
    }
    //инициализация файловой переменной
    ifstream file;
    file.open(path);
    //если файла не существует
    if (!file) {
        cout << "\nФайл \"" << path << "\" не найден.\n\n";
        return;
    }
    else
        //если файл пуст
        if (file.peek() == EOF)
        {
            cout << "\nФайл \"" << path << "\" пуст.\n\n"; // если первый символ конец файла
            return;
        }
        else cout << "\nФайл \"" << path << "\" открыт.\n\n";
    int number_of_lines = count_lines_in_file(file); //подсчет количество строк в файле
    bool error_flag; //индикатор наличия ошибок
    for (int j = 0; j < number_of_lines; j++)
    {
        error_flag = false; //изначально ошибок нет
        auto *exam = new Exam;
        // Чтение номера группы
        move_cursor(file);
        if (file.eof())
            break;
        file >> exam->group;
        if (!check_group(exam->group))
        {
            cout << "В записи " << j+1 << " некорректный номер группы.\n";
            error_flag = true;
        }
        // Чтение названия предмета
        move_cursor(file); //пропуск пробелов
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ') //если впереди не конец строки
            file >> exam->subject;
        if (!check_subject(exam->subject))
        {
            cout << "В записи " << j+1 << " некорректное название предмета.\n";
            error_flag = true;
        }
        // Чтение имени преподавателя
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->lecturer;
        if (!check_lecturer(exam->lecturer))
        {
            cout << "В записи " << j+1 << " некорректное имя преподавателя.\n";
            error_flag = true;
        }
        // Чтение номера аудитории
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->classroom;
        if (!check_classroom(exam->classroom))
        {
            cout << "В записи " << j+1 << " некорректный номер аудитории.\n";
            error_flag = true;
        }
        // Чтение дня консультации
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->consultation_day;
        if (!check_day(exam->consultation_day))
        {
            cout << "В записи " << j+1 << " некорректный день консультации.\n";
            error_flag = true;
        }
        // Чтение времени консультации
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->consultation_time;
        if (!check_time(exam->consultation_time))
        {
            cout << "В записи " << j+1 << " некорректное время консультации.\n";
            error_flag = true;
        }
        // Чтение дня экзамена
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->exam_day;
        if (!check_day(exam->exam_day))
        {
            cout << "В записи " << j+1 << " некорректный день экзамена.\n";
            error_flag = true;
        }
        // Чтение времени экзамена
        move_cursor(file);
        if (file.peek() != '\n' && file.peek() != '\r' && file.peek() != ' ')
            file >> exam->exam_time;
        if (!check_time(exam->exam_time))
        {
            cout << "В записи " << j+1 << " некорректное время экзамена.\n";
            error_flag = true;
        }
        file.seekg(1, ios::cur);
        while (file.peek() == '\n' || file.peek() == '\r')
        {
            number_of_lines -= 1;
            file.seekg(1, ios::cur);
        }
        if (error_flag)
        {
            delete exam;
            continue;
        }
        Group *ptr_to_group = search_group(*list_of_groups, exam->group);
        if (!ptr_to_group)
        {
            ptr_to_group = add_group(list_of_groups, exam->group);
        }
        if (ptr_to_group->number_of_exams >= 5)
        {
            cout << "У группы " << exam->group << " уже введено максимальное количество экзаменов. Запись " << j + 1 << " проигнорирована.\n";
            delete exam;
            continue;
        }
        Exam *ptr_to_exam = search_exam(list_of_exams, exam->group, exam->subject);
        if (ptr_to_exam)
        {
            cout << "Экзамен \"" << exam->subject << "\" (запись " << j+1 << ") уже внесен в Базу данных для группы " << exam->group << ".\n";
            delete exam;
            continue;
        }
        add_exam(list_of_exams, exam);
        ptr_to_group->number_of_exams++;
    }
    cout << "Были введены все корректные строки.\n\n";
    file.close();
}

//сдвинуть курсор и пропустить пробелы
void move_cursor(ifstream &file) {
    while (file.peek() == ' ' || file.peek() == '\t') {
        file.seekg(1, ios::cur);
    }
}

//посчитать количество строк в файле
int count_lines_in_file(ifstream &file) {
    int count = 1;
    char c;
    for (int i = 0; !file.eof(); i++) {
        c = file.get();
        if (c == '\n' || c == '\r') count++;
    }
    file.clear();
    file.seekg(0, ios::beg);
    return count;
}