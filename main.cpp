#include<iostream>
#include<list>
#include<string>
#include<string.h>
#include<map>
#include<iterator>
#include<vector>
#include <fstream>
#include "PROIECT.h"
#include<fstream>
#include<typeinfo>
list<Client> User;
vector<Obiect>Produsele;
vector<Manga>List_Manga;
#define NR_MAX_UTILIZATORI 10000
#define maxCharsPerLine 100
void deschidere();
char path[200]="C:\\Users\\user\\Desktop\\Proiectutul\\Clienti ID.txt";
char path2[200]="C:\\Users\\user\\Desktop\\Proiectutul\\ADMIN.txt";
Obiect produse[100];
int nr=0;
using namespace std;
map<string,string> m;
int contor = 0;
int readFromFile(char fileName[200])
    {
        FILE *filePointer = fopen(fileName, "r");
        if(filePointer == NULL)
        {
            printf("Nu pot deschide fisierul!");
            return 0;
        }
        else return 1;
    }
    void meniu_admin();
int deschide_fisier_admin(char path2[200])
{
    int d=readFromFile(path2);
    return d;

}
void citire_obiecte()
{
    ifstream f("obiecte.in");
    string x;
    int var;
    float varf;
    int ok;
    while(f>>x)
    {
        if(x=="obiect")
        {
            f>>x;
            produse[nr].setNume(x);
            f>>varf;
            produse[nr].setPret(varf);
            f>>var;
            produse[nr].setNr(var);
        }
        nr++;
    }
    f.close();

}
int login2(string id_user,string password_user){
string id,password;
    ifstream f("Clienti ID.txt");
    getline(f,id,'\n');
    getline(f,password,'\n');
    f.close();
    for(auto it: m)
    if(id_user==it.first && password_user==it.second)
        return 1;
    else return 0;
}
int login(string id1,string password1)
{
    string id,password;
    ifstream f("ADMIN.txt");
    getline(f,id,'\n');
    getline(f,password,'\n');
    f.close();
    if(id==id1 && password1==password)
        return 1;
    else return 0;
    //if(strncmp(id,id2,(strlen(id)-1))==0 && strncpy(password,password2,strlen(password)-1)==0)
}
int citire_dictionar(){
string id,parola;
ifstream f("Clienti ID.txt");
while(getline(f,id,'\n')){

getline(f,parola,'\n');
m.insert({id,parola});
}}
void vizualizare_produse(){
    int alegere;
    cout<<"Alege categoria de produse pe care doresti sa o vizualizezi :"<<endl;
    cout<<"1. Obiecte "<<endl<<"2. Manga "<<endl<<"3 .Haine "<<endl<<"4. Nu mai vreau sa vizualizez"<<endl;
    cout<<"Algerea dvs este : " ;
    cin>>alegere;
    if(alegere==1)
    for(auto it:Produsele){
cout<<"Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr();
    }
    else if(alegere==2)
        for(auto it:List_Manga)
            {cout<<"Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl<<it.get_volume();
                for(auto &itr:it.get_volum()){
                cout<<"Numele volumului "<<itr.getNume()<<"Cantitatea din stoc"<<itr.get_stoc()<<" Pret "<<itr.get_pret()<<endl;
           }//cout<<it;
        }
  else if(alegere==4)
        meniu_admin();
       // else if (dynamic_cast<Obiect*>(&it))
       // cout<<"Numele meu "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr();

}
void meniu_admin();
void adaugare(){
    cout<<"Ce tip de produs vrei sa adaugi?"<<endl;
    cout<<"1.Obiect"<<endl;
    cout<<"2.Manga"<<endl;
    cout<<"3.Haine"<<endl;
    cout<<"0.Nu mai vreau sa adaug"<<endl;
    int x;
    cin>>x;
    if(x==1)
    {
        string nume;
        cout<<"Nume = ";cin>>nume;
        int var;
        cout<<"Nr Produse = ";cin>>var;
        float varf;
        cout<<"Pret = ";cin>>varf;
        Obiect o(nume,varf,var);
        Produsele.push_back(o);
        meniu_admin();
    }
    if(x==2){
    string nume;
    float pret;
    int cantitate,nr_volume;
    vector<Obiect>M;
    cin.ignore();
    cout<<"Nume = ";
    getline(cin,nume);
    cout<<" Nr produse = ";
    cin>>cantitate;
    cout<<"Pret = ";
    cin>>pret;
    cout<<"Numar de volume = ";
    cin>>nr_volume;
    string nume_v;
    float pret_v;
    int  cantitate_v;
    for(int i=0;i<nr_volume;i++){
        cout<<"Numele volumului :"<<endl;
        cin.ignore();
        getline(cin,nume_v);
        cout<<endl<<"Pretul volumului :"<<endl;
        cin>>pret_v;
        cout<<endl<<"Cantitatea stocului :"<<endl;
        cin>>cantitate_v;
        cout<<endl;
      Obiect o(nume_v,pret_v,cantitate_v);
        M.push_back(o);
    cout<<o;

    }
    Manga k(nume,pret,cantitate,nr_volume,M);
    k.afisare();
    List_Manga.push_back(k);
    }
    else if(x==3){
        string nume;


    }
}
void stergere(){
    cout<<"Sectiunea unde poti sterge un produs"<<endl;
}
void modificare(){
    cout<<"Sectiunea unde poti modifica un produs"<<endl;
}
void meniu_admin(){
    cout<<"Alege una dintre optiunile de mai jos : "<<endl;
    cout<<"1. Vizualizare produse"<<endl <<"2. Adaugare produs "<<endl<<"3. Stergere produs "<<endl<<"4. Modificare  produs"<<endl<<"5. Iesire"<<endl;
    int alg;
    do{
        cout<<"alg= ";cin>>alg;
        if(alg==1){
            vizualizare_produse();
            cout<<endl;
            meniu_admin();
        return;
        }
        else if(alg ==2){
            adaugare();
            cout<<endl;
            meniu_admin();
        }
        else if(alg==3){
            stergere();
            cout<<endl;
            meniu_admin();
        }
        else if(alg==4)
        {
            modificare();
            cout<<endl;
            meniu_admin();
            cout<<endl;
        }
        if(alg==5)
        {
            cout<<endl;
            cout<<"Intoarcere la meniul principal"<<endl;

            deschidere();
            alg=6;
        }
    }while(alg==1  || alg==2 || alg==3  || alg==4 || alg==5);
}
void creare_cont(){
string id,parola;
cout<<"ID:"<<endl;
cin>>id;
while(m.find(id)!=m.end()){
    cout<<"ID-ul exista deja"<<endl<<"Mai incearca"<<endl;
    cin>>id;
}
cout<<"Parola(minim 8 caractere)"<<endl;
cin>>parola;
while(parola.size()<8)
{cout<<"Alege o parola mai lunga"<<endl;
cin>>parola;
}
cout<<"Confirmare parola"<<endl;
int k=0;
string parola2;
while(k<3 && parola!=parola2){
  cout<<"Introdu parola din nou"<<endl;
  cin>>parola2;
k++;

}

if(parola==parola2){
m.insert({id,parola});

}
else deschidere();
}
void meniu_user(){
    cout<<"Bun venit!"<<endl;
    cout<<"Alege una dintre optiunile de mai jos"<<endl;
    cout<<"1. Vizualizare produsele din stoc"<<endl<<"2. Stergere produs din cos"<<endl<<"3. Vizualizare numar de puncte de fidelitate"<<endl;
    cout<<"4. Iesire"<<endl;
    int alg;
    do{
        cin>>alg;
        if(alg==1)
            cout<<"Vizualizare produse"<<endl;
            vizualizare_produse();
         if(alg==2)
         cout<<"Stergere produse"<<endl;
        if(alg==3)
            cout<<"Vizualizare nr produse";
        if(alg==4){
            cout<<"Iesire";
            return;
    }
    }while (alg==1 || alg==2 || alg==3 || alg==4 || alg==5);
}
void deschidere(){
    int alegere;
    cout<<"Bun venit!"<<endl;
    cout<<" Selecteaza una dintre optiunile de mai jos"<<endl;
    cout<<"1. Sunt admin"<<endl<<"2. Sunt utilizator"<<endl<<"3. Nu am cont"<<endl<<"4. Pentru a inchide aplicatia apasati tasta 4^^"<<endl;
            cin>>alegere;cout<<alegere<<endl;
    if(alegere==1)
    {
        int d=deschide_fisier_admin(path2);
        if(d==0) return;

        else
        {
            string id,password;
            cout<<"ID: "<<endl;
            cin>>id;
            cout<<"Parola :"<<endl;
            cin>>password;
            int l=login(id,password);
            if(l==1)
            {
                cout<<"Bun venit, admin-ule"<<endl;
                meniu_admin();
            }
            else {
                cout<<"Autentificare imposibila";
                cout<<endl;
                deschidere();
            }
        }
    }
    else if(alegere==2){
{
            string id_user,password_user;
            cout<<"ID:"<<endl;
            cin>>id_user;
            cout<<"Parola: "<<endl;
            cin>>password_user;
            int l1=login2(id_user,password_user);
            if(l1==1)
            meniu_user();
            else{
            cout<<endl;
            cout<<"Autentificare imposibila"<<endl;
            cout<<endl;
            deschidere();
            }
        }
    }
    else if(alegere==3){
      creare_cont();
        cout<<"Contul a fost creat cu succes";
    }
    else
    {
        return ;
    }
}
void start(){
    deschidere();
}
void umplere_fisier()
{
    ofstream f("obiecte.txt");
    int i;
   for(auto it:Produsele){
    if(dynamic_cast<Obiect*>(&it))
    f<<it.getNume()<<","<<it.getPret()<<","<<it.getNr()<<endl;
   if(dynamic_cast<Manga*>(&it)){
    f<<it.getNume()<<","<<it.get_pret()<<","<<it.get_volume()<<","<<it.getPret();
    for(auto itr:it.get_volum()){
        f<<itr.getNume()<<","<<itr.get_stoc()<<","<<itr.get_pret();
    }
    f<<endl;
   }
   }
    f.close();

}
void scriere_cont(){
ofstream fout("Clienti ID.txt");
for(auto it:m){
    fout<<it.first<<endl<<it.second<<endl;
}
fout.close();
}
int main()
{citire_dictionar();
    citire_obiecte();
    start();
    umplere_fisier();
    scriere_cont();

    //for(auto it:m)
     //   cout<<it.first<<" "<<it.second;
vector<Obiect>A;
Obiect a("sdss",15.4,9);
Obiect b("sdss",15.4,9);
A.push_back(a);
A.push_back(b);


    cout<<"#";
    return 0;
}
