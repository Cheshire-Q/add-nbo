#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){

    FILE *f1, *f2;
    uint32_t data1;
    uint32_t data2;
    uint32_t sum;

    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");

    fread(&data1, sizeof(uint32_t), 1, f1);
    fread(&data2, sizeof(uint32_t), 1, f2);

    sum = ntohl(data1) + ntohl(data2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", ntohl(data1), ntohl(data1), ntohl(data2), ntohl(data2), sum, sum);
    
    fclose(f2);
    fclose(f1);
}
