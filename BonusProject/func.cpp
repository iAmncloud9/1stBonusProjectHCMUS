#include "Account.h"
#include "Course.h"
#include "func.h"
#include<string.h>
#include<fstream>

using namespace std;

// Ham xuat thong tin Staff
void outputStaffInformation(Staff log) {
	cout << "NAME: " << log.name << endl;
	cout << "POSITION: " << log.position << endl;
	cout << "WORKPLACE: " << log.place << endl;
	cout << endl;
}

// Ham xuat thong tin Student
void outputStudentInformation(SinhVien log) {
	cout << "NAME: " << log.name << endl;
	cout << "POSITION: " << log.position << endl;
	cout << "GRADE: " << log.grade << endl;
	cout << "STUDENT ID: " << log.id << endl;
	cout << "GENDER: " << log.gender << endl;
	cout << "DAY OF BIRTH: " << log.birthday << endl;
	cout << "CLASS: " << log.clas << endl;
}

// Ham xuat thong tin tai khoan Staff
void staffInformation(ifstream& f, string tk, string mk) {
	while (!f.eof()) {
		Staff log;
		readAccountStaff(f, log);
		if (log.acc.compare(tk) == 0) {
			outputStaffInformation(log);
		}
	}
}

// Ham xuat thong tin tai khoan Student
void studentInformation(ifstream& f, string tk, string mk) {
	while (!f.eof()) {
		SinhVien log;
		readAccountStudent(f, log);
		if (log.acc.compare(tk) == 0) {
			outputStudentInformation(log);
		}
	}
}

// Cap phat node tam cho Staff
node makeAccountStaff(Staff x) {
	node temp = new Node();
	temp->account = x;
	temp->next = NULL;
	return temp;
}

// Cap phat log tam cho Student
logstu makeAccountStudent(SinhVien x) {
	logstu temp = new Login();
	temp->infor = x;
	temp->next = NULL;
	return temp;
}

// Kiem tra node rong
bool nodeEmpty(node a) {
	return a == NULL;
}

// Kiem tra login rong
bool loginEmpty(logstu a) {
	return a == NULL;
}

// Them thong tin vao node
void addAccountStaff(node& a, node temp) {
	if (nodeEmpty(a)) {
		a = temp;
	}
	else {
		node p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
}

// Them thong tin vao logstu
void addAccountStudent(logstu& a, logstu temp) {
	if (loginEmpty(a)) {
		a = temp;
	}
	else {
		logstu p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
}

// Ham doc file cho Staff
void readAllFileStaff(ifstream& f, node& a) {
	while (!f.eof()) {
		Staff log;
		readAccountStaff(f, log);
		node temp = makeAccountStaff(log);
		addAccountStaff(a, temp);
	}
}

// Ham doc file cho Student
void readAllFileStudent(ifstream& f, logstu& a) {
	while (!f.eof()) {
		SinhVien log;
		readAccountStudent(f, log);
		logstu temp = makeAccountStudent(log);
		addAccountStudent(a, temp);
	}
}

// Doi mat khau cho Staff
void changePasswordStaff(node& a, string tk) {
	node p = a;
	string newpass;
	string checkpass;
	string oldpass;
	while (p != NULL) {
		if (p->account.acc.compare(tk) == 0) {
			int check = 1;
			cin.ignore();
			while (check) {
				cout << "OLD PASSWORK: "; getline(cin, oldpass);
				if (oldpass.compare(p->account.pass) == 0) {
					cout << "NEW PASSWORK: "; getline(cin, newpass);
					while (check) {
						cout << "CONFIRM PASSWORK: "; getline(cin, checkpass);
						if (checkpass.compare(newpass) == 0) {
							check = 0;
							p->account.pass = newpass.substr(0);
						}
						else {
							cout << "INCORRECT!" << endl;
						}
					}
				}
				else {
					cout << "INCORRECT!" << endl;
				}
			}
		}
		p = p->next;
	}
}

// Doi mat khau cho Student
void changePasswordStudent(logstu& a, string tk) {
	logstu p = a;
	string newpass;
	string checkpass;
	string oldpass;
	while (p != NULL) {
		if (p->infor.acc.compare(tk) == 0) {
			int check = 1;
			cin.ignore();
			while (check) {
				cout << "OLD PASSWORK: "; getline(cin, oldpass);
				if (oldpass.compare(p->infor.pass) == 0) {
					cout << "NEW PASSWORK: "; getline(cin, newpass);
					while (check) {
						cout << "CONFIRM PASSWORK: "; getline(cin, checkpass);
						if (checkpass.compare(newpass) == 0) {
							check = 0;
							p->infor.pass = newpass.substr(0);
						}
						else {
							cout << "INCORRECT!" << endl;
						}
					}
				}
				else {
					cout << "INCORRECT!" << endl;
				}
			}
		}
		p = p->next;
	}
}

// Ghi thong tin vao file cho Staff
void ouputFileStaff(ofstream& f, node a) {
	node p = a->next;
	while (p->next != NULL) {
		f << p->account.acc << "," << p->account.pass << "," << p->account.position << "," << p->account.name << "," << p->account.place << endl;
		p = p->next;
	}
	f << p->account.acc << "," << p->account.pass << "," << p->account.position << "," << p->account.name << "," << p->account.place;
}

// Ghi thong tin vao file cho Student
void ouputFileStudent(ofstream& f, logstu a) {
	logstu p = a->next;
	while (p->next != NULL) {
		f << p->infor.acc << "," << p->infor.pass << "," << p->infor.position << "," << p->infor.grade << "," << p->infor.name << "," << p->infor.id << "," << p->infor.clas << "," << p->infor.birthday << "," << p->infor.gender << "," << p->infor.credit << endl;
		p = p->next;
	}
	f << p->infor.acc << "," << p->infor.pass << "," << p->infor.position << "," << p->infor.grade << "," << p->infor.name << "," << p->infor.id << "," << p->infor.clas << "," << p->infor.birthday << "," << p->infor.gender << "," << p->infor.credit;
}

// Ham dang ki tai khoan cho Staff
void registerStaffAccount(node& a, string position) {
	string tk;
	string mk;
	string checkmk;
	string ten;
	string diadiem;
	int check = 1;
	int dem = 0;
	int count = 0;
	for (node p = a->next; p != NULL; p = p->next) {
		dem++;
	}
	cin.ignore();
	cout << "PERSONAL INFORMATION" << endl;
	while (check) {
		cout << "FULL NAME: "; getline(cin, ten);
		if (checkStuName(ten)) {
			cout << endl << "ACCOUNT INFORMATION" << endl;
			while (check) {
				cout << "USER NAME: "; getline(cin, tk);
				for (node t = a->next; t != NULL; t = t->next) {
					if (tk.compare(t->account.acc) == 0) {
						cout << "THIS USER NAME HAS ALREADY EXIST!" << endl;
						break;
					}
					else {
						count++;
					}
				}
				if (count == dem) {
					cout << "PASSWORD: "; getline(cin, mk);
					while (check) {
						cout << "CONFIRM PASSWORD: "; getline(cin, checkmk);
						if (checkmk.compare(mk) == 0) {
							cout << "WORK PLACE: "; getline(cin, diadiem);
							cout << endl << "REGISTER SUCCESSFULLY!" << endl;
							check = 0;
							Staff n;
							n.acc = tk;
							n.pass = mk;
							n.position = position.substr(0);
							n.name = ten;
							n.place = diadiem;
							node temp = makeAccountStaff(n);
							addAccountStaff(a, temp);
						}
						else {
							cout << "INCORRECT!" << endl;
						}
					}
				}
			}
		}
		else {
			cout << "INVALID NAME." << endl;
			check = 1;
		}
	}
}

// Ham dang ki tai khoan cho Student
void registerStudentAccount(logstu& a, list b, base& c, string position) {
	string tk;
	string mk;
	string checkmk;
	string ten;
	string id;
	string grade;
	string cla;
	string birth;
	string gen;
	int check = 1;
	int dem = 0;
	int count = 0;
	for (logstu p = a->next; p != NULL; p = p->next) {
		dem++;
	}
	cin.ignore();
	cout << "PERSONAL INFORMATION" << endl;
	while (check) {
		cout << "STUDENT ID: "; getline(cin, id);
		if (checkStuID(b, id)) {
			while (check) {
				cout << "FULL NAME: "; getline(cin, ten);
				checkName(ten);
				if (checkStuName(ten)) {
					cout << "GRADE: "; getline(cin, grade);
					cout << endl << "==========ACCOUNT INFORMATION==========" << endl;
					while (check) {
						cout << "USER NAME: "; getline(cin, tk);
						for (logstu t = a->next; t != NULL; t = t->next) {
							if (tk.compare(t->infor.acc) == 0) {
								cout << "THIS USER NAME HAS ALREADY EXIST!" << endl;
								break;
							}
							else {
								count++;
							}
						}
						if (count == dem) {
							cout << "PASSWORD: "; getline(cin, mk);
							while (check) {
								cout << "CONFIRM PASSWORD: "; getline(cin, checkmk);
								if (checkmk.compare(mk) == 0) {
									while (check) {
										cout << "CLASS: "; getline(cin, cla);
										if (reClass(c, cla)) {
											while (check) {
												cout << "DAY OF BIRTH (DAY/MONTH/YEAR): "; getline(cin, birth);
												if (checkDay(birth)) {
													while (check) {
														cout << "GENDER (MALE/FEMALE): "; getline(cin, gen);
														checkName(gen);
														if (gen == "Female" || gen == "Male") {
															cout << endl << "REGISTER SUCCESSFULLY!" << endl;
															check = 0;
															SinhVien n;
															n.acc = tk;
															n.pass = mk;
															n.position = position.substr(0);
															n.name = ten;
															n.grade = grade;
															n.id = id;
															n.clas = cla;
															n.birthday = birth;
															n.gender = gen;
															n.credit = "0";
															logstu temp = makeAccountStudent(n);
															addAccountStudent(a, temp);
														}
														else {
															cout << "INVALID" << endl;
															check = 1;
														}
													}
												}
												else {
													cout << "INVALID TIME. " << endl;
													check = 1;
												}
											}
										}
										else {
											cout << "THIS CLASS NOT EXISTS." << endl;
											check = 1;
										}
									}
								}
								else {
									cout << "INCORRECT!" << endl;
								}
							}
						}
					}
				}
				else {
					cout << "INVALID NAME." << endl;
					check = 1;
				}
			}
		}
		else {
			cout << "THIS ID ALREADY EXIST." << endl;
			check = 1;
		}
	}
}

// Lam rong Node
void clearNode(node& a) {
	node p = a;
	while (p != NULL) {
		node temp = p;
		p = p->next;
		delete temp;
	}
	a = NULL;
}

// Lam rong Login
void clearLogin(logstu& a) {
	logstu p = a;
	while (p != NULL) {
		logstu temp = p;
		p = p->next;
		delete temp;
	}
	a = NULL;
}

/*------------------------------------------------------------------------------------*/

//												HAM DANH CHO STAFF

//								===============THAO TAC VOI DANH SACH SINH VIEN=============

// Ham tao List moi
list makeList(sv infor) {
	list temp = new List();
	temp->student = infor;
	temp->next = NULL;
	return temp;
}

// Kiem tra List rong
bool listEmpty(list& a) {
	return a == NULL;
}

// Ham doc thong tin sinh vien
void readStudent(ifstream& f, sv& infor) {
	getline(f, infor.course, ',');
	getline(f, infor.cid, ',');
	getline(f, infor.stuclass, ',');
	getline(f, infor.id, ',');
	getline(f, infor.fname, ',');
	getline(f, infor.lname, ',');
	getline(f, infor.gender, ',');
	getline(f, infor.birth, ',');
	getline(f, infor.scid, '\n');
}

// Them thong tin vao list
void addInforStudent(list& a, list temp) {
	if (listEmpty(a)) {
		a = temp;
	}
	else {
		list p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
}

// Doc file va ghi vao danh sach
void readFileStudent(ifstream& f, list& a) {
	while (!f.eof()) {
		sv infor;
		readStudent(f, infor);
		list temp = makeList(infor);
		addInforStudent(a, temp);
	}
}

// Lam rong List
void clearList(list& a) {
	list p = a;
	while (p != NULL) {
		list temp = p;
		p = p->next;
		delete temp;
	}
	a = NULL;
}

// Ham kiem tra trung ma so sinh vien
bool checkStuID(list a, string id) {
	int dem = 0;
	for (list p = a; p != NULL; p = p->next) {
		if (p->student.id.compare(id) == 0) {
			dem++;
		}
	}
	if (dem > 0) {
		return false;
	}
	else {
		return true;
	}
}

// Ham kiem tra trung can cuoc cong dan
bool checkSocialId(list a, string id) {
	int dem = 0;
	for (list p = a; p != NULL; p = p->next) {
		if (p->student.scid.compare(id) == 0) {
			dem++;
		}
	}
	if (dem > 0) {
		return false;
	}
	else {
		return true;
	}
}

// Kiem tra ten hop le
bool checkStuName(string name) {
	int dem = 0;
	for (int i = 0; i < name.length(); i++) {
		if(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z' || name[i] == ' ') {}
		else {
			dem++;
		}
	}
	if (dem > 0) {
		return false;
	}
	else {
		return true;
	}
}

// Ham hieu chinh ten
void checkName(string& name) {
	if (name[0] >= 'a' && name[0] <= 'z') {
		name[0] = (char)((int)name[0] - 32);
	}
	for (int i = 1; i < name.length(); i++) {
		if (name[i - 1] == ' ' && name[i] != ' ') {
			if (name[i] >= 'a' && name[i] <= 'z') {
				name[i] = char((int)name[i] - 32);
			}
		}
		if (name[i - 1] != ' ' && name[i] != ' ') {
			if (name[i] >= 'A' && name[i] < 'Z') {
				name[i] = char((int)name[i] + 32);
			}
		}
	}
}

// Ham check lop hoc cua sinh vien
bool checkStuInClass(base a, string str) {
	int dem = 0;
	int count = 0;
	for (base t = a; t != NULL; t = t->next) {
		dem++;
	}
	for (base p = a; p != NULL; p = p->next) {
		if (p->data.name.compare(str) == 0) {
			return true;
		}
		else {
			count++;
		}
	}
	if (count == dem) {
		return false;
	}
}

// Them mot sinh vien vao lop hoc
void addStudentInClass(list& a, string str) {
	sv temp;
	temp.stuclass = str;
	int check = 1;
	cin.ignore();
	while (check) {
		cout << "STUDENT ID: "; getline(cin, temp.id);
		if (checkStuID(a, temp.id)) {
			while (check) {
				cout << "FIRST NAME: "; getline(cin, temp.fname);
				checkName(temp.fname);
				if (checkStuName(temp.fname)) {
					while (check) {
						cout << "LAST NAME: "; getline(cin, temp.lname);
						checkName(temp.lname);
						if (checkStuName(temp.lname)) {
							while (check) {
								cout << "GENDER (Male/Female): "; getline(cin, temp.gender);
								checkName(temp.gender);
								if (temp.gender == "Male" || temp.gender == "Female") {
									cout << "DATE OF BIRTH (Ex: 1/1/2004): "; getline(cin, temp.birth);
									if (checkDay(temp.birth)) {
										while (check) {
											cout << "SOCIAL ID: "; getline(cin, temp.scid);
											if (checkSocialId(a, temp.scid)) {
												check = 0;
												list tmp = makeList(temp);
												addInforStudent(a, tmp);
												cout << endl << "ADD STUDENT SUCCESSFULLY!" << endl;
											}
											else {
												check = 1;
												cout << "THIS ID ALREADY EXISTS." << endl;
											}
										}
									}
									else {
										check = 1;
										cout << "INVALID DAY." << endl;
									}
								}
								else {
									check = 1;
									cout << "INVALID GENDER." << endl;
								}
							}
						}
						else {
							check = 1;
							cout << "INVALID NAME." << endl;
						}
					}
				}
				else {
					check = 1;
					cout << "INVALID NAME." << endl;
				}
			}
		}
		else {
			check = 1;
			cout << "THIS ID ALREADY EXISTS." << endl;
		}
	}
}

// Them sinh vien tu file
void addStudentFromFile() {



}   // (Chua hoan thanh)

// Ghi List vao File
void outputStudentinFile(ofstream& f, list a) {
	list p = a->next;
	while (p->next != NULL) {
		f << p->student.course << "," << p->student.cid << "," << p->student.stuclass << "," << p->student.id << "," << p->student.fname << "," << p->student.lname << "," << p->student.gender << "," << p->student.birth << "," << p->student.scid << endl;
		p = p->next;
	}
	f << p->student.course << "," << p->student.cid << "," << p->student.stuclass << "," << p->student.id << "," << p->student.fname << "," << p->student.lname << "," << p->student.gender << "," << p->student.birth << "," << p->student.scid;
}

// Them mot sinh vien vao khoa hoc
void addStudentToCourse(list& a, base b, result& c, string str, string id) {
	sv temp;
	Score tmp;
	temp.course = str;
	temp.cid = id;
	tmp.course = str;
	tmp.cid = id;
	int check = 1;
	cin.ignore();
	while (check) {
		cout << "STUDENT ID: "; getline(cin, temp.id);
		if (checkStuID(a, temp.id)) {
			tmp.id = temp.id;
			while (check) {
				cout << "FIRST NAME: "; getline(cin, temp.fname);
				checkName(temp.fname);
				if (checkStuName(temp.fname)) {
					tmp.fname = temp.fname;
					while (check) {
						cout << "LAST NAME: "; getline(cin, temp.lname);
						checkName(temp.lname);
						if (checkStuName(temp.lname)) {
							tmp.lname = temp.lname;
							while (check) {
								cout << "CLASS: "; getline(cin, temp.stuclass);
								if (checkStuInClass(b, temp.stuclass)) {
									while (check) {
										cout << "GENDER (Male/Female): "; getline(cin, temp.gender);
										checkName(temp.gender);
										if (temp.gender == "Male" || temp.gender == "Female") {
											cout << "DATE OF BIRTH (Ex: 1/1/2004): "; getline(cin, temp.birth);
											if (checkDay(temp.birth)) {
												while (check) {
													cout << "SOCIAL ID: "; getline(cin, temp.scid);
													if (checkSocialId(a, temp.scid)) {
														check = 0;
														list student = makeList(temp);
														result kq = makeResult(tmp);
														addInforStudent(a, student);
														addInResult(c, kq);
														cout << endl << "ADD STUDENT SUCCESSFULLY!" << endl;
													}
													else {
														check = 1;
														cout << "THIS ID ALREADY EXISTS." << endl;
													}
												}
											}
											else {
												check = 1;
												cout << "INVALID DAY." << endl;
											}
										}
										else {
											check = 1;
											cout << "INVALID GENDER." << endl;
										}
									}
								}
								else {
									check = 1;
									cout << "INVALID CLASS." << endl;
								}
							}
						}
						else {
							check = 1;
							cout << "INVALID NAME." << endl;
						}
					}
				}
				else {
					check = 1;
					cout << "INVALID NAME." << endl;
				}
			}
		}
		else {
			check = 1;
			cout << "THIS ID ALREADY EXISTS." << endl;
		}
	}
}

// Xoa sinh vien ra khoi khoa hoc
void removeStudentFromCourse(list& a, string str, string cid, string id) {
	if (a->student.course.compare(str) == 0 && a->student.cid.compare(cid) == 0 && a->student.id.compare(id) == 0) {
		a = a->next;
	}
	else {
		list truoc = a;
		list sau = a->next;
		while (sau->next != NULL) {
			if (sau->student.course.compare(str) == 0 && sau->student.cid.compare(cid) == 0 && sau->student.id.compare(id) == 0) {
				truoc->next = sau->next;
				sau = sau->next;
			}
			else {
				truoc = sau;
				sau = sau->next;
			}
		}
	}
}

//								============THAO TAC VOI DANH SACH LOP HOC===============

// Ham tao Base moi
base makeBase(Class infor) {
	base temp = new Base();
	temp->data = infor;
	temp->next = NULL;
	return temp;
}

// Kiem tra Base rong
bool baseEmpty(base& a) {
	return a == NULL;
}

// Them thong tin vao Base
void addInClass(base& a, base temp) {
	if (baseEmpty(a)) {
		a = temp;
	}
	else {
		base p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
}

// Ham sap xep tang dan danh sach
void sortClass(base& a) {
	base p = a;
	for (base t = p->next; t != NULL; t = t->next) {
		for (base q = t->next; q != NULL; q = q->next) {
			if (t->data.name.compare(q->data.name) > 0) {
				swap(t->data, q->data);
			}
		}
	}
}

// Ham doc thong tin lop hoc
void readClass(ifstream& f, Class& infor) {
	getline(f, infor.name, ',');
	getline(f, infor.scyear, ',');
	getline(f, infor.max, ',');
	getline(f, infor.number, '\n');
}

// Doc file va ghi vao danh sach
void readFileClass(ifstream& f, base& a) {
	while (!f.eof()) {
		Class infor;
		readClass(f, infor);
		base temp = makeBase(infor);
		addInClass(a, temp);
	}
}

// In thong tin lop hoc ra man hinh
void outputClass(base a) {
	if (a == NULL) {
		cout << "NOTHING!" << endl;
	}
	else {
		cout << setw(40) << "=====CLASS=====" << endl;
		cout << endl;
		cout << "NO" << setw(14) << "CLASS" << setw(22) << "SCHOOL YEAR" << setw(27) << "STUDENT IN CLASS" << endl;
		int stt = 1;
		for (base t = a->next; t != NULL; t = t->next) {
			cout << left << setw(11) << stt << setw(17) << t->data.name << setw(29) << t->data.scyear << t->data.number << "/" << t->data.max << endl;
			stt++;
		}
		cout << right;
	}
}

// Tim class
bool reClass(base a, string str) {
	string temp;
	int dem = 0;
	int count = 0;
	for (base t = a; t != NULL; t = t->next) {
		dem++;
	}
	for (base p = a; p != NULL; p = p->next) {
		if (p->data.name.compare(str) == 0) {
			return true;
		}
		else {
			count++;
		}
	}
	if (count == dem) {
		return false;
	}
}

// Kiem tra sinh vien nam nhat
bool firstYearStu(base a, string str) {
	for (base p = a; p != NULL; p = p->next) {
		if (p->data.name.compare(str) == 0) {
			if (p->data.scyear == "2022-2023") {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

// Check ten lop 
int checkClass(string str, base a) {
	int check = 0;
	for (base p = a->next; p != NULL; p = p->next) {
		if (str.compare(p->data.name) == 0) {
			check++;
		}
	}
	return check;
}

// Ghi noi dung cua Base vao File
void outputFileClass(ofstream& f, base a) {
	base p = a;
	while (p->next != NULL) {
		f << p->data.name << "," << p->data.scyear << "," << p->data.max << "," << p->data.number << endl;
		p = p->next;
	}
	f << p->data.name << "," << p->data.scyear << "," << p->data.number;
}

// Them lop hoc vao Base
int addClass(base& a, string str, string name) {
	Class add;
	int check;
	add.scyear = str;
	add.name = name;
	add.number = "0";
	if (checkClass(add.name, a) == 0) {
		cout << "MAX STUDENT: "; getline(cin, add.max);
		base temp = makeBase(add);
		addInClass(a, temp);
		check = 1;
	}
	else {
		check = 0;
	}
	return check;
}

// In thong tin sinh vien cua lop
void outputStudentofClass(list a, string b) {
	int stt = 1;
	int count = 0;
	for (list t = a; t != NULL; t = t->next) {
		string temp = t->student.stuclass;
		if (temp.compare(b) == 0) {
			count++;
		}
	}
	if (count > 0) {
		cout << setw(40) << "==========STUDENT IN CLASS " << b << "==========" << endl;
		cout << endl;
		cout << "NO" << setw(5) << "ID" << setw(19) << "FIRST NAME" << setw(15) << "LAST NAME" << setw(13) << "GENDER" << setw(20) << "DATE OF BIRTH" << endl;
		for (list p = a; p != NULL; p = p->next) {
			string temp = p->student.stuclass;
			if (temp.compare(b) == 0) {
				cout << left << setw(5) << stt << setw(15) << p->student.id << setw(12) << p->student.fname << setw(16) << p->student.lname << setw(16) << p->student.gender << p->student.birth << endl;
				stt++;
			}
		}
		cout << right;
	}
	else {
		cout << endl << "THIS CLASS HAS NO STUDENT." << endl;
	}
}

// Xuat thong tin khoa hoc cua mot lop
void outputCourseofClass(board a, string b) {
	int stt = 1;
	int count = 0;
	for (board t = a; t != NULL; t = t->next) {
		string temp = t->course.clas;
		if (temp.compare(b) == 0) {
			count++;
		}
	}
	if (count > 0) {
		cout << setw(50) << "==========COURSE OF CLASS " << b << "==========" << endl;
		cout << endl;
		cout << "NO" << setw(15) << "COURSE ID" << setw(18) << "COURSE NAME" << setw(24) << "NUMBER OF CREDITS" << setw(15) << "TEACHER" << setw(25) << "ROOM" << endl;
		for (board p = a; p != NULL; p = p->next) {
			string temp = p->course.clas;
			if (temp.compare(b) == 0) {
				cout << left << setw(11) << stt << setw(15) << p->course.id << setw(24) << p->course.name << setw(17) << p->course.credit << setw(28) << p->course.lecturer << p->course.room << endl;
				stt++;
			}
		}
		cout << right;
	}
	else {
		cout << endl << "THIS CLASS HAS NO COURSE." << endl;
	}
}

// Lam rong Base
void clearBase(base& a) {
	base p = a;
	while (p != NULL) {
		base temp = p;
		p = p->next;
		delete temp;
	}
	a = NULL;
}

//								============THAO TAC VOI DANH SACH KHOA HOC==============

// Ham tao Board moi
board makeBoard(Course infor) {
	board temp = new Board();
	temp->course = infor;
	temp->next = NULL;
	return temp;
}

// Kiem tra Board rong
bool boardEmpty(board& a) {
	return a == NULL;
}

// Ham doc thong tin khoa hoc
void readCourse(ifstream& f, Course& infor) {
	getline(f, infor.name, ',');
	getline(f, infor.id, ',');
	getline(f, infor.credit, ',');
	getline(f, infor.clas, ',');
	getline(f, infor.daystart, ',');
	getline(f, infor.dayend, ',');
	getline(f, infor.timestart, ',');
	getline(f, infor.timeend, ',');
	getline(f, infor.day, ',');
	getline(f, infor.number, ',');
	getline(f, infor.lecturer, ',');
	getline(f, infor.room, '\n');
}

// Them thong tin vao Board
void addInCourse(board& a, board temp) {
	if (boardEmpty(a)) {
		a = temp;
	}
	else {
		board p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
}

// Doc file va ghi vao danh sach
void readFileCourse(ifstream& f, board& a) {
	while (!f.eof()) {
		Course infor;
		readCourse(f, infor);
		board temp = makeBoard(infor);
		addInCourse(a, temp);
	}
}

// Xuat thong tin khoa hoc
void outputCourse(board a) {
	cout << "NO" << setw(14) << "COURSE ID" << setw(12) << "CREDITS" << setw(10) << "CLASS" << setw(18) << "COURSE NAME" << setw(16) << "DAY START" << setw(13) << "DAY END" << setw(17) << "TIME START" << setw(11) << "TIME END" << setw(16) << "DAY OF WEEK" << setw(16) << "MAX STUDENT" << setw(12) << "TEACHER" << setw(21) << "ROOM" << endl;
	int stt = 1;
	for (board t = a->next; t != NULL; t = t->next) {
		cout << left << setw(10) << stt << setw(14) << t->course.id << setw(9) << t->course.credit << setw(12) << t->course.clas << setw(18) << t->course.name << setw(15) << t->course.daystart << setw(17) << t->course.dayend << setw(11) << t->course.timestart << setw(14) << t->course.timeend << setw(18) << t->course.day << setw(12) << t->course.number << setw(24) << t->course.lecturer << t->course.room << endl;
		stt++;
	}
	cout << right << endl;
}

// Ghi noi dung cua Board vao File
void outputFileCourse(ofstream& f, board a) {
	board p = a;
	while (p->next != NULL) {
		f << p->course.name << "," << p->course.id << "," << p->course.credit << "," << p->course.clas << "," << p->course.daystart << "," << p->course.dayend << "," << p->course.timestart << "," << p->course.timeend << "," << p->course.day << "," << p->course.number << "," << p->course.lecturer << "," << p->course.room << endl;
		p = p->next;
	}
	f << p->course.name << "," << p->course.id << "," << p->course.credit << "," << p->course.clas << "," << p->course.daystart << "," << p->course.dayend << "," << p->course.timestart << "," << p->course.timeend << "," << p->course.day << "," << p->course.number << "," << p->course.lecturer << "," << p->course.room;
}

// Kiem tra id khoa hoc
bool checkIDCourse(string id, board a) {
	int dem = 0;
	for (board p = a; p != NULL; p = p->next) {
		if (id.compare(p->course.id) == 0) {
			dem++;
		}
	}
	if (dem == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Kiem tra ngay thang
bool check(int ngay, int thang, int nam) {
	if(thang <= 0 || thang > 12 || nam <= 0) {
		return false;
	}
	else {
		if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
			if (ngay > 0 && ngay <= 31) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (thang == 2) {
				if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) {
					if (ngay > 0 && ngay <= 29) {
						return true;
					}
					else {
						return false;
					}
				}
				else {
					if (ngay > 0 && ngay <= 28) {
						return true;
					}
					else {
						return false;
					}
				}
			}
			else {
				if (ngay > 0 && ngay < 30) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}

// Ham kiem tra ngay thang
bool checkDay(string day) {					
	int ngay, thang, nam;
	string x1, x2, x3;
	if (day[1] == '/') {
		if (day[3] == '/') {
			x1 = day.substr(0);
			x2 = day.substr(2);
			x3 = day.substr(4, day.length());
		}
		else {
			x1 = day.substr(0);
			x2 = day.substr(2, 3);
			x3 = day.substr(5, day.length());
		}
	}
	else {
		if (day[3] == '/') {
			x1 = day.substr(0, 1);
			x2 = day.substr(3);
			x3 = day.substr(5, day.length());
		}
		else {
			x1 = day.substr(0, 1);
			x2 = day.substr(3, 4);
			x3 = day.substr(6, day.length());
		}
	}
	ngay = stoi(x1);
	thang = stoi(x2);
	nam = stoi(x3);
	if (check(ngay, thang, nam)) {
		return true;
	}
	else {
		return false;
	}
}

// Ham kiem tra thoi gian
bool checkTime(string time) {
	string x1, x2;
	if (time[1] == ':') {
		x1 = time.substr(0);
		x2 = time.substr(2, time.length());
	}
	else {
		x1 = time.substr(0, 1);
		x2 = time.substr(3, time.length());
	}
	if (stoi(x1) >= 0 && stoi(x1) <= 24) {
		if (stoi(x2) >= 0 && stoi(x2) <= 59) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

// Ham kiem tra ngay trong tuan
bool checkWeek(string day) {
	if (day == "Monday" || day == "Tuesday" || day == "Wednesday" || day == "Thursday" || day == "Friday" || day == "Saturday" || day == "Sunday") {
		return true;
	}
	else {
		return false;
	}
}

// Them khoa hoc moi vao Board
void addCourse(board& a) {
	Course add;
	add.number = "50";
	int check = 1;
	cin.ignore();
	while (check) {
		cout << "COURSE ID: "; getline(cin, add.id);
		if (checkIDCourse(add.id, a)) {
			cout << "COURSE NAME: "; getline(cin, add.name);
			while (check) {
				cout << "DAY START (DAY/MONTH/YEAR): "; getline(cin, add.daystart);
				if (checkDay(add.daystart)) {
					while (check) {
						cout << "DAY END (DAY/MONTH/YEAR): "; getline(cin, add.dayend);
						if (checkDay(add.dayend)) {
							while (check) {
								cout << "TIME START: "; getline(cin, add.timestart);
								if (checkTime(add.timestart)) {
									while (check) {
										cout << "TIME END: "; getline(cin, add.timeend);
										if (checkTime(add.timeend)) {
											while (check) {
												cout << "DAY OF WEEK (Monday, Tuesday, ...): "; getline(cin, add.day);
												if (!checkWeek(add.day)) {
													check = 1;
													cout << "INVALID DAY." << endl;
												}
												if (checkWeek(add.day)) {
													cout << "NUMBER OF CREDITS: "; getline(cin, add.credit);
													cout << "CLASS: "; getline(cin, add.clas);
													cout << "TEACHER: "; getline(cin, add.lecturer);
													cout << "ROOM: "; getline(cin, add.room);
													board temp = makeBoard(add);
													addInCourse(a, temp);
													check = 0;
													cout << "SUCCESFULLY!" << endl;
												}
											}
										}
										else {
											check = 1;
											cout << "INVALID TIME." << endl;
										}
									}
								}
								else {
									check = 1;
									cout << "INVALID TIME." << endl;
								}
							}
						}
						else {
							check = 1;
							cout << "INVALID TIME." << endl;
						}
					}
				}
				else {
					check = 1;
					cout << "INVALID TIME." << endl;
				}
			}
		}
		else {
			check = 1;
			cout << "ID ALREADY EXISTS." << endl;
		}
	}
	cout << "ADD NEW COURSE SUCCESSFULLY!" << endl;
}

// Lam rong Board
void clearBoard(board& a) {
	board p = a;
	while (p != NULL) {
		board temp = p;
		p = p->next;
		delete temp;
	}
	a = NULL;
}

// Xoa khoa hoc
void deleteCourse(board& a, string str) {
	if (boardEmpty(a)) {
		cout << "THERE'S NO COURSE." << endl;
	}
	else {
		if (a->course.name.compare(str) == 0) {
			a = a->next;
		}
		else {
			board truoc = a;
			board sau = a->next;
			while (sau != NULL) {
				if (sau->course.name.compare(str) == 0) {
					truoc->next = sau->next;
					sau = sau->next;
				}
				else {
					truoc = sau;
					sau = sau->next;
				}
			}
		}
		cout << "REMOVE COURSE SUCCESSFULLY." << endl;
	}
}

// Check ten khoa hoc
bool reCourse(board a, string str, string id) {
	int dem = 0;
	int count = 0;
	for (board t = a; t != NULL; t = t->next) {
		dem++;
	}
	for (board p = a; p != NULL; p = p->next) {
		if (p->course.name.compare(str) == 0 && p->course.id.compare(id) == 0) {
			return true;
		}
		else {
			count++;
		}
	}
	if (count == dem) {
		return false;
	}
}

//								============THAO TAC VOI DIEM CUA SINH VIEN==============

// Ham tao Result moi
result makeResult(Score infor) {
	result temp = new Result();
	temp->mark = infor;
	temp->next = NULL;
	return temp;
}

// Kiem tra Result rong
bool resultEmpty(result& a) {
	return a == NULL;
}

// Ham doc diem sinh vien
void readScore(ifstream& f, Score& infor) {
	getline(f, infor.course, ',');
	getline(f, infor.cid, ',');
	getline(f, infor.id, ',');
	getline(f, infor.fname, ',');
	getline(f, infor.lname, ',');
	getline(f, infor.omark, ',');
	getline(f, infor.mmark, ',');
	getline(f, infor.fmark, '\n');
	float a = atof(infor.omark.c_str()) * 0.2 + atof(infor.mmark.c_str()) * 0.3 + atof(infor.fmark.c_str()) * 0.5;
	infor.total = to_string(a);
}

// Them thong tin vao Result
void addInResult(result& a, result temp) {
	if (resultEmpty(a)) {
		a = temp;
	}
	else {
		result p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
}

// Doc file va ghi vao danh sach
void readFileScore(ifstream& f, result& a) {
	while (!f.eof()) {
		Score infor;
		readScore(f, infor);
		result temp = makeResult(infor);
		addInResult(a, temp);
	}
}

// Xuat thong tin diem sinh vien
void outputScore(result a, string str, string id) {
	cout << setw(80) << "====================RESULT====================" << endl;
	cout << endl;
	cout << "NO" << setw(15) << "FIRST NAME" << setw(16) << "LAST NAME" << setw(24) << "OTHER MARK (x0.2)" << setw(24) << "MIDTERM MARK (x0.3)" << setw(24) << "FINAL MARK (X0.5)" << setw(20) << "TOTAL MARK" << endl;
	int stt = 1;
	int dem = 0;
	int count = 0;
	for (result t = a->next; t != NULL; t = t->next) {
		count++;
	}
	for (result p = a->next; p != NULL; p = p->next) {
		if (p->mark.cid.compare(id) == 0) {
			cout << fixed << setprecision(2) << left << setw(11) << stt << setw(13) << p->mark.fname << setw(22) << p->mark.lname << setw(22) << atof(p->mark.omark.c_str()) << setw(26) << atof(p->mark.mmark.c_str()) << setw(25) << atof(p->mark.fmark.c_str()) << atof(p->mark.total.c_str()) << endl;
			stt++;
		}
		else {
			dem++;
		}
	}
	if (dem == count) {
		cout << "THIS COURSE HAS NO STUDENT." << endl;
	}
	cout << right << endl;
}

// Ham kiem tra sinh vien co trong khoa hoc hay khong
bool checkStuInCourse(result a, string str, string id, string stuid) {
	int dem = 0;
	int count = 0;
	for (result t = a; t != NULL; t = t->next) {
		dem++;
	}
	for (result p = a; p != NULL; p = p->next) {
		if (p->mark.course.compare(str) == 0 && p->mark.cid.compare(id) == 0 && p->mark.id.compare(stuid) == 0) {
			return true;
		}
		else {
			count++;
		}
	}
	if (count == dem) {
		return false;
	}
}

// Kiem tra diem
bool checkScore(string mark) {
	float b = atof(mark.c_str());
	if (b >= 0 && b <= 10) {
		return true;
	}
	else {
		return false;
	}
}

// Cap nhat diem cho sinh vien
void updateStudentScore(result& a, string str, string id, string stuid) {
	string mark1, mark2, mark3;
	cout << "ENTER STUDENT SCORE: " << endl;
	int check = 1;
	while (check) {
		cout << "\tOTHER MARK: "; getline(cin, mark1);
		if (checkScore(mark1)) {
			while (check) {
				cout << "\tMIDTERM MARK: "; getline(cin, mark2);
				if (checkScore(mark2)) {
					while (check) {
						cout << "\tFINAL MARK: "; getline(cin, mark3);
						if (checkScore(mark3)) {
							cout << "UPDATE SCORE SUCCESSFULLY." << endl;
							check = 0;
						}
						else {
							cout << "SCORE INVALID." << endl;
							cout << endl;
							check = 1;
						}
					}
				}
				else {
					cout << "SCORE INVALID." << endl;
					check = 1;
				}
			}
		}
		else {
			cout << "SCORE INVALID." << endl;
			check = 1;
		}
	}
	for (result p = a; p != NULL; p = p->next) {
		if (p->mark.course.compare(str) == 0 && p->mark.cid.compare(id) == 0 && p->mark.id.compare(stuid) == 0) {
			p->mark.omark = mark1;
			p->mark.mmark = mark2;
			p->mark.fmark = mark3;
		}
	}
}

// Ghi thong tin Result vao File
void outputFileScore(ofstream& f, result a) {
	result p = a;
	while (p->next != NULL) {
		f << p->mark.course << "," << p->mark.cid << "," << p->mark.id << "," << p->mark.fname << "," << p->mark.lname << "," << p->mark.omark << "," << p->mark.mmark << "," << p->mark.fmark << endl;
		p = p->next;
	}
	f << p->mark.course << "," << p->mark.cid << "," << p->mark.id << "," << p->mark.fname << "," << p->mark.lname << "," << p->mark.omark << "," << p->mark.mmark << "," << p->mark.fmark;
}

// Lam rong Result
void clearResult(result& a) {
	result p = a;
	while (p != NULL) {
		result temp = p;
		p = p->next;
		delete temp;
	}
	a = NULL;
}

// Xoa sinh vien ra khoi khoa hoc
void removeStudent(result& a, string str, string cid, string id) {
	if (a->mark.course.compare(str) == 0 && a->mark.cid.compare(cid) == 0 && a->mark.id.compare(id) == 0) {
		a = a->next;
	}
	else {
		result truoc = a;
		result sau = a->next;
		while (sau->next != NULL) {
			if (sau->mark.course.compare(str) == 0 && sau->mark.cid.compare(cid) == 0 && sau->mark.id.compare(id) == 0) {
				truoc->next = sau->next;
				sau = sau->next;
			}
			else {
				truoc = sau;
				sau = sau->next;
			}
		}
	}
}


//												HAM DANH CHO STUDENT

// Xem danh sach khoa hoc
void viewListCourse(logstu a, board b, list c, string tk) {
	string fid;
	int stt = 1;
	int dem = 0;
	for (logstu p = a; p != NULL; p = p->next) {
		if (p->infor.acc.compare(tk) == 0) {
			fid = p->infor.id;
			break;
		}
	}
	for (list t = c; t != NULL; t = t->next) {
		if (t->student.id.compare(fid) == 0) {
			for (board k = b; k != NULL; k = k->next) {
				if (t->student.course.compare(k->course.name) == 0 && t->student.cid.compare(k->course.id) == 0) {
					dem++;
				}
			}
		}
	}
	if (dem == 0) {
		cout << "YOU HAVE NO COURSE." << endl;
	}
	else {
		cout << setw(60) << "==========YOUR COURSE==========" << endl;
		cout << "NO" << setw(14) << "COURSE ID" << setw(12) << "CREDITS" << setw(10) << "CLASS" << setw(18) << "COURSE NAME" << setw(16) << "DAY START" << setw(13) << "DAY END" << setw(17) << "TIME START" << setw(15) << "TIME END" << setw(16) << "DAY OF WEEK" << setw(17) << "TEACHER" << setw(20) << "ROOM" << endl;
		for (list t = c; t != NULL; t = t->next) {
			if (t->student.id.compare(fid) == 0) {
				for (board q = b; q != NULL; q = q->next) {
					if (t->student.course.compare(q->course.name) == 0 && t->student.cid.compare(q->course.id) == 0) {
						cout << left << setw(10) << stt << setw(14) << q->course.id << setw(9) << q->course.credit << setw(12) << q->course.clas << setw(18) << q->course.name << setw(15) << q->course.daystart << setw(17) << q->course.dayend << setw(16) << q->course.timestart << setw(14) << q->course.timeend << setw(15) << q->course.day << setw(26) << q->course.lecturer << q->course.room << endl;
					}
				}
				cout << right;
			}
		}
	}
}

// Xem diem trong khoa hoc
void viewScore(logstu a, result b, string tk) {
	string fid;
	int dem = 0;
	int stt = 1;
	for (logstu p = a; p != NULL; p = p->next) {
		if (p->infor.acc.compare(tk) == 0) {
			fid = p->infor.id;
			break;
		}
	}
	for (result t = b; t != NULL; t = t->next) {
		if (t->mark.id.compare(fid) == 0) {
			dem++;
		}
	}
	if (dem == 0) {
		cout << "YOU HAVE NO COURSE." << endl;
		cout << endl;
	}
	else {
		cout << setw(60) << "==========YOUR SCORE==========" << endl;
		cout << "NO" << setw(15) << "COURSE" << setw(18) << "COURSE ID" << setw(20) << "OTHER MARK" << setw(20) << "MIDTERM MARK" << setw(20) << "FINAL MARK" << setw(20) << "TOTAL MARK" << endl;
		for (result t = b; t != NULL; t = t->next) {
			if (t->mark.id.compare(fid) == 0) {
				cout << fixed << setprecision(2) << left << setw(11) << stt << setw(18) << t->mark.course << setw(19) << t->mark.cid << setw(19) << atof(t->mark.omark.c_str()) << setw(21) << atof(t->mark.mmark.c_str()) << setw(20) << atof(t->mark.fmark.c_str()) << atof(t->mark.total.c_str()) << endl;
				stt++;
			}
		}
		cout << right;
	}
}