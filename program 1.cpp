#include <stdio.h>
#include <string.h>
void caesarEncrypt(char plaintext[], int shift) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = ((plaintext[i] - 'A') + shift) % 26 + 'A';
        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = ((plaintext[i] - 'a') + shift) % 26 + 'a';
        }
    }
}
void caesarDecrypt(char ciphertext[], int shift) {
    caesarEncrypt(ciphertext, -shift);
}
int main() {
    char plaintext[100], ciphertext[100];
    int shift;
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    strcpy(ciphertext, plaintext);
    caesarEncrypt(ciphertext, shift);
    printf("Encrypted text: %s\n", ciphertext);
    caesarDecrypt(ciphertext, shift);
    printf("Decrypted text: %s\n", ciphertext);

    return 0;
}
