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
#include<algorithm>
list<Client> User;

vector<Obiect>Produsele;
vector<Manga>List_Manga;
vector<Haine>List_Haine;
map<string,string> Cos;
#define NR_MAX_UTILIZATORI 10000
#define maxCharsPerLine 100
void meniu_user();
void deschidere();
char path[200]="C:\\Users\\user\\Desktop\\Proiectutul\\Clienti ID.txt";
char path2[200]="C:\\Users\\user\\Desktop\\Proiectutul\\ADMIN.txt";
Obiect produse[100];
int nr=0;
bool cmp(Obiect o1,Obiect o2){
return o1.getPret()<o2.getPret();
}
bool cmp1(Obiect o1,Obiect o2){
return o1.getPret()>o2.getPret();
}
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
    ifstream f("obiecte.txt");
    string x,nmm;
    int cant,volume;
    vector <Obiect> mangi;
    float pret,pm;
    int ok,cm,nr,marime,canmar;
    Obiect o;
    Manga mg;
    getline(f,x);
    map<int,int> mapul;
    Haine h;
    if(x=="Obiect")
    {
        while(getline(f,x))
        {

            if(x!="Manga" && x!="Haine"){
            f>>pret;
            f>>cant;
            o.setNume(x);
            o.setPret(pret);
            o.setNr(cant);
            Produsele.push_back(o);
            f.ignore();
            }
            else break;
        }


    }
    if(x=="Manga")
        {
            while(getline(f,x))
            {
                if(x!="Haine"){
                f>>pret;
                f>>cant;
                f>>volume;
                for(int i=0;i<volume;i++)
                {
                    f.ignore();
                    getline(f,nmm);
                    f>>pm;
                    f>>cm;


                    o.setNume(nmm);
            o.setPret(pm);
            o.setNr(cm);
             mangi.push_back(o);

                }
                mg.setNume(x);
                mg.setPret(pret);
                mg.setNr(cant);
                mg.setVolume(volume);
                mg.setListaVolume(mangi);
                List_Manga.push_back(mg);
                f.ignore();
                 mangi.clear();


            }
            else break;
            }

        }
    if(x=="Haine")
    {
        while(getline(f,x))
        {
            f>>pret;
            f>>cant;
            f>>nr;
            for(int i=0;i<nr;i++)
            {
                f>>marime;
                f>>canmar;
                mapul.insert({marime,canmar});
            }
            h.setNume(x);
            h.setNr(cant);
            h.setPret(pret);
            h.setMarimi(mapul);
            List_Haine.push_back(h);
            f.ignore();
            mapul.clear();
        }
    }
        //nr++;

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
cout<<"Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" $"<<" Cantitate in stoc "<< it.getNr();
    }
    else if(alegere==2)
        for(auto it:List_Manga)
            {cout<<"Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" $"<<" Cantitate in stoc "<< it.getNr()<<endl<<it.get_volume();
                for(auto &itr:it.get_volum()){
                cout<<"Numele volumului "<<itr.getNume()<<"Cantitatea din stoc"<<itr.get_stoc()<<" Pret "<<itr.get_pret()<<endl;
           }//cout<<it;
        }
       else if(alegere==3)
    {
        for(auto it:List_Haine)
        {
            cout<<"Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" $"<<" Cantitate in stoc "<< it.getNr()<<endl;
            for(auto &itr:it.get_exemplare())
            {
                cout<<"Marimea : "<<itr.first<<"    "<<itr.second<<endl;
            }

        }
    }
  else if(alegere==4)
        meniu_admin();
       // else if (dynamic_cast<Obiect*>(&it))
       // cout<<"Numele meu "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr();

}
bool cmp2(Manga m1,Manga m2){
return m1.getNume()<m2.getNume();
}
bool pret1(Haine h1,Haine h2){
return h1.getPret()<h2.getPret();

}
bool pret2(Haine h1,Haine h2){
return h1.getPret()>h2.getPret();
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
        cout<<"Nume = ";
        cin.ignore();
        getline(cin,nume);
        int var;
        cout<<"Nr Produse = ";cin>>var;
        float varf;
        cout<<"Pret = ";cin>>varf;
        Obiect o(nume,varf,var);
        Produsele.push_back(o);
       // meniu_admin();
    }
    if(x==2){
    string nume;
    float pret;
    int cantitate,nr_volume;
    vector<Obiect>M;
    cin.ignore();
    cout<<"Nume = ";
    getline(cin,nume);
    cout<<" Numar  produse = ";
    cin>>cantitate;
    cout<<"Pret = ";
    cin>>pret;
    cout<<" $";
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
        float pret;
        int cantitate,marimi,cant,mrm;
        map<int,int> exemplare;
        cin.ignore();
        cout<<"Nume = ";
        getline(cin,nume);
        cout<<" Nr produse = ";
        cin>>cantitate;
        cout<<"Pret = ";
        cin>>pret;
        cout<<"Cate marimi avem ? ";
        cin>>marimi;
        for(int i=0;i<marimi;i++)
        {
            cout<<"Marime = ";
            cin>>mrm;
            cout<<"Nr. Exemplare = ";
            cin>>cant;
            exemplare.insert({mrm,cant});

        }
        Haine o(nume,pret,cantitate,exemplare);
        List_Haine.push_back(o);


    }
}
void scriere_cont();
void stergere(){
    cout<<"ce fel de produs doresti sa stergi?"<<endl;
    cout<<"1.Obiect"<<endl;
    cout<<"2.Manga"<<endl;
    cout<<"3.Haine"<<endl;
    cout<<"4.Nu mai doresc sa sterg"<<endl;
    int alg;
    string nume;
    cout<<"Alegere"<<endl;cin>>alg;
    if(alg==1)
    {
        cout<<endl<<"Care este numele obiectului pe care doresti sa-l stergi?"<<endl;
        cin.ignore();
        getline(cin,nume);
        int k=0,ok=0;
        for(auto &it:Produsele)
        {
            if(it.getNume()==nume)
            {
                ok=1;
                Produsele.erase(Produsele.begin()+k,Produsele.begin()+k+1);
                break;

            }
            k++;
        }
        if(ok=0)
        {
            cout<<"Nu exista un asemenea de produs"<<endl;
        }

    }
    else if(alg==2)
    {
        cout<<endl<<"Care este numele obiectului pe care doresti sa-l stergi?"<<endl;
        cin.ignore();
        getline(cin,nume);
        int k=0,ok=0;
        for(auto &it:List_Manga)
        {
            if(it.getNume()==nume)
            {
                List_Manga.erase(List_Manga.begin()+k,List_Manga.begin()+k+1);
                break;

            }
            k++;
        }
        if(ok=0)
        {
            cout<<"Nu exista un asemenea de produs"<<endl;
        }
    }
    else if(alg==3)
    {
        cout<<endl<<"Care este numele obiectului pe care doresti sa-l stergi?"<<endl;
        cin.ignore();
        getline(cin,nume);
        int k=0,ok=0;
        for(auto &it:List_Haine)
        {
            if(it.getNume()==nume)
            {
                List_Haine.erase(List_Haine.begin()+k,List_Haine.begin()+k+1);
                break;

            }
            k++;
        }
        if(ok=0)
        {
            cout<<"Nu exista un asemenea de produs"<<endl;
        }
    }
}
void modificare(){
    int alegere1,alg;
    float pret,pret1;
    int cantitate;
    string nume,nume1;
    cout<<"Alege tipul de produs pe care vrei sa il modifici"<<endl;
    cout<<"1. Obiecte"<<endl;
    cout<<"2. Manga"<<endl;
    cout<<"3. Haine"<<endl;
    cout<<"4. Nu mai vreau sa modific"<<endl;
    cout<<"Alegerea dumneavoastra este "<<endl;
    cin>>alegere1;
    if(alegere1==1)
    {
        cout<<"Alegeti ce doriti sa modificati"<<endl;
    cout<<"1. Numele "<<endl<<endl;
    cout<<"2. Pretul "<<endl<<endl;
    cout<<"3. Cantitatea"<<endl<<endl;
    cout<<"4. Nu mai vreau sa modific "<<endl<<endl;
    cout<<"Alegerea dumneavoastra este ";
    cin>>alg;
    int ok=0;
    if(alg==1){
            cout<<"Numele produsul cautat este  ";
            cin.ignore();
           getline(cin,nume);
            for(auto  &it:Produsele)
            if(it.getNume()==nume){
                    ok=1;
            cout<<"Numele nou este  ";
            getline(cin,nume1);
            it.setNume(nume1);
            }
            if(ok==0){
                cout<<"Nu exista produs cu acest nume. Incercati din nou"<<endl;
                modificare();
            }
        }
        if(alg==2){
            ok=0;
            cout<<"Numele produsului cautat este  ";
            cin.ignore();
            getline(cin,nume1);
            cout<<"$$$"<<nume1<<endl;
            for(auto &it:Produsele)
            if(it.getNume()==nume1){
                ok=1;
                cout<<"Pretul nou este  ";
                cin>>pret;
                it.setPret(pret);
            }
            if(ok==0) {
                cout<<"Nu exista produs cu acest nume. Incercati din nou"<<endl;
                modificare();
            }
        }
    if(alg==3){
            int cantitate;
         cout<<"Numele produsului cautat este  ";
         cin.ignore();
        getline(cin,nume);
        ok=0;
        for(auto  &it:Produsele)
        if(it.getNume()==nume){
                ok=1;
         cout<<"Cantitatea noua din stoc este  ";
         cin>>cantitate;
         it.setNr(cantitate);
        }
        if(ok==0) {
            cout<<"Nu exista produs cu acest nume. Incercati din nou"<<endl;
            modificare();
        }
    if(alg==4){
        modificare();
    }

    }
    }
    if(alegere1==2){// Manga
        cout<<" Alegeti ce doriti sa modificati "<<endl;
        int al;
        cout<<"1. Nume Manga"<<endl<<endl;
        cout<<"2. Pret Manga"<<endl<<endl;
        cout<<"3. Cantitate Manga"<<endl<<endl;
        cout<<"4. Nume Volume "<<endl<<endl;
        cout<<"5. Pret Volume "<<endl<<endl;
        //cout<<"6. Cantitate Volume"<<endl<<endl;
        cout<<"Alegere= ";cin>>al;
        cout<<endl<<endl;
        cout<<"Numele produsului pe care doriti sa-l modificati";
        string numele,inlocuire;
        int inl;
        cin.ignore();
        getline(cin,numele);
        int ok=0;
        for(auto &itr:List_Manga)
        {
            if(itr.getNume()==numele)
            {
                ok=1;
                if(al==1)
                {
                    cout<<"Cu ce doriti sa modificati?"<<endl;
                    //cin.ignore();
                    getline(cin,inlocuire);
                    itr.setNume(inlocuire);
                    cout<<inlocuire<<endl;
                }
                else if(al==2)
                {
                    cout<<"Cu ce doriti sa modificati?"<<endl;
                    cin>>inl;
                    itr.setPret(inl);
                }
                else if(al==3)
                {
                     cout<<"Cu ce doriti sa modificati?"<<endl;
                     cin>>inl;
                     itr.setNr(inl);
                }
                else if(al==4)
                {
                    string vol,vol2;
                    cout<<"Ce volum doriti sa modificati?"<<endl;
                    //cin.ignore();
                    getline(cin,vol);
                    cout<<"$$$$"<<vol<<endl;
                    for(auto &itrr:itr.get_volum())
                    {
                        if(itrr.getNume()==vol)
                        {
                            cout<<"Cu ce doriti sa modificati?"<<endl;
                            //cin.ignore();
                            getline(cin,vol2);
                            itrr.setNume("hwemebew");
                            cout<<"****"<<vol2<<"  "<<vol<<endl;

                        }

                    }
                }
                else if(al==5)
                {
                    float p;
                    string vol;
                    cout<<"Ce volum doriti sa modificati?"<<endl;
                   // cin.ignore();
                    getline(cin,vol);
                    for(auto &itrr:itr.get_volum())
                    {
                        if(itrr.getNume()==vol)
                        {
                            cout<<"Cu ce doriti sa modificati?"<<endl;
                            cin>>p;
                            itrr.setPret(p);
                        }
                    }
                }
            }
        }

    }
    else if(alegere1==3)
    {
        int alg;
        string nm;
        cout<<"Alegeti ce doriti sa modificati"<<endl;
        cout<<"1. Numele "<<endl<<endl;
        cout<<"2. Pretul "<<endl<<endl;
        cin>>alg;
        if(alg==1)
        {
            cout<<"Numele produsul cautat este  ";
            cin.ignore();
            getline(cin,nume);
            cout<<nume<<endl;
            int ok=0;
            for(auto  &it:List_Haine)
            {
                if(it.getNume()==nume)
                {
                    ok=1;
                    cout<<"Numele nou este  ";
                    getline(cin,nm);
                    it.setNume(nm);
                }
            }
            if(ok==0)
            {
                cout<<"Nu exista produsul"<<endl;
            }
        }
        if(alg==2)
        {
            int prt;
            cout<<"Numele produsul cautat este  ";
            cin.ignore();
            getline(cin,nume);
            int ok=0;
            for(auto  &it:List_Haine)
            {
                if(it.getNume()==nume)
                {
                    ok=1;
                    cout<<"Pretul nou este  ";
                    cin>>pret;
                    it.setPret(prt);
                }
            }
            if(ok==0)
            {
                cout<<"Nu exista produsul"<<endl;
            }
        }
    }
}
void vizualizare_produse_user(){
    int alegere;
   // do{
    cout<<"Alege categoria de produse pe care doresti sa o vizualizezi :"<<endl;
    cout<<"1. Obiecte "<<endl<<"2. Manga "<<endl<<"3 .Haine "<<endl<<"4. Nu mai vreau sa vizualizez"<<endl;
    cout<<"Algerea dvs este : " ;
    cin>>alegere;
    int choice,x;
    string nume,clasa;
    int k=1;
    if(alegere==1)
    {int cresc;
        cout<<"Daca doriti afisarea produselor in ordinea crescatoare a pretului apasati tasta 1 "<<endl<<endl;
        cout<<"Daca doriti afisarea produselor in ordinea descrescatoare a pretului apasati tasta 2"<<endl<<endl;
        cout<<"Daca nu aveti preferinte in ceea ce priveste vizualizarea obiectelor apasati tasta 3"<<endl<<endl;
    cin>>cresc;
    if(cresc==1){
            sort(Produsele.begin(),Produsele.end(),cmp);
            for(auto it:Produsele)
        {
            cout<<k<<". "<<"Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl;
            k++;
        }
        cout<<"Va intereseaza vreun produs?0 daca nu";
        cin>>choice;
        if(choice=1){
        k=1;
        for(auto it:Produsele)
        {
            if(k==choice)
            {
                cout<<"Vreti sa adaugati in cos? "<<endl;
                cin>>x;
                if(x==1)
                {
                    nume=it.getNume();
                    clasa="obiect";
                }
            }
            k++;
        }
        }


    }

    if(cresc==2){
        sort(Produsele.begin(),Produsele.end(),cmp1);
        for(auto it:Produsele)
        {
            cout<<k<<". "<<"Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl;
            k++;
        }
        cout<<"Va intereseaza vreun produs?0 daca nu";
        cin>>choice;
        if(choice=1){
        k=1;
        for(auto it:Produsele)
        {
            if(k==choice)
            {
                cout<<"Vreti sa adaugati in cos? "<<endl;
                cin>>x;
                if(x==1)
                {
                    nume=it.getNume();
                    clasa="obiect";
                }
            }
            k++;
        }
        }


    }

     if(cresc==3)
        for(auto it:Produsele)
        {
            cout<<k<<". "<<"Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl;
            k++;
        }
        cout<<"Va intereseaza vreun produs?0 daca nu";
        cin>>choice;
        if(choice=1){
        k=1;
        for(auto it:Produsele)
        {
            if(k==choice)
            {
                cout<<"Vreti sa adaugati in cos? "<<endl;
                cin>>x;
                if(x==1)
                {
                    nume=it.getNume();
                    clasa="obiect";
                }
            }
            k++;
        }
        }

    }
    else if(alegere==2){
        int alg;
    cout<<"Daca doriti o vizualizare alfabetica a articolelor manga apasati tasta 1"<<endl<<endl;
    cout<<"Daca nu aveti o preferinta in ceea ce priveste vizualizarea acestora apasati tasta 2"<<endl<<endl;
    cin>>alg;
    int k=1;
    if(alg==1)
    sort(List_Manga.begin(),List_Manga.end(),cmp2);
        for(auto it:List_Manga)
            {
                cout<<k<<" . Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl<<it.get_volume();
                for(auto &itr:it.get_volum()){
                cout<<"Numele volumului "<<itr.getNume()<<"Cantitatea din stoc"<<itr.get_stoc()<<" Pret "<<itr.get_pret()<<endl;
                k++;
           }//cout<<it;
        }
        cout<<"Va intereseaza vreun produs?0 daca nu";
        cin>>choice;
        k=1;
        for(auto it:List_Manga)
        {
            if(k==choice)
            {
                cout<<"Vreti sa adaugati in cos? "<<endl;
                cin>>x;
                if(x==1)
                {
                    nume=it.getNume();
                    clasa="obiect";
                }
            }
            k++;
        }
        if(alg==2){
             for(auto it:List_Manga)
            {
                cout<<k<<" . Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl<<it.get_volume();
                for(auto &itr:it.get_volum()){
                cout<<"Numele volumului "<<itr.getNume()<<"Cantitatea din stoc"<<itr.get_stoc()<<" Pret "<<itr.get_pret()<<endl;
                k++;
           }//cout<<it;
        }
        cout<<"Va intereseaza vreun produs?0 daca nu";
        cin>>choice;
        k=1;
        for(auto it:List_Manga)
        {
            if(k==choice)
            {
                cout<<"Vreti sa adaugati in cos? "<<endl;
                cin>>x;
                if(x==1)
                {
                    nume=it.getNume();
                    clasa="obiect";
                }
            }
            k++;
        }
        }
    }
    else if(alegere==3)
    {int a;
        int k=1;

        cout<<"Daca doriti vizualizarea articolelor vestimentare in functie de pret crescator apasati tasta 1"<<endl<<endl;
        cout<<"Daca doriti vizualizarea articolelor vestimentare in functie de pret descrescator apasati tasta 2"<<endl<<endl;
        cout<<"Daca criteriul de vizualizare nu conteaza pentru dumneavoastra apasati tasta 3"<<endl<<endl;
        cin>>a;

        if(a==1)
            sort(List_Haine.begin(),List_Haine.end(),pret1);
        if(a==2)
         sort(List_Haine.begin(),List_Haine.end(),pret2);
        for(auto it:List_Haine)
        {
            cout<<k<<" . Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl;
            for(auto &itr:it.get_exemplare())
            {
                cout<<"Marimea : "<<itr.first<<"    "<<itr.second<<endl;
            }
            k++;

        }
        cout<<"Va intereseaza vreun produs?0 daca nu";
        cin>>choice;
        k=1;
        for(auto it:List_Haine)
        {
            if(k==choice)
            {
                cout<<"Vreti sa adaugati in cos? "<<endl;
                cin>>x;
                if(x==1)
                {
                    nume=it.getNume();
                    clasa="obiect";
                }
            }
            k++;
        }
        if(a==3)
            for(auto it:List_Haine)
        {
            cout<<k<<" . Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl;
            for(auto &itr:it.get_exemplare())
            {
                cout<<"Marimea : "<<itr.first<<"    "<<itr.second<<endl;
            }
            k++;

        }
        cout<<"Va intereseaza vreun produs?0 daca nu";
        cin>>choice;
        k=1;
        for(auto it:List_Haine)
        {
            if(k==choice)
            {
                cout<<"Vreti sa adaugati in cos? "<<endl;
                cin>>x;
                if(x==1)
                {
                    nume=it.getNume();
                    clasa="obiect";
                }
            }
            k++;
        }
    }
  else if(alegere==4)
        meniu_user();


    }
void meniu_admin(){

    int alg;
    do{cout<<"Alege una dintre optiunile de mai jos : "<<endl;
    cout<<"1. Vizualizare produse"<<endl <<"2. Adaugare produs "<<endl<<"3. Stergere produs "<<endl<<"4. Modificare  produs"<<endl<<"5. Iesire"<<endl;
        cout<<"Alegerea dumneavoastra este  ";cin>>alg;
        if(alg==1){
            vizualizare_produse();
            cout<<endl;
        }
        else if(alg ==2){
            adaugare();
            cout<<endl;

        }
        else if(alg==3){
            stergere();
            cout<<endl;

        }
        else if(alg==4)
        {
            modificare();
            cout<<endl;

        }
        if(alg==5)
        {
            cout<<endl;
            cout<<"Intoarcere la meniul principal"<<endl;
            deschidere();
            alg=6;
        }
    }while(alg==1  || alg==2 || alg==3  || alg==4);
}
void meniu_user();
void modificare_parola(){
string id,parola,parola_noua,parola_noua2;
cout<<"Va rugam autentificati-va"<<endl;
cout<<"ID: ";
cin>>id;
cout<<"Parola ";
cin>>parola;
int ok=0;
for(auto it:m){
if(it.first==id && it.second==parola){
        ok=1;
cout<<"Introdu parola noua "<<endl;
cin>>parola_noua;
cout<<"Confirmare parola "<<endl;
cin>>parola_noua2;
if(parola_noua==parola_noua2){

//it.first=id;
m[id]=parola_noua2;
cout<<"Parola a fost modificata cu succes"<<endl;
}
else {
    cout<<"Confirmare imposibila. Mai incearca odata :";
    cin>>parola_noua2;
    if(parola_noua==parola_noua2)
        it.second=parola_noua;
    else {cout<<"Incercare esuata";
        meniu_user();
    }
}
}
if (ok==0) {
    cout<<"Autentificare imposibila"<<endl;
    meniu_user();
}
}
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
    int alegere;
    do{
    cout<<"Bun venit!"<<endl;
    cout<<"Alege una dintre optiunile de mai jos"<<endl;
    cout<<"1. Vizualizare produsele din stoc"<<endl<<"2. Stergere produs din cos"<<endl<<"3. Vizualizare numar de puncte de fidelitate"<<endl;
    cout<<"4. Modificare parola" <<endl<<"5. Iesire"<<endl;

        cin>>alegere;
        if(alegere==1){
            cout<<"Vizualizare produse"<<endl;
            vizualizare_produse_user();
        }
         if(alegere==2)
         cout<<"Stergere produse din cos"<<endl;
        if(alegere==3)
            cout<<"Vizualizare numar puncte de fidelitate"<<endl;
        if(alegere==4){
            cout<<"Modificare parola"<<endl;
            modificare_parola();
            //meniu_user();
            return;
    }
    if (alegere==5) {
        return;
    }
    }while (alegere==1 || alegere==2 || alegere==3 || alegere==4);
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
   f<<"Obiect"<<endl;
   for(auto it:Produsele)
    {
        f<<it.getNume()<<endl<<it.getPret()<<endl<<it.getNr()<<endl;
   }
   f<<"Manga"<<endl;
   for(auto it:List_Manga)
   {
       f<<it.getNume()<<endl<<it.getPret()<<endl<<it.getNr()<<endl<<it.get_volume()<<endl;
       for(auto itr:it.get_volum())
       {
           f<<itr.getNume()<<endl<<itr.getPret()<<endl<<itr.getNr()<<endl;
       }
   }
   f<<"Haine"<<endl;
   for(auto it:List_Haine)
   {
       f<<it.getNume()<<endl<<it.getPret()<<endl<<it.getNr()<<endl;
       f<<it.get_exemplare().size()<<endl;
       for(auto itr:it.get_exemplare())
       {
           f<<itr.first<<endl<<itr.second<<endl;
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
{
    citire_dictionar();
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
