#ifndef GEN_HPP
#define GEN_HPP
#include <cstring>
#include <iostream>
using namespace std;

template<class T>
class Gen
{	
		int db;
		T* t;
		
	public:
//�LTAL�NOS TAGF�GGV�NYEK
	//ITER�TOR EL�DEKLAR�CI�
		class iterator;

	//KONSTRUKTOR
		Gen(int darab=6): db(darab)
		{
			t=new T[darab];
		}

	//COPY KONSTRUKTOR
		Gen(Gen const& e)
		{
			this->db=e.db;
			//delete[] this->t;
			this->t=new T[e.db];
			for(int i=0;i<this->db;i++)
			{
				this->t[i]=e.t[i];
			}
		}

	//DESTRUKTOR
		~Gen() 
		{
			delete[] t;
		}

	/*//ELEMSZ�M N�VEL�S
		void novel();*/
	
	//ITER�TOR

		iterator begin()  // l�trehoz egy iter�tort �s az elej�re �ll�tja
		{     
			return iterator(*this, 0, this->Getdb());
		}
		iterator end() // l�trehozza �s az utols� elem ut�n �ll�tja
		{        
			return iterator(*this, this->Getdb(), this->Getdb());
		}

		class iterator
		{
				T *p, *pe;	        // pointer az akt elemre, �s az utols� ut�nira
			public:
				//DEFAULT KONSTRUKTOR
				iterator() :p(0), pe(0) {}
				//KONSTRUKTOR GEN-R�L
				iterator(Gen& a, int ix = 0, int siz=0)  :p(a.t+ix), pe(a.t+siz) {}
				//ITER�TOR N�VEL�SE
				iterator& operator++() 
				{    
					if (p != pe) ++p; 
					return *this; 
				}
				iterator operator++(int) // n�veli az iter�tort (post) 
				{    
					iterator tmp = *this;
					if (p != pe) p++; 
					return tmp; 
				}
				//�SSZEHASONL�T�S
				bool operator!=(const iterator &i) 
				{ 
					return(p != i.p);  
				}
				T& operator*()  // indirekci�
				{           
					if (p != pe) return *p; 
					else throw "Hibas indirekcio";
				}
				T* operator->() // indirekci�
				{           
					if (p != pe) return p; 
					else throw "Hibas indirekcio";
				}
				T iter()
				{
					if (p != pe) return *p; 
					else throw "Hibas indirekcio";
				}
 
		};  
	//ITER�TOR V�GE

	//T�MB ELEMSZ�M�NAK LEK�RDEZ�SE
		int Getdb();
				
	//SHELL RENDEZ�SEK
		int compare(T a, T b);
		
		void shell(int n);
		void strshell(int n);

	//KI�RAT�S
		void Print();

	//INDEXOPER�TOR
		T& operator[](int i);
		
	//EGYENL�S�G OPER�TOR
		int operator==(Gen& e);
		
	//�RT�KAD� OPER�TOR
		Gen& operator=(const Gen& a);
		
	//2 T�MB ELEMEINEK �SSZEAD�SA
		Gen operator+(Gen& d);
		Gen& operator+=(Gen& d);
		
	//T�MB ELEMEIHEZ EGY VAL�S SZ�M HOZZ�AD�SA
		Gen operator+(double elem);
		Gen& operator+=(double elem);
		
	//M�SIK T�MBBEL VAL� SZORZ�S
		Gen operator*(Gen& d);
		Gen& operator*=(Gen& d);
		
	//VAL�S SZ�MMAL VAL� SZORZ�S
		Gen operator*(double c);
		Gen& operator*=(double c);

	//T�MB�K ELEMEINEK KIVON�SA
		Gen operator-(Gen& d);
		Gen& operator-=(Gen& d);
		
	//T�MB�K ELEMEIB�L EGY VAL�S SZ�M KIVON�SA
		Gen operator-(double elem);
		Gen& operator-=(double elem);
/*
	//�J ELEM HOZZ�AD�SA A T�MB V�G�RE
		Gen& Add(T  elem);

	///L�TEZ� ELEM �T�R�SA	
		Gen& Over(int hanyadik, T  elem);*/
	//STRINGEK
		void StrLenAvg();
		void StrLenMax();
		void StrLenMin();

	
	//SZAMOKRA
		
		void Modusz();
		void Median();
		T GetMax();
		T GetMin();
		T GetSum();
		T GetSzorzat();
		double GetAvg();
};
#endif
