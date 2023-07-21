#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;
class History
{
	string diagnoses = "";
	vector<string> treatments;
	vector<string>  medications;
public:
	void setDiagnoses(string D){diagnoses = D;}
	void addTreatments(string T){treatments.push_back(T);}
	void addMedications(string M){medications.push_back(M);}
	string getDiagnoses(){return diagnoses;}
	vector<string> getTreatments(){return treatments;}
	vector<string> getMedications(){return medications;}
	string info()
	{
		string s = "";
		s +=  getDiagnoses() + "\n|";
		for (const auto& i : treatments) {
        	s +=" " + i + " |";
    	}
    	s += "\n|";
    	for (const auto& i : medications) {
        	s +=" "  + i + " |";
    	}
    	s += "\n|";
    	return s;
	}
	void displey()
	{
		cout << info();
	}
};

#endif //HISTORY_HPP