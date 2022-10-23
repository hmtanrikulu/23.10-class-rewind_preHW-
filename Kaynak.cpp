#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;
class database {
private:
	class user {
	private:
		string username;
		string lastname;
		tm birthdate;
		int id;
		int basesalary;
		int workexp;
		int sectoyear(int x) {
			int year = 60 * 60 * 24 * 365 + 6;
			return (int)(x / year);
		}
	public:
		void setname(string x){
			this->username = x;
		}
		string getName() {
			return this->username;
		}
		string getLastName() {
			return this->lastname;
		}
		int calcAge() {
			time_t tmp = mktime(&this->birthdate);
			auto birthdate = chrono::system_clock::from_time_t(tmp);
			auto curr = chrono::system_clock::now();
			auto age_diff = (curr - birthdate);
			auto age_seconds = chrono::duration_cast<chrono::seconds>(age_diff);
			return this->sectoyear(age_seconds.count());
		}
		user( string username,string lastname,int id,int basesalary,int workexp,int day,int month,int year) { // ayný isimde "user"  yazýnca constructer
			this->birthdate = { 0 };
			this->username = username;
			this->lastname = lastname;
			this->birthdate.tm_year = year - 1900;
			this->birthdate.tm_mon = month - 1;
			this->birthdate.tm_mday = day;
			this->id = id;
			this->basesalary = basesalary;
			this->workexp = workexp;
		}
	};
	vector <user> users;
	bool doesUserExist(string n, string ln) {
		for (int i = 0; i < this->users.size(); i++) {
			if (this->users[i].getName() == n && this->users[i].getLastName() == ln) {
				return true;
			}
		}
		return false;
	}
public:
	void createUser(
		string username,
		string lastname,
		int basesalary,
		int workexp,
		int day,
		int month,
		int year) {
		if (this->doesUserExist(username, lastname)) {
			int id = users.size() + 1; // user sayýsý na gore id verme
			user tmp(
				username, lastname, id, basesalary, workexp, day, month, year
			);
			users.push_back(tmp);
		}
	}
};
class bdate {
private:
	int day, month, year;
	void strtodates(string bday, int& tmpday, int& tmpmonth, int& tmpyear) {
		tmpday = stoi(bday.substr(0, bday.find('/')));// BDAY = 14/03/1998
		bday = bday.substr(bday.find('/') + 1); //substr yi burdan baslattýk          == yani basýný silmis olduk     BDAY = 03/1998
		tmpmonth = stoi(bday.substr(0, bday.find('/')));
		bday = bday.substr(bday.find('/') + 1); // BDAY = 1998
		tmpyear = stoi(bday);
	}
public:
	bdate(string strbday) {
		strtodates(strbday, this->day, this->month, this->year); // bilgileri private a daðýttýk
	}
	int getDay() {
		return this->day;
	}
	int getMonth() {
		return this->month;
	}
	int getYear() {
		return this->year;
	}
};
//struct user {
//	string username;
//	string lastname;
//	string birthdate;
//	int id;
//	int basesalary;
//	int workexp;
//}user1, user2;
void getvariables(database &db) {
	string name, ln, bidate;
	int basesalary, workexp;
	cout << "enter name: ";
	cin >> name;
	cout << "enter lname";
	cin >> ln;
	cout << "enter bdate: ";
	cin >> bidate;
	bdate classbdate(bidate);
	db.createUser(name,ln,10,workexp, classbdate.getDay(), classbdate.getMonth(), classbdate.getYear()); 
}
int main() {
	database db;
	getvariables(db);
			//db.createUser(
			//	name, 
			//	"arikan",
			//	20,                 YEÞÝL KISIM = GET VARIABLES FONKSIYONUNUN YAPTIGI KISIM
			//	1,
			//	14,
			//	3,
			//	1998
			//);
	return 0;
}