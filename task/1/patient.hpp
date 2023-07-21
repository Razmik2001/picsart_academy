#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "history.hpp"
using std::string;

using std::cout;
using std::endl;

class Patient
{
	const string m_name;
	const int m_birthData;//years
	const string m_Gender;
	const string m_contactInformation;
	string m_medicalConditions;
	History history;
public:
	void setDiagnoses(string D){history.setDiagnoses(D);}
	void addTreatments(string T){history.addTreatments(T);}
	void addMedications(string M){history.addMedications(M);}
	Patient(const string& N,int BD,const string G,const string &CI,const string& M):m_name(N),m_birthData(BD),m_contactInformation(CI),m_Gender(G) {}
	void setMedicalConditions(string M)
	{
		m_medicalConditions = M;
	}
	void setHistory(History h)
	{
		history = h;
	}
	string getName(){return m_name;}
	string getContactInformation(){return m_contactInformation;}
	string getGender(){return m_Gender;}
	int getBirthData(){return m_birthData;}
	History getHistory(){return history;}
	string getMedicalConditions(){return m_medicalConditions;}
	string info()
	{	
		string s = "";
		s += getName() + "\n";
		s += std::to_string(getBirthData()) + "\n";
		s += getGender() + "\n";
		s += getContactInformation() + "\n";
		s += getMedicalConditions() + "\n";
		s += history.info();
		return s;
	}
	void displey()
	{
		cout << info() << endl;
	}
};

#endif //PATIENT_HPP