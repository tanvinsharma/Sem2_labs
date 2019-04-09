#include <iostream>
#include <cstring>

using namespace std;

class Movie{

	int id;
	char * title;
	int year;
	Movie * next;

public:
	Movie();
	Movie(int id, char * title, int year);
	~Movie();
	void print();
	int get_id();
	int get_year();
	char * get_title();
	Movie * get_next();
	void set_id(int id);
	void set_title(const char * title);
	void set_year(int year);
	void set_next(Movie * next); 
	friend class MovieList;
};

class MovieList{

	Movie * head;

public:
	MovieList();
	~MovieList();
	MovieList(const MovieList &x);
	void add_Movie(int id, char * title, int year);
	void remove_Movie(int id);
	void print();
	Movie *get_movie(int id) const;
	void delete_list();
	//addition in task 4
	Movie * get_head() const;
	MovieList & operator = (const MovieList &x);
};

MovieList &MovieList::operator=(const MovieList &x) {
	if(x.get_head() != this->get_head()){
		Movie *temp = x.get_head();
		while(temp != NULL){
			this -> add_Movie(temp->get_id(), temp->get_title(), temp->get_year());
			temp = temp -> next;
		}
		return *this;
	}
	else {
		cout <<"error"<<endl;
		return *this;
	}
}

Movie * MovieList :: get_head() const{

	return head;
}

MovieList :: MovieList(const MovieList &x){

	Movie *temp = x.get_head();

	while(temp != NULL){
		this -> add_Movie(temp->get_id(), temp->get_title(), temp->get_year());
		temp = temp -> next;
	}
}

void MovieList::delete_list() {
	this-> ~MovieList();
}

Movie *MovieList::get_movie(int id) const {
	Movie *temp = head;
	while(temp != NULL) {
		if(temp -> id == id) 
			return temp;
		temp = temp -> next;
	}
	printf("Movie not found\n");
	return NULL;
}

Movie :: Movie(){
 
}

Movie :: Movie(int id, char * title, int year){

	this -> id = id;
	this -> year = year;

	this ->title = new char[strlen(title) + 1];
	strcpy(this ->title, title);

	cout << "Adding " << endl;
	print();

}

Movie :: ~Movie(){

	// delete[] title;
}

void Movie :: print(){

	cout << "ID: " << id << endl;
	cout << "Title: ";
	puts(title);
	
	cout << "Year: " << year << endl;
}

char * Movie :: get_title(){

	return title ;
}

Movie * Movie :: get_next(){

	return next; 
}

int Movie :: get_id(){

	return id;
}

int Movie :: get_year(){

	return year; 
}

void Movie :: set_id(int id){

	this -> id = id;
	

}

void Movie :: set_year(int year){

	this -> year = year;


}

void Movie :: set_title(const char* title){

	strcpy(this  -> title ,title);


}

void Movie :: set_next(Movie *next){

	next = this -> next;

}

MovieList :: MovieList(){

	head = NULL; 
	cout << "Empty List is created " << endl;

}

MovieList :: ~MovieList(){

	Movie * current = head ;
	if(head == NULL)
		cout << "List is empty so nothing to delete " << endl;

	while (current != NULL){ 
		delete current -> get_title();
		delete current;
		current = current -> get_next();
	}
	head = NULL ;

}

void MovieList :: add_Movie(int id, char * title, int year){

	Movie *iterate = head;

  //make sure don't repeat an id
	while(iterate != NULL) {
		if(iterate -> get_id() == id) {
			cout << "Cant add another movie with the same id" << endl;   
			return;
		}
		iterate = iterate -> get_next();
	}
  //free memory of temp pointer if no repeats 
	delete iterate;

  //continue sorted insert by year
	Movie *temp = new Movie;
	temp -> id = id;
	temp -> year = year;
	temp -> title = new char[sizeof(title)+1];
	strcpy(temp -> title, title);
	temp -> next = NULL;   

	Movie *current = new Movie; 
	if (head == NULL || head -> get_year() >= temp -> get_year()) { 
		temp -> set_next(head) ; 
		head = temp; 
	} else { 
		current = head; 
		while (current -> next != NULL && current -> next -> year < temp -> year) current = current -> next; 
		temp -> next = current -> next; 
		current -> next = temp; 
	} 
}

void MovieList :: remove_Movie(int id){

	Movie *current = new Movie;
	current = head;
	Movie *prev = new Movie;
	if(head == NULL) {
		cout << "list is empty!" << endl;
		return;
	} 
	else if (current -> get_next() == NULL) {
		delete current -> get_title();
		delete current;
		head = NULL;
		return;
	}
	else if( current -> id == id && current -> next != NULL){
		head = current -> next;
		delete current -> title;
		delete current;
		return;
	}
	while(current -> id != id) {
		if(current -> next == NULL) {cout << "Movie not found" << endl;
		return;
	}
	else {
		prev = current;
		current = current -> next;
	}
} 
prev -> next = current -> next;
delete current -> title;
delete current;
}

void MovieList :: print(){
	Movie *current = new Movie;
	current = head;
	if(head == NULL) cout<<"list is empty!"<<endl;
	while(current != NULL) {
		cout << "ID: " << current -> get_id() << endl << " Title: " << current -> get_title() << endl << " Year: " << current -> get_year() << endl;
		current = current -> next; 
	}
}

int main(){
	//create at least two objects of MovieList
	MovieList a; 
	cout << "Adding movies" << endl;
	// MovieList *dynamic = new MovieList;
	a.add_Movie(1, "test", 1992);
	a.add_Movie(3, "test2", 1993);
	a.add_Movie(6, "test3", 1995);
	a.print();

	(a.get_movie(3)) -> print();
	
	a.remove_Movie(3);
	a.print();

	cout << "using copy constructor" << endl;
	//copy constructor
	MovieList b(a);
	b.print();
	cout << "Using assignment operator "<< endl;
	//assignment operator
	MovieList c;
	c = b;
	c.print();
	a=a;
	a.print();
	return 0;
}
// #include <iostream>
// #include <cstring>

// using namespace std;

// class Movie{

// 	int id;
// 	char * title;
// 	int year;
// 	Movie * next;

// public:
// 	Movie();
// 	Movie(int id, char * title, int year);
// 	~Movie();
// 	void print();
// 	int get_id();
// 	int get_year();
// 	char * get_title();
// 	Movie * get_next();
// 	void set_id(int id);
// 	void set_title(const char * title);
// 	void set_year(int year);
// 	void set_next(Movie * next); 
// 	friend class MovieList;
// };

// class MovieList{

// 	Movie * head;

// public:
// 	MovieList();
// 	~MovieList();
// 	MovieList(const MovieList &x);
// 	void add_Movie(int id, char * title, int year);
// 	void remove_Movie(int id);
// 	void print();
// 	Movie *get_movie(int id) const;
// 	void delete_list();
// 	//addition in task 4
// 	Movie * get_head() const;
// 	MovieList & operator = (const MovieList &x);
// };

// MovieList &MovieList::operator=(const MovieList &x) {
// 	if(x.get_head() != this->get_head()){
// 		Movie *temp = x.get_head();
// 		while(temp != NULL){
// 			this -> add_Movie(temp->get_id(), temp->get_title(), temp->get_year());
// 			temp = temp -> next;
// 		}
// 		return *this;
// 	}
// 	else {
// 		cout <<"error"<<endl;
// 		return *this;
// 	}
// }

// Movie * MovieList :: get_head() const{

// 	return head;
// }

// MovieList :: MovieList(const MovieList &x){

// 	Movie *temp = x.get_head();

// 	while(temp != NULL){
// 		this -> add_Movie(temp->get_id(), temp->get_title(), temp->get_year());
// 		temp = temp -> next;
// 	}
// }

// void MovieList::delete_list() {
// 	this-> ~MovieList();
// }

// Movie *MovieList::get_movie(int id) const {
// 	Movie *temp = head;
// 	while(temp != NULL) {
// 		if(temp -> id == id) 
// 			return temp;
// 		temp = temp -> next;
// 	}
// 	printf("Movie not found\n");
// 	return NULL;
// }

// Movie :: Movie(){
 
// }

// Movie :: Movie(int id, char * title, int year){

// 	this -> id = id;
// 	this -> year = year;

// 	this ->title = new char[strlen(title) + 1];
// 	strcpy(this ->title, title);

// 	cout << "Adding " << endl;
// 	print();

// }

// Movie :: ~Movie(){

// 	delete[] title;
// }

// void Movie :: print(){

// 	cout << "ID: " << id << endl;
// 	cout << "Title: ";
// 	puts(title);
	
// 	cout << "Year: " << year << endl;
// }

// char * Movie :: get_title(){

// 	return title ;
// }

// Movie * Movie :: get_next(){

// 	return next; 
// }

// int Movie :: get_id(){

// 	return id;
// }

// int Movie :: get_year(){

// 	return year; 
// }

// void Movie :: set_id(int id){

// 	this -> id = id;
	

// }

// void Movie :: set_year(int year){

// 	this -> year = year;


// }

// void Movie :: set_title(const char* title){

// 	strcpy(this  -> title ,title);


// }

// void Movie :: set_next(Movie *next){

// 	next = this -> next;

// }

// MovieList :: MovieList(){

// 	head = NULL; 
// 	cout << "Empty List is created " << endl;

// }

// MovieList :: ~MovieList(){

// 	Movie * current = head ;
// 	if(head == NULL)
// 		cout << "List is empty so nothing to delete " << endl;

// 	while (current != NULL){ 
// 		delete current -> get_title();
// 		delete current;
// 		current = current -> get_next();
// 	}
// 	head = NULL ;

// }

// void MovieList :: add_Movie(int id, char * title, int year){

// 	Movie *iterate = head;

//   //make sure don't repeat an id
// 	while(iterate != NULL) {
// 		if(iterate -> get_id() == id) {
// 			cout << "Cant add another movie with the same id" << endl;   
// 			return;
// 		}
// 		iterate = iterate -> get_next();
// 	}
//   //free memory of temp pointer if no repeats 
// 	delete iterate;

//   //continue sorted insert by year
// 	Movie *temp = new Movie;
// 	temp -> id = id;
// 	temp -> year = year;
// 	temp -> title = new char[sizeof(title)+1];
// 	strcpy(temp -> title, title);
// 	temp -> next = NULL;   

// 	Movie *current = new Movie; 
// 	if (head == NULL || head -> get_year() >= temp -> get_year()) { 
// 		temp -> set_next(head) ; 
// 		head = temp; 
// 	} else { 
// 		current = head; 
// 		while (current -> next != NULL && current -> next -> year < temp -> year) current = current -> next; 
// 		temp -> next = current -> next; 
// 		current -> next = temp; 
// 	} 
// }

// void MovieList :: remove_Movie(int id){

// 	Movie *current = new Movie;
// 	current = head;
// 	Movie *prev = new Movie;
// 	if(head == NULL) {
// 		cout << "list is empty!" << endl;
// 		return;
// 	} 
// 	else if (current -> get_next() == NULL) {
// 		delete current -> get_title();
// 		delete current;
// 		head = NULL;
// 		return;
// 	}
// 	else if( current -> id == id && current -> next != NULL){
// 		head = current -> next;
// 		delete current -> title;
// 		delete current;
// 		return;
// 	}
// 	while(current -> id != id) {
// 		if(current -> next == NULL) {cout << "Movie not found" << endl;
// 		return;
// 	}
// 	else {
// 		prev = current;
// 		current = current -> next;
// 	}
// } 
// prev -> next = current -> next;
// delete current -> title;
// delete current;
// }

// void MovieList :: print(){
// 	Movie *current = new Movie;
// 	current = head;
// 	if(head == NULL) cout<<"list is empty!"<<endl;
// 	while(current != NULL) {
// 		cout << "ID: " << current -> get_id() << endl << " Title: " << current -> get_title() << endl << " Year: " << current -> get_year() << endl;
// 		current = current -> next; 
// 	}
// }

// int main(){
// 	//create at least two objects of MovieList
// 	MovieList a; 
// 	cout << "Adding movies" << endl;
// 	// MovieList *dynamic = new MovieList;
// 	a.add_Movie(1, "test", 1992);
// 	a.add_Movie(3, "test2", 1993);
// 	a.add_Movie(6, "test3", 1995);
// 	a.print();

// 	(a.get_movie(3)) -> print();
	
// 	a.remove_Movie(3);
// 	a.print();

// 	cout << "using copy constructor" << endl;
// 	//copy constructor
// 	MovieList b(a);
// 	b.print();
// 	cout << "Using assignment operator "<< endl;
// 	//assignment operator
// 	MovieList c;
// 	c = b;
// 	c.print();
// 	a=a;
// 	a.print();
// 	return 0;
// }