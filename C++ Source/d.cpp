#include<iostream>
#include<vector>
#include<cstdio>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char **argv)
{
    char vig[26][26];
    string x = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i=0; i<26; i++)
    {
        int pos = i;
        for(int j=0; j<26; j++)
        {
            pos %= 26;
            vig[i][j] = x[pos++];
        }
    }

    string ifname,ofname,msg;
    if(argc == 2)
        ifname = argv[1];
    else
    {
        cout << "'decipher <file>'\n";
        return 0;
    }
    ofname = ifname;

    string key;
    cout << "Key?\n";
    cin >> key;

    rename(&ifname[0], "xzqtt.txt");
    ifname = "xzqtt.txt";

    ifstream filein(ifname);
    if(!filein.is_open())
    {
        cout << "File not found.\n";
        return 0;
    }
    ofstream fileout(ofname);
    if(!fileout.is_open())
    {
        cout << "Error.\n";
        return 0;
    }
    cin.ignore();

    int i=0, l=key.length();
    while(getline(filein, msg))
    {
        string decode;
        for(int j=0; j<msg.length(); j++)
        {
            if(int(toupper(msg[j])) <= 64 || int(toupper(msg[j])) > 90)
            {
                decode += msg[j];
                continue;
            }

            i %= l;
            int I = 0;
            int J = (int(toupper(msg[j]))-65)-(int(toupper(key[i]))-65);
            if(J < 0)
                J = 26-(-J%26);

            if(islower(msg[j]))
                decode += tolower(vig[I][J]);
            else
                decode += toupper(vig[I][J]);
            i++;
        }
        fileout << decode << endl;
    }
    filein.close();
    remove(&ifname[0]);
    fileout.close();
    cout << "Done!" << endl;
}