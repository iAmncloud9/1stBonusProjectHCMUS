#include<iostream>

using namespace std;

//------------------------------------------------------------------------------------------------------------------------

// Ham su dung trong Login

void readAccountStaff(ifstream& f, Staff& log);									// Ham doc thong tin tai khoan tu File
void readAccountStudent(ifstream& f, SinhVien& log);	
int loginStaff(ifstream& f, string tk, string mk);								// Ham kiem tra tai khoan khi dang nhap
int loginStudent(ifstream& f, string tk, string mk);	
void outputStaffInformation(Staff log);											// Ham xuat thong tin Staff ra man hinh
void outputStudentInformation(SinhVien log);		
void staffInformation(ifstream& f, string tk, string mk);						// Ham doc thong tin nguoi so huu tu File
void studentInformation(ifstream& f, string tk, string mk);
node makeAccountStaff(Staff x);													// Ham cap phat node tam
logstu makeAccountStudent(SinhVien x);			
bool nodeEmpty(node a);															// Ham kiem tra danh sach rong
bool loginEmpty(logstu a);			
void addAccountStaff(node& a, node temp);										// Ham them thong tin tai khoan vao danh sach
void addAccountStudent(logstu& a, logstu temp);	
void readAllFileStaff(ifstream& f, node& a);									// Ham doc toan bo File yeu cau
void readAllFileStudent(ifstream& f, logstu& a);	
void changePasswordStaff(node& a, string tk);									// Ham thay doi mat khau
void changePasswordStudent(logstu& a, string tk);	
void ouputFileStaff(ofstream& f, node a);										// Ham ghi thong tin trong danh sach vao File
void ouputFileStudent(ofstream& f, logstu a);	
void registerStaffAccount(node& a, string position);							// Ham dang ki tai khoan
void registerStudentAccount(logstu& a, list b, base c, string position);
void clearNode(node& a);
void clearLogin(logstu& a);

// -----------------------------------------------------------------------------------------------------------------------

// Ham su dung trong phan con lai

//								DANH CHO STAFF

//					============STUDENT=============
list makeList(sv infor);
bool listEmpty(list& a);
void readStudent(ifstream& f, sv& infor);
void addInforStudent(list& a, list temp);
void readFileStudent(ifstream& f, list& a);
void outputStudentinFile(ofstream& f, list a);
void clearList(list& a);
bool checkStuID(list a, string id);
bool checkSocialId(list a, string id);
bool checkStuName(string name);
void checkName(string& a);
bool checkStuInClass(base a, string str);
void addStudentInClass(list& a, string str);
void addStudentFromFile();
void addStudentToCourse(list& a, base b, result& c, string str, string id);
void removeStudentFromCourse(list& a, string str, string cid, string id);

//					============CLASS============
base makeBase(Class infor);
bool baseEmpty(base& a);
void addInClass(base& a, base temp);
void readClass(ifstream& f, Class& infor);
void readFileClass(ifstream& f, base& a);
void sortClass(base& a);
void outputClass(base a);
int checkClass(string str, base a);
void outputFileClass(ofstream& f, base a);
int addClass(base& a, string str, string name);
void clearBase(base& a);
//void findStudent(base a, list b, int& sl);
//void findCourse(board a, base b, int& sl);
void outputStudentofClass(list a, string b);
void outputCourseofClass(board a, string b);
bool reClass(base a, string str);
bool firstYearStu(base a, string str);

//					============COURSE=============
board makeBoard(Course infor);
bool boardEmpty(board& a);
void readCourse(ifstream& f, Course& infor);
void addInCourse(board& a, board temp);
void readFileCourse(ifstream& f, board& a);
void outputCourse(board a);
void outputFileCourse(ofstream& f, board a);
bool checkIDCourse(string id, board a);
bool check(int ngay, int thang, int nam);
bool checkDay(string day);
bool checkTime(string time);
bool checkWeek(string day);
void addCourse(board& a);
void clearBoard(board& a);
void deleteCourse(board& a, string str);
bool reCourse(board a, string str, string id);

//					============SCORE=============
result makeResult(Score infor);
bool resultEmpty(result& a);
void readScore(ifstream& f, Score& infor);
void addInResult(result& a, result temp);
void readFileScore(ifstream& f, result& a);
void outputScore(result a, string str, string id);
bool checkStuInCourse(result a, string str, string id, string stuid);
void updateStudentScore(result& a, string str, string id, string stuid);
void outputFileScore(ofstream& f, result a);
void clearResult(result& a);
bool checkScore(string mark);
void removeStudent(result& a, string str, string cid, string id);

//								DANH CHO STUDENT
void viewListCourse(logstu a, board b, list c, string tk);
void viewScore(logstu a, result b, string tk);