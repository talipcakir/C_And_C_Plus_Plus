#include <iostream> 	// standart giriþ giriþ/çýkýþ için
#include <fstream> 		// dosyalama
#include <string> 		// string tanýmý
#include <clocale> 		// Türkçe desteði

using namespace std;

int main()
{
	setlocale(LC_ALL, "turkish"); 	//Türkçe karakter ekliyoruz
	int secim;						//menu için seçim için istem deðiþkeni
	long long int h_tc;				//hastanýn TC nosu
	string h_ad; 					//hastanýn Adý
	string h_soy; 					//hastanýn Soyadý
	string h_tarih; 				//hastanýn giriþ tarihi
	
	while(1)			//while(1) Döngüsü ile sürekli ana menüyü döndürmek için
	{					//Anamenü baþlangýcý
		cout << "******* Hastane Otomasyonu *******" << endl;		
		cout << "\t1 - Hasta Arama" << endl;
		cout << "\t2 - Hasta Kaydý" << endl;
		cout << "\t3 - Hasta Listesi" << endl; 
		cout << "\t0 - Çýkýþ" << endl;
		cout << "Ýþlem Seçiniz: ";
		cin>>secim;
		switch (secim)	//switch - case yapýsý ile ana menuden alt menülere geçiþ yapýyoruz.
		{
		case 1:
		{
			system("cls");
			cout << "----------------HASTA ARAMA MENUSU----------------" <<endl;
			ifstream dosyaara;	//dosya tanýmlama
			int sira;			// dosya sýrasý tutmak için
			string dosyaici;	// dosyada ki yazýlarý tutmak için
			char arama[10]; 	// aranacak deðiþken 10 karakter
			int kacbulundu = 0; // bulunan veri sayýsýný tutmek için
			dosyaara.open("HastaneVeri.txt",ios::in); //dosyayý sadece okuma modunda açýyoruz.
			if(dosyaara == NULL) //dosya yoksa oluþturulmamýþsa sadece okuma modunda açtýðýmýz için hata verir.
			{
				cout <<" Hastane dosyasý açýlamadý...";
				exit(1);	//uygulamadan çýkýþ yaptýrmak için
			}
			cout << endl << "Aramak istediðiniz hastayý yazýnýz:  ";//arama istemi
			cin >> arama;
			cout << "TC No \t\tAdý\tSoyadý\tGiriþ Tarihi" << endl<<endl;
			    while(!dosyaara.eof()) //dosyaara sonuna kadar while döngüsü dönecek
				{
			        getline(dosyaara, dosyaici);	//getline ile dosyaara da ki line i dosyaicine alýyoruz.
			        if ((dosyaici.find(arama, 0)) != string::npos)	//dosyaici deðiþkenine .find parametresi ile arama yaptýrýyoruz.
					{
			            cout << dosyaici << endl;	//aranan deðikenin bulunduðu line'larý yazdýrýyoruz.
			            kacbulundu++;			//kac adet aranan deðiþken bulundu tutuyoruz.
			        }
			    }
			    if(kacbulundu > 0)	//aranan deðiþken bulunmuþ ise
			    cout << endl << kacbulundu << " hasta bulundu." << endl;
			    else	//aranan deðiþken hiç bulunamadýysa
			    cout << endl << "Hasta bulunamadý." << endl;
			dosyaara.close();
			break;			
		}
		case 2:			//Hasta kayýt menusu
		{
			system("cls");
			cout << "----------------HASTA KAYIT MENUSU----------------" <<endl;
			ofstream dosya("HastaneVeri.txt",ios::app); //dosya yý tam yetki ile açýyoruz.
				cout << "Hasta Bilgilerini Giriniz" << endl;
				tcalan:	//tc hatalý girilirse buraya gelecek
				cout << endl;
				cout << "TC no: ";
				cin >> h_tc;
				if(h_tc > 10000000000 && h_tc < 99999999999); //tc no 11 karakter olmasýnýn denetimi
				else { cout << "Hatalý TC no giriþi yazýldý. Tekrar giriniz."; goto tcalan;}
				cout << "Adý: ";
				cin >> h_ad;
				cout << "Soyadý: ";
				cin >> h_soy;
				cout << "Hasta giriþ tarihi: ";
				cin >> h_tarih;
				dosya << h_tc << "\t" << h_ad << "\t" << h_soy  << "\t" << h_tarih << "\t" << "\n";
			dosya.close();
			break;
		}
		case 3:		//Hasta liste menusu
		{
			system("cls");
			cout << "------------------HASTA LÝSTESÝ------------------" <<endl;
				ifstream dosyagetir; //dosyagetir tanýmalamasý
				int hastasay = 0;
				dosyagetir.open("HastaneVeri.txt",ios::in); //dosyayý sadece okuma modunda açýyoruz.
				if(dosyagetir == NULL) //dosya yoksa oluþturulmamýþsa sadece okuma modunda açtýðýmýz için hata verir.
				{
					cout <<" Hastane dosyasý açýlamadý...";
					exit(1);	//uygulamadan çýkýþ yaptýrmak için
				}
				cout << "TC No \t\tAdý\tSoyadý\tGiriþ Tarihi" << endl<<endl;
				while(dosyagetir)//dosyagetir kadar dönmesini saðlýyoruz.
				{ 
					string getir;	//her dosyagetir de yeniden tanýmlanmasý için burada tanýmlý
					getline(dosyagetir,getir);	//dosya getirden gelen line'i getir'e atýyor
					cout << getir << endl;	//getir deðiþkenini ekrana yaz.
					hastasay++;	//kaç hasta olduðunu sayýyoruz.
				}
			    //hastasay 1 fazla çýkýyoru nedeni kayýt iþleminde kullanýlan "\n" komutu.
			    cout << endl << "\t" << hastasay - 1 << " hasta var." << endl << endl;
			break;
		}
		case 0:
		{
		exit(1); break;
		}
		default: system("cls"); cout << "Hatalý seçim tekrar seçim yapýn..." <<endl; break;
		}
	}
		return 0;
}






