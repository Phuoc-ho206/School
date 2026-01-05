#include <iostream>
#include <string>

struct Student {
    std::string name;
    int mssv;
    std::string email;
    std::string phone;
};

int Hash(const std::string& s, int M) {
    if (M == 0) return 0;
    int sum = 0;
    for (char c : s) {
        sum += static_cast<int>(c);    
    }
    return sum % M;
}

// 1
struct Node {
    Student data;
    Node* next;
};

void InitHashChaining(Node** U, int M) {
    Student K[5] = {
        {"Messi", 1, "messi@example.com", "123456789"},
        {"Ronaldo", 3, "ronaldo@example.com", "987654321"},
        {"Rooney", 5, "rooney@example.com", "112233445"},
        {"Drogba", 7, "drogba@example.com", "556677889"},
        {"Xavi", 9, "xavi@example.com", "998877665"}
    };

    for (int i = 0; i < M; ++i) U[i] = nullptr;
    for (int i = 0; i < 5; ++i) {
        int pos = Hash(K[i].name, M);
        Node* newNode = new Node;
        newNode->data = K[i];
        newNode->next = U[pos];
        U[pos] = newNode;
    }
}

void SearchChaining(Node** U, int M, const std::string& name) {
    int pos = Hash(name, M);
    Node* p = U[pos];
    while (p != nullptr) {
        if (p->data.name == name) {
            std::cout << "Thong tin SV: MSSV: " << p->data.mssv << ", Email: " << p->data.email << ", So dien thoai: " << p->data.phone << std::endl;
            return;
        }
        p = p->next;
    }
    std::cout << "Khong tim thay SV nao trong bang bam" << std::endl;
}

// 2
void InitHashLinear(Student* U, int M) {
    Student K[5] = {
        {"Messi", 1, "messi@example.com", "123456789"},
        {"Ronaldo", 3, "ronaldo@example.com", "987654321"},
        {"Rooney", 5, "rooney@example.com", "112233445"},
        {"Drogba", 7, "drogba@example.com", "556677889"},
        {"Xavi", 9, "xavi@example.com", "998877665"}
    };

    for (int i = 0; i < M; ++i) U[i].name = "";
    for (int i = 0; i < 5; ++i) {
        int pos = Hash(K[i].name, M);
        int j = 0;
        while (!U[(pos + j) % M].name.empty()) ++j;
        U[(pos + j) % M] = K[i];
    }
}

void SearchLinear(Student* U, int M, const std::string& name) {
    int pos = Hash(name, M);
    int j = 0;
    while (!U[(pos + j) % M].name.empty()) {
        if (U[(pos + j) % M].name == name) {
            const Student& s = U[(pos + j) % M];
            std::cout << "Thong tin SV: MSSV: " << s.mssv << ", Email: " << s.email << ", So dien thoai: " << s.phone << std::endl;
            return;
        }
        ++j;
        if (j >= M) break;
    }
    std::cout << "Khong tim thay SV nao trong bang bam" << std::endl;
}

// 3
void InitHashQuadratic(Student* U, int M) {
    Student K[5] = {
        {"Messi", 1, "messi@example.com", "123456789"},
        {"Ronaldo", 3, "ronaldo@example.com", "987654321"},
        {"Rooney", 5, "rooney@example.com", "112233445"},
        {"Drogba", 7, "drogba@example.com", "556677889"},
        {"Xavi", 9, "xavi@example.com", "998877665"}
    };

    for (int i = 0; i < M; ++i) U[i].name = "";
    for (int i = 0; i < 5; ++i) {
        int pos = Hash(K[i].name, M);
        int j = 0;
        while (!U[(pos + j * j) % M].name.empty()) ++j;
        U[(pos + j * j) % M] = K[i];
    }
}

void SearchQuadratic(Student* U, int M, const std::string& name) {
    int pos = Hash(name, M);
    int j = 0;
    while (!U[(pos + j * j) % M].name.empty()) {
        if (U[(pos + j * j) % M].name == name) {
            const Student& s = U[(pos + j * j) % M];
            std::cout << "Thong tin SV: MSSV: " << s.mssv << ", Email: " << s.email << ", So dien thoai: " << s.phone << std::endl;
            return;
        }
        ++j;
        if (j >= M) break;
    }
    std::cout << "Khong tim thay SV nao trong bang bam" << std::endl;
}

// 4
int Hash2(const std::string& s, int M) {
    int sum = 0;
    for (char c : s) {
        sum += static_cast<int>(c);
    }
    return 1 + (sum % (M - 1));
}

void InitHashDouble(Student* U, int M) {
    Student K[5] = {
        {"Messi", 1, "messi@example.com", "123456789"},
        {"Ronaldo", 3, "ronaldo@example.com", "987654321"},
        {"Rooney", 5, "rooney@example.com", "112233445"},
        {"Drogba", 7, "drogba@example.com", "556677889"},
        {"Xavi", 9, "xavi@example.com", "998877665"}
    };

    for (int i = 0; i < M; ++i) U[i].name = "";
    for (int i = 0; i < 5; ++i) {
        int pos = Hash(K[i].name, M);
        int step = Hash2(K[i].name, M);
        int j = 0;
        while (!U[(pos + j * step) % M].name.empty()) ++j;
        U[(pos + j * step) % M] = K[i];
    }
}

void SearchDouble(Student* U, int M, const std::string& name) {
    int pos = Hash(name, M);
    int step = Hash2(name, M);
    int j = 0;
    while (!U[(pos + j * step) % M].name.empty()) {
        if (U[(pos + j * step) % M].name == name) {
            const Student& s = U[(pos + j * step) % M];
            std::cout << "Thong tin SV: MSSV: " << s.mssv << ", Email: " << s.email << ", So dien thoai: " << s.phone << std::endl;
            return;
        }
        ++j;
        if (j >= M) break;
    }
    std::cout << "Khong tim thay SV nao trong bang bam" << std::endl;
}

int main() {
    int M = 10;
    std::string name;

    // Chaining
    std::cout << "Phuong phap noi ket (Chaining):" << std::endl;
    Node** U_chaining = new Node*[M];
    InitHashChaining(U_chaining, M);
    std::cout << "Nhap ten SV tim kiem: ";
    std::cin >> name;
    SearchChaining(U_chaining, M, name);

    // Linear Probing
    std::cout << "\nPhuong phap dia chi mo - Do tuyen tinh (Linear Probing):" << std::endl;
    Student* U_linear = new Student[M];
    InitHashLinear(U_linear, M);
    std::cout << "Nhap ten SV tim kiem: ";
    std::cin >> name;
    SearchLinear(U_linear, M, name);

    // Quadratic Probing
    std::cout << "\nPhuong phap dia chi mo - Do bac 2 (Quadratic Probing):" << std::endl;
    Student* U_quadratic = new Student[M];
    InitHashQuadratic(U_quadratic, M);
    std::cout << "Nhap ten SV tim kiem: ";
    std::cin >> name;
    SearchQuadratic(U_quadratic, M, name);

    // Double Hashing
    std::cout << "\nPhuong phap dia chi mo - Bam kep (Double Hashing):" << std::endl;
    Student* U_double = new Student[M];
    InitHashDouble(U_double, M);
    std::cout << "Nhap ten SV tim kiem: ";
    std::cin >> name;
    SearchDouble(U_double, M, name);

    // Note: Memory deallocation omitted for brevity

    return 0;
}