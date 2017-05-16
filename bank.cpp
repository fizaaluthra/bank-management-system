#include<iostream.h>
#include <fstream.h>
#include<string.h>
struct add
{
	char country[40];
	char city[20];
	int pc;
};

class account
{
	char name[40];
	int id;
	int phno;
	float balance;


	add address;
public:
void getdata()
{
	cout<<"Enter Name ";
	cin.getline(name,40);
	cout<<"Enter ID no ";
	cin>>id;
	cout<<"\n Enter phone number ";
	cin>>phno;
    cout<<"Enter balance ";
    cin>>balance;

	cout<<"\n Enter postal code ";
	cin>>address.pc;
	cout<<"\n Enter city ";
	gets(address.city);
	cout<<"Enter country ";
	gets(address.country);

}
int getid()
{
	return id;
}
void putdata()
{
	cout<<"Name: "<<name;
	cout<<"ID: "<<id;
	cout<<"Phone: "<<phno;
	cout<<"Balance "<<balance;
	cout<<"Postal code: "<<address.pc;
	cout<<"City: "<<address.city;
	cout<<"Country: "<<address.country;
}
void changebal(int n)
{
	balance=n;
}
}a;
void add()
{
	fstream f1;
	f1.open("bank.dat", ios::out | ios::app );
	int a,j;
	int n,i;
	cout<<"How many records do you want to enter ? ";
	cin>>n;
	for(i=1;i<=n;++i)
	{
		a.getdata();
		f1.write((char*)&a,sizeof(a));

	}
    f1.close();
}
void display()
{
	fstream f1;
	int n;
	cout<<"Enter id no. ";
	cin>>n;
	f1.open("bank.dat",ios::in);
	while(f1.read((char*)&a,sizeof(a)))
	{
		if(a.getid()==n)
		a.putdata();
	}
	f1.close();
}
void deleterecord()
{
	fstream f1,f2;
	int n;
	cout<<"Enter id no. ";
	cin>>n;
	f1.open("bank.dat", ios::in);
	f2.open("temp.dat",ios::out);
	int fl=0;
	while(f1.read((char*)&a,sizeof(a)));
	{
		if(a.getid()!=n)
			f2.write((char*)&a,sizeof(a));

		else
		fl=1;
	}
	if(fl==1)
	cout<<"Record successfully deleted ";
	else
	cout<<"Record not found ";

}
void modify()
{
	fstream f1;
	float withdraw;
	int n;
	int fl=0;
	cout<<"Enter ID no ";
	cin>>n;
	f1.open("bank.dat",ios::in | ios::out);
	while(f1.read((char*)&a,sizeof(a)))
	{
		if(a.getid()==n)
		{
			cout<<"Enter withdraw amount ";
			cin>>withdraw;
			a.changebal(withdraw);
			f1.seekp(-1*sizeof(a),ios::cur);
			f1.write((char*)&a, sizeof(a));
		    cout<<"Record modified ";
		    fl=1;
		    cout<<"Current balance amount";
		    display();
		}
	}
	if(fl==0)
	cout<<"Record not found ";
	f1.close();

}
int main()
{
   int x;
   cout<<"1. Add more records ";
   cout<<endl<<"2. Search and display a record ";
   cout<<endl<<"3. Delete a record ";
   cout<<endl<<"4. Modify a record ";
   cout<<endl<<endl<<"Please enter your choice ";
   cin>>x;
   switch(x)
   {
   	case 1: add();
   	        break;
   	case 2: display();
   	        break;
   	case 3: delete();
   	        break;
   	case 4: modify();
   	        break;
   }
   return 0;
}
