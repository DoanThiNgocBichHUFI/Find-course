#include<stdio.h>
#include<conio.h>
#include<string.h>
struct moTaKH
{
	char hinhThucDaoTao[30];
	char cachThucHoc;
};
struct tenKH
{
	char tenMonHoc[40];
	char capDo[20];
};

struct Course
{
	int maKH;
	struct tenKH tenkh;
	struct moTaKH moTa;
	char danhMucKH[20];
	char tenNguoiDay[20];
	char tenNguoiHoc[20];
};

void nhapTen(struct tenKH* ten)
{
	printf("Mon hoc: ");
	getchar(); // doc giup bo bo dem di, sau do doc vao dong moi
	gets( ten->tenMonHoc);
	printf("Cap do cua khoa hoc: ");
	getchar(); // doc giup bo bo dem di, sau do doc vao dong moi
	gets( ten->capDo); // doc ca dong , ten tro den cap do
}

// ham tra ve thong tin khoa hoc sau khi nhap
struct Course nhapKH()
{
	// tao ra struct dat ten la KH
	struct Course KH;
	printf("Nhap ma: ");
	scanf("%5d", &KH.maKH);
	nhapTen(&KH.tenkh);
	return KH;
}

void hienThiTTKH(struct Course KH)
{
	printf("%-10d %-10s",KH.maKH, KH.tenkh.tenMonHoc);
	printf("%-10s %-10s",KH.tenkh.capDo, KH.moTa);
	printf("%-10s",KH.danhMucKH);
	printf( "%-10s %-10s", KH.tenNguoiDay, KH.tenNguoiHoc);
}

void timTheoTen(struct Course* ds, int slkh)
{
	char ten[20];
	printf("NHap ten khoa hoc: "); scanf("%s",ten);

	int timKH =0;
	for(int i =0; i < slkh; i++)
	{
		if(strcmp(ten, ds[i].tenkh.tenMonHoc)== 0)
		{
			hienThiTTKH(ds[i]);
			timKH =1;
		}
	}
	if(timKH == 0)
	{
		printf("KHONG co khoa hoc %s trong danh sach.", ten);
	}
}


int main()
{
	struct Course dskh[100];
	struct Course KH;
	int  slkh =0;
		KH = nhapKH();
	dskh[slkh++] = KH;

	KH = nhapKH();
	dskh[slkh++] = KH;
	timTheoTen(dskh,slkh);
	return 0;
}