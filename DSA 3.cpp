#include <iostream>
using namespace std;
class Queue
 {
 int *q, front, rear;
 int count;
 int size;
 public:
 Queue(int size);
 bool isFull();
 bool isEmpty();
 void enQueue(int item);
 int deQueue();
 int top();
 void display();
 void demo();
 int menu();
 };
Queue::Queue(int size)
 {
 front = 0;
 rear = -1;
 count =0;
 this->size= size;
 q= new int[size];
 }
// Check if the queue is full
bool Queue::isFull()
 {
 if (count == size)
 return true;
 else
 return false;
 }
 // Check if the queue is empty
bool Queue::isEmpty()
 {
 if (count == 0)
 return true;
 else
 return false;
 }
 // Adding an item
void Queue::enQueue(int item)
 {
 if (isFull())
 {
 cout << "Queue is full";
 cout<<"\n Terminating the program";
 exit(-1);
 }
 rear = (rear + 1) % size;
 q[rear] = item;
 count++;
 }
// Removing an item
int Queue::deQueue()
 {
 int item;
 if (isEmpty())
 {
 cout << "Queue is full";
 cout<<"\n Terminating the program";
 exit(-1);
 }
 item = q[front];
 front= (front+1)%size;
 count--;
 return item;
 }
// Removing an item
int Queue::top()
 {
 int item;
 if (isEmpty())
 {
 cout << "Queue is full";
 cout<<"\n Terminating the program";
 exit(-1);
 }
 item = q[front];
 return item;
 }
void Queue::display()
 {
 // Function to display status of Circular Queue
 int c,f;
 if (isEmpty())
 {
 cout << endl<< "Empty Queue" << endl;
 }
 else
 {
 cout << "Front -> ";
 for (c=count,f=front; c > 0; f = (f + 1) % size,c--)
 cout << q[f]<<"->";
 cout << "Rear " ;
 }
 }
void Queue::demo()
 {
 int item;
 while(1)
 {
 switch(menu())
 {
 case 1:
 cout<<"\n Enter item to add in queue";
 cin>>item;
 enQueue(item);
 break;
 case 2:
 item=deQueue();
 cout<<"\n Item deleted="<<item;
 break;
 case 3:
 item=top();
 cout<<"\n Item at front="<<item;
 break;
 case 4:
 cout<<"\n Queue is \n";
 display();
 break;
 case 5:
 exit(0);
 }
 }
 }
int Queue::menu()
 {
 int ch;
 cout<<"\n Enter "
 "\n1: for add item in queue"
 "\n2: for delete item from queue"
 "\n3: for read item from queue"
 "\n4: for display queue"
 "\n5: for terminate the program"
 "\n Enter your choice...";
 cin>>ch;
 return ch;
 }
int main()
 {
 Queue q(10);
 q.demo();
 return 0;
 }