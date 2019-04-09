#include <iostream>

using namespace std;

/*
Question:

a) Design a class PaintingMuseum, storing the following information :
name, maximum number of paintings(capacity), number of paintings owned and a set of paintings
A painting is described by a title, an author, a year of completion(7p)

b) Write implementations the assignment operator(7p)

c) Write implementation of removing a particular painting(6p) 
*/

class Painting{

private:
	char *title;
	char *author;
	int year_of_completion;
	Painting *next;

public:
	Painting();
	Painting(char *title, char *author, int year_of_completion);
	~Painting();
	char *get_title();
	char *get_author();
	int get_year_of_completion();
	Painting *get_next();
	char *set_title(char *title);
	char *set_author(char *author);
	int set_year_of_completion(int year_of_completion);
	Painting *set_next(Painting *next);
	friend class PaintingMuseum;

};

class PaintingMuseum{

private:
	Painting * head;
	char *name;
	int max_no_of_paintings;
	int no_of_paintings_owned;
	int set_of_paintings;

public:
	PaintingMuseum();
	~PaintingMuseum();
	void print();
	void add_Painting(char *title, char *author, int year_of_completion);
	void remove_Painting(char *title, char *author);
	Painting *get_Painting(char *title, char *author) const ;
	void delete_List();
	Painting *get_head() const;
	PaintingMuseum & operator =(const PaintingMuseum &x);

};

PaintingMuseum & PaintingMuseum :: operator =(const PaintingMuseum &x){

	if(x.get_head() != this->get_head()){
	Painting *temp = x.get_head();
		while(temp != NULL){
			this->add_Painting(temp->get_title(), temp->get_author(), temp->year_of_completion());
			temp = temp->next;

		}
		return *this;
	} 
	else {
		cout << "error !" << endl;
		return *this;
	}
}
