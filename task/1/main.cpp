#include "regist.hpp"

int main()
{
	Regist r;
	r.addDoctor(new Doctor("Armen","Xirurg",12,"2313"));
	r.addPatient(new Patient("Rafo",19,"male","2122","vata"));
	(r.getPatient(1))->setDiagnoses("toq");
	(r.getPatient(1))->addTreatments("hac");
	(r.getPatient(1))->addTreatments("sac");
	(r.getPatient(1))->displey();
	r.diagSave(1,1);
}