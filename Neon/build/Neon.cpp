#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

//Token class !!
class Tokens{

    public:
        std::string objname;
        std::string identifier;
        int posx;
        int posy;
        int posz;
        int rotation;
        int scale;


};

class tokenizer{
    public:
        void tokenize(std::string line,Tokens& tokens){
            tokens = Tokens();
            std::istringstream iss(line);
            std::string curr_char;
            int count = 0;
            while (iss >> curr_char){
                if (count == 0){
                    tokens.objname = curr_char;
                } else if (count == 1){
                    tokens.identifier = curr_char;
                }else{
                    //Check if the data is not 1 char long
                    if (curr_char.length() < 2) continue;
                    char type = curr_char[0];
                    int dat = std::stoi(curr_char.substr(1));
                    //Very bad ik but it works
                    if (type == 'x'){
                        tokens.posx = dat;
                    }else if(type == 'y'){
                        tokens.posy = dat;
                    }else if (type == 'z'){
                        tokens.posz = dat;
                    }else if (type == 'r'){
                        tokens.rotation = dat;
                    }else if (type == 's'){
                        tokens.scale = dat;
                    }else {
                        std::cout << "Invalid data type: " << curr_char ; 
                        break;
                    }

                }
                ++count;
            }
            
        }

};

int main(){
    std::string uselesssvar;
    //File stuff
    std::ifstream file;
    std::string filename;
    std::cout << "Enter FileName: ";
    std::cin >> filename;

    file.open(filename,std::ios::in);

    std::string line;

    //Init the Token class
    Tokens tokens;
    tokenizer lexer;
    //Reading the file stuff
    int counter = 0;
    std::string temp;

    //Start timer
    auto start = std::chrono::high_resolution_clock::now();

    while (std::getline(file,line)){
        line.erase(0, line.find_first_not_of(" \t\r\n"));

        // Skip empty lines or comments
        if (line.empty() or line[0] == '#' or (line.size() >= 2 && line[0] == '/' && line[1] == '/')) {
        continue;
        }
        lexer.tokenize(line,tokens);
        /*
        std::cout << "name : " << tokens.objname << "\n"
        << "id : " << tokens.identifier << "\n"
        << "x : " << tokens.posx << "\n"
        <<  "y : " << tokens.posy << "\n"
        << "z : " << tokens.posz << "\n"
        << "r : " << tokens.rotation << "\n"
        << "s : " << tokens.scale << "\n";
        */
        
        /*
        Object{ # SceneObject
    TemplateName : 'platformwood0',
    Identifier : 'obj21',
    Position{ # Vector2
        X : 2232.24462890625,
        Y : -849.1557006835938,
    }
    Depth : 0.0,
    Rotation : 0.0,
    Scaling : 1.0,
    LocalAabb{ # Rectangle
        X : -54.653690338134766,
        Y : -6.8772125244140625,
        Width : 118.49516296386719,
        Height : 53.251014709472656,
    }
    Hidden : 0,
}
    */
        std::cout << "Object{" << "\n"
        << "\t" << "TemplateName : " << tokens.objname << "\n"
        << "\t" << "Identifier : " << tokens.identifier << "\n"
        << "\t" << "Position{" << "\n"
        << "\t\t" << "X : " << tokens.posx << "\n"
        << "\t\t" << "Y : " << tokens.posy << "\n"
        << "\t" << "}" << "\n"
        << "\t" << "Depth : " << tokens.posz << "\n"
        << "\t" << "Rotation : " << tokens.rotation << "\n"
        << "\t" << "Scaling : " << tokens.scale << "\n"
        << "\t" << "Hidden : 0" << "\n"
        << "}" << "\n";
        
    }

    

    // End timer
    auto end = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Parsing took " << duration.count() << " ms.\n";
    //Prevent exit :l
    std::cout << "press enter to end the program";
    std::cin >> uselesssvar;
    return 0;
}
