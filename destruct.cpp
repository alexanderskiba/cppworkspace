//============================================================================
// Name        : destruct.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int ComputeDistance(const string& source, const string& destination){
	return source.length() - destination.length();

}
class Route{
public:
	Route(){
		source = "Moscow";
		destination = "Saint Petersburg";
		UpdateLength();
		cout << "Default constructed\n";
	}
	Route(const string& new_source, const string& new_destination){
		source = new_source;
		destination = new_destination;
		UpdateLength();
		cout << "Constructed\n";
	}
	~Route(){ // После вывода всех элементов вектора деструктор уничтожит объект
		cout <<"Destructed\n";
		for (const string& entry: compute_distance_log) {
			//cout << entry << "\n";
		}
	}
	string GetSource() const {
		return source;

	}
	string GetDestination() const {
		return destination;

	}
	int GetLength() const {
		return length;
	}

	void SetSource(const string& new_source)  {
		source = new_source;
		UpdateLength();
	}

	void SetDestination(const string& new_destination){
		destination = new_destination;
		UpdateLength();
	}
private:
	void UpdateLength(){
		length = ComputeDistance(source, destination);
		compute_distance_log.push_back(source + " - " + destination); // лог вызова функции
	}
	string source;
	string destination;
	int length;
	vector<string> compute_distance_log;
};

void PrintRoute(const Route& route){
	cout << route.GetSource() << " - " << route.GetDestination() << "\n";
}

void ReverseRoute(Route& route){
	string old_source = route.GetSource();
	string old_destination = route. GetDestination();
	route.SetSource(old_destination);
	route.SetDestination(old_source);
}

void WorthLess(Route route){
	cout << 2 << "\n";
}
Route GetRoute(){
	cout << 1 << "\n";
	return{};
}

int main() {
//	Route route("Moscow", "Saint Petersburg");
//	route.SetSource("Vyborg");
//	route.SetDestination("Vologda");
////	for(int i : {0,1}){
//		cout << "Step " << i << ": " << 1 << "\n";
//		Route route;
//		cout << "Step " << i << ": " << 2 << "\n";
//	}
//	cout << "End\n";
 GetRoute();
cout << 2 << "\n";
	return 0;
}
