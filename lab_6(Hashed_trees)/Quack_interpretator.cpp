#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include<queue>
#include <map>

using namespace std;
int main() {
    setlocale(LC_ALL, "Rus");
    ios_base::sync_with_stdio(false);
    ifstream fin;
    fin.open("quack.in");
    ofstream fout;
    fout.open("quack.out");
    queue<unsigned short> q;
    map<string, long long> labels;
    vector<unsigned short> registers(26, 0);
    vector<string> commands;
    string command;
    char c_temp1, c_temp2;
    string s_temp;
    unsigned short x, y, i_temp;
    int i = 0;
    while (fin >> command) {
        if (command[0] == ':') {
            s_temp = command.substr(1);
            labels[s_temp] = i;
        }
        ++i;
        commands.push_back(command);
    }
    i = 0;
    while (i < commands.size()) {
        switch (commands[i][0]) {
        case 'Q':
            return 0;
        case ':': {
            break;
        }
        case '+': {
            x = q.front();
            q.pop();

            y = q.front();
            q.pop();
            q.push((x + y) % 65536);
            break;
        }
        case '-': {
            x = q.front();
            q.pop();

            y = q.front();
            q.pop();
            q.push(abs(65536 + x - y) % 65536);
            break;
        }
        case '*': {
            x = q.front();
            q.pop();

            y = q.front();
            q.pop();
            q.push(abs(x * y) % 65536);
            break;
        }
        case '/': {
            x = q.front();
            q.pop();

            y = q.front();
            q.pop();
            if (y == 0) {
                q.push(0);
            }
            else {
                q.push(x / y);
            }
            break;
        }
        case '%': {
            x = q.front();
            q.pop();

            y = q.front();
            q.pop();
            if (y == 0) {
                q.push(0);
            }
            else {
                q.push(x % y);
            }
            break;
        }
        case '>': {
            c_temp1 = commands[i][1];
            x = q.front();
            q.pop();
            registers[int(c_temp1) - 97] = x;
            break;
        }
        case '<': {
            c_temp1 = commands[i][1];
            q.push(registers[int(c_temp1) - 97] % 65536);
            break;
        }
        case 'P': {
            if (commands[i].size() == 1) {
                x = q.front();
                q.pop();
                fout << x << endl;
            }
            else {
                c_temp1 = commands[i][1];
                fout << registers[int(c_temp1) - 97] << endl;
            }
            break;
        }
        case 'C': {
            if (commands[i].size() == 1) {
                x = q.front();
                q.pop();
                fout << char(x % 256);
            }
            else {
                c_temp1 = commands[i][1];
                fout << char(registers[int(c_temp1) - 97] % 256);
            }
            break;
        }
        case 'J': {
            s_temp = commands[i].substr(1);
            i = labels[s_temp] - 1;
            break;
        }
        case 'Z': {
            c_temp1 = commands[i][1];
            if (registers[int(c_temp1) - 97] == 0) {
                i = labels[commands[i].substr(2)] - 1;
            }
            break;
        }
        case 'E': {
            c_temp1 = commands[i][1];
            c_temp2 = commands[i][2];
            if (registers[int(c_temp1) - 97] == registers[int(c_temp2) - 97]) {
                i = labels[commands[i].substr(3)] - 1;
            }
            break;
        }
        case 'G': {
            c_temp1 = commands[i][1];
            c_temp2 = commands[i][2];
            if (registers[int(c_temp1) - 97] > registers[int(c_temp2) - 97]) {
                i = labels[commands[i].substr(3)] - 1;
            }
            break;
        }
        default: {
            s_temp = commands[i];
            i_temp = atoi(&s_temp[0]);
            q.push(i_temp % 65536);
            break;
        }
        }
        ++i;
    }
    return 0;
}