#include "sort.h"

void sorting_menu(Exam **list_of_exams)
{
    //очистка консоли
    if ((*list_of_exams)->next == nullptr)
    {
        cout << "Нет строк для сортировки. База данных пуста.\n\n";
        return;
    }
    if ((*list_of_exams)->next == *list_of_exams)
    {
        system("cls");
        cout << "База данных состоит только из 1 строки.\n\n";
        print_DB(*list_of_exams);
        return;
    }
    cout << "\nВыберите команду:\n"
    << "\tСортировка\n"
    << "1 - по номеру группы\n"
    << "2 - по названию предмета\n"
    << "3 - по имени преподавателя\n"
    << "4 - по номеру аудитории\n"
    << "5 - по дню консультации\n"
    << "6 - по времени консультации\n"
    << "7 - по дню экзамена\n"
    << "8 - по времени экзамена\n\n"
    << "9 - выйти в главное меню\n\n";
    int comm;
    cout << "\nВведите номер команды: ";
    cin >> comm;
    //если некорректный ввод
    if(cin.fail() || comm < 1 || comm > 9)
    {
        cout << "Введите корректный номер команды: натуральное число от 1 до 9.\n";
        cin.clear(); //очистка ввода
        system("cls"); //очистка консоли
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
        system("pause");
        return;
    }
    cin.clear(); //очистка ввода
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
    if (comm == 9) return;
    int (*comparison_functions[])(Exam *, Exam *) = {compare_groups, compare_subjects, compare_lecturers, compare_classrooms, compare_consultation_days, compare_consultation_times, compare_exam_days, compare_exam_times};
    int size = get_number_of_elements(*list_of_exams);
    if (size > 200)
        shell_sort(list_of_exams, comparison_functions[comm-1]);
    else
        selection_sort(list_of_exams, comparison_functions[comm-1]);
    system("cls");
    print_DB(*list_of_exams);
}

void selection_sort(Exam **list_of_exams, int(*comparison_function)(Exam *, Exam *))
{
    Exam *ptr_to_cur = *list_of_exams; //указатель на текущий рассматриваемый элемент
    Exam *ptr_before_cur = nullptr; //указатель на элемент перед текущим
    Exam *ptr_before_replacement = nullptr; //указатель на элемент перед меняемым
    bool first_iteration = true; //флаг первого прохода цикла
    //пока не прошли весь список или заходим в цикл первый раз
    while (ptr_to_cur != *list_of_exams || first_iteration)
    {
        //Ищем минимальный элемент
        Exam *ptr_to_min = ptr_to_cur; //указатель на минимальный элемент
        Exam *ptr_before_min; //указатель на элемент перед минимальным
        Exam *ptr_to_replacement = ptr_to_cur;
        first_iteration = true; //флаг первого прохода цикла
        //Проходим от текущего до конца списка в поисках минимального
        while (ptr_to_replacement != *list_of_exams || first_iteration)
        {
//            if (strcmp(ptr_to_replacement->group, ptr_to_min->group) < 0)
            if (comparison_function(ptr_to_replacement, ptr_to_min) < 0)
            {
                //Если нашли, записываем в переменную
                ptr_to_min = ptr_to_replacement;
                ptr_before_min = ptr_before_replacement;
            }
            ptr_before_replacement = ptr_to_replacement;
            ptr_to_replacement = ptr_to_replacement->next;
            first_iteration = false;
        }
        //Меняем текущий с минимальным, если это не один и тот же элемент
        if (ptr_to_cur != ptr_to_min)
        {
            if (ptr_to_cur->next == ptr_to_min)
            {
                if (ptr_before_cur) ptr_before_cur->next = ptr_to_min;
                ptr_to_cur->next = ptr_to_min->next;
                ptr_to_min->next = ptr_before_min;
            }
            else
            {
                if (ptr_before_cur) ptr_before_cur->next = ptr_to_min;
                Exam *temp_ptr = ptr_to_cur->next;
                ptr_to_cur->next = ptr_to_min->next;
                ptr_to_min->next = temp_ptr;
                ptr_before_min->next = ptr_to_cur;
            }
            if (ptr_to_cur == *list_of_exams)
            {
                *list_of_exams = ptr_to_min;
                Exam *temp_ptr = ptr_to_cur;
                while (temp_ptr->next != ptr_to_cur) temp_ptr = temp_ptr->next;
                temp_ptr->next = *list_of_exams;
                (*list_of_exams)->next = ptr_to_min->next;
            }
        }
        //Переставляем указатели на следующий элемент
        ptr_before_cur = ptr_to_min;
        ptr_to_cur = ptr_to_min->next;
        first_iteration = false;
    }
}


void shell_sort(Exam **list_of_exams, int(*comparison_function)(Exam *, Exam *))
{
    int size = get_number_of_elements(*list_of_exams); //получаем размер списка
    int h = 1; //изначально шаг равен 1
    while (h <= size/3) h = 3*h + 1; //находим шаг
    for (h; h > 0; h = (h-1)/3)
    {
        for (int i = h; i < size; i++)
        {
            Exam *temp_ptr = get_ptr_to_element(*list_of_exams, i);
            int j;
            for (j = i; j >= h && comparison_function(get_ptr_to_element(*list_of_exams, j-h), temp_ptr) > 0; j -= h)
            {
                Exam *ptr_j = get_ptr_to_element(*list_of_exams, j);
                Exam *ptr_before_j;
                if (ptr_j == *list_of_exams)
                    ptr_before_j = nullptr;
                else
                    ptr_before_j = get_ptr_to_element(*list_of_exams, j-1);
                Exam *ptr_j_minus_h = get_ptr_to_element(*list_of_exams, j-h);
                Exam *ptr_before_j_minus_h;
                if (ptr_j_minus_h == *list_of_exams)
                    ptr_before_j_minus_h = nullptr;
                else
                    ptr_before_j_minus_h = get_ptr_to_element(*list_of_exams, j-h-1);

                if (ptr_j_minus_h->next == ptr_j)
                {
                    if (ptr_before_j_minus_h) ptr_before_j_minus_h->next = ptr_j;
                    ptr_j_minus_h->next = ptr_j->next;
                    ptr_j->next = ptr_before_j;
                }
                else
                {
                    if (ptr_before_j_minus_h) ptr_before_j_minus_h->next = ptr_j;
                    Exam *temp = ptr_j_minus_h->next;
                    ptr_j_minus_h->next = ptr_j->next;
                    ptr_j->next = temp;
                    ptr_before_j->next = ptr_j_minus_h;
                }
                if (ptr_j_minus_h == *list_of_exams)
                {
                    *list_of_exams = ptr_j;
                    Exam *temp = ptr_j_minus_h;
                    while (temp->next != ptr_j_minus_h) temp = temp->next;
                    temp->next = *list_of_exams;
                    (*list_of_exams)->next = ptr_j->next;
                }
            }
        }
    }
}

//сравнить номера групп
int compare_groups(Exam *ptr_to_exam1, Exam *ptr_to_exam2)
{
    return strcmp(ptr_to_exam1->group, ptr_to_exam2->group);
}

//сравнить названия предметов
int compare_subjects(Exam *ptr_to_exam1, Exam *ptr_to_exam2)
{
    return strcmp(ptr_to_exam1->subject, ptr_to_exam2->subject);
}

//сравнить имена преподавателей
int compare_lecturers(Exam *ptr_to_exam1, Exam *ptr_to_exam2)
{
    return strcmp(ptr_to_exam1->lecturer, ptr_to_exam2->lecturer);
}

//сравнить номера аудиторий
int compare_classrooms(Exam *ptr_to_exam1, Exam *ptr_to_exam2)
{
    return strcmp(ptr_to_exam1->classroom, ptr_to_exam2->classroom);
}

//сравнить день консультации
int compare_consultation_days(Exam *ptr_to_exam1, Exam *ptr_to_exam2)
{
    return strcmp(ptr_to_exam1->consultation_day, ptr_to_exam2->consultation_day);
}

//сравнить время консультации
int compare_consultation_times(Exam *ptr_to_exam1, Exam *ptr_to_exam2)
{
    return strcmp(ptr_to_exam1->consultation_time, ptr_to_exam2->consultation_time);
}

//сравнить день экзамена
int compare_exam_days(Exam *ptr_to_exam1, Exam *ptr_to_exam2)
{
    return strcmp(ptr_to_exam1->exam_day, ptr_to_exam2->exam_day);
}

//сравнить время экзамена
int compare_exam_times(Exam *ptr_to_exam1, Exam *ptr_to_exam2)
{
    return strcmp(ptr_to_exam1->exam_time, ptr_to_exam2->exam_time);
}

int get_number_of_elements(Exam *list_of_exams)
{
    if (list_of_exams->next == nullptr) return 0;
    Exam *ptr_to_exam = list_of_exams;
    int counter = 0;
    bool first_iteration = true;
    while (ptr_to_exam != list_of_exams || first_iteration)
    {
        first_iteration = false;
        counter++;
        ptr_to_exam = ptr_to_exam->next;
    }
    return counter;
}

Exam* get_ptr_to_element(Exam *list_of_exams, int number)
{
    if (list_of_exams->next == nullptr) return nullptr;
    if (number < 0) return nullptr;
    Exam *ptr_to_exam = list_of_exams;
    int index = 0;
    bool first_iteration = true;
    while (ptr_to_exam != list_of_exams || first_iteration)
    {
        first_iteration = false;
        if (index == number) return ptr_to_exam;
        index++;
        ptr_to_exam = ptr_to_exam->next;
    }
    return nullptr;
}