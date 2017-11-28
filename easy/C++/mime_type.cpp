#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

void toLower(string& str) 
{
    int string_size = str.size();
    for (int i = 0; i < string_size; ++i)
    {
        str[i] = tolower(str[i]);
    }
}

vector<string> splitString(const string& str, const char& delim)
{
    vector<string> result;
    stringstream ss(str);
    string item = "";
    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }
    if (str.length() > 0 && str[str.length() - 1] == delim)
    {
        result.push_back("");
    }
    return result;
}

int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    
    map <string, string> mimetype;
    for (int i = 0; i < N; i++) 
    {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        toLower(EXT);
        mimetype[EXT] = MT;
    }
    
    int vector_size = 0;
    string extension = "";
    for (int i = 0; i < Q; i++) 
    {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        cerr << FNAME << endl;
        
        string result = "UNKNOWN";
        vector<string> splitted = splitString(FNAME, '.');
        vector_size = splitted.size();
        if (vector_size > 1) 
        {
            extension = splitted[vector_size - 1];
            toLower(extension);
            map<string,string>::iterator it = mimetype.find(extension);
            if (it != mimetype.end())
            {
                result = it -> second;
            }
        }
        cout << result << endl;
    }
}