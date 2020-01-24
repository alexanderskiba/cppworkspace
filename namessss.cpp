//============================================================================
// Name        : namessss.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;
class Person {
public:
  void ChangeFirstName(int year, const string& first_name)  {
    if (first_name.size() > 0) fio_name[year] = first_name;
                                                            }

  void ChangeLastName(int year, const string& last_name)    {
    if (last_name.size() > 0) fio_surname[year] = last_name;
                                                            }

  string GetFullName(int year)  {
      	string  result_name = "";
	    string  result_surname = "";

	    if ((fio_name.empty()) && (fio_surname.empty()))    {
	        return "Incognito";
	                                                            }
	   else {
        //nothing
        if (year < fio_name.begin()->first && year < fio_surname.begin()->first)    {
            return "Incognito";
                                                                                    }
        else    {
            for (auto item : fio_name)  {
        if (item.first <= year) {
        	result_name = item.second;
        }
                                        }
            for (auto item : fio_surname)   {
        if (item.first <= year) {
        	result_surname = item.second;
        }
                                            }
        //no name
        //if ((result_name.size() == 0) && (result_surname.size() != 0))  {
            if(fio_name.empty()|| year<fio_name.begin()->first ){
            return (result_surname + " with unknown first name");
                                                                        }
        //no last_name
        //else if ((result_name.size() != 0) && (result_surname.size() == 0))

        else if (fio_surname.empty()|| year< fio_surname.begin() ->first)	{
            return (result_name + " with unknown last name");
                                                                            }
        //all OK
        else if ((result_name.size() != 0) && (result_surname.size() != 0)) {
            return (result_name + " " + result_surname);              }
                }
            }
                                    }

private:
    map <int, string> fio_name;
    map <int, string> fio_surname;
};


int main() {
	Person person;

	cout << person.GetFullName(2000) << endl;

	person.ChangeLastName(1968, "1968_2nd");
	person.ChangeLastName(1967, "1967_2nd");
	person.ChangeLastName(1965, "1965_2nd");
	person.ChangeLastName(1966, "1966_2nd");

	for (int year : {1900, 1920, 1950, 1965, 1966, 1967, 1968}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1920, "1920_1st");
	person.ChangeFirstName(1900, "1900_1st");
	person.ChangeFirstName(1965, "1965_1st");
	person.ChangeFirstName(1950, "1950_1st");

	for (int year : {1900, 1920, 1950, 1965, 1966, 1967, 1968}) {
		cout << person.GetFullName(year) << endl;
	}


	return 0;
}
// Целевой вывод:
// Incognito
// Incognito
// Incognito
// Incognito
// 1965_2nd with unknown first name
// 1966_2nd with unknown first name
// 1967_2nd with unknown first name
// 1968_2nd with unknown first name
// 1900_1st with unknown last name
// 1920_1st with unknown last name
// 1950_1st with unknown last name
// 1965_1st 1965_2nd
// 1965_1st 1966_2nd
// 1965_1st 1967_2nd
// 1965_1st 1968_2nd

