#ifndef SEMMETRIES_H
#define SEMMETRIES_H

#include<iostream>
using namespace std;
#include "cubie.h"
#include "define.h"
#include "enum.h"

#define INVALID 65535

vector<int> cpROT_URF3 = { Co.URF, Co.DFR, Co.DLF, Co.UFL, Co.UBR, Co.DRB, Co.DBL, Co.ULB };
vector<int> coROT_URF3 = { 1, 2, 1, 2, 2, 1, 2, 1 };
vector<int> epROT_URF3 = { Ed.UF, Ed.FR, Ed.DF, Ed.FL, Ed.UB, Ed.BR, Ed.DB, Ed.BL, Ed.UR, Ed.DR, Ed.DL, Ed.UL };
vector<int> eoROT_URF3 = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1 };

// 180бу rotation around the axis through the F and B centers
vector<int> cpROT_F2 = { Co.DLF, Co.DFR, Co.DRB, Co.DBL, Co.UFL, Co.URF, Co.UBR, Co.ULB };
vector<int> coROT_F2 = { 0, 0, 0, 0, 0, 0, 0, 0 };
vector<int> epROT_F2 = { Ed.DL, Ed.DF, Ed.DR, Ed.DB, Ed.UL, Ed.UF, Ed.UR, Ed.UB, Ed.FL, Ed.FR, Ed.BR, Ed.BL };
vector<int> eoROT_F2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// 90бу clockwise rotation around the axis through the U and D centers
vector<int> cpROT_U4 = { Co.UBR, Co.URF, Co.UFL, Co.ULB, Co.DRB, Co.DFR, Co.DLF, Co.DBL };
vector<int> coROT_U4 = { 0, 0, 0, 0, 0, 0, 0, 0 };
vector<int> epROT_U4 = { Ed.UB, Ed.UR, Ed.UF, Ed.UL, Ed.DB, Ed.DR, Ed.DF, Ed.DL, Ed.BR, Ed.FR, Ed.FL, Ed.BL };
vector<int> eoROT_U4 = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 };

// reflection at the plane through the U, D, F, B centers
vector<int> cpMIRR_LR2 = { Co.UFL, Co.URF, Co.UBR, Co.ULB, Co.DLF, Co.DFR, Co.DRB, Co.DBL };
vector<int> coMIRR_LR2 = { 3, 3, 3, 3, 3, 3, 3, 3 };
vector<int> epMIRR_LR2 = { Ed.UL, Ed.UF, Ed.UR, Ed.UB, Ed.DL, Ed.DF, Ed.DR, Ed.DB, Ed.FL, Ed.FR, Ed.BR, Ed.BL };
vector<int> eoMIRR_LR2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

vector<CubieCube> basicSymCube = {
	CubieCube(cpROT_URF3, coROT_URF3, epROT_URF3, eoROT_URF3),
	CubieCube(cpROT_F2, coROT_F2, epROT_F2, eoROT_F2),
	CubieCube(cpROT_U4, coROT_U4, epROT_U4, eoROT_U4),
	CubieCube(cpMIRR_LR2, coMIRR_LR2, epMIRR_LR2, eoMIRR_LR2)
};

vector<CubieCube> symCube;
void build_symCube() {
	CubieCube cc;
	int idx = 0;
	for (int urf3 = 0; urf3 < 3; urf3++) {
		for (int f2 = 0; f2 < 2; f2++) {
			for (int u4 = 0; u4 < 4; u4++) {
				for (int lr2 = 0; lr2 < 2; lr2++) {
					symCube.push_back(cc);
					idx++;
					cc.Multiply(basicSymCube[BS.MIRR_LR2]);
				}
				cc.Multiply(basicSymCube[BS.ROT_U4]);
			}
			cc.Multiply(basicSymCube[BS.ROT_F2]);
		}
		cc.Multiply(basicSymCube[BS.ROT_URF3]);
	}
}

unsigned int inv_idx[N_SYM];
void build_inv_idx() {
	CubieCube cc;
	memset(inv_idx, 0, sizeof(inv_idx));
	for (int i = 0; i < N_SYM; i++) {
		for (int j = 0; j < N_SYM; j++) {
			cc = CubieCube(symCube[i].cp, symCube[i].co, symCube[i].ep, symCube[i].eo);
			cc.Multiply(symCube[j]);
			if (cc.cp[Co.URF] == Co.URF && cc.cp[Co.UFL] == Co.UFL && cc.cp[Co.ULB] == Co.ULB) {
				inv_idx[i] = j;
				//cout << j << endl;
				break;
			}
		}
	}
}

vector<int> symmetries(CubieCube cb){
	vector<int> s;
	CubieCube d;
	for (int j = 0; j < N_SYM;j++) {
		CubieCube c(symCube[j].cp, symCube[j].co, symCube[j].ep, symCube[j].eo);
		c.Multiply(cb);
		c.Multiply(symCube[inv_idx[j]]);
		if (cb == c)
			s.push_back(j);
		d=c.inv_Cubie_Cube();
		if (cb == d)
			s.push_back(j + N_SYM);
	}
	return s;
}



#endif
