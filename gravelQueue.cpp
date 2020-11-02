#include <iostream>
#include <string>

using namespace std;


 struct purchase_node {
     string ClientName, QualityOfGravel;
     int QtyOfGravel;
    struct purchase_node *pNext;
    purchase_node(string name, int quantity, string quality) {
        ClientName = name;
        QualityOfGravel = quality;
        QtyOfGravel = quantity;
     }

};

 struct Queue {
     purchase_node * front, * rear;
     Queue() {
         front = rear = NULL;
     }

     void enQueue(string name, int quantity, string quality) {
         purchase_node * temp_node = new purchase_node(name, quantity, quality);

         if (rear == NULL) {
             front = rear = temp_node;
         }
         else {
             rear->pNext = temp_node;
             rear = temp_node;
         }
     }

     void deQueue() {

         if (front == NULL)
             return;

         purchase_node * temp = front;
         front = front->pNext;
         
         if (front == NULL) {
             rear = NULL;
         }

         delete(temp);
     }

 };

int main() {
    
    int option = 0;
    Queue q;

   begin:
        cout << "Welcome to gravel buyer platform, we just love gravel.." << endl;
        cout << "* If you want to register a new buyer in a queue press 1 *" << endl;
        cout << "* If you want to print all customer data by specifying quality of gravel press 2 *" << endl;
        cout << "* PRESS 3 to EXIT *" << endl;
        cout << "Your option: ";
        cin >> option;
    

    

    if (option == 1) {
        string name, quality, str;
        int quantity=0;
        
        getline(cin, str);

        cout << "Enter customer name: ";
        getline(cin, name);
        cout << "Enter quantity of gravel in cubic meters: ";
        cin >> quantity;
        getline(cin, str);
        cout << "Enter quality of gravel (poor, good, luxury): ";
        getline(cin, quality);

        q.enQueue(name, quantity, quality);

        cout << "You have successfully added customer " << name << " buying " << quantity << " cubic meters of " << quality << " gravel!" << endl;
    }
    /*
    else if (option == 2) {
        string option;
        cout << "Specify which quality gravel customers to print: ";
        getline(cin, option);
    }
    */
    else if (option == 3) {
        return(0);
    }

    goto begin;

    /*
    q.enQueue("Joe", 25, "Fine");
    q.enQueue("Mangela", 25, "Fine");
    q.deQueue();
    q.enQueue("Last", 22, "Good");

    cout << "FRONT: " << (q.front)->ClientName << endl;
    cout << "REAR: " << (q.rear)->ClientName;
  
  */


}
