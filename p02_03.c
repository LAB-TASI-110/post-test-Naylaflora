#include <stdio.h>
#include <string.h>

int main() {
    char namaPelanggan[50];
    int pilihan, jumlah, totalHarga = 0;
    int pilihanLayanan, pilihanPembayaran;
    char lanjut;

    printf("=== SISTEM KASIR KAFETARIA IT DEL ===\n");
    printf("Masukkan Nama Pelanggan: ");
    fgets(namaPelanggan, sizeof(namaPelanggan), stdin);
    namaPelanggan[strcspn(namaPelanggan, "\n")] = 0;

    // Perulangan untuk memesan minuman dan makanan
    do {
        printf("\n--- MENU KAFETARIA ---\n");
        printf("[MINUMAN]\n");
        printf("1. Taro Latte   (17.000)  4. Kentang Goreng (15.000)\n");
        printf("2. Brown Sugar  (19.000)  5. Donat          (18.000)\n");
        printf("3. Matcha Latte (17.000)  6. Dimsum         (21.000)\n");
        printf("                          7. Burger         (17.000)\n");
        printf("                          8. Pizza          (35.000)\n");
        
        printf("\nPilih Nomor Menu: ");
        scanf("%d", &pilihan);
        printf("Masukkan Jumlah: ");
        scanf("%d", &jumlah);

        // Logika penentuan harga
        int hargaSatuan = 0;
        switch(pilihan) {
            case 1: hargaSatuan = 17000; break;
            case 2: hargaSatuan = 19000; break;
            case 3: hargaSatuan = 17000; break;
            case 4: hargaSatuan = 15000; break;
            case 5: hargaSatuan = 18000; break;
            case 6: hargaSatuan = 21000; break;
            case 7: hargaSatuan = 17000; break;
            case 8: hargaSatuan = 35000; break;
            default: printf("Pilihan tidak valid!\n");
        }

        totalHarga += (hargaSatuan * jumlah);

        printf("Tambah pesanan lagi? (y/n): ");
        scanf(" %c", &lanjut); // Spasi sebelum %c untuk membersihkan buffer

    } while (lanjut == 'y' || lanjut == 'Y');

    // Pilihan Layanan
    printf("\n--- METODE LAYANAN ---\n");
    printf("1. Take Away\n2. Makan Di Sini\nPilih: ");
    scanf("%d", &pilihanLayanan);

    // Pilihan Pembayaran
    printf("\n--- METODE PEMBAYARAN ---\n");
    printf("1. Cash\n2. QRIS\nPilih: ");
    scanf("%d", &pilihanPembayaran);

    // Output Ringkasan
    printf("\n======================================\n");
    printf("         STRUK AKHIR KAFETARIA         \n");
    printf("======================================\n");
    printf("Nama Pelanggan  : %s\n", namaPelanggan);
    printf("Metode Layanan  : %s\n", (pilihanLayanan == 1) ? "Take Away" : "Makan Di Sini");
    printf("Metode Bayar    : %s\n", (pilihanPembayaran == 1) ? "Cash" : "QRIS");
    printf("--------------------------------------\n");
    printf("TOTAL PEMBAYARAN: Rp %d\n", totalHarga);
    printf("======================================\n");

    return 0;
}