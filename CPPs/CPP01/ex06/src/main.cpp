#include "../includes/harl.hpp"

/*./harlFilter WARNING
argv[1] is "WARNING".
getLevel("WARNING") returns 2.
switch(level) jumps to case 2: and executes:*/


int main(int argc, char **argv)
{
    harlFilter harl;
    
    if (argc != 2)
    {
        std::cerr << "Error: Wrong number of arguments!\n";
        return -1;
    }

    int level = getLevel(argv[1]);
    switch(level)
    {
        case 0:
            harl.complain("DEBUG");
            // fall through
        case 1:
            harl.complain("INFO");
            // fall through
        case 2:
            harl.complain("WARNING");
            // fall through
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "Wrong argument. Try again\n";
            break;
    }
    return 0;
}