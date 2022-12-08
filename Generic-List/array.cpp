#include <iostream>
using namespace std;

struct Model
{
    int id;
    string name;
};

struct Model list[10];
int main()
{
    cout << "Start" << endl;
    for (int i = 0; i < 10; i++)
    {
        list[i] = {i, "name"};
    }
    for (int i = 0; i < 10; i++)
    {
        cout << list[i].id << list[i].name << endl;
    }
}