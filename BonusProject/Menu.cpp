#include "Account.h"
#include "Course.h"

using namespace std;

// Menu chinh
void main_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(20) << "LOGIN" << setw(20) << "*" << endl;
	cout << setw(60) << "*" << setw(22)	<< "---------" << setw(18) << "*" << endl;
	cout << setw(60) << "*"	<< setw(26) << "1. Academic Staff" << setw(14) << "*" << endl;
	cout << setw(60) << "*" << setw(19) << "2. Student" << setw(21) << "*" << endl;
	cout << setw(60) << "*" << setw(16) << "3. Exit" << setw(24) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}

// Ham lua chon
void choose(int& op) {
	cout << setw(105) << "---------------------------------------------------" << endl;
	cout << endl;
	cout << setw(86) << "YOUR CHOICE: "; cin >> op;
	cout << endl;
}

// 1. Danh cho Giang vien
// Menu rieng
void sta_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(26) << "ACADEMIC STAFF" << setw(14) << "*" << endl;
	cout << setw(60) << "*" << setw(27) << "----------------" << setw(13) << "*" << endl;
	cout << setw(60) << "*" << setw(17) << "1. Login" << setw(23) << "*" << endl;
	cout << setw(60) << "*" << setw(20) << "2. Register" << setw(20) << "*" << endl;
	cout << setw(60) << "*" << setw(16) << "3. Back" << setw(24) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}

// Menu khi dang nhap
void in_sta_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(18) << "STAFF" << setw(22) << "*" << endl;
	cout << setw(60) << "*" << setw(19) << "-------" << setw(21) << "*" << endl;
	cout << setw(60) << "*" << setw(26) << "1. My Information" << setw(14) << "*" << endl;
	cout << setw(60) << "*" << setw(28) << "2. Course And Class" << setw(12) << "*" << endl;
	cout << setw(60) << "*" << setw(27) << "3. Change Password" << setw(13) << "*" << endl;
	cout << setw(60) << "*" << setw(19) << "4. Log Out" << setw(21) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}

// Menu khoa hoc va lop hoc
void work_sta_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(29) << "COURSE AND CLASS" << setw(11) << "*" << endl;
	cout << setw(60) << "*" << setw(31) << "--------------------" << setw(9) << "*" << endl;
	cout << setw(60) << "*" << setw(17) << "1. Class" << setw(23) << "*" << endl;
	cout << setw(60) << "*" << setw(18) << "2. Course" << setw(22) << "*" << endl;
	cout << setw(60) << "*" << setw(16) << "3. Back" << setw(24) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}

// Menu lop hoc
void class_sta_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(18) << "CLASS" << setw(22) << "*" << endl;
	cout << setw(60) << "*" << setw(20) << "---------" << setw(20) << "*" << endl;
	cout << setw(60) << "*" << setw(28) << "1. Create New Class" << setw(12) << "*" << endl;
	cout << setw(60) << "*" << setw(22) << "2. List Class" << setw(18) << "*" << endl;
	cout << setw(60) << "*" << setw(16) << "3. Back" << setw(24) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}

// Menu my class
void in_class_sta_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(31) << "WORKING WITH CLASS" << setw(9) << "*" << endl;
	cout << setw(60) << "*" << setw(33) << "----------------------" << setw(7) << "*" << endl;
	cout << setw(60) << "*" << setw(29) << "1. View List Student" << setw(11) << "*" << endl;
	cout << setw(60) << "*" << setw(28) << "2. View List Course" << setw(12) << "*" << endl;
	cout << setw(60) << "*" << setw(24) << "3. Update Class" << setw(16) << "*" << endl;
	cout << setw(60) << "*" << setw(16) << "4. Back" << setw(24) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}

// Menu update class
void update_class_sta_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(19) << "UPDATE" << setw(21) << "*" << endl;
	cout << setw(60) << "*" << setw(21) << "----------" << setw(19) << "*" << endl;
	cout << setw(60) << "*" << setw(27) << "1. Add One Student" << setw(13) << "*" << endl;
	cout << setw(60) << "*" << setw(29) << "2. Add Student(File)" << setw(11) << "*" << endl;
	cout << setw(60) << "*" << setw(16) << "3. Back" << setw(24) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}
 
// Menu thao tac voi khoa hoc
void course_sta_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(19) << "COURSE" << setw(21) << "*" << endl;
	cout << setw(60) << "*" << setw(21) << "----------" << setw(19) << "*" << endl;
	cout << setw(60) << "*" << setw(29) << "1. Create New Course" << setw(11) << "*" << endl;
	cout << setw(60) << "*" << setw(23) << "2. List Course" << setw(17) << "*" << endl;
	cout << setw(60) << "*" << setw(16) << "3. Back" << setw(24) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}

// Menu my course
void in_course_sta_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(28) << "WORKING WITH COURSE" << setw(12) << "*" << endl;
	cout << setw(60) << "*" << setw(24) << "-------------" << setw(16) << "*" << endl;
	cout << setw(60) << "*" << setw(23) << "1. View Result" << setw(17) << "*" << endl;
	cout << setw(60) << "*" << setw(25) << "2. Update Course" << setw(15) << "*" << endl;
	cout << setw(60) << "*" << setw(25) << "3. Remove Course" << setw(15) << "*" << endl;
	cout << setw(60) << "*" << setw(16) << "4. Back" << setw(24) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}

// Menu update course
void update_course_sta_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(19) << "UPDATE" << setw(21) << "*" << endl;
	cout << setw(60) << "*" << setw(21) << "----------" << setw(19) << "*" << endl;
	cout << setw(60) << "*" << setw(23) << "1. Add Student" << setw(17) << "*" << endl;
	cout << setw(60) << "*" << setw(35) << "2. Update Student's Result" << setw(5) << "*" << endl;
	cout << setw(60) << "*" << setw(26) << "3. Remove Student" << setw(14) << "*" << endl;
	cout << setw(60) << "*" << setw(16) << "4. Back" << setw(24) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}


// 2. Danh cho Sinh Vien
// Menu rieng
void stu_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(20) << "STUDENT" << setw(20) << "*" << endl;
	cout << setw(60) << "*" << setw(22) << "----------" << setw(18) << "*" << endl;
	cout << setw(60) << "*" << setw(17) << "1. Login" << setw(23) << "*" << endl;
	cout << setw(60) << "*" << setw(20) << "2. Resigter" << setw(20) << "*" << endl;
	cout << setw(60) << "*" << setw(16) << "3. Back" << setw(24) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}

// Menu khi dang nhap
void in_stu_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(20) << "STUDENT" << setw(20) << "*" << endl;
	cout << setw(60) << "*" << setw(22) << "-----------" << setw(18) << "*" << endl;
	cout << setw(60) << "*" << setw(26) << "1. My Information" << setw(14) << "*" << endl;
	cout << setw(60) << "*" << setw(18) << "2. Course" << setw(22) << "*" << endl;
	cout << setw(60) << "*" << setw(27) << "3. Change Password" << setw(13) << "*" << endl;
	cout << setw(60) << "*" << setw(19) << "4. Log Out" << setw(21) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}

// Menu khoa hoc
void in_course_stu_menu() {
	cout << setw(100) << "*****************************************" << endl;
	cout << setw(60) << "*" << setw(19) << "COURSE" << setw(21) << "*" << endl;
	cout << setw(60) << "*" << setw(21) << "----------" << setw(19) << "*" << endl;
	cout << setw(60) << "*" << setw(27) << "1. Register Course" << setw(13) << "*" << endl;
	cout << setw(60) << "*" << setw(28) << "2. View List Course" << setw(12) << "*" << endl;
	cout << setw(60) << "*" << setw(22) << "3. View Score" << setw(18) << "*" << endl;
	cout << setw(60) << "*" << setw(16) << "4. Back" << setw(24) << "*" << endl;
	cout << setw(100) << "*****************************************" << endl;
}