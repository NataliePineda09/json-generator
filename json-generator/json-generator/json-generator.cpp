#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Para la función rand()
#include <ctime> // Para la función time()
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

// Función para generar un valor aleatorio para un campo específico
string generarValorAleatorio() {
    // Aquí puedes implementar la lógica para generar valores aleatorios
    // Por ejemplo, podrías generar nombres, apellidos, edades aleatorias, etc.
    // En este ejemplo, simplemente generaremos una cadena aleatoria para representar la información aleatoria
    string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string valorAleatorio = "";
    int longitud = 10; // Longitud de la cadena aleatoria

    for (int i = 0; i < longitud; ++i) {
        valorAleatorio += caracteres[rand() % caracteres.length()];
    }

    return valorAleatorio;
}

// Función para generar un objeto JSON con campos aleatorios
json generarObjetoJSON(const vector<string>& campos) {
    json objetoJSON;

    for (const string& campo : campos) {
        objetoJSON[campo] = generarValorAleatorio();
    }

    return objetoJSON;
}

int main() {
    // Semilla para la generación de números aleatorios
    srand(time(0));

    // Pedir los campos del objeto
    cout << "Ingrese los campos del objeto separados por comas (ejemplo: nombre,apellidos,edad): ";
    string camposInput;
    getline(cin, camposInput);

    // Parsear los campos
    vector<string> campos;
    size_t pos = 0;
    while ((pos = camposInput.find(',')) != string::npos) {
        campos.push_back(camposInput.substr(0, pos));
        camposInput.erase(0, pos + 1);
    }
    campos.push_back(camposInput);

    // Pedir el número de repeticiones
    int repeticiones;
    cout << "Ingrese cuantas veces se va a repetir el objeto: ";
    cin >> repeticiones;

    // Generar y mostrar los objetos JSON
    json arrayJSON;
    for (int i = 0; i < repeticiones; ++i) {
        json objetoJSON = generarObjetoJSON(campos);
        arrayJSON.push_back(objetoJSON);
    }

    // Mostrar el resultado
    cout << arrayJSON.dump(2) << endl;

    return 0;
}
