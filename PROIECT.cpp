
//citire din fisier //login
//scriere in fisier
//constructor
//meniu
#include<iostream>
#include<list>
#include<string>
#include<map>
#include<iterator>
#include<vector>
#include "PROIECT.h"
using namespace std;
Client::Client(string nume, int nr,list <int> calendar1)
{
    this->nume=nume;
    this->nr_puncte_f=nr;

}

Admin:: Admin(string id,string parola)
{
    this->id=id;
    this->parola=parola;

}
Obiect :: Obiect(string nume, float pret, int nr)
{
    this->nume=nume;
    this->pret=pret;
    this->nr_produs=nr;
}

Manga :: Manga (string nume,float pret,int nr_produs,int nr_volume,vector <Obiect> volume):Obiect(nume,pret,nr_produs){
this->nr_volume=nr_volume;
this->volume=volume;
}
vector<Obiect> Manga ::get_volum()
{
    return this->volume;
}
vector<Obiect>Obiect:: get_volum(){
return this->volume;}

string Manga::getNume(){
return this->nume;}
int Manga:: get_stoc(){
return this->nr_produs;
}
int Manga::get_volume(){
return this->nr_volume;
}
float Manga::get_pret(){
return this->pret;
}
int Obiect::get_volume(){
return this->nr_volume;}
int Obiect ::get_stoc(){
return this->nr_produs;}
float Obiect ::get_pret(){
return this->pret;}
void Obiect::afisare(){
}
void Manga ::afisare(){
cout<<" Nume :"<<this->nume<<" "<<" Numarul de volume "<<this->nr_volume<<" Pret "<<this->pret<<" "<<endl<<"Volumele prezente in stoc :"<<endl;
int k=1;
for(auto it:volume){
    cout<<k<<". ";
    k++;
    cout<<"Nume :  "<<it.getNume()<<" Cantitate in stoc "<<it.get_stoc()<<" Pret : "<<it.get_pret()<<" $ "<<endl;
}
}
void Obiect::setNume(string x)
{
     this->nume=x;
}
 void Obiect::setNr(int x)
{
    this->nr_produs=x;
}
 void Obiect::setPret(float x)
{
    this->pret=x;
}
ostream& operator <<(ostream &o,const Obiect &x)
{
    o<<x.nume<<" "<<x.nr_produs<<" "<<x.pret<<" $";
    return o;
}
string Obiect::getNume()
{
    return this->nume;
}
int Obiect::getNr()
{
    return this->nr_produs;
}
float Obiect::getPret()
{
    return this->pret;
}














