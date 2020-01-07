#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

#define d 256 
int i, j;

char HTMLFile[100000000];
char XMLFile[100000000];
char TXTFile[100000000];
char RTFFile[100000000];

// Rabin-Karp Pattern Search Algoritmasi
void RabinKarpSearch(char pattern[], char txt[], int q)
{
	int M = strlen(pattern);
	int N = strlen(txt);
	int p = 0;
	int t = 0;
	int h = 1;

	

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < M; i++)
	{
		p = (d * p + pattern[i]) % q;
		t = (d * t + txt[i]) % q;
	}
	cout << pattern << " kelimesi araniyor..." << endl;

	for (i = 0; i <= N - M; i++)
	{
		if (p == t)
		{
			for (j = 0; j < M; j++)
			{
				if (txt[i + j] != pattern[j])
					break;
			}
			if (j == M) {
				cout << "Index: " << i << endl;
				ofstream myfile;
				myfile.open("yazdir.txt",ios::app);
				myfile << "Index: " << i << endl;
				myfile.close();
			}
		}

		if (i < N - M)
		{
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			if (t < 0)
				t = (t + q);

		}

		if (i == N - M && j != M) {
			cout << "Veri bulunamadi." << endl;
		}

	}
}

// HTML Fonksiyonu
void ReadFromHTML() {
	ifstream myfile("veri.html");
	if (myfile.is_open())
	{
		for (int i = 0; i < 1000000; ++i)
			myfile >> HTMLFile[i];

		myfile.close();
	}
}

// XML Fonksiyonu
void ReadFromXML() {
	fstream oku;
	oku.open("veri.xml");

	if (oku.is_open())
	{
		for (int i = 0; i < 1000000; ++i)
		{
			oku >> XMLFile[i];
		}
	}
}

// TXT Fonksiyonu
void ReadFromTXT() {

	fstream oku;
	oku.open("veri.txt");

	if (oku.is_open())
	{
		for (int i = 0; i < 1000000; ++i)
		{
			oku >> TXTFile[i];
		}
	}
}

// RTF (Rich Text File) Fonksiyonu
void ReadFromRTF() {
	//string line;
	ifstream myfile("veri.rtf");
	if (myfile.is_open())
	{
		for (int i = 0; i < 1000000; ++i)
			myfile >> RTFFile[i];

		myfile.close();
	}
	else {
		cout << "Dosya acilamadi!";
	}
}

int main()
{
	char aranacakKelime[256];
	int secim;

	int j = 101; // Algoritma icin gereken ozel bir sayi

	do {
		cout << "Kelime Aratin : ";
		cin.getline(aranacakKelime, 256);


		cout << "******************************************************************\nHTML dosyasi araniyor..." << endl;
		ReadFromHTML();
		RabinKarpSearch(aranacakKelime, HTMLFile, j);
		cout << "******************************************************************" << endl << endl;


		cout << "******************************************************************\nXML dosyasi araniyor..." << endl;
		ReadFromXML();
		RabinKarpSearch(aranacakKelime, XMLFile, j);
		cout << "******************************************************************" << endl << endl;


		cout << "******************************************************************\nTXT dosyasi araniyor..." << endl;
		ReadFromTXT();
		RabinKarpSearch(aranacakKelime, TXTFile, j);
		cout << "******************************************************************" << endl << endl;


		cout << "******************************************************************\nRTF dosyasi araniyor..." << endl;
		ReadFromRTF();
		RabinKarpSearch(aranacakKelime, RTFFile, j);
		cout << "******************************************************************" << endl << endl;


		cout << "******************************************************************\n1.Baska bir arama yap\n2.Cikis\n******************************************************************\n";
		cout << "Lutfen islem seciniz: ";
		cin >> secim;
		cin.getline(aranacakKelime,256); // DUMMY (Enter'a basınca enter olayını input olarak alıyor. Almaması için)

	} while (secim == 1);


	return 1;
}