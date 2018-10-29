#include <iostream>
#include <string>
using namespace std;
const int C_per_Pro = 4;
const int C_per_Fat = 9;
const int C_per_Car = 4;
struct person
{
	string name;
	unsigned int sex;
	double hight;
	double weight;
	unsigned int year;
	unsigned int sport_level;
	unsigned int goal;
};

struct plan
{
	double Calorie;
	double Protein;
	double Fat;
	double Carbonhydate;
	double Protein_C;
	double Fat_C;
	double Carbonhydate_C;
};

double BMR(const person * someone);
double estimate_C(unsigned int sport_level, double bmr);
double goal_C(double estimate_Calorie, unsigned int goal);

int main(int argc, char const *argv[])
{
	person you;
	plan yourplan;
	cout << "Please enter your name: ";
	getline(cin,you.name);
	cout << "Please enter your sex: (enter 1 if you are male, O for female)";
	cin >> you.sex;
	cout << "Please enter your hight(cm): ";
	cin >> you.hight;
	cout << "Please enter your weight(kg): ";
	cin >> you.weight;
	cout << "Please enter your age: ";
	cin >> you.year;
	cout << "Please enter your sport level " << endl;
	cout << "no exercise: 1 " << endl; 
	cout << "exercise 1-3 times a week: 2 " << endl; 
	cout << "exercise 3-5 times a week: 3 " << endl; 
	cout << "exercise 6-7 times a week: 4 " << endl;
	cout << "exercise as athlete: 5 " << endl;  
	cin >> you.sport_level;
	cout << "Please enter your goal: (stronger: 1, silm: 2)";
	cin >> you.goal;
	double bmr = BMR(&you);
	double estimate_Calorie = estimate_C(you.sport_level, bmr);
	//-------------------------------------------------------------
	yourplan.Calorie = goal_C(estimate_Calorie, you.goal);
	yourplan.Protein = you.weight * 2.2;
	yourplan.Protein_C = yourplan.Protein * C_per_Pro;
	yourplan.Fat_C = yourplan.Calorie * 0.25;
	yourplan.Fat = yourplan.Fat_C / C_per_Fat;
	yourplan.Carbonhydate_C = yourplan.Calorie - yourplan.Protein_C - yourplan.Fat_C;
	yourplan.Carbonhydate = yourplan.Carbonhydate_C / C_per_Car;
	//-------------------------------------------------------------
	cout << "Hello" << you.name << " here is your information: " << endl;
	cout << "Your hight: " << you.hight << "cm" << endl;
	cout << "Your weight: " << you.weight << "kg" << endl;
	cout << "Your age: " << you.year << endl;
	cout << "Your basic consumption Calorie: " << estimate_Calorie << endl;
	cout << "Your plan input Calorie: " << yourplan.Calorie << endl;
	cout << "Your should eat " << yourplan.Protein << " g Protein every day. It contain " << yourplan.Protein_C << " Calories." << endl;
	cout << "Your should eat " << yourplan.Fat << " g Fat every day. It contain " << yourplan.Fat_C << " Calories." << endl;
	cout << "Your should eat " << yourplan.Carbonhydate << " g Carbonhydate every day. It contain " << yourplan.Carbonhydate_C << " Calories." << endl;
	return 0;

}
double BMR(const person * someone)
{
	double bmr;
	if (someone->sex)
	{
		bmr = 66 + (5 * someone->hight) + (13.7 * someone->weight) - (6.8 * someone->year);/* code */
	}
	return bmr;
}

double estimate_C(unsigned int sport_level, double bmr)
{
	double consume_level;
	switch(sport_level){
		case 1:{
			consume_level = 1.2;
			break;
		}
		case 2:{
			consume_level = 1.375;
			break;
		}
		case 3:{
			consume_level = 1.55;
			break;
		}
		case 4:{
			consume_level = 1.725;
			break;
		}
		case 5:{
			consume_level = 1.9;
			break;
		}
		default:{
			cout << "enter: wrong number, will cumulate with lowest level 1.2.";
			consume_level = 1.2;
			break;
		}
	}
	double Est_Calorie = consume_level * bmr ;
	return Est_Calorie;
}

double goal_C(double estimate_Calorie, unsigned int goal)
{
	double goal_calorie;
	switch(goal){
		case 1:{
			goal_calorie = estimate_Calorie + 500;
			break;
		}
		case 2:{
			goal_calorie = estimate_Calorie - 500;
			break;
		}
		default: {
			cout << "enter the wrong number and you will get basic Calorie Consumption." << endl;
			goal_calorie = estimate_Calorie;
			break;
		}
	}
	return goal_calorie;
}



