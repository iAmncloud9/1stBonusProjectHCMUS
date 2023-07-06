#include "Account.h"
#include "Course.h"
#include "func.h"
#include "menu.h"
#include<string>

using namespace std;

int main() {
	int a = 1;
	int op;
	node ds = new Node();
	logstu doc = new Login();
	list stu = new List();
	base cla = new Base();
	board course = new Board();
	result score = new Result();
	add input = NULL;
	int checklogin;
	string tk, mk;
	string p, str, name;
	ifstream f;
	ofstream g;
	main_menu();
	while (true) {
		choose(op);
		switch (op) {
		case 1:															// 1. Academic Staff
			system("cls");
			sta_menu();
			while (a) {
				choose(op);
				switch (op) {
				case 1:														// 1.1. Login
					system("cls");
					f.open("staff.csv", ios::in);
					cout << setw(61) << "--------LOGIN--------" << endl;
					cout << "USER NAME: ";
					cin.ignore();
					getline(cin, tk);
					cout << "PASSWORD: ";
					getline(cin, mk);
					checklogin = loginStaff(f, tk, mk);
					if (checklogin == 1) {
						cout << endl << endl << "LOGIN SUCCESSFULLY!" << endl;
						f.close();
						f.seekg(0, ios_base::beg);
						system("pause");
						system("cls");
						in_sta_menu();
						while (a) {
							choose(op);
							switch (op) {
							case 1:													// 1.1.1. Information
								f.open("staff.csv", ios::in);
								cout << setw(79) << "**********ACCOUNT INFORMATION**********" << endl;
								staffInformation(f, tk, mk);
								f.close();
								system("pause");
								system("cls");
								in_sta_menu();
								break;
							case 2:													// 1.1.2. Course and Class
								system("cls");
								work_sta_menu();
								while (a) {
									choose(op);
									switch (op) {
									case 1:												// 1.1.2.1. Class
										system("cls");
										class_sta_menu();
										while (a) {
											choose(op);
											switch (op) {
												f.open("class.csv", ios::in);
												readFileClass(f, cla);
												f.close();
												clearBase(cla);
											case 1:											// 1.1.2.1.1. Create New Class
												system("cls");
												f.open("class.csv", ios::in);
												readFileClass(f, cla);
												f.close();
												cout << setw(39) << "*****NEW CLASS*****" << endl;
												cin.ignore();
												cout << "SCHOOL YEAR: "; getline(cin, str);
												if (str == "2022-2023") {
													cout << "NAME CLASS: "; getline(cin, p);
													if (addClass(cla, str, p) == 1) {
														cout << endl << endl << "CREATE NEW CLASS SUCCESSFULLY!" << endl;
														g.open("class.csv", ios::out);
														outputFileClass(g, cla);
														g.close();
													}
													else {
														cout << endl << endl << "CLASS ALREADY EXISTS. " << endl;
													}
												}
												else {
													cout << endl << endl << "JUST FOR SCHOOL YEAR 2022-2023!" << endl;
												}
												system("pause");
												system("cls");
												class_sta_menu();
												clearBase(cla);
												break;
											case 2:											// 1.1.2.1.2. My Class
												system("cls");
												in_class_sta_menu();
												f.open("class.csv", ios::in);
												readFileClass(f, cla);
												f.close();
												clearBase(cla);
												while (a) {
													system("cls");
													f.open("class.csv", ios::in);
													readFileClass(f, cla);
													outputClass(cla);
													f.close();
													clearBase(cla);
													cout << endl << endl;
													in_class_sta_menu();
													choose(op);
													switch (op) {
													case 1:										// 1.1.2.1.2.1. View List Student
														cin.ignore();
														cout << endl << "SELECT CLASS: "; getline(cin, str);
														f.open("class.csv", ios::in);
														readFileClass(f, cla);
														f.close();
														if (reClass(cla, str)) {
															system("cls");
															f.open("list_student.csv", ios::in);
															readFileStudent(f, stu);
															f.close();
															outputStudentofClass(stu, str);
															system("pause");
															outputClass(cla);
															cout << endl << endl;
															in_class_sta_menu();
															clearList(stu);
														}
														else {
															cout << "CAN'T FIND THIS CLASS." << endl;
															system("pause");
														}
														clearBase(cla);
														break;
													case 2:										// 1.1.2.1.2.2. View List Course Of Class
														cin.ignore();
														cout << endl << "SELECT CLASS: "; getline(cin, str);
														f.open("class.csv", ios::in);
														readFileClass(f, cla);
														f.close();
														if (reClass(cla, str)) {
															f.open("course.csv", ios::in);
															readFileCourse(f, course);
															f.close();
															outputCourseofClass(course, str);
															system("pause");
															clearBoard(course);
														}
														else {
															cout << endl << endl << "CAN'T FIND THIS CLASS." << endl;
															system("pause");
															clearBoard(course);
														}
														clearBase(cla);
														break;
													case 3:										// 1.1.2.1.2.3. Update Class
														cin.ignore();
														cout << endl << "SELECT CLASS: "; getline(cin, str);
														f.open("class.csv", ios::in);
														readFileClass(f, cla);
														f.close();
														if (reClass(cla, str)) {
															if (firstYearStu(cla, str)) {
																clearBase(cla);
																system("cls");
																update_class_sta_menu();
																while (a) {
																	choose(op);
																	switch (op) {
																	case 1:								// 1.1.2.1.2.3.1. Add 1 Student
																		//Them 1 sinh vien
																		f.open("list_student.csv", ios::in);
																		readFileStudent(f, stu);
																		f.close();
																		f.open("class.csv", ios::in);
																		readFileClass(f, cla);
																		f.close();
																		addStudentInClass(stu, cla, str);
																		g.open("list_student.csv", ios::out);
																		outputStudentinFile(g, stu);
																		g.close();
																		g.open("class.csv", ios::out);
																		outputFileClass(g, cla);
																		g.close();
																		clearList(stu);
																		clearBase(cla);
																		system("pause");
																		system("cls");
																		update_class_sta_menu();
																		break;
																	case 2:								// 1.1.2.1.2.3.2. Add Student From File
																		// Them sinh vien theo file
																		f.open("add_student.csv", ios::in);
																		readFileAdd(f, input);
																		f.close();
																		f.open("list_student.csv", ios::in);
																		readFileStudent(f, stu);
																		f.close();
																		f.open("class.csv", ios::in);
																		readFileClass(f, cla);
																		f.close();
																		addStudentFromFile(input, stu, cla, str);
																		g.open("list_student.csv", ios::out);
																		outputStudentinFile(g, stu);
																		g.close();
																		g.open("class.csv", ios::out);
																		outputFileClass(g, cla);
																		g.close();
																		system("pause");
																		system("cls");
																		update_class_sta_menu();
																		clearList(stu);
																		clearAdd(input);
																		clearBase(cla);
																		break;
																	case 3:									// 1.1.2.1.2.3.3. Back
																		a = 0;
																		clearBase(cla);
																		system("cls");
																		in_class_sta_menu();
																		break;
																	default:
																		cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
																		system("pause");
																		system("cls");
																		update_class_sta_menu();
																		break;
																	}
																}
															}
															else {
																cout << endl << endl << "JUST FOR FIRST YEAR STUDENT" << endl;
																cout << endl;
																system("pause");
															}
														}
														else {
															cout << endl << endl << "CAN'T FIND THIS CLASS." << endl;
															system("pause");
														}
														a = 1;
														break;
													case 4:										// 1.1.2.1.2.4. Back
														a = 0;
														system("cls");
														class_sta_menu();
														break;
													default:
														cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
														clearBase(cla);
														system("pause");
														system("cls");
														in_class_sta_menu();
														break;
													}
												}
												a = 1;
												break;
											case 3:											// 1.1.2.1.3. Back
												a = 0;
												system("cls");
												work_sta_menu();
												break;
											default:
												cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
												system("pause");
												system("cls");
												class_sta_menu();
												break;
											}
										}
										a = 1;
										break;
									case 2:												// 1.1.2.2.  Course
										system("cls");
										course_sta_menu();
										while (a) {
											f.open("course.csv", ios::in);
											readFileCourse(f, course);
											f.close();
											clearBoard(course);
											choose(op);
											switch (op) {
											case 1:											// 1.1.2.2.1. Create New Course														
												f.open("course.csv", ios::in);
												readFileCourse(f, course);
												f.close();
												g.open("course.csv", ios::out);
												addCourse(course);
												outputFileCourse(g, course);
												system("pause");
												g.close();
												system("cls");
												clearBoard(course);
												course_sta_menu();
												break;
											case 2:											// 1.1.2.2.2. List Course
												system("cls");
												f.open("course.csv", ios::in);
												readFileCourse(f, course);
												f.close();
												clearBoard(course);
												f.open("student_score.csv", ios::in);
												readFileScore(f, score);
												f.close();
												clearResult(score);
												while (a) {
													f.open("course.csv", ios::in);
													readFileCourse(f, course);
													f.close();
													outputCourse(course);
													clearBoard(course);
													in_course_sta_menu();
													choose(op);
													switch (op) {
													case 1:										// 1.1.2.2.2.1. View Result
														cin.ignore();
														cout << endl << "SELECT COURSE: "; getline(cin, str);
														cout << "ENTER COURSE ID: "; getline(cin, p);
														f.open("list_student.csv", ios::in);
														readFileCourse(f, course);
														f.close();
														if(reCourse(course, str, p)) {
															f.open("student_score.csv", ios::in);
															readFileScore(f, score);
															f.close();
															outputScore(score, str, p);
															system("pause");
															system("cls");
															a = 1;
														}
														else {
															a = 1;
															cout << endl << endl << "CAN'T FIND THIS COURSE." << endl;
															system("pause");
															system("cls");
														}
														clearBoard(course);
														clearResult(score);
														break;
													case 2:										// 1.1.2.2.2.2. Update Course
														cin.ignore();
														cout << endl << "SELECT COURSE: "; getline(cin, str);
														cout << "ENTER COURSE ID: "; getline(cin, p);
														f.open("course.csv", ios::in);
														readFileCourse(f, course);
														f.close();
														if (reCourse(course, str, p)) {
															system("cls");
															update_course_sta_menu();
															while (a) {
																choose(op);
																switch (op) {
																case 1:									// 1.1.2.2.2.1.1. Add 1 Student
																	f.open("list_student.csv", ios::in);
																	readFileStudent(f, stu);
																	f.close();
																	f.open("class.csv", ios::in);
																	readFileClass(f, cla);
																	f.close();
																	f.open("student_score.csv", ios::in);
																	readFileScore(f, score);
																	f.close();
																	addStudentToCourse(stu, cla, score, str, p);
																	g.open("list_student.csv", ios::out);
																	outputStudentinFile(g, stu);
																	g.close();
																	g.open("student_score.csv", ios::out);
																	outputFileScore(g, score);
																	g.close();
																	clearList(stu);
																	clearBase(cla);
																	clearResult(score);
																	system("pause");
																	system("cls");
																	outputCourse(course);
																	in_course_sta_menu();
																case 2:									// 1.1.2.2.2.1.2. Update Student Result
																	//Cap nhat ket qua sinh vien
																	cin.ignore();
																	cout << endl  << "ENTER STUDENT ID: "; getline(cin, name);
																	f.open("student_score.csv", ios::in);
																	readFileScore(f, score);
																	f.close();
																	if (checkStuInCourse(score, str, p, name)) {
																		updateStudentScore(score, str, p, name);
																		g.open("student_score.csv", ios::out);
																		outputFileScore(g, score);
																		g.close();
																		system("pause");
																		system("cls");
																		update_course_sta_menu();
																	}
																	else {
																		cout << endl << "THIS STUDENT NOT EXIST." << endl;
																		system("pause");
																		system("cls");
																		a = 1;
																		update_course_sta_menu();
																	}
																	clearResult(score);
																	break;
																case 3:									// 1.1.2.2.2.1.3. Remove Student
																	cin.ignore();
																	cout << endl << "ENTER STUDENT ID: "; getline(cin, name);
																	f.open("list_student.csv", ios::in);
																	readFileStudent(f, stu);
																	f.close();
																	f.open("student_score.csv", ios::in);
																	readFileScore(f, score);
																	f.close();
																	if (checkStuInCourse(score, str, p, name)) {
																		removeStudent(score, str, p, name);
																		removeStudentFromCourse(stu, str, p, name);
																		g.open("list_student.csv", ios::out);
																		outputStudentinFile(g, stu);
																		g.close();
																		g.open("student_score.csv", ios::out);
																		outputFileScore(g, score);
																		g.close();
																		cout << endl << endl << "REMOVE STUDENT SUCCESSFULLY." << endl;
																	}
																	else {
																		cout << endl << endl << "CAN'T FIND THIS STUDENT." << endl;
																	}
																	clearList(stu);
																	clearResult(score);
																	system("pause");
																	system("cls");
																	update_course_sta_menu();
																	break;
																case 4:									// 1.1.2.2.2.1.4. Back
																	a = 0;
																	system("cls");
																	break;
																default:
																	cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
																	system("pause");
																	system("cls");
																	update_course_sta_menu();
																	break;
																}
															}
														}
														else {
															a = 1;
															cout << endl << endl << "CAN'T FIND THIS COURSE." << endl;
															system("pause");
															system("cls");
														}
														clearBoard(course);
														a = 1;
														break;
													case 3:										// 1.1.2.2.2.3. Remove Course
														cin.ignore();
														cout << endl << "SELECT COURSE: "; getline(cin, str);
														cout << "ENTER COURSE ID: "; getline(cin, p);
														f.open("course.csv", ios::in);
														readFileCourse(f, course);
														f.close();
														if (reCourse(course, str, p)) {
															deleteCourse(course, str);
															g.open("course.csv", ios::out);
															outputFileCourse(g, course);
															g.close();
														}
														else {
															cout << endl << endl << "CAN'T FIND THIS COURSE." << endl;
															system("pause");
														}
														system("cls");
														clearBoard(course);
														break;
													case 4:										// 1.1.2.2.2.4. Back
														a = 0;
														system("cls");
														course_sta_menu();
														break;
													default:
														cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
														system("pause");
														system("cls");
														break;
													}
												}
												a = 1;
												break;
											case 3:											// 1.1.2.2.3. Back
												a = 0;
												system("cls");
												work_sta_menu();
												break;
											default:
												cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
												system("pause");
												system("cls");
												course_sta_menu();
												break;
											}
										}
										a = 1;
										break;
									case 3:												// 1.1.2.3. Back
										a = 0;
										system("cls");
										in_sta_menu();
										break;
									default:
										cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
										system("pause");
										system("cls");
										work_sta_menu();
										break;
									}
								}
								a = 1;
								break;
							case 3:													// 1.1.3. Change Password
								f.open("staff.csv", ios::in);
								readAllFileStaff(f, ds);
								f.close();
								g.open("staff.csv", ios::out);
								changePasswordStaff(ds, tk);
								ouputFileStaff(g, ds);
								cout << endl << endl << "CHANGE PASSWORD SUCCESSFULLY!" << endl;
								g.close();
								a = 0;
								system("pause");
								system("cls");
								sta_menu();
								break;
							case 4:													// 1.1.4. Log Out
								a = 0;
								cout << endl << "LOG OUT SUCCESSFULLY!" << endl;
								system("pause");
								system("cls");
								sta_menu();
								break;
							default:
								cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
								system("pause");
								system("cls");
								in_sta_menu();
								break;
							}
						}
						a = 1;
						break;
					}
					else {
						f.open("staff.csv", ios::in);
						if (checklogin == 2) {
							cout << endl << endl << "INCORRECT PASSWORD!" << endl;
							system("pause");
							system("cls");
							sta_menu();
						}
						else {
							cout << endl << endl << "ACCOUNT DOES NOT EXIST!" << endl;
							system("pause");
							system("cls");
							sta_menu();
						}
						f.close();
					}
					break;
				case 2:														// 1.2. Register
					cout << setw(68) << "**********REGISTER**********" << endl;
					p = "Staff";
					f.open("staff.csv", ios::in);
					readAllFileStaff(f, ds);
					f.close();
					registerStaffAccount(ds, p);
					g.open("staff.csv", ios::out);
					ouputFileStaff(g, ds);
					g.close();
					system("pause");
					system("cls");
					sta_menu();
					clearNode(ds);
					break;
				case 3:														// 1.3. Back
					a = 0;
					system("cls");
					main_menu();
					break;
				default:
					cout << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
					system("pause");
					system("cls");
					sta_menu();
					break;
				}
			}
			a = 1;
			break;
		case 2:															// 2. Student
			system("cls");
			stu_menu();
			while (a) {
				choose(op);
				switch (op) {
				case 1:														// 2.1. Login
					system("cls");
					f.open("student.csv", ios::in);
					cout << setw(61) << "--------LOGIN--------" << endl;
					cin.ignore();
					cout << "USER NAME: ";
					getline(cin, tk);
					cout << "PASSWORD: ";
					getline(cin, mk);
					checklogin = loginStudent(f, tk, mk);
					if (checklogin == 1) {
						cout << endl << endl << "LOGIN SUCCESSFULLY!" << endl;
						f.close();
						f.seekg(0, ios_base::beg);
						system("pause");
						system("cls");
						in_stu_menu();
						while (a) {
							choose(op);
							switch (op) {
							case 1:													// 2.1.1. Information
								f.open("student.csv", ios::in);
								cout << setw(81) << "**********USER INFORMATION**********" << endl;
								cout << endl;
								studentInformation(f, tk, mk);
								f.close();
								system("pause");
								system("cls");
								in_stu_menu();
								break;
							case 2:													// 2.1.2. Course
								system("cls");
								in_course_stu_menu();
								while (a) {
									f.open("course.csv", ios::in);
									readFileCourse(f, course);
									f.close();
									clearBoard(course);
									f.open("student.csv", ios::in);
									readAllFileStudent(f, doc);
									f.close();
									clearLogin(doc);
									choose(op);
									switch (op) {
									case 1:												// 2.1.2.1. Register Course
										system("cls");
										f.open("course.csv", ios::in);
										readFileCourse(f, course);
										f.close();
										outputCourse(course);
										f.open("student_score.csv", ios::in);
										readFileScore(f, score);
										f.close();
										clearResult(score);
										cin.ignore();
										cout << endl << "SELECT COURSE: "; getline(cin, str);
										cout << "ENTER COURSE ID: "; getline(cin, p);
										if (reCourse(course, str, p)) {
											f.open("list_student.csv", ios::in);
											readFileStudent(f, stu);
											f.close();
											f.open("student_score.csv", ios::in);
											readFileScore(f, score);
											f.close();
											f.open("student.csv", ios::in);
											readAllFileStudent(f, doc);
											f.close();
											registerCourse(doc, stu, score, str, p, tk);
											g.open("list_student.csv", ios::out);
											outputStudentinFile(g, stu);
											g.close();
											g.open("student_score.csv", ios::out);
											outputFileScore(g, score);
											g.close();
											g.open("student.csv", ios::out);
											ouputFileStudent(g, doc);
											g.close();
											clearList(stu);
											clearResult(score);
											clearLogin(doc);
										}
										else {
											cout << endl << endl << "THIS COURSE IS NOT EXITS." << endl;
										}
										system("pause");
										system("cls");
										in_course_stu_menu();
										clearBoard(course);
										break;
									case 2:												// 2.1.2.2. View List Course 
										f.open("course.csv", ios::in);
										readFileCourse(f, course);
										f.close();
										f.open("student.csv", ios::in);
										readAllFileStudent(f, doc);
										f.close();
										f.open("list_student.csv", ios::in);
										readFileStudent(f, stu);
										f.close();
										viewListCourse(doc, course, stu, tk);
										clearBoard(course);
										clearLogin(doc);
										clearList(stu);
										system("pause");
										system("cls");
										in_course_stu_menu();
										break;
									case 3:												// 2.1.2.3. View Score
										cin.ignore();
										f.open("student.csv", ios::in);
										readAllFileStudent(f, doc);
										f.close();
										f.open("student_score.csv", ios::in);
										readFileScore(f, score);
										f.close();
										cout << endl;
										viewScore(doc, score, tk);
										system("pause");
										clearLogin(doc);
										clearResult(score);
										system("pause");
										system("cls");
										in_course_stu_menu();	
										break;
									case 4:												// 2.1.2.4. Back
										a = 0;
										system("cls");
										in_stu_menu();
										break;
									default:
										cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
										system("pause");
										system("cls");
										in_course_stu_menu();
										break;
									}
								}
								a = 1;
								break;
							case 3:													// 2.1.3. Change Password
								f.open("student.csv", ios::in);
								readAllFileStudent(f, doc);
								f.close();
								g.open("student.csv", ios::out);
								changePasswordStudent(doc, tk);
								ouputFileStudent(g, doc);
								cout << endl << endl << "CHANGE PASSWORK SUCCESSFULLY!" << endl;
								g.close();
								a = 0;
								system("pause");
								system("cls");
								stu_menu();
								break;
							case 4:													// 2.1.4. Log Out
								a = 0;
								cout << endl << endl << "LOG OUT SUCCESSFULLY" << endl;
								system("pause");
								system("cls");
								stu_menu();
								break;
							default:
								cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
								system("pause");
								system("cls");
								in_stu_menu();
								break;
							}
						}
						a = 1;
						break;
					}
					else {
						f.open("student.csv", ios::in);
						if (checklogin == 2) {
							cout << endl << endl << "INCORRECT PASSWORD." << endl;
							system("pause");
							system("cls");
							stu_menu();
							f.seekg(0, ios::beg);
						}
						else {
							cout << endl << endl << "ACCOUNT DOES NOT EXISTS." << endl;
							system("pause");
							system("cls");
							stu_menu();
						}
						f.close();
					}
					break;
				case 2:														// 2.2. Register
					f.open("list_student.csv", ios::in);
					readFileStudent(f, stu);
					f.close();
					f.open("class.csv", ios::in);
					readFileClass(f, cla);
					f.close();
					f.open("student.csv", ios::in);
					readAllFileStudent(f, doc);
					f.close();
					cout << setw(68) << "**********REGISTER**********" << endl;
					p = "Student";
					registerStudentAccount(doc, stu, cla, p);
					g.open("student.csv", ios::out);
					ouputFileStudent(g, doc);
					g.close();
					system("pause");
					system("cls");
					stu_menu();
					clearLogin(doc);
					clearList(stu);
					clearBase(cla);
					break;
				case 3:														// 2.3. Back
					a = 0;
					system("cls");
					main_menu();
					break;
				default:
					cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
					system("pause");
					system("cls");
					stu_menu();
					break;
				}
			}
			a = 1;
			break;
		case 3:															// 3. Exit
			system("cls");
			cout << endl << endl << "END. SEE YOU LATER!" << endl;
			a = 0;
			return 0;
		default:
			cout << endl << endl << "INVALID REQUEST. PLEASE TRY AGAIN!" << endl;
			system("pause");
			system("cls");
			main_menu();
			break;
		}
	}
}