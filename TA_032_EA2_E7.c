#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char w[] = "lv";
char wi[] = "vlvl";
char i[] = {'1', '9', '0', '9', '3', '9', '4'};
char j2[] = "arturoarturo";
char alfabeto[] = {'a', 'l', 'o', 'r', 't', 'u', 'v', '0', '1', '3', '4', '9'};
char validacion(char cadena[]);
char insi_Alfabet(char cadena[]);
char digitos(char cadena[]);
char inicialApp(char cadena[]);
char inicialInvApp(char cadena[]);
char espacios(char cadena[]);
char repetir(); 


//validación inicial que la cadena sea mayor o igual a 32.
//que no se ingrese letras mayúsculas y sin acentos

int main(int argc, char const *argv[])
{
    char cadenaI[' '];
    char valid = 'N';
    do{

        printf("Cadena: ");
        gets(cadenaI);
        fflush(stdin);
        strlwr(cadenaI);

        
        if(strlen(cadenaI) < 32){

            printf("\n\tCadena inv%clida. Favor de ingresar una cadena minima de 32 caracteres.\n\n", 160);
            valid = repetir();

        }else{

            valid = validacion(cadenaI);

            if(valid == 'S'){

                printf("\n\tCadena inv%clida.\n", 160);
                valid = repetir(); 
            
            } else{

                printf("\n\tCadena v%clida.\n", 160);
                valid = repetir();

            }

        }

    } while (valid == 'S');

    return 0;
}

char validacion(char cadena[]){

    if(espacios(cadena) == 'S')
        return 'S';
    else
        if(insi_Alfabet(cadena) == 'S')
            return 'S';
        else
            if(digitos(cadena) == 'S')
                return 'S';
            else 
                return 'N';

}

char insi_Alfabet(char cadena[]){

    int aux1;
    for (int n = 0; n < strlen(cadena); n++){

        aux1 = 0;
        for (int j = 0; j < 12; j++){
            
            if (cadena[n] == alfabeto[j]){

                if (n == strlen(cadena) - 1)
                    return 'N';
                else
                    break;

            }else{

                if (aux1 == 11)
                    return 'S';

            }
            aux1++;

        }

    }

}

char digitos(char cadena[]){

    char *token = strtok(cadena, w);
    if(strlen(token) > 7){

        return 'S';

    }else{

        for(int n = 0; n < 7; n++){

            // printf("%c        %c\n", token[n], i[n]);
            // system("pause");
            if(token[n] == i[n]){

                if(n == 6)
                    return 'N';

            }else{

                if(n != 6)
                return 'S';

            }

        }

    }

}


char espacios(char cadena[]){

    int i = 0;
    int longC = strlen(cadena);

    for(i = 0; i < longC; i++){

        if(cadena[i] == (char)32){
    
            return 'S';
            break;

        } else {

            if(i == longC -1)
                return 'N';

        }

    }

}

char repetir(){

    int aux;
    do{

        printf("\t\t\t\t%cQuiere ingresar otra cadena%c\t(1. S%c/2. No)\n\t\t\t>", 168, 63, 161);
        scanf("%d", &aux);
        fflush(stdin);

    }while(aux < 1 || aux > 2);
    if(aux == 1)
        return 'S';
    else
        return 'N';

}