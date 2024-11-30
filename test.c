#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[1024];

    // Lire la sortie du script shell transmise via le pipe
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        printf("Message reçu : %s", buffer);
    }

    return 0;
}