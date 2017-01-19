#include <iostream> 

using namespace std;

class LL{
   class Node {
   public:
      int data;
      Node* next;
      Node(int v, Node* n) : data(v), next(n) {}
   };
   Node* head;

public:
   LL(){
      head = nullptr;
   }
   
   void addStart(int v){
      head =  new Node(v,head); // the left is executed first and the new head is created with data as v and points to the previous head
   }
   void addEnd(int v){
      if ( head == nullptr)
	 head = new Node(v,nullptr);
   
      Node* p;
      for ( p=head; p->next != nullptr ; p=p->next){
      }
   
      p = new Node(v,nullptr);
   }

   int removeStart(){
      if ( head == nullptr)
	cout << "List is empty" << endl;
      
      int temp = head->data;
      head = head->next;
      return temp;	   
   }

   int removeEnd(){
      if( head == nullptr)
	    cout << "List is empty" << endl;
      
      Node* p;
      for(p=head; p->next->next != nullptr; p=p->next)
      {}
      int temp = p->next->data;
      p->next = nullptr;
      return temp;
   }
};


int main()
{
	LL x;
        for (int i = 0; i < 10; i++)
                x.addEnd(i);
        for (int i = 0; i < 10; i++)
                x.addStart(i);



}


















    
      



