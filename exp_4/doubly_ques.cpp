#include <iostream>
using namespace std;
class Node_d{
    public:
        int data;
        Node_d* next = NULL;
        Node_d* prev = NULL;
        Node_d(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }
};
class Node_c{
    public:
        int data;
        Node_c* next = NULL;
        Node_c(int val){
            data = val;
            next = NULL;
        }
};
class Circular{
    public:
        Node_c* head = NULL;
        void insert_at_begining(int val){
            Node_c* n = new Node_c(val);
            
            Node_c* temp = head;
            while(temp->next!=head){
                temp = temp->next;
            }
            if(head == NULL){
                head = n;
                head->next = head;
                return;
            }
            n->next = head;
            head = n;
            temp->next = head;
        }
        void insert_at_end(int val){
            Node_c* n = new Node_c(val);
            Node_c* temp = head;
            while(temp->next!=head){
                temp = temp->next;
            }
            temp->next = n;
            n->next = head;
        }
        void print_c_list(){
            Node_c* temp = head->next;
            cout<<head->data<<endl;
            while(temp->next!=head){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
};

class Linked{
    public:
        Node_d* head = NULL;
        Node_d* tail = NULL;
        void insert_at_end(int val){
            Node_d* n = new Node_d(val);
            if(head == NULL){
                tail = n;
                head = n;
                return;
            }
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        void insert_at_begining(int val){
            Node_d* n = new Node_d(val);
            if(head == NULL){
                head = n;
                tail = n;
                return;
            }
            head->prev = n;
            n->next = head;
            head = n;
        }
        void delete_at_begining(){
            Node_d* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
        void delete_at_end(){
            Node_d* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
        void print_d_list(){
            Node_d* temp = head;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
};
int main(){
    Circular first;
    first.insert_at_begining(5);
    first.insert_at_end(10);
    first.insert_at_end(15);
    first.insert_at_end(20);
    first.insert_at_begining(0);
    first.print_c_list();
    
}
