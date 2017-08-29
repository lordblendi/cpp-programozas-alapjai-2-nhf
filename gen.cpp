#include "gen.hpp"
#include <cstring>
#include <iostream>

using namespace std;

//template<class T>

//ÁLTALÁNOS TAGFÜGGVÉNYEK

	//TÖMB ELEMSZÁMÁNAK LEKÉRDEZÉSE
	template<class T>	
	int Gen<T>::Getdb()
{
	return this->db;
}

	/*//ELEMSZÁM NÖVELÉS
	template<class T>
	void Gen<T>:: novel()
{
	db++;
	delete[] t;
	t=new T[db];
}*/
			
//SHELL RENDEZÉSEK
	//SZÁM ÖSSZEHASONLÍTÓ FÜGGVÉNY
	template<class T>
	int Gen<T>::compare(T a, T b)
{
	if(a>b) return 1;
	else if(b>a) return -1;
	return 0;
}

	//CHAR* SHELLJE
	template<class T>
	void Gen<T>::strshell(int n)
{
	if(n>=0) n=1;
	else n=-1;
	int j,i,m;
	char* temp;
	for(m = this->Getdb()/2;m>0;m/=2)
	{
		for(j = m;j< this->Getdb();j++)
		{
			for(i=j-m;i>=0;i-=m)
			{
				if(strcmp(this->t[i+m],this->t[i])!=n)
				{
					temp = this->t[i];
					this->t[i] = this->t[i+m];
					this->t[i+m] = temp;
				}
			}

		}
	}
}

	//SZÁMOK SHELLJE
	template<class T>
	void Gen<T>::shell(int n)
{
	if(n>=0) n=1;
	else n=-1;
	int j,i,m;
	T temp;
	for(m = this->Getdb()/2;m>0;m/=2)
	{
		for(j = m;j< this->Getdb();j++)
		{
			for(i=j-m;i>=0;i-=m)
			{
				if(compare(this->t[i+m],this->t[i])!=n)
				{
					temp = this->t[i];
					this->t[i] = this->t[i+m];
					this->t[i+m] = temp;
				}
			}

		}
	}
}

//KIÍRATÁS
	template<class T>
	void Gen<T>::Print()
	{ 	iterator i1;
		int i=0;
		for(i1=this->begin();i1!=this->end();i++, i1++)
		{
			cout<<"A "<<i<<". elem: "<<*i1<<endl;
		}
	}

//INDEXOPERÁTOR
	template<class T>
	T& Gen<T>::operator[](int i)
	{
		if(i<0 || i>=this->Getdb()) throw "rossz indexeles";
		return this->t[i];
	}
	
//EGYENLÕSÉG OPERÁTOR
	template<class T>
	int Gen<T>::operator==(Gen<T>& e)
{
	if(this->db==e.db)
	{
		for(int i=0;i<e.db;i++)
		{
			if(e[i]!=t[i])
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
//ÉRTÉKADÓ OPERÁTOR
	template<class T>
	Gen<T>& Gen<T>::operator=(const Gen<T>& a)
	{
		if(this!=&a)
		{
			this->db=a.db;
			delete[] this->t;
			this->t=new T[a.db];
			for(int i=0;i<a.db;i++)
			{
				this->t[i]=a.t[i];
			}
		}
		return *this;
	}
	
//2 TÖMB ELEMEINEK ÖSSZEADÁSA
	template<class T>
	Gen<T> Gen<T>::operator+(Gen<T>& d)
{
	iterator i1, i2, i3;
	i1=this->begin();
	i2=d.begin();
	int darab;

	if(d.Getdb()>this->Getdb()) 
	{
		darab=this->Getdb();
	}
	else 
	{
		darab =d.Getdb();
	}
	Gen<T> v(darab);

	i3=v.begin();
	for(int i=0;(i3!=v.end())&&(i2!=d.end())&&(i1!=this->end());i++,i3++, i1++, i2++)
	{	
		*i3=*i1+*i2;
	}
	return v;
}
	template<class T>
	Gen<T>& Gen<T>::operator+=(Gen<T>& d)
{
	iterator i1, i2;
	i1=this->begin();
	i2=d.begin();
	while((i1!=this->end())&&(i2!=d.end()))
	{	
		*i1+=*i2;
		i1++;
		i2++;
	}
	return *this;
}
	
//TÖMB ELEMEIHEZ EGY VALÓS SZÁM HOZZÁADÁSA
	template<class T>
	Gen<T> Gen<T>::operator+(double elem)
{
	iterator i1, i2;
	i1=this->begin();
	int darab=this->Getdb();
	Gen<T> v(darab);
	i2=v.begin();

	for(int i=0;(i1!=this->end())&&(i2!=v.end());i++, i1++, i2++)
	{	
		*i2=*i1+ (T)elem;
	}
	return v;
}
	template<class T>
	Gen<T>& Gen<T>::operator+=(double elem)
{
	iterator i1;
	i1=this->begin();
	while(i1!=this->end())
	{	
		*i1+= (T)elem;
		i1++;
			
	}
	return *this;
}
	
//MÁSIK TÖMBBEL VALÓ SZORZÁS
	template<class T>
	Gen<T> Gen<T>::operator*(Gen<T>& d)
{

	iterator i1, i2, i3;
	i1=this->begin();
	i2=d.begin();
	int darab;

	if(d.Getdb()>this->Getdb()) 
	{
		darab=this->Getdb();
	}
	else 
	{
		darab =d.Getdb();
	}
	Gen<T> v(darab);

	i3=v.begin();
	for(int i=0;(i3!=v.end())&&(i2!=d.end())&&(i1!=this->end());i++,i3++, i1++, i2++)
	{	
		*i3=*i1 * *i2;
	}
	return v;

}
	template<class T>
	Gen<T>& Gen<T>::operator*=(Gen<T>& d)
{
	iterator i1, i2;
	i1=this->begin();
	i2=d.begin();
	while((i1!=this->end())&&(i2!=d.end()))
	{	
		*i1 *= *i2;
		i1++;
		i2++;
	}
	return *this;
}
	
//VALÓS SZÁMMAL VALÓ SZORZÁS
	template<class T>
	Gen<T> Gen<T>::operator*(double elem)
{
	iterator i1, i2;
	i1=this->begin();
	int darab=this->Getdb();
	Gen<T> v(darab);
	i2=v.begin();

	for(int i=0;(i1!=this->end())&&(i2!=v.end());i++, i1++, i2++)
	{	
		*i2=*i1 * (T)elem;
	}
	return v;
}
	template<class T>
	Gen<T>& Gen<T>::operator*=(double elem)
{
	iterator i1;
	i1=this->begin();
	while(i1!=this->end())
	{	
		*i1 *= (T)elem;
		i1++;
			
	}
	return *this;
}

//TÖMBÖK ELEMEINEK KIVONÁSA
	template<class T>
	Gen<T> Gen<T>::operator-(Gen<T>& d)
{
	iterator i1, i2, i3;
	i1=this->begin();
	i2=d.begin();
	int darab;

	if(d.Getdb()>this->Getdb()) 
	{
		darab=this->Getdb();
	}
	else 
	{
		darab =d.Getdb();
	}
	Gen<T> v(darab);

	i3=v.begin();
	for(int i=0;(i3!=v.end())&&(i2!=d.end())&&(i1!=this->end());i++,i3++, i1++, i2++)
	{	
		*i3=*i1 - *i2;
	}
	return v;
}
	template<class T>
	Gen<T>& Gen<T>::operator-=(Gen<T>& d)
{
	iterator i1, i2;
	i1=this->begin();
	i2=d.begin();
	while((i1!=this->end())&&(i2!=d.end()))
	{	
		*i1 -= *i2;
		i1++;
		i2++;
	}
	return *this;
}
	
//TÖMBÖK ELEMEIBÕL EGY VALÓS SZÁM KIVONÁSA
	template<class T>
	Gen<T> Gen<T>::operator-(double elem)
{
	iterator i1, i2;
	i1=this->begin();
	int darab=this->Getdb();
	Gen<T> v(darab);
	i2=v.begin();

	for(int i=0;(i1!=this->end())&&(i2!=v.end());i++, i1++, i2++)
	{	
		*i2=*i1 - (T)elem;
	}
	return v;
}
	template<class T>
	Gen<T>& Gen<T>::operator-=(double elem)
{
	iterator i1;
	i1=this->begin();
	while(i1!=this->end())
	{	
		*i1 -= (T)elem;
		i1++;
			
	}
	return *this;
}
/*	
//ÚJ ELEM HOZZÁADÁSA A TÖMB VÉGÉRE
	template<class T>
	Gen<T>& Gen<T>::Add(T  elem)
{
	int i;
	iterator i1, i2;
	i1=this->begin();
	Gen<T> v(this->Getdb());
	i2=v.begin();
	for(i=0;(i1!=this->end()) && (i2!=v.end());i++, i2++, i1++)
	{
		*i2=*i1;
	}

	this->novel();
	i1=this->begin();
	i2=v.begin();
	for(i=0;(i1!=this->end()) && (i2!=v.end());i++, i2++, i1++)
	{
		*i1=*i2;
	}
	*i1=elem;
	return *this;
}

///LÉTEZÕ ELEM ÁTÍRÁSA	
	template<class T>
	Gen<T>& Gen<T>::Over(int hanyadik, T  elem)
	{
		if((hanyadik>=this->Getdb())||(hanyadik<0)) throw "rossz indexeles";
		this->t[hanyadik]=elem;
		return *this;
	}*/

//STRINGEK
	template<class T>
	void Gen<T>::StrLenAvg()
{
	int szum=0;
	for(int i=0;i<this->Getdb();i++)
	{
		szum+=strlen(this->t[i]);
	}
	cout<<"Atlagos szohossz: "<< (double)szum/(double)this->Getdb()<<endl<<endl;
}
	
	template<class T>
	void Gen<T>::StrLenMax()
{
	int max=0;
	for(int i=0;i<this->Getdb();i++)
	{
		if(strlen(this->t[i])>strlen(this->t[max]))
		{
			max=i;
		}
	}
	cout<<endl<<"Leghosszabb szo: "<< this->t[max]<<"\t Betuk szama: "<<strlen(this->t[max])<<endl<<endl;
}
	
	template<class T>
	void Gen<T>::StrLenMin()
{
	int max=0;
	for(int i=1;i<this->Getdb();i++)
	{
		if(strlen(this->t[i])<strlen(this->t[max]))
		{
			max=i;
		}
	}
	cout<<endl<<"Legrovidebb szo: "<< this->t[max]<<"\t Betuk szama: "<<strlen(this->t[max])<<endl<<endl;
}


//SZAMOKRA
	template<class T>
	void Gen<T>::Modusz()
{
	iterator i=this->begin();
	iterator k=this->begin();
	int n=0;
	int *hanyszor;
	int j=0;
	hanyszor=new int[this->Getdb()];
	for(int p=0;p<this->Getdb();p++) hanyszor[p]=0;

	for(i=this->begin();i!=this->end();i++,j++)
	{
		for(k=this->begin();k!=this->end();k++)
		{
			if(*i==*k) hanyszor[j]++;
		}
	}
	int max=0;
	int maxi=0;
	for(int h=0;h<n;h++)
	{
		if(hanyszor[h]>max) maxi=h;
	}
	cout<<"A legtobbszor elofordulo elem: "<<this->t[maxi]<<"\t elofordulasok szama: "<<hanyszor[maxi]<<endl<<endl;
	delete[] hanyszor;
} 
	
	template<class T>
	void Gen<T>::Median()
{
		
	this->shell(1);
	if(this->Getdb()%2==0)
	{
		int i=this->Getdb()/2;
		int k=i-1;
		double avg= ((double)this->t[k]+(double)this->t[i])/2;
		cout<<endl<<endl<<"A kozepso ket elem: "<<this->t[k]<<" es "<<this->t[i]<<". Atlaguk: " <<avg<<endl;
	}
	else
	{
		int j=this->Getdb()/2+1;
		cout<<endl<<endl<<"A kozepso elem: "<<this->t[j]<<endl;
	}
}
	
	template<class T>
	T Gen<T>::GetMax()
{
	iterator i1=this->begin();
	T max=0;
	for(int i=1;i1!=this->end();i++,i1++)
	{
		if(max<*i1)
		{
			max=*i1;
		}
	}
	return max;
}
	
	template<class T>
	T Gen<T>::GetMin()
{
	iterator i1=this->begin();
	T min=*i1;
	i1++;
	for(int i=1;i1!=this->end();i++,i1++)
	{
		if(min>*i1)
		{
			min=*i1;
		}
	}
	return min;
}
	
	template<class T>
	T Gen<T>::GetSum()
{
	iterator i1=this->begin();
	T szum=0;
	for(int i=0;i1!=this->end();i++,i1++) szum+=*i1;
	return szum;

}
	
	template<class T>
	T Gen<T>::GetSzorzat()
{
	iterator i1=this->begin();
	T szorzat=1;
	for(int i=0;i1!=this->end();i++,i1++) szorzat*=*i1;
	return szorzat;
}
	
	template<class T>
	double Gen<T>::GetAvg()
{
	return (double)this->GetSum()/(double)this->Getdb();
}
