#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std; 

const int TABLE_SIZE = 200;

struct Employee {
    string registrationNumber;
    int age;
    string gender;
    string educationLevel;
    string jobTitle;
    int yearsOfExperience;
    int salary;
    Employee* next;

    Employee(string regNum, int empAge, string empGender, string eduLvl, string jobTtl, int exp, int empSalary){
    	registrationNumber = regNum;
		age = empAge;
		gender = empGender;
		educationLevel = eduLvl;
		jobTitle = jobTtl;
        yearsOfExperience = exp;
		salary = empSalary;
		next = NULL;
	}
       
};

class HashTable {
public:
    Employee* table[TABLE_SIZE];
    HashTable() {        
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

	int hashFunction(string key) {
	    int sum = 0;
	    for (int i = 0; i < key.length(); i++) {
	        sum += key[i];
	    }
	    return sum % 199;
	}

    void insertEmployee(Employee* emp) {
        int index = hashFunction(emp->registrationNumber);

        if (table[index] == NULL) {
            table[index] = emp;
        } else {
            Employee* curr = table[index];
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = emp;
        }
    }

    Employee* searchEmployee(string regNum) {
        int index = hashFunction(regNum);

        Employee* curr = table[index];
        while (curr != NULL) {
            if (curr->registrationNumber == regNum) {
                return curr;
            }
            curr = curr->next;
        }

        return NULL;
    }
    
     Employee* BinarySearch(string regNum, int low, int high) {
        if (low > high) {
            return NULL;
        }

        int mid = (low + high) / 2;
        Employee* midEmployee = searchEmployee(regNum);

        if (midEmployee == NULL) {
            return NULL;
        }

        if (midEmployee->registrationNumber == regNum) {
            return midEmployee;
        } else if (midEmployee->registrationNumber > regNum) {
            return BinarySearch(regNum, low, mid - 1);
        } else {
            return BinarySearch(regNum, mid + 1, high);
        }
    }

    void removeEmployee(string regNum) {
        int index = hashFunction(regNum);

        Employee* curr = table[index];
        Employee* prev = NULL;

        while (curr != NULL) {
            if (curr->registrationNumber == regNum) {
                if (prev == NULL) {
                    table[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    
    void displayEmployee(Employee* emp) {
        cout << "\nRegistration Number: " << emp->registrationNumber << endl;
        cout << "Age: " << emp->age << endl;
        cout << "Gender: " << emp->gender << endl;
        cout << "Education Level: " << emp->educationLevel << endl;
        cout << "Job Title: " << emp->jobTitle << endl;
        cout << "Years of Experience: " << emp->yearsOfExperience << endl;
        cout << "Salary: " << emp->salary << endl << endl;
	    cout << "-----------------------" << endl;
    }
    
    void viewAllEmployees() {
	    for (int i = 0; i < TABLE_SIZE; i++) {
	        Employee* curr = table[i];
	        while (curr != NULL) {
	        	displayEmployee(curr);
	            curr = curr->next;
	        }
	    }
	}
	
	void viewEmployeesByAge(int ageThreshold, bool isGreater) {
	    if (isGreater) {
	        cout << "Employees older than " << ageThreshold << ":" << endl;
	        for (int i = 0; i < TABLE_SIZE; i++) {
	            Employee* curr = table[i];
	            while (curr != NULL) {
	                if (curr->age > ageThreshold) {
	        			displayEmployee(curr);
	                }
	                curr = curr->next;
	            }
	        }
	    } else {
	        cout << "Employees younger than " << ageThreshold << ":" << endl;
	        for (int i = 0; i < TABLE_SIZE; i++) {
	            Employee* curr = table[i];
	            while (curr != NULL) {
	                if (curr->age < ageThreshold) {
	                	displayEmployee(curr);
	                }
	                curr = curr->next;
	            }
	        }
	    }
	}

	
	void viewEmployeesByGender( string gender) {
	    for (int i = 0; i < TABLE_SIZE; i++) {
	        Employee* curr = table[i];
	        while (curr != NULL) {
	            if (curr->gender == gender) {
	            	displayEmployee(curr);
	            }
	            curr = curr->next;
	        }
	    }
	}
	
	void viewEmployeesByEducation(string eduLevel) {
        bool found = false;

        for (int i = 0; i < TABLE_SIZE; i++) {
            Employee* curr = table[i];
            while (curr != NULL) {
                if (curr->educationLevel == eduLevel) {
                	displayEmployee(curr);
                    found = true;
                }
                curr = curr->next;
            }
        }

        if (!found) {
            cout << "No employees found with the education level: " << eduLevel << endl;
        }
    }

	void viewEmployeesByExperience(int limit, bool greaterThan) {
	    if (greaterThan) {
	        for (int i = 0; i < TABLE_SIZE; i++) {
	            Employee* curr = table[i];
	            while (curr != NULL) {
	                if (curr->yearsOfExperience > limit) {
	                	displayEmployee(curr);
	                }
	                curr = curr->next;
	            }
	        }
	    } else {
	        for (int i = 0; i < TABLE_SIZE; i++) {
	            Employee* curr = table[i];
	            while (curr != NULL) {
	                if (curr->yearsOfExperience < limit) {
	                	displayEmployee(curr);
	                }
	                curr = curr->next;
	            }
	        }
	    }
	}

		
	void viewEmployeesBySalary(int threshold, bool isGreater) {
	    if (isGreater) {
	        for (int i = 0; i < TABLE_SIZE; i++) {
	            Employee* curr = table[i];
	            while (curr != NULL) {
	                if (curr->salary > threshold) {
	                	displayEmployee(curr);
	                }
	                curr = curr->next;
	            }
	        }
	    } else {
	        for (int i = 0; i < TABLE_SIZE; i++) {
	            Employee* curr = table[i];
	            while (curr != NULL) {
	                if (curr->salary < threshold) {
	                	displayEmployee(curr);
	                }
	                curr = curr->next;
	            }
	        }
	    }
	}
	
	void promoteEmployees() {
	    for (int i = 0; i < TABLE_SIZE; i++) {
	        Employee* curr = table[i];
	        while (curr != NULL) {
	            if (curr->educationLevel == "Bachelor's") {
	                if (curr->yearsOfExperience >= 5) {
	                    curr->jobTitle = "Senior " + curr->jobTitle;
	                    curr->salary += 10000;
	                }
	            } else if (curr->educationLevel == "Master's") {
	                if (curr->yearsOfExperience >= 3) {
	                    curr->jobTitle = "Lead " + curr->jobTitle;
	                    curr->salary += 15000;
	                }
	            } else if (curr->educationLevel == "PhD") {
	                if (curr->yearsOfExperience >= 10) {
	                    curr->jobTitle = "Principal " + curr->jobTitle;
	                    curr->salary += 20000;
	                }
	            }
	            curr = curr->next;
	        }
	    }
	}
	
	void calculateTotalBudget() {
	    int totalBudget = 0;
	
	    for (int i = 0; i < TABLE_SIZE; i++) {
	        Employee* curr = table[i];
	        while (curr != NULL) {
	            totalBudget += curr->salary;
	            curr = curr->next;
	        }
	    }
	
	    cout << "Total Budget: " << totalBudget << endl;
	}

	void getAverageSalary() {
	    int totalSalary = 0;
	    int employeeCount = 0;
	
	    for (int i = 0; i < TABLE_SIZE; i++) {
	        Employee* curr = table[i];
	        while (curr != NULL) {
	            totalSalary += curr->salary;
	            employeeCount++;
	            curr = curr->next;
	        }
	    }
	
	    if (employeeCount > 0) {
	        double averageSalary = static_cast<double>(totalSalary) / employeeCount;
	        cout << "Average Salary: " << averageSalary << endl;
	    } else {
	        cout << "No employees found." << endl;
	    }
	}
	
	void merge(Employee* arr[], int left, int mid, int right) {
	    int i, j, k;
	    int n1 = mid - left + 1;
	    int n2 = right - mid;
	
	    Employee* L[n1], *R[n2];
	
	    for (i = 0; i < n1; i++)
	        L[i] = arr[left + i];
	    for (j = 0; j < n2; j++)
	        R[j] = arr[mid + 1 + j];
	
	    i = 0;
	    j = 0;
	    k = left;
	
	    while (i < n1 && j < n2) {
	        if (L[i]->salary <= R[j]->salary) {
	            arr[k] = L[i];
	            i++;
	        } else {
	            arr[k] = R[j];
	            j++;
	        }
	        k++;
	    }
	
	    while (i < n1) {
	        arr[k] = L[i];
	        i++;
	        k++;
	    }
	
	    while (j < n2) {
	        arr[k] = R[j];
	        j++;
	        k++;
	    }
	}
	
	void mergeSort(Employee* arr[], int left, int right) {
	    if (left < right) {
	        int mid = left + (right - left) / 2;
	
	        mergeSort(arr, left, mid);
	        mergeSort(arr, mid + 1, right);
	
	        merge(arr, left, mid, right);
	    }
	}
	
	void mergeSortBySalary() {
	    Employee* tempArray[TABLE_SIZE];
	    int index = 0;
	
	    for (int i = 0; i < TABLE_SIZE; i++) {
	        Employee* curr = table[i];
	        while (curr != NULL) {
	            tempArray[index++] = curr;
	            curr = curr->next;
	        }
	    }
	
	    mergeSort(tempArray, 0, index - 1);
	
	    cout << "Employees sorted by salary:" << endl;
	    for (int i = 0; i < index; i++) {
	        displayEmployee(tempArray[i]);
	    }
	}
	
	void insertionSort(Employee* arr[], int n) {
	    for (int i = 1; i < n; i++) {
	        Employee* key = arr[i];
	        int j = i - 1;
	
	        while (j >= 0 && arr[j]->salary > key->salary) {
	            arr[j + 1] = arr[j];
	            j = j - 1;
	        }
	
	        arr[j + 1] = key;
	    }
	}
	
	void insertionSortBySalary() {
	    Employee* tempArray[TABLE_SIZE];
	    int index = 0;
	
	    for (int i = 0; i < TABLE_SIZE; i++) {
	        Employee* curr = table[i];
	        while (curr != NULL) {
	            tempArray[index++] = curr;
	            curr = curr->next;
	        }
	    }
	
	    insertionSort(tempArray, index);
	
	    cout << "Employees sorted by salary:" << endl;
	    for (int i = 0; i < index; i++) {
	        displayEmployee(tempArray[i]);
	    }
	}
};

int main() {
    HashTable employees;

    ifstream inputFile("data.csv");
    if (!inputFile) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    vector<Employee*> employeeData;

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
            Employee* emp = new Employee(regNum, age, gender, eduLvl, jobTtl, exp, salary);
            employeeData.push_back(emp);
        } else {
            cerr << "Invalid data format in the CSV file." << endl;
            return 1;
        }
    }

    inputFile.close();

    for (size_t i = 0; i < employeeData.size(); i++) {
        employees.insertEmployee(employeeData[i]);
    }
    
    int choice;
    string regNum;
    int ageThreshold;
    string gender;
    string eduLevel;
    int expLimit;
    int salaryThreshold;
    string searchKey;
	string cho;

    do {
        cout << "========== Main Menu ==========" << endl;
        cout << "1. View all employees" << endl;
        cout << "2. Search for an employee (Linear Search)" << endl;
        cout << "3. Search for an employee (Binary Search)" << endl;
        cout << "4. Remove an employee" << endl;
        cout << "5. View employees older than a specific age" << endl;
        cout << "6. View employees younger than a specific age" << endl;
        cout << "7. View employees by gender" << endl;
        cout << "8. View employees by education level" << endl;
        cout << "9. View employees by experience" << endl;
        cout << "10. View employees by salary" << endl;
        cout << "11. Promote employees" << endl;
        cout << "12. Calculate total budget" << endl;
        cout << "13. Calculate average salary" << endl;
        cout << "14. Sort employees by salary (Merge Sort)" << endl;
        cout << "15. Sort employees by salary (Insertion Sort)" << endl;
        cout << "0. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                employees.viewAllEmployees();
                break;
            case 2:
                cout << "Enter the registration number of the employee: ";
                cin >> regNum;
                cout << endl;
                {
                    Employee* emp = employees.searchEmployee(regNum);
                    if (emp != NULL) {
                        employees.displayEmployee(emp);
                    } else {
                        cout << "Employee with registration number " << regNum << " not found." << endl;
                    }
                }
                break;
            case 3:
                cout << "Enter the registration number of the employee: ";
                cin >> regNum;
                cout << endl;
                {
                    Employee* emp = employees.BinarySearch(regNum, 0, TABLE_SIZE-1);
                    if (emp != NULL) {
                        employees.displayEmployee(emp);
                    } else {
                        cout << "Employee with registration number " << regNum << " not found." << endl;
                    }
                }
                break;
            case 4:
                cout << "Enter the registration number of the employee to remove: ";
                cin >> regNum;
                cout << endl;
                employees.removeEmployee(regNum);
                break;
            case 5:
                cout << "Enter the age threshold: ";
                cin >> ageThreshold;
                cout << endl;
                employees.viewEmployeesByAge(ageThreshold, true);
                break;
            case 6:
                cout << "Enter the age threshold: ";
                cin >> ageThreshold;
                cout << endl;
                employees.viewEmployeesByAge(ageThreshold, false);
                break;
            case 7:
                cout << "Enter the gender (Male/Female): ";
                cin >> gender;
                cout << endl;
                employees.viewEmployeesByGender(gender);
                break;
            case 8:
                cout << "Enter the education level (Bachelor's/Master's/PhD): ";
                cin >> eduLevel;
                cout << endl;
                employees.viewEmployeesByEducation(eduLevel);
                break;
            case 9:
                cout << "Enter the experience limit: ";
                cin >> expLimit;
                cout << endl;
                cout << "Greater than from "<<expLimit<<" or Lesser? (Y/N) : ";
                cin>>cho;
                if(cho == "Y"){
                	employees.viewEmployeesByExperience(expLimit, true);
                }else if(cho == "N"){
                	
                	employees.viewEmployeesByExperience(expLimit, false);
				}
                break;
            case 10:
                cout << "Enter the salary threshold: ";
                cin >> salaryThreshold;
                cout << endl;
                cout << "Greater than from "<<salaryThreshold<<" or Lesser? (Y/N) : ";
                cin>>cho;
                if(cho == "Y"){
                	employees.viewEmployeesBySalary(salaryThreshold, true);
                }else if(cho == "N"){                	
                	employees.viewEmployeesBySalary(salaryThreshold, false);
				}
                break;
            case 11:
                employees.promoteEmployees();
                break;
            case 12:
                employees.calculateTotalBudget();
                break;
            case 13:
                employees.getAverageSalary();
                break;
            case 14:
                employees.mergeSortBySalary();
                break;
            case 15:
                employees.insertionSortBySalary();
                break;
            case 0:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;

    } while (choice != 0);

    // Free allocated memory
    for (int i = 0; i < employeeData.size(); i++) {
        delete employeeData[i];
    }

}

