#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Node {

    string regNo;
    int age;
    string gender;
    string education;
    string jobTitle;
    int yearOfExperience;
    double salary;
    Node* next;

    Node(string regNo, int age,string gender, string education, string jobTitle, int yearOfExperience, double salary) {
        this->regNo = regNo;
        this->age = age;
        this->gender = gender;
        this->education = education;
        this->jobTitle = jobTitle;
        this->yearOfExperience = yearOfExperience;
        this->salary = salary;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* first;
public:
    LinkedList() {
        first = head = NULL;
    }

    void insertAtFront(string regNo,int age , string gender, string education, string jobTitle, int yearOfExperience, double salary) {
        Node* newNode = new Node(regNo,age, gender, education, jobTitle, yearOfExperience, salary);
		newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(string regNo,int age ,string gender, string education, string jobTitle, int yearOfExperience, double salary) {
        Node* newNode = new Node(regNo,age,  gender, education, jobTitle, yearOfExperience, salary);
        if (head == NULL) {
            first = head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAfterNode(string regNo, int age ,string gender, string education, string jobTitle, int yearOfExperience, double salary, string targetRegNo) {
        Node* newNode = new Node(regNo,age, gender, education, jobTitle, yearOfExperience, salary);
        Node* temp = head;
        while (temp != NULL && temp->regNo != targetRegNo) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Target node not found!" << endl;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteAtFront() {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node at the front deleted." << endl;
        }
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
        } else if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Reg No: " << temp->regNo << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Gender: " << temp->gender << endl;
            cout << "Education: " << temp->education << endl;
            cout << "Job Title: " << temp->jobTitle << endl;
            cout << "Years of Experience: " << temp->yearOfExperience << endl;
            cout << "Salary: " << temp->salary << endl;
            cout << endl;
            temp = temp->next;
        }
    }
    
    void deleteByKey(string regNo) {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
            return;
        }

      
        if (head->regNo == regNo) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node with regNo " << regNo << " deleted." << endl;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        
        while (curr != NULL && curr->regNo != regNo) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Node with regNo " << regNo << " not found." << endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Node with regNo " << regNo << " deleted." << endl;
    }

    Node* searchByKey(string regNo) {
        Node* curr = head;
        while (curr != NULL) {
            if (curr->regNo == regNo) {
                cout << "Node with regNo " << regNo << " found." << endl;
                return curr;
            }
            curr = curr->next;
        }

        cout << "Node with regNo " << regNo << " not found." << endl;
        return NULL;
    }
    
     double getAverageSalary() {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
            return 0.0;
        }

        Node* curr = head;
        double totalSalary = 0.0;
        int count = 0;

        while (curr != NULL) {
            totalSalary += curr->salary;
            count++;
            curr = curr->next;
        }

        double averageSalary = totalSalary / count;
        return averageSalary;
    }

    Node* getMaxSalary() {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
            return NULL;
        }

        Node* maxNode = head;
        Node* curr = head->next;

        while (curr != NULL) {
            if (curr->salary > maxNode->salary) {
                maxNode = curr;
            }
            curr = curr->next;
        }

        return maxNode;
    }

    Node* getMinSalary() {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
            return NULL;
        }

        Node* minNode = head;
        Node* curr = head->next;

        while (curr != NULL) {
            if (curr->salary < minNode->salary) {
                minNode = curr;
            }
            curr = curr->next;
        }

        return minNode;
    }

    int getTotalExperience() {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
            return 0;
        }

        Node* curr = head;
        int totalExperience = 0;

        while (curr != NULL) {
            totalExperience += curr->yearOfExperience;
            curr = curr->next;
        }

        return totalExperience;
    }
    

    int countByGender(string gender) {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
            return 0;
        }

        Node* curr = head;
        int count = 0;

        while (curr != NULL) {
            if (curr->gender == gender) {
                count++;
            }
            curr = curr->next;
        }

        return count;
    }

    int countByEducation(string education) {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
            return 0;
        }

        Node* curr = head;
        int count = 0;

        while (curr != NULL) {
            if (curr->education == education) {
                count++;
            }
            curr = curr->next;
        }

        return count;
    }

    Node* getOldestEmployee() {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
            return NULL;
        }

        Node* oldestNode = head;
        Node* curr = head->next;

        while (curr != NULL) {
            if (curr->yearOfExperience > oldestNode->yearOfExperience) {
                oldestNode = curr;
            }
            curr = curr->next;
        }

        return oldestNode;
    }

    Node* getNewestEmployee() {
        if (head == NULL) {
            cout << "Linked list is empty!" << endl;
            return NULL;
        }

        Node* newestNode = head;
        Node* curr = head->next;

        while (curr != NULL) {
            if (curr->yearOfExperience < newestNode->yearOfExperience) {
                newestNode = curr;
            }
            curr = curr->next;
        }

        return newestNode;
    }
    
    
    void bubbleSortLinkedList() {
    if (head == NULL || head->next == NULL) {
        return;
    }
    
    bool swapped;
    Node* current;
    Node* last = NULL;
    
    do {
        swapped = false;
        current = head;
        
        while (current->next != last) {
            if (current->age > current->next->age) {
                swapNodes(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

void swapNodes(Node* node1, Node* node2) {
    string tempRegNo = node1->regNo;
    int tempAge = node1->age;
    string tempGender = node1->gender;
    string tempEducation = node1->education;
    string tempJobTitle = node1->jobTitle;
    int tempYearOfExperience = node1->yearOfExperience;
    double tempSalary = node1->salary;
    
    node1->regNo = node2->regNo;
    node1->age = node2->age;
    node1->gender = node2->gender;
    node1->education = node2->education;
    node1->jobTitle = node2->jobTitle;
    node1->yearOfExperience = node2->yearOfExperience;
    node1->salary = node2->salary;
    
    node2->regNo = tempRegNo;
    node2->age = tempAge;
    node2->gender = tempGender;
    node2->education = tempEducation;
    node2->jobTitle = tempJobTitle;
    node2->yearOfExperience = tempYearOfExperience;
    node2->salary = tempSalary;
}

    

};

int main() {
    LinkedList list;
   
     ifstream inputFile("data.csv");
    if (!inputFile) {
        cerr << "Failed to open the file." << endl;
        return 1;
	}
	string regNum, gender, eduLvl, jobTtl;
        int age, exp, salary;
    vector<Node*> employeeData;
    
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);

        if (getline(ss, regNum, ',') &&
            ss >> age && ss.ignore() &&
            getline(ss, gender, ',') &&
            getline(ss, eduLvl, ',') &&
            getline(ss, jobTtl, ',') &&
            ss >> exp && ss.ignore() &&
            ss >> salary)
         list.insertAtEnd(regNum, age,gender, eduLvl, jobTtl, exp, salary);
        	
    }

    inputFile.close();
    
	
	
	int choice;
    do {
        cout << "===== Selection Menu =====" << endl;
        
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After Node" << endl;
        cout << "4. Delete at Front" << endl;
        cout << "5. Delete at End" << endl;
        cout << "6. Delete by Key" << endl;
        cout << "7. Search by Key" << endl;
        cout << "8. Get Average Salary" << endl;
        cout << "9. Get Max Salary" << endl;
        cout << "10. Get Min Salary" << endl;
        cout << "11. Get Total Experience" << endl;
        cout << "12. Count by Gender" << endl;
        cout << "13. Count by Education" << endl;
        cout << "14. Get Oldest Employee" << endl;
        cout << "15. Get Newest Employee" << endl;
        cout <<"16. Displaying List" << endl;
        cout <<"17. Bubble Sort" << endl;
        cout << "0. Exit" << endl;
        cout << "=========================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter Registration Number: ";
                cin >> regNum;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Gender: ";
                cin >> gender;
                cout << "Enter Education Level: ";
                cin >> eduLvl;
                cout << "Enter Job Title: ";
                cin >> jobTtl;
                cout << "Enter Years of Experience: ";
                cin >> exp;
                cout << "Enter Salary: ";
                cin >> salary;

                list.insertAtFront(regNum, age, gender, eduLvl, jobTtl, exp, salary);
                cout << "Node inserted at the front." << endl;
                break;
            }
            case 2: {
                cout << "Enter Registration Number: ";
                cin >> regNum;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Gender: ";
                cin >> gender;
                cout << "Enter Education Level: ";
                cin >> eduLvl;
                cout << "Enter Job Title: ";
                cin >> jobTtl;
                cout << "Enter Years of Experience: ";
                cin >> exp;
                cout << "Enter Salary: ";
                cin >> salary;

                list.insertAtEnd(regNum, age, gender, eduLvl, jobTtl, exp, salary);
                cout << "Node inserted at the end." << endl;
                break;
            }
            case 3: {
                string targetRegNo;
                cout << "Enter Target Registration Number: ";
                cin >> targetRegNo;
                cout << "Enter Registration Number: ";
                cin >> regNum;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Gender: ";
                cin >> gender;
                cout << "Enter Education Level: ";
                cin >> eduLvl;
                cout << "Enter Job Title: ";
                cin >> jobTtl;
                cout << "Enter Years of Experience: ";
                cin >> exp;
                cout << "Enter Salary: ";
                cin >> salary;

                list.insertAfterNode(regNum, age, gender, eduLvl, jobTtl, exp, salary, targetRegNo);
                cout << "Node inserted after " << targetRegNo << "." << endl;
                break;
            }
            case 4: {
                list.deleteAtFront(); 
                cout<< endl;
                break;
            }
            case 5: {
                list.deleteAtEnd();
                cout<< endl;
                break;
            }
            case 6: {
            	string n;
            	cout<<"Enter The Reg-Id To Delete:";
            	cin>>n;
                list.deleteByKey(n);
                cout<< endl;
                break;
            }
            case 7: {
            	string n;
            	cout<<"Enter The Reg-Id To Search:";
            	cin>>n;
                cout<<"\nThe Salary Of "<<n<< " Is:"<<list.searchByKey(n)->salary;
                cout<< endl;
                break;
            }
            case 8: {
               cout<<list.getAverageSalary();
               cout<< endl;
                break;
            }
            case 9: {
                cout<<list.getMaxSalary()->salary;
                cout<< endl;
                break;
            }
            case 10: {
                cout<<list.getMinSalary()->salary;
                cout<< endl;
                break;
            }
            case 11: {
                cout<<list.getTotalExperience();
                cout<< endl;
                break;
            }
            case 12: {
            	string n;
            	cout<<"Enter The Gender:";
            	cin>>n;
                cout<<list.countByGender(n);
                cout<< endl;
                break;
            }
            case 13: {
            	string n;
            	cout<<"Enter The Educational Level:";
            	cin>>n;
				cout<<list.countByEducation(n);
				cout<< endl;
                break;
            }
            case 14: {
                cout<<list.getOldestEmployee()->regNo;
                cout<< endl;
                break;
            }
            case 15: {
                cout<<list.getNewestEmployee()->regNo;
                cout<< endl;
                break;
            }
            case 16: {
				list.display();
				cout<< endl;
                break;
            }
            case 17: {
				list.bubbleSortLinkedList();
				list.display();
				cout<< endl;
                break;
            }
            case 0: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
        while (choice != 0);
}

