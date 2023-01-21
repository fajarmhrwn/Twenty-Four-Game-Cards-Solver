#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include <string>
#include <iostream>
using namespace std;

int chartoint(string cc);
/* Mengubah string angka ke int */

void saveAnswer(vector <string> s, string namaFile, int n);
/* I.S vector s, string namaFile, dan int n terdefinisi */
/* F.S n dan elemen vector s tersimpan di namaFile.txt */

bool checkValid(string input);
/* Mengembalikan true jika input valid */

void inputUser(int (&result)[4]);
/* I.S result terdefinisi */
/* F.S result terisi dengan input user */

void randomCard(int (&result)[4]);
/* I.S result terdefinisi */
/* F.S result terisi dengan random card */

void inttocard(int in);
/* I.S in terdefinisi */
/* F.S in ditulis dalam bentuk kartu */

void permutasiKartu(int a, int kedalaman, vector <int> &result,int input[4]);
/* I.S a, kedalaman, result, dan input terdefinisi */
/* F.S result terisi dengan permutasi kartu */

char inttochar(int in);
/* Mengubah int ke char */

void kombinasiOperator(vector <char> &result);
/* I.S result terdefinisi */
/* F.S result terisi dengan kombinasi operator */

void hitung1(char op1,char op2,char op3,int a, int b, int c, int d, int &n,vector <string> &s);
/* I.S op1, op2, op3, a, b, c, d, n, dan s terdefinisi */
/* F.S n dan s terisi dengan hasil perhitungan dari ((( a op1 b ) op2 c ) op3 d ) */

void hitung2(char op1,char op2,char op3,int a, int b, int c, int d, int &n,vector <string> &s);
/* I.S op1, op2, op3, a, b, c, d, n, dan s terdefinisi */
/* F.S n dan s terisi dengan hasil perhitungan dari ( a op1 b ) op2 ( c op3 d ) */

void hitung3(char op1,char op2,char op3,int a, int b, int c, int d, int &n,vector <string> &s);
/* I.S op1, op2, op3, a, b, c, d, n, dan s terdefinisi */
/* F.S n dan s terisi dengan hasil perhitungan dari ( a op1 ( b op2 c ) ) op3 d */

void hitung4(char op1,char op2,char op3,int a, int b, int c, int d, int &n,vector <string> &s);
/* I.S op1, op2, op3, a, b, c, d, n, dan s terdefinisi */
/* F.S n dan s terisi dengan hasil perhitungan dari a op1 ( ( b op2  c ) op3 d ) */

void hitung5(char op1,char op2,char op3,int a, int b, int c, int d, int &n,vector <string> &s);
/* I.S op1, op2, op3, a, b, c, d, n, dan s terdefinisi */
/* F.S n dan s terisi dengan hasil perhitungan dari a op1 (  b op2 ( c  op3 d ) ) */

int stringtoint(string cc);
/* Mengubah string angka ke int */

float hitung(char op, float a, float b);
/* Mengembalikan hasil perhitungan a op b */

void hapusSama(vector <string> &s, int &n);
/* I.S s dan n terdefinisi */
/* F.S s dan n terisi dengan elemen yang tidak sama */

bool isNumber(string s, vector <string> v);
/* Mengembalikan true jika s ada di v */

void readFile(int (&angka)[4]);
/* I.S angka terdefinisi */
/* F.S angka terisi dengan angka dari file */


#endif