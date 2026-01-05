#include <iostream>
#include <cstring>
using namespace std;

void swapInt(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void sortAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapInt(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortAbsAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (abs(arr[j]) > abs(arr[j + 1])) {
                swapInt(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortPosNeg(int arr[], int n) {
    int temp[n], k = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > 0) temp[k++] = arr[i];
    for (int i = 0; i < k - 1; i++)
        for (int j = 0; j < k - i - 1; j++)
            if (temp[j] < temp[j + 1]) swapInt(temp[j], temp[j + 1]);
    int m = k;
    for (int i = 0; i < n; i++)
        if (arr[i] < 0) temp[m++] = arr[i];
    for (int i = k; i < m - 1; i++)
        for (int j = k; j < m - i + k - 1; j++)
            if (temp[j] > temp[j + 1]) swapInt(temp[j], temp[j + 1]);
    for (int i = 0; i < n; i++) arr[i] = temp[i];
}

void sortEvenOdd(int arr[], int n) {
    int temp[n], k = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0) temp[k++] = arr[i];
    for (int i = 0; i < k - 1; i++)
        for (int j = 0; j < k - i - 1; j++)
            if (temp[j] > temp[j + 1]) swapInt(temp[j], temp[j + 1]);
    int m = k;
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 != 0) temp[m++] = arr[i];
    for (int i = k; i < m - 1; i++)
        for (int j = k; j < m - i + k - 1; j++)
            if (temp[j] < temp[j + 1]) swapInt(temp[j], temp[j + 1]);
    for (int i = 0; i < n; i++) arr[i] = temp[i];
}

struct SinhVien {
    int MSSV;
    char hoten[50];
    int namsinh;
};

void swapSV(SinhVien &a, SinhVien &b) {
    SinhVien t = a;
    a = b;
    b = t;
}

void sortMSSV(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (sv[j].MSSV > sv[j + 1].MSSV) swapSV(sv[j], sv[j + 1]);
}

void sortNameYear(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(sv[j].hoten, sv[j + 1].hoten) > 0) {
                swapSV(sv[j], sv[j + 1]);
            } else if (strcmp(sv[j].hoten, sv[j + 1].hoten) == 0 &&
                       sv[j].namsinh > sv[j + 1].namsinh) {
                swapSV(sv[j], sv[j + 1]);
            }
        }
    }
}

int main() {
    int A[] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Day ban dau: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    sortAsc(A, n);
    cout << "Sap xep tang dan: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    cout << "So lon thu 3: " << A[n - 3] << "\n";

    int maxVal = A[n - 1], countMax = 0;
    for (int i = 0; i < n; i++) if (A[i] == maxVal) countMax++;
    cout << "So luong phan tu lon nhat: " << countMax << "\n";

    sortAbsAsc(A, n);
    cout << "Sap xep theo tri tuyet doi tang dan: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    sortPosNeg(A, n);
    cout << "Sap xep duong giam, am tang: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    sortEvenOdd(A, n);
    cout << "Sap xep chan tang, le giam: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    SinhVien sv[5] = {
        {1005, "Tran Minh Thanh", 1991},
        {1001, "Tran Thi Bich", 1988},
        {1003, "Tran Minh Thanh", 1990},
        {1000, "Vo Quang Vinh", 1990},
        {1008, "Nguyen Van An", 1990}
    };

    cout << "\nDanh sach SV ban dau:\n";
    for (int i = 0; i < 5; i++)
        cout << sv[i].MSSV << " - " << sv[i].hoten << " - " << sv[i].namsinh << "\n";
        
    sortMSSV(sv, 5);
    cout << "\nSap xep theo MSSV tang dan:\n";
    for (int i = 0; i < 5; i++)
        cout << sv[i].MSSV << " - " << sv[i].hoten << " - " << sv[i].namsinh << "\n";

    sortNameYear(sv, 5);
    cout << "\nSap xep theo ten + nam sinh:\n";
    for (int i = 0; i < 5; i++)
        cout << sv[i].MSSV << " - " << sv[i].hoten << " - " << sv[i].namsinh << "\n";

    return 0;
}
