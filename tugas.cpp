#include <iostream>
using namespace std;

class RekeningBank {
    protected :
        string noRekening;
        double saldo;
    public :
        RekeningBank(string no, double saldoAwal){
            noRekening = no;
            saldo = saldoAwal;
        }
        virtual void potongAdmin() = 0;


        void tampilkanInfo() {
            cout << "No Rekening: " << noRekening << endl;
            cout << "Saldo: Rp " << saldo << endl;
        }
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string no, double saldoAwal) : RekeningBank(no, saldoAwal) {}
    void potongAdmin() override {
        cout << "Rekening Syariah: Tidak ada potongan admin bulanan." << endl;
    }
};

class RekeningKonvensional :  public RekeningBank {
public:
    RekeningKonvensional(string no, double saldoAwal) : RekeningBank(no, saldoAwal) {}
    void potongAdmin() override {
        double admin = 15000;
        saldo -= admin;
        cout << "Rekening Konvensional: Dipotong biaya admin Rp" << admin << endl;
    }
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string no, double saldoAwal) 
        : RekeningBank(no, saldoAwal) {}

    void potongAdmin() {
        if (saldo > 10000000) {
            cout << "Premium: bebas admin" << endl;
        } else {
            saldo -= 50000;
            cout << "Premium: kena 50000" << endl;
        }
    }
};


int main() {
    RekeningBank* akun;

    RekeningSyariah tabunganKu1("SYR-001", 500000);
    RekeningKonvensional tabunganKu2("KON-001", 500000);
    RekeningPremium tabunganKu3("PRE-001", 8000000); //kena 50k
    RekeningPremium tabunganKu4("PRE-002", 15000000); //bebas


    akun = &tabunganKu1;
    akun->potongAdmin();
    akun->tampilkanInfo();

    cout << "---------------------------" << endl;
    
    
    akun = &tabunganKu2;
    akun->potongAdmin();
    akun->tampilkanInfo();

    cout << "---------------------------" << endl;
    
    
    akun = &tabunganKu3;
    akun->potongAdmin();
    akun->tampilkanInfo();

    cout << "---------------------------" << endl;
    
    
    akun = &tabunganKu4;
    akun->potongAdmin();
    akun->tampilkanInfo();

    cout << "---------------------------" << endl;

    return 0; 
}