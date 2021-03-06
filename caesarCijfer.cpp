#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::getline;


int main(int argc, char *argv[]){
    int rotaties = 0;
    string arguments(argv[1]);

    try{
        rotaties = std::stoi(argv[1]);
    }
    catch (const std::invalid_argument& ia){
        std::cerr << "Het argument " << arguments << " is geen geldig argument.\nEen geldig argument bestaat uit een positief of een negatief getal.\nFunctie: " << ia.what() << endl;
        return 0;
    }

    rotaties = ((rotaties % 26) + 26) % 26;

    string input;
    string output;

    while(getline(cin, input)){
        if (input[0] == 0x04){
            break;
        }
        if (rotaties == 0){
            output += input + '\n';
            continue;
        }
        
        for (size_t i = 0; i < input.size(); i++){
            if (input[i] >= 'A' && input[i] <= 'Z'){
                input[i] |= (1<<5);
            }
            
            if (input[i] < 'a' || input[i] > 'z'){
                output += input[i];
                continue;
            }
          
            if ((input[i] + rotaties) > 'z'){
                output += (((input[i] + rotaties) % 122) | 0x60);
            }
            else{
                output += (((input[i] + rotaties) % 123) | 0x60);
            }
        }
        output += '\n';
    }
    
    cout << output;
    return 0;
}
