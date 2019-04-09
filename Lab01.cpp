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
  //Printing empty list
  print();

  //Deleting from empty list
  remove_Movie(1);

  cout << "==========Adding movies=========\n";
  //Addition to empty list
  add_Movie(8, "a", 1945); add_Movie(3, "b", 1962); add_Movie(2, "c", 2001);
  add_Movie(1, "d", 1990); add_Movie(5, "e", 1825); add_Movie(7, "f", 1320);
  add_Movie(4, "g", 1991); add_Movie(6, "h", 1998); add_Movie(9, "i", 2000);
  print();

  cout << "==========Adding same movie=========\n";
  //Adding same movie
  add_Movie(1, "d", 1990);

  cout << "==========Deleting movies=========\n";
  //Removing head element 
  remove_Movie(7);
  cout << "Printing list without head element " << endl;
  print();

  //Removing tail element
  remove_Movie(2);
  cout << "Printing list without last element" << endl;
  print();

  //removing element from the middle
  remove_Movie(8);
  cout << "Printing list without some middle element" << endl;
  print();

  return 0;
}

void add_Movie(int id, char* title, int year) { 
 Movie *iterate = head;

  //make sure don't repeat an id
 while(iterate != NULL) {
  if(iterate -> id == id) {
    cout << "Cant add another movie with the same id" << endl;   
    return;
  }
  iterate = iterate -> next;
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
if (head == NULL || head -> year >= temp -> year) { 
  temp -> next = head; 
  head = temp; 
} else { 
  current = head; 
  while (current -> next != NULL && current -> next -> year < temp -> year) current = current -> next; 
  temp -> next = current -> next; 
  current -> next = temp; 
} 

}
//fix removing head element
void remove_Movie(int id) {
  Movie *current= new Movie;
  current = head;
  Movie *prev = new Movie;
  if(head == NULL) {                       //empty list
    cout << "list is empty!" << endl;
    return;
  } 
  else if (current -> next == NULL) {       // list with one element 
    delete current -> title;
    delete current;
    head = NULL;
    return;
  }
  else if( current -> id == id && current -> next != NULL){     // movie found in the middle of the list but not in the end
    head = current -> next;
    delete current -> title;
    delete current;
    return;
  }
  while(current -> id != id) {                  
    if(current -> next == NULL) {
      cout << "Movie not found" << endl;
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

void print() {
 Movie *current = new Movie;
 current = head;
 if(head == NULL) cout<<"list is empty!"<<endl;
 while(current != NULL) {
  cout << "ID: " << current -> id << " Title: " << current -> title << " Year: " << current -> year << endl;
  current = current -> next; 
}
}