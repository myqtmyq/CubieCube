#pragma once
#ifndef FACE_H
#define FACE_H
#include"define.h"
#include"enum.h"
#include<string>

using namespace std;

class FaceCube {
public:
	int f[54];
	void from_string(string s);
	string to_string();


};

void FaceCube::from_string(string s) {
	for (int i = 0; i < 54; i++) {
		if (s[i] == 'U') this->f[i] = color.U;
		if (s[i] == 'R') this->f[i] = color.R;
		if (s[i] == 'F') this->f[i] = color.F;
		if (s[i] == 'D') this->f[i] = color.D;
		if (s[i] == 'L') this->f[i] = color.L;
		if (s[i] == 'B') this->f[i] = color.B;
	}
}

string FaceCube::to_string() {
	string str;
	for (int i = 0; i < 54; i++) {
		if(this->f[i] == color.U) str += "U";
		else if (this->f[i] == color.R) str += "R";
		else if (this->f[i] == color.F) str += "F";
		else if (this->f[i] == color.D) str += "D";
		else if (this->f[i] == color.L) str += "L";
		else if (this->f[i] == color.B) str += "B";
		str += "  ";
	}
	return str;
}

#endif
