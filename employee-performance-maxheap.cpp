#include<iostream>
#include <vector>
//using 
using namespace std;
class Employee {
	public:
		int employeeID;
		string name;
		float sales;
		float customerSatisfaction;
		float projectCompletion;
		float performanceScore;
		Employee(int employeeID, string name,float sales, float customerSatisfaction, float projectCompletion) {
			this->employeeID=employeeID;
			this->name=name;
			this->customerSatisfaction=customerSatisfaction;
			this->projectCompletion=projectCompletion;
			this->sales=sales;
		}
		Employee()
		{
		}

		float calculatePerformanceScore() 
		{

performanceScore = sales+customerSatisfaction+projectCompletion;
return performanceScore;
		}
};

class MaxHeap {
	public:
		vector<Employee> employeeHeap;
Employee obj;
		int getParent(int child) 
	{
    	return (child-1)/2;
    }

    int getLeft(int parent) {
    	return 2*parent+1;    
    }

    int getRight(int parent) {
        return 2*parent+2;
    }

    void swap(Employee &a, Employee &b) {
        Employee temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int node) 
	{
//		float s=;
        while(node>0 && employeeHeap[node].calculatePerformanceScore()>employeeHeap[getParent(node)].calculatePerformanceScore())
		{
        	swap(employeeHeap[node], employeeHeap[getParent(node)]);
        	node=getParent(node);
		}
    }
    

	void heapifyDown(int node) {
	    
	    int left=getLeft(node);
	    int right=getRight(node);
	    int smallest=node;
	    
	    if(left< employeeHeap.size() && employeeHeap[left].calculatePerformanceScore()<employeeHeap[smallest].calculatePerformanceScore()){
	    	smallest=left;
		}
	    
	    if(right< employeeHeap.size() && employeeHeap[right].calculatePerformanceScore()<employeeHeap[smallest].calculatePerformanceScore()){
	    	smallest=right;
		}
	    
	    if(smallest!=node){
	    	swap(employeeHeap[node], employeeHeap[smallest]);
	    	heapifyDown(smallest);
		}
	
	}


    void insert(Employee employee) {
        employeeHeap.push_back(employee);
        int LastIndex=employeeHeap.size()-1;
        heapifyUp(LastIndex);
        
    }

    void del() {
        
        if(employeeHeap.empty()){
        	cout<<"Nothing to remove"<<endl;
		}
		
		swap(employeeHeap[0], employeeHeap[employeeHeap.size()-1]);
		
		employeeHeap.pop_back();
		
		heapifyDown(0);
        
    }
		void insertEmployee(Employee emp) {
employeeHeap.push_back(emp);
        int LastIndex=employeeHeap.size()-1;
        heapifyUp(LastIndex);
		}
		void getTopRankingEmployee() 
		{
float a=employeeHeap[0].calculatePerformanceScore();
//cout<<a;
cout<<"Top Ranking Employee \n";
for(int i=0;i<employeeHeap.size();i++)
{
	if(a == employeeHeap[i].calculatePerformanceScore())
	{
		cout<<"Employee ID : "<<employeeHeap[i].employeeID<<endl;
				cout<<"Employee Name : "<<employeeHeap[i].name<<endl;
				cout<<"Employee PerformanceScore : "<<employeeHeap[i].calculatePerformanceScore()<<endl;
	}
}
		}

		void updatePerformance(int employeID, float newSales, float newCS, float newPCE) 
		{
			for(int i=0;i<employeeHeap.size();i++)
			{
				if(employeeHeap[i].employeeID==employeID)
				{
					employeeHeap[i].employeeID=employeID;
					employeeHeap[i].sales = newSales;
					employeeHeap[i].customerSatisfaction=newCS;
					employeeHeap[i].projectCompletion=newPCE;
				}
		}
		}

		void displayEmployees() {
			if (employeeHeap.empty()) {
				cout << "No Employees." << endl;
				return;
			}
			cout << "Employee Rankings:" << endl;
			for(int i=0;i<employeeHeap.size();i++)
			{
				cout<<"Employee ID : "<<employeeHeap[i].employeeID<<endl;
				cout<<"Employee Name : "<<employeeHeap[i].name<<endl;
				cout<<"Employee PerformanceScore : "<<employeeHeap[i].calculatePerformanceScore()<<endl;
			}
			cout<<endl;
		}

};

int main() {
	MaxHeap employeeMaxHeap;

	while (true) {
		cout << "\nMenu:\n";
		cout << "1. Enter a new employee details\n";
		cout << "2. Get the top-ranking employee\n";
		cout << "3. Update an employee's scores\n";
		cout << "4. Display employee rankings\n";
		cout << "5. Exit\n";

		int choice;
		cin >> choice;

		switch (choice) {
			case 1: {
				int id;
				string name;
				float sales, cs, pce;
				cout << "Enter Employee ID: ";
				cin >> id;
				cin.ignore(); // Clear newline character from the buffer
				cout << "Enter Employee Name: ";
				getline(cin, name);
				cout << "Enter Sales (in percentage): ";
				cin >> sales;
				cout << "Enter Customer Satisfaction (in percentage): ";
				cin >> cs;
				cout << "Enter Project Completion Efficiency (in percentage): ";
				cin >> pce;

				Employee obj(id, name,cs, pce, sales);
//				newEmployee.calculatePerformanceScore();
				employeeMaxHeap.insertEmployee(obj);
				cout << "Employee added successfully!" << endl;
				break;
			}
			case 2: {
				employeeMaxHeap.getTopRankingEmployee();
				break;
			}
			case 3: {
				int empID;
				float newSales, newCS, newPCE;
				cout << "Enter Employee ID to update scores: ";
				cin >> empID;
				cout << "Enter new Sales (in percentage): ";
				cin >> newSales;
				cout << "Enter new Customer Satisfaction (in percentage): ";
				cin >> newCS;
				cout << "Enter new Project Completion Efficiency (in percentage): ";
				cin >> newPCE;
				employeeMaxHeap.updatePerformance(empID, newSales, newCS, newPCE);
				break;
			}
			case 4: {
				employeeMaxHeap.displayEmployees();
				break;
			}
			case 5:
				cout << "Exiting the program." << endl;
				return 0;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	}

	return 0;
}

