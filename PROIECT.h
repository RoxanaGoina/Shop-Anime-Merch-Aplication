#include<iostream>
#include<list>
#include<string>
#include<map>
#include<iterator>
#include<vector>
using namespace std;
class Obiect{
    protected:
    string nume;
    float pret;
    int nr_produs;
     int nr_volume;
     vector<Obiect> volume;
public:
    Obiect(string nume, float pret, int nr);
    Obiect(){}
    string getNume();
    float getPret();
    int getNr();
   void  setNume(string x);
   void setNr(int x);
    void setPret(float x);
    virtual void afisare();
    friend ostream& operator <<(ostream &o,const Obiect &x);
    virtual int get_stoc();
    virtual int get_volume();
    virtual float get_pret();
    vector<Obiect> get_volum();
    virtual ~Obiect() = default;

};
class Manga:public Obiect{
    int nr_volume;
    vector<Obiect>volume;
public:
    Manga(string nume,float pret,int nr_produs,int nr_volume,vector <Obiect> volume);
    void afisare();
    string getNume();
    int get_stoc();
    //~Manga() override= default;
    virtual int get_volume();
    float get_pret();
    vector<Obiect>get_volum();

};
class Haine:public Obiect{
    string marime;
    char s;
};
class Client{
    string nume;
    int nr_puncte_f;
    list <int > calendar;
public:
    Client(string nume, int nr, list<int> calendar);
};
class Admin{
    protected:
    string id;
    string parola;
public:
    Admin(string id,string parola);
    Admin(){}



};

