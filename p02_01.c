#include <stdio.h>
#include <string.h>

int main() {
    char kode[4], namaKota[20], keterangan[20], infoPromo[50];
    float beratButet, beratUcok, totalBerat, ongkosPerKg, totalOngkos, diskon = 0;

    printf("=== Sistem Input DEL-EXPRESS ===\n");
    printf("Masukkan Kode Kota (MDN/BLG/JKT/SBY): ");
    scanf("%s", kode);
    printf("Masukkan Berat Paket Butet (kg): ");
    scanf("%f", &beratButet);

    // Tentukan data berdasarkan Kode Kota
    if (strcmp(kode, "MDN") == 0) {
        strcpy(namaKota, "Medan");
        ongkosPerKg = 8000;
        strcpy(keterangan, "Dalam Pulau");
    } else if (strcmp(kode, "BLG") == 0) {
        strcpy(namaKota, "Balige");
        ongkosPerKg = 5000;
        strcpy(keterangan, "Dalam Pulau");
    } else if (strcmp(kode, "JKT") == 0) {
        strcpy(namaKota, "Jakarta");
        ongkosPerKg = 12000;
        strcpy(keterangan, "Luar Pulau");
    } else if (strcmp(kode, "SBY") == 0) {
        strcpy(namaKota, "Surabaya");
        ongkosPerKg = 13000;
        strcpy(keterangan, "Luar Pulau");
    } else {
        printf("Kode Kota tidak valid!\n");
        return 1;
    }

    // Perhitungan Berat sesuai Gambar 3 (Ucok = 3/2 * Butet)
    beratUcok = 1.5 * beratButet;
    totalBerat = beratButet + beratUcok;
    totalOngkos = totalBerat * ongkosPerKg;

    // Cek Promo sesuai Gambar 2
    if (totalBerat > 10 && strcmp(keterangan, "Luar Pulau") == 0) {
        diskon = 0.10 * totalOngkos;
        totalOngkos -= diskon;
        strcpy(infoPromo, "Diskon 10% & Asuransi Gratis");
    } else {
        strcpy(infoPromo, "Tidak Mendapatkan Promo");
    }

    // Output Struk Pembayaran
    printf("\n==================================\n");
    printf("      STRUK PEMBAYARAN DEL-EXPRESS  \n");
    printf("==================================\n");
    printf("Kota Tujuan         : %s (%s)\n", namaKota, keterangan);
    printf("Berat Paket Butet   : %.2f kg\n", beratButet);
    printf("Berat Paket Ucok    : %.2f kg\n", beratUcok);
    printf("Total Berat         : %.2f kg\n", totalBerat);
    printf("----------------------------------\n");
    printf("Informasi Promo     : %s\n", infoPromo);
    printf("TOTAL ONGKOS KIRIM  : Rp %.2f\n", totalOngkos);
    printf("==================================\n");

    return 0;
}