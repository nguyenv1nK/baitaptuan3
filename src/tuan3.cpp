#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <ctime>

//Yeu cau de file ma nguon va cac file .txt cung 1 thu muc truoc khi bien dich




using namespace std;

class taikhoan
{
	public:
		char tentaikhoandangki[20], tentaikhoandangnhap[20];
		char hoten[20], ngaysinh[20], gioitinh[3], diachi[30];
		int flagdangnhap = 0;
		void dangnhap();
		void dangki();
	    void kiemtradangnhap();
	    void dangxuat();
	    int kiemtratontai(char tentaikhoandangnhap[20]);

	private:
		char matkhaudangki[20], matkhaudangnhap[20];
		char tentaikhoandk[20], matkhaudk[20];
};

void taikhoan::dangnhap()
{
	cout<<"Ten tai khoan:\n";
	cin>>tentaikhoandangnhap;
	cout<<"Mat khau : \n";
	fflush(stdin);
	cin>>matkhaudangnhap;
	kiemtradangnhap();
}

void taikhoan::dangxuat()
{
	flagdangnhap=0;
}

void taikhoan::dangki()
{
	cout<<"Moi ban nhap thong tin dang ki\n";
a:	cout<<"Ten tai khoan:\n";
	cin>> tentaikhoandangki;
	if(	kiemtratontai(tentaikhoandangki)==1)
	{
		cout<<"Ten tai khoan da ton tai, yeu cau chon ten khac !\n";
		goto a;
	}
	cout<<"Mat khau: \n";
	fflush(stdin);
	cin>> matkhaudangki;
	cout<<"Ho va ten: \n";
	fflush(stdin);
    cin>>hoten;
	cout<<"Ngay sinh: \n";
	fflush(stdin);
	cin>>ngaysinh;
	cout<<"Gioi tinh:\n";
	fflush(stdin);
	cin>>gioitinh;
	cout<<"Dia chi\n";
	fflush(stdin);
	cin>>diachi;
	system("cls");
	cout<<"Dang ki thanh cong !\n";
	ofstream fp("taikhoan.txt",ios::app);
	if(fp.fail())
	{
		cout<<"Khong tim thay file taikhoan.txt!\n";
	}
	else
	{
		fp<<tentaikhoandangki<<endl;
		fp<<matkhaudangki<<endl;
		fp.close();
	}	
}

void taikhoan::kiemtradangnhap()
{	
	ifstream fp( "taikhoan.txt",ios::out );
	if( fp.fail() )
	{
		cout<<"Khong tim thay file taikhoan.txt!\n";
	}
	else
	{
	
	while( !fp.eof() )
	{
		fp>>tentaikhoandk;
		fp>>matkhaudk;
		if(strcmp( tentaikhoandangnhap, tentaikhoandk ) == 0 && strcmp( matkhaudangnhap, matkhaudk ) == 0)
			{
				flagdangnhap = 1;
			}	
	}
		if( flagdangnhap == 1 )
			cout<<"Dang nhap thanh cong!\n";
		else
			cout<<"Dang nhap that bai, vui long kiem tra lai!\n";
	}
}

int taikhoan::kiemtratontai( char taikhoankiemtra[20] )
{	int flagtontai;
	ifstream fp( "taikhoan.txt",ios::out );
	while( !fp.eof() )
	{
		fp>>tentaikhoandk;
		fp>>matkhaudk;
		if( strcmp( taikhoankiemtra, tentaikhoandk) == 0)
			{
				flagtontai = 1;
			}
	}
	if( flagtontai == 1)
		return 1;
	else 
		return 0;
}

class tinnhan
{
	public:
		char taikhoannhan[20], taikhoangui[20];
		string noidungtinnhan;
		void tinnhandagui(char tentaikhoandangnhap[20]);
		void tinnhandanhan(char tentaikhoandangnhap[20]);
		void guitinnhan(char tentaikhoandangnhap[20]);
		int flagtontai=0;
		time_t thoigian = time(0);
		int flagblock;
		char* dt = ctime(&thoigian);
		int kiemtratontai(char taikhoankiemtra[20]);
		void kiemtrablock(char tentaikhoandangnhap[20],char tkb[20]);
	
};

void tinnhan::guitinnhan( char tentaikhoandangnhap[20] )
{	
	char taikhoannhan[20];
	cout<<"Nhap ten tai khoan gui tin nhan ";
	fflush(stdin);
	cin>>taikhoannhan;
	if( kiemtratontai(taikhoannhan) == 0)
		{
		system("cls");
		cout<<"Tai khoan nhan tin nhan khong ton tai\n";
		}
	else 
		kiemtrablock( tentaikhoandangnhap, taikhoannhan );
	if ( flagblock == 1 )
		{	system("cls");
			cout<<"Ban da bi tai khoan block\n";
		}
	else{
			cout<<"Nhap noi dung tin nhan: ";
			fflush(stdin);
			getline(cin, noidungtinnhan);
			ofstream fp1("tinnhan.txt", ios::app);
			fp1<<tentaikhoandangnhap<<endl;
			fp1<<taikhoannhan<<endl;
			fp1<<dt<<endl;
			fp1<<noidungtinnhan<<endl;
			fp1.close();
		}
}
void tinnhan::kiemtrablock(char tentaikhoandangnhap[20], char tkb[20])
	{	
		char taikhoanc[20], taikhoand[20];

		
		ifstream fp2("block.txt",ios::out);
		while(!fp2.eof())
		{
			fp2>>taikhoand;
			fp2>>taikhoanc;
			if(strcmp(taikhoanc, tentaikhoandangnhap)==0 && strcmp(taikhoand, tkb)==0)
				flagblock=1;
		}
	}
void tinnhan::tinnhandagui(char tentaikhoandangnhap[20])
{		string thoigian;
		ifstream fp1("tinnhan.txt", ios::out);
		
	while(!fp1.eof())
	{
		fp1>>taikhoangui;
		fp1>>taikhoannhan;
		fp1.ignore();
		getline(fp1, thoigian);
		fp1.ignore();
		getline(fp1, noidungtinnhan);
		fp1.ignore();
		if(strcmp(tentaikhoandangnhap, taikhoangui)==0)
		{
			cout<<"Da gui tin nhan den:"<<taikhoannhan<<"\nvao luc: "<<thoigian<<"\nNoi dung :";
			cout<<noidungtinnhan<<endl;
		}
	}
		fp1.close();
}
void tinnhan::tinnhandanhan(char tentaikhoandangnhap[20])
{		string thoigian;
		ifstream fp1("tinnhan.txt", ios::out);
		
	while(!fp1.eof())
	{
		fp1>>taikhoangui;
		fp1>>taikhoannhan;
		fp1.ignore();
		getline(fp1, thoigian);
		fp1.ignore();
		getline(fp1, noidungtinnhan);
		fp1.ignore();
		if(strcmp(tentaikhoandangnhap, taikhoannhan)==0)
		{
			cout<<"Da nhan tin nhan tu:"<<taikhoangui<<"\nvao luc: "<<thoigian<<"\nNoi dung :";
			cout<<noidungtinnhan<<endl;
		}
	}
		fp1.close();
}


int tinnhan::kiemtratontai(char taikhoankiemtra[20])
{	int flagtontai;
	char tentaikhoandk[20], matkhaudk[20];
	ifstream fp("taikhoan.txt",ios::out);
	while(!fp.eof())
	{
		fp>>tentaikhoandk;
		fp>>matkhaudk;
		if(strcmp(taikhoankiemtra, tentaikhoandk)==0)
			{
				flagtontai=1;
			}
	}
	if(flagtontai==1)
		return 1;
	else
		return 0;
}

class banbe
{
	public:  	void themban(char tentaikhoandangnhap[20]);
				void indanhsachban(char tentaikhoandangnhap[20]);
				void block(char tentaikhoandangnhap[20]);
				time_t thoigian = time(0);
				char* dt = ctime(&thoigian);
				char tg[255];
				int kiemtratontai(char taikhoankiemtra[20]);

};
int banbe::kiemtratontai(char taikhoankiemtra[20])
{	int flagtontai;
	char tentaikhoandk[20], matkhaudk[20];
	ifstream fp("taikhoan.txt", ios::out);
	while(!fp.eof())
	{
		fp>>tentaikhoandk;
		fp>>matkhaudk;
		if(strcmp(taikhoankiemtra, tentaikhoandk)==0)
			{
				flagtontai=1;
			}
	}
	if(flagtontai==1)
		return 1;
	else
		return 0;
}

void banbe:: themban(char tentaikhoandangnhap[20])
	{	char taikhoanb[20];
		ofstream fp2("banbe.txt", ios::app);
		cout<<"Nhap tai khoan ban muon ket ban:\n";
		cin>>taikhoanb;
		if(kiemtratontai(taikhoanb)==1)
		{	system("cls");
			cout<<"Ket ban thanh cong !\n";
			fp2<<tentaikhoandangnhap<<"\t";
			fp2<<taikhoanb<<"\n";
			fp2<<dt<<"\n";
		}
		else
		{	system("cls");
			cout<<"Tai khoan khong ton tai, yeu cau kiem tra lai!\n";
		}
		fp2.close();
	}
void banbe::indanhsachban(char tentaikhoandangnhap[20])
	{	char taikhoana[20], taikhoanb[20];
		string data;
		ifstream fp2("banbe.txt", ios::out);	
	while(!fp2.eof())
		{
			fp2>>taikhoana;
			fp2>>taikhoanb;
			fp2.ignore();
			getline(fp2, data);
			
			if(strcmp(taikhoana, tentaikhoandangnhap)==0)
				{	
					cout<<endl;
					cout<<taikhoanb<<endl;
					cout<<"them vao luc\t"<<data<<endl;				
				}
		else	if(strcmp(taikhoanb,tentaikhoandangnhap)==0)
					{
						cout<<taikhoana<<endl;
						cout<<"them vao luc\t"<<data<<endl;				
					}
		}	
		fp2.close();
	}
void banbe::block(char tentaikhoandangnhap[20])
	{	char taikhoanblock[20];
		cout<<"*Luu y sau khi block 1 tai khoan,tai khoan do se khong the gui tin nhan cho ban !\n";
		cout<<"Nhap tai khoan ban muon block:\n";
		cin>>taikhoanblock;
		ofstream fp2("block.txt",ios::app);
		fp2<<tentaikhoandangnhap<<"\t";
		fp2<<taikhoanblock<<endl;
		fp2.close();
	}
int main()
{	
	taikhoan a;
 	banbe b;
 	tinnhan c;
 	int luachon, luachon1;
 	while(luachon!=3)
 	{
 	cout<<"==================Menu==================\n";
 	cout<<"1.Dang nhap\n";
 	cout<<"2.Dang ki\n";
 	cout<<"3.Ket thuc\n";
 	cout<<"Moi nhap lua chon:\n";
 	cin>>luachon;
 	switch(luachon)
 	{
 		case 1:
 			a.dangnhap();
 			system("cls");
 			goto z;
 			break;
 		case 2:
 			a.dangki();
 			break;
 		case 3:
 			break;
 		default :
 			system("cls");
 			cout<<"Khong co lua chon nay,moi nhap lai\n";
 			break;
 			
 	}
 	}
 z:	if(a.flagdangnhap==1)
 	{
 	do
 		{
 		cout<<"=============>>>"<<a.tentaikhoandangnhap<<"<<<=============\n";
 		cout<<"1.Gui tin nhan\n";
 		cout<<"2.Hien thi cac tin nhan da gui\n";
 		cout<<"3.Hien thi cac tin nhan da nhan\n";
 		cout<<"4.Them ban be\n";
 		cout<<"5.Hien thi danh sach ban be\n";
 		cout<<"6.Block\n";
 		cout<<"7.Dang xuat\n";
 		cout<<"Moi nhap lua chon:\n";
 		cin>>luachon1;
 		switch(luachon1)
 	{
 		case 1:
 			system("cls");
 			c.guitinnhan(a.tentaikhoandangnhap);
 			break;
 		case 2:
 			system("cls");
 			c.tinnhandagui(a.tentaikhoandangnhap);
 			break;
 		case 3:
 			system("cls");
 			c.tinnhandanhan(a.tentaikhoandangnhap);
 			break;
 		
 		case 4:
 			system("cls");
 			b.themban(a.tentaikhoandangnhap);
 			break;
 		case 5:
 			system("cls");
 			b.indanhsachban(a.tentaikhoandangnhap);
 			break;
 		case 6:
 			system("cls");
 			b.block(a.tentaikhoandangnhap);
 			break;
 		case 7:
 			a.dangxuat();
 			system("cls");
 			return main();
 			break;
 		default:
 			system("cls");
 			cout<<"Khong co lua chon nay,yeu cau nap lai!\n";
 	}

 		}
 		while(luachon1!=6);
 	}
 	else
 		{
		 	cout<<"Dang nhap that bai, yeu cau kiem tra lai tai khoan va mat khau!\n";
		 	return main();
		 }
 	return 0;
}

