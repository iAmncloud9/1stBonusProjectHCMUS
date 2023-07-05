#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

typedef struct Student {
	string course;
	string cid;
	string stuclass;
	string id;
	string fname;
	string lname;
	string gender;
	string birth;
	string scid;
} sv;

struct List {
	sv student;
	List* next;
};

typedef struct List* list;

/*------------------------------------------------------------*/

struct Class {
	string name;
	string number;
	string scyear;
};

struct Base {
	Class data;
	Base* next;
};

typedef struct Base* base;

/*------------------------------------------------------------*/

struct Course {
	string name;
	string id;
	string credit;
	string clas;
	string daystart;
	string dayend;
	string timestart;
	string timeend;
	string number;
	string lecturer;
	string day;
	string room;
};

struct Board {
	Course course;
	Board* next;
};

typedef struct Board* board;

/*---------------------------------------------------------------*/

struct Score {
	string course;
	string cid;
	string id;
	string fname;
	string lname;
	string omark;
	string mmark;
	string fmark;
	string total;
};

struct Result {
	Score mark;
	Result* next;
};

typedef struct Result* result;