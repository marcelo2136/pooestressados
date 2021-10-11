#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <ctime>

//BLOCO I
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


//BLOCO II
//Operações de Filtragem
//Retorna um novo vetor copiando os valores do vetor de entrada
std::vector<int> clonador(const std::vector<int>& vet){
    std::vector<int> clonado{};

    for (int i = 0; i < (int) vet.size(); i++){
        clonado.push_back(vet[i]);
    }

    return clonado;
}

//Retorna uma lista com os homens (valores positivos)
std::vector<int> retorna_homens(const std::vector<int>& vet){
    std::vector<int> men{};

    for (int i = 0; i < (int) vet.size(); i++){
        if (vet[i] > 0)
        men.push_back(vet[i]);
    }

    return men;
}

//Retorna uma lista com as pessoas com stress menor que 10 (abs)
std::vector<int> retorna_calmos(const std::vector<int>& vet){
    std::vector<int> calmos{};

    for (int i = 0; i < (int) vet.size(); i++){
        if (std::fabs(vet[i]) < 10){
            calmos.push_back(vet[i]);
        }
    }

    return calmos;
}

//Retorna uma lista com as mulheres com nível de stress menor que 10
std::vector<int> retorna_mulheres_calmas(const std::vector<int>& vet){
    std::vector<int> women{};

    for (int i = 0; i < (int) vet.size(); i++){
        if (vet[i] > -10 && vet[i] < 0)
        women.push_back(vet[i]);
    }

    return women;
}

//Funções de acesso
//Retorna um novo vetor com os dados invertidos
std::vector<int> inversor_copia(const std::vector<int>& vet){
    std::vector<int> invertido{};

    for (int i = (int) vet.size()-1; i >= 0; i--){
        invertido.push_back(vet[i]);
    }

    return invertido;
}

//Inverte os valores do vetor de entrada sem uso de vetor auxiliar
void inversor_inplace(std::vector<int>& vet){
    int aux{};
    int a{};

    a = (int) vet.size();
    for (int i = 0; i <= (int) vet.size()/2; i++){
        a--;
        aux = vet[i];
        vet[i] = vet[a];
        vet[a] = aux;
    }
}

//Retorna aleatoriamente um elemento do vetor
int sorteio(const std::vector<int>& vet){
    int sorteado{};

    srand (time(NULL));

    sorteado = vet[rand() % (int)vet.size()];

    return sorteado;
}

//Embaralha o vetor original
void embaralhar(std::vector<int>& vet){
    int aux{};
    int a{};
    int b{};
    const int changes {10};
    
    srand (time(NULL));

    for (int i = 0; i <= changes; i++){
        a = rand() % (int) vet.size();
        b = rand() % (int) vet.size();
        aux = vet[b];
        vet[b] = vet[a];
        vet[a] = aux;
    }
}

//Ordena o vetor original (utilizando selection sort)
void ordenar(std::vector<int>& vet){
    int menor{};
    int men_i{};



    for (int i = 0; i < (int) vet.size(); i++){
        for (int j = i; j < (int) vet.size(); j++){
            if (vet[i] > vet[j]){
                menor = vet[j];
                men_i = j;
                vet[men_i] = vet[i];
              vet[i] = menor;
            }
        }

    }
}

//Funções de conjuntos
//Retorna uma lista dos valores do vetor sem repetição
std::vector<int> exclusivo(std::vector<int>& vet){
    std::vector<int> v_igual;
    int num_igual {0};

    for (int i = 0; i < (int) vet.size(); i++){
        for (int j = 0; j < (int) vet.size(); j++){
            if(vet[i] == vet[j]){
                num_igual++;
                if(i == j && num_igual < 2){
                    v_igual.push_back(vet[i]);
                }
            }
        }
    num_igual = 0;
    }

    return v_igual;
}

//Retorna uma lista dos diferentes níveis de stress
std::vector<int> diferentes(std::vector<int>& vet){
    std::vector<int> v_igual;
    std::vector<int> vet2;
    int num_igual {0};

    for (int i = 0; i < (int) vet.size(); i++){
        vet2.push_back(std::fabs(vet[i]));
    }

    for (int i = 0; i < (int) vet2.size(); i++){
        for (int j = 0; j < (int) vet2.size(); j++){
            if(vet2[i] == vet2[j]){
                num_igual++;
                if(i == j && num_igual < 2){
                    v_igual.push_back(vet2[i]);
                }
            }
        }
    num_igual = 0;
    }

    return v_igual;
}

//Remove um exemplar de cada valor
std::vector<int> abandonados(std::vector<int>& vet){
    std::vector<int> v_igual;
    int num_igual {0};

    for (int i = 0; i < (int) vet.size(); i++){
        for (int j = 0; j < (int) vet.size(); j++){
            if(vet[i] == vet[j]){
                num_igual++;
                if(i == j && num_igual > 1){
                    v_igual.push_back(vet[i]);
                }
            }
        }
    num_igual = 0;
    }

    return v_igual;
}


int main() {

    //BLOCO I
    
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



    //BLOCO II
    
    //Vetor de teste
     std::vector<int> vet = {1, -5, -6, 2, -7, -14, 2, 1, -6, -6, 8};
   

    
    //for (auto i : clonador(vet)){
    //   std::cout << i << ' ';
    // }
    // for (auto i : retorna_homens(vet)){
    //    std::cout << i << ' ';
    // }
    // for (auto i : retorna_calmos(vet)){
    //    std::cout << i << ' ';
    // } 
    // for (auto i :  retorna_mulheres_calmas(vet)){
    //    std::cout << i << ' ';
    // }



    //for (auto i : inversor_copia(vet)){
    //    std::cout << i << ' ';
    //}

    //inversor_inplace(vet);
    //for (auto i : vet){
    //    std::cout << i << ' ';
    //}

    //std::cout << sorteio({1, -1, 4}) << '\n';

    //embaralhar(vet);
    //for (auto i : vet){
    //    std::cout << i << ' ';
    //}

    //ordenar(vet);
    //for (auto i : vet){
    //    std::cout << i << ' ';
    //}

    

    //for (auto i : exclusivo(vet)){
    //    std::cout << i << ' ';
    //}
    
    //for (auto i : diferentes(vet)){
    //    std::cout << i << ' ';
    //}

    //for (auto i : abandonados(vet)){
    //    std::cout << i << ' ';
    //}
    return 0;
}
