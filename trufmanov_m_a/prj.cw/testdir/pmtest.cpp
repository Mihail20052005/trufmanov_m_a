#include"PeronaMalic/PeronaMalic.hpp"

int main(int argc, char** argv){
    std::string OutputDirectory;
    std::string InputDirectory;


    cv::Mat image;
    double lambda;
    double k;
    int iter;

    bool saveFile = false;
    bool demonstrationPeronaMalic = false;
    std::string executable_path = argv[0];

    if(argc == 1){
        std::cout << "Введите команду для дальнейшей работы" << std::endl;
        return 1;
    }
    if(argc > 1){
        for (int i = 1; i < argc; i++) {
            if(static_cast<std::string>(argv[i]) == "-m") {
                saveFile = true;
            }

            else if (static_cast<std::string>(argv[i]) == "-d"){
                demonstrationPeronaMalic = true;
            }

            else if(static_cast<std::string>(argv[i]).size() > 2){
                std::string param = static_cast<std::string>(argv[i]);
                if (param[0] == '-' && param[2] == '=') {
                    if (param[1] == 'l') {
                        InputDirectory = param.substr(3, param.size() - 3);
                    }
                    else if (param[1] == 's') {
                        OutputDirectory = param.substr(3, param.size() - 3);
                    }

                    else if (param[1] == 'k') {
                        k = std::stod(param.substr(3, param.size() - 3));
                        if (k < 0) {
                            std::cout << "k may be only positive" << std::endl;
                            return -1;
                        }
                    }
                    else if (param[1] == 'i') {
                        iter = std::stod(param.substr(3, param.size() - 3));
                        if (iter < 1) {
                            std::cout << "iter may be only positive" << std::endl;
                            return -1;
                        }
                    }
                    else if (param[1] == 'l') {
                        lambda = std::stod(param.substr(3, param.size() - 3));
                        if (lambda < 0) {
                            std::cout << "lambda may be only positive" << std::endl;
                            return -1;
                        }
                    }
                }
            }
        }
    }
    
    if(saveFile){
        cv::Mat image = cv::imread(InputDirectory, 0);
        auto p = PeronaMalic(image, lambda, k, iter);
        p.filterPeronaMalic();
        p.postFiler();
        p.saveImage(OutputDirectory, "saveFile mod");
    }

    if(demonstrationPeronaMalic){
        cv::Mat image = cv::imread(InputDirectory, 0);
        auto p = PeronaMalic(image, lambda, k, iter);
        p.demonstrationPM();
    }
}


