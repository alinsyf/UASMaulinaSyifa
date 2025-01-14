#include <iostream>
#include <vector>
#include <string>


struct Order {
    int orderID;              // ID pesanan
    std::string pickupLocation; // Lokasi pengambilan
    std::string dropoffLocation; // Lokasi tujuan
    std::string deliveryTime;    // Waktu pengiriman

    // Operator untuk membandingkan dua pesanan berdasarkan waktu pengiriman
    bool operator<(const Order& other) const {
        return deliveryTime < other.deliveryTime; 
    }
};

void merge(std::vector<Order>& orders, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;    

    
    std::vector<Order> L(n1);
    std::vector<Order> R(n2);


    for (int i = 0; i < n1; i++)
        L[i] = orders[left + i]; 
    for (int j = 0; j < n2; j++)
        R[j] = orders[mid + 1 + j]; 

    int i = 0, j = 0, k = left;

    
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            orders[k] = L[i]; 
            i++;
        } else {
            orders[k] = R[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        orders[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        orders[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Order>& orders, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; 

        
        mergeSort(orders, left, mid);
        mergeSort(orders, mid + 1, right);
        merge(orders, left, mid, right); 
    }
}

int main() {
    std::cout << "Nama: [Maulina Syifa Miranti]\n"; 
    std::cout << "NIM: [241011400833]\n";   
    std::cout << std::endl;

    std::vector<Order> orders; 

    // Menambahkan data pesanan ke dalam vektor
    orders.push_back({1, "Location A", "Location B", "2023-10-02 10:30:00"});
    orders.push_back({2, "Location C", "Location D", "2023-10-01 09:15:00"});
    orders.push_back({3, "Location E", "Location F", "2023-10-02 08:45:00"});
    orders.push_back({4, "Location G", "Location H", "2023-10-01 14:00:00"});
    orders.push_back({5, "Location I", "Location J", "2023-10-02 12:00:00"});

    // Menampilkan pesanan sebelum diurutkan
    std::cout << "Pesanan sebelum diurutkan:\n";
    for (size_t i = 0; i < orders.size(); i++) {
        std::cout << "ID: " << orders[i].orderID << ", Waktu: " << orders[i].deliveryTime << "\n";
    }

    // Mengurutkan pesanan
    mergeSort(orders, 0, orders.size() - 1);

    // Menampilkan pesanan setelah diurut
    std::cout << "\nPesanan setelah diurutkan berdasarkan waktu pengiriman:\n";
    for (size_t i = 0; i < orders.size(); i++) {
        std::cout << "ID: " << orders[i].orderID << ", Waktu: " << orders[i].deliveryTime << "\n";
    }

    return 0;
}
