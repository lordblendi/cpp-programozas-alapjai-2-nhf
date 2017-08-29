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
//ÁLTALÁNOS TAGFÜGGVÉNYEK
    //ITERÁTOR ELÕDEKLARÁCIÓ
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
 
    /*//ELEMSZÁM NÖVELÉS
        void novel();*/
     
    //ITERÁTOR
 
        iterator begin()  // létrehoz egy iterátort és az elejére állítja
        {     
            return iterator(*this, 0, this->Getdb());
        }
        iterator end() // létrehozza és az utolsó elem után állítja
        {        
            return iterator(*this, this->Getdb(), this->Getdb());
        }
 
        class iterator
        {
                T *p, *pe;          // pointer az akt elemre, és az utolsó utánira
            public:
                //DEFAULT KONSTRUKTOR
                iterator() :p(0), pe(0) {}
                //KONSTRUKTOR GEN-RÕL
                iterator(Gen& a, int ix = 0, int siz=0)  :p(a.t+ix), pe(a.t+siz) {}
                //ITERÁTOR NÖVELÉSE
                iterator& operator++() 
                {    
                    if (p != pe) ++p; 
                    return *this; 
                }
                iterator operator++(int) // növeli az iterátort (post) 
                {    
                    iterator tmp = *this;
                    if (p != pe) p++; 
                    return tmp; 
                }
                //ÖSSZEHASONLÍTÁS
                bool operator!=(const iterator &i) 
                { 
                    return(p != i.p);  
                }
                T& operator*()  // indirekció
                {           
                    if (p != pe) return *p; 
                    else throw "Hibas indirekcio";
                }
                T* operator->() // indirekció
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
    //ITERÁTOR VÉGE
 
    //TÖMB ELEMSZÁMÁNAK LEKÉRDEZÉSE
        int Getdb();
                 
    //SHELL RENDEZÉSEK
        int compare(T a, T b);
         
        void shell(int n);
        void strshell(int n);
 
    //KIÍRATÁS
        void Print();
 
    //INDEXOPERÁTOR
        T& operator[](int i);
         
    //EGYENLÕSÉG OPERÁTOR
        int operator==(Gen& e);
         
    //ÉRTÉKADÓ OPERÁTOR
        Gen& operator=(const Gen& a);
         
    //2 TÖMB ELEMEINEK ÖSSZEADÁSA
        Gen operator+(Gen& d);
        Gen& operator+=(Gen& d);
         
    //TÖMB ELEMEIHEZ EGY VALÓS SZÁM HOZZÁADÁSA
        Gen operator+(double elem);
        Gen& operator+=(double elem);
         
    //MÁSIK TÖMBBEL VALÓ SZORZÁS
        Gen operator*(Gen& d);
        Gen& operator*=(Gen& d);
         
    //VALÓS SZÁMMAL VALÓ SZORZÁS
        Gen operator*(double c);
        Gen& operator*=(double c);
 
    //TÖMBÖK ELEMEINEK KIVONÁSA
        Gen operator-(Gen& d);
        Gen& operator-=(Gen& d);
         
    //TÖMBÖK ELEMEIBÕL EGY VALÓS SZÁM KIVONÁSA
        Gen operator-(double elem);
        Gen& operator-=(double elem);
/*
    //ÚJ ELEM HOZZÁADÁSA A TÖMB VÉGÉRE
        Gen& Add(T  elem);
 
    ///LÉTEZÕ ELEM ÁTÍRÁSA  
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
