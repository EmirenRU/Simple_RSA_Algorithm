/*
 * C++ Program for RSA asymmetric cryptographic algorithm.
 */

// Not Finished


#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;

class RSA{
    int p, q, mod, e = 2, phi, d;

    bool prime_num(long long int Number){
        if (Number <= 2 && Number >= 0){
            return true;
        }
        for (int i = 2; i < Number; i++){
            if (Number % i != 0){
                return false;
            }
        }
        return true;
    }

    int encrypt(){


        return 0;
    }

    int decrypt() {

        return 0;
    }




    static int GCD(int Num, int Mod){
        int tmp;

        while(true){

            tmp = Num % Mod;

            if (tmp == 0) return Mod;

            Num = Mod;

            Mod = tmp;

        }
        return 0;
    }





public:

    RSA(int P, int Q){
//        this->e = eNum;
//        this->degree = nDegree;
        this->p = P;
        this->q = Q;
        this->mod = (this->p * this->q);
        this->phi = ((this->p - 1) * (this->q - 1));

        int i, j;
        int count=0;

        int *arr = new int [phi];

        for (i = 2; i < phi; i++){
            if (this->prime_num(i)){
                if (phi % i == 0){

                    arr[count] = i;

                    count++;
                }
            }
        }

        for (i = phi - 1; phi > 0; phi--)
        {
            if (this->prime_num(i))
            {
                for (j = 0; j < phi; j++)
                {

                    if (this->e % arr[j] == 0 && arr[j] != 0) {
                        break;
                    }

                    this->e = i;
                    break;
                }
            }
        }

        for (i = 0; i < this->phi; i++)
        {

            if (((i * this->e) % this->phi) == 1)
            {
                this->d = i;
            }
        }
    }

    void private_key() {
        // Mod,
        int i;

        cout << "Private key = " << this->mod << " " << this->d << endl;
    }

    void open_key(){
        cout << "Open Key = " << this->e << " " << this->mod << endl;
    }

};


/* You need to choose how many bit of information you want to hold */
// P.S. It's Simple version of RSA.
// e < phi(p,q) == (p-1) * (q-1)


int main(){
    srand(static_cast<unsigned>(time(NULL)));
    int n, e, p, q;

    cout << "Enter prime number P and Q: ";
    cin >> p >> q;

    RSA key = RSA(e, n);
    key.open_key();
    cout << endl;
    key.private_key();

    // Was disabled due to limits of double

//    cout << "Due to double limit 2 ^ 1024 == 1.7e+308, then n = 1024 " << endl;
//    n = 1024;

//    cout << "Enter e: ";
//    cin >> e;
//
//
//    cout << "Enter degree of number e: ";
//    cin >> n;

//    cout << "Set a limit: \n1. 1024.\n2. 2048.\n3. 4096.\n Enter the number";
//    cin >> choice;
//
//    switch(choice)
//    {
//        case 1: n = 1024; break;
//        case 2: n = 2048; break;
//        case 3: n = 4096; break;
//        default: cout << "Something went wrong.\n Exiting..."; return 1;
//    }






    return 0;
}