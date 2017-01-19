#include <iostream>

using namespace std;

class dll{
private:
   class Node{
   public:
      int data;
      Node* next;
      Node* prev;
      Node(int v, Node* n, Node* p) : data(v), next(n), prev(p){}
   };

   Node* head;
public:
   dll(){
     head = nullptr;
     // head->next = nullptr;
     // head->prev = nullptr;
   }
   void addStart(int v);
   void addEnd(int v);
   int  removeStart();
   int  removeEnd();
   void printList();

   friend ostream& operator <<(ostream& s, const dll& list) {
      for (Node* p = list.head; p!=nullptr; p=p->next)
	       s << p->data << ",";
	    return s;
   }
};

void dll::addEnd(int v){
   if(head == nullptr){
      head = new Node(v,nullptr,nullptr);
   }
   
   else{
      Node* p;
      for( p = head; p->next != nullptr ; p=p->next){}
      
      p->next = new Node(v,nullptr,p);
      cout << "Added value :  " << v << endl;
   }
}

void dll::addStart(int v){
      head = new Node(v,head,nullptr);
}

int dll::removeStart(){
   if (head == nullptr){
      cout << "List is empty" << endl;
   }
   else{
      int temp = head->data;
      head = head->next;
      return temp;

   }
}

int dll::removeEnd(){
   if ( head == nullptr){
      cout << " List is empty " << endl;
   }
   else{
      Node* p;
      for ( p = head; p->next->next != nullptr ; p=p->next){}
      
      int temp = p->next->data;
      p->next = nullptr;
      p->prev = p;
      return temp; 
   }
}

void dll::printList(){
  if ( head == nullptr){
	   cout << "List is empty" << endl;
  }
  
  Node* p;
  for ( p = head; p->next != nullptr; p=p->next){
     cout << "Data :" << p->data << endl;
  	 cout << "next :" << p->next->data << endl;
	   if ( p->prev != nullptr){
   	   cout << "prev :" << p->prev->data << endl;
 	   }
  }


}

int main(){
   
   dll a;
   for (int i = 0; i < 10; i++)
                a.addEnd(i);

   a.addStart(30);
   a.addStart(3);
   cout << a << '\n';
   cout << "removed : " << a.removeStart() << endl;
   cout << a << '\n';
   cout << "Printing now" << endl;
   cout << a << '\n';
   cout<<"my way"<<endl;
   a.printList();

   a.removeEnd();
   cout << "Printing now" << endl;
   cout << a << '\n';

   a.printList();


}

