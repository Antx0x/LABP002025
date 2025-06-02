#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

//   PRIMUL EXERCITIU
/*
int conver(char numere[]) {
    int i = 0;
    int number = 0;
    while (numere[i] != '\0')
    {
        int cif = numere[i] - '0';
        number = number * 10 + cif;
        i++;

        return number;
    }

int main() {
    char buff[20];
    int suma = 0;

    FILE* fisier;
    errno_t err;

    err = fopen_s(&fisier, "C:/Users/anton/source/repos/Laborator1/Laborator1/in.txt", "r");

    if (err != 0) {
        perror("Eroare la deschiderea fisierului");
        return 1;
    }

    while (fgets(buff, sizeof(buff), fisier) != NULL) {
        int nr = conver(buff);
        suma += nr;
    }

    fclose(fisier);  

    printf("Suma numerelor este: %d\n", suma);

    return 0;
}
*/


// EXERCITIUL 2
/*
void sortare_cuvinte(char* cuvinte[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int lungime1 = strlen(cuvinte[j]);
            int lungime2 = strlen(cuvinte[j + 1]);
             
            if (lungime1 < lungime2 || (lungime1 == lungime2 && strcmp(cuvinte[j], cuvinte[j + 1]) > 0)) 
            {    
                char* temp = cuvinte[j];
                cuvinte[j] = cuvinte[j + 1];
                cuvinte[j + 1] = temp;
            }
        }
    }
}

int main() {

    char str[100];
    fgets(str, 100, stdin);
    char* words[100];
    char* context;

    int i = 0;
    char* cuvant = strtok_s(str, " ", &context);
    while (cuvant != NULL && i < 100) {
        words[i] = cuvant;  
        i++;
        cuvant = strtok_s(NULL, " ", &context);
    }

    sortare_cuvinte(words, i);
 
    printf("Cuvintele sortate dupa lungime (descrescator), apoi alfabetic:\n");
    for (int k = 0; k < i; k++) {
        printf("%s\n", words[k]);
    }
    return 0;
}
*/

//  EXERCITIUL 3

bool isPrime(int n)
{
    if (n < 2) return false; 

    for (int tr = 2; tr <= n / 2; tr++)  
        if ((n % tr) == 0)               
            return false;                

    return true; 
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n; 

    if (isPrime(n))
        std::cout << n << " is prime!";
    else
        std::cout << n << " is NOT prime!";

    return 0;
}
