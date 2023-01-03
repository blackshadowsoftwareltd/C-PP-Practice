// #include <iostream>
// using namespace std;

// int queue[5], size = 5, front = -1, rear = -1, item, choice;
// void enQueue();
// void deQueue();
// void display();
// void printOptions();
// void doTask();
// void enQueue()
// {
//     if (rear == size - 1)
//         cout << "\nQ is Full !! OVERFLOW";
//     else
//     {
//         if (front == -1)
//             front = 0;
//         rear++;
//         cout << "Enter the item : ";
//         cin >> item;
//         queue[rear] = item;
//     }
// }
// void deQueue()
// {
//     if (front == -1 || front > rear)
//         cout << "Queue is empty !! UNDERFLOW";
//     else
//     {
//         cout << "\n"
//              << queue[front] << " element is deleted";
//         front++;
//     }
// }
// void display()
// {
//     if (front == -1 || front > rear)
//         cout << "The Q is empty !! UNDERFLOW";
//     else
//     {
//         cout << "\nThe elements of Q is: \n";
//         for (int i = front; i <= rear; i++)
//         {
//             cout << queue[i] << " ";
//         }
//     }
// }
// void printOptions()
// {
//     cout
//         << "\n\nPress 1 for enQueue" << endl
//         << "Press 2 for deQueue" << endl
//         << "Press 3 for Display" << endl
//         << "Press 4 for EXIT" << endl
//         << "Enter your choice : ";
// }
// void doTask()
// {
//     cin >> choice;
//     switch (choice)
//     {
//     case 1:
//         enQueue();
//         break;
//     case 2:
//         deQueue();
//         break;
//     case 3:
//         display();
//         break;
//     case 4:
//         cout << "EXIT";
//         break;
//     default:
//         cout << "Envalid Input Inserted";
//     }
// }
// int main()
// {
//     do
//     {
//         printOptions();
//         doTask();

//     } while (choice != 4);
//     return 0;
// }

#include <iostream>
using namespace std;
#define size 5
int first = -1, last = -1, item, choice;
int queue[size];
void doTask();
void printOptions();
void enqueu();
void dequeue();
void display();
int main()
{
    do
    {
        printOptions();
        doTask();
    } while (choice != 4);
    return 0;
}
void doTask()
{
    cin >> choice;
    switch (choice)
    {
    case 1:
        enqueu();
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    case 4:
        break;
    default:
        break;
    }
}
void printOptions()
{
    cout << "\n\nPress 1 for enQueue" << endl
         << "Press 2 for deQueue" << endl
         << "Press 3 for Display" << endl
         << "Press 4 for EXIT" << endl
         << "Enter your choice : ";
}
void enqueu()
{
    if (last == size - 1)
    {
        cout << "The queue is Overflow";
    }
    else
    {
        if (first == -1)
        {
            first = 0;
        }
        cout << "Enter the item : ";
        cin >> item;
        last++;
        queue[last] = item;
    }
}
void dequeue()
{
    if (first == -1 || first > last)
    {
        cout << "the queue is empty or underflow";
    }
    else
    {
        first++;
    }
}
void display()
{
    if (first == -1 || first > last)
    {
        cout << endl
             << "the queue is empty or underflow";
    }
    else
    {
        cout << endl
             << "the elements of queue is : ";
        for (int i = first; i <= last; i++)
        {
            cout << queue[i] << ", ";
        }
    }
}