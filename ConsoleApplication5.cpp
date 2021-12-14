#include <iostream>
#include <string>


using namespace std;

int main() {

	string tekst;
	int szyfr;
	bool powrot = false;

	cout << "podaj tekst do zaszyfrowania \n";
	getline(cin, tekst);

	cout << "wybierz algorytm szyfrujący.\n" << "1. szyfr podstawieniowy\n" << "2. szyfr pszedstawieniowy\n";
	cout << "3. szyfr podstawienowy i przedstawienowy\n" << "4. odszyfruj tekst\n";
	cin >> szyfr;
	int dl = tekst.length();

	switch (szyfr) {


	case 1:
		int przesuniecie;
		cout << "ile chesz przesunąć? \n";
		cin >> przesuniecie;
		for (int i = 0; i < dl; i++)
		{
			for (int j = 1; j < przesuniecie; j++) {
				if (tekst[i] == ' ') continue;
				else if (tekst[i] == 'z') {
					tekst[i] == 'a';
					przesuniecie--;
					powrot = true;
				}
				else if (tekst[i] == 'Z') {
					tekst[i] == 'A';
					przesuniecie--;
					powrot = true;
				}
				else {
					tekst[i]++;
				}
				if (powrot) {
					przesuniecie++;
					powrot = false;
				}
			}
		}
		cout << tekst;
		break;

	case 2:
		for (int i = 0; i < dl - 1; i += 2)
		{
			char znak;
			znak = tekst[i];
			tekst[i] = tekst[i + 1];
			tekst[i + 1] = znak;
		}
		cout << "Zaszyfrowany tekst kodem przestawieniowym: \n" << tekst << "/n";

		break;

	case 3:
		for (int i = 0; i < dl; i++) {
			for (int j = 1; j < przesuniecie; j++) {
				if (tekst[i] == ' ') continue;
				else if (tekst[i] == 'z') {
					tekst[i] == 'a';
					przesuniecie--;
					powrot = true;
				}
				else if (tekst[i] == 'Z') {
					tekst[i] == 'A';
					przesuniecie--;
					powrot = true;
				}
				else {
					tekst[i]++;
				}
				if (powrot) {
					przesuniecie++;
					powrot = false;
				}
			}
			for (int i = 0; i < dl - 1; i += 2)
			{
				char znak;
				znak = tekst[i];
				tekst[i] = tekst[i + 1];
				tekst[i + 1] = znak;
			}
		}
		cout << "Zaszyfrowany tekst kodem przestawieniowym: \n" << tekst << "\n";
		break;

	case 4:
		char znak;
		cout << "O ile przesunac: ";
		cin >> szyfr;
		if (szyfr <= 0 || szyfr > 26)
		{
			cout << "Niepoprawna liczba\n";
		}
		for (int j = 0; j < dl; j++) {
			znak = tekst[j];
			if (znak >= 'a' && znak <= 'z')
			{
				znak = ((znak - 'a' + (26 - szyfr)) % 26) + 'a';
			}
			tekst[j] = znak;
		}
		cout << "Odszyfrowany tekst kodem cezara\n" << tekst << "\n";
		break;
	deafult:
		cout << "niepoprawny wybór";
	}

}