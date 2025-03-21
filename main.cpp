#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
 
   
void traslazioneconmedia(std::string filename)
{   std::ifstream fstr(filename);
    if (fstr.fail()) {
        std::cerr << "File not found" << std::endl;
        return;
    } 
    std::string linea;             
    double numero;
    std::vector<double> vec;
    std::string filefinale = "result.txt";
    std::ofstream ofs(filefinale);
    ofs << std::scientific << std::setprecision(16);
    ofs << "# N Mean" << std::endl;

    
    while (fstr >> numero) {
        vec.push_back(numero);
        
    }

   
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = (3.0/4.0)*(vec[i]-1.0)-1.0;  
    }

    for (int i = 1; i <= vec.size(); ++i) {
        double somma = 0;
        for (int j = 0; j < i; ++j) {
            somma += vec[j];
        }
        double media = somma / i; 
        ofs << i << " " << media << std::endl;  }
}
       


int main()
{   std::cout << "Inserire nome del file" << std::endl;
    std::string filename;
    std::cin >> filename;
    traslazioneconmedia(filename);
	
    return 0;
}
