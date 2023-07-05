#include "Account.h"
#include<string>
#include<string.h>
#include<fstream>

using namespace std;

// Ham doc thong tin tai khoan Staff
void readAccountStaff(ifstream& f, Staff& log) {
	getline(f, log.acc, ',');
	getline(f, log.pass, ',');
	getline(f, log.position, ',');
	getline(f, log.name, ',');
	getline(f, log.place, '\n');
}

// Kiem tra tai khoan dang nhap Staff
int loginStaff(ifstream& f, string tk, string mk) {
	int check;
	int count = 0;
	int dem = 0;
	while (!f.eof()) {
		Staff log;
		readAccountStaff(f, log);
		count++;
		if (tk.compare(log.acc) == 0) {
			if (mk.compare(log.pass) == 0) {
				check = 1;
			}
			else {
				check = 2;
			}
		}
		else {
			dem++;
		}
	}
	if (dem == count) {
		check = 3;
	}
	return check;
}

// Doc thong tin tai khoan Student
void readAccountStudent(ifstream& f, SinhVien& log) {
	getline(f, log.acc, ',');
	getline(f, log.pass, ',');
	getline(f, log.position, ',');
	getline(f, log.grade, ',');
	getline(f, log.name, ',');
	getline(f, log.id, ',');
	getline(f, log.clas, ',');
	getline(f, log.birthday, ',');
	getline(f, log.gender, ',');
	getline(f, log.credit, '\n');
}

// Kiem tra tai khoan dang nhap Student
int loginStudent(ifstream& f, string tk, string mk) {
	int check;
	int count = 0;
	int dem = 0;
	while (!f.eof()) {
		SinhVien log;
		readAccountStudent(f, log);
		count++;
		if (tk.compare(log.acc) == 0) {
			if (mk.compare(log.pass) == 0) {
				check = 1;
			}
			else {
				check = 2;
			}
		}
		else {
			dem++;
		}
	}
	if (dem == count) {
		check = 3;
	}
	return check;
}