#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
 
using namespace std;
struct Node{
	string regId;
	int age;
	string gender;
	string edu;
	string job;
	int lvlOfExp;
	int salary;
	Node(string r, int a, string g, string e, string j, int l, int s) {
	    regId = r;
	    age = a;
	    gender = g;
	    edu = e;
	    job = j;
	    lvlOfExp = l;
	    salary = s;
	}
};

class Orgnanization{
	public:
	Node *H[200];
	int size = -1;
	int parent(int i){
		return ((i-1)/2);
	}
	int leftChild(int i){
		return((2 * i) + 1);
	}
	int rightChild(int i){
		return((2 * i) + 2);
	}
	 
	void shiftUpRegNo(int i){
		while(i > 0 && H[parent(i)] < H[i]){
			swap(H[parent(i)], H[i]);
			i = parent(i);
		}
	}
	void insertRegNo(Node* data){
		size++;
		Node *p = data;
		H[size] = p;
		shiftUpRegNo(size);
	}
	void shiftDownRegNo(int i){
		int maxIndex = i;
		int l = leftChild(i);
		while(i<=size && H[l] > H[maxIndex]){
			maxIndex = l;
		}
		int r = rightChild(i);
		while(i<=size && H[r] > H[maxIndex]){
			maxIndex = r;
		}
		if(i != maxIndex){
			swap(H[i], H[maxIndex]);
			shiftDownRegNo(maxIndex);
		}
	}
	
	Node* extractMaxSal(){
		Node* result = H[0];
		result = H[0];
		H[0] = H[size];
		size--;
		shiftDownRegNo(0);
		return result;
	}
	
	void display(){
		int i = 0;
		while(i<=size){
			cout<<"Registration no."<<H[i]->regId<<"\nAge:"<<H[i]->age<<
			"\nGender:"<<H[i]->gender<<"\nEducation level:"<<H[i]->edu<<"\nJob title:"<<H[i]->job<<
			"\nExperience level:"<<H[i]->lvlOfExp<<" years\nSalary:"<<H[i]->salary<<"\n\n";
			i++;
		}
	}

    void HighestSalaryEmployees() {
	    if (size < 0) {
	        cout << "No employees in the organization." << endl;
	        return;
	    }
	
	    int maxSalary = H[0]->salary;
	    for (int i = 1; i <= size; i++) {
	        if (H[i]->salary > maxSalary) {
	            maxSalary = H[i]->salary;
	        }
		}
	    bool found = false;
	    for (int i = 0; i <= size; i++) {
	        if (H[i]->salary == maxSalary) {
	            cout << "Registration no of highest salary employee/employee: " << H[i]->regId << endl;
	            found = true;
	        }
	    }
	    if (!found) {
	        cout << "No employees found with the highest income." << endl;
	    }
	}


	void LowestSalaryEmployees() {
	    if (size < 0) {
	        cout << "No employees in the organization." << endl;
	        return;
	    }
	    int minSalary = H[0]->salary;
	    for (int i = 1; i <= size; i++) {
	        if (H[i]->salary < minSalary) {
	            minSalary = H[i]->salary;
	        }
	    }
	    bool found = false;
	    for (int i = 0; i <= size; i++) {
	        if (H[i]->salary == minSalary) {
	            cout << "Registration no of lowest salary employee/employee: : " << H[i]->regId << endl;
	            found = true;
	        }
		}
	    if (!found) {
	        cout << "No employees found with the lowest income." << endl;
	    }
	}
	string MostCommonEducationLevel() {
	    if (size < 0) {
	        return "No employees in the organization.";
	    }
	
	    int bachelorsCount = 0;
	    int mastersCount = 0;
	    int phdCount = 0;

	    for (int i = 0; i <= size; i++) {
	        string eduLevel = H[i]->edu;
	        if (eduLevel == "Bachelor's") {
	            bachelorsCount++;
	        } else if (eduLevel == "Master's") {
	            mastersCount++;
	        } else if (eduLevel == "PhD") {
	            phdCount++;
	        }
	    }

	    if (bachelorsCount >= mastersCount && bachelorsCount >= phdCount) {
	        return "Bachelor's";
	    } else if (mastersCount >= bachelorsCount && mastersCount >= phdCount) {
	        return "Master's";
	    } else {
	        return "PhD";
	    }
	}
	int averageExpLvl(){
		int averageExp = 0,count = 0;
		for(int i = 1; i <= size; i++){
			averageExp += H[i]->lvlOfExp;
			count++;
		}
		return averageExp/count;
	}
	int averageAge(){
		int averageAge = 0,count = 0;
		for(int i = 1; i <= size; i++){
			averageAge += H[i]->age;
			count++;
		}
		return averageAge/count;
	}
	int averageSalary(){
		int averageSalary = 0,count = 0;
		for(int i = 1; i <= size; i++){
			averageSalary += H[i]->salary;
			count++;
		}
		return averageSalary/count;
	}
	string MostCommonGender() {
	    if (size < 0) {
	        return "No employees in the organization.";
	    }
	
	    int maleCount = 0;
	    int femaleCount = 0;
	
	    for (int i = 0; i <= size; i++) {
	        string gender = H[i]->gender;
	        if (gender == "Male") {
	            maleCount++;
	        } else if (gender == "Female") {
	            femaleCount++;
	        }
	    }
	
	    if (maleCount >= femaleCount) {
	        return "Male";
	    } else {
	        return "Female";
	    }
	}
	void MostExperiencedEmployees() {
	    if (size < 0) {
	        cout << "No employees in the organization." << endl;
	        return;
	    }
	
	    int maxExperience = H[0]->lvlOfExp;
	
	    for (int i = 1; i <= size; i++) {
	        if (H[i]->lvlOfExp > maxExperience) {
	            maxExperience = H[i]->lvlOfExp;
	        }
	    }

	    bool found = false;
	    for (int i = 0; i <= size; i++) {
	        if (H[i]->lvlOfExp == maxExperience) {
	            cout << "Registration no of most exp employee/employee: " << H[i]->regId << endl;
	            found = true;
	        }
	    }
	
	    if (!found) {
	        cout << "No employees with the maximum experience level." << endl;
	    }
	}
	void ViewEmployeesBySalary() {
	    if (size < 0) {
	        cout << "No employees in the organization." << endl;
	        return;
	    }
	
	    cout << "\nEmployees sorted by salary:" << endl;
	
	    Node* sortedArray[size + 1];
	    for (int i = 0; i <= size; i++) {
	        sortedArray[i] = H[i];
	    }

	    for (int i = size; i >= 0; i--) {
	        for (int j = 0; j < i; j++) {
	            if (sortedArray[j]->salary < sortedArray[j + 1]->salary) {
	                swap(sortedArray[j], sortedArray[j + 1]);
	            }
	        }
	    }
		cout<<endl;
	    for (int i = 0; i <= size; i++) {
	        cout << "Registration no: " << sortedArray[i]->regId << endl;
	        cout << "Age: " << sortedArray[i]->age << endl;
	        cout << "Gender: " << sortedArray[i]->gender << endl;
	        cout << "Education level: " << sortedArray[i]->edu << endl;
	        cout << "Job title: " << sortedArray[i]->job << endl;
	        cout << "Experience level: " << sortedArray[i]->lvlOfExp << " years" << endl;
	        cout << "Salary: " << sortedArray[i]->salary << endl;
	        cout << endl;
	    }
	}
	void MostAgedEmployee() {
	    if (size < 0) {
	        cout << "No employees in the organization." << endl;
	        return;
	    }
	
	    int maxAge = H[0]->age;
	
	    for (int i = 1; i <= size; i++) {
	        if (H[i]->age > maxAge) {
	            maxAge = H[i]->age;
	        }
	    }
	
	    cout << "Most aged employee(s) in the organization:" << endl;
	    for (int i = 0; i <= size; i++) {
	        if (H[i]->age == maxAge) {
	            cout << "Registration no: " << H[i]->regId << endl;
	            cout << "Age: " << H[i]->age << endl;
	            cout << "Gender: " << H[i]->gender << endl;
	            cout << "Education level: " << H[i]->edu << endl;
	            cout << "Job title: " << H[i]->job << endl;
	            cout << "Experience level: " << H[i]->lvlOfExp << " years" << endl;
	            cout << "Salary: " << H[i]->salary << endl;
	            cout << endl;
	        }
	    }
	}
	void MostYoungestEmployee() {
	    if (size < 0) {
	        cout << "No employees in the organization." << endl;
	        return;
	    }
	
	    int minAge = H[0]->age;
	
	    for (int i = 1; i <= size; i++) {
	        if (H[i]->age < minAge) {
	            minAge = H[i]->age;
	        }
	    }
	
	    cout << "Most youngest employee(s) in the organization:" << endl;
	    for (int i = 0; i <= size; i++) {
	        if (H[i]->age ==  minAge) {
	            cout << "Registration no: " << H[i]->regId << endl;
	            cout << "Age: " << H[i]->age << endl;
	            cout << "Gender: " << H[i]->gender << endl;
	            cout << "Education level: " << H[i]->edu << endl;
	            cout << "Job title: " << H[i]->job << endl;
	            cout << "Experience level: " << H[i]->lvlOfExp << " years" << endl;
	            cout << "Salary: " << H[i]->salary << endl;
	            cout << endl;
	        }
	    }
	}
	void promoteEmployees(int experience, int salaryIncrement) {
    	for (int i = 0; i <= size; i++) {
	        if (H[i]->lvlOfExp >= experience) {
	            H[i]->salary += salaryIncrement;
	        }
	    }
	    cout << "Employees promoted successfully." << endl;
	}
	void YoungestEmployeeByEducation(string educationLevel) {
	    Node* youngestEmployee = NULL;
	    int youngestAge = 9999999;
	
	    for (int i = 0; i <= size; i++) {
	        if (H[i]->edu == educationLevel && H[i]->age < youngestAge) {
	            youngestEmployee = H[i];
	            youngestAge = H[i]->age;
	        }
	    }
	
	    if (youngestEmployee != NULL) {
	        cout << "Youngest Employee by Education Level (" << educationLevel << "):" << endl;
	        cout << "Registration no.: " << youngestEmployee->regId << endl;
	        cout << "Age: " << youngestEmployee->age << endl;
	        cout << "Gender: " << youngestEmployee->gender << endl;
	        cout << "Education level: " << youngestEmployee->edu << endl;
	        cout << "Job title: " << youngestEmployee->job << endl;
	        cout << "Experience level: " << youngestEmployee->lvlOfExp << " years" << endl;
	        cout << "Salary: " << youngestEmployee->salary << endl;
	    } else {
	        cout << "No employee found with the specified education level." << endl;
	    }
	}
	
	void OldestEmployeeByEducationLevel(string educationLevel){
	    
		Node* oldestEmployee = NULL;
		int oldestAge = -99999999;
	    for (int i = 0; i <= size; i++) {
	        if (H[i]->edu == educationLevel && H[i]->age > oldestAge) {
	            oldestAge = H[i]->age;
	            oldestEmployee = H[i];
	        }
		}
	    if (oldestEmployee != NULL) {
	        cout << "Oldest Employee by Education Level (" << educationLevel << "):" << endl;
	        cout << "Registration No.: " << oldestEmployee->regId << endl;
	        cout << "Age: " << oldestEmployee->age << endl;
	        cout << "Gender: " << oldestEmployee->gender << endl;
	        cout << "Education Level: " << oldestEmployee->edu << endl;
	        cout << "Job Title: " << oldestEmployee->job << endl;
	        cout << "Experience Level: " << oldestEmployee->lvlOfExp << " years" << endl;
	        cout << "Salary: " << oldestEmployee->salary << endl;
	        cout << endl;
	    }
	    else {
	        cout << "No employee found with education level: " << educationLevel << endl;
	        cout << endl;
	    }
	}
	bool IsEmployeeExists(string regId){
	    for (int i = 0; i <= size; i++) {
	        if (H[i]->regId == regId) {
	            return true; 
	        }
	    }
	    return false; 
	}
	void ViewEmployeesByGender(string gender){
	    bool found = false;
	    for (int i = 0; i <= size; i++) {
	        if (H[i]->gender == gender) {
	            cout << "Registration No.: " << H[i]->regId << endl;
	            cout << "Age: " << H[i]->age << endl;
	            cout << "Gender: " << H[i]->gender << endl;
	            cout << "Education Level: " << H[i]->edu << endl;
	            cout << "Job Title: " << H[i]->job << endl;
	            cout << "Experience Level: " << H[i]->lvlOfExp << " years" << endl;
	            cout << "Salary: " << H[i]->salary << endl;
	            cout << endl;
	            found = true;
	        }
	    }
	    if (!found) {
	        cout << "No employees found with gender: " << gender << endl;
	    }
	}
	string HighestSalaryByEducation(string educationLevel){
	    int highestSalary = -999999;
	    Node* highestSalaryEmployee = NULL;
	    for (int i = 0; i <= size; i++) {
	        if (H[i]->edu == educationLevel && H[i]->salary > highestSalary) {
            highestSalary = H[i]->salary;
            highestSalaryEmployee = H[i];
        	}
	    }
	    if (highestSalaryEmployee != NULL) {
        cout << "Employee with the highest salary for " << educationLevel << ":" << endl;
        cout << "Registration no.: " << highestSalaryEmployee->regId << endl;
        cout << "Age: " << highestSalaryEmployee->age << endl;
        cout << "Gender: " << highestSalaryEmployee->gender << endl;
        cout << "Education level: " << highestSalaryEmployee->edu << endl;
        cout << "Job title: " << highestSalaryEmployee->job << endl;
        cout << "Experience level: " << highestSalaryEmployee->lvlOfExp << " years" << endl;
        cout << "Salary: " << highestSalaryEmployee->salary << endl;
	    } else {
	        cout << "No employee found with the specified education level." << endl;
	    }
	}
	void LowestSalaryByEducation(string educationLevel){
	    int lowestSalary = 9999999;
	    Node* lowestSalaryEmployee = NULL;
	
	    for (int i = 0; i <= size; i++) {
	        if (H[i]->edu == educationLevel && H[i]->salary < lowestSalary) {
	            lowestSalary = H[i]->salary;
	            lowestSalaryEmployee = H[i];
	        }
	    }
	
	    if (lowestSalaryEmployee != NULL) {
	        cout << "Employee with the lowest salary for " << educationLevel << ":" << endl;
	        cout << "Registration no.: " << lowestSalaryEmployee->regId << endl;
	        cout << "Age: " << lowestSalaryEmployee->age << endl;
	        cout << "Gender: " << lowestSalaryEmployee->gender << endl;
	        cout << "Education level: " << lowestSalaryEmployee->edu << endl;
	        cout << "Job title: " << lowestSalaryEmployee->job << endl;
	        cout << "Experience level: " << lowestSalaryEmployee->lvlOfExp << " years" << endl;
	        cout << "Salary: " << lowestSalaryEmployee->salary << endl;
	    } else {
	        cout << "No employee found with the specified education level." << endl;
	    }
	}
};

int main(){

	Orgnanization org;
	ifstream inputFile("Data.csv");
    if (!inputFile) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    vector<Node*> employeeData;

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string regNum, gender, eduLvl, jobTtl;
        int age, exp, salary;

        if (getline(ss, regNum, ',') &&
            ss >> age && ss.ignore() &&
            getline(ss, gender, ',') &&
            getline(ss, eduLvl, ',') &&
            getline(ss, jobTtl, ',') &&
            ss >> exp && ss.ignore() &&
            ss >> salary)
        {
        	
        	Node* p = new Node(regNum, age, gender, eduLvl, jobTtl, exp, salary);
            org.insertRegNo(p);
        } else {
            cerr << "Invalid data format in the CSV file." << endl;
            return 1;
        }
    }

    inputFile.close();
	int choice;
	string eduLevel, gender, search;
	do {
		cout<<endl;
        cout << "================== Main Menu ===================" << endl;
        cout << "1.  View all employees" << endl;
        cout << "2.  Reg no. of Highest salary employee/employees" << endl;
        cout << "3.  Reg no. of lowest salary employee" << endl;
        cout << "4.  Most common education level in organization" << endl;
        cout << "5.  Average experience level of employees in orgnization" << endl;
        cout << "6.  Average age of employee in organization" << endl;
        cout << "7.  Most common gender in organization" << endl;
        cout << "8.  Average salary of employees in organization" << endl;
        cout << "9.  Most experience employee/employees" << endl;
        cout << "10. View employee with respect to there salary" << endl;
        cout << "11. Most aged employee/employees in organization" << endl;
        cout << "12. Most youngest employee/employees in organization" << endl;
        cout << "13. Promote employees" << endl;
        cout << "14. Youngest employee by education level" << endl;
        cout << "15. Oldest employee by education level" << endl;
        cout << "16. Search employee by its reg no." << endl;
        cout << "17. View employee by gender" << endl;
        cout << "18. Highest salary by education level" << endl;
        cout << "19. Lowest salary by education level" << endl;
        cout << "20. EXIT"<<endl;
        cout << "==============================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                org.display();
                break;
            case 2:
                org.HighestSalaryEmployees();
                break;
            case 3:
               org.LowestSalaryEmployees();
                break;
            case 4:
                cout<<"Most common education level is: "<<org.MostCommonEducationLevel();
                break;
            case 5:
                cout<<"Average experience level of employees is: "<<org.averageExpLvl();
                break;
            case 6:
                cout<<"Average age of employees is: "<<org.averageAge();
                break;
            case 7:
                cout<<"Most common gender is: "<<org.MostCommonGender();
                break;
            case 8:
                cout<<"Average salary of employees is: "<<org.averageSalary();
                break;
            case 9:
                org.MostExperiencedEmployees();
                break;
            case 10:
                org.ViewEmployeesBySalary();
                break;
            case 11:
                org.MostAgedEmployee();
                break;
            case 12:
            	org.MostYoungestEmployee();
                break;
            case 13:
               	int expLvl,increment;
                cout<<"Enter minimum experience for promotion: ";
                cin>>expLvl;
                cout<<"Enter there salary increment: ";
                cin>>increment;
                org.promoteEmployees(expLvl , increment);
                break;
            case 14:
            	cout<<"Enter he education level in which you find youngest employee(Bachelor's , Master's , Phd): ";
            	cin>>eduLevel;
            	org.YoungestEmployeeByEducation(eduLevel);
                break;
            case 15:
                cout<<"Enter he education level in which you find oldest employee(Bachelor's , Master's , Phd): ";
            	cin>>eduLevel;
            	org.OldestEmployeeByEducationLevel(eduLevel);
                break;
            case 16:
            	cout<<"Enter employee registration id to search: ";
            	cin>>search;
            	if (org.IsEmployeeExists(search)) {
    				cout << "Employee exists." << endl;
				} else {
    				cout << "Employee does not exist." << endl;
				}
            	break;
            case 17:
            	cout<<"Enter gender of employees to view there data(Male, Female): ";
            	cin>>gender;
            	org.ViewEmployeesByGender(gender);
            	break;
            case 18:
            	cout<<"Enter he education level in which you find highest employee salary(Bachelor's , Master's , Phd): ";
            	cin>>eduLevel;
            	org.HighestSalaryByEducation(eduLevel);
            	break;
            case 19:
            	cout<<"Enter he education level in which you find lowest employee salary(Bachelor's , Master's , Phd): ";
            	cin>>eduLevel;
            	org.LowestSalaryByEducation(eduLevel);
            	break;
            case 20:
            	break;
            default:
                cout << "INVALID OPTION, Please choose correct option." << endl;
                break;
        }

        cout << endl;

    } while (choice != 20);
	cout<<"You are exited from the organization";
}
