#include <stdio.h>
#include <stdlib.h>

void copyFile(const char *source, const char *destination) {
    FILE *sourceFile, *destinationFile;
    char ch;

    // 소스 파일 열기
    sourceFile = fopen(source, "rb");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // 대상 파일 열기 (없으면 생성)
    destinationFile = fopen(destination, "wb");
    if (destinationFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        exit(EXIT_FAILURE);
    }

    // 파일 복사
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    // 파일 닫기
    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *source = argv[1];
    const char *destination = argv[2];

    copyFile(source, destination);

    return 0;
}
