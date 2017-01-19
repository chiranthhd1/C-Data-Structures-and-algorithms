#include <iostream>
#include <vector>

using namespace std;
class node {
	public:
		int val;
		node* next;
		node(int v, node* n) : val(v), next(n) {};
	};
class LL{
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
	int getSize(){
		node* ptr;
		int count;
		for(ptr=head; ptr!= nullptr; ptr = ptr->next){
			count++;
		}
		return count;
		
	}
	void sort(){
		node* index;
		node* selection;
		
		for (index = head; index->next != nullptr; index = index->next) {
			for (selection = index->next; selection != nullptr; selection = selection->next) {
				if (index->val > selection->val) {
					swap(index->val, selection->val);
				}
			}
		}
	}
		

};

class Solution1{
	node* addtwonumbers(LL* l1, LL* l2){
		l1.sort();
		l2.sort();
		
		node* ptr;
		for()
	}
	
	
	
	
};
int main(){
	
	LL a;
	LL b;
	a.add(2);
	a.add(4);
	a.add(3);
	a.print();
//	a.sort();
	cout << "after sorting" << endl;
	a.print();
	
	b.add(5);
	b.add(6);
	b.add(4);
	b.print();
//	b.sort();
	cout << "after sorting" << endl;
	b.print();
	
}