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
        pNext = NULL;
     }

};

 struct Queue {
     citizen * front, * rear;
     Queue() {
         front = rear = NULL;
     }

     void enQueue(string name, int age, string lastName, int time) {
         citizen * temp_node = new citizen(name, age, lastName, time);
        citizen * temp_p = front;
        

         if (rear == NULL) {
             front = rear = temp_node;
         }
         else if (rear==front) { // sorting if only one element exists
             int precent = 100-(time*100/(temp_p->ConsultationTime));
            if(precent>=50) {
                cout << "Name of person which passed his position: " << front->CitizenName;
                temp_node->pNext = rear;
                front = temp_node;
            }
            else {
                rear->pNext = temp_node;
                rear = temp_node;  
            }
         }
         else if(rear!=front) { //sorting if multiple elements exist
             citizen * prev_p = temp_p;
             while(temp_p->pNext!=NULL) {
                    int precent = 100-(time*100/(temp_p->ConsultationTime));
                    if(precent>=50) {
                        if(temp_p==prev_p) { //checking if first node from front is 50% higher 
                            cout << "Name of person which passed his position: " << temp_p->CitizenName << endl;
                            temp_node->pNext = temp_p;
                            front = temp_node;
                        }
                        else{   //checking other elements, and inserting 
                            cout << "Name of person which passed his position: " << temp_p->CitizenName << endl;
                            temp_node = prev_p->pNext;
                            prev_p->pNext = temp_node;
                        }
                    }
                    prev_p = temp_p;
                    temp_p = temp_p->pNext;
             }
             if(temp_p->pNext==NULL) { //checking precentage difference for last element
                    int precent = 100-(time*100/(temp_p->ConsultationTime));
                    if(precent>=50) {
                        cout << "Name of person which passed his position: " << temp_p->CitizenName << endl;
                        prev_p->pNext = temp_node;
                        temp_node->pNext = rear;
                    }
                    else { //if no element duration 50% higher, add to rear
                    rear->pNext = temp_node;
                    rear = temp_node;
                    rear->pNext = NULL;
             }
          }
             
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
         else if (front == rear) { //if only one node set all pointers to NULL
             front = rear = temp = NULL;
         }

         delete(temp);
         
     }

     void equal(int age) {
         citizen * temp = front;
         citizen * prev = temp;
  

         while(temp->pNext!=NULL) {
             cout << "ONE";
             if(temp->ConsultationTime==age) {
                 if(temp==front) { // if node is in front, just use dequeue function
                    temp = front->pNext;
                    prev = temp;
                     deQueue();
                     
                 }
                else if(temp==rear && rear!=front) { //if last element change rear pointer to previous node
                    rear = prev;
                    rear->pNext = NULL;
                    delete(temp);
                    return;
                }
                else {                        //deleting node not from front or rear
                    prev->pNext = temp->pNext;
                    temp->pNext = NULL;
                    delete(temp);
                }
             }

             if(temp->pNext!=NULL){ //if node is not last change previous to temp and current temp to next node
                 prev = temp;
                 temp = temp->pNext;
             }
         }
        
         if(temp->pNext==NULL && rear==NULL) { //if last element has the key(age) delete it
            if(temp->ConsultationTime<age) {
                if(front!=rear) {
                    rear = prev;
                    rear->pNext == NULL;
                }
                else{
                rear = front = NULL;
                }
                delete(temp);
            }
         }

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
         
         if(rear!=NULL) { //deleting last node, optional if
             deQueue();
         }
     }

     void remove_shorter_than(int duration) {
         citizen * temp = front;
         citizen * prev = temp;
   //     cout << "FRONT NUM: " << front->ConsultationTime;
   //     cout << "TEMP NUMBER: " << temp->ConsultationTime;

         while(temp->pNext!=NULL) {
             cout << "ONE";
             if(temp->ConsultationTime<duration) {
                 if(temp==front) { // if node is in front, just use dequeue function
                    temp = front->pNext;
                    prev = temp;
                //    cout << "TEMP NUM: " << temp->ConsultationTime;
                     deQueue();
                     
                 }
                else if(temp==rear && rear!=front) { //if last element change rear pointer to previous node
                    rear = prev;
                    rear->pNext = NULL;
                    delete(temp);
                    return;
                }
                else {                        //deleting node not from front or rear
                    prev->pNext = temp->pNext;
                    temp->pNext = NULL;
                    delete(temp);
                }
             }

             if(temp->pNext!=NULL){ //if node is not last change previous to temp and current temp to next node
                 prev = temp;
                 temp = temp->pNext;
             }
         }
        
         if(temp->pNext==NULL && rear!=NULL) { //if last element has the key(duration) delete it
            if(temp->ConsultationTime<duration) {
                if(front!=rear) {
                    rear = prev;
                    rear->pNext == NULL;
                }
                else{
                rear = front = NULL;
                }
                delete(temp);
            }
         }

     }

     bool isEmpty() {
         if(rear == NULL) {
            return true; 
        }
        else {
            return false;
        }
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
        if(q.front!=NULL) {
        cout << "We are sorry but all consultations have been canceled.." << endl;
        }
        else{
            cout<< "The list is empty!"<< endl;
        }
    }
    else if (option == 4) {
        int age;
        if(q.isEmpty()) {
            cout << "The list is empty!" << endl;   
        }
        else {
        cout << "Specify age of citizens to provide consultations immediately: ";
        cin >> age;
        q.equal(age);
        }
    }
    else if (option == 5) {
        int duration;

        if(q.rear == NULL) {
            cout << "The list is empty!" << endl;   
        }
        else {
        cout << "Enter minimal consultation duration: ";
        cin >> duration;
        q.remove_shorter_than(duration);
        }
    }   
    else if (option == 6) {
        return(0);
    }
    else {
        cout << "Choose between 1-6!!" << endl;
    }

    goto begin;
}
