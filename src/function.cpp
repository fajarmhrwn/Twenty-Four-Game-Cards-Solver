#include "function.hpp"
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
using std::ofstream;

int chartoint(string cc){
    int n = 0;
    if (cc == "A"){
        n = 1;
    }
    else if (cc == "2"){
        n = 2;
    }
    else if (cc == "3"){
        n = 3;
    }
    else if (cc == "4"){
        n = 4;
    }
    else if (cc == "5"){
        n = 5;
    }
    else if (cc == "6"){
        n = 6;
    }
    else if (cc == "7"){
        n = 7;
    }
    else if (cc == "8"){
        n = 8;
    }
    else if (cc == "9"){
        n = 9;
    }
    else if (cc == "10"){
        n = 10;
    }
    else if (cc == "J"){
        n = 11;
    }
    else if (cc == "Q"){
        n = 12;
    }
    else if (cc == "K"){
        n = 13;
    }
    else{
        n = -1;
    }
    return n;
}

void inttocard(int in){
    if (in == 1){
        cout << "A";
    }
    else if (in == 2){
        cout << "2";
    }
    else if (in == 3){
        cout << "3";
    }
    else if (in == 4){
        cout << "4";
    }
    else if (in == 5){
        cout << "5";
    }
    else if (in == 6){
        cout << "6";
    }
    else if (in == 7){
        cout << "7";
    }
    else if (in == 8){
        cout << "8";
    }
    else if (in == 9){
        cout << "9";
    }
    else if (in == 10){
        cout << "10";
    }
    else if (in == 11){
        cout << "J";
    }
    else if (in == 12){
        cout << "Q";
    }
    else if (in == 13){
        cout << "K";
    }
}

bool checkValid(string input)
{
    //check if input is empty
    if (input.empty())
    {
        cout << "Input is empty" << endl;
        return false;
    }
    //check if each card is valid
    stringstream ss(input);
    string temp;
    int n = 0;
    while (ss >> temp)
    {
        if (chartoint(temp) < 0)
        {
            cout << "Masukkan Huruf dan Angka Tidak Valid" << endl;
            return false;
        }
        n++;
    }
    //check if input is only have 4 cards
    if (n != 4)
    {
        cout << "Input is not 4 cards" << endl;
        return false;
    }
    return true;
}

void inputUser(int (&result)[4])
{
    //input user
    string input;
    //check input if valid when input is not empty, only have 4 cards, and each card is valid
    do{
        cout << "Masukkan kartu yang ingin di cek: ";
        getline(cin, input);
    }
    while (!checkValid(input));
    cout << "Input valid" << endl;
    stringstream ss(input);
    string temp;
    int n = 0;
    while (ss >> temp)
    {
        result[n] = chartoint(temp);
        n++;
    }
    
}
int n, catat[10];
bool status[10];
void randomCard(int (&result)[4])
{
    //random card
    for (int i = 0; i < 4; i++)
    {
        result[i] = rand() % 13 + 1;
        if (i != 4){
            inttocard(result[i]);
            cout << " ";
        }
    }
    cout << endl;
}
void tulis(int kedalaman, vector <int> &result, int input[4]){

    if(kedalaman >= n){

            for (int i = 0; i < n; i++)
            {
                result.push_back(input[catat[i]-1]);
            }
    }else{
        for(int i = 1;i<=n;i++){
            if(status[i] == false){
                status[i] = true;
                catat[kedalaman] = i;
                tulis(kedalaman+1, result, input);
                status[i] = false;
            }
        }
    }
}
void permutasiKartu(int a, int kedalaman, vector <int> &result,int input[4]){
    n = a;
    tulis(kedalaman,result,input);
}

char inttochar(int in){
    /*Menghasilkan Kartu sesuai konversi nilai pada kartu remi*/
    if (in == 1){
        return '+';
    }
    else if (in == 2){
        return '-';
    }
    else if (in == 3){
        return '*';
    }
    else if (in == 4){
        return '/';
    }
    else{
        return ' ';
    }
}

void kombinasiOperator(vector <char> &result){
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            for (int k = 1; k <= 4; k++)
            {
                result.push_back(inttochar(i));
                result.push_back(inttochar(j));
                result.push_back(inttochar(k));
            }
        }
    }
}

float hitung(float a, float b, char c){
    if (c == '+'){
        return a+b;
    }
    else if (c == '-'){
        return a-b;
    }
    else if (c == '*'){
        return a*b;
    }
    else if (c == '/'){
        return a/b;
    }
    else{
        return 0;
    }
}

void hitung1(char op1,char op2,char op3,int a, int b, int c, int d, int &n,vector <string> &s){
    float hasil = hitung(hitung(hitung(a,b,op1),c,op2),d,op3);
    string s1 = "(((" + to_string(a) + op1 + to_string(b) + ")" + op2 + to_string(c) + ")" + op3 + to_string(d) + ")=" + to_string(hasil); 
    // cout << s1 << endl;
    // cout << hasil << endl;
    if (hasil == 24){
        // s1 = "(((" + to_string(a) + op1 + to_string(b) + ")" + op2 + to_string(c) + ")" + op3 + to_string(d) + ")=" + to_string(hasil); 
        // // cout << s1 << endl;
        // cout << "Kartu yang anda masukkan dapat menghasilkan 24" << endl;
        s1 = "((" + to_string(a) + op1 + to_string(b) + ")" + op2 + to_string(c) + ")" + op3 + to_string(d) ;
        n++;
        s.push_back(s1);
    }

}

void hitung2(char op1,char op2,char op3,int a, int b, int c, int d, int &n, vector <string> &s){
    float hasil = hitung(hitung(a,b,op1),hitung(c,d,op3),op2);
    string s1 = "(" + to_string(a) + op1 + to_string(b) + ")" + op2 + "(" + to_string(c) + op3 + to_string(d) + ")=" + to_string(hasil);
    // cout << s1 << endl;
    // cout << hasil << endl;
    if (hasil == 24){
        // s1 = "(" + to_string(a) + op1 + to_string(b) + ")" + op2 + "(" + to_string(c) + op3 + to_string(d) + ")=" + to_string(hasil);
        // cout << s1 << endl;
        // cout << "Kartu yang anda masukkan dapat menghasilkan 24" << endl;
        s1 = "(" + to_string(a) + op1 + to_string(b) + ")" + op2 + "(" + to_string(c) + op3 + to_string(d) + ")";
        n++;
        s.push_back(s1);
    }
}

void hitung3(char op1,char op2,char op3,int a, int b, int c, int d, int &n,vector <string> &s){
    float hasil = hitung(hitung(a,hitung(b,c,op2),op1),d,op3);
    string s1 = "(" + to_string(a) + op1 + "(" + to_string(b) + op2 + to_string(c) + "))" + op3 + to_string(d) + "=" + to_string(hasil);
    // cout << s1 << endl;
    // cout << hasil << endl;
    if (hasil == 24){
        // string s1 = "(" + to_string(a) + op1 + "(" + to_string(b) + op2 + to_string(c) + "))" + op3 + to_string(d) + "=" + to_string(hasil);
        // // cout << s1 << endl;
        // cout << "Kartu yang anda masukkan dapat menghasilkan 24" << endl;
        s1 = "(" + to_string(a) + op1 + "(" + to_string(b) + op2 + to_string(c) + "))" + op3 + to_string(d) ;
        n++;
        s.push_back(s1);
    }

}

void hitung4(char op1,char op2,char op3,int a, int b, int c, int d, int &n,vector <string> &s){
    float hasil = hitung(a,hitung(hitung(b,c,op2),d,op3),op1);
    string s1 = "("+to_string(a) + op1 + "((" + to_string(b) + op2 + to_string(c) + ")" + op3 + to_string(d) + "))=" + to_string(hasil);
    // cout << s1 << endl;
    // cout << hasil << endl;
    if (hasil == 24){
        // s1 = "("+to_string(a) + op1 + "((" + to_string(b) + op2 + to_string(c) + ")" + op3 + to_string(d) + "))=" + to_string(hasil);
        // cout << s1 << endl;
        // cout << "Kartu yang anda masukkan dapat menghasilkan 24" << endl;
        s1 = to_string(a) + op1 + "((" + to_string(b) + op2 + to_string(c) + ")" + op3 + to_string(d) + ")";
        n++;
        s.push_back(s1);
    }

}

void hitung5(char op1,char op2,char op3,int a, int b, int c, int d, int &n,vector <string> &s){
    float hasil = hitung(a,hitung(b,hitung(c,d,op3),op2),op1);
    string s1 = "("+to_string(a) + op1 + "(" + to_string(b) + op2 + "(" + to_string(c) + op3 + to_string(d) + ")))=" + to_string(hasil);
    // cout << s1 << endl;
    // cout << hasil << endl;
    if (hasil == 24){
        // s1 = "("+to_string(a) + op1 + "(" + to_string(b) + op2 + "(" + to_string(c) + op3 + to_string(d) + ")))=" + to_string(hasil);
        // cout << s1 << endl;
        // cout << "Kartu yang anda masukkan dapat menghasilkan 24" << endl;
        s1 = to_string(a) + op1 + "(" + to_string(b) + op2 + "(" + to_string(c) + op3 + to_string(d) + "))";
        n++;
        s.push_back(s1);
    }
}

int stringtoint(string cc){
    if (cc == "1"){
        return 1;
    }else if(cc == "2"){
        return 2;
    }else if(cc == "3"){
        return 3;
    }else if(cc == "4"){
        return 4;
    }else if(cc == "5"){
        return 5;
    }else if(cc == "6"){
        return 6;
    }else if(cc == "7"){
        return 7;
    }else if(cc == "8"){
        return 8;
    }else if(cc == "9"){
        return 9;
    }else if(cc == "10"){
        return 10;
    }else if(cc == "11"){
        return 11;
    }else if(cc == "12"){
        return 12;
    }else if(cc == "13"){
        return 13;
    }else{
        return 0;
    }
}

bool isNumber(string s, vector <string> v){
    for (int i = 0; i < v.size(); i++){
        if (s == v[i]){
            return true;
        }
    }
    return false;
}

void hapusSama(vector <string> &s, int &n){
    vector <string> temp ;
    for (int i = 0; i < s.size(); i++){
        if (!isNumber(s[i],temp)){
            temp.push_back(s[i]);
        }
    }
    n = temp.size();
    s = temp;
}

void readFile(int (&angka)[4]){
    string namaFile;
    ifstream myfile;
    string line;
    do{
        cout << "Masukkan nama file: ";
        cin >> namaFile;
        myfile.open ("../test/"+namaFile);
        getline(myfile,line);
        if (checkValid(line)){
            cout << "Input valid" << endl;
            stringstream ss(line);
            string temp;
            int n = 0;
            while (ss >> temp)
            {
                angka[n] = chartoint(temp);
                n++;
            }
        }else{
            cout << "Input tidak valid" << endl;
        }    
        myfile.close();
    }while(!checkValid(line));
}

void saveAnswer(vector <string> s,string namaFile = "answer.txt", int n = 0){
    ofstream myfile;
    myfile.open ("../test/"+namaFile);
    myfile << "Jumlah kemungkinan = " << n << endl;
    for (int i = 0; i < s.size(); i++){
        myfile << s[i] << endl;
    }
    myfile.close();
}

