#ifndef TRIE_H
#define TRIE_H

    typedef unsigned char uchar;

    typedef enum ASCII_TRIE_ESTADO{
        ATE_LIVRE,
        ATE_OCUPADO
    } ASCII_TRIE_ESTADO;
    

    typedef struct ASCII_TRIE {
        int valor; 
        struct ASCII_TRIE* filhos[256];
        ASCII_TRIE_ESTADO estado;
    } ASCII_TRIE;

    //busca
    ASCII_TRIE* AT_Buscar(ASCII_TRIE* T, unsigned char* chave);
    static ASCII_TRIE* AT_Buscar_R(ASCII_TRIE* T, uchar* chave, int n, int p);

    //inserção
    void AT_Inserir(ASCII_TRIE** T, uchar* chave, int valor);
    ASCII_TRIE* AT_Criar();  
    //inserção iterativa
    void AT_Inserir_I(ASCII_TRIE** T, uchar* chave, int valor);
    ASCII_TRIE* AT_Buscar_I(ASCII_TRIE* T, uchar* chave);

    //remoção 
    //implementar remoção preguiçosa
    void AT_Remover(ASCII_TRIE** T, uchar* chave);
    void AT_Remover_I(ASCII_TRIE** T, uchar* chave);


    void AT_Imprimir(ASCII_TRIE* T);
    int AT_Limpa(ASCII_TRIE* T);

    int AT_Tamanho(ASCII_TRIE* T);

    int SubstringCountLenL(char * s, int L);

    




#endif