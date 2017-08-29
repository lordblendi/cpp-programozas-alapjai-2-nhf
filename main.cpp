#include <cstring>
#include <iostream>
#include "gen.cpp"
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//OPER�TOROK TESZTEL�SE - INT T�MB�KET HASZN�LOK
	Gen<int> x(7), x2(4), x5(6), xx;
	//ertekadasok - ezekkel a sz�mokkal jobban l�tszik az oper�torok m�k�d�se, ez�rt itt nem haszn�lok f�jlbeolvas�st
	for(int i=0; i<7;i++)
	{
		x[i]=1;

	}
	for(int i=0; i<4;i++)
	{
		x2[i]=-1;
	}
	for(int i=0; i<6;i++)
	{
		x5[i]=i*i;
	}
	//kiiratasok
	cout<<"x rendesen: "<<endl;
	x.Print();
	cout<<endl<<"x2 rendesen: "<<endl;
	x2.Print();
	cout<<endl<<"x5 rendesen: "<<endl;
	x5.Print();

	cout<<endl<<"minden operatort az x generikus tombre futtatom."<<endl;
	//szamokkal valo teszteles
	cout<<endl<<"1 hozzaadva"<<endl;
	x+=1;
	x.Print();
	cout<<endl<<"1 kivonva"<<endl;
	x-=1;
	x.Print();
	cout<<endl<<"3al szorozva"<<endl;
	x*=3;
	x.Print();

	//tombokkel valo teszteles
	cout<<endl<<"x2 hozzaadasa"<<endl;
	x+=x2;
	x.Print();
	cout<<endl<<"x2 kivonasa"<<endl;
	x-=x2;
	x.Print();
	cout<<endl<<"x5el valo szorzas"<<endl;
	x*=x5;
	x.Print();

	//kiadas masik tombbe - szamokkal valo muveletek
	cout<<endl<<"x most"<<endl;
	x.Print();
	cout<<endl<<"xxbe x*2"<<endl;
	xx=x*2;
	xx.Print();
	cout<<endl<<"xxbe x-2"<<endl;
	xx=x-2;
	xx.Print();
	cout<<endl<<"xxbe x+2"<<endl;
	xx=x+2;
	xx.Print();

	//kiadas masik tombbe - tombokkel valo muvelet
	cout<<endl<<"xxbe x*x2"<<endl;
	xx=x*x2;
	xx.Print();
	cout<<endl<<"xxbe x-x2"<<endl;
	xx=x-x2;
	xx.Print();
	cout<<endl<<"xxbe x+x2"<<endl;
	xx=x+x2;
	xx.Print();


	//MARAD�K SZ�MOKRA �RT F�GGV�NYEK MEGH�V�SA
	cout<<endl<<"x maximuma: "<<x.GetMax()<<endl;
	cout<<"x minimuma: "<<x.GetMin()<<endl;
	cout<<"x szorzata: "<<x.GetSzorzat()<<endl;
	cout<<"x szummaja: "<<x.GetSum()<<endl;
	cout<<"x darabszama: "<<x.Getdb()<<endl;
	cout<<"x avgje: "<<x.GetAvg()<<endl;
	cout<<endl<<endl<<"x2 modusza"<<endl;
	x2.Modusz();
	cout<<"x5 medianja";
	x5.Median();

	//F�JLBEOLVAS�S - EZEKKEL FOGOM TESZTELNI A SHELLEKET - DOUBLE T�MB�KET HASZN�LOK
	//els� t�mb beolvas�sa
	ifstream f;
	string file;

	cout<<endl<<endl<<"Kerem adja meg, mi a fajl neve, es hogy hol talalhato."<<endl;
	cin>>file;
	if((file=="string.dat")||(file=="string2.dat"))
	{
		cout<<endl<<"ide csak szamokat tartalmazo fajlt adhat meg";
		while((file=="string.dat")||(file=="string2.dat"))
		{
			cout<<endl<<"adjon meg egy masik fajlt"<<endl;
			cin>>file;
		}
	}
	f.open(file.c_str(),ios::in); // Open file
	int szam=0,meret;


	if (f.is_open()) //a f�jl l�tez�s�nek ellen�rz�se
	{
		f>>meret;
		cout<<meret;
		Gen<double> x3(meret);
		while(f.good()) //addig olvas, am�g nincs error.
		{
			f>>x3[szam];
			szam++;
		}
		cout<<endl<<"x3 beolvasas utan"<<endl<<endl;
		x3.Print();
		cout<<endl<<"x3 elemei novekvo sorrendben"<<endl<<endl;
		x3.shell(1);
		x3.Print();
	}
	else
	{
		cout << "A fajl nem talalhato"<<endl<<endl;
	}

	f.close();

	//m�sodik t�mb beolvas�sa

	ifstream f2;
	cout<<endl<<"Kerem adja meg, mi a masodik fajl neve, es hogy hol talalhato."<<endl;
	cin>>file;
	if((file=="string.dat")||(file=="string2.dat"))
	{
		cout<<endl<<"ide csak szamokat tartalmazo fajlt adhat meg";
		while((file=="string.dat")||(file=="string2.dat"))
		{
			cout<<endl<<"adjon meg egy masik fajlt"<<endl;
			cin>>file;
		}
	}
	f2.open(file.c_str(),ios::in); // Open file
	szam=0;


	if (f2.is_open()) //a f�jl l�tez�s�nek ellen�rz�se
	{
		f2>>meret;
		Gen<double> x4(meret);
		while(f2.good()) //addig olvas, am�g nincs error.
		{
			f2>>x4[szam];
			szam++;
		}
		cout<<endl<<endl<<"x4 beolvasas utan"<<endl<<endl;
		x4.Print();
		cout<<endl<<"x4 elemei csokkeno sorrendben"<<endl<<endl;
		x4.shell(-1);
		x4.Print();
	}
	else
	{
		cout << "A fajl nem talalhato"<<endl<<endl;
	}

	f2.close();





	//STRINGEKRE �RT F�GGV�NYEK TESZTEL�SE - ILLETVE AZ EDDIG NEM MEGH�VOTT F�GGV�NYEKET IS ITT TESZTELEM
	//EZEKHEZ EL�G 1 STRING T�MB IS, SZINT�N F�JLBEOLVAS�SSAL OLDOM MEG

	ifstream f3;
	cout<<endl<<"Kerem adja meg, mi a fajl neve, es hogy hol talalhato."<<endl;
	cin>>file;
	if((file=="double1.dat")||(file=="double2.dat")||(file=="double3.dat")||(file=="double4.dat"))
	{
		cout<<endl<<"ide csak szovegeket tartalmazo fajlt adhat meg";
		while((file=="double1.dat")||(file=="double2.dat")||(file=="double3.dat")||(file=="double4.dat"))
		{
			cout<<endl<<"adjon meg egy masik fajlt"<<endl;
			cin>>file;
		}
	}
	f3.open(file.c_str(),ios::in); // Open file
	szam=0;

	if (f3.is_open()) //a f�jl l�tez�s�nek ellen�rz�se
	{
		f3>>meret;
		Gen<char*> x6(meret);
		for(szam=0;szam<meret;szam++)
		{
			x6[szam]=new char[20];
		}
		szam=0;
		while(f3.good()) //addig olvas, am�g nincs error.
		{

			f3>>x6[szam];
			szam++;
		}
		//str shellek
		cout<<endl<<"x6 beolvasas utan"<<endl<<endl;
		x6.Print();
		cout<<endl<<"x6 elemei novekvo sorrendben"<<endl<<endl;
		x6.strshell(1);
		x6.Print();
		cout<<endl<<"x6 elemei csokkeno sorrendben"<<endl<<endl;
		x6.strshell(-1);
		x6.Print();

		//str-es fuggvenyek
		x6.StrLenAvg();
		x6.StrLenMax();
		x6.StrLenMin();
/*
		elem hozzaadasa, atirasa
		x6.Add("szoftlab");
		cout<<endl<<"x6 egy szo hozzaadasa utan"<<endl<<endl;
		x6.Print();
		x6.Over(3,"almafacska");
		cout<<endl<<"x6 egy szo atirasa utan"<<endl<<endl;
		x6.Print();*/
		for(szam=0;szam<meret;szam++)
		{
			delete[] x6[szam];
		}
	}
	else
	{
		cout << "A fajl nem talalhato"<<endl<<endl;
	}

	f3.close();

	return 0;
}
