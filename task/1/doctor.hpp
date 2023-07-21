#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Doctor
{
	const string m_name;
	int m_experience;//years
	const string m_specialization;
	const string m_contactInformation;
public:
	Doctor(const  string& N,const string& S,int YOF,const string &CI):m_name(N),m_experience(YOF),m_contactInformation(CI),m_specialization(S) {}
	string getName(){return m_name;}
	string getContactInformation(){return m_contactInformation;}
	string getSpecialization(){return m_specialization;}
	int getExperience(){return m_experience;}
	void displey()
	{
		cout << getName() << endl;
		cout << getContactInformation() << endl;
		cout << getSpecialization() << endl;
		cout << getExperience() << endl;			
	}
};

#endif //DOCTOR_HPP