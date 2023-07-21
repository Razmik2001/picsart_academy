#ifndef REGIST_HPP
#define REGIST_HPP

#include "patient.hpp"
#include "doctor.hpp"
using std::vector;
using std::string;
using std::cout;
using std::endl;
#include <fstream>

void save(const string& user, const string& order)
    {
        string s = user + ".txt";
        std::ofstream f(s); // Use std::ofstream in output mode
        f << order;
        f.close();
    }

class Regist
{
	vector<Patient *> pat;
	vector<Doctor *>  doc;
public:
	void addDoctor(Doctor* d){doc.push_back(d);}
	void addPatient(Patient* p){pat.push_back(p);}
	Patient * getPatient(int patNum){return pat[patNum - 1];}
	void displey()
	{
		cout << "Patients" << endl;
		for (const auto& i : pat) {
			i->displey();
			cout<<endl;
    	}
		cout << "Doc" << endl;
		for (const auto& i : doc) {
			i->displey();
			cout<<endl;
    	}
	}
	void diagSave(int docNum, int patNum)
    {
        save(doc[docNum - 1]->getName(),pat[patNum - 1]->info());
    }  
};

#endif //REGIST_HPP