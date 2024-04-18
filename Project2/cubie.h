////######//The cube on the cubie level is described by the permutation and orientations of corners and edges ############
#ifndef CUBIE_H
#define CUBIE_H
#include<iostream>
using namespace std;
#include"enum.h"
#include"define.h"
#include"misc.h"
#include"face.h"

////#################//The basic six cube moves described by permutations and changes in orientation #####################

////Up - move
std::vector<int> cpU = {Co.UBR, Co.URF, Co.UFL, Co.ULB, Co.DFR, Co.DLF, Co.DBL, Co.DRB};
std::vector<int> coU = { 0, 0, 0, 0, 0, 0, 0, 0 };
std::vector<int> epU = { Ed.UB, Ed.UR, Ed.UF, Ed.UL, Ed.DR, Ed.DF, Ed.DL, Ed.DB, Ed.FR, Ed.FL, Ed.BL, Ed.BR };
std::vector<int> eoU = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

//Right - move
std::vector<int> cpR = { Co.DFR, Co.UFL, Co.ULB, Co.URF, Co.DRB, Co.DLF, Co.DBL, Co.UBR };  //permutation of the corners
std::vector<int> coR = { 2, 0, 0, 1, 1, 0, 0, 2 };  //changes of the orientations of the corners
std::vector<int> epR = { Ed.FR, Ed.UF, Ed.UL, Ed.UB, Ed.BR, Ed.DF, Ed.DL, Ed.DB, Ed.DR, Ed.FL, Ed.BL, Ed.UR };  //permutation of the edges
std::vector<int> eoR = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };  //changes of the permutations of the edges

//Front - move
std::vector<int> cpF = { Co.UFL, Co.DLF, Co.ULB, Co.UBR, Co.URF, Co.DFR, Co.DBL, Co.DRB };
std::vector<int> coF = { 1, 2, 0, 0, 2, 1, 0, 0 };
std::vector<int> epF = { Ed.UR, Ed.FL, Ed.UL, Ed.UB, Ed.DR, Ed.FR, Ed.DL, Ed.DB, Ed.UF, Ed.DF, Ed.BL, Ed.BR };
std::vector<int> eoF = { 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0 };

//Down - move
std::vector<int> cpD = { Co.URF, Co.UFL, Co.ULB, Co.UBR, Co.DLF, Co.DBL, Co.DRB, Co.DFR };
std::vector<int> coD = { 0, 0, 0, 0, 0, 0, 0, 0 };
std::vector<int> epD = { Ed.UR, Ed.UF, Ed.UL, Ed.UB, Ed.DF, Ed.DL, Ed.DB, Ed.DR, Ed.FR, Ed.FL, Ed.BL, Ed.BR };
std::vector<int> eoD = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// Left - move
std::vector<int> cpL = { Co.URF, Co.ULB, Co.DBL, Co.UBR, Co.DFR, Co.UFL, Co.DLF, Co.DRB };
std::vector<int> coL = { 0, 1, 2, 0, 0, 2, 1, 0 };
std::vector<int> epL = { Ed.UR, Ed.UF, Ed.BL, Ed.UB, Ed.DR, Ed.DF, Ed.FL, Ed.DB, Ed.FR, Ed.UL, Ed.DL, Ed.BR };
std::vector<int> eoL = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// Back - move
std::vector<int> cpB = { Co.URF, Co.UFL, Co.UBR, Co.DRB, Co.DFR, Co.DLF, Co.ULB, Co.DBL };
std::vector<int> coB = { 0, 0, 1, 2, 0, 0, 2, 1 };
std::vector<int> epB = { Ed.UR, Ed.UF, Ed.UL, Ed.BR, Ed.DR, Ed.DF, Ed.DL, Ed.BL, Ed.FR, Ed.FL, Ed.UB, Ed.DB };
std::vector<int> eoB = { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1 };
//#######################################################################################################################

bool CUBE_OK = true;


class CubieCube {
public:
	std::vector<int> cp;
	std::vector<int> co;
	std::vector<int> ep;
	std::vector<int> eo;

	CubieCube();
	CubieCube(std::vector<int> cp, std::vector<int> co, std::vector<int> ep, std::vector<int> eo);
	void from_facelet_cube(FaceCube fc);
	void Corner_Multiply(CubieCube b);
	void Edge_Multiply(CubieCube b);
	void Multiply(CubieCube b);
	CubieCube inv_Cubie_Cube();
	int get_twist();
	void set_twist(int twist);
	int get_flip();
	void set_flip(int flip);
	int get_slice();
	void set_slice(int idx);
	int get_slice_sorted();
	void set_slice_sorted(int idx);
	int get_u_edges();
	void set_u_edges(int idx);
	int get_d_edges();
	void set_d_edges(int idx);

	bool operator==(const CubieCube& other) const {
		if (other.co == co && other.cp == cp && other.eo == eo && other.ep == ep)
			return true;
		else
			return false;
	}

};

CubieCube::CubieCube() {
	this->cp.resize(8);
	this->co.resize(8);
	this->ep.resize(12);
	this->eo.resize(12);
	for (int c = 0; c < 8; c++) {
		this->cp[c] = c;
		this->co[c] = 0;
	}
	for (int e = 0; e < 12; e++) {
		this->ep[e] = e;
		this->eo[e] = 0;
	}
}

CubieCube::CubieCube(std::vector<int> cp, std::vector<int> co, std::vector<int> ep, std::vector<int> eo) {
	this->cp.resize(8);
	this->co.resize(8);
	this->ep.resize(12);
	this->eo.resize(12);
	this->cp = cp;
	this->co = co;
	this->ep = ep;
	this->eo = eo;
}

void CubieCube::from_facelet_cube(FaceCube fc) {
	for (int i = 0; i < 8; i++) {
		std::vector<int> fac = cornerFacelet[i];
		int ori=0;
		while (!(fc.f[fac[ori]] == Cl.U || fc.f[fac[ori]] == Cl.D)) ori++;
		int col1 = fc.f[fac[(ori + 1) % 3]];
		int col2 = fc.f[fac[(ori + 2) % 3]];
		for (int j = 0; j < 8; j++) {
			std::vector<int> col = cornerColor[j]; 
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

void CubieCube::Corner_Multiply(CubieCube b) {
	std::vector<int> C_perm;
	std::vector<int> C_ori;
	for (int i = 0; i < 8; i++) {
		C_perm.push_back(this->cp[b.cp[i]]);
		C_ori.push_back((this->co[b.cp[i]] + b.co[i]) % 3);
	}
	this->cp = C_perm;
	this->co = C_ori;
}

void CubieCube::Edge_Multiply(CubieCube b) {
	std::vector<int> E_perm;
	std::vector<int> E_ori;
	for (int i = 0; i < 12; i++) {
		E_perm.push_back(this->ep[b.ep[i]]);
		E_ori.push_back((this->eo[b.ep[i]] + b.eo[i]) % 2);
	}
	this->ep = E_perm;
	this->eo = E_ori;
}

void CubieCube::Multiply(CubieCube b) {
	this->Corner_Multiply(b);
	this->Edge_Multiply(b);
}

CubieCube CubieCube::inv_Cubie_Cube() {
	CubieCube d;
	for (int e = 0; e <= Ed.BR; e++) 
		d.ep[this->ep[e]] = e;
	for (int e = 0; e <= Ed.BR; e++)
		d.eo[e] = this->eo[d.ep[e]];

	for (int c = 0; c <= 7; c++)
		d.cp[this->cp[c]] = c;
	for (int c = 0; c <= 7; c++) {
		int ori = this->co[d.cp[c]];
		if (ori >= 3)
			d.co[c] = ori;
		else {
			d.co[c] = -ori;
			if (d.co[c] < 0)
				d.co[c] += 3;
		}
	}

	return d;

}

int CubieCube::get_twist() {
	int ret = 0;
	for (int i = Co.URF; i < Co.DRB; i++)
		ret = 3 * ret + this->co[i];
	return ret;
}

void CubieCube::set_twist(int twist) {
	int twistparity = 0;
	for(int i = Co.DRB - 1; i >= Co.URF; i--) {
		this->co[i] = twist % 3;
		twistparity += this->co[i];
	    twist /= 3;
				
	}
	this->co[Co.DRB] = ((3 - twistparity % 3) % 3);
}

int CubieCube::get_flip() {
	int ret = 0;
	for (int i = Ed.UR; i < Ed.BR; i++)
		ret = 2 * ret + this->eo[i];

	return ret;
}

void CubieCube::set_flip(int flip) {
	int flipparity = 0;
	for (int i = Ed.BR-1; i >= Ed.UR; i--) {
		this->eo[i] = flip % 2;
		flipparity += this->eo[i];
		flip /= 2;

	}
	this->co[Ed.DB] = ((2 - flipparity % 2) % 2);
}

int CubieCube::get_slice(){
	int a = 0;
	int x = 0;
	for (int i = Ed.BR; i >= Ed.UR; i--) {
		if (Ed.FR <= this->ep[i] && this->ep[i] <= Ed.BR) {
			a += c_nk(11 - i, x + 1);
			x += 1;
		}
	}
	return a;
}

void CubieCube::set_slice(int idx) {
	int slice_edge[4] = { Ed.FR,Ed.FL,Ed.BL,Ed.BR };
	int other_edge[8] = { Ed.UR, Ed.UF, Ed.UL, Ed.UB, Ed.DR, Ed.DF, Ed.DL, Ed.DB };
	int a = idx;
	for (int i = 0; i < 12; i++) this->ep[i] = -1;
	int x = 4;
	for (int i = 0; i < 12; i++) {
		if ((a - c_nk(11 - i, x)) >= 0) {
			a -= c_nk(11 - i, x);
			x -= 1;
		}
	}
	x = 0;
	for (int j = 0; j < 12; j++) {
		if (this->ep[j] == -1) {
			this->ep[j] = other_edge[x];
			x++;
		}
	}
}

int CubieCube::get_slice_sorted() {
	int a = 0;
	int x = 0;
	vector<int> edge4(4,0);
	for (int i = Ed.BR; i >= 0; i--) {
		if (Ed.FR <= this->ep[i] && this->ep[i] <= Ed.BR) {
			a += c_nk(11 - i, x + 1);
			edge4[3 - x] = this->ep[i];
			x += 1;
		}
	}
	int b = 0;
	for (int i = 3; i > 0; i--) {
		int k = 0;
		while (edge4[i] != i + 8) {
			rotate_left(edge4, 0, i);
			k++;
		}
		b = (i + 1) * b + k;
	}
	return 24*a+b;
}

void CubieCube::set_slice_sorted(int idx) {
	vector<int> slice_edge = { Ed.FR, Ed.FL, Ed.BL, Ed.BR };
	vector<int> other_edge = { Ed.UR, Ed.UF, Ed.UL, Ed.UB, Ed.DR, Ed.DF, Ed.DL, Ed.DB };
	int b = idx % 24;
	int a = idx / 24;
	for (int e = 0; e <= Ed.BR; e++)
		this->ep[e] = -1;

	int j = 1;
	int k;
	while (j < 4) {
		k = b % (j + 1);
		b /= j + 1;
		while (k>0)
		{
			rotate_right(slice_edge, 0, j);
			k -= 1;
		}
		j++;
	}

	int x = 4;
	for (int e = 0; e <= Ed.BR; e++) {
		if (a - c_nk(11 - e, x) >= 0) {
			this->ep[e] = slice_edge[4 - x];
			a -= c_nk(11 - e, x);
			x--;
		}
	}

	x = 0;
	for (int e = 0; e <= Ed.BR; e++) {
		if (this->ep[e] == -1) {
			this->ep[e] = other_edge[x];
			x++;
		}
	}
}

int CubieCube::get_u_edges() {
	int a = 0;
	int x = 0;
	vector<int> edge4(4, 0);
	vector<int> ep_mod = this->ep;
	for (int i = 0; i < 4; i++)
		rotate_right(ep_mod, 0, 11);
	for (int i = 11; i >= 0; i--) {
		if (Ed.UR <= ep_mod[i] && ep_mod[i] <= Ed.UB) {
			a += c_nk(11 - i, x + 1);
			edge4[3 - x] = ep_mod[i];
			x += 1;
		}
	}
	cout << a << endl;
	int b = 0;
	for (int i = 3; i > 0; i--) {
		int k = 0;
		while (edge4[i] != i) {
			rotate_left(edge4, 0, i);
			k++;
		}
		b = (i + 1) * b + k;
	}
	return 24 * a + b;
}

void CubieCube::set_u_edges(int idx) {
	vector<int> slice_edge = { Ed.UR, Ed.UF, Ed.UL, Ed.UB };
	vector<int> other_edge = { Ed.DR, Ed.DF, Ed.DL, Ed.DB, Ed.FR, Ed.FL, Ed.BL, Ed.BR };
	int b = idx % 24;
	int a = idx / 24;
	for (int e = 0; e <= Ed.BR; e++)
		this->ep[e] = -1;

	int j = 1;
	int k;
	while (j < 4) {
		k = b % (j + 1);
		b /= j + 1;
		while (k > 0)
		{
			rotate_right(slice_edge, 0, j);
			k -= 1;
		}
		j++;
	}
	
	int x = 4;
	for (int e = 0; e <= Ed.BR; e++) {
		if (a - c_nk(11 - e, x) >= 0) {
			this->ep[e] = slice_edge[4 - x];
			a -= c_nk(11 - e, x);
			x--;
		}
	}

	x = 0;
	for (int e = 0; e <= Ed.BR; e++) {
		if (this->ep[e] == -1) {
			this->ep[e] = other_edge[x];
			x++;
		}
	}
}

int CubieCube::get_d_edges() {
	int a = 0;
	int x = 0;
	vector<int> edge4(4, 0);
	vector<int> ep_mod = this->ep;
	for (int i = 0; i < 4; i++)
		rotate_right(ep_mod, 0, 11);
	for (int i = 11; i >= 0; i--) {
		if (Ed.DR <= ep_mod[i] && ep_mod[i] <= Ed.DB) {
			a += c_nk(11 - i, x + 1);
			edge4[3 - x] = ep_mod[i];
			x += 1;
		}
	}
	int b = 0;
	for (int i = 3; i > 0; i--) {
		int k = 0;
		while (edge4[i] != (i + 4)) {
			rotate_left(edge4, 0, i);
			k++;
		}
		b = (i + 1) * b + k;
	}
	return 24 * a + b;
}

void CubieCube::set_d_edges(int idx) {
	vector<int> slice_edge = { Ed.DR, Ed.DF, Ed.DL, Ed.DB };
	vector<int> other_edge = { Ed.FR, Ed.FL, Ed.BL, Ed.BR, Ed.UR, Ed.UF, Ed.UL, Ed.UB };
	int b = idx % 24;
	int a = idx / 24;
	for (int e = 0; e <= Ed.BR; e++)
		this->ep[e] = -1;

	int j = 1;
	int k;
	while (j < 4) {
		k = b % (j + 1);
		b /= j + 1;
		while (k > 0)
		{
			rotate_right(slice_edge, 0, j);
			k -= 1;
		}
		j++;
	}

	int x = 4;
	for (int e = 0; e <= Ed.BR; e++) {
		if (a - c_nk(11 - e, x) >= 0) {
			this->ep[e] = slice_edge[4 - x];
			a -= c_nk(11 - e, x);
			x--;
		}
	}

	x = 0;
	for (int e = 0; e <= Ed.BR; e++) {
		if (this->ep[e] == -1) {
			this->ep[e] = other_edge[x];
			x++;
		}
	}
}


std::vector<CubieCube> basicMoveCube = {
	CubieCube(cpU, coU, epU, eoU),
	CubieCube(cpF, coF, epF, eoF),
	CubieCube(cpR, coR, epR, eoR),
	CubieCube(cpD, coD, epD, eoD),
	CubieCube(cpL, coL, epL, eoL),
	CubieCube(cpB, coB, epB, eoB)
};

vector<CubieCube> moveCube;

void build_moveCube() {
	for (int cl = color.U; cl <= color.B; cl++) {
		CubieCube cc;
		for (int k = 0; k < 3; k++) {
			cc.Multiply(basicMoveCube[cl]);
			moveCube.push_back(cc);
			cout << cl <<" " << k << endl;
		}
	}
}

#endif
