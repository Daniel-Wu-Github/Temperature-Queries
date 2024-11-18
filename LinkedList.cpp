# include <iostream>
# include <string>
# include "LinkedList.h"
# include "Node.h"

using std::string, std::ostream;

LinkedList::LinkedList() /* TODO */:head(nullptr), tail(nullptr){
	// TODO: implement this function
}

LinkedList::~LinkedList() {
	// TODO: implement this function
	clear();
}

LinkedList::LinkedList(const LinkedList& source) /* TODO */:head(nullptr), tail(nullptr) {
	// TODO: implement this function
	if (source.head == nullptr) {
        return;
    }
	if(this == &source){
		return;
	}
	head->data = source.head->data;
	head->next = nullptr;

	Node* curr = source.head->next;
    Node* prev = head;

    while(curr != nullptr){
        Node* nextNode = new Node;
        nextNode->data = curr->data;
        nextNode->next = nullptr;

        prev->next = nextNode;
        prev = nextNode;

        if(curr == source.tail){
            tail = nextNode;
        }

        curr = curr->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// TODO: implement this function
	if (source.head == nullptr) {
        return *this;
    }
	if(this == &source){
		return *this;
	}
	clear();

	head->data = source.head->data;
	head->next = nullptr;
	Node* curr = head->next;
	Node* prev = head;

	while(curr!=nullptr){
		Node* nextNode = new Node;
		nextNode->data = curr->data;
		nextNode->next = nullptr;

		prev->next = nextNode;
		prev = nextNode;

		if(curr == source.tail){
			tail = nextNode;
		}

		curr = curr->next;
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// TODO: implement this function
	Node* newNode = new Node;
	newNode->data.id = location;
	newNode->data.year = year;
	newNode->data.month = month;
	newNode->data.temperature = temperature;
	newNode->next = nullptr;

	if(head == nullptr || newNode->data < head->data){
        newNode->next = head;
        head = newNode;
        if(tail == nullptr) {
            tail = newNode;
        }
        return;
    }

	Node* curr = head->next;
	Node* prev = head;
	bool isAtEnd = true;

	while(curr!=nullptr){
		if(newNode->data<curr->data){
			newNode->next = curr;
			prev->next = newNode;
			isAtEnd = false;
			break;
		}
		curr = curr->next;
		prev = prev->next;
	}

	if(isAtEnd){
		tail->next = newNode;
		tail = newNode;
	}
}

void LinkedList::clear() {
	// TODO: implement this function
	Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
	}
	head = nullptr;
	tail = nullptr;
}

Node* LinkedList::getHead() const {
	// TODO: implement this function, it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	string outputString;
	// TODO: implement this function
	Node* curr = head;
	while (curr != nullptr) {
		outputString += curr->data.id + " " + std::to_string(curr->data.year) + " " + std::to_string(curr->data.month) + " " + std::to_string(curr->data.temperature) + "\n";
		curr = curr->next;
	}

	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}