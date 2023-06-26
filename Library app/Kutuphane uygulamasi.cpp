#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct book {
	string ad;
	string atandigiogrenci = {};
	string yazar;
};
book kitap[10000];

int n;
bool Admin;

void KitapListesiNoPause();
void Saver();
int Nfinder();
int Admin_Login();
string Student_Login();
int ShowScreen(string);
void Kitap_Listesi();
void Kitap_Atama();
void Kitap_Ekleme();
void Txt_Struct();
void Kitap_Silme();
void Kitap_Iade(string);
void Add_Student();
void Search();
string Lower(string);

int main()
{	while(1)
	{
		string no;
		n = Nfinder();
		Saver();
		int secim;
		system("cls");
		cout << "1-Admin Login" << endl << "2-Student Login" <<endl <<"3-Exit to Desktop" << endl;
		cout << "Your choice:";
		while (1)
		{

			cin >> secim;
			if (secim > 3 || secim < 1)
			{
				system("cls");
				cout << "Enter a number between 1 and 3" << endl << "Your choice:";
			}
			else
				break;
		}
		if(secim==3)
		{
			return 0;
		}
		switch (secim)
		{
		case 1:
		{

			Admin = Admin_Login();
			break;
		}
		case 2:
		{
			no = Student_Login();
			break;
		}
		}

		ShowScreen(no);
	}
}

int Nfinder()
{
	int i = 0;
	string satir;
	ifstream Kitaplar;
	Kitaplar.open("Books.txt");
	while (getline(Kitaplar, satir))
	{
		i++;
	}
	Kitaplar.close();
	return i;
}
int Admin_Login()
{
	system("cls");
	string admin_sifre;
	string satir;
	ifstream PASS;
	PASS.open("AdminSifre.txt");
	PASS >> satir;
	PASS.close();

	while (1)
	{
		cout << "Admin Password:";
		cin >> admin_sifre;
		if (satir == admin_sifre)
		{
			return true;
		}
		else
		{
			cout << "password is incorrect" << endl;
		}
	}
}
string Student_Login()
{
	int i = 0, j = 0;
	string studentNo;
	string studentPass;
	string satir;
	string satir2;
	while (1)
	{
		system("cls");
		cout << "Student No:";
		cin >> studentNo;
		cout << "Student Password:";
		cin >> studentPass;
		ifstream StudentNo;
		StudentNo.open("StudentNo.txt");
		while (getline(StudentNo, satir))
		{
			i++;
			if (studentNo == satir)
			{
				break;
			}
		}
		StudentNo.close();
		ifstream StudentPass;
		StudentPass.open("StudentPass.txt");
		while (j < i)
		{
			j++;
			getline(StudentPass, satir2);
		}
		if (studentPass == satir2)
		{
			Admin = false;
			break;
		}
		else
		{
			system("cls");
			cout << "password or student no is incorrect" << endl;
		}
	}
	return studentNo;
}
int ShowScreen(string no)
{
	int secim;

	if (Admin == true)
	{
		while (1)
		{
			while (1)
			{
				system("cls");
				cout << "Welcome" << endl;
				cout << "Operations:" << endl << "1-Book list  " << "2-Add a book " << "3-Delete a book " << "4-Register a book to a student "<<endl<<"5-Register a Student " <<"6-Search for a book's order " << "7-Exit to login screen" << endl << "Your choice:";
				Txt_Struct();
				cin >> secim;
				if (secim > 7 || secim < 1)
				{
					cout <<endl << "Please enter a number between 1 and 5"<<endl;
					system("pause");
				}
				else if (secim == 7)
				{
					return 0;
				}
				else
				{

					switch (secim)
					{
					case 1:
					{
						Kitap_Listesi();
						break;
					}
					case 2:
					{	Kitap_Ekleme();
					break;
					}
					case 3:
					{
						Kitap_Silme();
						break;
					}
					case 4:
					{
						Kitap_Atama();
						break;
					}
					case 5:
					{
						Add_Student();
						break;
					}
					case 6:
					{
						Search();
						break;
					}
					}
					break;
				}
			}
		}
	}
	else
	{
		while (1)
		{
			while (1)
			{
				system("cls");
				cout << "Welcome"<<endl ;
				cout <<"No:"<<no<< endl << "Operations:" << "1-Book list " << "2-Return a book " <<"3-Search for a book's order " << "4-Exit to login screen " << endl;
				cout << "Your choice:";
				cin >> secim;
				if (secim > 4 || secim < 1)
				{
					cout << "Please enter a number between 1 and 4";
				}
				else if (secim == 4)
				{
					return 0;
				}
				else
				{

				switch (secim)
				{
					case 1:
					{
					Kitap_Listesi();
					break;
					}
					case 2:
					{	
					Kitap_Iade(no);
					break;
					}
					case 3:
					{
					Search();
					break;
					}
				}
				break;
				}
			}
		}
	}
}
void Kitap_Listesi()
{

	int i ;
	cout << endl << endl;
	for (i = 1; i <= n ;i++)
	{
		cout << i << "-" << kitap[i].ad <<"    Author:"<<kitap[i].yazar;
		if (kitap[i].atandigiogrenci.length() == 9)
		{
			cout << " [This book is registered to a student]";
		}
		cout << endl;
	}
	system("pause");
}
void Kitap_Ekleme()
{
	cout << "Name of the book you are going to add:";
	cin.ignore();
	getline(cin,kitap[n+1].ad);
	cout << "Author";
	getline(cin, kitap[n + 1].yazar);
	
	ofstream Kitap;
	ofstream Author;
	Kitap.open("Books.txt", ios_base::app);
	Author.open("Author.txt", ios_base::app);
	Kitap <<endl<< kitap[n+1].ad;
	Author << endl << kitap[n + 1].yazar;
	Kitap.close();
	Author.close();
	n++;

}
void Txt_Struct()
{
	int i = 1;
	ifstream Kitap,Author;
	string satir;
	Kitap.open("Books.txt");
	Author.open("Author.txt");
	while (getline(Kitap, kitap[i].ad))
	{
		i++;
	}
	i = 1;
	while (getline(Author, kitap[i].yazar))
	{
		i++;
	}
	Kitap.close();
	Author.close();
}
void Kitap_Silme()
{
	system("cls");
	int secim, i;
	while (1)
	{



		KitapListesiNoPause();
		cout << endl << "The book you want to delete:";
		cin >> secim;
		if (secim<1 || secim > n)
		{
			cout << "Please add a number between 1 and " << n << endl;
			system("pause");
			system("cls");
		}
		else
		{
			if (kitap[secim].atandigiogrenci.length() == 9)
			{
				cout << "You can not delete a book that is registered to a student" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << endl << endl;
				for (secim; secim < n; secim++)
				{
					kitap[secim].ad = kitap[secim + 1].ad;
					kitap[secim].atandigiogrenci = kitap[secim + 1].atandigiogrenci;
					kitap[secim].yazar = kitap[secim + 1].yazar;

				}
				kitap[n].ad = "";
				n--;
				ofstream Kitap;

				Kitap.open("Books.txt");
				for (i = 1; i < n; i++)
				{
					Kitap << kitap[i].ad << endl;
				}
				Kitap << kitap[i].ad;
				Kitap.close();
				break;
			}
		}
	}

}
void Kitap_Atama()
{
	bool D = false;
	int secim;

	string ogrencino, satir;
	ifstream Ogrencino;
	Ogrencino.open("StudentNo.txt");
	while (1)
	{
		system("cls");
		KitapListesiNoPause();
		cout <<endl << " The book you want to register:";
		cin >> secim;
			if (secim<1 || secim > n)
			{
				cout << "Please enter a number between 1 and " << n;
				system("pause");
			}
			else if (kitap[secim].atandigiogrenci.length() == 9)
			{
				cout << "You cannot register a book that is already registered"<<endl;
				system("pause");
			}
			else
				break;
	}
	cout << "The number of the the student you want to register:";
	cin >> ogrencino;
	while (getline(Ogrencino, satir))
	{
		if (satir == ogrencino)
		{

			ofstream Atanan;

			Atanan.open("Atanan.txt", ios_base::app);
			kitap[secim].atandigiogrenci = ogrencino;
			Atanan << ogrencino << endl << kitap[secim].ad<<endl;
			D = true;
			break;
			Atanan.close();
			Saver();
		}
		else
		{}
	}
			if (D != true)
			{
				cout << "The student no you entered is not in our system"<<endl;
				system("pause");
			}
	Ogrencino.close();
}
void Kitap_Iade(string no)
{
	Saver();
	int secim;
	string atama_no, satir;
	int arr[10000];
	int i, j = 1, k, x;
	cout << "Books that are registered to you:" << endl;
	for (i = 1; i <= n; i++)
	{
		atama_no = kitap[i].atandigiogrenci;
		if (atama_no.compare(no) == 0)
		{
			cout << j << "-" << kitap[i].ad << endl;
			arr[j] = i;
			j++;
		}
	}
	x = j;
	if (j == 1)
	{
	cout << "There is no book  registered to you" <<endl ;
	system("pause");
	}
	else
	{
		while (1)
		{
			cout << "The book you want to return:";
			cin >> secim;
			if (secim <= 0 || secim > x - 1)
			{
				cout << "Please enter a number between 0 and" << x << endl;
			}
			else
			{
				kitap[arr[secim]].atandigiogrenci = {};
				ofstream Atanan;
				Atanan.open("Atanan.txt");
				for (k = 1; k <= n; k++)
				{
					if (kitap[k].atandigiogrenci.length() == 9)
					{
						Atanan << kitap[k].atandigiogrenci << endl << kitap[k].ad<< endl;
					}
				}
				Atanan.close();
				break;
			
			}
		}
	}




}
void Saver()
{
	Txt_Struct();
	int i;
	string satir, satir2, tempsatir;
	ifstream Kitap;
	ifstream Atanan;
	Atanan.open("Atanan.txt");

	while (getline(Atanan, satir))
	{
		Kitap.open("Books.txt");
		i = 1;
		while (getline(Kitap, satir2))
		{
			if (satir.compare(satir2) == 0)
			{
				kitap[i].atandigiogrenci = tempsatir;
				break;
			}
			i++;

		}
		Kitap.close();
		tempsatir = satir;
	}
	Atanan.close();
}
void KitapListesiNoPause()
{
	int i;
	cout << endl << endl;
	for (i = 1; i <= n; i++)
	{
		cout << i << "-" << kitap[i].ad << "    Author:" << kitap[i].yazar;
		if (kitap[i].atandigiogrenci.length() == 9)
		{
			cout << " [This book is registered to a student]";
		}
		cout << endl;
	}
}
void Add_Student()
{
	bool existence = false;
	string no,pass,notxt;
	ifstream No;
	ofstream StudentNo;
	ofstream StudentPass;
	No.open("StudentNo.txt", ios_base::app);
	StudentNo.open("StudentNo.txt", ios_base::app);
	StudentPass.open("StudentPass.txt", ios_base::app);
	while (1)
	{
		existence = false;
		cout << "Student No:";
		cin >> no;
		while (getline(No, notxt))
		{
			if (no == notxt)
			{
				cout << "This student already exist in our system";
				system("pause");
				system("cls");
				existence = true;
				break;
			}
		}
		if (existence == true)
		{continue;}

		if (no.length() != 9)
		{
			cout << "Student no should be 9 character long.";
			system("pause");
			system("cls");
			continue;
		}
		break;
	}
	cout << "Student Password:";
	cin >> pass;
	StudentNo <<endl << no;
	StudentPass << endl << pass;
	StudentNo.close();
	StudentPass.close();
	No.close();
}
void Search()
{
	int i=0;
	string n1, n2;
	cout << "The book you are gonna search:";
	cin >> n1;
	n1 = Lower(n1);
	ifstream BOOK;
	BOOK.open("Books.txt");
	while (getline(BOOK, n2))
	{
		i++;
		n2 = Lower(n2);
			if (n1 == n2)
			{
				break;
			}
	}
	cout << "The order of the book is :" << i<<endl;
	system("pause");
}
string Lower(string s2)
{
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s2;
}