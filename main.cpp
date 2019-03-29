#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("afn.in");
ofstream cout("afn.out");

struct nod {

    int stare;
    int cheie;
    nod *next;

};


int AFN(char cuvant[1000], nod *tranzitii[1000], int curr, int final[1000]) {


    int valid = 0;//dc cuvant a fost gasit ca fiind deja valid se va schimba in 1

    if (cuvant[0] == NULL && final[curr] == 1)//verific daca am terminat de parcurs cuvantul intr-o stare finala
        return 1;


    else if (cuvant[0] == NULL)  //verific daca am terminat de parcurs cuvantul intr-o stare nefinala
        return 0;


    for (nod *k = tranzitii[curr]; k!=NULL ; k = k->next) //caut toate drumurile posibile care ies din starea actuala si vad daca am vreunul valid


        if (cuvant[0] == k->cheie){  //daca avem un drum valid

            valid = AFN(cuvant + 1, tranzitii, k->stare,final);//valid devine 1 daca am gasit o acceptare sau 0 daca nu am gasit o acceptare a cuvantului
            if (valid)
                return 1;//daca unul dintre "drumuri" accepta cuvantul atunci returnez 1
        }

    //daca nu am gasit niciun drum bun dupa ce am incercat toate posibilitatile atunci cuvantul nu este acceptat
    return 0;
}


void SOLVE() {



    char cuvant[1000], c;  //declar cuvantul si un caracter de care ma voi ajuta pentru a verifica validitatea
    int initial, final[1000] = {0}, n, x, y;  /*declar starea initila, vectorul de stari finale pe care il initializez
                                                cu 0, numarul starilor finale
                                              */
    nod *tranzitii[1000], *k;

    cin.getline(cuvant, 1000);  //citesc cuvantul

    cin >> initial;  //citesc starea initiala
    cin >> n;  //citesc numarul de stari finale


    int i = 0;
    while (i < n) {  //citesc starile finale

        cin >> x;
        final[x] = 1;
        i++;

    }

    for (int i = 0; i < 1000; ++i) { //initializez fiecare nod din vectprul tranzitii cu NULL

        tranzitii[i] = NULL;
    }

    while (cin >> x >> y >> c) {  //cat timp gasesc tranzitii in fisier

        k = new nod;  //creez un nou nod, respectiv o noua tranzitie
        k->cheie = c;  //ii asociez litera corespunzatoare
        k->stare = y;  //ii asociez starea in care merge
        k->next = NULL;

        if (tranzitii[x] != NULL)//daca am o lista npua pt starea x
            tranzitii[x] = k;  //ii asociez nodul, tranzitia creata

        else
            k->next = tranzitii[x], tranzitii[x] = k;  //adaug la inceputul listei, apoi pun k ca inceputul listei


    }

    if (AFN(cuvant, tranzitii, initial, final)!=0)
        cout << "Cuvantul este valid!";
    else
        cout << "Cuvantul este invalid!";

}

int main() {
    SOLVE();
    return 0;
}
