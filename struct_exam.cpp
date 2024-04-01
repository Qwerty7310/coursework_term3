#include "struct_exam.h"
#include "print_DB.h"

//добавление нового экзамена
void add_exam(Exam **list_of_exams, Exam *new_exam)
{
    if ((*list_of_exams)->next == nullptr) //если список экзаменов пуст
    {
        *list_of_exams = new_exam;
        (*list_of_exams)->next = *list_of_exams; //указатель на следующий узел указывает на сам экзамен
        return; //выйти из функции
    }
    //инициализировать указатель для прохода по списку в поисках конца
    Exam *ptr_to_exam = (*list_of_exams)->next;
    //пока не дошли до последнего элемента
    while(ptr_to_exam->next != *list_of_exams)
        ptr_to_exam = ptr_to_exam->next; //переместить указатель на следующий элемент
    //добавляем новый элемент
    ptr_to_exam->next = new_exam;
    new_exam->next = *list_of_exams;
}

//удалить экзамен
void delete_exam(Exam **list_of_exams, Exam **exam, Group **list_of_groups, bool question)
{
    if (question)
    {
        cout << "\nВы уверены, что хотите удалить экзамен?\n";
        cout << "Введите \"1\", если хотите удалить экзамен, или любой другой символ, чтобы выйти в главное меню: ";
        char answer;
        cin >> answer;
        cin.clear(); //очистка ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //удалить '\n', оставшийся после ввода
        if (answer != '1')
        {
            cout << "\nЭкзамен не удален.";
            return;
        }
    }


    if (list_of_groups)
    {
        //уменьшаем количество экзаменов у группы на 1
        Group *ptr_to_group = search_group(*list_of_groups, (*exam)->group);
        ptr_to_group->number_of_exams = ptr_to_group->number_of_exams - 1;
        //если экзамен был только 1, удаляем группу
        if (ptr_to_group->number_of_exams == 0) delete_group(list_of_groups, &ptr_to_group);
    }


    if (*exam == *list_of_exams) //если удаляем первый в списке экзамен
    {
        //если в списке только один экзамен
        if ((*exam)->next == *list_of_exams)
        {
            (*list_of_exams)->next = nullptr;
            int i = 0;
            while ((*list_of_exams)->group[i] != '\0')
            {
                (*list_of_exams)->group[i] = '\0';
                i++;
            }
            if (question) cout << "\nЭкзамен удален.\n";
            return;
        }
        //если в списке несколько экзаменов
        *list_of_exams = (*exam)->next; //делаем головой списка следующий элемент
        //инициализируем указатель для прохода списка
        Exam *ptr_to_exam = (*list_of_exams)->next;
        //пока не дошли до конца списка, передвигаем указатель
        while (ptr_to_exam->next != *exam) ptr_to_exam = ptr_to_exam->next;
        ptr_to_exam->next = *list_of_exams; //меняем указатель последнего элемента на указатель на новую голову списка
        delete *exam; //удаляем экзамен
        if (question) cout << "\nЭкзамен удален.\n";
        return;
    }
    //если удаляем не первый элемент
    Exam *ptr_to_exam = *list_of_exams;
    //идем по списку, пока не дошли до удаляемого элемента
    while (ptr_to_exam->next != *exam) ptr_to_exam = ptr_to_exam->next;
    ptr_to_exam->next = (*exam)->next; //меняем указатель предыдущего элемента
    delete *exam; //удаляем экзамен
    if (question) cout << "\nЭкзамен удален.\n";
}

//добавить новую группу в список групп
Group* add_group(Group **list_of_groups, char new_group[])
{
    //если список пуст
    if ((*list_of_groups)->next == nullptr)
    {
        int i = 0;
        //записываем название группы в головной элемент списка
        while (new_group[i] != '\0')
        {
            (*list_of_groups)->name_of_group[i] = new_group[i];
            i++;
        }
        (*list_of_groups)->next = *list_of_groups; //закольцовываем список
        return *list_of_groups; //выходим из функции
    }
    //инициализируем указатель для прохода списка
    Group *ptr_to_group = *list_of_groups;
    //проходим до конца списка и останавливаемся на последнем элементе
    while (ptr_to_group->next != *list_of_groups) ptr_to_group = ptr_to_group->next;
    auto *group = new Group; //создаем новый элемент списка
    //записываем название группы
    int i = 0;
    while (new_group[i] != '\0')
    {
        group->name_of_group[i] = new_group[i];
        i++;
    }
    //меняем указатели
    ptr_to_group->next = group;
    group->next = *list_of_groups;
    return group;
}

//удалить группу из списка групп
void delete_group(Group **list_of_groups, Group **group)
{
    if (*group == *list_of_groups) //если удаляемая группа первая в списке
    {
        if ((*list_of_groups)->next == *list_of_groups) //если удаляемая группа одна в списке
        {
            //очищаем поле названия
            int i = 0;
            while ((*list_of_groups)->name_of_group[i] != '\0')
            {
                (*list_of_groups)->name_of_group[i] = '\0';
                i++;
            }
            (*list_of_groups)->number_of_exams = 0; //обнуляем число экзаменов
            (*list_of_groups)->next = nullptr; //обнуляем указатель на следующий узел
            return; //выходим из функции
        }
        //если не одна в списке
        *list_of_groups = (*group)->next; //меняем указатель на следующий узел
        //инициализируем указатель для прохода списка
        Group *ptr_to_group = *list_of_groups;
        //проходим до конца списка
        while (ptr_to_group->next != *group) ptr_to_group = ptr_to_group->next;
        ptr_to_group->next = *list_of_groups; //указатель последнего элемента на голову списка
        delete *group; //удаляем группу
        group = nullptr;
        return; //выход из функции
    }
    //инициализируем указатель для прохода списка
    Group *ptr_to_group = *list_of_groups;
    //проходим до конца список
    while (ptr_to_group->next != *group) ptr_to_group = ptr_to_group->next;
    ptr_to_group->next = (*group)->next; //меняем указатель
    delete *group; //удаляем группу
    group = nullptr;
}

//найти экзамен
Exam* search_exam(Exam **list_of_exams, char group[], char subject[])
{
    //если список экзаменов пуст
    if ((*list_of_exams)->next == nullptr)
    {
        return nullptr; //вернуть пустой указатель
    }
    //инициализируем указатель для прохождения списка
    Exam *ptr_to_exam = *list_of_exams;
    bool first_iteration = true; //флаг первого прохождения цикла
    //пока не дошли до конца списка
    while (ptr_to_exam != *list_of_exams || first_iteration)
    {
        first_iteration = false;
        //Если нашли предмет у заданной группы
        if (strcmp(group, ptr_to_exam->group) == 0 && strcmp(subject, ptr_to_exam->subject) == 0)
        {
            return ptr_to_exam; //возвращаем адрес найденного экзамена
        }
        ptr_to_exam = ptr_to_exam->next; //передвигаем указатель на следующий узел
    }
    return nullptr; //если ничего не нашли, возвращаем нулевой указатель
}

//найти группу
Group* search_group(Group *list_of_groups, char group[])
{
    //проверка списка на пустоту
    if (list_of_groups->next == nullptr)
        return nullptr; //возвращаем пустой указатель
    //инициализируем указатель для прохождения списка
    Group *ptr_to_group = list_of_groups;
    bool first_iteration = true; //флаг первого прохождения цикла
    //пока не дошли до конца списка
    while (ptr_to_group != list_of_groups || first_iteration)
    {
        first_iteration = false;
        if (strcmp(group, ptr_to_group->name_of_group) == 0)
        {
            return ptr_to_group; //если нашли, возвращаем true
        }
        ptr_to_group = ptr_to_group->next; //передвигаем указатель на следующий узел
    }
    return nullptr; //если ничего не нашли, возвращаем нулевой указатель
}


void delete_list(Exam **list_of_exams, Group **list_of_groups)
{
    if ((*list_of_exams)->next == nullptr)
    {
        cout << "Нет строк для сортировки. База данных пуста.\n\n";
        return;
    }
    Exam *ptr_to_exam = *list_of_exams;
    while (ptr_to_exam->next != *list_of_exams)
    {
        Exam *temp = ptr_to_exam;
        ptr_to_exam = ptr_to_exam->next;
        delete_exam(list_of_exams, &temp, list_of_groups, false);
    }
    delete_exam(list_of_exams, list_of_exams,list_of_groups, false);
}

//Получить длину строки
int get_length(char *str)
{
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}