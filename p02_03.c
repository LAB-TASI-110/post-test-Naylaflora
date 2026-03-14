#include <stdio.h>

int main() {
    // Deklarasi variabel
    char nama[50];
    int jumlahMinuman[5] = {0, 0, 0, 0, 0}; // Teh Manis, BengBeng, Nutrisari, Capucino, Pop Ice
    int jumlahSnack[5] = {0, 0, 0, 0, 0};   // Tahu, Tempe, Bakwan, Risol, Roti Isi Ayam
    int tipeMakan, metodeBayar;
    int hargaSatuan = 5000;
    int totalHarga = 0;

    printf("=== Sistem Kafetaria IT Del ===\n");
    
    // Input Nama
    printf("Masukkan Nama Anda: ");
    scanf("%s", nama);

    // Input Pesanan Minuman
    printf("\n--- Menu Minuman (Semua Rp 5.000) ---\n");
    printf("Berapa Teh Manis? "); scanf("%d", &jumlahMinuman[0]);
    printf("Berapa BengBeng? ");   scanf("%d", &jumlahMinuman[1]);
    printf("Berapa Nutrisari? ");  scanf("%d", &jumlahMinuman[2]);
    printf("Berapa Capucino? ");   scanf("%d", &jumlahMinuman[3]);
    printf("Berapa Pop Ice? ");    scanf("%d", &jumlahMinuman[4]);

    // Input Pesanan Snack
    printf("\n--- Menu Makanan Ringan (Semua Rp 5.000) ---\n");
    printf("Berapa Tahu? ");           scanf("%d", &jumlahSnack[0]);
    printf("Berapa Tempe? ");          scanf("%d", &jumlahSnack[1]);
    printf("Berapa Bakwan? ");         scanf("%d", &jumlahSnack[2]);
    printf("Berapa Risol? ");          scanf("%d", &jumlahSnack[3]);
    printf("Berapa Roti Isi Ayam? ");  scanf("%d", &jumlahSnack[4]);

    // Opsi Makan
    printf("\nTipe Pesanan (1. Take Away, 2. Makan di Sini): ");
    scanf("%d", &tipeMakan);

    // Metode Pembayaran
    printf("Metode Pembayaran (1. Cash, 2. QRIS): ");
    scanf("%d", &metodeBayar);

    // Hitung Total
    for(int i = 0; i < 5; i++) {
        totalHarga += (jumlahMinuman[i] * hargaSatuan);
        totalHarga += (jumlahSnack[i] * hargaSatuan);
    }

    // Output Ringkasan Pesanan
    printf("\n==================================\n");
    printf("        STRUK KAFETARIA IT DEL      \n");
    printf("==================================\n");
    printf("Nama Pelanggan  : %s\n", nama);
    printf("Tipe Pesanan    : %s\n", (tipeMakan == 1) ? "Take Away" : "Makan di Sini");
    printf("Metode Bayar    : %s\n", (metodeBayar == 1) ? "Cash" : "QRIS");
    printf("----------------------------------\n");
    printf("Rincian Pesanan:\n");
    
    // Menampilkan hanya yang dipesan (jumlah > 0)
    if(jumlahMinuman[0] > 0) printf("- Teh Manis (%d)\n", jumlahMinuman[0]);
    if(jumlahMinuman[1] > 0) printf("- BengBeng (%d)\n", jumlahMinuman[1]);
    if(jumlahMinuman[2] > 0) printf("- Nutrisari (%d)\n", jumlahMinuman[2]);
    if(jumlahMinuman[3] > 0) printf("- Capucino (%d)\n", jumlahMinuman[3]);
    if(jumlahMinuman[4] > 0) printf("- Pop Ice (%d)\n", jumlahMinuman[4]);
    
    if(jumlahSnack[0] > 0) printf("- Tahu (%d)\n", jumlahSnack[0]);
    if(jumlahSnack[1] > 0) printf("- Tempe (%d)\n", jumlahSnack[1]);
    if(jumlahSnack[2] > 0) printf("- Bakwan (%d)\n", jumlahSnack[2]);
    if(jumlahSnack[3] > 0) printf("- Risol (%d)\n", jumlahSnack[3]);
    if(jumlahSnack[4] > 0) printf("- Roti Isi Ayam (%d)\n", jumlahSnack[4]);

    printf("----------------------------------\n");
    printf("TOTAL PEMBAYARAN: Rp %d\n", totalHarga);
    printf("==================================\n");

    return 0;
}