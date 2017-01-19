#include <iostream>
#include <vector>

using namespace std;
class LL{
	class node {
	public:
		int val;
		node* next;
		node(int v, node* n) : val(v), next(n) {};
	};
	node* head;
public:
	LL(){
		head = nullptr;
	}
	void add(int v){
		if (head == nullptr){
			head = new node(v,nullptr);
		}
		else{
			node* p;
			for(p=head; p->next!=nullptr; p=p->next){}
			p->next = new node(v,nullptr);
		}
	}
	void print(){
		node* ptr;
		for(ptr=head; ptr!= nullptr; ptr = ptr->next){
			cout << ptr->val << endl;
		}
		
	}
	node* gethead(){
		return head;
	}
	void sort(){
		//node* ptr;
		//node* temp;
		for (node *index = head; index->next != nullptr; index = index->next) {
			for (node *selection = index->next; selection != nullptr; selection = selection->next) {
				if (index->val > selection->val) {
					swap(index->val, selection->val);
				}
			}
		}
		/*for(ptr=head ; ptr->next!=nullptr ; ptr=ptr->next){
			if (ptr->val > ptr->next->val ){
				ptr = temp;
				ptr = ptr->next;
				ptr->next = temp;
			}
		}*/
	}
		

};

int main(){
	
	LL a;
	LL b;
	a.add(2);
	a.add(4);
	a.add(3);
	a.print();
	a.sort();
	cout << "after sorting" << endl;
	a.print();
	
	b.add(5);
	b.add(6);
	b.add(4);
	b.print();
	b.sort();
	cout << "after sorting" << endl;
	b.print();
	
}