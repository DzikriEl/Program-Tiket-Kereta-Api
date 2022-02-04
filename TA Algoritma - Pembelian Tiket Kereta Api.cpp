#include<iostream> //header untuk cin dan cout
#include<fstream> //header untuk menggunakan operasi file
using namespace std;

void pembuka(){ //menggunakan void untuk bagian pembuka
	cout<<"\t\t|#######################################################|"<<endl;
	cout<<"\t\t|                   -----------------                   | "<<endl;
	cout<<"\t\t|================== [ TIKET KERETA API ] ===============|"<<endl;
	cout<<"\t\t|                   -----------------                   | "<<endl;
	cout<<"\t\t|#######################################################|"<<endl<<endl;
	cout<<"\t\t    [ PROGRAM SEDERHANA PEMBELIAN TIKET KERETA API ]   "<<endl;
}

void penutup(){ //menggunakan void untuk bagian penutup
	cout<<endl<<endl<<endl;
	cout<<"\t\t|=======================================|"<<endl;
	cout<<"\t\t|TERIMA KASIH TELAH MELAKUKAN TRANSAKSI |"<<endl;
	cout<<"\t\t|=======================================|"<<endl;	
}

void garis(){
	cout<<"=========================================\n";
}

//TOTAL HARGA PEMBELIAN TIKET
int total(int a, int b, int c){
	return(a*(b+c));
}

//TOTAL UANG YANG DIMASUKAN
int uang_total(int f, int g){
	return(f+g);
}

//KEMBALIAN SETELAH MEMASUKAN UANG 
int kembalian(int x, int y){
	return(x-y);
}

//KEMBALIAN KEDUA JIKA UANG KURANG
int kembalian2(int d, int e){
	return(d+e);
}



main(){
	mulai:
	system("cls");
	char yt;
	system("COLOR A"); //Untuk mewarnai program
	int stasiun; //variabel untuk memilih stasiun
	int total_harga; 
	int konfirmasi; //variabel untuk konfirmasi melanjutkan transaksi
	int resi1;
			//Tarif deposit
			int deposit=10000;
			
				//Tarif Kereta, ada 7 stasiun
				int tarif_cilebut=5000;
				int tarif_bojong_gede=5000;
				int tarif_citayam=5000;
				int tarif_depok=5000;
				int tarif_depok_baru=5000;
				
				
	//DEKLARASI TIKET
	struct tiket{
		int tiket; 
		int uang;
		int uang_2;
		int uang_3; 
		int jumlah_uang;
		int kembalian;
		int kembalian_2;
	};
	tiket kereta; 

	//PEMBUKA
	pembuka();
	cout<<endl;
	//ISI
	cout<<"\t\t\t\t Stasiun Bogor - Depok Baru \n"; 
	cout<<endl;
	cout<<"Silakan Pilih Stasiun Tujuan : \n";
	cout<<"1. Cilebut\n";
	cout<<"2. Bojong Gede\n";
	cout<<"3. Citayam\n";
	cout<<"4. Depok\n";
	cout<<"5. Depok Baru\n"<<endl;
	cout<<"Masukan Stasiun Tujuan Anda : ";
	cin>>stasiun; 
	switch(stasiun){
		case 1:
			system("cls"); //Menghapus layar sebelumnya
			cout<<"Tujuan  : Stasiun Cilebut\n";
			cout<<"Tarif   : Rp.5000\n";
			cout<<"Deposit : Rp.10.000\n";
			cout<<"Silakan Masukan Jumlah Tiket : ";
			cin>>kereta.tiket;
			total_harga=total(kereta.tiket, tarif_cilebut, deposit); //menggunakan fungsi (non-void)
			cout<<"Total   : Rp."<<total_harga;
			cout<<endl<<endl;
			cout<<"Konfirmasi Stasiun & Tiket\n";
			garis();
			cout<<"RELASI   : BOGOR-CILEBUT\n";
			cout<<"JUMLAH   : "<<kereta.tiket<<endl;
			cout<<"TOTAL    : Rp."<<total_harga<<endl;
			garis();
			cout<<"Lanjutkan Transaksi?\n";
			cout<<"1. Ya\n";
			cout<<"2. Batal\n";
			cout<<"Jawab : ";
			cin>>konfirmasi;
			switch(konfirmasi){
				case 1:
					system("cls");
					cout<<"Total  : Rp."<<total_harga<<endl;
					cout<<"Masukan Uang Anda : Rp.";
					cin>>kereta.uang;
					kereta.kembalian=kembalian(kereta.uang, total_harga);
					//KONDISI UANG PAS ATAU LEBIH
					if(kereta.uang>=total_harga){
						cout<<"Kembalian : Rp."<<kereta.kembalian<<endl;
						cout<<"Terima Kasih, Transaksi Sedang Diproses. . . ";
						penutup();
						ofstream resi1;
						resi1.open("resi_cilebut.txt");
						resi1<<"TRANSAKSI           : PEMBELIAN TIKET KERETA API"<<endl;
						resi1<<"RELASI              : BOGOR-CILEBUT"<<endl;
						resi1<<"JUMLAH TIKET        : "<<kereta.tiket<<endl;
						resi1<<"HARGA TIKET         : Rp."<<tarif_cilebut<<endl;
						resi1<<"TOTAL               : Rp."<<total_harga<<endl;
						resi1<<"UANG YANG DIMASUKAN : Rp."<<kereta.uang<<endl;
						resi1<<"KEMBALIAN           : Rp."<<kereta.kembalian<<endl;
						resi1<<endl;
						resi1<<"TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
						resi1.close();
					}
					//KONDISI UANG KURANG
					else{
						cout<<"Anda Masih Kurang : Rp."<<kereta.kembalian<<endl;
						cout<<"Silakan Masukan Uang Kurang : Rp.";
						cin>>kereta.uang_2;
						kereta.kembalian_2=kembalian2(kereta.kembalian, kereta.uang_2);
						kereta.uang_3=uang_total(kereta.uang, kereta.uang_2);
							cout<<"Kembalian : Rp."<<kereta.kembalian_2<<endl;
							cout<<"Terima Kasih, Transaksi Sedang Diproses. . . ";
							penutup();
							ofstream resi1;
							resi1.open("resi_cilebut.txt");
							resi1<<"TRANSAKSI           : PEMBELIAN TIKET KERETA API"<<endl;
							resi1<<"RELASI              : BOGOR-CILEBUT"<<endl;
							resi1<<"JUMLAH TIKET        : "<<kereta.tiket<<endl;
							resi1<<"HARGA TIKET         : Rp."<<tarif_cilebut<<endl;
							resi1<<"TOTAL               : Rp."<<total_harga<<endl;
							resi1<<"UANG YANG DIMASUKAN : Rp."<<kereta.uang_3<<endl;
							resi1<<"KEMBALIAN           : Rp."<<kereta.kembalian_2<<endl;
							resi1<<endl;
							resi1<<"TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
							resi1.close();
						}
					break;	
					default:
					system("cls");
					cout<<"Pilihan Anda Salah !"<<endl;
    				cout<<"Masukan Y untuk Mengulang, T untuk keluar"<<endl;
					cin>>yt; 
    				if(yt=='Y' || yt=='y')
					{goto mulai;} 
					if(yt=='T' || yt=='t') 
					{goto selesai;} 					
					}
		break;
		case 2:
			system("cls");
			cout<<"Tujuan  : Stasiun Bojong Gede\n";
			cout<<"Tarif   : Rp.5000\n";
			cout<<"Deposit : Rp.10.000\n";
			cout<<"Silakan Masukan Jumlah Tiket : ";
			cin>>kereta.tiket;
			total_harga=total(kereta.tiket, tarif_bojong_gede, deposit);
			cout<<"Total   : Rp."<<total_harga;
			cout<<endl<<endl;
			cout<<"Konfirmasi Stasiun & Tiket\n";
			garis();
			cout<<"RELASI   : BOGOR-BOJONG GEDE\n";
			cout<<"JUMLAH   : "<<kereta.tiket<<endl;
			cout<<"TOTAL    : Rp."<<total_harga<<endl;
			garis();
			cout<<"Lanjutkan Transaksi?\n";
			cout<<"1. Ya\n";
			cout<<"2. Batal\n";
			cout<<"Jawab : ";
			cin>>konfirmasi;
			switch(konfirmasi){
				case 1:
					system("cls");
					cout<<"Total  : Rp."<<total_harga<<endl;
					cout<<"Masukan Uang Anda : Rp.";
					cin>>kereta.uang;
					kereta.kembalian=kembalian(kereta.uang, total_harga);
					//KONDISI UANG PAS ATAU LEBIH
					if(kereta.uang>=total_harga){
						cout<<"Kembalian : Rp."<<kereta.kembalian<<endl;
						cout<<"Terima Kasih, Transaksi Sedang Diproses. . . ";
						penutup();
						ofstream resi1;
						resi1.open("resi_bojong_gede.txt");
						resi1<<"TRANSAKSI           : PEMBELIAN TIKET KERETA API"<<endl;
						resi1<<"RELASI              : BOGOR-BOJONG GEDE"<<endl;
						resi1<<"JUMLAH TIKET        : "<<kereta.tiket<<endl;
						resi1<<"HARGA TIKET         : Rp."<<tarif_bojong_gede<<endl;
						resi1<<"TOTAL               : Rp."<<total_harga<<endl;
						resi1<<"UANG YANG DIMASUKAN : Rp."<<kereta.uang<<endl;
						resi1<<"KEMBALIAN           : Rp."<<kereta.kembalian<<endl;
						resi1<<endl;
						resi1<<"TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
						resi1.close();
					}
					//KONDISI UANG KURANG
					else{
						cout<<"Anda Masih Kurang : Rp."<<kereta.kembalian<<endl;
						cout<<"Silakan Masukan Uang Kurang : Rp.";
						cin>>kereta.uang_2;
						kereta.kembalian_2=kembalian2(kereta.kembalian, kereta.uang_2);
						kereta.uang_3=uang_total(kereta.uang, kereta.uang_2);
						cout<<"Kembalian : Rp."<<kereta.kembalian_2<<endl;
						cout<<"Terima Kasih, Transaksi Sedang Diproses. . . ";
						penutup();
						ofstream resi1;
						resi1.open("resi_bojong_gede.txt");
						resi1<<"TRANSAKSI           : PEMBELIAN TIKET KERETA API"<<endl;
						resi1<<"RELASI              : BOGOR-BOJONG GEDE"<<endl;
						resi1<<"JUMLAH TIKET        : "<<kereta.tiket<<endl;
						resi1<<"HARGA TIKET         : Rp."<<tarif_bojong_gede<<endl;
						resi1<<"TOTAL               : Rp."<<total_harga<<endl;
						resi1<<"UANG YANG DIMASUKAN : Rp."<<kereta.uang_3<<endl;
						resi1<<"KEMBALIAN           : Rp."<<kereta.kembalian_2<<endl;
						resi1<<endl;
						resi1<<"TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
						resi1.close();
					}
				break;	
				default:
					system("cls");
					cout<<"Pilihan Anda Salah !"<<endl;
    				cout<<"Masukan Y untuk Mengulang, T untuk keluar"<<endl;
					cin>>yt; 
    				if(yt=='Y' || yt=='y')
					{goto mulai;} 
					if(yt=='T' || yt=='t') 
					{goto selesai;} 
					}




		break;
		case 3:
			system("cls");
			cout<<"Tujuan  : Stasiun Citayam\n";
			cout<<"Tarif   : Rp.5000\n";
			cout<<"Deposit : Rp.10.000\n";
			cout<<"Silakan Masukan Jumlah Tiket : ";
			cin>>kereta.tiket;
			total_harga=total(kereta.tiket, tarif_citayam, deposit);
			cout<<"Total   : Rp."<<total_harga;
			cout<<endl<<endl;
			cout<<"Konfirmasi Stasiun & Tiket\n";
			garis();
			cout<<"RELASI   : BOGOR-CITAYAM\n";
			cout<<"JUMLAH   : "<<kereta.tiket<<endl;
			cout<<"TOTAL    : Rp."<<total_harga<<endl;
			garis();
			cout<<"Lanjutkan Transaksi?\n";
			cout<<"1. Ya\n";
			cout<<"2. Batal\n";
			cout<<"Jawab : ";
			cin>>konfirmasi;
			switch(konfirmasi){
				case 1:
					system("cls");
					cout<<"Total  : Rp."<<total_harga<<endl;
					cout<<"Masukan Uang Anda : Rp.";
					cin>>kereta.uang;
					kereta.kembalian=kembalian(kereta.uang, total_harga);
					//KONDISI UANG PAS ATAU LEBIH
					if(kereta.uang>=total_harga){
						cout<<"Kembalian : Rp."<<kereta.kembalian<<endl;
						cout<<"Terima Kasih, Transaksi Sedang Diproses. . . ";
						penutup();
						ofstream resi1;
						resi1.open("resi_citayam.txt");
						resi1<<"TRANSAKSI           : PEMBELIAN TIKET KERETA API"<<endl;
						resi1<<"RELASI              : BOGOR-CITAYAM"<<endl;
						resi1<<"JUMLAH TIKET        : "<<kereta.tiket<<endl;
						resi1<<"HARGA TIKET         : Rp."<<tarif_citayam<<endl;
						resi1<<"TOTAL               : Rp."<<total_harga<<endl;
						resi1<<"UANG YANG DIMASUKAN : Rp."<<kereta.uang<<endl;
						resi1<<"KEMBALIAN           : Rp."<<kereta.kembalian<<endl;
						resi1<<endl;
						resi1<<"TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
						resi1.close();
					}
					//KONDISI UANG KURANG
					else{
						cout<<"Anda Masih Kurang : Rp."<<kereta.kembalian<<endl;
						cout<<"Silakan Masukan Uang Kurang : Rp.";
						cin>>kereta.uang_2;
						kereta.kembalian_2=kembalian2(kereta.kembalian, kereta.uang_2);
						kereta.uang_3=uang_total(kereta.uang, kereta.uang_2);
						cout<<"Kembalian : Rp."<<kereta.kembalian_2<<endl;
						cout<<"Terima Kasih, Transaksi Sedang Diproses. . . ";
						penutup();
						ofstream resi1;
						resi1.open("resi_citayam.txt");
						resi1<<"TRANSAKSI           : PEMBELIAN TIKET KERETA API"<<endl;
						resi1<<"RELASI              : BOGOR-CITAYAM"<<endl;
						resi1<<"JUMLAH TIKET        : "<<kereta.tiket<<endl;
						resi1<<"HARGA TIKET         : Rp."<<tarif_citayam<<endl;
						resi1<<"TOTAL               : Rp."<<total_harga<<endl;
						resi1<<"UANG YANG DIMASUKAN : Rp."<<kereta.uang_3<<endl;
						resi1<<"KEMBALIAN           : Rp."<<kereta.kembalian_2<<endl;
						resi1<<endl;
						resi1<<"TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
						resi1.close();
					}
				break;	
				default:
					system("cls");
					cout<<"Pilihan Anda Salah !"<<endl;
    				cout<<"Masukan Y untuk Mengulang, T untuk keluar"<<endl;
					cin>>yt; 
    				if(yt=='Y' || yt=='y')
					{goto mulai;} 
					if(yt=='T' || yt=='t') 
					{goto selesai;} 
					}	
					
					
		break;
		case 4:
			system("cls");
			cout<<"Tujuan  : Stasiun Depok\n";
			cout<<"Tarif   : Rp.5000\n";
			cout<<"Deposit : Rp.10.000\n";
			cout<<"Silakan Masukan Jumlah Tiket : ";
			cin>>kereta.tiket;
			total_harga=total(kereta.tiket, tarif_depok, deposit);
			cout<<"Total   : Rp."<<total_harga;
			cout<<endl<<endl;
			cout<<"Konfirmasi Stasiun & Tiket\n";
			garis();
			cout<<"RELASI   : BOGOR-DEPOK\n";
			cout<<"JUMLAH   : "<<kereta.tiket<<endl;
			cout<<"TOTAL    : Rp."<<total_harga<<endl;
			garis();
			cout<<"Lanjutkan Transaksi?\n";
			cout<<"1. Ya\n";
			cout<<"2. Batal\n";
			cout<<"Jawab : ";
			cin>>konfirmasi;
			switch(konfirmasi){
				case 1:
					system("cls");
					cout<<"Total  : Rp."<<total_harga<<endl;
					cout<<"Masukan Uang Anda : Rp.";
					cin>>kereta.uang;
					kereta.kembalian=kembalian(kereta.uang, total_harga);
					//KONDISI UANG PAS ATAU LEBIH
					if(kereta.uang>=total_harga){
						cout<<"Kembalian : Rp."<<kereta.kembalian<<endl;
						cout<<"Terima Kasih, Transaksi Sedang Diproses. . . ";
						penutup();
						ofstream resi1;
						resi1.open("resi_depok.txt");
						resi1<<"TRANSAKSI           : PEMBELIAN TIKET KERETA API"<<endl;
						resi1<<"RELASI              : BOGOR-DEPOK"<<endl;
						resi1<<"JUMLAH TIKET        : "<<kereta.tiket<<endl;
						resi1<<"HARGA TIKET         : Rp."<<tarif_depok<<endl;
						resi1<<"TOTAL               : Rp."<<total_harga<<endl;
						resi1<<"UANG YANG DIMASUKAN : Rp."<<kereta.uang<<endl;
						resi1<<"KEMBALIAN           : Rp."<<kereta.kembalian<<endl;
						resi1<<endl;
						resi1<<"TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
						resi1.close();
					}
					//KONDISI UANG KURANG
					else{
						cout<<"Anda Masih Kurang : Rp."<<kereta.kembalian<<endl;
						cout<<"Silakan Masukan Uang Kurang : Rp.";
						cin>>kereta.uang_2;
						kereta.kembalian_2=kembalian2(kereta.kembalian, kereta.uang_2);
						kereta.uang_3=uang_total(kereta.uang, kereta.uang_2);
						cout<<"Kembalian : Rp."<<kereta.kembalian_2<<endl;
						cout<<"Terima Kasih, Transaksi Sedang Diproses. . . ";
						penutup();
						ofstream resi1;
						resi1.open("resi_depok.txt");
						resi1<<"TRANSAKSI           : PEMBELIAN TIKET KERETA API"<<endl;
						resi1<<"RELASI              : BOGOR-DEPOK"<<endl;
						resi1<<"JUMLAH TIKET        : "<<kereta.tiket<<endl;
						resi1<<"HARGA TIKET         : Rp."<<tarif_depok<<endl;
						resi1<<"TOTAL               : Rp."<<total_harga<<endl;
						resi1<<"UANG YANG DIMASUKAN : Rp."<<kereta.uang_3<<endl;
						resi1<<"KEMBALIAN           : Rp."<<kereta.kembalian_2<<endl;
						resi1<<endl;
						resi1<<"TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
						resi1.close();
					}
				break;	
				default:
					system("cls");
					cout<<"Pilihan Anda Salah !"<<endl;
    				cout<<"Masukan Y untuk Mengulang, T untuk keluar"<<endl;
					cin>>yt; 
    				if(yt=='Y' || yt=='y')
					{goto mulai;} 
					if(yt=='T' || yt=='t') 
					{goto selesai;} 
					}
					
					
		break;
		case 5:
			system("cls");
			cout<<"Tujuan  : Stasiun Depok Baru\n";
			cout<<"Tarif   : Rp.5000\n";
			cout<<"Deposit : Rp.10.000\n";
			cout<<"Silakan Masukan Jumlah Tiket : ";
			cin>>kereta.tiket;
			total_harga=total(kereta.tiket, tarif_depok_baru, deposit);
			cout<<"Total   : Rp."<<total_harga;
			cout<<endl<<endl;
			cout<<"Konfirmasi Stasiun & Tiket\n";
			garis();
			cout<<"RELASI   : BOGOR-DEPOK BARU\n";
			cout<<"JUMLAH   : "<<kereta.tiket<<endl;
			cout<<"TOTAL    : Rp."<<total_harga<<endl;
			garis();
			cout<<"Lanjutkan Transaksi?\n";
			cout<<"1. Ya\n";
			cout<<"2. Batal\n";
			cout<<"Jawab : ";
			cin>>konfirmasi;
			switch(konfirmasi){
				case 1:
					system("cls");
					cout<<"Total  : Rp."<<total_harga<<endl;
					cout<<"Masukan Uang Anda : Rp.";
					cin>>kereta.uang;
					kereta.kembalian=kembalian(kereta.uang, total_harga);
					//KONDISI UANG PAS ATAU LEBIH
					if(kereta.uang>=total_harga){
						cout<<"Kembalian : Rp."<<kereta.kembalian<<endl;
						cout<<"Terima Kasih, Transaksi Sedang Diproses. . . ";
						penutup();
						ofstream resi2;
						resi2.open("resi_depok_baru.txt");
						resi2<<"TRANSAKSI           : PEMBELIAN TIKET KERETA API"<<endl;
						resi2<<"RELASI              : BOGOR-DEPOK BARU"<<endl;
						resi2<<"JUMLAH TIKET        : "<<kereta.tiket<<endl;
						resi2<<"HARGA TIKET         : Rp."<<tarif_depok_baru<<endl;
						resi2<<"TOTAL               : Rp."<<total_harga<<endl;
						resi2<<"UANG YANG DIMASUKAN : Rp."<<kereta.uang<<endl;
						resi2<<"KEMBALIAN           : Rp."<<kereta.kembalian<<endl;
						resi2<<endl;
						resi2<<"TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
						resi2.close();
					}
					//KONDISI UANG KURANG
					else{
						cout<<"Anda Masih Kurang : Rp."<<kereta.kembalian<<endl;
						cout<<"Silakan Masukan Uang Kurang : Rp.";
						cin>>kereta.uang_2;
						kereta.kembalian_2=kembalian2(kereta.kembalian, kereta.uang_2);
						kereta.uang_3=uang_total(kereta.uang, kereta.uang_2);
						cout<<"Kembalian : Rp."<<kereta.kembalian_2<<endl;
						cout<<"Terima Kasih, Transaksi Sedang Diproses. . . ";
						penutup();
						ofstream resi1;
						resi1.open("resi_depok_baru.txt");
						resi1<<"TRANSAKSI           : PEMBELIAN TIKET KERETA API"<<endl;
						resi1<<"RELASI              : BOGOR-DEPOK BARU"<<endl;
						resi1<<"JUMLAH TIKET        : "<<kereta.tiket<<endl;
						resi1<<"HARGA TIKET         : Rp."<<tarif_depok_baru<<endl;
						resi1<<"TOTAL               : Rp."<<total_harga<<endl;
						resi1<<"UANG YANG DIMASUKAN : Rp."<<kereta.uang_3<<endl;
						resi1<<"KEMBALIAN           : Rp."<<kereta.kembalian_2<<endl;
						resi1<<endl;
						resi1<<"TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
						resi1.close();
					}
				break;	
				default:
					system("cls");
					cout<<"Pilihan Anda Salah !"<<endl;
    				cout<<"Masukan Y untuk Mengulang, T untuk keluar"<<endl;
					cin>>yt; 
    				if(yt=='Y' || yt=='y')
					{goto mulai;} 
					if(yt=='T' || yt=='t') 
					{goto selesai;} 
					}	
																											
		break;
		default:
			system("cls");
			cout<<endl;
			cout<<"\t\t =============[ PERINGATAN ! ]============"<<endl;
			cout<<"\t    ======== Pilihan Yang Anda Masukan Salah ========="<<endl<<endl;
    		cout<<"Silahkan Ketik 'Y' untuk Mengulang dan 'T' untuk Keluar"<<endl;
    		cout<<"Jawab : ";
			cin>>yt; 
    		if(yt=='Y' || yt=='y')
			{goto mulai;} 
			if(yt=='T' || yt=='t') 
			{goto selesai;} 
			selesai:
			cout<<endl<<endl;
			cout<<"\t\t|============================================|"<<endl;
			cout<<"\t\t|TERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI |"<<endl;
			cout<<"\t\t|============================================|"<<endl;
			}
		}
