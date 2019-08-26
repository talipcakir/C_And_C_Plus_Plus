#include <iostream> 	// standart giri� giri�/��k�� i�in
#include <fstream> 		// dosyalama
#include <string> 		// string tan�m�
#include <clocale> 		// T�rk�e deste�i

using namespace std;

int main()
{
	setlocale(LC_ALL, "turkish"); 	//T�rk�e karakter ekliyoruz
	int secim;						//menu i�in se�im i�in istem de�i�keni
	long long int h_tc;				//hastan�n TC nosu
	string h_ad; 					//hastan�n Ad�
	string h_soy; 					//hastan�n Soyad�
	string h_tarih; 				//hastan�n giri� tarihi
	
	while(1)			//while(1) D�ng�s� ile s�rekli ana men�y� d�nd�rmek i�in
	{					//Anamen� ba�lang�c�
		cout << "******* Hastane Otomasyonu *******" << endl;		
		cout << "\t1 - Hasta Arama" << endl;
		cout << "\t2 - Hasta Kayd�" << endl;
		cout << "\t3 - Hasta Listesi" << endl; 
		cout << "\t0 - ��k��" << endl;
		cout << "��lem Se�iniz: ";
		cin>>secim;
		switch (secim)	//switch - case yap�s� ile ana menuden alt men�lere ge�i� yap�yoruz.
		{
		case 1:
		{
			system("cls");
			cout << "----------------HASTA ARAMA MENUSU----------------" <<endl;
			ifstream dosyaara;	//dosya tan�mlama
			int sira;			// dosya s�ras� tutmak i�in
			string dosyaici;	// dosyada ki yaz�lar� tutmak i�in
			char arama[10]; 	// aranacak de�i�ken 10 karakter
			int kacbulundu = 0; // bulunan veri say�s�n� tutmek i�in
			dosyaara.open("HastaneVeri.txt",ios::in); //dosyay� sadece okuma modunda a��yoruz.
			if(dosyaara == NULL) //dosya yoksa olu�turulmam��sa sadece okuma modunda a�t���m�z i�in hata verir.
			{
				cout <<" Hastane dosyas� a��lamad�...";
				exit(1);	//uygulamadan ��k�� yapt�rmak i�in
			}
			cout << endl << "Aramak istedi�iniz hastay� yaz�n�z:  ";//arama istemi
			cin >> arama;
			cout << "TC No \t\tAd�\tSoyad�\tGiri� Tarihi" << endl<<endl;
			    while(!dosyaara.eof()) //dosyaara sonuna kadar while d�ng�s� d�necek
				{
			        getline(dosyaara, dosyaici);	//getline ile dosyaara da ki line i dosyaicine al�yoruz.
			        if ((dosyaici.find(arama, 0)) != string::npos)	//dosyaici de�i�kenine .find parametresi ile arama yapt�r�yoruz.
					{
			            cout << dosyaici << endl;	//aranan de�ikenin bulundu�u line'lar� yazd�r�yoruz.
			            kacbulundu++;			//kac adet aranan de�i�ken bulundu tutuyoruz.
			        }
			    }
			    if(kacbulundu > 0)	//aranan de�i�ken bulunmu� ise
			    cout << endl << kacbulundu << " hasta bulundu." << endl;
			    else	//aranan de�i�ken hi� bulunamad�ysa
			    cout << endl << "Hasta bulunamad�." << endl;
			dosyaara.close();
			break;			
		}
		case 2:			//Hasta kay�t menusu
		{
			system("cls");
			cout << "----------------HASTA KAYIT MENUSU----------------" <<endl;
			ofstream dosya("HastaneVeri.txt",ios::app); //dosya y� tam yetki ile a��yoruz.
				cout << "Hasta Bilgilerini Giriniz" << endl;
				tcalan:	//tc hatal� girilirse buraya gelecek
				cout << endl;
				cout << "TC no: ";
				cin >> h_tc;
				if(h_tc > 10000000000 && h_tc < 99999999999); //tc no 11 karakter olmas�n�n denetimi
				else { cout << "Hatal� TC no giri�i yaz�ld�. Tekrar giriniz."; goto tcalan;}
				cout << "Ad�: ";
				cin >> h_ad;
				cout << "Soyad�: ";
				cin >> h_soy;
				cout << "Hasta giri� tarihi: ";
				cin >> h_tarih;
				dosya << h_tc << "\t" << h_ad << "\t" << h_soy  << "\t" << h_tarih << "\t" << "\n";
			dosya.close();
			break;
		}
		case 3:		//Hasta liste menusu
		{
			system("cls");
			cout << "------------------HASTA L�STES�------------------" <<endl;
				ifstream dosyagetir; //dosyagetir tan�malamas�
				int hastasay = 0;
				dosyagetir.open("HastaneVeri.txt",ios::in); //dosyay� sadece okuma modunda a��yoruz.
				if(dosyagetir == NULL) //dosya yoksa olu�turulmam��sa sadece okuma modunda a�t���m�z i�in hata verir.
				{
					cout <<" Hastane dosyas� a��lamad�...";
					exit(1);	//uygulamadan ��k�� yapt�rmak i�in
				}
				cout << "TC No \t\tAd�\tSoyad�\tGiri� Tarihi" << endl<<endl;
				while(dosyagetir)//dosyagetir kadar d�nmesini sa�l�yoruz.
				{ 
					string getir;	//her dosyagetir de yeniden tan�mlanmas� i�in burada tan�ml�
					getline(dosyagetir,getir);	//dosya getirden gelen line'i getir'e at�yor
					cout << getir << endl;	//getir de�i�kenini ekrana yaz.
					hastasay++;	//ka� hasta oldu�unu say�yoruz.
				}
			    //hastasay 1 fazla ��k�yoru nedeni kay�t i�leminde kullan�lan "\n" komutu.
			    cout << endl << "\t" << hastasay - 1 << " hasta var." << endl << endl;
			break;
		}
		case 0:
		{
		exit(1); break;
		}
		default: system("cls"); cout << "Hatal� se�im tekrar se�im yap�n..." <<endl; break;
		}
	}
		return 0;
}






