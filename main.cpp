#include <iostream>
#include <vector>
#include <fstream>
#include <list>
using namespace std;

// Data structures
/**
 *  Stare represents the data structure used for a state.
 *  It contains an vector that stores a list of transitions.
 *  Say you have the state '1' that goes to '2' by the letter 'a'
 *  then you will have the vector for state '1' = [('a', 2)]
 *
 */
struct Stare {
    string eticheta;
    vector<pair<char, int>> listaTranzitii;
};
/**
 * ElementTabelMultimi represents the data structure used to store an element in the
 * table of lamba*letter*lambda closures.
 * It contains a pointer to the array representing the closure.
 */
struct ElementTabelMultimi {
    int *pointerVector;
};
/**
 * ElementTabelAFD represents the data structure used to store an element in the
 * table that will be used to create the AFD.
 */
struct ElementTabelAFD {
    char eticheta;
    int *multime;
};
/**
 * Generic struct for: AFN-lamda, AFN and AFD.
 */
struct Automat {
    int nrStari = 0;
    Stare *stari = NULL;
    int nrStariFinale = 0;
    int *stariFinale = NULL;
    char *litere = NULL;
    int nrLitere = 0;
};


// Functions
/**
 *
 * @param nrStari is an integer representing the number of states of the machine
 * @param stari is an array used to store all the states of the machine
 * @param nrStariFinale is an integer representing the number of final states
 * @param stariFinale is an array of ints used to store all final states of the machine
 * The purpose of the function is to read the machine states and transitions from "date.in"
 */
void citireAutomat(Automat &automat) {
    int indexStareInceput, indexStareSfarsit, nrTranzitii;
    char literaTranzitie;
    ifstream f("..//date2.in");

    f >> automat.nrStari >> nrTranzitii >> automat.nrStariFinale;
    automat.stariFinale = new int[automat.nrStariFinale + 1];
    for (int i = 0; i < automat.nrStariFinale; i++) f >> automat.stariFinale[i];

    f >> automat.nrLitere;
    automat.litere = new char[automat.nrLitere];
    for (int i = 0; i < automat.nrLitere; i++) f >> automat.litere[i];


    automat.stari = new Stare[automat.nrStari];

    // Add lambda '~' transition to the state itself
    for(int i = 0; i < automat.nrStari; i++) {
        automat.stari[i].listaTranzitii.emplace_back(make_pair('~', i));
    }

    for (int i = 0; i < nrTranzitii; i++) {
        f >> indexStareInceput >> literaTranzitie >> indexStareSfarsit;

        automat.stari[indexStareInceput].listaTranzitii.emplace_back(make_pair(literaTranzitie, indexStareSfarsit));
        automat.stari[indexStareInceput].eticheta = to_string(indexStareInceput);
    }
}

/**
 *
 * @param nrStari is an integer representing the number of states of the machine
 * @param stari is an array used to store all the states of the machine
 * @param nrStariFinale is an integer representing the number of final states
 * @param stariFinale is an array of ints used to store all final states of the machine
 * The purpose of the function is to print to the console the array of states and every
 * transition as they are stored in memory.
 */
void afisareAutomat(Automat automat) {
    for (int i = 0; i < automat.nrStari; i++) {
        cout << i << ":";
        for (int j = 0; j < automat.stari[i].listaTranzitii.size(); j++) {
            cout << "(" << automat.stari[i].listaTranzitii.at(j).first << ", " << automat.stari[i].listaTranzitii.at(j).second << ") ";
        }
        cout << endl;
    }
    cout << "Stari finale: ";
    for (int i = 0; i < automat.nrStariFinale; i++) {
        cout << automat.stariFinale[i] << ' ';
    }
}

/**
 *
 * @param a first array
 * @param b second array
 * @param rezultat result array
 * @param marime the size of the arrays
 * The purpose of the function is to make a reunion between to arrays
 */
void reuniuneMultimi(int *a, int *b, int *&rezultat, int marime) {
    for (int i = 0; i < marime; i++) {
        if (a[i] == 1 || b[i] == 1) {
            rezultat[i] = 1;
        }
    }
}

/**
 *
 * @param a first array
 * @param b second array
 * @param rezultat result array
 * @param marime the size of the arrays
 * The purpose of the function is to compare two arrays
 * If they are the same the result is 1 else -1.
 */
int comparareMultimi(int *a, int *b, int marime) {
    for (int i = 0; i < marime; i++) {
        if(a[i] != b[i])
            return -1;
    }
    return 1;
}

/**
 *
 * @param indexStare the index of the currentState
 * @param nrStari number of states
 * @param stari states array
 * @param inchidereLambda lambda closure int array
 * @return true if didnt reach a dead end
 * This function is used in "inchidereLambda" to find all the possible paths for lambda transitions.
 */
bool inchidereLambdaRecursie(int indexStare, int nrStari, Stare *stari, int *&inchidereLambda) {
    for (int i = 0; i < stari[indexStare].listaTranzitii.size(); i++) {
        if(stari[indexStare].listaTranzitii[i].first == '~' && stari[indexStare].listaTranzitii[i].second != indexStare) {
            inchidereLambda[stari[indexStare].listaTranzitii[i].second] = 1;
            if(inchidereLambdaRecursie(stari[indexStare].listaTranzitii[i].second, nrStari, stari, inchidereLambda)) {
                return true;
            }
        }
    }
}

/**
 *
 * @param indexStare the index of the currentState
 * @param nrStari number of states
 * @param stari states array
 * @param inchidereLambda lambda closure int array
 * Calculates the lambda closure for a given state.
 */
void inchidereLambda(int indexStare, int nrStari, Stare *stari, int *&inchidereLambda) {
    inchidereLambdaRecursie(indexStare, nrStari, stari, inchidereLambda);
    // The closure for the element itself is set to 1
    inchidereLambda[indexStare] = 1;
}

/**
 *
 * @param indexStare the index of the currentState
 * @param stari states array
 * @param inchidereLitera the closure for a given letter
 * @param litera the letter
 * Calculates the closure for a given letter.
 */
void inchidereLitera(int indexStare, Stare *stari, int *&inchidereLitera, char litera) {
    for(int i = 0; i < stari[indexStare].listaTranzitii.size(); i++) {
        if(stari[indexStare].listaTranzitii[i].first == litera) {
            inchidereLitera[stari[indexStare].listaTranzitii[i].second] = 1;
        }
    }
}

/**
 *
 * @param indexStare the index of the currentState
 * @param nrStari number of states
 * @param stari states array
 * @param litera the letter
 * @return the lamba*letter*lambda closure for a given letter
 */
int *inchidereLambdaLiteraLambda(int indexStare, int nrStari, Stare *stari, char litera) {

    int *inchidereLam = new int[nrStari]();
    int *inchidereLit = new int[nrStari]();
    int *inchidere = new int[nrStari]();

    inchidereLambda(indexStare, nrStari, stari, inchidereLam);

    for(int i = 0; i < nrStari; i++) {
        if(inchidereLam[i] == 1) {
            inchidereLitera(i, stari, inchidereLit, litera);
        }
    }

    for(int i = 0; i < nrStari; i++) {
        if(inchidereLit[i] == 1) {
            inchidereLambda(i, nrStari, stari, inchidere);
        }
    }

    return inchidere;

}

/**
 *
 * @param AFN the nondeterministic finite machine
 * @param AFD the deterministic finite machine
 */
void AfnLambdaInAfd(Automat AFN, Automat &AFD) {
    // The algorithm for this function will be in the wiki written in romanian

    // create the AFN table of states
    ElementTabelMultimi tabel[AFN.nrStari][AFN.nrLitere];
    for (int i = 0; i < AFN.nrStari; i++) {
        for (int j = 0; j < AFN.nrLitere; j++) {
            tabel[i][j].pointerVector = inchidereLambdaLiteraLambda(i, AFN.nrStari, AFN.stari, AFN.litere[j]);
        }
    }

    // For printing the AFN table if wanted (Debugging)
    /*for (int i = 0; i < nrStari; i++) {
        for (int j = 0; j < nrLitere; j++) {
            for (int k = 0; k < nrStari; k++) {
                if (tabel[i][j].pointerVector[k] == 1) cout << k;
            }
            cout << "/" << litere[j];
        }
        cout << endl;
    }*/

    // Create the AFD table
    ElementTabelAFD tabelAFD[AFN.nrStari][AFN.nrLitere + 1];
    ElementTabelAFD elementInitial;
    list<ElementTabelAFD> elementeNoi;
    int indexLinie = 0;
    AFD.stariFinale = new int[AFN.nrStari]();
    char et = '0';

    // The initial element will be of the form: ('A', <0>) then we will add it to the table
    // <0> = closure of state 0
    elementInitial.eticheta = et++;
    elementInitial.multime = new int[AFN.nrStari];
    inchidereLambda(0, AFN.nrStari, AFN.stari, elementInitial.multime);
    elementeNoi.push_back(elementInitial);

    // elementeNoi is a queue used to determine if we run out of new elements
    // that we need to add to the AFD table
    while(!elementeNoi.empty()) {
        // Adding an element to the table
        ElementTabelAFD elementNou = elementeNoi.front();
        tabelAFD[indexLinie][0] = elementNou;
        elementeNoi.pop_front();

        for(int i = 0; i < AFN.nrLitere; i++) {
            // Initialize a new element for the i letter in the table
            ElementTabelAFD elementPentruLitera;
            elementPentruLitera.multime = new int[AFN.nrStari]();

            // Calculate his closure using the AFN table
            for(int j = 0; j < AFN.nrStari; j++) {
                if(elementNou.multime[j] == 1) {
                    reuniuneMultimi(elementPentruLitera.multime, tabel[j][i].pointerVector, elementPentruLitera.multime, AFN.nrStari);
                }
            }

            // Verify if it has been already defined
            int existent = 0;
            for(int j = 0; j < indexLinie + 1; j++) {
                if(comparareMultimi(tabelAFD[j][0].multime, elementPentruLitera.multime, AFN.nrStari) == 1) {
                    // If so then we don't have to add it
                    elementPentruLitera.eticheta = tabelAFD[j][0].eticheta;
                    existent = 1;
                }
            }

            // Verify if it has been already added to the queue for new elements
            for(ElementTabelAFD x : elementeNoi) {
                if(comparareMultimi(x.multime, elementPentruLitera.multime, AFN.nrStari) == 1) {
                    // If so then we don't have to add it
                    elementPentruLitera.eticheta = x.eticheta;
                    existent = 1;
                }
            }

            if(existent == 0) {
                // It has to be added
                elementPentruLitera.eticheta = et++;
                elementeNoi.push_back(elementPentruLitera);
            }

            tabelAFD[indexLinie][i+1] = elementPentruLitera;

        }

        indexLinie++;

    }

    // Creating the AFD
    AFD.nrLitere = AFN.nrLitere;
    AFD.litere = AFN.litere;
    AFD.nrStari = indexLinie;
    AFD.stari = new Stare[AFD.nrStari];
    AFD.nrStariFinale = 0;

    int tempStariFinale[AFN.nrStari] = {0};

    // Set the states names
    for(int i = 0; i < AFD.nrStari; i++) {
        AFD.stari[i].eticheta = tabelAFD[i][0].eticheta;
    }

    // Set all the transitions
    for(int i = 0; i < AFD.nrStari; i++) {
        for(int j = 1; j <= AFD.nrLitere; j++) {
            AFD.stari[i].listaTranzitii.emplace_back(make_pair(AFD.litere[j-1], tabelAFD[i][j].eticheta - '0'));
        }
    }

    //For printing the AFD table (Debugging)
    /*
    for(int i = 0; i < indexLinie; i++) {
        for(int j = 0; j < AFN.nrLitere + 1; j++) {
            cout<<tabelAFD[i][j].eticheta<<"(";
            for(int x = 0; x < AFN.nrStari; x++) {
                if(tabelAFD[i][j].multime[x] == 1) {
                    cout<<x;
                }
            }
            cout<<")";
        }
        cout<<endl;
    }*/


    // Searching for the final states in all the stated of AFD
    for(int i = 0; i < indexLinie; i++) {
        for(int j  = 0; j < AFN.nrStari; j++) {
            int elementMultime;
            if(tabelAFD[i][0].multime[j] == 1) {
                elementMultime = j;
            }
            for(int k = 0; k < AFN.nrStariFinale; k++) {
                if(AFN.stariFinale[k] == elementMultime) {
                    tempStariFinale[i] = 1;
                }
            }
        }
    }

    // Setting the final states for AFD
    for(int i = 0; i < AFD.nrStari; i++) {
        if(tempStariFinale[i] == 1) {
            AFD.nrStariFinale++;
        }
    }
    int index = 0;
    for(int i = 0; i < AFD.nrStari; i++) {
        if(tempStariFinale[i] == 1) {
            AFD.stariFinale[index++] = i;
        }
    }

}

/**
 *
 * @param AFD the deterministic finite machine
 * @param indexStareActuala index of current state
 * @param cuvant the word to be verified
 * @param verbose if we want to also see the path for the machine we set it to true
 * @return true if the word is accepted, false otherwise
 */
bool AfdDelta(Automat AFD, int indexStareActuala, string cuvant, bool verbose) {

    /// if the word array is empty then verify if the current state is also a final one
    if (cuvant[0] == NULL) {
        int i;
        for (i = 0; i < AFD.nrStariFinale; i++) {
            if (indexStareActuala == AFD.stariFinale[i])
                return true;
        }
        if (i == AFD.nrStariFinale)
            return false;
    }

    /// loops through all the coonections of the current state
    for (int i = 0; i < AFD.stari[indexStareActuala].listaTranzitii.size(); i++) {
        /// if the current word's first letter is in any of the transitions then go to that state
        /// it also prints the path from one state to another
        if (cuvant[0] == AFD.stari[indexStareActuala].listaTranzitii[i].first) { ;
            cuvant.erase(cuvant.begin(), cuvant.begin() + 1);

            if(verbose)
                cout << indexStareActuala << " " << AFD.stari[indexStareActuala].listaTranzitii[i].second << endl;

            indexStareActuala = AFD.stari[indexStareActuala].listaTranzitii[i].second;
            return AfdDelta(AFD, indexStareActuala, cuvant, verbose);
        }
    }

    return false;
}

// Menu related
void AfisareAFN(Automat AFN, Automat AFD);
void AfisareAFD(Automat AFN, Automat AFD);
void TestareAFD(Automat AFN, Automat AFD);
void ClearScreen() {
    for(int i = 0; i < 50; i++) cout<<endl;
}

/**
 *
 * @param AFN the nondeterministic finite machine
 * @param AFD the deterministic finite machine
 * Function used to show the main menu.
 */
void MeniuPrincipal(Automat AFN, Automat AFD) {
    cout<<"Buna ziua si bine v-am gasit la lansarea celui mai nou convertor de AFN-lambda in AFD!\n";
    cout<<"Datele necesare pentru AFN vor fi introduse in fisierul 'date.in'.\n";
    cout<<"De forma 'nrStari' 'nrTranzitii' 'nrStariFinale'\n";
    cout<<"starile finale\n";
    cout<<"tranzitiile de forma: 'stareInceput' 'litera' 'stareFinala'\n";
    cout<<"\n 1.Afiseaza AFN-ul introdus.";
    cout<<"\n 2.Afiseaza AFD-ul rezultat din AFN.";
    cout<<"\n 3.Testeaza AFD-ul cu un cuvant.";

    int optiune;
    cin>>optiune;

    switch (optiune) {
        case 1:
            ClearScreen();
            AfisareAFN(AFN, AFD);
            break;
        case 2:
            ClearScreen();
            AfisareAFD(AFN, AFD);
            break;
        case 3:
            ClearScreen();
            TestareAFD(AFN, AFD);
            break;
    }
}

/**
 *
 * @param AFN the nondeterministic finite machine
 * @param AFD the deterministic finite machine
 * Function used to show the AFN.
 */
void AfisareAFN(Automat AFN, Automat AFD) {
    cout<<"Automatul AFN-lambda introdus este:\n";
    afisareAutomat(AFN);

    cout<<"\nApasa tasta x pentru a te intoarce la meniul principal.";

    char optiune;

    while(cin>>optiune) {
        if(optiune == 'x') {
            ClearScreen();
            MeniuPrincipal(AFN, AFD);
        }
    }
}

/**
 *
 * @param AFN the nondeterministic finite machine
 * @param AFD the deterministic finite machine
 * Function used to show the AFD.
 */
void AfisareAFD(Automat AFN, Automat AFD) {
    cout<<"Automatul AFD construit este:\n";
    afisareAutomat(AFD);

    cout<<"\nApasa tasta x pentru a te intoarce la meniul principal.";

    char optiune;

    while(cin>>optiune) {
        if(optiune == 'x') {
            ClearScreen();
            MeniuPrincipal(AFN, AFD);
            break;
        }
    }
}

/**
 *
 * @param AFN the nondeterministic finite machine
 * @param AFD the deterministic finite machine
 * Function used to test a word in AFD.
 */
void TestareAFD(Automat AFN, Automat AFD) {
    cout<<"Introdu cuvantul pe care vrei sa l testezi\n";

    string cuvant;
    cin>>cuvant;

    cout<<"\nVrei sa vezi traseul cuvantului pe stari?(Y/N)\n";
    char optiune;

    while(cin>>optiune) {
        if(optiune == 'Y' || optiune == 'y') {
            if(AfdDelta(AFD, 0, cuvant, true)) {
                cout<<"Cuvantul "<<cuvant<<" este acceptat!";
            } else cout<<"Cuvantul "<<cuvant<<" nu este acceptat!";
            break;
        } else if(optiune == 'N' || optiune == 'n') {
            if(AfdDelta(AFD, 0, cuvant, false)) {
                cout<<"Cuvantul "<<cuvant<<" este acceptat!";
            } else cout<<"Cuvantul "<<cuvant<<" nu este acceptat!";
            break;
        }
    }

    cout<<"\nApasa x pentru a te intoarce la meniul principal.\n";
    while(cin>>optiune) {
        if(optiune == 'x') {
            ClearScreen();
            MeniuPrincipal(AFN, AFD);
            break;
        }
    }
}

int main() {

    // Setting up
    Automat AFD, AFN;
    citireAutomat(AFN);
    AfnLambdaInAfd(AFN, AFD);

    // Start of program
    MeniuPrincipal(AFN, AFD);


    return 0;
}