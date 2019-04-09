#include<iostream>
#include<cstring>

using namespace std;

struct Movie {
	int id;
	char *title;
	int year;
	Movie* next;
};
Movie *head = NULL;

void add_Movie(int, char*, int);
void remove_Movie(int);
void print();

int main(){

/*	cout << "Trying to delete from empty list " << endl;
	remove_Movie(1);*/

	cout << "Adding some movies " << endl;
	add_Movie(1, "loda1", 100);
	add_Movie(4, "loda4", 400);
	add_Movie(2, "loda2", 200);
	add_Movie(5, "loda5", 500);
	add_Movie(6, "loda6", 600);
	add_Movie(3, "loda3", 300);


	// print();

	cout << "Removing a movie from the beginning of the list" << endl;
	// remove_Movie(1);

	// print();

	cout << "Removing a movie from the end of the list " << endl;

	remove_Movie(6);
	print();

	cout << "Removing a movie from the middle of the list" << endl;

	remove_Movie(4);
	print();



	return 0;
}

void add_Movie(int id, char* title, int year){

	//Check if addition is possible 

	Movie * iterate = head;
	while(iterate != NULL){
		if(iterate->id == id){
			cout << "Cant have another movie with the same id " << endl;
			return;
		}
		iterate = iterate->next;
	}

	//Delete iterate bc its not required anymore
	delete iterate;

	Movie * temp = new Movie;
	temp -> id = id;
	temp -> year = year;
	temp -> title = new char[sizeof(title) +1];
	strcpy(temp->title, title);
	temp -> next = NULL;

	Movie * current = new Movie;
	if(head == NULL || head->year >= temp->year){

		temp->next = head;
		head = temp;
	}
	else{
		current = head;
		while(current->next != NULL && current->next->year < temp->year) current = current->next;
		temp->next = current->next;
		current->next = temp;

	}

	
}

void remove_Movie(int id){

	Movie * current = new Movie;
	current = head;
	Movie * previous = new Movie;
	previous->next = current;
	// empty list
	if(head == NULL){
		cout << "List is empty" << endl;
		return;
	}
		//only one element present in the list
	else if(current->next == NULL){
		delete current->title;
		delete current;
		head = NULL;
		return;
	}
	else{
		while(current != NULL){

		// element is found in the middle of the list
			if(current->id == id && current->next != NULL){

				if(current == head){
					head = current->next;
					delete current->title;
					delete current;
					return;
				}
				else{
					previous->next = current->next;
					delete current->title;
					delete current;
					return;
				}
			}

		//element is found as the last element of the list 
			if(current->id == id && current->next == NULL){
				previous->next = NULL;
				delete current->title;
				delete current;
				return;
			}
		//element is not found at all
			else cout << "Movie not found" << endl;

			previous = current;
			current = current->next;
		}

	}

}


void print(){

	Movie * current = new Movie;
	current = head;
	if (head == NULL)
		cout << " List is empty " << endl;
	else{
		while(current != NULL){
			cout << "ID: " << current->id << endl;
			cout << "Title: " << current->title << endl;
			cout << "Year: " << current->year << endl;
			current = current->next;
		}
	}
}