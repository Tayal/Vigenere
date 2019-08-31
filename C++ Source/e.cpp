#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<fstream>
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
    	cout << "'encipher <file>'\n";
    	return 0;
    }
    ofname = ifname;

    cout << "Key?\n";
    string key;
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
        string encode;
        for(int j=0; j<msg.length(); j++)
        {
            if(int(toupper(msg[j])) <= 64 || int(toupper(msg[j])) > 90)
            {
                encode += msg[j];
                continue;
            }

            i %= l;
            int I = int(toupper(key[i]))-65;
            int J = int(toupper(msg[j]))-65;

            if(islower(msg[j]))
            	encode += tolower(vig[I][J]);
            else
            	encode += toupper(vig[I][J]);
            i++;
        }
        fileout << encode << endl;
    }
    filein.close();
    remove(&ifname[0]);
    fileout.close();
    cout << "Done!" << endl;
}
