#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student
{
	typedef struct stud
	{
		int roll;
		char name[10];
		char div;
		char add[10];
	}stud;
	stud rec;
	public:
		void create();
		void display();
		int search();
		void Delete();
};

void student::create()
{
	char ans;
	ofstream fout;
	fout.open("stud.dat",ios::out | ios::binary);
	do
	{
		cout<<"\nRoll No. : ";
		cin>>rec.roll;
		cout<<"Name     : ";
		cin>>rec.name;
		cout<<"Division : ";
		cin>>rec.div;
		cout<<"Address  : ";
		cin>>rec.add;
		fout.write((char*)&rec, sizeof(stud))<<flush;
		cout<<"Do you want to add any more records (y/n) :: ";
		cin>>ans;
	}while(ans=='y' || ans=='Y');
	fout.close();
}

void student::display() {
    ifstream file;
    student s;
    int count = 0;
    file.open("stud.dat", ios::in | ios::binary);
    cout<<"\n";
    while (file.read((char*)&rec, sizeof(stud))) {
        count++;
        cout << count << ") ";
        cout << rec.roll << " | ";
        cout << rec.name << " | ";
        cout << rec.div << " | ";
        cout << rec.add << endl;
    }
    if (count == 0) {
        cout << "No records found." << endl;
    }
    file.close();
}

int student::search() {
    int roll,i=0;
    
    cout << "Roll number to search:\t";
    cin >> roll;

    ifstream readFile;
    readFile.open("stud.dat", ios::in | ios::binary);
    readFile.seekg(0,ios::beg);

    while (readFile.read((char*)&rec, sizeof(stud))) {
        if (rec.roll == roll) {
        	cout << rec.roll << " | ";
       		cout << rec.name << " | ";
        	cout << rec.div << " | ";
        	cout << rec.add << endl;
        	return i;
        }
        i++;
    }
    readFile.close();
    return 0;
}

void student::Delete() {
	int pos;
	pos=search();
	fstream f;
	f.open("stud.dat", ios::in | ios::out | ios::binary);
	f.seekg(0,ios::beg);
	if(pos==0){
		cout<<"\nRecord Not Found !!"<<endl;
		return;
	}
	int offset=pos*sizeof(stud);
	f.seekp(offset);
	rec.roll=-1;
	strcpy(rec.name, "NULL");
	rec.div='N';
	strcpy(rec.add, "NULL");
	f.write((char*)&rec, sizeof(stud));
	f.seekg(0);
	f.close();
	cout<<"\nDeleted"<<endl;
}

int main(){
	student s;
	s.create();
	s.display();  
	s.Delete();
	s.display();
	return 0;
}		

