//============================================================================
// Name        : constructor.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class ReversibleString {

public:
	ReversibleString(string kek) {string s = kek;}
	string Reverse(){

		reverse(begin(s), end(s));
		return s;
	}

	string ToString(){

			return s;
		}
private:
	string s;
};


int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}

