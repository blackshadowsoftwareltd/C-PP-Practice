#include <iostream>
  using namespace std;
  int size = 5;
int queue[5], front = -1, rear = -1, item, choice;
  void enQueue();
void deQueue();
void display();
void printOptions();
void doTask();
  void enQueue()
{
    if (rear == size - 1)
          cout << "\nQ is Full !! OVERFLOW";
      else
    {
        if (front == -1)
            front = 0;
        rear++;
        cout << "Enter the item : ";
        cin >> item;
        queue[rear] = item;
    }
}
void deQueue()
{
    if (front == -1 || front > rear)
        cout << "Queue is empty !! UNDERFLOW";
    else
    {
        cout << "\n"
             << queue[front] << " element is deleted";
        front++;
    }
}
void display()
{
    if (front == -1 || front > rear)
        cout << "The Q is empty !! UNDERFLOW";
    else
    {
        cout << "\nThe elements of Q is: \n";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
}
void printOptions()
{
    cout
        << "\n\nPress 1 for enQueue" << endl
        << "Press 2 for deQueue" << endl
        << "Press 3 for Display" << endl
        << "Press 4 for EXIT" << endl
        << "Enter your choice : ";
}
void doTask()
{
    cin >> choice;
    switch (choice)
    {
    case 1:
        enQueue();
        break;
    case 2:
        deQueue();
        break;
    case 3:
        display();
        break;
    case 4:
        cout << "EXIT";
        break;
    default:
        cout << "Envalid Input Inserted";
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