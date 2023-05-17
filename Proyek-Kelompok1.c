#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int banyakArgumen, char *argumen[])
{
    if (banyakArgumen == 1)
    {
        // Menampilkan petunjuk cara penggunaan program
        printf("\n+==========================================+");
        printf("\n|  SELAMAT DATANG DIMENU UTAMA GAME INI    |");
        printf("\n+==========================================+");
        printf("\n\nSILAHKAN MELAKUKAN REGRISTRASI TERLEBIH DAHULU: \n");
        printf("Dengan Cara Registrasi: ./Program reg\n");
        printf("\nJIKA ANDA TELAH MEMPUNYAI AKUN SILAHKAN LOGIN\n");
        printf("Dengan Cara Login: ./Program username(spasi)password\n\n");
        return EXIT_SUCCESS;
    }
    else if (strcmp(argumen[1], "reg") == 0)
    {
        // Bagian Registrasi
        printf("\n+==========================================+");
        printf("\n|               Registrasi                 |");
        printf("\n+==========================================+");
        printf("\n| Silahkan masukkan username dan password  |");
        printf("\n|  Dengan format username(spasi)password   |");
        printf("\n+==========================================+");
        printf("\n\nMasukkan username dan password Anda: ");
        
        // Membaca input username dan password
        char namepass[50];
        scanf("%[^\n]s", namepass);
        getchar();
        
        // Membuka file Login.bin untuk menulis username dan password
        FILE *fptr;
        fptr = fopen("Login.bin", "wb");
        
        // Menulis username dan password ke dalam file jika input tidak kosong
        if (namepass != '\0')
        {
            fwrite(namepass, sizeof(char), sizeof(namepass) / sizeof(char), fptr);
        }

        fclose(fptr);
                      
        // Memisahkan string input menjadi username dan password
        char *string[3];
        char username[30], password[20];
        int ctrl = 0;

        string[0] = strtok(namepass, " ");
        while (string[ctrl++] != NULL)
        {
            string[ctrl] = strtok(NULL, " ");
        }
        
        strcpy(username, string[0]);
        strcpy(password, string[1]);
        
        // Menampilkan username dan password yang telah diinput di atas
        printf("Username: %s\nPassword: %s\n", username, password);
        printf("\n+==========================================+");
        printf("\n|           Registrasi Berhasil            |");
        printf("\n+==========================================+");
        return EXIT_SUCCESS;
    }
    else if (banyakArgumen == 3)
    {
        // Bagian login
        char usernameInput[30], passwordInput[20];
        strcpy(usernameInput, argumen[1]);
        strcpy(passwordInput, argumen[2]);
    
        // Membuka file Login.bin untuk membaca username dan password
        FILE *fptr;

        if ((fptr = fopen("Login.bin", "rb")) == NULL)
        {
            printf("Gagal membuka file!");
            return EXIT_FAILURE;
        }
    
        // Memisahkan string dan password yang ada di file
        char namepass[50];
        fread(namepass, sizeof(char), sizeof(namepass) / sizeof(char), fptr);

        char *string[3];
        char username[30], password[20];
        int ctrl = 0;

        string[0] = strtok(namepass, " ");
        while (string[ctrl++] != NULL)
        {
            string[ctrl] = strtok(NULL, " ");
        }
    
        // Menyalin nilai string ke variabel username dan password
        strcpy(username, string[0]);
        strcpy(password, string[1]);
    
        // Mengecek apakah usernameInput dan passwordInput sama dengan dalam file
        if ((strcmp(usernameInput, username) == 0) && (strcmp(passwordInput, password) == 0))
        {
                        printf("Selamat, Anda berhasil login!\n");
        }
        else
        {
            printf("Anda gagal login!\n");
            printf("Username atau password yang Anda masukkan salah atau tidak terdaftar\n");
            printf("Silakan periksa kembali username dan password Anda atau registrasi terlebih dahulu untuk membuat akun\n");
            return EXIT_FAILURE;
        }
        // Menutup file Login.bin    
        fclose(fptr);
    }
    else
    {
        printf("Argumen yang dimasukkan tidak valid. Silakan periksa kembali cara penggunaan program.\n");
        return EXIT_FAILURE;
    }
    char jawaban;
    int benar = 0;

    // Pertanyaan 1
    printf("1. Apa ibukota negara Indonesia?\n");
    printf("A. Jakarta\n");
    printf("B. Bandung\n");
    printf("C. Surabaya\n");
    printf("D. Yogyakarta\n");

    printf("Masukkan jawaban: ");
    scanf(" %c", &jawaban);

    if (jawaban == 'A' || jawaban == 'a') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 2
    printf("\n2. Siapakah penemu telepon?\n");
    printf("A. Alexander Graham Bell\n");
    printf("B. Thomas Edison\n");
    printf("C. Nikola Tesla\n");
    printf("D. Isaac Newton\n");

    printf("Masukkan jawaban: ");
    scanf(" %c", &jawaban);

    if (jawaban == 'A' || jawaban == 'a') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 3
    printf("\n3. Apa warna dasar dalam model warna RGB?\n");
    printf("A. Merah\n");
    printf("B. Hijau\n");
    printf("C. Biru\n");
    printf("D. Kuning\n");

    printf("Masukkan jawaban: ");
    scanf(" %c", &jawaban);

    if (jawaban == 'C' || jawaban == 'c') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 4
    printf("\n4. Berapa jumlah planet dalam Tata Surya?\n");
    printf("A. 7\n");
    printf("B. 8\n");
    printf("C. 9\n");
    printf("D. 10\n");

    printf("Masukkan jawaban: ");
    scanf(" %c", &jawaban);

    if (jawaban == 'B' || jawaban == 'b') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Pertanyaan 5
    printf("\n5. Apa nama ilmuwan terkenal yang merumuskan teori relativitas?\n");
    printf("A. Albert Einstein\n");
    printf("B. Isaac Newton\n");
    printf("C. Galileo Galilei\n");
    printf("D. Charles Darwin\n");

    printf("Masukkan jawaban: ");
    scanf(" %c", &jawaban);

    if (jawaban == 'A' || jawaban == 'a') {
        printf("Jawaban Anda benar!\n");
        benar++;
    } else {
        printf("Jawaban Anda salah.\n");
    }

    // Hasil
    printf("\nAnda berhasil menjawab %d dari 5 pertanyaan.\n", benar);

    return 0;
}
