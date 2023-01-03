// #include <iostream>
// #define MAXSIZE 5

// using namespace std;

// int Stack[MAXSIZE], top = 0, item, i;

// void PUSH()
// {
//     if (top == MAXSIZE)
//         cout << "Stack is full!!overflow\n";
//     else
//     {
//         cout << "Enter your item: ";
//         cin >> item;
//         cout << "#Position: " << top << ", Pushed value: " << item << "\n";
//         Stack[top] = item;
//         top = top + 1;
//     }
// }

// void POP()
// {
//     if (top == 0)
//         cout << "Stack is empty!!underflow\n";
//     else
//     {
//         top = top - 1;
//         cout << "#Position: " << top << ", Poped value: " << Stack[top] << "\n";
//     }
// }

// int Display()
// {
//     if (top == 0)
//         cout << "Stack is empty\n";
//     else
//     {
//         cout << "Size of Stack is: " << top << "\n";
//         for (int i = top - 1; i >= 0; i--)
//             cout << "#Position: " << i << ", value: " << Stack[i] << "\n";
//     }
//     return 0;
// }

// int main()
// {

//     int choice;

//     do
//     {
//         cout << "Choice 1 for push\n";
//         cout << "Choice 2 for pop\n";
//         cout << "Choice 3 for display\n";
//         cout << "Choice 4 for exit\n";
//         cin >> choice;
//         switch (choice)
//         {
//         case 1:
//             PUSH();
//             break;
//         case 2:
//             POP();
//             break;
//         case 3:
//             Display();
//             break;
//         case 4:
//             cout << "Exit\n";
//             break;
//         default:
//             cout << "Wrong choice\n";
//         }
//     } while (choice != 4);

//     return 0;
// }

#include <iostream>
using namespace std;
#define size 5
int stack[size], position = 0, choice, item, i;
void doTask();
void printOptions();
void push();
void pop();
void display();
void doTask()
{
    cout << endl
         << "enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        break;
    default:
        cout << "Envalid input";
    }
}
void printOptions() { cout << "Enter 1 to push. 2 to pop. 3 to preview. 4 to exit"; }
void push()
{
    if (position == size)
    {
        cout << "stack is full";
        return;
    }
    cout << "Enter your item : ";
    cin >> item;
    stack[position] = item;
    position++;
}
void pop()
{
    if (position == 0)
    {
        cout << "stack is empty";
        return;
    }
    position--;
}
void display()
{
    if (position == 0)
    {
        cout << "stack is empty";
        return;
    }
    cout << endl;
    for (i = position - 1; i >= 0; i--)
    {
        cout << stack[i] << ", ";
    }
}

int main()
{
    do
    {
        printOptions();
        doTask();
    } while (choice != 4);
    return 0;
}