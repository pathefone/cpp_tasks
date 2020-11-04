#include <iostream>
#include <string>

using namespace std;


 struct citizen {
     string CitizenName, CitizenLastName;
     int CitizenAge, ConsultationTime;
    struct citizen *pNext;
    citizen(string name, int age, string lastName, int time) {
        CitizenName = name;
        CitizenLastName = lastName;
        CitizenAge = age;
        ConsultationTime = time;
     }

};

 struct Queue {
     citizen * front, * rear;
     Queue() {
         front = rear = NULL;
     }

     void enQueue(string name, int age, string lastName, int time) {
         citizen * temp_node = new citizen(name, age, lastName, time);

         if (rear == NULL) {
             front = rear = temp_node;
         }
         else {
             rear->pNext = temp_node;
             rear = temp_node;
         }
     }

     void deQueue() {

         if (rear == NULL) { //check if list is empty
             cout << "The list is empty!";
             return;
         }

         citizen * temp = front;

         if(temp->pNext!=NULL){ //avoid accessing unallocated memory
         front = front->pNext;
         }
         
         if (front == rear) { //if only one node set all pointers to NULL
             front = rear = temp = NULL;
         }

         delete(temp);
         
     }
    
     void printConsultationList() {
         citizen * temp = front;
         int consultationCount=0,consultationTime=0;
        
        if(rear == NULL){ //checking if list is empty
            cout << "The list is empty!"<< endl;
            return;
        }

        if(temp!=rear) { //if more than one element, add last element time/count instantly
            consultationCount= consultationCount + 1;
            consultationTime = rear->ConsultationTime + consultationTime;
        }
   
         do{ //count all elements except last one
            consultationCount= consultationCount + 1;
            consultationTime = temp->ConsultationTime + consultationTime;
            if(temp->pNext != NULL) //check if next element is the last
            temp = temp->pNext;
            
         }
         while (temp->pNext != NULL);

         cout << "Total consultations count: " << consultationCount << endl;
         cout << "Total consultation time: " << consultationTime << endl;
     }

     void cancel_all() {
         citizen * temp = front;

         if(temp==NULL) { //checking if list is empty
             cout << "List is empty!" << endl;
             return;
         }
         if(front==rear) { //checking if only node exists
             deQueue();
             return;
         }
         do {
             temp = temp->pNext;
             deQueue();             
         }while (temp->pNext!=NULL); //deleting all nodes except the last one
         
         if(rear!=NULL) { //deleting last node
             deQueue();
         }
     }

     void remove_shorter_than(int duration) {
         
     }

 };

int main() {
    
    int option = 0;
    Queue q;

   begin:
        cout << "Welcome to the consultation registering platform.." << endl;
        cout << "* If you want to register a new consultation press 1 *" << endl;
        cout << "* If you want to print all consultations press 2 *" << endl;
        cout << "* Cancel all consultations press 3 * "<< endl;
        cout << "* Immediately provide consultation for citizens of specified age press 4 *"<< endl;
        cout << "* To cancel all shorter than specified duration consultations press 5 *"<< endl;
        cout << "* PRESS 6 to EXIT *" << endl;
        cout << "Your option: ";
        cin >> option;
    

    if (option == 1) {
        string name, lastName, str;
        int age=0, time=0;
        
        getline(cin, str);

        cout << "Enter citizen name: ";
        getline(cin, name);
        cout << "Enter age of citizen: ";
        cin >> age;
        getline(cin, str);
        cout << "Enter last name of citizen: ";
        getline(cin, lastName);
        cout << "Enter consultation duration: ";
        cin >> time;

        q.enQueue(name, age, lastName, time);

        cout << "You have successfully added customer " << name << " " << lastName 
        << " age:  " << age << " consultation duration: " << time <<  endl;
    }
    
    else if (option == 2) {
        q.printConsultationList();
    }
    else if (option == 3) {
        q.cancel_all();
        cout << "We are sorry but all consultations have been canceled.." << endl;
    }
    else if (option == 5) {
        int duration;

        cout << "Enter minimal consultation duration: ";
        cin >> duration;


    }


    
    else if (option == 6) {
        return(0);
    }

    goto begin;

    


}
