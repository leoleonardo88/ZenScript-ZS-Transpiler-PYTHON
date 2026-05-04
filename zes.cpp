#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> // Para usar system()

using namespace std;

int main(int argc, char* argv[]) {
    // Verificação mínima de argumentos: zes <arquivo> --name <saida>
    if (argc < 4) {
        cout << "Uso: zes <input.zs> --name <output.exe>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputName = argv[3];
    string tempPy = "temp_build.py";

    ifstream input(inputFile);
    ofstream output(tempPy);
    string line;

    if (!input.is_open()) {
        cerr << "Erro ao abrir " << inputFile << endl;
        return 1;
    }

    // --- Tradução Simples ---
    output << "import sys\n\n";
    while (getline(input, line)) {
        if (line.find("text.console") != string::npos) {
            size_t start = line.find("(\"") + 2;
            size_t end = line.find("\")");
            output << "print(\"" << line.substr(start, end - start) << "\")\n";
        }
    }
    input.close();
    output.close();

    // --- Transformando em .EXE ---
    // Aqui usamos o PyInstaller para converter o script Python gerado em um executável real
    cout << "Gerando executavel: " << outputName << "..." << endl;
    
    string command = "pyinstaller --onefile --name " + outputName.substr(0, outputName.find(".exe")) + " " + tempPy;
    
    // Executa o comando no sistema
    int result = system(command.c_str());

    if (result == 0) {
        cout << "\n>>> Sucesso! " << outputName << " criado com exito." << endl;
        // Limpeza de arquivos temporários (opcional)
        system("rm temp_build.py"); 
    } else {
        cout << "\nErro: Verifique se o PyInstaller esta instalado (pip install pyinstaller)." << endl;
    }

    return 0;
}