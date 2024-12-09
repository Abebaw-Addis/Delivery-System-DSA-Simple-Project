/*
  * The Delivery System in C++ is a consoled based application and created using C++ programming language. 
  * This system is a simple delivery system either food order,  beverage order or material order mini project
  *  and compiled in Falcons IDE and Dev C++ using GCC compiler.
  * 
  * This ordering items project is based on a concept of the fundamental idea of fast ordering items and 
  * creating complete items and generating cost. There is a login system framework in this system. 
  * At that point the client, which are customers can make a request by choosing from the menu or item lists and concept of ordering items and generating total.
  * 
  * About Project       Project Details 
  * Project Name :	   SINK Delivery System
  * Project Platform :      	C++
  * Programming Language Used: 	C++ Programming Language
  * Developer's Name->This project is completed /done by Software Engineering Students 	
  * 
  * Name                                 I'd Number 
  * 1. Abebaw Addis              1402806
  * 2. Abinet Ayelet                1402847
  * 3. Yohannes Eshetu.       1403167
  * 4. Eyerusalem Cherinet   1401229
  * 5. Etsub Zewudu              1401215
  * 6. Kaleb Netsanet.           1401473

  */



//Including usable libraries
#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
using namespace std;
// Define the struct for employee data
struct Employee{
    string name, address, profession ;
    double salary;
    int id, phone_no , age;
    char sex;
    Employee *next;   
};
Employee *start=NULL, *temp , *employee; 
// Define the struct for item data
struct Item {
    string name;
    double price;
    int id;
    Item *next;    
};   
   Item *item, *head =NULL, *temp2;
//Define the struct for customer data 
struct Customer {
    string name, address, choice; 
    char sex;
    int phone_no , age , amount;    
    double payment;  };
/**
  *Define the variables used for switching the system from one case to an other case, 
  *validate the owner until the system is terminated  * 
  */
string owner_password="Owner";  
int x, y, found=0;
bool is_owner=false;


// Function declarations
void login();
void owner();
void customers();
void payments();
void display_all_employee();
void display_sp_employee(int);
void add_employee();
void dismiss_employee(int);
void modify_employee(int);
void writeEmployee();
void read_employee_file();
void add_item();
void display_all_item();
void display_sp_item(int);
void delete_item(int);
void modify_item(int);
void writeItem();
void read_item_file();


// Main function
int main() {  
cout<<" 1. Login \t\t\t"<<" 2. Exit \n";
	  cin>>x;
	  switch (x){
	      case 1:
	      login();
	      break;
	      case 2:
        cout<<"EXISTING THANK YOU !!!! \n\n";  break;
	  }
    return 0;
}
/*  
  *Function to validate user input and log in as owner or customer. 
  *Default password of an owner to enter into the system and 
  *to operate operations like add , delete display, modify and the like is 'Owner' 
  */
void login() {
    string response;
    cout<<"Are you the owner? (yes or no) ";
    cin >> response;
    if(response == "yes") {
        cout << "Please enter the owner password: ";
        string password;
        cin >> password;
    if(password == owner_password){
        is_owner = true;
        owner();
    }else{
        cout<<"Incorrect password. Please try again." << endl;
        login();
    }}else if(response == "no") {
        customers();
    }else {
        cout << "Invalid input. Please try again." << endl;
        login();
    }
}
/* Function to display the owner menu and handle owner responsibilities. */
void owner() {
    cout << "Welcome, owner!" << endl;
    do{
      cout<<"=======================""=MAIN MENU====================="<<endl<<" = "<<endl;    
      cout<<" = 1. For Employees "<<endl;
      cout<<" = 2. For items"<<endl;
      cout<<" = 3. Return back  " <<endl;  
      cout<<" = 4. To quite "<<endl<<" =" <<endl;
      cout<<" = This is SINK Delivery System Enter Your Option (1- 4) !"<<endl<<" ="<<endl;  
      cout<<"======================================================"<<endl;
      cin>>x;
      system ("cls");
      switch (x){
      case 1:
        do{
          cout<<"======================== MAIN MENU ====================="<<endl<<" = "<<endl;    
          cout<<" = 1. To add new Employee in to the organization "<<endl;
          cout<<" = 2. To See detail info about all Employees "<<endl;
          cout<<" = 3. For dismissing an  employee "<<endl;
          cout<<" = 4. To see detail info about specific employee "<<endl;
          cout<<" = 5. To modify detail info of an  employee "<<endl;
          cout<<" = 6. Write in to the file  \n";
          cout<<" = 7. Read from the file  "<<endl;
          cout<<" = 8. Return to back "<<endl;
          cout<<" = 9. To quite "<<endl;
          cout<<" =" <<endl;
          cout<<" = This is SINK Delivery System Enter Your Option (1- 7) !"<<endl<<" ="<<endl;  
          cout<<"======================================================"<<endl;
          cin>>y;
          switch (y){
            case 1: 
              add_employee();
              break;
            case 2:
              display_all_employee(); 
              break;
            case 3:
              cout<<" Enter an ID that you want to dismiss from your organization. \n";
              cin>>x; 
              dismiss_employee(x);
              break;
            case 4:
              cout<<" Enter an ID that you want to  see detail info about a specific Employee ."<<endl;
              cin>>y;
              display_sp_employee(y);
              break;
            case 5:
              cout<<" Enter an employee ID that you want to modify its detail info.\n"; cin>>x;   
              modify_employee(x) ; 
              break;
            case 6:
              writeEmployee();  
              break;
            case 7:
              read_employee_file();
              break;
            case 8:
              owner();
              break; 
            case 9:
            	break;
            default:
              cout<<" Enter Correct Choice , Please "<<endl;
              break;
            }
        }while (y!= 9);
        break;
      case 2:
        do{
          cout<<"======================== MAIN MENU====================="<<endl<<" = "<<endl;    
          cout<<" = 1. To add a new item in to the organization  "<<endl;
          cout<<" = 2. To See detail info about all Items"<<endl;
          cout<<" = 3. For deleting an Item from linked list "<<endl;
          cout<<" = 4. To see detail info about a specific Item "<<endl;
          cout<<" = 5. To modify detail info of an item "<<endl;
          cout<<" = 6. Write item to file"<<endl;
          cout<<" = 7. Read item from file \n";
          cout<<" = 8. Return back "<<endl;
          cout<<" = 9. To quite "<<endl;
          cout<<" =" <<endl;
          cout<<" = This is SINK Delivery System Enter Your Option (1- 7)! \n";  
          cout<<"======================================================"<<endl;
          cin>>y;
        switch (y){
          case 1:
            add_item();
            break;
          case 2:
            display_all_item();
            break;
          case 3:  
            cout<<" Enter a product ID that you want to delete from your list of items."<<endl;
            cin>>x;       
            delete_item(x);
            break; 
          case 4:
            cout<<" Enter a product ID that you want to see detail info about it . \n";
            cin>>x; 
            display_sp_item(x);
            break; 
          case 5:
            cout<<" Enter a product ID that you want to modify its detail info.  \n";
            cin>>x;   
            modify_item(x); 
            break;
          case 6:
            writeItem();
            break;
          case 7:
            read_item_file();
            break;
          case 8:
            owner();
            break;  
          case 9:
        	  break;
          default:
            cout<<" Enter Correct Choice , Please "<<endl;
            break;
          }
        }while (y!= 9);
        break;
      case 3:
        login();
        break;
      case 4:
      	break;
      default:
        cout<<"Invalid input. Please try again. \n";
        break;
    }  
  }while(x != 4);
}



//Add employee in to the linked list  
void add_employee(){
  employee = new Employee;
  cout<<" Enter  Name : ";
  cin.ignore();
  getline(cin, employee->name); 
  cout<<" Enter  Profession : ";    
  getline(cin,employee->profession);
  cout<<" Enter  Age : ";
  cin>>employee ->age;
  cout<<" Enter  Address : ";
  cin.ignore(); 
  getline(cin, employee -> address);
  cout<<" Enter  Salary : ";
  cin>>employee ->salary;
  cout<<" Enter  Sex (M/F) : ";
  cin>>employee ->sex;
  cout<<" Enter  Phone number : ";
  cin>>employee ->phone_no;
  cout<<" Enter ID number : ";
  cin>>employee ->id;
  if(start==NULL){
   start=employee;
  }else{
    temp=start;
    while (temp->next != NULL){
      temp= temp->next ;
    }temp->next =employee;
   employee->next = NULL;   
  }
  cin.ignore();
  cin.get();
}   


//Display all employees from linked list  
void display_all_employee() {    
  if (start == NULL) {
    cout<<" You Have No Employees.\n";
  } else{
      employee=start; 
      while (employee != NULL){
        cout << " Name : " <<employee-> name << endl;
        cout << " Profession : " <<employee-> profession << endl;
        cout<<"Age :"<<employee->age<< '\n';cout<<" Sex :"<<employee->sex<< '\n';
        cout<< " Address : "<<employee->address << endl;
        cout<<" Phone No. : "<<employee->phone_no<< endl;
        cout << " Salary : " <<employee-> salary << endl;
        cout<< " I'D : "<<employee->id << '\n';
        cout<<"\n====================================\n";
        employee =employee ->next;
      }     
    }
    cin.ignore();
    cin.get();
}


//Delete employee from linked list
void dismiss_employee(int n){   
  if(start==NULL){
    cout<<" You Have No Employees.\n";        
  }  
  if(start->id==n){
    employee =start;
    start=start->next;
    cout<<"Employee with I'D number "<<n<<" has been dismissed from the organization"<<endl;
    delete employee ;
  } else{
      employee=start;   
      while(employee->id != n){  
        temp=employee; 
        employee=employee->next;  
      }   
      temp->next=employee->next; 
      cout<<"Employee with I'D number "<<n<<" has been dismissed from the organization"<<endl; 
      found=1;  
      delete employee;  
   }
  if(found ==0){
    cout<<" There is no Employee registered in this "<<n<<" I'D number "<<endl;
  }      
  cin.ignore();
  cin.get();
}


// Display an employee from linked list  
void display_sp_employee(int n) {  
    if (start == NULL) { 
      cout<<" You Have No Employees.\n";
    } else {
        employee = start;
        while (employee != NULL) {
          if (employee->id == n) {
              cout << " Name : " <<employee-> name << endl;
              cout << " Profession : " <<employee-> profession << endl;
              cout<<"Age :"<<employee->age<< '\n';cout<<" Sex :" <<employee->sex<<'\n';
              cout<< " Address : "<<employee->address << endl;
              cout<<" Phone No. : "<<employee->phone_no<< endl;
              cout << " Salary : " <<employee-> salary << endl;
              cout<< " I'D : "<<employee->id << '\n';
              cout<<"\n====================================\n";
          }
        found = 1;
        break;
        }
        employee = employee->next;
      }
    if(found ==0){
        cout<<" There is no Employee Registered in this "<<n<<" I'D number "<<endl;
    }  
    cin.ignore();
    cin.get();
}


//Modify an employee in thr linked list 
void modify_employee(int n){ 
    ofstream outfile;
    outfile.open("employees.dat", ios::binary | ios::app );
    add_employee();
    if(start==NULL){
        cout<<" You Have No Employees.\n";
    } else {    
        employee=start;    
        while(employee != NULL){
          if(n == employee->id){
              cout << " Enter Name : " <<employee-> name << endl;
              cout << " Enter Profession : " <<employee-> profession << endl;
              cout<<"Enter  Age :"<<employee->age<< '\n';
              cout<<" Enter Sex :"<<employee->sex<<'\n';
              cout<< " Enter Address : "<<employee->address << endl;
              cout<<" Enter Phone No. : "<<employee->phone_no<< endl;
              cout << " Enter Salary : " <<employee-> salary << endl;
              cout<< " Enter I'D Number : " <<employee->id << '\n';
              cout<<"\n====================================\n";  
          }
          cin.ignore();
          cin.get();
          cout<<"Enter New  Name : ";
          cin.ignore();
          getline(cin, employee->name); 
          cout<<" Enter New Profession : ";    
          getline(cin,employee->profession);
          cout<<" Enter New Age : ";
          cin>>employee ->age;
          cout<<" Enter New Address : ";
          cin.ignore(); 
          getline(cin, employee -> address);
          cout<<" Enter New Salary : ";
          cin>>employee ->salary;
          cout<<" Enter New Sex (M/F) : ";
          cin>>employee ->sex;
          cout<<" Enter New Phone number : ";   cin>>employee ->phone_no;
          cout<<" Enter New ID for your employee : ";
          cin>>employee ->id;
          outfile<<employee->name<< endl <<employee->profession<<endl <<employee->age
                  <<endl<<employee->sex<<endl<<employee->address<< endl<<employee->phone_no
                  << endl <<employee->salary<< endl <<employee->id<<endl;
          outfile.close(); 
          cout<<" \n Record Updated Successfully !!"<<endl;
          found =1;
          break;
        }   
        employee=employee->next;
      }
      if(found == 0){
          cout<<" There is no Item registered in this "<<n<<" I'D number to get updating "<<endl;
      }   
    cin.ignore();
    cin.get();
}


// Customer function 
void customers() {
    Customer customer;
    double price;//price of the chosen item
    cout << "------- This is SINK Online Delivery System Welcome -----------\n";
    cout << "--------------------------------------------------------------" << endl;
    cout << " Enter Name: ";
    cin.ignore();
    getline(cin, customer.name);
    cout << " Enter Age: ";
    cin >> customer.age;
    cout << " Enter Sex (M/F): ";
    cin >> customer.sex;
    cout << " Enter Address: ";
    cin.ignore();
    getline(cin, customer.address);
    cout << " Enter Phone number: ";
    cin >> customer.phone_no;
    do{
        read_item_file();//is a display function which is used to display available items for customer
        cin.ignore();
        cout << " Enter the name of an item you want to purchase: ";
        getline(cin, customer.choice);
        cout << "How many do you want to purchase? ";
        cin >> customer.amount;
        cout << "Enter the price of the item for better calculation: ";
        cin >>price;
        cout << " Enter Your Payment method:" << endl;
        payments();
        cin >> x;
        customer.payment =price * customer.amount;
        cout<<" You are charged "<< customer.payment<<" birr to purchase "<< 
        customer.choice<< " Please enter your payment amount:"<<endl;
        cin >> x;
        if (x == customer.payment) {
          cout<< "You have subscribed to purchase " << customer.choice << " for " 
              <<customer.amount<< " pieces with a total cost of " << customer.payment 
              << " birr. Please wait a few moments for delivery."<< endl;
        } else if(x<customer.payment){
            cout<<" You Entered a Payment less than that of an Item Price \n Please try Latter "<<endl;
        } else{
            cout<<" You Entered a Payment greater than that of an Item Price \n Please try Latter "<<endl;
        }  
        cin.ignore();
        cin.get();
        cout<<"1. Logout : ";
        cin>>x;
        switch(x){
          case 1:
            cout<<" Thank You for Purchasing an Item and for Using This System \n\n\n\n";    break;
          default :
            cout<<" Press any key to get Started "; break;
        }
        cin.ignore();
        cin.get(); 
    }while(x != 1);
}


//Add item in to the linked list 
void add_item(){
  item = new Item;
  cout<<" Enter Product Name  : ";
  cin.ignore();
  getline(cin,item->name);
  cout<<" Enter Product Price : ";
  cin>>item->price;
  cout<<" Enter Product I'D : ";
  cin>>item ->id;
  if(head==NULL){
    head=item;
  } else{
      temp2=head;
      while (temp2->next != NULL){
        temp2= temp2->next ;
       }
      temp2->next = item;
      item->next = NULL; 
    }    
  cin.ignore();
  cin.get();
}


//Display all items from linked list
void display_all_item(){
  if(head==NULL){
    cout<<" You Have no Items "<<endl;
  } else{
        item=head;
        cout<<" Product \t  name Product price \t Product I'D " <<endl;
        while (item != NULL){
            cout<<item->name<<"\t\t"<<item ->price<<"\t\t "<<item ->id <<endl;
            item=item->next;
        }
      cout<<"\n====================================\n";
    }  
  cin.ignore();
  cin.get();
}


//Delete an item from linked list
void delete_item(int n){
  if(head==NULL){
    cout<<" You Have no Items "<<endl;
  } 
  if(head->id==n){
      item =head;
      head=head->next;
      cout<<" Item with I'D number "<<n<<" has been deleted from the list."; 
      delete item ;
  } else{
      item=head;   
      while(item->id != n){  
          temp2=item; 
          item=item->next;  
      }       
      temp2->next=item->next; 
      cout<<" Item with I'D number "<<n<<" has been deleted from the list."; 
      found=1;  
      delete item;  
   }     
   if(found ==0){
        cout<<" There is no Item Registered in this "<<n<<" I'D number. "<<endl;
    } 
    cin.ignore();
    cin.get();
}



//Display an item from linked list 
void display_sp_item(int n){
    if(head==NULL){
        cout<<" You Have no Items "<<endl;
    } else {   
        item=head;    
        while(item != NULL){
          if(item->id == n){
              cout<<" Product name : "<<item->name<<endl;
              cout<<" Product price : "<<item ->price <<endl;
              cout<<" Product I'D : "<<item ->id <<endl;
              cout<<"\n====================================\n";
              found=1;
              break;
          }   
          item=item->next;
        }    
    if(found == 0){
        cout<<" There is no Item Registered in this "<<n<<" I'D number. "<<endl;
    }
    }  
    cin.ignore();
    cin.get();          
}


//Modify an item from linked list 
void modify_item(int n){
    if(head==NULL){
        cout<<" You Have No Items "<<endl;
    } else {    
    item=head;    
    while(item != NULL){
      if(n == item->id){
          cout<<" Product name "<<item->name<<endl;
          cout<<"Product price "<<item ->price <<endl;
          cout<<"Product ID "<<item ->id <<endl;
          cout<<"\n====================================\n";
          cin.ignore();
          cin.get();
          cout<<" Enter New Product Name  :";
          cin.ignore();
          getline(cin, item->name);  
          cout<<" Enter New Product Price : ";
          cin>>item->price;
          cout<<" Enter New Product ID  : ";
          cin>>item ->id;
          cout<<" \n Record Updated Successfully !!"<<endl;
          found =1;
          break;
      }   item=item->next;
    }     
    if(found == 0){
        cout<<" There is no Item Registered in this "<<n<<" I'D number to get updating "<<endl;
    }
  }  
  cin.ignore();
  cin.get();          
}



//Read employees from the file  
void read_employee_file(){
    ifstream inFile;
    inFile.open("employees.dat",
    ios::binary);    
    if(!inFile){
      cout<<"File could not be opened !! Press any Key to exit";
      cin.ignore();
      cin.get();
      return;
    } else{
          string name, pro, age, sex, add, p_no, salary, id;
          cout<<"\n\n\t\tDISPLAYING ALL RECORDS\n\n";
          while(getline(inFile, name),getline (inFile, pro), getline(inFile, age),
              getline(inFile, sex), getline(inFile, add), getline(inFile, p_no),
              getline (inFile, salary), getline(inFile, id)){
                cout << " Name : " << name << endl;
                cout << " Profession : " <<pro << endl;
                cout << " Age : " <<age << endl;
                cout << " Sex : " <<sex<< endl;
                cout<< " Address : "<<add << endl;
                cout<<" Phone No. : "<<p_no<< endl;
                cout << " Salary : " <<salary << endl;
                cout<< " I'D : "<<id << endl; cout<<"\n====================================\n";
          }
      }
    inFile.close();
    cin.ignore();
    cin.get();	
}



//Write employees in to the file
void writeEmployee(){
	  ofstream outfile;
    outfile.open("employees.dat", ios::binary | ios::app );
    add_employee();
    outfile<<employee->name<< endl <<employee->profession<<endl <<employee->age<< 
        endl<<employee->sex<<endl<<employee->address<< endl<<employee->phone_no<< 
        endl <<employee->salary<< endl <<employee->id<<endl;
    outfile.close(); 
	  cout<<"\nEmployee Record Has Been Created .";
    cin.ignore();
    cin.get();
}


// Read items from the file      
void read_item_file(){
    ifstream inFile;
    inFile.open("items.dat",
    ios::binary);    
    if(!inFile){
      cout<<"File could not be opened !! Press any Key to exit";
      cin.ignore();
      cin.get();
      return;
    } else{
          string name, price, id;
          cout<<"\n\t\tDISPLAYING ALL RECORDS\n";
          cout<<" Product name \t Product price \t Product I'D " <<endl; 
          while(getline(inFile, name),getline (inFile, price), getline(inFile, id)){
              cout<<name<<"\t\t"<<price<<"\t\t "<<id <<endl;
          }cout<<"\n====================================\n";
      }
    inFile.close();
    cin.ignore();
    cin.get();	
}


// Write items in to the file
void writeItem(){
	  ofstream outfile;
    outfile.open("items.dat", ios::binary | ios::app );
    add_item();
    outfile<<item->name<< endl <<item->price<< endl <<item->id<<endl;
    outfile.close(); 
	  cout<<"\nItem Record Has Been Created ";
    cin.ignore();
    cin.get();
}


//Function of payment methods   
void payments(){
    cout<<"======================== MAIN MENU ====================="<<endl<<" = "<<endl;    
    cout<<" = 1. By cash  "<<endl;
    cout<<" = 2. By mobile banking"<<endl;
    cout<<" = 3. By credit card "<<endl;  
    cout<<" = This is Delivery System Enter Your Option (1- 3) !"<<endl;
    cout<<"======================================================"<<endl;
}