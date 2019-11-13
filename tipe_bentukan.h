#ifndef type_H
#define type_H

typedef struct {
			char nama;
			int player;
			int poin;
			int posisiR;
			int posisiC;
		} piece;

typedef struct {
			char nama;
			int player;
		} papan;

typedef struct {
			int posisiR;
			int posisiC;
		} posisi;

char command;

#endif