#include <stdio.h>

struct person {
    char name[20] ;
    char last_name[20] ;
    int balance;
};

int main() {
    int feedback;

    struct person igor = {"igor" ,"hyesos" , 0 };
    while(1) {


        printf("\nЧто опять ? \n 1: проверить счета \n 2: метнуть деньги на счет \n 3: спиздить деньги со счета \n 4: сохранить \n 5: загрузить \n 6: выход(без сохранения)");
        scanf("%d", &feedback);
        if (feedback == 1) {
            printf("Name: %s \t Last Name: %s \n Balance: %d", igor.name, igor.last_name, igor.balance);
        }
        if (feedback == 2) {
            printf("Скока добавит ?");
            scanf("%d", &feedback);
            igor.balance += feedback;
        }
        if (feedback == 3) {
            printf("Скока спиздить ?");
            scanf("%d", &feedback);
            igor.balance -= feedback;

        }

        if (feedback == 4){
            FILE* output;

            output = fopen("Data.dat", "wb");

            fwrite(&igor, sizeof(igor), 1, output);

            fclose(output);
        }
        if (feedback == 5){
            FILE* input;

            input = fopen("Data.dat", "rb");

            fread(&igor, sizeof(igor), 1, input);

            fclose(input);
        }
        if (feedback == 6){
            break;
        }


    }

}
