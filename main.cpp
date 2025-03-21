#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
 
   
void traslazioneconmedia(int n) 
{   std::string nomefile= "data.txt";
    std::ifstream ifs(nomefile);      
    std::string linea;             
    double numero;
    std::vector<double> arr(n);
    std::string filefinale = "result.txt";
    std::ofstream ofs(filefinale);
    ofs << std::scientific << std::setprecision(16);
    ofs << "# N Mean" << std::endl;

    for (int i = 0; i < n && std::getline(ifs, linea); ++i) {
        numero = std::stod(linea);
        arr[i] = numero; }
    for (int i = 0; i < n; ++i) {
        arr[i] = (3.0/4.0)*(arr[i]-1.0)-1.0;  
    }

    for (int i = 1; i <= n; ++i) {
        double somma = 0;
        for (int j = 0; j < i; ++j) {
            somma += arr[j];
        }
        double media = somma / i; 
        ofs << i << " " << media << std::endl;  }
}
       


int main()
{   int n;
    std::cout << "Inserisci N così da creare il file e calcolare la media progressiva" << std::endl;
	std::cin >> n;
	traslazioneconmedia(n);
	
	
    

	    
   
    return 0;
}
