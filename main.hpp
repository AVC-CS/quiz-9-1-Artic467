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
#define struct Student Student;
// typedef struct Student Student;

Student *makeStudent(int N);
void printStudent(Student *head);
int getLength(Student *head);
Student *sortStudent(Student *head, int asc);

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
    /*******************************
     * Code your program here
     *******************************/
    return head;
}
