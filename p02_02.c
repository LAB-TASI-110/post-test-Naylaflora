#include <stdio.h>
#include <string.h>

typedef struct {
    int jumlah;
    char kode[3];
} Barang;

int main() {
    int N;
    char target[3];

    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &N);

    Barang gudang[N];

    printf("Masukkan data (jumlah kode):\n");
    for (int i = 0; i < N; i++) {
        scanf("%d %s", &gudang[i].jumlah, gudang[i].kode);
    }

    printf("\nMasukkan kode kategori yang dicari (my/rp/gl/ds): ");
    scanf("%s", target);

    int ditemukan = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(gudang[i].kode, target) == 0) {
            printf("Stok untuk kategori '%s' adalah: %d pcs\n", target, gudang[i].jumlah);
            ditemukan = 1;
            break; 
        }
    }

    if (!ditemukan) {
        printf("Data dengan kode '%s' tidak ditemukan.\n", target);
    }

    return 0;
}