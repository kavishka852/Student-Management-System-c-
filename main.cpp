#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int marks;
    int fronts;
    int rear;
    int maxsize;
public:
    int highestScience;
    int highestMath;
    string name;
    string namee;
    int index;
    string *n; //student
    string *s; //subject
    int *m; //marks
    int *e; //atend exam or not
    Student(int j);
    bool isFull();
    bool isEmpty();
    void dequeue();
    void enqueue(int a1);
    void Display_menu();
    void Insertstudent();
    void DeleteStudent();
    int searchStudent(string name);
    void DisplayRelevantStudent();
    void NotAttendStudent();
    void DisplayHighestMarks();
    void DisplayLowestMarks();
    int getTotalStudents();
    void DisplayHighestMarksStudent();
    void DisplayLowestMarksStudent();
    void DisplaynextStudent();
};

Student::Student(int j)
{
    maxsize = j;
    n = new string[maxsize];
    fronts = 0;
    rear = -1;
    s = new string[maxsize];
    fronts = 0;
    rear = -1;
    m = new int[maxsize];
    fronts = 0;
    rear = -1;
    e = new int[maxsize];
    fronts = 0;
    rear = -1;
    highestScience = -1;
    highestMath = -1;

}

void Student::enqueue(int a1){
    if(isFull()){
      cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Que is Full!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}
}

void Student::dequeue(){
  if(isEmpty()){
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Que is Empty!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  }
  else{
    cout << "Removed student " << n[fronts] << " from the queue" << endl;
    fronts++;
    if(fronts > rear){
      fronts=0;
      rear=-1;
    }
  }
}


bool Student::isEmpty(){
  if(rear == -1){
    return true;
  }
  else{
    return false;
  }
}

bool Student::isFull(){
 if(rear == maxsize-1){
    return true;
 }
 else{
   return false;
 }
}

void Student::Insertstudent()
{
    if(isFull()){
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Que is Full!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    }
    else{
        rear=0;
        while(rear <= maxsize-1){
            cout << "Enter name of student: ";
            cin >> n[rear];
            cout << "Enter subject of student (type ""s"" for science & ""m"" for maths): ";
            cin >> s[rear];
            cout << "student attend exam or not(type if attend = 1 or not = 0): ";
            cin >> e[rear];
            if(e[rear] == 1){
            if(s[rear] == "m"){
                cout << "Enter marks of maths student: ";
                cin >> m[rear];
            }
            else if(s[rear] == "s"){
                cout << "Enter marks of science student: ";
                cin >> m[rear];
            }}
            else{
                m[rear]= 0;
            }
            rear++;
        }
    }
}

void Student::DeleteStudent(){
  if(isEmpty()){
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Que is Empty!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  }
  else{
    cout << "Removed student " << n[fronts] << " from the queue" << endl;
    cout << "Removed mark " << m[fronts] << " from the queue" << endl;
    cout << "Removed subject " << s[fronts] << " from the queue" << endl;
    cout << "Removed attend exam " << e[fronts] << " from the queue" << endl;
    fronts++;
    if(fronts > rear){
      fronts=0;
      rear=-1;
    }
  }
}

void Student::DisplaynextStudent() {
    if (isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    else{
       if (n[fronts] == ""){
        cout << "ERROR 404 Not FOUND" << endl;
       }
       else{
       cout << n[fronts] <<endl;
       }
    }
}

int Student::searchStudent(string name) {
    for (int i = 0; i <= rear; i++) {
        if (n[i] == name) {
            return i;
        }
    }
    return -1; // student not found
}


void Student::DisplayRelevantStudent() {
    char subject;
    cout << "Enter subject to display relevant students (type ""s"" for science & ""m"" for maths): ";
    cin >> subject;

    string subject_str(1, subject); // Convert char to string

    bool found = false;
    for (int i = fronts; i <= rear; i++) {
        if (s[i] == subject_str) {
            found = true;
            cout << "Name: " << n[i] << endl;
        }
    }

    if (!found) {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!No students found for the selected subject!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }
}

void Student::NotAttendStudent(){
    for (int i = fronts; i <= rear; i++) {
        if (e[i] == 0) {
            cout << "Name: " << n[i] << ", Subject: " << s[i] << "not attend "<< endl;
        }
    }
}


void Student::DisplayHighestMarks() {
  int highestScience = -1;
  int highestMath = -1;

for (int i = 0; i < maxsize; i++){
    if (s[i] == "m" && e[i] == 1 && m[i] > highestMath){
        highestMath = m[i];
    }
    else if (s[i] == "s" && e[i] == 1 && m[i] > highestScience){
        highestScience = m[i];
    }
}
cout << "Highest Maths marks: " << highestMath <<  endl;
cout << "Highest Science marks: " << highestScience <<  endl;
}


void Student::DisplayLowestMarks() {
int lowestMath = m[0];
int lowestScience = m[0];
for(int i = 0; i < maxsize; i++){
  if(s[i] == "m"){
    if(m[i] < lowestMath){
      lowestMath = m[i];
    }
  }
  else if(s[i] == "s"){
    if(m[i] < lowestScience){
      lowestScience = m[i];
    }
  }

}
cout << "The lowest marks for Maths is: " << lowestMath <<  endl;
cout << "The lowest marks for Science is: " << lowestScience <<  endl;
}



int Student::getTotalStudents() {
    if (isEmpty()) {
        return 0;
    } else {
        return rear ;   //////////////////////////////////////
    }
}

void Student::DisplayLowestMarksStudent() {

   int lowestMarksForMath = 100;
   int lowestMarksForScience = 100;
   string lowestMarksStudentForMath;
   string lowestMarksStudentForScience;

for(int i=0; i<maxsize; i++){
    if(s[i] == "m" && m[i] < lowestMarksForMath){
        lowestMarksForMath = m[i];
        lowestMarksStudentForMath = n[i];
    }
    else if(s[i] == "s" && m[i] < lowestMarksForScience){
        lowestMarksForScience = m[i];
        lowestMarksStudentForScience = n[i];
    }
}
if (lowestMarksForMath == 100){
    cout << "Not Any student chose Maths" << endl;
    cout << "Lowest Marks Student for Science: " << lowestMarksStudentForScience << " with marks: " << lowestMarksForScience << endl;
}
else if (lowestMarksForScience == 100)
{
    cout << "Not Any student chose Science" << endl;
    cout << "Lowest Marks Student for Math: " << lowestMarksStudentForMath << " with marks: " << lowestMarksForMath << endl;
}
else if (lowestMarksForMath == 100 && lowestMarksForScience == 100)
{
    cout << "Queue is Empty" <<endl;
}
else{
cout << "Lowest Marks Student for Math: " << lowestMarksStudentForMath << " with marks: " << lowestMarksForMath << endl;
cout << "Lowest Marks Student for Science: " << lowestMarksStudentForScience << " with marks: " << lowestMarksForScience << endl;
}
}


void Student::DisplayHighestMarksStudent() {
    int highestMarksForMath = 0;
    int highestMarksForScience = 0;
    string highestMarksStudentForMath;
    string highestMarksStudentForScience;
for(int i=0; i<maxsize; i++){
    if(s[i]=="m" && m[i]>highestMarksForMath){
        highestMarksForMath=m[i];
        highestMarksStudentForMath=n[i];
    }
    else if(s[i]=="s" && m[i]>highestMarksForScience){
        highestMarksForScience=m[i];
        highestMarksStudentForScience=n[i];
    }
}
if (highestMarksForMath == 100){
    cout << "Not Any student chose Maths" << endl;
    cout<<"Highest marks student for Science is: "<<highestMarksStudentForScience<<" with marks: "<<highestMarksForScience<<endl;
}
else if (highestMarksForScience == 100)
{
    cout << "Not Any student chose Science" << endl;
    cout<<"Highest marks student for Math is: "<<highestMarksStudentForMath<<" with marks: "<<highestMarksForMath<<endl;
}
else if (highestMarksForMath == 100 && highestMarksForScience == 100)
{
    cout << "Queue is Empty" <<endl;
}
else{
cout<<"Highest marks student for Math is: "<<highestMarksStudentForMath<<" with marks: "<<highestMarksForMath<<endl;
cout<<"Highest marks student for Science is: "<<highestMarksStudentForScience<<" with marks: "<<highestMarksForScience<<endl;
}
}

void Student::Display_menu() {
    cout << "1. Add New Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3. Display Next Student" << endl;
    cout << "4. Search Student" << endl;
    cout << "5. Display Relevant Student is for which Subject" << endl;
    cout << "6. Display Highest Marks for Science and Math" << endl;
    cout << "7. Display Lowest Marks for Science and Math" << endl;
    cout << "8. Display Total Number of Students" << endl;
    cout << "9. Display whose not attend to exam" << endl;
    cout << "10. Display Highest Marks Student for Math and Science" << endl;
    cout << "11. Display Lowest Marks of Student for Math and Science" << endl;
    cout << "12. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    cout<<"=======================================================================================================================" << endl;
    cout<<"---------------------------------------------------------------AYUBOWAN!-----------------------------------------------" << endl;
    cout<<"=======================================================================================================================" << endl;
    cout<<"-------------------------------------------------------------Admin Login------------------------------------------------" << endl;
    string username = "admin";
    string password = "admin";
    string input_username, input_password;

    cout << "=================Username: ";
    cin >> input_username;

    cout << "=================Password: ";
    cin >> input_password;

    if (input_username == username && input_password == password) {
        cout << "==================================================Login successful!====================================================" << endl;
        int quesize;
        int choice;
        cout << "How many student you think to insert for queue:" << endl;
        cin >> quesize;
        Student s(quesize);
        while (true) {
        s.Display_menu();
        cin >> choice;

        switch (choice) {
            case 1:
                s.Insertstudent();
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Student added to the queue!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                break;
            case 2:
                s.DeleteStudent();
                break;
            case 3:
                s.DisplaynextStudent();
                break;
            case 4:

                cout << "Enter name of student to search for: ";
                cin >> s.name;
                s.index = s.searchStudent(s.name);
                if (s.index == -1) {
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Student not found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                } else {
                    cout << "Name: " << s.n[s.index] << endl;
                    cout << "Subject: " << s.s[s.index] << endl;
                    if (s.e[s.index] == 1){
                       cout << "Marks: " << s.m[s.index] << endl;
                    }
               }
                break;
            case 5:
                s.DisplayRelevantStudent();
                break;
            case 6:
                 s.DisplayHighestMarks();
                break;
            case 7:
                s.DisplayLowestMarks();
                break;
            case 8:
                cout << "Total number of students: " << s.getTotalStudents() << endl;
                break;
            case 9:
                s.NotAttendStudent();
                break;
            case 10:
                s.DisplayHighestMarksStudent();
                break;
            case 11:
                s.DisplayLowestMarksStudent();
                break;
            case 12:
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Thanks for using us!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                exit(0);
                break;
        }
        }

    } else {
        cout << "Invalid username or password. Please try again." << endl;
}

return 0;
}
