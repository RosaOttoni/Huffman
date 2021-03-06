#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED
#include <iostream>
#include <ctime>
#include "Review.h"
#include "ReviewNode.h"

using namespace std;

void acessaRegistro(int i, char *diretorio);

void geraArquivo(int n, int *vet);

void leituraCsv(string diretorio);

void importaConjunto(int n, Review *vet[]);

void importaConjunto (char *nomeDiretorio, int n, Review *vet[]);

void importaConjunto (char *nomeDiretorio, int n, ReviewNode *vet[]);

void imprimeConjunto (int n, Review *vet[]);

#endif // FILEIO_H_INCLUDED
