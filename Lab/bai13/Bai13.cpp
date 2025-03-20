#include <stdio.h>
struct ngaysinh{
	int ngay, thang, nam;
};

struct nhanvien{
	char ten[20];
	struct ngaysinh ns;
	int id; 
	float luong;
};
int main(){
	struct nhanvien A;
	printf("nhap thong tin nhan vien:  ");
	printf("\nnhap ten: ");
	scanf("%s", &A.ten);
	printf("\nnhap nam sinh dd/dd/dddd: ");
	scanf("%d %d %d", &A.ns.ngay, &A.ns.thang, &A.ns.nam);
	printf("\nnhap id: ");
	scanf("%d", &A.id);
	printf("\nnhap luong: ");
	scanf("%f", &A.luong);
	
	printf("\n=========================\n");
	printf("Thong tin cua nhan vien: ");
	printf("\nHo ten: %s", A.ten);
	printf("\nNgay sinh: %d/%d/%d", A.ns.ngay, A.ns.thang, A.ns.nam);
	printf("\nID: %d", A.id);
	printf("\nLuong: %.2f", A.luong);
	return 0;
}
