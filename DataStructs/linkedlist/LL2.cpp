#include <iostream>
#include <ostream>


using namespace std;

class LL{
   private:
      class Node{
         public:
	    int data;
	    Node* next;
	    int size=0;
	    Node(int v, Node* n, int size) : data(v), next(n), size(size) {}
	    int getSize(){
	//	cout << "increasing the size" << endl;	
	//	 size++;
	       return size;
	    }
      };
      Node* head;

   public:
   
      LL(){
	     head = nullptr;
      }
     
      void addEnd(int v) {
         if (head == nullptr){
	    head = new Node(v, nullptr,size++);
	// setSize();
	 }

         Node* p;
	 for ( p=head; p->next != nullptr;p = p->next)
	 {}
	 p->next = new Node(v , nullptr);
         //size++;
      }

      void addStart (int v) {
         head = new Node (v,head);
	 //size++;
      }

      int removeEnd () {
         if ( head == nullptr )
	    cout << "List is empty" << endl;
         if ( head -> next == nullptr){
            int temp = head->data;
	    head = nullptr;
	    //size--;
	    return temp;
         }
         
	 Node*  p;
	 for ( p=head; p->next->next != nullptr; p = p->next)
	 {}
	 int temp = p->next->data;
	 p->next = nullptr;
	 //size--;
	 return temp;
     }

     int removeStart() {
        if ( head == nullptr )
            cout << "List is empty" << endl;
		
	int temp = head->data;
	head = head->next;
	//size--;
	return temp;
    }
   
    int size () {
	Node p;
        return p.getSize();
    }
/*
    int operator [](int i) const{
       Node* p;
*/

   friend ostream& operator <<(ostream& s, const LL& list) {
      for (Node* p = list.head; p!=nullptr; p=p->next)
	s << p->data << ",";
	return s;
   }
};

int main() {
        LL x;
        for (int i = 0; i < 10; i++)
                x.addEnd(i);
        for (int i = 0; i < 10; i++)
                x.addStart(i);
        cout << x << '\n';
	cout << endl;
	cout << "size" << x.size() << endl;
        //ofstream f("test.dat");
        //f << x;
}  


































