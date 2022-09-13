#include "../include/Dados.h"

#include <iostream>     // std::cout
#include <algorithm>    // std::sort


//////////////////////////////////
/// CONSTRUTORES E DESTRUTORES ///
//////////////////////////////////

Dados::Dados()
{
    //construtor

    // Inicializa gerador de numeros aleatorios (da biblioteca random)
    std::random_device r;
    gerador = new std::default_random_engine(r());

}

Dados::~Dados()
{
    // destrutor

    delete(gerador);
}

////////////////////////////////////
/// METODOS DE ORDENACAO - LAB 2 ///
////////////////////////////////////

int Dados::particione(int pi, int pf)
{
    // TODO: implementar funcao de particionamento
    // do subarray que vai da posicao inicial pi até posicao final pf
    // e que apos particionar os dados, retorna a posicao do pivo

    int pivo, i, j, p;
    i = pi + 1;
    j = pf;     //poiscao final do elemento

//=================================================================================================
//----------------------------------------------------------
//Descomente para rodar o programa com o pivo sempre no primeiro elemento do vetor
//e comente o pivo aleatorio


//    p = pi;                                                           //PIVO INICIAL

//----------------------------------------------------------
//Descomente para rodar o programa com pivo aleatório
//e comente o pivo fixo

    std::uniform_int_distribution<int> numero_aleatorio(pi,pf);
    int r = numero_aleatorio(*gerador);
    p = r;                                                              //PIVO ALEATORIO
    troca(registros[p], registros[pi]);
    p = pi;

//----------------------------------------------------------
//=================================================================================================


    while(j > i){
        while(registros[i] <= registros[p] && i < pf){
            i++;
            estatisticasTotais.comparacoes++;
        }

        while(registros[j] > registros[p] && j > pi){
            j--;
            estatisticasTotais.comparacoes++;
        }

        if(i < j && registros[i] > registros[j]){       //troca (C[i], C[j])
            troca(registros[i], registros[j]);
            estatisticasTotais.trocas++;
        }

        estatisticasTotais.comparacoes+=3;
    }

    if(registros[j] < registros[p]){
        troca(registros[j], registros[p]);
        estatisticasTotais.trocas++;
    }

        estatisticasTotais.comparacoes++;

    pivo = j;


    return pivo;
}

void Dados::quickSort(int i, int f)
{
    // TODO: implementar funcao recursiva de quicksort que chama particionamento

    int p;     //posicao de pivo

    if(f > i){
        p = particione(i, f);
        quickSort(i, p - 1);
        quickSort(p + 1, f);
    }
}

Estatisticas Dados::ordenaComQuickSort()
{
    estatisticasTotais.trocas = 0;
    estatisticasTotais.comparacoes = 0;

    quickSort(0,registros.size()-1);

    return estatisticasTotais;
}

void Dados::heapify(int i)
{
    // TODO: implementar funcao de heapificação.
    // o tamanho da heap é descrito por 'heapSize',
    // para obter os indices dos filhos de um nodo i
    // usar 'filhoEsquerdoHeap(i)' e 'filhoDireitoHeap(i)'

    int e,d;
    int maior;

    e = filhoEsquerdoHeap(i);
    d = filhoDireitoHeap(i);
    maior = i;

    estatisticasTotais.comparacoes++;
    if(e < heapSize && registros[e] > registros[maior])
        maior = e;
    estatisticasTotais.comparacoes ++;
    if(d < heapSize && registros[d] > registros[maior])
        maior = d;
    estatisticasTotais.comparacoes ++;
    if(maior != i){
        estatisticasTotais.trocas++;
        troca(registros[i], registros[maior]);
        heapify(maior);
    }
}

void Dados::buildHeap()
{
    heapSize = registros.size();
    for(int i=heapSize/2 - 1; i>=0; i--)
        heapify(i);
}

Estatisticas Dados::ordenaComHeapSort()
{
    estatisticasTotais.trocas = 0;
    estatisticasTotais.comparacoes = 0;

    heapSize = 0;

    // TODO: implementar funcao de heapsort chamando buildHeap() e heapify(i)

    int i;
    buildHeap();
    for(i = heapSize - 1; i >= 0; i--){
        estatisticasTotais.comparacoes++;
        estatisticasTotais.trocas++;
        troca(registros[i], registros[0]);
        heapSize--;
        heapify(0);
    }
    return estatisticasTotais;
}

void Dados::ordenaComCountingSort(int K)
{
    estatisticasTotais.trocas = 0;
    estatisticasTotais.comparacoes = 0;

    // TODO: implementar funcao de ordenacao por contagem

    int i, j;
    std::vector<int> acumulador(K+1,0), saida(registros.size(),0);

    for(i = 0; i < registros.size();i++)
        acumulador[registros[i].getChave()]++;
    for(i = 1; i <= K; i++)
        acumulador[i] += acumulador[i - 1];
    for(j = registros.size() - 1; j >= 0; j--){
        saida[acumulador[registros[j].getChave()]-1]=registros[j].getChave();
        acumulador[registros[j].getChave()]--;
    }
    for(i=0;i<registros.size();i++)
        registros[i] = saida[i];
}

////////////////////////////////////
/// METODOS DE ORDENACAO - LAB 1 ///
////////////////////////////////////

Estatisticas Dados::ordenaComBubbleSort()
{
    Estatisticas est;
    est.trocas = 0;
    est.comparacoes = 0;

    // TODO: implementar codigo do bubbleSort

    int i, k, m, troca;
    Registro temp;

    m = registros.size() - 1;
    k = 1;
    do{
        troca = 0;

        for(i = 0; i < m; i++){
            est.comparacoes++;
            est.comparacoes++;
            if(registros[i] > registros[i + 1]){
                est.trocas++;

                temp = registros[i];
                registros[i] = registros[i + 1];
                registros[i + 1] = temp;

                k=i;

                troca = 1;
            }
        }
        m = k;
        est.comparacoes++;
    }while(troca == 1);

    return est;
}

Estatisticas Dados::ordenaComInsertionSort()
{
    Estatisticas est;
    est.trocas = 0;
    est.comparacoes = 0;

    // TODO: implementar codigo do insertionSort
    Registro escolhido;
    int i,j;
    int N=registros.size();

    for(j=1;j<N;j++){
        est.comparacoes++;
        escolhido=registros[j];
        i=j-1;
        est.comparacoes+=2;
        while(i>=0 && registros[i]>escolhido){
            est.trocas++;
            registros[i+1]=registros[i];
            i--;
            est.comparacoes+=2;
        }
        registros[i+1]=escolhido;
    }
    return est;
}

Estatisticas Dados::ordenaComShellSort(TipoShellSort tipo)
{
    Estatisticas est, aux;
    est.trocas = 0;
    est.comparacoes = 0;

    int n = registros.size();
    int p, f, h;

    std::vector<int> sequenciaDeGaps = geraSequenciaDeGaps(n,tipo);

    // TODO: implementar codigo do shellSort

    for(p = sequenciaDeGaps.size(); p > 0; p--){
        est.comparacoes++;
        h = sequenciaDeGaps[p-1];
        for(f = 0; f < h; f++){
            est.comparacoes++;
            aux = insDiretaShellSort(registros.size(), h, f);
            est.comparacoes += aux.comparacoes;
            est.trocas += aux.trocas;
        }
    }

    return est;
}

Estatisticas Dados::insDiretaShellSort(int n, int h, int f){
    int i, j;
    Registro chave;
    Estatisticas est;
    est.trocas = 0;
    est.comparacoes = 0;

    for(j=f+h;j<n;j+=h){
        est.comparacoes++;
        chave=registros[j];
        i=j-h;
        est.comparacoes += 2;
        while(i >= 0 && registros[i] > chave){
            est.comparacoes += 2;
            est.trocas++;
            registros[i + h] = registros[i];
            i = i - h;
        }
        registros[i+h]=chave;
    }

    return est;
}

bool Dados::checaSeOrdenacaoFoiEstavel()
{
    bool ehEstavel=true;

    // TODO: checar se elementos com chave igual mantem a ordem inicial analisando seus dados satelites
    int i, n=registros.size();
    for(i=0;i<n-1;i++)
        if(registros[i].getChave() == registros[i+1].getChave() && registros[i].getDadoSatelite() > registros[i+1].getDadoSatelite())
            return false;
    return ehEstavel;
}

//////////////////////////
/// METODOS AUXILIARES ///
//////////////////////////

int Dados::filhoEsquerdoHeap(int i)
{
    return 2*i+1;
}

int Dados::filhoDireitoHeap(int i)
{
    return 2*i+2;
}

int Dados::paiHeap(int i)
{
    return (i-1)/2;
}

void Dados::imprimeHeap()
{
    int nivel=-1;
    int nodos_no_nivel=1;

    std::cout << "\nHEAP\n";
    for(int i=0;i<heapSize; i++){
        if(i==nodos_no_nivel-1){
            nivel++;
            nodos_no_nivel *= 2;
        }
        for(int j=0;j<nivel;j++)
            std::cout << " ";
        std::cout << registros[i];

        int e = filhoEsquerdoHeap(i);
        int d = filhoDireitoHeap(i);

        if(e<heapSize)
            std::cout << " filho_esq: " << registros[e];
        if(d<heapSize)
            std::cout << " filho_dir: " << registros[d];
        if(i>=heapSize/2)
            std::cout << " FOLHA";
        std::cout << std::endl;
    }
}

void Dados::troca(Registro &x, Registro &y)
{
    Registro temp;
    temp = x;
    x = y;
    y = temp;
}

bool Dados::checaSeRegistrosOrdenados()
{
    for(unsigned int i=0; i<registros.size() - 1; i++)
        if(registros[i]>registros[i+1])
            return false;

    return true;
}

std::vector<int> Dados::geraSequenciaDeGaps(int tamanho, TipoShellSort tipo)
{
    std::vector<int> v;

    int e=1;
    v.push_back(e);

    if(tipo==SHELL59){         // (Shell,1959) - sequencia 1, 2, 4, 8, 16, 32, ...
        while(e<tamanho){
            e *= 2;
            v.push_back(e);
        }

    }else if(tipo==KNUTH71){   // (Knuth,1971) - sequencia 1, 4, 13, 40, 121, 364, ...
        while(e<tamanho){
            e = e*3+1;
            v.push_back(e);
        }

    }else if(tipo==TOKUDA92){  // (Tokuda,1992) - sequencia 1, 4, 9, 20, 46, 103, ...
        int i=1;
        while((e=ceil((9.0 * pow(9.0,i)/pow(4.0,i) - 4.0)/5.0)) < tamanho){
            v.push_back(e);
            i++;
        }
    }else if(tipo==CIURA01){  // (Ciura,2001) - sequencia 1, 4, 10, 23, 57, 132, 301, 701 - daqui em diante nao tem prova de otimalidade
        int seq[8]={1,4,10,23,57,132,301,701};

        int i=1;
        while(i<8 && seq[i]<tamanho){
            v.push_back(seq[i]);
            i++;
        }

        int e=701;
        while((e=floor(2.25*(float)e))<tamanho)
            v.push_back(e);
    }

    return v;
}

void Dados::inicializaRegistrosComVetor(const std::vector<int>& vetor_auxiliar)
{
    // Reseta vetor de registros
    registros.clear();

    // Reserva novo tamanho do vetor de registros
    unsigned int tamanho = vetor_auxiliar.size();
    registros.reserve(tamanho);

    // Copia valores para vetor de registros
    for(unsigned int i=0; i<tamanho; i++){
        int c = vetor_auxiliar[i];
        int s = i+1;

        registros.push_back(Registro(c,s));
    }
}

void Dados::geraVetorAleatorio(unsigned int tamanho, int minimo_possivel, int maximo_possivel)
{
    // Seta distribuicao de chaves como valor aleatorio uniforme entre 'minimo_possivel' e 'maximo_possivel'
    std::uniform_int_distribution<int> chave_aleatoria(minimo_possivel, maximo_possivel);

    // Cria vetor auxiliar e preenche com valores aleatorios
    std::vector<int> vetor_auxiliar(tamanho);
    for(unsigned int i=0; i<tamanho; i++){
        vetor_auxiliar[i] = chave_aleatoria(*gerador);
    }

    // Inicializa registros a partir do vetor
    inicializaRegistrosComVetor(vetor_auxiliar);
}

void Dados::geraVetorOrdenado(unsigned int tamanho, int minimo_possivel, int maximo_possivel)
{
    // Gera valores aleatorios iniciais em um vetor auxiliar
    std::uniform_int_distribution<int> chave_aleatoria(minimo_possivel, maximo_possivel);
    std::vector<int> vetor_auxiliar(tamanho);
    for(unsigned int i=0; i<tamanho; i++)
        vetor_auxiliar[i] = chave_aleatoria(*gerador);

    // Ordena o vetor com funcao de ordenacao da std library
    std::sort (vetor_auxiliar.begin(), vetor_auxiliar.end());

    // Inicializa registros a partir do vetor
    inicializaRegistrosComVetor(vetor_auxiliar);
}

void Dados::geraVetorQuaseOrdenado(unsigned int tamanho, int minimo_possivel, int maximo_possivel)
{
    // Gera valores aleatorios iniciais em um vetor auxiliar
    std::uniform_int_distribution<int> chave_aleatoria(minimo_possivel, maximo_possivel);
    std::vector<int> vetor_auxiliar(tamanho);
    for(unsigned int i=0; i<tamanho; i++)
        vetor_auxiliar[i] = chave_aleatoria(*gerador);

    // Ordena o vetor com funcao de ordenacao da std library
    std::sort (vetor_auxiliar.begin(), vetor_auxiliar.end());

    // Da uma leve embaralhada, dentro de uma distancia 'range'
    int range=tamanho/50;
    if(range<5)
        range=5;
    std::uniform_int_distribution<int> gap_para_troca(0,range);

    for(unsigned int i=0; i<tamanho; i++){
        int k = gap_para_troca(*gerador);
        if(k%5==0 && i+k<tamanho){
            int temp = vetor_auxiliar[i+k];
            vetor_auxiliar[i+k] = vetor_auxiliar[i];
            vetor_auxiliar[i] = temp;
        }
    }

    // Inicializa registros a partir do vetor
    inicializaRegistrosComVetor(vetor_auxiliar);
}

void Dados::geraVetorReverso(unsigned int tamanho, int minimo_possivel, int maximo_possivel)
{
    // Gera valores aleatorios iniciais em um vetor auxiliar
    std::uniform_int_distribution<int> chave_aleatoria(minimo_possivel, maximo_possivel);
    std::vector<int> vetor_auxiliar(tamanho);
    for(unsigned int i=0; i<tamanho; i++)
        vetor_auxiliar[i] = chave_aleatoria(*gerador);

    // Ordena o vetor com funcao de ordenacao da std library
    std::sort (vetor_auxiliar.begin(), vetor_auxiliar.end(), std::greater<int>());

    // Inicializa registros a partir do vetor
    inicializaRegistrosComVetor(vetor_auxiliar);
}

void Dados::imprimeRegistros()
{
    for(unsigned int i=0; i<registros.size(); i++){
        std::cout << registros[i] << ' ';
    }
    std::cout << std::endl;
}

