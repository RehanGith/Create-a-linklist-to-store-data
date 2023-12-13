// linklist.cpp
// linked list
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct link //one element of list
{
	int data; //data item
	link* next; //pointer to next link
};
////////////////////////////////////////////////////////////////
class linklist //a list of links
{
private:
	link* first; //pointer to first link
public:
	linklist() //no-argument constructor
	{
		first = NULL;
	} //no first link
	linklist(const linklist& ll);
	linklist& operator =(const linklist& ll);
	void additem(int d); //add data item (one link)
	void display(); //display all links
	~linklist();
};
//--------------------------------------------------------------
linklist::linklist(const linklist& ll) {
	link* current = ll.first;
	first = NULL;
	while (current) {
		link* newlink = new link; //make a new link
		newlink->data = current->data; //give it data
		newlink->next = first; //it points to next link
		first = newlink; //now first points to this
		current = current->next;
	}
}
linklist& linklist::operator=(const linklist& ll) {
	link* current = ll.first;
	first = NULL;
	while (current) {
		link* newlink = new link; //make a new link
		newlink->data = current->data; //give it data
		newlink->next = first; //it points to next link
		first = newlink; //now first points to this
		current = current->next;
	}
	return *this;
}
void linklist::additem(int d) //add data item
{
	link* newlink = new link; //make a new link
	newlink->data = d; //give it data
	newlink->next = first; //it points to next link
	first = newlink; //now first points to this
}
//--------------------------------------------------------------
void linklist::display() //display all links
{
	link* current = first; //set ptr to first link
	while (current != NULL) //quit on last link
	{
		cout << current->data << endl; //print data
		current = current->next; //move to next link
	}
}
////////////////////////////////////////////////////////////////
linklist::~linklist() {
	cout << "Destructor calls" << endl;
	while (first) {
		link* next = first->next;
		cout << "Destructor is called for: " << first->data << endl;
		delete first;
		first = next;
	}
}
int main()
{
	linklist li; //make linked list
	li.additem(25); //add four items to list
	li.additem(36);
	li.additem(49);
	li.additem(64);
	linklist l2;
	//display entire list
	l2 = li;
	return 0;
}