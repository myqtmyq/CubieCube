#ifndef MOVES_H
#define MOVES_H

#include "cubie.h"
#include "define.h"
#include"enum.h"
#include<iostream>
#include<fstream>
#include <filesystem>
using namespace std;


bool IS_created(FILE* file) {
    string line;

    if (fseek(file, -9, SEEK_END) != 0);
    int c;
    int index = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            if (line == "created"){
                rewind(file);
                return true;
            }
            line.clear();
            index = 0;
        }
        else 
            line += static_cast<char>(c);
    }

    rewind(file);

    return false;
}

void load_file(FILE* file, vector<unsigned int> &arr) {
    int i = 0;
    int number;
    while (fscanf_s(file, "%d", &number) == 1 ) 
        arr[i] = number,i++;

}

const char* folder = "D:/C++ CODE/Ä§·½»úÆ÷ÈË/Project2";
char filepath[256];  // Assuming a maximum path length of 255 characters
FILE* outputFile;


vector<unsigned int> twist_move(N_TWIST * N_MOVE);
void build_move_twist() {
    const char* filename = "move_twist.txt";
    sprintf_s(filepath, "%s/%s", folder, filename);
    CubieCube a;
    errno_t err = fopen_s(&outputFile, filepath, "r");

    if (outputFile != NULL&& IS_created(outputFile)) {
        cout << "loading " << filename << " table..." << endl;
        load_file(outputFile, twist_move);
    }
    else {
        if (outputFile != NULL)
            fclose(outputFile);
        errno_t err = fopen_s(&outputFile, filepath, "w");
        cout << "creating " << filename << " table..." << std::endl;

        for (int i = 0; i < N_TWIST; ++i) {
            a.set_twist(i);
            for (int j = 0; j < 6; ++j) {  // six faces U, R, F, D, L, B
                for (int k = 0; k < 3; ++k) {  // three moves for each face
                    a.Corner_Multiply(basicMoveCube[j]);
                    twist_move[N_MOVE * i + 3 * j + k] = a.get_twist();

                    fprintf(outputFile, "%d\n", a.get_twist());
                }
                a.Corner_Multiply(basicMoveCube[j]);  // 4. move restores face
            }
        }

        fprintf(outputFile, "created\n");
    }

    fclose(outputFile);
}

vector<unsigned int> flip_move(N_FLIP* N_MOVE);
void build_move_flip() {
    const char* filename = "move_flip.txt";
    sprintf_s(filepath, "%s/%s", folder, filename);
    CubieCube a;
    errno_t err = fopen_s(&outputFile, filepath, "r");

    if (outputFile != NULL && IS_created(outputFile)) {
        cout << "loading " << filename << " table..." << endl;
        load_file(outputFile, flip_move);
    }
    else {
        if (outputFile != NULL)
            fclose(outputFile);
        errno_t err = fopen_s(&outputFile, filepath, "w");
        cout << "creating " << filename << " table..." << std::endl;

        for (int i = 0; i < N_FLIP; ++i) {
            a.set_flip(i);
            for (int j = 0; j < 6; ++j) {  // six faces U, R, F, D, L, B
                for (int k = 0; k < 3; ++k) {  // three moves for each face
                    a.Edge_Multiply(basicMoveCube[j]);
                    flip_move[N_MOVE * i + 3 * j + k] = a.get_flip();
                }
                a.Corner_Multiply(basicMoveCube[j]);  // 4. move restores face
            }
        }

        for (int i = 0; i < flip_move.size(); i++) {
            fprintf(outputFile, "%d\n", flip_move[i]);
        }
        fprintf(outputFile, "created\n");
    }

    fclose(outputFile);
}

vector<unsigned int> slice_sorted_move(N_SLICE_SORTED* N_MOVE);
void build_move_slice_sorted() {
    const char* filename = "move_slice_sorted.txt";
    sprintf_s(filepath, "%s/%s", folder, filename);
    CubieCube a;
    errno_t err = fopen_s(&outputFile, filepath, "r");

    if (outputFile != NULL && IS_created(outputFile)) {
        cout << "loading " << filename << " table..." << endl;
        load_file(outputFile, slice_sorted_move);
    }
    else {
        if (outputFile != NULL)
            fclose(outputFile);
        errno_t err = fopen_s(&outputFile, filepath, "w");
        cout << "creating " << filename << " table..." << std::endl;

        for (int i = 0; i < N_SLICE_SORTED; i++) {
            if (i % 200 == 0) 
                std::cout << '.' << std::flush;
            a.set_slice_sorted(i);
            for (int j = 0; j < 6;j++) {
                for (int k = 0; k < 3; k++) {
                    a.Edge_Multiply(basicMoveCube[j]);
                    slice_sorted_move[N_MOVE * i + 3 * j + k] = a.get_slice_sorted();
                }

                a.Edge_Multiply(basicMoveCube[j]);
            }
        }
        cout << endl;
        for (int i = 0; i < slice_sorted_move.size(); i++) {
            fprintf(outputFile, "%d\n", slice_sorted_move[i]);
        }
        fprintf(outputFile, "created\n");
    }

    fclose(outputFile);
}

vector<unsigned int> u_edges_move(N_SLICE_SORTED* N_MOVE);
void build_move_u_edges() {
    const char* filename = "move_u_edges.txt";
    sprintf_s(filepath, "%s/%s", folder, filename);
    CubieCube a;
    errno_t err = fopen_s(&outputFile, filepath, "r");

    if (outputFile != NULL && IS_created(outputFile)) {
        cout << "loading " << filename << " table..." << endl;
        load_file(outputFile, u_edges_move);
    }
    else {
        if(outputFile != NULL) 
            fclose(outputFile);
        errno_t err = fopen_s(&outputFile, filepath, "w");
        cout << "creating " << filename << " table..." << std::endl;

        for (int i = 0; i < N_SLICE_SORTED; i++) {
            if (i % 200 == 0)
                std::cout << '.' << std::flush;
            a.set_u_edges(i);
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 3; k++) {
                    a.Edge_Multiply(basicMoveCube[j]);
                    u_edges_move[N_MOVE * i + 3 * j + k] = a.get_u_edges();

                }

                a.Edge_Multiply(basicMoveCube[j]);
            }
        }
        cout << endl;
        for (int i = 0; i < u_edges_move.size(); i++) {
            fprintf(outputFile, "%d\n", u_edges_move[i]);
        }
        fprintf(outputFile, "created\n");
    }

    fclose(outputFile);
}

vector<unsigned int> d_edges_move(N_SLICE_SORTED* N_MOVE);
void build_move_d_edges() {
    const char* filename = "move_d_edges.txt";
    sprintf_s(filepath, "%s/%s", folder, filename);
    CubieCube a;
    errno_t err = fopen_s(&outputFile, filepath, "r");

    if (outputFile != NULL && IS_created(outputFile)) {
        cout << "loading " << filename << " table..." << endl;
        load_file(outputFile, d_edges_move);
    }
    else {
        if (outputFile != NULL)
            fclose(outputFile);
        errno_t err = fopen_s(&outputFile, filepath, "w");
        cout << "creating " << filename << " table..." << std::endl;

        for (int i = 0; i < N_SLICE_SORTED; i++) {
            if (i % 200 == 0)
                std::cout << '.' << std::flush;
            a.set_d_edges(i);
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 3; k++) {
                    a.Edge_Multiply(basicMoveCube[j]);
                    d_edges_move[N_MOVE * i + 3 * j + k] = a.get_d_edges();

                }

                a.Edge_Multiply(basicMoveCube[j]);
            }
        }
        cout << endl;
        for (int i = 0; i < d_edges_move.size(); i++) {
            fprintf(outputFile, "%d\n", d_edges_move[i]);
        }
        fprintf(outputFile, "created\n");
    }

    fclose(outputFile);
}

#endif
