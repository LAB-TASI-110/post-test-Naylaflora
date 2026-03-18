#include <stdio.h>
#include <string.h>

// Struktur untuk menyimpan data barang
struct Barang {
    int stok;
    char nama[50];
    char kode[3];
};

int main() {
    int N;
    char cariKode[3];

    // 1. Input Jumlah total data (N)
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &N);

    struct Barang daftarBarang[N];

    // 2. Input Deret stok dan detail barang
    for (int i = 0; i < N; i++) {
        printf("\nData ke-%d\n", i + 1);
        printf("Masukkan jumlah stok: ");
        scanf("%d", &daftarBarang[i].stok);
        
        printf("Masukkan kode kategori (my/rp/gl/ds): ");
        scanf("%s", daftarBarang[i].kode);

        // Memberikan nama otomatis berdasarkan kode untuk verifikasi
        if (strcmp(daftarBarang[i].kode, "my") == 0) strcpy(daftarBarang[i].nama, "Minyak");
        else if (strcmp(daftarBarang[i].kode, "rp") == 0) strcpy(daftarBarang[i].nama, "Rok Pramuka");
        else if (strcmp(daftarBarang[i].kode, "gl") == 0) strcpy(daftarBarang[i].nama, "Gula");
        else if (strcmp(daftarBarang[i].kode, "ds") == 0) strcpy(daftarBarang[i].nama, "Dasi SD");
        else strcpy(daftarBarang[i].nama, "Tidak Diketahui");
    }

    // 3. Input Kode kategori yang dicari
    printf("\nMasukkan kode kategori yang ingin ditampilkan (my/rp/gl/ds): ");
    scanf("%s", cariKode);

    // Output hasil filter
    printf("\n--- Hasil Stok Barang ---\n");
    int ditemukan = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(daftarBarang[i].kode, cariKode) == 0) {
            printf("%d pcs %s\n", daftarBarang[i].stok, daftarBarang[i].nama);
            ditemukan = 1;
        }
    }

    if (!ditemukan) {
        printf("Data dengan kode '%s' tidak ditemukan.\n", cariKode);
    }

    return 0;
}