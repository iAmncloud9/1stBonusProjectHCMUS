#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#define MAX 100
#define MIN 10

using namespace std;

struct Staff {
	string acc;
	string pass;
	string position;
	string name;
	string place;
};

struct Node {
	Staff account;
	Node* next;
};

typedef Node* node;

struct SinhVien {
	string acc;
	string pass;
	string position;
	string name;
	string id;
	string clas;
	string birthday;
	string gender;
	string credit;
};

struct Login {
	SinhVien infor;
	Login* next;
};

typedef struct Login* logstu;