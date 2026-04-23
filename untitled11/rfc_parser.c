#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rfc_parser.h"

int parse_priority(const char* header_str) {
    int urgency = 3; // Varsayılan değer

    // "u=" ifadesini arıyoruz
    const char *p = strstr(header_str, "u=");

    if (p != NULL) {
        // "u="dan hemen sonraki sayıyı oku
        // p+2 dememizin sebebi "u=" karakterlerini atlayıp sayıya geçmek
        sscanf(p, "u=%d", &urgency);
    }

    // RFC sınırları: 0 ile 7 arasında olmalı
    if (urgency < 0) urgency = 0;
    if (urgency > 7) urgency = 7;

    return urgency;
}