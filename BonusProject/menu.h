#include<iostream>

using namespace std;

void main_menu();						// Menu chinh

// Danh cho Staff

void sta_menu();						// Menu rieng
void in_sta_menu();						// Menu khi dang nhap
void work_sta_menu();					// Menu khoa hoc va lop hoc
void class_sta_menu();					// Menu lop hoc
void in_class_sta_menu();				// Menu my class
void update_class_sta_menu();			// Menu update class
void course_sta_menu();					// Menu thao tac voi khoa hoc
void in_course_sta_menu();				// Menu my course
void update_course_sta_menu();			// Menu update course

// Danh cho sinh vien

void stu_menu();						// Menu rieng
void in_stu_menu();						// Menu khi dang nhap
void in_course_stu_menu();				// Menu khoa hoc
void choose(int& op);					// Ham lua chon