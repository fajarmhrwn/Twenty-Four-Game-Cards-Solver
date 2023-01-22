    #include <iostream>
    #include <string>
    #include "function.hpp"
    #include <sstream>
    #include <vector>
    #include <ctime>
    using namespace std::chrono;
    using namespace std;

    void mainGame(){
        int inputArr[4];
        vector <int> result;
        vector <char> resultOp;
        string caseNum;
        bool valid = false;
        do
        {
            cout << "Masukkan Input atau Random [1/2]: ";
            cin.clear();
            cin >> caseNum;
            if (caseNum == "1"|| caseNum == "2")
            {
                valid = true;
            }else{
                cout << "Input tidak valid" << endl;
            }
        } while (!valid);
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        if (caseNum == "1")
        {   
            bool status = false;
            do{
                cout << "File atau Keyboard [1/2]: ";
                cin >> caseNum;
                if(caseNum == "1" || caseNum == "2"){
                    status = true;
                }else{
                    cout << "Input tidak valid" << endl;
                }
                cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
            }while(!status);
            if(caseNum == "1"){
                readFile(inputArr);
            }else{
                inputUser(inputArr);
            }
        }
        else
        {
            randomCard(inputArr);
        }
        for (int i = 0; i < 4; i++)
        {
            cout << inputArr[i] << " ";
        }
        high_resolution_clock::time_point start_time = high_resolution_clock::now();
        permutasiKartu(4,0,result,inputArr);
        kombinasiOperator(resultOp);
        int n = 0;
        vector <string> s;
        for (int i = 0; i < result.size(); i = i+4)
        {
            for (int j = 0;j<resultOp.size();j = j+3){
                string input;
                input = to_string(result[i]) +" "+resultOp[j]+" "+ to_string(result[i+1])+" "+ resultOp[j+1]+" "+to_string(result[i+2])+" "+ resultOp[j+2]+" "+ to_string(result[i+3]);
                // cout << input << endl;
                hitung1(resultOp[j],resultOp[j+1],resultOp[j+2],stringtoint(to_string(result[i])),stringtoint(to_string(result[i+1])),stringtoint(to_string(result[i+2])),stringtoint(to_string(result[i+3])),n,s);
                hitung2(resultOp[j],resultOp[j+1],resultOp[j+2],stringtoint(to_string(result[i])),stringtoint(to_string(result[i+1])),stringtoint(to_string(result[i+2])),stringtoint(to_string(result[i+3])),n,s);
                hitung3(resultOp[j],resultOp[j+1],resultOp[j+2],stringtoint(to_string(result[i])),stringtoint(to_string(result[i+1])),stringtoint(to_string(result[i+2])),stringtoint(to_string(result[i+3])),n,s);
                hitung4(resultOp[j],resultOp[j+1],resultOp[j+2],stringtoint(to_string(result[i])),stringtoint(to_string(result[i+1])),stringtoint(to_string(result[i+2])),stringtoint(to_string(result[i+3])),n,s);
                hitung5(resultOp[j],resultOp[j+1],resultOp[j+2],stringtoint(to_string(result[i])),stringtoint(to_string(result[i+1])),stringtoint(to_string(result[i+2])),stringtoint(to_string(result[i+3])),n,s);
            }
        }
        hapusSama(s,n);
        high_resolution_clock::time_point final_time = high_resolution_clock::now();
        cout << endl <<"=========="<< endl;
        cout << n << " solusi ditemukan" << endl;
        cout <<"=========="<< endl;
        cout << "Solusi:" << endl;
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i] << endl;
        }
        cout <<"=========="<< endl;
        duration<double> time_span = duration_cast< duration<double> >(final_time - start_time);
        cout << "Waktu yang dibutuhkan: " << time_span.count() << " detik" << endl;
        bool status = false;
        do{
            cout << "Simpan ke file [Y/N]: ";
            cin >> caseNum;
            if(caseNum == "Y" || caseNum == "N"){
                status = true;
            }else{
                cout << "Input tidak valid" << endl;
            }
            cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        }while(!status);
        if(caseNum == "Y"){
            cout << "Masukkan nama file: ";
            string input;
            cin >> input;
            saveAnswer(s,input,n);
        }
    }

    void splahScreen(){
        printf("     _______. _______  __          ___      .___  ___.      ___   .___________.    _______       ___   .___________.    ___      .__   __.   _______ \n");
        printf("    /       ||   ____||  |        /   \\     |   \\/   |     /   \\  |           |   |       \\     /   \\  |           |   /   \\     |  \\ |  |  /  _____|\n");
        printf("   |   (----`|  |__   |  |       /  ^  \\    |  \\  /  |    /  ^  \\ `---|  |----`   |  .--.  |   /  ^  \\ `---|  |----`  /  ^  \\    |   \\|  | |  |  __  \n");
        printf("    \\   \\    |   __|  |  |      /  /_\\  \\   |  |\\/|  |   /  /_\\  \\    |  |        |  |  |  |  /  /_\\  \\    |  |      /  /_\\  \\   |  . `  | |  | |_ | \n");
        printf(".----)   |   |  |____ |  `----./  _____  \\  |  |  |  |  /  _____  \\   |  |        |  '--'  | /  _____  \\   |  |     /  _____  \\  |  |\\   | |  |__| | \n");
        printf("|_______/    |_______||_______/__/     \\__\\ |__|  |__| /__/     \\__\\  |__|        |_______/ /__/     \\__\\  |__|    /__/     \\__\\ |__| \\__|  \\______| \n");
        printf("                                                                                                                                                     \n");
        printf("  _______  ___   ___          ________  ________  _____ ______   _______           ________  ________  ___       ___      ___ _______   ________     \n");
        printf(" /  ___  \\|\\  \\ |\\  \\        |\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\         |\\   ____\\|\\   __  \\|\\  \\     |\\  \\    /  /|\\  ___ \\ |\\   __  \\    \n");
        printf("/__/|_/  /\\ \\  \\\\_\\  \\       \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|        \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\    \\ \\  \\  /  / | \\   __/|\\ \\  \\|\\  \\   \n");
        printf("|__|//  / /\\ \\______  \\       \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__       \\ \\_____  \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\/  / / \\ \\  \\_|/_\\ \\   _  _\\  \n");
        printf("    /  /_/__\\|_____|\\  \\       \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\       \\|____|\\  \\ \\  \\\\\\  \\ \\  \\____\\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\| \n");
        printf("   |\\________\\     \\ \\__\\       \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\        ____\\_\\  \\ \\_______\\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ _\\ \n");
        printf("    \\|_______|      \\|__|        \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|       |\\_________\\|_______|\\|_______|\\|__|/       \\|_______|\\|__|\\|__|\n");
        printf("                                                                                     \\|_________|                                                    \n");
        printf("                                                                                                                                                \n");
    }

    int main()
    {

        splahScreen();
        bool masihMain = true;
        while (masihMain)
        {
            string input;
            bool status = false;
            mainGame();
            do{
                cout << "Main Lagi? [Y/N]: ";
                cin >> input;
                if(input == "Y" || input == "N"){
                    status = true;
                }else{
                    cout << "Input tidak valid" << endl;
                }
            }while(!status);
            if (input == "Y")
            {
                masihMain = true;
            }
            if(input == "N")
            {
                masihMain = false;
            }
        }
    }
