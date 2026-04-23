#include <stdio.h>
#include <string.h>
#include "rfc_parser.h"

int main() {
    char kullanici_girdisi[100];

    printf("--- RFC 9213 Oncelik Hesaplayici ---\n");
    printf("Lutfen bir header metni girin (Ornek: u=5, i): ");

    // Kullanicidan satirin tamamini alir
    fgets(kullanici_girdisi, sizeof(kullanici_girdisi), stdin);

    // Satir sonundaki '\n' karakterini temizleyelim
    kullanici_girdisi[strcspn(kullanici_girdisi, "\n")] = 0;

    // Senin yazdigin fonksiyona bu girdiyi gonderiyoruz
    int sonuc = parse_priority(kullanici_girdisi);

    printf("\n-----------------------------------\n");
    printf("Girilen Metin: %s\n", kullanici_girdisi);
    printf("Hesaplanan Oncelik Degeri: %d\n", sonuc);
    printf("-----------------------------------\n");

    return 0;
}