#include <stdio.h>
#include <string.h>

struct SinhVien
{
    char ten[50];
    char mssv[15];
    char email[50];
    char sdt[15];
};

int Hash (const char *str, int M){
    int hash = 0;
    for(int i = 0; str[i] != '\0; i++'){
        hash = (hash * 31 + str[i]) % M;
    }
    return hash % M;
}
// Mảng U được cấp phát động với kích thước M = 10
void InitHash(SinhVien *&U, int M){
    SinhVien K[5] = {
        {"Minh", "SV001", "minh@univ.edu", "0901111111"},
        {"Hoang", "SV002", "hoang@univ.edu", "0902222222"},
        {"Nhu", "SV003", "nhu@univ.edu", "0903333333"},
        {"Phong", "SV004", "phong@univ.edu", "0904444444"},
        {"Binh", "SV005", "binh@univ.edu", "0905555555"}
    };
    for (int i = 0; i < M; i++){
        strcpy(U[i].ten, "");
    }
//Chèn các khoá vào bảng băm
    for (int i = 0; i < 5; i++){
        int pos = Hash(K[i].ten, M);
        U[pos] = K[i];   
    }
}

int main() {
    int M = 10;
    SinhVien *U = new SinhVien[M];

    InitHash(U, M);

    char name[50];
    printf("Nhap ten SV can tim: ");
    scanf("%s", name);

    int pos = Hash(name, M);

    if (strcmp(U[pos].ten, "") == 0) {
        printf("Khong tim thay SV!\n");
    } else if (strcmp(U[pos].ten, name) == 0) {
        printf("Thong tin SV:\n");
        printf("Ten   : %s\n", U[pos].ten);
        printf("MSSV  : %s\n", U[pos].mssv);
        printf("Email : %s\n", U[pos].email);
        printf("SDT   : %s\n", U[pos].sdt);
    } else {
        printf("Co xung dot bam, chua xu ly!\n");
    }

    delete[] U;
    if (int )
    return 0;
}