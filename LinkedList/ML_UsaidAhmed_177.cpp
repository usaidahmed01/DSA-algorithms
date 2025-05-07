#include <bits/stdc++.h>
using namespace std;

struct student {
	string data;
	student* next;
};

struct course {
	int data;
	course* next;
	student* stud = NULL;
};

student* startS = NULL;
course* startC = NULL;

// student* startCS = NULL;

void addStudInCrs(int courseTitle, student* ptr) {

	course *crnt = startC;
	course* selectedCrs = new course();

	while (crnt != NULL) {
		if(crnt->data = courseTitle) {
			selectedCrs = crnt;
			selectedCrs->next = NULL;
			break;
		}
		crnt = crnt->next;
	}

	if ( selectedCrs->stud == NULL) {
		selectedCrs->stud = ptr;
	} else {
		student* crntStud = selectedCrs->stud;
		// selectedCrs->stud* crnt = starts;
		while(crntStud->next != NULL) {
			crntStud = crntStud->next;
		}
		crntStud->next = ptr;
	}

}

void insertForAdmin() {
	cout<< "Add Course Codes Accurately: "<<endl;
	int courseCode;
	cin>>courseCode;
	course* ptr = new course();
	ptr->data = courseCode;

	if(startC == NULL) {
		startC = ptr;
		ptr->next = NULL;
	} else {
		course* crnt = startC;
		while(crnt->next != NULL) {
			crnt = crnt->next;
		}
		crnt->next = ptr;
	}

}

void deleteCourse() {
	cout << "Enter Course code You want to Delete : \n";
    int toDel;
    cin >> toDel;

    if (startC->data == toDel)
    {
        course *temp = startC;
        startC = startC->next;

        cout << toDel <<"Course has been deleted along with enrolled Students."<<endl;

		while(temp->stud != NULL){
			student* crntStud = temp->stud;
			temp->stud = crntStud->next;
			free(crntStud);
		}

        free(temp); // deallocate the memory
    }
    else
    {
        course *prev = startC;
        course *current = startC->next;

        while (current != NULL)
        {
            if (current->data == toDel)
            {
                prev->next = current->next; // Link previous next with current next because current is to be deleted

				while(current->stud != NULL){
					student* crntStud = current->stud;
					current->stud = crntStud->next;
					free(crntStud);
				}

                free(current);
				cout << toDel <<"Course has been deleted along with enrolled Students."<<endl;
                return;
            }
            prev = prev->next;
            current = current->next;
        }
        cout << "Your Deleted Course is not present in the list. ";
    }

}

void searchCourse() {
	cout<<"Enter Course Code You are searching for: "<<endl;
	int toSearch;
	cin>>toSearch;

	course* crntCrs = startC;

	if(startC == NULL){
		cout<<"Add Courses in the List First."<<endl;
		return;
	}

	while(crntCrs != NULL){
		if(crntCrs->data == toSearch){
			cout<<crntCrs->data<<" Course is Present in the list."<<endl;
			return;
		}
		crntCrs = crntCrs->next;
	}
	cout<<toSearch<<" Course does not exist in the list.";

}

void printCoursesWStud() {
	course* crnt = startC;
	
	if(startC == NULL ){
		cout<<"Add Courses to see the list.";
		return;
	}else{
		cout<<"Courses List:"<<endl;
		while(crnt != NULL){
			cout<<crnt->data<<endl<<endl;
			
			student* crntCrsStud = crnt->stud;
			cout<<"Students List"<<endl;
			while(crntCrsStud != NULL){
				cout<<crntCrsStud->data<<endl;
				
				crntCrsStud = crntCrsStud->next;
			}
			crnt = crnt->next;
		}
	}

}

void searchStudInCourse() {
	cout<<"Enter Student Name accurately that You are searching for: "<<endl;
	string toSearch;
	cin>>toSearch;

	course* crntCrs = startC;
	int counter = 0;
	string courseNames;

	if(startC == NULL){
		cout<<"ADD Course First."<<endl;
		return;
	}

	while(crntCrs != NULL){
		if(crntCrs->stud->data == toSearch){
			counter++;
			courseNames = courseNames + " " +  to_string(crntCrs->data);
		}
		crntCrs = crntCrs->next;
	}
	if(counter == 0){
		cout<<toSearch<<" Student does not enroll in any of the Course";
		return;

	}else{
		cout<<toSearch<<" Student is enrolled in "<<counter<<" Courses."<<endl;
		cout<<courseNames<<endl;
	}

}

void insertForStud() {
	cout<<"Enter Your Name: "<<endl;
	string name;
	cin>>name;

	cout<<"Input Course Code Accurately: "<<endl;
	int courseCode;
	cin >>courseCode;

	student* ptr = new student();
	ptr->data = name;

	if(startS == NULL) {
		startS = ptr;
		ptr->next = NULL;
	} else {
		student* crnt = startS;

		while(crnt->next != NULL) {
			crnt = crnt->next;
		}
		crnt->next = ptr;
	}
	addStudInCrs(courseCode, ptr);
}

void removeCourse() {
	cout<<"Enter Your Name: "<<endl;
	string name;
	cin>>name;

	cout << "Enter Course code You want to withdraw : \n";
    int toSearch;
    cin >> toSearch;

    course* crntCrs = startC;
	course* courseToWD;


	while(crntCrs != NULL){
		if(crntCrs->data == toSearch){
			courseToWD = crntCrs;
			break;
		}
		crntCrs = crntCrs->next;
	}
	if(crntCrs == NULL){
		cout<<"You have selected course that does not exist."<<endl;
		return;
	}

	while(courseToWD->stud != NULL){
		if(courseToWD->stud->data == name){
			student* delStud = courseToWD->stud;
			courseToWD->stud = delStud->next;
			free(delStud);
			return;
		}
		courseToWD->stud = courseToWD->stud->next;
	}
	cout<<"You are not enrolled in the Given Course."<<endl;


}

void printCourses(){
	cout<<"Enter Your Name :";
	string stdName;
	cin>>stdName;

	course* crntCrs = startC;

	if(crntCrs->stud == NULL){
		cout<<"Select Courses First."<<endl;
		return;
	}

	while(crntCrs != NULL){
		if(crntCrs->stud->data == stdName){
			cout<<crntCrs->data<<endl;
		}
		crntCrs = crntCrs->next;
	}
	
}

main() {
	
	while(true){
	
	int cat;
	cout<<"Welcome to MultiList"<<endl;
	cout<<"Press 1 for Admin Panel "<<endl<<"Press 2 for Student. "<<endl ;
	cin>> cat;
	if(cat == 1) {
		cout<<"Press 1 to Add Course \n Press 2 to See the list of Courses with Enrolled Students \n Press 3 to Search a Course \n Press 4 to Search Student in Courses \n Press 5 to Remove the Course \n Press 6 To Exit The Program"<<endl;
		int choice;
		cin>>choice;

		while(choice < 6) {
			if (choice == 1) {

				choice = 6;
				insertForAdmin();

				cout<<endl<<endl<<"Press 1 to Add Course \n Press 2 to See the list of Courses with Enrolled Students \n Press 3 to Search a Course \n Press 4 to Search Student in Courses \n Press 5 to Remove the Course \n Press 6 to Exit the Program ";
				cin>>choice;
			}
			if(choice == 2) {
				choice = 6;
				cout<<"Courses List"<<endl;
				printCoursesWStud();

				cout<<endl<<endl<<"Press 1 to Add Course \n Press 2 to See the list of Courses with Enrolled Students \n Press 3 to Search a Course \n Press 4 to Search Student in Courses \n Press 5 to Remove the Course \n Press 6 to Exit the Program ";
				cin>>choice;
			}
			if (choice == 3) {

				choice = 6;
				searchCourse();

				cout<<endl<<endl<<"Press 1 to Add Course \n Press 2 to See the list of Courses with Enrolled Students \n Press 3 to Search a Course \n Press 4 to Search Student in Courses \n Press 5 to Remove the Course \n Press 6 to Exit the Program ";
				cin>>choice;
			}
			if (choice == 4) {

				choice = 6;
				searchStudInCourse();

				cout<<endl<<endl<<"Press 1 to Add Course \n Press 2 to See the list of Courses with Enrolled Students \n Press 3 to Search a Course \n Press 4 to Search Student in Courses \n Press 5 to Remove the Course \n Press 6 to Exit the Program ";
				cin>>choice;
			}
			if (choice == 5) {

				choice = 6;
				deleteCourse();

				cout<<endl<<endl<<"Press 1 to Add Course \n Press 2 to See the list of Courses with Enrolled Students \n Press 3 to Search a Course \n Press 4 to Search Student in Courses \n Press 5 to Remove the Course \n Press 6 to Exit the Program ";
				cin>>choice;
			}			
		}
	}
	if (cat == 2) {
		cout<<"Press 1 to Select Courses \n Press 2 to withdraw the Course \n Press 3 to Print Courses "<<endl;
		int choice;
		cin>>choice;

		while (choice < 4) {
			if (choice == 1) {
			choice = 4;
			insertForStud();

			cout<< " Press 1 to Select Course \n Press 2 to withdraw Course \n Press 3 to Print Courses ";
			cin>>choice;
			}
			if (choice == 2) {
			choice = 4;
			removeCourse();

			cout<< " Press 1 to Select Course \n Press 2 to withdraw  Course \n Press 3 to Print Courses ";
			cin>>choice;
			}
			if (choice == 3) {
			choice = 4;
			printCourses();

			cout<< " Press 1 to Select Course \n Press 2 to withdraw Course \n Press 3 to Print Courses ";
			cin>>choice;
			}			
		}
	}
	}
}

