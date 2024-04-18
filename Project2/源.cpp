#include<iostream>
#include<string>
using namespace std;
#include"enum.h"
#include"define.h"
#include"face.h"
#include"cubie.h"
#include"symmetries.h"
#include"moves.h"

FaceCube facecube;

void Init() {
	build_moveCube();
	build_symCube();
	build_inv_idx();
	build_move_twist();
	build_move_flip();
	build_move_slice_sorted();
	build_move_u_edges();
	build_move_d_edges();
}

void show_movetwist() {
	for (int i = 0; i < N_TWIST * N_MOVE; i++)
		cout << twist_move[i]<<endl;
}

int main() {
	Init();
	//show_movetwist();

	
	string s;
	CubieCube cc;
	vector<int> a = symmetries(basicMoveCube[5]);
	for (int i = 0; i < a.size(); i++)
		cout << a[i]<<"  ";
	cout << endl;
	cin >> s;
	facecube.from_string(s);
	cc.from_facelet_cube(facecube);
	for (int k = 0; k < 48; k++) {
		for (int i = 0; i < 8; i++) {
			cout << symCube[k].cp[i] << "   ";
		}
		cout << endl;
		for (int i = 0; i < 12; i++) {
			cout << symCube[k].ep[i] << "   ";
		}
		cout << endl;

	}
	cout <<endl<< cc.get_slice()<<endl;
	a = symmetries(cc);
	for (int i = 0; i < a.size(); i++)
		cout << a[i];

	return 0;
}