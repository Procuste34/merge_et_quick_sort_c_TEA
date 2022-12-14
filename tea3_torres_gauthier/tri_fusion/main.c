#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "test_utils.h"
#include "tri_fusion.h"

//prototypes des fonctions à tester :
void triFusion(T_data d, int n);

T_mode m[] = {
	{MODE_TAB_ORDONNE, "ordonne", 0, 1}, 
	{MODE_TAB_ALEATOIRE, "aleatoire", 0, 1}, 
	{MODE_TAB_INVERSE, "inverse", 0, 1}, 
	{MODE_EVAL_X, "x=2.0", 2.0, 0}, 
	{MODE_TAB_ORDONNE, "ordonne (x=59)", 59, 0}, 
	{MODE_TAB_ORDONNE, "hanoi", 1, 0}
};

//affiche un tableau d'entiers
void showTabInt(int * p, int len){
	for(int i=0; i<len; i++){
		printf("%d -", p[i]);
	}
	printf("\n");
}

//fonction à passer à fusionsort pour comparer (dans le cas où les éléments sont des int)
int comparerInt(const void * e1, const void * e2){
	stats.nbComparisons++;
	
    int e1_int = * (const int *) e1;
    int e2_int = * (const int *) e2;
    return e1_int - e2_int;
}

int main(void){
	printf("********** tri fusion sur T_data ************ \n");

	int tab1[6] = {10, 50, 30, 20, 40, 60};
    T_data data = genData(0, tab1);
	
	triFusion(data, 6);
	showTabInt(data.pElt, 6);

	printf("*************** fusionsort ***********\n");
	int tab2[] = {10, 50, 30, 20, 40, 60};

	fusionsort(tab2, 6, sizeof(int), comparerInt);
	showTabInt(tab2, 6);

	printf("************** graphiques *************** \n");

	T_elt tab [MAX_ELT];
	outputPath = "output";
	srand((unsigned int)time(NULL));
	Test_Fn("TRI FUSION", triFusion, tab, MAX_ELT/10, m[MODE_TAB_ORDONNE]);
	Test_FnV2("TRI FUSION", triFusion, tab, 512, m[MODE_TAB_ORDONNE]);
	
	/*
	printf("**************** timing ******************\n");

	time_t start = time(NULL);

	for(int j = 0; j<100; j++){
		T_elt tab2 [MAX_ELT];
		for(int i = 0; i<MAX_ELT; i++){
			tab2[i] = rand();
		}
	
		fusionsort(tab2, MAX_ELT, sizeof(int), comparerInt);
	}

	time_t end = time(NULL);
	printf("%f\n", difftime(end, start));
	*/

    return 0;
}