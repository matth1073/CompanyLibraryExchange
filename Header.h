#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <list>

using namespace std;


class employee {

public:
	employee();
	string compare();// Takes another employee and compares it to the current employee and returns "greater", "less" or "equal"
	void set_retainer(int retainer);
	void set_wait(int newwait);
	void set_priority(int newpriority);
	void set_start(date startDate);
	void set_book(string newBook);
	int get_priority();
	int get_retainer();
	int get_wait();
	date get_start_date();
	string get_book();
	string get_name();




private:
	string name;
	date start;
	int wait_time, ratain_time, priority;
	string book;
};

class date {
public:
	date();
	string compare(string date);//comparing two different date instances and returns "greater", "less" or "equal" MAKE SURE TO COMPARE LARGER OF SECTION OF TIME FIRST
	void set_date();//will take a date "02/28/2019" and fill in the appropriate attributes 
	string get_date();//return date in a string formate "XX/XX/XXXX"
	int get_difference(date incomingDate);//Returns the difference between passed date and selfdate

private:
	int year, month, day;
};
class book {
public:
	book(string name, date start_date);
	void use();//increments times_used
	void update_current(date newdate);//updates current date
	date get_current_date();//Returns the current date
	date get_start_date(); //Returns the start date
	string get_name();
	int get_usage();//returns usage

private:
	string name;
	date start_date, current_date;
	int times_used;
};


class Library {
private:
	vector<employee> PQ;
	list<employee> has_books;
	list<book> book_in_circ;
	list<book> archives;
	int num_employees;


public:
	void add_employee(employee employee);//Adds a new employee to PQ in the right priority location
	void circulate_book(string bookIncoming, date start_date);//adds a new book to the list book_in_circ and gives it to the top employee in PQ and removes that employee to has_books - sets start for employee - sets wait for employee
	void pass_on(string bookPass, string newEmployee, date current_date);//updates retainer(employee.start-book.current_date) for current holding employee - sets prioirty for ncurrent holding employee - update book with current date - removes next employee from PQ, adds this employee to has_book and sets that emlpoyees wait(current_date- book.start_date) - returns the previous holding employee to PQ - increment use on book
	void archive_book(book bookChecked);// checks to see if book needs to be archives and if so move the book from list book_in_circ and put it in list archives
	void remove_employee(employee employeeBye); // Removes employee from the has_books list. 


};
