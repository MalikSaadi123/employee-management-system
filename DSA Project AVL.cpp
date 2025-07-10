#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

struct Node {
    string regNum;
    int age;
    string gender;
    string eduLvl;
    string jobTtl;
    int exp;
    int salary;
    Node* left;
    Node* right;
    int height;
};

int height(Node* h) {
    if (h == NULL) {
        return 0;
    }
    return h->height;
}

int maxHeight(int l, int r) {
    if (l > r) {
        return l;
    }
    else if (r > l) {
        return r;
    }
}

Node* newNode(string regNum, int age, string gender, string eduLvl, string jobTtl, int exp, int salary) {
    Node* p = new Node();
    p->regNum = regNum;
    p->age = age;
    p->gender = gender;
    p->eduLvl = eduLvl;
    p->jobTtl = jobTtl;
    p->exp = exp;
    p->salary = salary;
    p->right = NULL;
    p->left = NULL;
    p->height = 1;
    return p;
}

Node* rightRotate(Node* root) {
    Node* x = root->left;
    Node* y = x->right;
    x->right = root;
    root->left = y;
    root->height = maxHeight(height(root->left), height(root->right)) + 1;
    x->height = maxHeight(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* root) {
    Node* x = root->right;
    Node* y = x->left;
    x->left = root;
    root->right = y;
    root->height = maxHeight(height(root->left), height(root->right)) + 1;
    x->height = maxHeight(height(x->left), height(x->right)) + 1;
    return x;
}

int getBalance(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

Node* insert(Node* root, Node* p) {
    if (root == NULL) {
        return p;
    }
    if (p->regNum < root->regNum) {
        root->left = insert(root->left, p);
    }
    else if (p->regNum > root->regNum) {
        root->right = insert(root->right, p);
    }
    else {
        return root;
    }
    root->height = maxHeight(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    if (balance > 1 && p->regNum < root->left->regNum) {
        return rightRotate(root);
    }
    if (balance < -1 && p->regNum > root->right->regNum) {
        return leftRotate(root);
    }
    if (balance > 1 && p->regNum > root->left->regNum) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && p->regNum < root->right->regNum) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* smallestRegNo(Node* root){
	Node* current = root;
	while(current->left != NULL){
		current = current->left;
	}
	return current;
}
bool deleteNodeByRegNo(Node*& root, const string& regNo) {
    if (root == NULL)
        return false;

    if (regNo < root->regNum)
        return deleteNodeByRegNo(root->left, regNo);
    else if (regNo > root->regNum)
        return deleteNodeByRegNo(root->right, regNo);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            Node* successor = smallestRegNo(root->right);
            root->regNum = successor->regNum;
            return deleteNodeByRegNo(root->right, successor->regNum);
        }

        return true;
    }
}
void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << "Registration Number: " << root->regNum << endl;
    cout << "Age: " << root->age << endl;
    cout << "Gender: " << root->gender << endl;
    cout << "Education Level: " << root->eduLvl << endl;
    cout << "Job Title: " << root->jobTtl << endl;
    cout << "Experience: " << root->exp << endl;
    cout << "Salary: " << root->salary << endl;
    cout << endl;
    inOrder(root->right);
}
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout << "Registration Number: " << root->regNum << endl;
    cout << "Age: " << root->age << endl;
    cout << "Gender: " << root->gender << endl;
    cout << "Education Level: " << root->eduLvl << endl;
    cout << "Job Title: " << root->jobTtl << endl;
    cout << "Experience: " << root->exp << endl;
    cout << "Salary: " << root->salary << endl;
    cout << endl;

}
void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << "Registration Number: " << root->regNum << endl;
    cout << "Age: " << root->age << endl;
    cout << "Gender: " << root->gender << endl;
    cout << "Education Level: " << root->eduLvl << endl;
    cout << "Job Title: " << root->jobTtl << endl;
    cout << "Experience: " << root->exp << endl;
    cout << "Salary: " << root->salary << endl;
    cout << endl;
    postOrder(root->left);
    postOrder(root->right);
}

void levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << "Registration Number: " << current->regNum << endl;
        cout << "Age: " << current->age << endl;
        cout << "Gender: " << current->gender << endl;
        cout << "Education Level: " << current->eduLvl << endl;
        cout << "Job Title: " << current->jobTtl << endl;
        cout << "Experience: " << current->exp << endl;
        cout << "Salary: " << current->salary << endl;
        cout << endl;
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}
bool isBalanced(Node* root) {
    if (root == NULL) {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int balanceFactor = leftHeight - rightHeight;

    if (balanceFactor < -1 || balanceFactor > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}
void printAllAboveExperience(Node* root, int targetExp) {
    if (root == NULL) {
        return;
    }

    printAllAboveExperience(root->left, targetExp);

    if (root->exp > targetExp) {
        cout << "Employee data:\n";
		cout << "Registration Number: " << root->regNum << endl;
		cout << "Age: " << root->age << endl;
		cout << "Gender: " << root->gender << endl;
		cout << "Education Level: " << root->eduLvl << endl;
		cout << "Job Title: " << root->jobTtl << endl;
		cout << "Experience: " << root->exp << endl;
		cout << "Salary: " << root->salary << endl;
		cout << endl;
    }
    printAllAboveExperience(root->right, targetExp);
}
void printAllAboveAge(Node* root, int targetAge) {
    if (root == NULL) {
        return;
    }

    printAllAboveAge(root->left, targetAge);

    if (root->age > targetAge) {
        cout << "Employee data:\n";
		cout << "Registration Number: " << root->regNum << endl;
		cout << "Age: " << root->age << endl;
		cout << "Gender: " << root->gender << endl;
		cout << "Education Level: " << root->eduLvl << endl;
		cout << "Job Title: " << root->jobTtl << endl;
		cout << "Experience: " << root->exp << endl;
		cout << "Salary: " << root->salary << endl;
		cout << endl;
    }
    printAllAboveAge(root->right, targetAge);
}

void printAllAboveSalary(Node* root, int targetSalary) {
    if (root == NULL) {
        return;
    }

    printAllAboveSalary(root->left, targetSalary);

    if (root->salary > targetSalary) {
        cout << "Employee data:\n";
		cout << "Registration Number: " << root->regNum << endl;
		cout << "Age: " << root->age << endl;
		cout << "Gender: " << root->gender << endl;
		cout << "Education Level: " << root->eduLvl << endl;
		cout << "Job Title: " << root->jobTtl << endl;
		cout << "Experience: " << root->exp << endl;
		cout << "Salary: " << root->salary << endl;
		cout << endl;
    }
    printAllAboveSalary(root->right, targetSalary);
}
int budget = 0;
int totalBudget(Node* root) {
    if (root == NULL) {
        return -1;
    }
    totalBudget(root->left);
    budget += root->salary;
    totalBudget(root->right);
    return budget;
}

int mostExp = -9999;
void findMostExperienced(Node* root) {
    if (root == NULL) {
        return;
    }
	
    if (root->exp > mostExp) {
        mostExp = root->exp;
    }

    findMostExperienced(root->left);
    findMostExperienced(root->right);
}

void printMostExperienced(Node* root) {
    if (root == NULL) {
        cout << "No employees found in the organization." << endl;
        return;
    }

    Node* maxExperienceNode = root;
    findMostExperienced(root);

    cout << "Employee with the Highest Experience: " << endl;
    cout << "Registration Number: " << maxExperienceNode->regNum << endl;
    cout << "Age: " << maxExperienceNode->age << endl;
    cout << "Gender: " << maxExperienceNode->gender << endl;
    cout << "Education Level: " << maxExperienceNode->eduLvl << endl;
    cout << "Job Title: " << maxExperienceNode->jobTtl << endl;
    cout << "Experience: " << maxExperienceNode->exp << endl;
    cout << "Salary: " << maxExperienceNode->salary << endl;
}
int main() {
    Node* root = NULL;

    ifstream inputFile("Data.csv");
    if (!inputFile) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

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
            Node* p = newNode(regNum, age, gender, eduLvl, jobTtl, exp, salary);
            root = insert(root, p);
        }
        else {
            cerr << "Invalid data format in the CSV file." << endl;
            return 1;
        }
    }
    

    inputFile.close();
	int choice, height1 ,exp1,age1,salary1;
	string regNo;
	bool isDeleted = false;
	
    do {
		cout<<endl;
        cout << "================== Main Menu ===================" << endl;
        cout << "1.  View all employees(In order traversal)" << endl;
        cout << "2.  View all employee(pre order traversal)" << endl;
        cout << "3.  View all employee(post order traversal)" << endl;
        cout << "4.  View all employee(Level order traversal)" << endl;
        cout << "5.  Kick employee from organization :-|" << endl;
        cout << "6.  Height of AVL tree" << endl;
        cout << "7.  Is tree is balanced?" << endl;
        cout << "8.  Employee having experience level above a specific experince level" << endl;
        cout << "9.  Employee having age above a specific age" << endl;
        cout << "10. Employee having salary above a specific salary" << endl;
        cout << "11. Total budget of organization:" << endl;
        cout << "12. Most experience employee/employee" << endl;
        cout << "13. EXIT"<<endl;
        cout << "==============================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            	cout<<"In Order traversal:"<<endl;
                inOrder(root);
                break;
            case 2:
            	cout<<"Pre Order traversal:"<<endl;
                preOrder(root);
                break;
            case 3:
            	cout<<"Post Order traversal:"<<endl;
               	postOrder(root);
                break;
            case 4:
                cout<<"Level Order traversal:"<<endl;
               	levelOrderTraversal(root);
                break;
            case 5:
                cout<<"Enter registration no. of Employee(like RGN000):";
                cin>>regNo;
                isDeleted = deleteNodeByRegNo(root, regNo);
			    if (isDeleted) {
			        cout << "Employee with registration number " << regNo << " was found and deleted." << endl;
			    } else {
			        cout << "Employee with registration number " << regNo << " was not found." << endl;
			    }
                break;
            case 6:
                height1 = height(root);
                cout<<"The height of tree is: "<<height1;
                break;
            case 7:
                if(isBalanced(root)){
                	cout<<"AVL TREE is balanced";
				} else{
					cout<<"AVL TREE is not balanced";
				}
                break;
            case 8:
                cout<<"Enter experience level which you find employee above that exp level: ";
                cin>>exp1;
                cout<<endl<<"Employee having exp level above "<< exp1 <<" are: "<<endl;
                printAllAboveExperience(root,exp1);
                break;
            case 9:
                cout<<"Enter age which you find employee above that age: ";
                cin>>age1;
                cout<<endl<<"Employee which age is above "<< age1 <<" are: "<<endl;
                printAllAboveSalary(root,age1);
                break;
            case 10:
                cout<<"Enter salary which you find employee above that salary: ";
                cin>>salary1;
                cout<<endl<<"Employee which salary is above "<< salary1 <<" are: "<<endl;
                printAllAboveSalary(root,salary1);
                break;
            case 11:
                cout<<"Total budget of organization: "<<totalBudget(root);
                break;
            case 12:
            	printMostExperienced(root);
                break;
            case 13:
            	break;
            default:
                cout << "INVALID OPTION, Please choose correct option." << endl;
                break;
        }

        cout << endl;

    } while (choice != 13);
	cout<<"You are exited from the organization";
	
}

