/*
	Nama    : Hafidh Akhdan Najib
	NPM     : 140810180061
	Kelas   : A
*/

#include<iostream> 
#include<string.h>

using namespace std;

void enkripsi(){
    string plain;
    string cipherteks;
    int i, k;
    char c;
    
    cout << "Pesan atau plaintext : ";
    cin.ignore(); getline (cin, plain);
    cout << "Jumlah pergeseran (key) : "; cin >> k;
    cipherteks = " "; 
    
    for (i=0; i < plain.length(); i++) 
    {
        c = plain[i];
        if (isalpha(c)) 
        {
            c = toupper(c); 
            c = c - 65; 
            c = (c + k) % 26; 
            c = c + 65;
        }
        cipherteks = cipherteks + c; 
    }
    cout << "Cipherteks : " << cipherteks <<endl; 
}

void dekripsi(){
    string plainteks, cipherteks;
    int i, k;
    char c;
    
    cout << "Ketikan cipherteks : ";
    cin.ignore(); getline (cin, cipherteks);
    cout << "Masukan jumlah pergeseran : "; cin >> k;
    plainteks = "";  
    
    for (i=0; i<cipherteks.length(); i++)
    {
        c = cipherteks[i];
        if (isalpha(c)) 
        {
            c = toupper(c); 
            c = c - 65; 
            if (c - k < 0) 
                c = 26 + (c - k);
            else
                c = (c - k) % 26;
            c = c + 65; 
            c = tolower(c); 
        }
        plainteks = plainteks + c; 
    }
    cout << "Plainteks : " << plainteks <<endl; 
}

int main (){ 
    int pil;
    bool stop;
    stop = false;
    
    while (!stop) 
    {
        cout << "1. Enkripsi " <<endl;
        cout << "2. Dekripsi " <<endl;
        cout << "3. Exit " <<endl;
        cout << "Pilih (1/2/3) : "; cin >> pil;
        switch(pil){
            case 1 : 
			enkripsi();
			break;
            case 2 : 
			dekripsi();
			break;
            case 3 : 
			stop = true;
			break;
        }
    }
}
