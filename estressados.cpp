#include <iostream>
#include <vector>
#include <string>

//FUNÇÕES DE BUSCA
// Função que verifica a existência
bool exist(std::vector<int> vet, int numb){
    bool existe {false};

    for(size_t i = 0; i < vet.size(); i++){
        if(vet[i] == numb){
            existe = true;
        }
    }
    return existe;
}

//Função que verifica a quantidade
int quant(std::vector<int> vet, int numb){
    size_t quantidade {0};

    for(size_t i = 0; i < vet.size(); i++){
        if(vet[i] == numb){
            quantidade++;
        }
    }
    return quantidade;
}

//Função que faz a busca de um valor (retorna a posição)
int proc_valor(std::vector<int> vet, int numb){
    int pos {-1};

    for(size_t i = 0; i < vet.size(); i++){
        if(vet[i] == numb){
            pos = i;
            break;
        }
    }
    return pos;
}

//Função que faz a busca de um valor a partir de determinada posição (retorna a posição)
int proc_valor_por_posicao(std::vector<int> vet, int numb, size_t inicio){
    int pos {-1};

    for(size_t i = inicio; i < vet.size(); i++){
        if(vet[i] == numb){
            pos = i;
            break;
        }
    }
    return pos;
}


//FUNÇÕES DE MELHOR CASO
//Função que procura o menor valor
int menor_valor(std::vector<int> vet){
    int small {0};

    for(size_t i = 0; i < vet.size(); i++){
        if(i == 0){
            small = vet[i];
            }
        if(vet[i] < small && i > 0){
            small = vet[i];
            }
    }
    return small;
}

//Retorna a posição do menor valor
int menor_valor_pos(std::vector<int> vet){
    int small {0};

    
    for(size_t i = 0; i < vet.size(); i++){
        if(i == 0){
            small = i;
            }
        if(vet[i] < vet[small] && i > 0){
            small = i;
            }
    }
    return small;
}

//Retorna posição do menor valor (com posição inicial)
int menor_valor_pos_com_inicio(std::vector<int> vet, size_t inicio){
    int small {0};

    for(size_t i = inicio; i < vet.size(); i++){
        if(i == inicio){
            small = i;
            }
        if(vet[i] < vet[small] && i > 0){
            small = i;
            }
    }
    return small;
}

//Retorna homem mais calmo
int homem_mais_calmo(std::vector<int> vet){
    int small {-1};
    bool man {false};
    
    for(size_t i = 0; i < vet.size(); i++){
        if (vet[i] > 0 && man == false){
            small = i;
            man = true;
        }
        if(vet[i] < vet[small] && vet[i] > 0){
            small = i;
            }
    }
    return small;
}


//FUNÇÕES DE CONTAGEM
//Retorna Estresse médio
float stress_medio(std::vector<int> vet){
    float media {0};

    
    for(size_t i = 0; i < vet.size(); i++){
            media += vet[i];
    }

    media /= vet.size();
    return media;
}

//Mais homens ou mulheres?
std::string quem_e_mais(std::vector<int> vet){
    int menQuant {0};
    int womenQuant {0};
    
    for(size_t i = 0; i < vet.size(); i++){
        if (vet[i] > 0){
            menQuant++;
        }
        if (vet[i] < 0){
            womenQuant++;
        }
    }

    if (menQuant > womenQuant){
        return "homens";
    }
    else if (womenQuant > menQuant){
        return "mulheres";
    }
    else{
        return "empate";
    }

}

//Qual metade é a mais estressada?
std::string metade_mais_estresse(std::vector<int> vet){
    float half1 {0};
    float half2 {0};
    
    if (vet.size()%2 != 0){
        return "O numero de elementos do vetor e impar";
    }
    else{

        for(size_t i = 0; i < vet.size(); i++){
            if (i <= vet.size()/2){
                half1 += vet[i];
            }
            if (i > vet.size()/2){
                half2 += vet[i];
            }
        }

        if (half1/vet.size()/2 > half2/vet.size()/2){
            return "primeira";
        }
        else if (half1/vet.size()/2 < half2/vet.size()/2){
            return "segunda";
        }
        else{
            return "empate";
        }
    }
}

//Os homens estão mais estressados que as mulheres?
std::string homens_mais_estressados_q_mulheres(std::vector<int> vet){
    float men {0};
    int menquant {0};
    float women {0};
    int womenquant {0};
    
        for(size_t i = 0; i < vet.size(); i++){
            if (vet[i] > 0){
                men += vet[i];
                menquant++;
            }
            if (vet[i] < 0){
                women += vet[i];
                womenquant++;
            }
        }

        if (men/menquant > (women/womenquant)*-1){
            return "sim";
        }
        else{
            return "nao";
        }
}

int main() {

    //std::cout << exist({-1, 1, 2}, 2) << '\n';
    //std::cout << quant({-1, 1, 2}, 2) << '\n';
    //std::cout << proc_valor({-1, 1, 2, 3}, 1) << '\n';
    //std::cout << proc_valor_por_posicao({-1, 1, 2}, 1, 0) << '\n';

    //std::cout << menor_valor({-1, -3, 1, -12}) << '\n';
    //std::cout << menor_valor_pos({-1, -10, 1, -12}) << '\n';
    //std::cout << menor_valor_pos_com_inicio({-1, -99, 1, -12}, 0) << '\n';
    //std::cout << homem_mais_calmo({-1, 3, 14, -12}) << '\n';
    
    //std::cout << stress_medio({1, 2}) << '\n';
    //std::cout << quem_e_mais({1, 0, -1}) << '\n';
    //std::cout << metade_mais_estresse({1, 2, 1}) << '\n';
    //std::cout << homens_mais_estressados_q_mulheres({1, -1, 4}) << '\n';

    return 0;
}
