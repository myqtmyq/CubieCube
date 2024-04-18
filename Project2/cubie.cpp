#include"enum.h"
#include"define.h"
#include"face.h"
#include"cubie.h"
#include<iostream>

Corner Co;
Edge Ed;

////#################//The basic six cube moves described by permutations and changes in orientation #####################

////Up - move
int cpU[8] = { Co.UBR, Co.URF, Co.UFL, Co.ULB, Co.DFR, Co.DLF, Co.DBL, Co.DRB };
int coU[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int epU[12] = { Ed.UB, Ed.UR, Ed.UF, Ed.UL, Ed.DR, Ed.DF, Ed.DL, Ed.DB, Ed.FR, Ed.FL, Ed.BL, Ed.BR };
int eoU[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

//Right - move
int cpR[8] = { Co.DFR, Co.UFL, Co.ULB, Co.URF, Co.DRB, Co.DLF, Co.DBL, Co.UBR };  //permutation of the corners
int coR[8] = { 2, 0, 0, 1, 1, 0, 0, 2 };  //changes of the orientations of the corners
int epR[12] = { Ed.FR, Ed.UF, Ed.UL, Ed.UB, Ed.BR, Ed.DF, Ed.DL, Ed.DB, Ed.DR, Ed.FL, Ed.BL, Ed.UR };  //permutation of the edges
int eoR[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };  //changes of the permutations of the edges

//Front - move
int cpF[8] = { Co.UFL, Co.DLF, Co.ULB, Co.UBR, Co.URF, Co.DFR, Co.DBL, Co.DRB };
int coF[8] = { 1, 2, 0, 0, 2, 1, 0, 0 };
int epF[12] = { Ed.UR, Ed.FL, Ed.UL, Ed.UB, Ed.DR, Ed.FR, Ed.DL, Ed.DB, Ed.UF, Ed.DF, Ed.BL, Ed.BR };
int eoF[12] = { 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0 };

//Down - move
int cpD[8] = { Co.URF, Co.UFL, Co.ULB, Co.UBR, Co.DLF, Co.DBL, Co.DRB, Co.DFR };
int coD[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
int epD[12] = { Ed.UR, Ed.UF, Ed.UL, Ed.UB, Ed.DF, Ed.DL, Ed.DB, Ed.DR, Ed.FR, Ed.FL, Ed.BL, Ed.BR };
int eoD[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// Left - move
int cpL[8] = { Co.URF, Co.ULB, Co.DBL, Co.UBR, Co.DFR, Co.UFL, Co.DLF, Co.DRB };
int coL[8] = { 0, 1, 2, 0, 0, 2, 1, 0 };
int epL[12] = { Ed.UR, Ed.UF, Ed.BL, Ed.UB, Ed.DR, Ed.DF, Ed.FL, Ed.DB, Ed.FR, Ed.UL, Ed.DL, Ed.BR };
int eoL[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// Back - move
int cpB[8] = { Co.URF, Co.UFL, Co.UBR, Co.DRB, Co.DFR, Co.DLF, Co.ULB, Co.DBL };
int coB[8] = { 0, 0, 1, 2, 0, 0, 2, 1 };
int epB[12] = { Ed.UR, Ed.UF, Ed.UL, Ed.BR, Ed.DR, Ed.DF, Ed.DL, Ed.BL, Ed.FR, Ed.FL, Ed.UB, Ed.DB };
int eoB[12] = { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1 };
//#######################################################################################################################

bool CUBE_OK = true;

void CubieCube::from_facelet_cube(FaceCube fc) {
	for (int i = 0; i < 8; i++) {
		std::vector<int> fac = cornerFacelet[i];
		int ori;
		for (ori = 0; ori < 2; i++)
			if (fc.f[fac[ori]] == Cl.U || fc.f[fac[ori]] == Cl.D) break;
		int col1 = fc.f[fac[(ori + 1) % 3]];
		int col2 = fc.f[fac[(ori + 2) % 3]];
		std::vector<int> col = cornerColor[i];
		for (int j = 0; j < 8; j++) {
			if (col1 == col[1] && col2 == col[2]) {
				this->cp[i] = j;
				this->co[i] = ori;
			}
		}
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (fc.f[edgeFacelet[i][0]] == edgeColor[j][0] && fc.f[edgeFacelet[i][1]] == edgeColor[j][1]) {
				this->ep[i] = j;
				this->eo[i] = 1;
			}
			else if (fc.f[edgeFacelet[i][0]] == edgeColor[j][1] && fc.f[edgeFacelet[i][1]] == edgeColor[j][0]) {
				this->ep[i] = j;
				this->eo[i] = 0;
			}
		}
	}
}