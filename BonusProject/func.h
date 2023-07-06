#include<iostream>

using namespace std;

//------------------------------------------------------------------------------------------------------------------------

// Ham su dung trong Login

void readAccountStaff(ifstream& f, Staff& log);									// Ham doc thong tin tai khoan tu File (Staff)
void readAccountStudent(ifstream& f, SinhVien& log);							// Ham doc thong tin tai khoan tu File (Student)
int loginStaff(ifstream& f, string tk, string mk);								// Ham kiem tra tai khoan khi dang nhap (Staff)
int loginStudent(ifstream& f, string tk, string mk);							// Ham kiem tra tai khoan khi dang nhap (Student)
void outputStaffInformation(Staff log);											// Ham xuat thong tin Staff ra man hinh
void outputStudentInformation(SinhVien log);									// Ham xuat thong tin Student ra man hinh
void staffInformation(ifstream& f, string tk, string mk);						// Ham doc thong tin tai khoan tu File (Staff)
void studentInformation(ifstream& f, string tk, string mk);						// Ham doc thong tin tai khoan tu File (Student)
node makeAccountStaff(Staff x);													// Ham cap phat node tam (Staff)
logstu makeAccountStudent(SinhVien x);											// Ham cap phat node tam (Staff)
bool nodeEmpty(node a);															// Ham kiem tra danh sach rong (Staff)
bool loginEmpty(logstu a);														// Ham kiem tra danh sach rong (Student)
void addAccountStaff(node& a, node temp);										// Ham them thong tin tai khoan vao danh sach (Staff)
void addAccountStudent(logstu& a, logstu temp);									// Ham them thong tin tai khoan vao danh sach (Student)
void readAllFileStaff(ifstream& f, node& a);									// Ham doc toan bo File (Staff)
void readAllFileStudent(ifstream& f, logstu& a);								// Ham doc toan bo File (Student)
void changePasswordStaff(node& a, string tk);									// Ham thay doi mat khau (Staff)
void changePasswordStudent(logstu& a, string tk);								// Ham thay doi mat khau (Student)
void ouputFileStaff(ofstream& f, node a);										// Ham ghi thong tin Staff vao File
void ouputFileStudent(ofstream& f, logstu a);									// Ham ghi thong tin Student vao File
void registerStaffAccount(node& a, string position);							// Ham dang ki tai khoan (Staff)
void registerStudentAccount(logstu& a, list b, base& c, string position);		// Ham dang ki tai khoan (Student)
void clearNode(node& a);														// Lam rong danh sach
void clearLogin(logstu& a);														// Lam rong danh sach

// -----------------------------------------------------------------------------------------------------------------------

// Ham su dung trong phan con lai

//								DANH CHO STAFF

//					============STUDENT=============
list makeList(sv infor);																	// Ham cap phat List moi		
bool listEmpty(list& a);																	// Kiem tra List rong	
void readStudent(ifstream& f, sv& infor);													// Ham doc thong tin sinh vien
void addInforStudent(list& a, list temp);													// Them thong tin vao list
void readFileStudent(ifstream& f, list& a);													// Doc file va ghi vao danh sach								
void outputStudentinFile(ofstream& f, list a);												// Ghi List vao File
void clearList(list& a);																	// Lam rong List
bool checkStuID(list a, string id);															// Ham kiem tra trung ma so sinh vien
bool checkSocialId(list a, string id);														// Ham kiem tra trung can cuoc cong dan
bool checkStuName(string name);																// Kiem tra ten hop le
void checkName(string& a);																	// Ham hieu chinh ten
bool checkStuInClass(base a, string str);													// Ham check lop hoc cua sinh vien		
void addStudentInClass(list& a, base& b, string str);										// Them mot sinh vien vao lop hoc
void addStudentToCourse(list& a, base b, result& c, string str, string id);					// Them mot sinh vien vao khoa hoc
void removeStudentFromCourse(list& a, string str, string cid, string id);					// Xoa sinh vien ra khoi khoa hoc

//					============CLASS============
base makeBase(Class infor);																	// Ham cap phat Base moi
bool baseEmpty(base& a);																	// Kiem tra Base rong
void addInClass(base& a, base temp);														// Them thong tin vao Base
void readClass(ifstream& f, Class& infor);													// Ham doc thong tin lop hoc		
void readFileClass(ifstream& f, base& a);													// Doc file lop hoc va ghi vao danh sach										
void sortClass(base& a);																	// Ham sap xep tang dan danh sach
void outputClass(base a);																	// In thong tin lop hoc ra man hinh	
int checkClass(string str, base a);															// Check ten lop 
void outputFileClass(ofstream& f, base a);													// Ghi noi dung cua Base vao File
int addClass(base& a, string str, string name);												// Them lop hoc vao Base
void clearBase(base& a);																	// Lam rong Base
void outputStudentofClass(list a, string b);												// Xuat thong tin sinh vien cua lop
void outputCourseofClass(board a, string b);												// Xuat thong tin khoa hoc cua mot lop
bool reClass(base a, string str);															// Tim class
bool firstYearStu(base a, string str);														// Kiem tra sinh vien nam nhat
	
//					============COURSE=============
board makeBoard(Course infor);																// Ham cap phat Board moi
bool boardEmpty(board& a);																	// Kiem tra Board rong
void readCourse(ifstream& f, Course& infor);												// Ham doc thong tin khoa hoc
void addInCourse(board& a, board temp);														// Them thong tin vao Board
void readFileCourse(ifstream& f, board& a);													// Doc file va ghi vao danh sach
void outputCourse(board a);																	// Xuat thong tin khoa hoc
void outputFileCourse(ofstream& f, board a);												// Ghi noi dung cua Board vao File
bool checkIDCourse(string id, board a);														// Kiem tra id khoa hoc
bool check(int ngay, int thang, int nam);													// Kiem tra ngay thang
bool checkDay(string day);																	// Kiem tra ngay
bool checkTime(string time);																// Kiem tra thoi gian
bool checkWeek(string day);																	// Kiem tra ngay trong tuan
void addCourse(board& a);																	// Them khoa hoc moi vao Board
void clearBoard(board& a);																	// Lam rong Board
void deleteCourse(board& a, string str);													// Xoa khoa hoc
bool reCourse(board a, string str, string id);												// Check ten khoa hoc
	
//					============SCORE=============
result makeResult(Score infor);																// Ham cap phat Result moi
bool resultEmpty(result& a);																// Kiem tra Result rong
void readScore(ifstream& f, Score& infor);													// Ham doc diem sinh vien
void addInResult(result& a, result temp);													// Them thong tin vao Result
void readFileScore(ifstream& f, result& a);													// Doc file va ghi vao danh sach
void outputScore(result a, string str, string id);											// Xuat thong tin diem sinh vien
bool checkStuInCourse(result a, string str, string id, string stuid);						// Kiem tra sinh vien co trong khoa hoc hay khong
void updateStudentScore(result& a, string str, string id, string stuid);					// Cap nhat diem cho sinh vien
void outputFileScore(ofstream& f, result a);												// Ghi thong tin Result vao File
void clearResult(result& a);																// Lam rong Result
bool checkScore(string mark);																// Kiem tra diem
void removeStudent(result& a, string str, string cid, string id);							// Xoa sinh vien ra khoi khoa hoc

//					============FILE ADD=============
add makeAdd(Them infor);																	// Ham cap phat Add moi
bool addEmpty(add& a);																		// Kiem tra Add rong
void readAdd(ifstream& f, Them& infor);														// Ham doc thong tin file them sinh vien
void addInAdd(add& a, add temp);															// Them thong tin vao Add
void readFileAdd(ifstream& f, add& a);														// Doc file va ghi vao danh sach
void addStudentFromFile(add a, list& b, base& c, string str);								// Them sinh vien tu file vao lop
void clearAdd(add& a);																		// Lam rong Result

//								DANH CHO STUDENT
void viewListCourse(logstu a, board b, list c, string tk);									// Xem danh sach khoa hoc
void viewScore(logstu a, result b, string tk);												// Xem diem trong khoa hoc
void registerCourse(logstu& a, list& b, result& c, string str, string cid, string tk);		// Ham dang ky khoa hoc