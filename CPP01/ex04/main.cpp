#include <iostream>
#include <fstream>
#include <string>

// read file, copy to file.replace but changing every occurence of s1 to s2.
// s1 = dog / s2 = cat / file = the dog is gay / file.replace = the cat is gay.

std::string replaceStr(std::string str, const std::string &s1, const std::string &s2)
{
    size_t pos = 0;
    while ((pos = str.find(s1, pos)) != std::string::npos) // npos is no position found, system-defined
    {
        str.erase(pos, s1.length());
        str.insert(pos, s2);
        pos += s2.length();
    }
    return str;
}

void processFile(std::ifstream &in, std::ofstream &out, const std::string &s1, const std::string &s2)
{
    std::string buffer;
    while (getline(in, buffer))                             // reads one line at a time and stores in buffer
        out << replaceStr(buffer, s1, s2) << std::endl;     // writes the transformed line to the output file
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: Wrong number of argument\n";
        return -1;
    }
    std::string infile = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream myReadFile(infile.c_str());               // .c_str is just something for c++98 to compile
    if (!myReadFile)
    {
        std::cerr << "Error: cannot open input file\n";
        return -1;
    }
    std::string dest = infile + ".replace";                 // dest is where the output will be copied
    std::ofstream myWriteFile(dest.c_str());
    if (!myWriteFile)
    {
        std::cerr << "Error: cannot open output file\n";
        return -1;
    }
    processFile(myReadFile, myWriteFile, s1, s2);
    myReadFile.close();
    myWriteFile.close();
    return 0;
}
