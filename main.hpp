#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int NUMCOURSE = 2;
struct Student
{
    int id;
    string name;
    int score[NUMCOURSE];
    double sum;
    double avg;
    struct Student *next;
};

Student *makeStudent(int N);
void printStudent(Student *head);
int getLength(Student *head);
Student *sortStudent(Student *head, int asc);
int compareStudent(Student *tmp, int asc);
Student *swapStudent(Student *prev, Student *tmp);

Student *makeStudent(int N)
{
    ifstream ifs;
    ifs.open("students.txt");
    if (!ifs)
    {
        cerr << "Error: file open error" << endl;
        exit(0);
    }
    Student *head, *tmp, *prev;
    double studentSum;
    for(int i=0;i<N;i++){
        studentSum = 0;
        Student *tmp = new Student;
        ifs >> tmp->id >> tmp->name;
        for (int j = 0; j < NUMCOURSE; j++){
            ifs >> tmp->score[j];
            studentSum = studentSum + tmp->score[j];
        }
        tmp->sum = studentSum;
        tmp->avg = studentSum / NUMCOURSE;
        tmp->next = NULL;
        if (i == 0)
            head = tmp;
        else
            prev->next = tmp;
        prev = tmp;
    }
    return head;
}
void printStudent(Student *head)
{
    Student *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->id << "\t";
        cout << ptr->name << "\t";
        cout << ptr->score[0] << "\t";
        cout << ptr->score[1] << "\t";
        cout << ptr->sum << "\t";
        cout << ptr->avg << "\n";
        ptr = ptr->next;
    }
    cout << endl;
    /*******************************
     * Code your program here
     *******************************/
}
int getLength(Student *head)
{
    int cnt = 0;
    Student *ptr = head;
    while (ptr != NULL){
        cnt++;
        ptr = ptr->next;
    }

    return cnt;
}
Student *sortStudent(Student *head, int asc)
{
    Student *tmp, *prev;
    int iteration, length;

    length = getLength(head);
    for (int i = 0; i < length - 1; i++){
        tmp = prev = head;
        iteration = 0;
        while (tmp->next != NULL){
            if (compareStudent(tmp, asc) == 1)
                tmp = swapStudent(prev, tmp);
            if (iteration == 0)
                head = tmp;
            iteration++;
            prev = tmp;
            tmp = tmp->next;
        }
    }
    return head;
}

int compareStudent(Student *tmp, int asc)
{
    if (asc == 1){
        if (tmp->sum > tmp->next->sum)
            return 1;
    }
    else{
        if (tmp->sum < tmp->next->sum)
            return 1;
    }
    return 0;
}

Student *swapStudent(Student *prev, Student *tmp)
{
    Student *after;
    after = tmp->next;
    prev->next = tmp->next;
    tmp->next = after->next;
    after->next = tmp;
    return after;
}
