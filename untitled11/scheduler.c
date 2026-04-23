#include <stdio.h>
#include "rfc_parser.h" // Header dosyasını eklemeyi unutma!

void process_requests() {
    const char* ornek_header = "u=5, i";

    // rfc_parser.c içindeki fonksiyonu burada çağırıyoruz
    int priority = parse_priority(ornek_header);

    printf("Belirlenen Oncelik: %d\n", priority);
    // ... diğer işlemler ...
}