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
string idi;
vector<Obiect>Produsele;
vector<Manga>List_Manga;
vector<Haine>List_Haine;
map<string,int>puncte;
map<string,int> Cos1;
map<string,float>Cos2;
map<string,string> Cos0;
map<string,int>Cos3;
vector<string>comenzi;
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
void citire_cos();
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
    if(id_user==it.first && password_user==it.second){

        idi=id_user;
        citire_cos();
        return 1;
    }

  return 0;
}
void citire_puncte()
{
    ifstream f("puncte_fid.txt");
    string nume;
    int pct;
    while(f>>nume)
    {
        f>>pct;
        puncte[nume]=pct;
    }

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
    system("cls");
    cout<<"Alege categoria de produse pe care doresti sa o vizualizezi :"<<endl;
    cout<<"1. Obiecte "<<endl<<"2. Manga "<<endl<<"3. Haine "<<endl<<"4. Nu mai vreau sa vizualizez"<<endl;
    cout<<"Algerea dvs este : " ;
    cin>>alegere;
    if(alegere==1){
        system("cls");
        for(auto it:Produsele){
            cout<<"Nume "<<it.getNume()<<"\n"<<"Pret "<<it.getPret()<<" $\n"<<"Cantitate in stoc "<< it.getNr()<<"\n\n";
        }
        system("pause");
    }
    else if(alegere==2){
        system("cls");
        for(auto it:List_Manga)
        {cout<<"Nume "<<it.getNume()<<"\n"<<"Pret "<<it.getPret()<<" $\n"<<"Cantitate in stoc "<< it.getNr()<<"\n\n";
            for(auto &itr:it.get_volum()){
                cout<<"Numele volumului "<<itr.getNume()<<"\nCantitatea din stoc "<<itr.get_stoc()<<"\nPret "<<itr.get_pret()<<endl;
            }//cout<<it;
        }
        system("pause");
    }
    else if(alegere==3)
    {
        system("cls");
        for(auto it:List_Haine)
        {
            cout<<"Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" $"<<" Cantitate in stoc "<< it.getNr()<<"\n";
            for(auto &itr:it.get_exemplare())
            {
                cout<<"Marimea : "<<itr.first<<"    "<<itr.second<<"\n";
            }
            cout<<"\n\n";
        }
        system("pause");
    }
  else if(alegere==4)
        system("pause");
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
    system("cls");
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
            cout<<"Numele volumului :"<<endl; cin.ignore(); getline(cin,nume_v);
            cout<<endl<<"Pretul volumului :"<<endl; cin>>pret_v;
            cout<<endl<<"Cantitatea stocului :"<<endl; cin>>cantitate_v;
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
        cout<<"Nume = "; getline(cin,nume);
        cout<<" Nr produse = "; cin>>cantitate;
        cout<<"Pret = "; cin>>pret;
        cout<<"Cate marimi avem ? "; cin>>marimi;
        for(int i=0;i<marimi;i++)
        {
            cout<<"Marime = "; cin>>mrm;
            cout<<"Nr. Exemplare = "; cin>>cant;
            exemplare.insert({mrm,cant});
        }
        Haine o(nume,pret,cantitate,exemplare);
        List_Haine.push_back(o);
    }
    cout<<"Produs adaugat! Apasa inca o data ca sa te intorci la meniu\n";
    system("pause");
}
void scriere_cont();
void stergere(){
    system("cls");
    cout<<"Ce fel de produs doresti sa stergi?"<<endl;
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
                cout<<"Produs sters! Apasa inca o data ca sa te intorci la meniu\n";
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
                cout<<"Produs sters! Apasa inca o data ca sa te intorci la meniu\n";
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
                cout<<"Produs sters! Apasa inca o data ca sa te intorci la meniu\n";
                break;

            }
            k++;
        }
        if(ok=0)
        {
            cout<<"Nu exista un asemenea de produs"<<endl;
        }
    }
    system("pause");
}
void modificare(){
    system("cls");
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
        system("cls");
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
                system("pause");
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
                system("pause");
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
            if(ok==0){
                cout<<"Nu exista produs cu acest nume. Incercati din nou"<<endl;
                system("pause");
                modificare();
            }
        if(alg==4){
        modificare();
        }

    }
    }
    if(alegere1==2){// Manga
        system("cls");
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
                    //cout<<"$$$$"<<vol<<endl;
                    for(auto &itrr:itr.get_volum())
                    {
                        if(itrr.getNume()==vol)
                        {
                            cout<<"Cu ce doriti sa modificati?"<<endl;
                            //cin.ignore();
                            getline(cin,vol2);
                            itrr.setNume(vol2);
                            //cout<<"****"<<vol2<<"  "<<vol<<endl;

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
    float pret;
    int k=1;
    int cant;
    if(alegere==1)
    {
            int cresc;
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
            cout<<endl<<"Va intereseaza vreun produs?"<<endl<<endl<<"Daca da,introduceti nr produsului"<<endl<<"Daca nu, apastai tasta 0"<<endl<<endl;
            cin>>choice;
            if(choice!=0){
            k=1;
            for(auto it:Produsele)
            {
                if(k==choice)
                {
                    cout<<"Vreti sa adaugati in cos? "<<endl;
                    cin>>x;
                    if(x==1)
                    {
                        cout<<endl<<"Cate bucati doriti sa cumparati?"<<endl;
                        cin>>cant;
                        nume=it.getNume();
                        if(Cos1.count(nume)>0)
                        {
                            Cos1[nume]=cant+Cos1[nume];
                        }
                        else{
                        Cos1[nume]=cant;
                        Cos2[nume]=it.getPret();
                        }


                    }
                }
                k++;
            }
            }
            if(choice==0)
            {
                return;
            }


        }

        if(cresc==2){
            sort(Produsele.begin(),Produsele.end(),cmp1);
            for(auto it:Produsele)
            {
                cout<<k<<". "<<"Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl;
                k++;
            }
            cout<<endl<<"Va intereseaza vreun produs?"<<endl<<endl<<"Daca da,introduceti nr produsului"<<endl<<"Daca nu, apastai tasta 0"<<endl<<endl;
            cin>>choice;
            if(choice!=0){
            k=1;
            for(auto it:Produsele)
            {
                if(k==choice)
                {
                    cout<<"Vreti sa adaugati in cos? "<<endl;
                    cin>>x;
                    if(x==1)
                    {
                        cout<<endl<<"Cate bucati doriti sa cumparati?"<<endl;
                        cin>>cant;
                        nume=it.getNume();
                        if(Cos1.count(nume)>0)
                        {
                            Cos1[nume]=cant+Cos1[nume];
                        }
                        else{
                        Cos1[nume]=cant;
                        Cos2[nume]=it.getPret();
                        }

                    }
                }
                k++;
            }
            }
            if(choice==0)
            {
                return;
            }


        }

         if(cresc==3){
            for(auto it:Produsele)
            {
                cout<<k<<". "<<"Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl;
                k++;
            }
            cout<<endl<<"Va intereseaza vreun produs?"<<endl<<endl<<"Daca da,introduceti nr produsului"<<endl<<"Daca nu, apastai tasta 0"<<endl<<endl;
            cin>>choice;
            if(choice!=0){
            k=1;
            for(auto it:Produsele)
            {
                if(k==choice)
                {
                    cout<<"Vreti sa adaugati in cos? "<<endl;
                    cin>>x;
                    if(x==1)
                    {
                        cout<<endl<<"Cate bucati doriti sa cumparati?"<<endl;
                        cin>>cant;

                        nume=it.getNume();
                        if(Cos1.count(nume)>0)
                        {
                            Cos1[nume]=cant+Cos1[nume];
                        }
                        else{
                        Cos1[nume]=cant;
                        Cos2[nume]=it.getPret();
                        }


                    }
                }
                k++;
            }
            }
            if(choice==0)
            {
                return;
            }

        }
    }
    else if(alegere==2){
        int alg;
    cout<<"Daca doriti o vizualizare alfabetica a articolelor manga apasati tasta 1"<<endl<<endl;
    cout<<"Daca nu aveti o preferinta in ceea ce priveste vizualizarea acestora apasati tasta 2"<<endl<<endl;
    cin>>alg;
    int k=1,k2;
    if(alg==1){
    sort(List_Manga.begin(),List_Manga.end(),cmp2);
        for(auto it:List_Manga)
            {
                cout<<k<<" . Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl;
                k2=1;
                for(auto &itr:it.get_volum()){
                cout<<k2<<". "<<"Numele volumului "<<itr.getNume()<<"Cantitatea din stoc"<<itr.get_stoc()<<" Pret "<<itr.get_pret()<<endl;
                k2++;
                }
                k++;
           }//cout<<it;

        cout<<endl<<"Va intereseaza vreun produs?"<<endl<<endl<<"Daca da,introduceti nr produsului"<<endl<<"Daca nu, apastai tasta 0"<<endl<<endl;
        cin>>choice;
        if(choice!=0){
        k=1;
        int adda;
        for(auto it:List_Manga)
        {
            if(k==choice)
            {
                cout<<"Daca doriti sa adaugati un volum introduceti numarul voumului"<<endl;
                cout<<"Daca doriti nu mai doriti sa adaugati introdueti 0"<<endl<<endl;
                cin>>x;
                k2=1;
                for(auto &itr:it.get_volum())
                {
                    if(k2==x)
                    {
                        cout<<"Cate doriti sa adaugati?"<<endl;
                        cin>>adda;
                        if(Cos1.count(itr.getNume())>0)
                        {

                            Cos1[itr.getNume()]=adda+Cos1[itr.getNume()];
                        }
                        else{
                               // cout<<itr.getNume()<<"%%%\n";
                            Cos1[itr.getNume()]=adda;
                            Cos2[itr.getNume()]=itr.getPret();
                            Cos0[itr.getNume()]=it.getNume();
                        }

                        cout<<endl<<"S-a adaugat cu succes"<<endl;

                    }
                    k2++;
                }
            }
            k++;
        }
        }
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
        cout<<endl<<"Va intereseaza vreun produs?"<<endl<<endl<<"Daca da,introduceti nr produsului"<<endl<<"Daca nu, apastai tasta 0"<<endl<<endl;
        cin>>choice;
        if(choice!=0){
        k=1;
        int adda;
        for(auto it:List_Manga)
        {
            if(k==choice)
            {
                cout<<"Daca doriti sa adaugati un volum introduceti numarul voumului"<<endl;
                cout<<"Daca doriti nu mai doriti sa adaugati introdueti 0"<<endl<<endl;
                cin>>x;
                k2=1;
                for(auto &itr:it.get_volum())
                {
                    if(k2==x)
                    {
                        cout<<"Cate doriti sa adaugati?"<<endl;
                        cin>>adda;
                       if(Cos1.count(itr.getNume())>0)
                        {
                            Cos1[itr.getNume()]=adda+Cos1[itr.getNume()];
                        }
                        else{
                            Cos1[itr.getNume()]=adda;
                            Cos2[itr.getNume()]=itr.getPret();
                            Cos0[itr.getNume()]=it.getNume();
                        }
                        cout<<endl<<"S-a adaugat cu succes"<<endl;

                    }
                    k2++;
                }
            }
            k++;
        }
        }
        }
    }
    else if(alegere==3)
    {int a;
        int k=1;
        int k2;
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
            k2=1;
            for(auto &itr:it.get_exemplare())
            {
                cout<<k2<<". "<<"Marimea : "<<itr.first<<"    "<<itr.second<<endl;
                k2++;
            }
            k++;

        }
        cout<<endl<<"Va intereseaza vreun produs?"<<endl<<endl<<"Daca da,introduceti nr produsului"<<endl<<"Daca nu, apastai tasta 0"<<endl<<endl;
        cin>>choice;
        k=1;

        int cantiteisan;
        for(auto it:List_Haine)
        {
            if(k==choice)
            {
                cout<<"Daca doriti sa adaugati in cos, introduceti indicele marimii"<<endl;
                cout<<"Daca nu apasati tasta 0";
                cin>>x;
                k2=1;
                for(auto &itr:it.get_exemplare())
                {
                    if(k2==x){
                            cout<<"Cate bucati doriti sa adaugati?"<<endl;
                            cin>>cantiteisan;
                            if(Cos1.count(it.getNume())>0)
                        {
                            Cos1[it.getNume()]=cantiteisan+Cos1[it.getNume()];
                        }
                        else{
                            Cos1[it.getNume()]=cantiteisan;
                            Cos2[it.getNume()]=it.getPret();
                            Cos3[it.getNume()]=itr.first;
                        }

                    }
                    k2++;
                }
            }
            k++;
        }
        if(a==3){
            for(auto it:List_Haine)
        {
            cout<<k<<" . Nume "<<it.getNume()<<" "<<"Pret "<<it.getPret()<<" Cantitate in stoc "<< it.getNr()<<endl;
            for(auto &itr:it.get_exemplare())
            {
                cout<<"Marimea : "<<itr.first<<"    "<<itr.second<<endl;
            }
            k++;

        }
        cout<<endl<<"Va intereseaza vreun produs?"<<endl<<endl<<"Daca da,introduceti nr produsului"<<endl<<"Daca nu, apastai tasta 0"<<endl<<endl;
        cin>>choice;
        k=1;
        int k2;
        int cantiteisan;
        for(auto it:List_Haine)
        {
            if(k==choice)
            {
                cout<<"Daca doriti sa adaugati in cos, introduceti indicele marimii"<<endl;
                cout<<"Daca nu apasati tasta 0";
                cin>>x;
                k2=1;
                for(auto &itr:it.get_exemplare())
                {
                    if(k2==x){
                            cout<<"Cate bucati doriti sa adaugati?"<<endl;
                            cin>>cantiteisan;
                        if(Cos1.count(it.getNume())>0)
                        {
                            Cos1[it.getNume()]=cantiteisan+Cos1[it.getNume()];
                        }
                        else{
                            Cos1[it.getNume()]=cantiteisan;
                            Cos2[it.getNume()]=it.getPret();
                            Cos3[it.getNume()]=itr.first;
                        }
                    }
                    k2++;
                }
            }
            k++;
        }
    }}
  else if(alegere==4)
        meniu_user();
   }
void admin_comenzi()
{
    system("cls");
    //cout<<"mere";
    int i,nr;
    //in>>i;

    cout<<"Acestea sunt toate comenzile:"<<endl<<endl;
    ifstream f("comenzi.txt");
    string x,z;
    if(comenzi.size()==0){
    while(f>>x)
    {
        comenzi.push_back("Comanda");
        f>>z;
        cout<<"-----------------------------------------\n"<<endl<<"Comanda "<<z<<endl<<endl;
       // comenzi.push_back(x);
        comenzi.push_back(z);
        cout<<"Informatii"<<endl;
        f.ignore();
        for(i=0;i<8;i++)
        {
           // f.ignore();
            getline(f,x);
            comenzi.push_back(x);
            cout<<x<<endl;

        }
        f>>nr;
        cout<<"^^"<<nr<<endl<<endl;
         f.ignore();
        for(i=0;i<nr;i++)
        {

            getline(f,x);
            comenzi.push_back(x);
            cout<<x<<endl;
        }

    }

    cout<<"-----------------------------------------\n"<<endl;
    }
    else
    {
        for(auto &it:comenzi)
        {
            cout<<it<<endl;
        }

    }
    cout<<endl;
    cout<<"Doriti sa stergeti o comanda?"<<endl;
    cout<<endl<<"Daca da, apasa 1"<<endl;
    cout<<"Daca nu,apasa 0"<<endl;
    cin>>i;
    string y;
   // auto it1;
   int k;
    if(i==1)
    {
        cout<<"Introduceti nr comenzii"<<endl;
        cin>>y;
        k=0;
        for(auto &itr:comenzi)
        {
           // cout<<"itr  "<<itr<<endl;
            if(itr=="Comanda")
            {
                k++;
                //advance(itr, 1);
               // cout<<itr<<"*"<<y<<endl;
                // cout<<comenzi[k]<<endl;
                if(comenzi[k]==y)
                {
                   //cout<<comenzi[k]<<endl;
                    while(comenzi[k]!="Comanda"&& k<comenzi.size())
                    {
                       // it1=itr+1;
                       comenzi.erase(comenzi.begin()+k,comenzi.begin()+k+1);
                    }
                    comenzi.erase(comenzi.begin()+k,comenzi.begin()+k+1);
                }
            }
            else{k++;}
        }
    }
    for(auto &it:comenzi)
    {
        cout<<it<<endl;
    }

    system("pause");
}


void meniu_admin(){
    int alg;
    do{
        system("cls");
        cout<<"Alege una dintre optiunile de mai jos : "<<endl;
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
            system("pause");
            deschidere();
            alg=6;
        }
    }while(alg==1  || alg==2 || alg==3  || alg==4);
}
void meniu_user();
void modificare_parola(){
string id,parola,parola_noua,parola_noua2;
cout<<"Va rugam autentificati-va"<<endl; cin.ignore();
cout<<"ID: ";
cin>>id; cin.ignore();
cout<<"Parola ";
cin>>parola; cin.ignore();
int key = 0;
for(auto it:m){
    if(it.first==id && it.second==parola){
        key++;
        cout<<"Introdu parola noua "<<endl;
        cin>>parola_noua;
        cout<<"Confirmare parola "<<endl;
        cin>>parola_noua2;
        if(parola_noua==parola_noua2){
            //it.first=id;
            m[id]=parola_noua2;
            cout<<"Parola a fost modificata cu succes"<<endl;
        }
        else{
            cout<<"Confirmare imposibila. Mai incearca odata :";
            cin>>parola_noua2;
            if(parola_noua==parola_noua2)
            it.second=parola_noua;
            else{
                cout<<"Incercare esuata";
                system("pause");
                meniu_user();
            }
        }
    }
}
    if(key == 0){
        cout<<"Autentificare imposibila"<<endl;
        system("pause");
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
    while(parola.size()<8){
        cout<<"Alege o parola mai lunga"<<endl;
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
void citire_cos()
{
    ifstream f("cosuri.txt");
    ofstream g("cosuri_help.txt");
    string id;
    int nr_prod,cant;
    string tip,nume;
    float pret;
    string manga;
    int marime,nr,i;
    //f.ignore();
    while(getline(f,id))
    {
       // f.ignore();
        cout<<endl<<endl<<id<<endl<<endl;
        if(id!=idi)
        {
            g<<id<<endl;
          cout<<id<<"*"<<idi<<"$"<<endl;
            f>>nr;
            g<<nr<<endl;
            for(i=0;i<nr;i++)
            {

                f.ignore();
                getline(f,tip);
               // cout<<"@@"<<tip<<endl;
                if(tip=="Obiect")
                {
                  //  f.ignore();
                    getline(f,nume);
                    f>>cant;
                    f>>pret;
                    cout<<tip<<endl<<nume<<endl<<cant<<endl<<pret<<endl;
                    g<<tip<<endl<<nume<<endl<<cant<<endl<<pret<<endl;

                }
                else if(tip=="Manga")
                {
                    //f.ignore();
                    getline(f,nume);
                    getline(f,manga);
                        f>>pret;
                        f>>cant;
                    g<<tip<<endl<<manga<<endl<<nume<<endl<<cant<<endl<<pret<<endl;
                }
                else if(tip=="Haine")
                {
                   // f.ignore();
                    getline(f,nume);
                    f>>marime;
                    f>>pret;
                    f>>cant;
                    g<<tip<<endl<<nume<<endl<<marime<<endl<<cant<<endl<<pret<<endl;
                }
            }
        }
        else
        {
            f>>nr;
            cout<<"**"<<id<<endl<<nr<<endl;
            for(i=0;i<nr;i++)
            {

               f.ignore();
                getline(f,tip);
                if(tip=="Obiect")
                {
                    //f.ignore();
                    getline(f,nume);
                    f>>cant;
                    f>>pret;

                    //g<<tip<<endl<<nume<<endl<<pret<<endl<<cant<<endl;
                   // cout<<tip<<endl<<nume<<endl<<pret<<endl<<cant<<endl;
                    Cos1[nume]=cant;
                    Cos2[nume]=pret;


                }
                else if(tip=="Manga")
                {
                   // f.ignore();
                    getline(f,nume);
                    getline(f,manga);
                        f>>pret;
                        f>>cant;
                    cout<<tip<<endl<<manga<<endl<<nume<<endl<<pret<<endl<<cant<<endl;
                    Cos1[nume]=cant;
                    Cos2[nume]=pret;
                    Cos0[nume]=manga;
                }
                else if(tip=="Haine")
                {
                   // f.ignore();
                    getline(f,nume);
                    f>>marime;
                    f>>pret;
                    f>>cant;
                  //  g<<tip<<endl<<nume<<endl<<marime<<endl<<pret<<endl<<cant<<endl;
                    Cos1[nume]=cant;
                    Cos2[nume]=pret;
                    Cos3[nume]=marime;
                }
            }

        }
        f.ignore();
    }
   //f.close();
}
void print_fisier()
{
    ofstream f("cosuri.txt");
    string x;
    f<<idi<<endl<<Cos1.size()<<endl;
    for(auto &it:Cos1)
    {

        if(Cos0.count(it.first)>0)
        {
            f<<"Manga"<<endl;
            f<<it.first<<endl;
            f<<Cos0[it.first]<<endl;
        }
        else if(Cos3.count(it.first)>0)
        {
            f<<"Haine"<<endl;

            f<<it.first<<endl;
            f<<Cos3[it.first]<<endl;
        }
        else
        {
            f<<"Obiect"<<endl;
            f<<it.first<<endl;


        }
        f<<it.second<<endl<<Cos2[it.first]<<endl;
    }
    ifstream g("cosuri_help.txt");
    while(getline(g,x))
    {
        f<<x<<endl;
    }
}
void vizualizare_cos()
{
    system("cls");
    float pret_fin=0;
    if(Cos1.empty()==1){
    cout<<endl<<endl<<"Cosul dvs.de cumparaturi este gol"<<endl;
    }
    else
    {
        cout<<endl<<endl<<"Cosul dvs de cumparaturi:"<<endl;
        for(auto &it:Cos1)
        {
            if(Cos3.count(it.first)>0)
            {
                cout<<it.first<<"    Marimea : "<<Cos3[it.first]<<"      "<<it.second<<" bucati      "<<it.second<<" x "<<Cos2[it.first]<<"$"<<endl;
            }
            else if(Cos0.count(it.first)>0)
            {
                cout<<Cos0[it.first]<<" -- "<<it.first<<"    "<<it.second<<" bucati      "<<it.second<<" x "<<Cos2[it.first]<<"$"<<endl;
            }
            else
            cout<<it.first<<"    "<<it.second<<" bucati      "<<it.second<<" x "<<Cos2[it.first]<<"$"<<endl;
            pret_fin=pret_fin+it.second*Cos2[it.first];
        }
    }
    cout<<endl<<"----------------------------------------------------"<<endl<<"Pretul final este                     "<<pret_fin<<"$ "<<endl;
    cout<<endl;
    cout<<"Doriti sa plasati comanda? Daca da, apasati 1"<<endl;
    cout<<"Doriti sa modificati cosul de cumparaturi? Daca da apasati 2"<<endl;
    int modificare,modfy;
    cin>>modificare;
    string sterg;
    int cont=0;
    int cantiteisan;
    if(modificare==2)
    {
        do{
        cout<<endl<<"Cum doriti sa modificati?"<<endl;
        cout<<"1.Doresc sa sterg din cos"<<endl<<"2.Doresc sa modific cantitatea unui produs"<<endl<<"3.Nu mai doresc sa modific"<<endl<<endl;
        cout<<"Alegere = ";cin>>modfy;
        if(modfy==1)
        {

            cout<<"Care este numele produsului pe care doriti sa-l stergeti?"<<endl;
            cin.ignore();
            getline(cin,sterg);
            for(auto &it:Cos1)
            {
                if(it.first==sterg)
                {
                    Cos1.erase(sterg);
                    Cos2.erase(sterg);
                    cont++;
                    cout<<endl<<"S-a sters cu succes"<<endl;
                }

            }
            if(cont==0)
            {
                cout<<"Nu exista produsul in cos"<<endl;
            }

        }
        else if(modfy==2)
        {
            cout<<"Care este numele produsului pe care doriti sa-l modificati?"<<endl;
            cin.ignore();
            getline(cin,sterg);
            cout<<"Cu ce cantitate doriti sa inlocuiti?";
            cin>>cantiteisan;
            Cos1[sterg]=cantiteisan;

        }
        else
        {

        }

        }while(modfy==1 || modfy==2);
    }
    else if(modificare==1)
    {
    cout<<"Introduceti datele personale:"<<endl<<endl;
    string nume,prenume,judet,localitate,strada,bloc,scara;
    int nr,apartament;
    cout<<"Nume : ";cin>>nume;
    cout<<endl<<"Prenume : ";cin>>prenume;
    cout<<endl<<"Judet : ";cin>>judet;
    cout<<endl<<"Localitate : ";cin>>localitate;
    cout<<endl<<"Strada : ";cin.ignore();getline(cin,strada);
    cout<<endl<<"Bloc : ";cin>>bloc;
    //cout<<endl<<"Nr : ";cin>>;
    cout<<endl<<"Scara : ";cin>>scara;
    cout<<endl<<"Apartament : ";cin>>apartament;
    cout<<endl<<endl<<endl<<"-------------------------------------------"<<endl;
    cout<<"            Finalizare Comanda:             "<<endl<<endl;
    cout<<"Nume : "<<nume<<"       "<<"Prenume : "<<prenume<<endl;
    cout<<"Judet : "<<judet<<"       Localitate"<<localitate<<"       Strada : "<<strada<<endl;
    cout<<"Bloc : "<<bloc<<"         Scara : "<<scara<<"     Apartament: "<<apartament<<endl<<endl;
    cout<<"               Sumar comanda:        "<<endl;
  //  cout<<endl;
    //  cout<<endl<<endl<<"Cosul dvs de cumparaturi:"<<endl;

      pret_fin=0;
        for(auto &it:Cos1)
        {
            if(Cos3.count(it.first)>0)
            {
                cout<<it.first<<"    Marimea : "<<Cos3[it.first]<<"      "<<it.second<<" bucati      "<<it.second<<" x "<<Cos2[it.first]<<"$"<<endl;
            }
            else if(Cos0.count(it.first)>0)
            {
                cout<<Cos0[it.first]<<" -- "<<it.first<<"    "<<it.second<<" bucati      "<<it.second<<" x "<<Cos2[it.first]<<"$"<<endl;
            }
            else
            cout<<it.first<<"    "<<it.second<<" bucati      "<<it.second<<" x "<<Cos2[it.first]<<"$"<<endl;
            pret_fin=pret_fin+it.second*Cos2[it.first];
        }
    cout<<endl<<"-------------------------------------------"<<endl<<"Pretul final este                     "<<pret_fin<<"$ "<<endl;
    cout<<endl;
    int aleale;
    cout<<"Trimiteti comanda?"<<endl;
    cout<<"1.Da"<<endl;
    cout<<"2.Nu"<<endl;
    cin>>aleale;
    if(aleale==2)
    {
        system("pause");
    }
    else if(aleale==1)
    {
        ofstream f("comenzi.txt");
        f<<rand()%1000<<endl;
        f<<nume<<endl<<prenume<<endl<<judet<<endl<<localitate<<endl<<strada<<endl<<bloc<<endl<<scara<<endl<<pret_fin<<endl;
        Cos0.clear();
        Cos1.clear();
        Cos2.clear();
        Cos3.clear();
    }

}
    else system("pause");
}
void meniu_user(){
    int alegere;
    do{
        system("cls");
    cout<<"Bun venit!"<<endl;
    cout<<"Alege una dintre optiunile de mai jos"<<endl;
    cout<<"1. Vizualizare produsele din stoc"<<endl<<"2. Vizualizare cos"<<endl;
    cout<<"3. Modificare parola" <<endl<<"4. Iesire"<<endl;

        cin>>alegere;
        if(alegere==1){
            system("cls");
            cout<<"Vizualizare produse"<<endl;
            vizualizare_produse_user();
        }
         if(alegere==2){
             system("cls");
             vizualizare_cos();
         }

        //if(alegere==3){
          //  system("cls");
          //  cout<<"Vizualizare numar puncte de fidelitate"<<endl;
        //}

        if(alegere==3){
            system("cls");
            cout<<"Modificare parola"<<endl;
            modificare_parola();
    }
    if (alegere==4) {
        system("cls");
        deschidere();
    }
    }while (alegere==1 || alegere==2 || alegere==3 );
}
void deschidere(){
    int alegere;
    system("cls");
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
                system("pause");
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
            system("pause");
            deschidere();
            }

        }
    }
    else if(alegere==3){
      creare_cont();
        cout<<"Contul a fost creat cu succes\n";
        system("pause");
    }
    else if(alegere == 4)
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
void print_comenzi()
{
    ofstream f("comenzi.txt");
    for(auto &itr:comenzi)
    {
        f<<itr<<endl;
    }
}
int main()
{
    citire_dictionar();
    citire_obiecte();
    //citire_cos();
    start();
    umplere_fisier();
    scriere_cont();
    print_fisier();

    //for(auto it:m)
     //   cout<<it.first<<" "<<it.second;
//vector<Obiect>A;
//Obiect a("sdss",15.4,9);
//Obiect b("sdss",15.4,9);
//A.push_back(a);
//A.push_back(b);


    cout<<"#";
    return 0;
}/*Iasmina
1
Obiect
Pix
12
4.5
Roxana
1
Obiect
Pix
12
4.6*/
