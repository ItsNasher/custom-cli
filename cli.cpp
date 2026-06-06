#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

// for updating whats inside the boxes
void gotoxy(int x, int y){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

void consoleLayout(){
    system("cls");
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "| NVIDIA-SMI 551.86            Driver Version: 551.86      CUDA Version: 12.4     |" << endl;
    cout << "+------------------------------------+---------------------+----------------------+" << endl;
    cout << "| GPU Name                  TCC/DDM  | Bus-Id       Disp.A | Volatile Uncorr.Ecc  |" << endl;
    cout << "| Fan Temp   Perf      Pwr:Usage/Cap |        Memory-Usage | GPU-Util  Compute M. |" << endl;
    cout << "|                                    |                     |               MIG M. |" << endl;
    cout << "|====================================+=====================+======================|" << endl;
    cout << "|   0 NVIDIA GeForce GTX 1080  WDDM  | 00000000:26:00.0 On |                  N/A |" << endl;
    cout << "|                                    |                     |                      |" << endl;
    cout << "|                                    |                     |                  N/A |" << endl;
    cout << "+------------------------------------+---------------------+----------------------+" << endl;
    cout << "" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "| Processes:                                                                      |" << endl;
    cout << "|  GPU   GI    CI    PID   Type   Process Name                         GPU Memory |" << endl;
    cout << "|        ID    ID                                                      Usage      |" << endl;
    cout << "|=================================================================================|" << endl;
}

// filled out in main
void consoleProcess(){
    cout << "|    0   N/A  N/A  1368    C+G   C:\\Windows\\System32\\dwm.exe             N/A      |" << endl;
    cout << "|    0   N/A  N/A  1369    C+G                                           N/A      |" << endl;
    cout << "|    0   N/A  N/A  2116    C+G                                           N/A      |" << endl;
    cout << "|    0   N/A  N/A  4224    C+G                                           N/A      |" << endl;
    cout << "|    0   N/A  N/A  5684    C+G                                           N/A      |" << endl;
    cout << "|    0   N/A  N/A  6767    C+G                                           N/A      |" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;
}

// formatting process names to fit
string formatString(string text, int maxWidth) {
    if (text.length() > maxWidth) {
        return "..." + text.substr(text.length() - (maxWidth - 3));
    } else {
        string paddedText = text;
        while (paddedText.length() < maxWidth) {
            paddedText += " ";
        }
        return paddedText;
    }
}

int main() {
    int fan = 10 + rand() % 40;
    int temp = 10 + rand() % 40;
    int power = rand() % 70;
    int memory = 4000 + (rand() % 2000);
    int gpu = 10 + rand() % 89;
    vector<string> processNames = {
        "C:\\Users\\delac\\Downloads\\take-home-exam\\node_modules",
        "C:\\Users\\delac\\AppData\\Roaming\\ModrinthApp\\profiles\\Cobblemon Delta",
        "chrome.exe",
        "Zed.exe",
        "GameManagerService.exe"
    }; 
    consoleLayout();
    consoleProcess();
    
    gotoxy(0, 8); // goes to line with missing values
    cout << "| " << fan << "%";
    cout << "   "<< temp << "C";
    cout << "    P8";
    cout << "         " << power << "W / 180W";
    cout << " |   " << memory << "MiB / 8192MiB";
    cout << " |     "<< gpu << "%";
    cout << "      Default |" << endl;

    // print process names
    for (int i = 0; i < processNames.size(); i++){
        string formatted = formatString(processNames[i], 35);
        gotoxy(34, 17 + i);
        cout << formatted;
    }
    cout << endl;
    gotoxy(0,30); // just to put cursor out of the way
    return 0;
}