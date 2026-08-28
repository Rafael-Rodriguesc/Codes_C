//cofre digital

#include <stdio.h>

int main() {
    int senha;
    int senhaCorreta = 1234;
    int acertou = 0;

    for (int tentativa = 1; tentativa <= 3; tentativa++) {

        printf("Digite a senha: ");
        scanf("%d", &senha);

        if (senha == senhaCorreta) {
            printf("Acesso permitido!\n");
            acertou = 1;
            break;
        } else {
            printf("Senha incorreta!\n");
            printf("Tentativas restantes: %d\n", 3 - tentativa);
        }
    }

    if (acertou == 0) {
        printf("Cofre bloqueado!\n");
    }

    return 0;
}