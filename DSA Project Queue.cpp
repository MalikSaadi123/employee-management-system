#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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

struct Node* front = NULL;
struct Node* rear = NULL;
class Enqueue{
public:
void enqueue(string r, int a,string gen, string edu, string jobT, int year, double sal) {
    Node* new_node = new Node(r,a,gen,  edu,  jobT,  year, sal);
    new_node->next = NULL;

    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty. Cannot dequeue element." << endl;
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << "Reg No: " << temp->regNo << endl;
            cout<<"Age : "<<temp->age<<endl;
            cout << "Gender: " << temp->gender << endl;
            cout << "Education: " << temp->education << endl;
            cout << "Job Title: " << temp->jobTitle << endl;
            cout << "Years of Experience: " << temp->yearOfExperience << endl;
            cout << "Salary: " << temp->salary << endl;
            cout << endl;
            temp = temp->next;
        }
    }
Node* GetOldestEmployee(Node* front) {
    if (front == NULL) {
        return NULL;
    }

    Node* oldestEmployee = front;
    Node* current = front->next;

    while (current != NULL) {
        if (current->yearOfExperience > oldestEmployee->yearOfExperience) {
            oldestEmployee = current;
        }
        current = current->next;
    }

    return oldestEmployee;
}

Node* GetNewestEmployee(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* newestEmployee = head;
    Node* current = head->next;

    while (current != NULL) {
        if (current->yearOfExperience < newestEmployee->yearOfExperience) {
            newestEmployee = current;
        }
        current = current->next;
    }

    return newestEmployee;
}
Node* GetHighestPaidEmployee(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* highestPaidEmployee = head;
    Node* current = head->next;

    while (current != NULL) {
        if (current->salary > highestPaidEmployee->salary) {
            highestPaidEmployee = current;
        }
        current = current->next;
    }

    return highestPaidEmployee;
}

Node* GetLowestPaidEmployee(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* lowestPaidEmployee = head;
    Node* current = head->next;

    while (current != NULL) {
        if (current->salary < lowestPaidEmployee->salary) {
            lowestPaidEmployee = current;
        }
        current = current->next;
    }

    return lowestPaidEmployee;
}
double getAverageSalary() {
    if (front == NULL) {
        cout << "Queue is empty. Cannot calculate average salary." << endl;
        return 0.0;
    }

    Node* current = front;
    double sum = 0.0;
    int count = 0;

    while (current != NULL) {
        sum += current->salary;
        count++;
        current = current->next;
    }

    return sum / count;
}

int countByGender(string gender) {
    if (front == NULL) {
        cout << "Queue is empty. No nodes to count." << endl;
        return 0;
    }

    Node* current = front;
    int count = 0;

    while (current != NULL) {
        if (current->gender == gender) {
            count++;
        }
        current = current->next;
    }

    return count;
}
int countByEducation(string education) {
    if (front == NULL) {
        cout << "Queue is empty. No nodes to count." << endl;
        return 0;
    }

    Node* current = front;
    int count = 0;

    while (current != NULL) {
        if (current->education == education) {
            count++;
        }
        current = current->next;
    }

    return count;
}
int countByJobTitle(string jobTitle) {
    if (front == NULL) {
        cout << "Queue is empty. No nodes to count." << endl;
        return 0;
    }

    Node* current = front;
    int count = 0;

    while (current != NULL) {
        if (current->jobTitle == jobTitle) {
            count++;
        }
        current = current->next;
    }

    return count;
}

void selectionSort() {
    if (front == NULL) {
        cout << "Queue is empty. Cannot perform selection sort." << endl;
        return;
    }

    Node* current = front;

    while (current != NULL) {
        Node* minNode = current;
        Node* nextNode = current->next;

        while (nextNode != NULL) {
            if (nextNode->age < minNode->age) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        if (minNode != current) {
            swapNodes(current, minNode);
        }

        current = current->next;
    }

    cout << "Selection sort completed." << endl;
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
    Enqueue e;
    ifstream fin("data.csv");
    string line, word;
    vector<string> lineData;

    while (getline(fin, line)) {
        stringstream s(line);
        while (getline(s, word, ',')) {
            lineData.push_back(word);
        }

        string regNo = lineData[0];
        string ageStr = lineData[1];
        int age;
        stringstream(ageStr) >> age;

        string gender = lineData[2];
        string education = lineData[3];
        string jobTitle = lineData[4];

        string expStr = lineData[5];
        int exp;
        stringstream(expStr) >> exp;

        string salaryStr = lineData[6];
        double salary;
        stringstream(salaryStr) >> salary;

        e.enqueue(regNo, age, gender, education, jobTitle, exp, salary);

        lineData.clear();
    }

    fin.close();

    int choice;
    string input;

    do {
        cout << "\n--- Selection Menu ---" << endl;
        cout << "1. Get Oldest Employee\n";
        cout << "2. Get Newest Employee\n";
        cout << "3. Get Highest Paid Employee\n";
        cout << "4. Get Lowest Paid Employee\n";
        cout << "5. Get Average Salary\n";
        cout << "6. Count Employees by Gender\n";
        cout << "7. Count Employees by Education\n";
        cout << "8. Count Employees by Job Title\n";
        cout << "9. Perform Selection Sort\n";
        cout << "10. Display All Values\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << e.GetOldestEmployee(front)->regNo;
                break;
            case 2:
                cout << e.GetNewestEmployee(front)->regNo;
                break;
            case 3:
                cout << e.GetHighestPaidEmployee(front)->regNo;
                break;
            case 4:
                cout << e.GetLowestPaidEmployee(front)->regNo;
                break;
            case 5:
                cout << e.getAverageSalary();
                break;
            case 6:
                cout << "Enter gender value: ";
                cin >> input;
                cout << e.countByGender(input);
                break;
            case 7:
                cout << "Enter education value: ";
                cin >> input;
                cout << e.countByEducation(input);
                break;
            case 8:
                cout << "Enter job title value: ";
                cin >> input;
                cout << e.countByJobTitle(input);
                break;
            case 9:
                e.selectionSort();
                e.display();
                break;
            case 10:
                e.display();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

}


