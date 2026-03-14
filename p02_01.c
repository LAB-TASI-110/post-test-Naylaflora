#include <stdio.h>
#include <string.h>

int main() {
    char kodeKota[4];
    char namaKota[20];
    char keterangan[20];
    int ongkosPerKg = 0;
    float beratButet, beratUcok, totalBerat, totalOngkos, diskon = 0;
    int dapatAsuransi = 0;

    printf("=== Sistem Input Otomatis Del-Express ===\n");
    printf("Masukkan Kode Kota (MDN/BLG/JKT/SBY): ");
    scanf("%s", kodeKota);
    printf("Masukkan Berat Paket Butet (kg): ");
    scanf("%f", &beratButet);

    if (strcmp(kodeKota, "MDN") == 0) {
        strcpy(namaKota, "Medan");
        ongkosPerKg = 8000;
        strcpy(keterangan, "Dalam Pulau");
    } else if (strcmp(kodeKota, "BLG") == 0) {
        strcpy(namaKota, "Balige");
        ongkosPerKg = 5000;
        strcpy(keterangan, "Dalam Pulau");
    } else if (strcmp(kodeKota, "JKT") == 0) {
        strcpy(namaKota, "Jakarta");
        ongkosPerKg = 12000;
        strcpy(keterangan, "Luar Pulau");
    } else if (strcmp(kodeKota, "SBY") == 0) {
        strcpy(namaKota, "Surabaya");
        ongkosPerKg = 13000;
        strcpy(keterangan, "Luar Pulau");
    } else {
        printf("Kode kota tidak valid!\n");
        return 1;
    }

    beratUcok = 1.5 * beratButet;
    totalBerat = beratButet + beratUcok;

    totalOngkos = totalBerat * ongkosPerKg;

    if (totalBerat > 10) {
        diskon = 0.10 * totalOngkos;
    }
    
    if (strcmp(keterangan, "Luar Pulau") == 0) {
        dapatAsuransi = 1;
    }

    totalOngkos = totalOngkos - diskon;

    printf("\n==========================================\n");
    printf("        STRUK PEMBAYARAN DEL-EXPRESS      \n");
    printf("==========================================\n");
    printf("Kota Tujuan          : %s\n", namaKota);
    printf("Berat Paket Butet    : %.2f kg\n", beratButet);
    printf("Berat Paket Ucok     : %.2f kg\n", beratUcok);
    printf("Total Berat          : %.2f kg\n", totalBerat);
    printf("------------------------------------------\n");
    printf("Total Ongkos Kirim   : Rp %.2f\n", totalOngkos);
    printf("------------------------------------------\n");
    printf("Informasi Promo yang Diperoleh:\n");
    
    if (diskon > 0) {
        printf("- Selamat! Anda mendapatkan diskon 10%%.\n");
    } else {
        printf("- Tidak ada diskon (Total berat <= 10kg).\n");
    }

    if (dapatAsuransi == 1) {
        printf("- Selamat! Anda mendapatkan Asuransi Gratis.\n");
    } else {
        printf("- Tidak mendapatkan asuransi gratis.\n");
    }
    printf("==========================================\n");

    return 0;
}