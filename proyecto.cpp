#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

//Struct que usaremos para los juegos
struct juego 
{
    string titulo;       
    string desarrollador; 
    int id;               
    float calificacion;   
    double precio;        
    char categoria;       
    bool esDigital;       
    bool ocupado = false;
};

//Declaracion de la matriz
typedef vector<vector<juego>> Matrizjuegos; 

//Funcion para verificar si ya existe un id repetido
bool idExiste(const Matrizjuegos& m, int idBusca) 
{
    for (const auto& fila : m) 
        for (const auto& j : fila)
            if (j.ocupado && j.id == idBusca) return true;
    return false;
}
//Validcacion de enteros
int leerInt(string m) 
{
    int v; cout << m;
    while (!(cin >> v)) {
        cout << "Debes ingresar un numero: ";
        cin.clear(); cin.ignore(1000, '\n');
    }
    return v;
}


//Operaciones que se van a hacer en la matriz
void insertar(Matrizjuegos& m) {
    for (int i = 0; i < m.size(); i++) 
    {
        for (int j = 0; j < m[i].size(); j++) 
        {
            if (!m[i][j].ocupado) {
                cout << "\nSe registra en: [" << i << "][" << j << "] \n";
                int nuevoId;
                do 
                {
                    nuevoId = leerInt("ID unico: ");
                    if (idExiste(m, nuevoId)) cout << "Este ID ya se usa\n";
                } while (idExiste(m, nuevoId));

                m[i][j].id = nuevoId;
                cin.ignore(); 
                cout << "Titulo: "; getline(cin, m[i][j].titulo);
                cout << "Desarrollador: "; getline(cin, m[i][j].desarrollador);
                
                cout << "Precio base: ";
                while (!(cin >> m[i][j].precio)) {
                    cout << "Error. Ingrese un precio numerico: ";
                    cin.clear(); cin.ignore(1000, '\n');
                }

                cout << "Calificacion (0-10): ";
                while (!(cin >> m[i][j].calificacion)) {
                    cout << "Error. Ingrese un numero para la calificacion: ";
                    cin.clear(); cin.ignore(1000, '\n');
                }

                // Validacion de categoria
                while (true) {
                    cout << "Categoria (A/R/D): "; cin >> m[i][j].categoria;
                    m[i][j].categoria = toupper(m[i][j].categoria);
                    if (m[i][j].categoria == 'A' || m[i][j].categoria == 'R' || m[i][j].categoria == 'D') break;
                    cout << "Categoria no valida. ";
                }

                // Validacion de formato, digital o fisico
                cout << "Es digital? (1: si / 0: no): ";
                while (!(cin >> m[i][j].esDigital)) {
                    cout << "Error. Ingrese 1 para si o 0 para no: ";
                    cin.clear(); cin.ignore(1000, '\n');
                }

                if(m[i][j].esDigital) 
                {
                    m[i][j].precio *= 0.90; // Descuento especial por ser digital
                    cout << ">> Se ha aplicado un descuento del 10% al ser digital \n";
                }

                m[i][j].ocupado = true;
                return;
            }
        }
    }
    cout << "Inventario lleno, debe eliminar un juego antes de continuar\n";
}

//Funcion para mostrar la tabla
void mostrarTabla(const Matrizjuegos& m) 
{
    cout << "\n" << left << setw(5) << "POS" << setw(6) << "ID" << setw(15) << "TITULO" 
         << setw(15) << "DESARROLLADOR" << setw(10) << "PRECIO" << setw(10) << "FORMATO" << "CALIF" << endl;
    cout << "--------------------------------------------------------------------------------\n";
    for (int i = 0; i < m.size(); i++) 
    {
        for (int j = 0; j < m[i].size(); j++) {
            cout << "[" << i << j << "]\t";
            if (m[i][j].ocupado) {
                cout << left << setw(6) << m[i][j].id 
                     << setw(15) << m[i][j].titulo 
                     << setw(15) << m[i][j].desarrollador 
                     << "$" << setw(9) << fixed << setprecision(2) << m[i][j].precio 
                     << setw(10) << (m[i][j].esDigital ? "DIGITAL" : "FISICO")
                     << m[i][j].calificacion << endl;
            } else {
                cout << "--    [ ESPACIO VACIO ]" << endl;
            }
        }
    }
}

//Funcion que permite modificar los registros existentes
void modificar(Matrizjuegos& m) 
{
    int idB = leerInt("ID a modificar: ");
    for (auto& fila : m) for (auto& j : fila) 
    {
        if (j.ocupado && j.id == idB) {
            cout << "Modifica: " << j.titulo << endl;
            
            // Pedimos el precio base de nuevo para recalcular el descuento correctamente
            cout << "Nuevo precio base: ";
            while (!(cin >> j.precio)) {
                cout << "Error numerico. Nuevo precio: ";
                cin.clear(); cin.ignore(1000, '\n');
            }

            cout << "Nueva calificacion: ";
            while (!(cin >> j.calificacion)) {
                cout << "Error numerico. Nueva calificacion: ";
                cin.clear(); cin.ignore(1000, '\n');
            }
            
            // Validacion de categoria
            while (true) {
                cout << "Nueva Categoria (A/R/D): "; cin >> j.categoria;
                j.categoria = toupper(j.categoria);
                if (j.categoria == 'A' || j.categoria == 'R' || j.categoria == 'D') break;
                cout << "Categoria no valida. ";
            }

            // Validacion de formato digital o fisico
            cout << "Es digital ahora? (1: si / 0: no): ";
            while (!(cin >> j.esDigital)) {
                cout << "Error. Ingrese 1 o 0: ";
                cin.clear(); cin.ignore(1000, '\n');
            }

            // Aplicar descuento si es digital
            if(j.esDigital) 
            {
                j.precio *= 0.90; 
                cout << ">> Se ha actualizado el descuento del 10% por formato digital \n";
            }

            cout << "--- Registro actualizado ---\n"; return;
        }
    }
    cout << "--- No se ha encontrado ---\n";
}
//Funcion para eliminar un registro
void eliminar(Matrizjuegos& m) {
    int idB = leerInt("ID a eliminar: ");
    for (auto& fila : m) for (auto& j : fila) 
    {
        if (j.ocupado && j.id == idB) {
            j = juego(); 
            cout << "--- Eliminado ---\n"; return;
        }
    }
    cout << "--- No se ha encontrado ---\n";
}

//Fucion para ordenar los precios de los juegos
void ordenar(Matrizjuegos& m) 
{
    for (auto& fila : m) {
        sort(fila.begin(), fila.end(), [](juego a, juego b) 
        {
            if (!a.ocupado) return false; if (!b.ocupado) return true; //Esta parte asegura que los espacios vacios queden al final
            return a.precio < b.precio;
        });
    }
    cout << "--- Filas ordenadas por precio ---\n";
}

//Operaciones del struct, analisis
void analizarStruct(const Matrizjuegos& m) 
{
    float maxC = -1.0; string mejor = "N/A";
    double suma = 0; int cont = 0;
    for (const auto& f : m) for (const auto& j : f) if (j.ocupado) 
    {
        if (j.calificacion > maxC) { maxC = j.calificacion; mejor = j.titulo; }
        suma += j.precio; cont++;
    }
    if (cont > 0) 
    {
        cout << "\nMayor calificacion: " << mejor << " (" << maxC << ")\n"; //Este ocupa el float para ver la calificacion
        cout << "Precio promedio de los juegos: $" << (suma/cont) << endl; //Este otro el double para ver el promedio
    }
}

//La funcion para buscar un juego por su nombre
void buscarNombre(const Matrizjuegos& m) {
    cin.ignore();
    cout << "Nombre exacto a buscar: ";
    string busca; getline(cin, busca);
    for (const auto& f : m) for (const auto& j : f) {
        if (j.ocupado && j.titulo == busca) {
            cout << "\n--- FICHA TECNICA COMPLETA ---" << endl;
            cout << "ID: " << j.id << " | Categoria: " << j.categoria << endl;
            cout << "Titulo: " << j.titulo << endl;
            cout << "Desarrollador: " << j.desarrollador << endl;
            cout << "Precio Final: $" << j.precio << endl;
            cout << "Calificacion: " << j.calificacion << endl;
            cout << "Formato: " << (j.esDigital ? "Digital" : "Fisico") << endl;
            return;
        }
    }
    cout << "--- No encontrado ---\n";
}

//Funcion principal, aqui desplegamos el menu
int main() {
    Matrizjuegos ElCientificoDeJuegos(2, vector<juego>(2)); 
    int op;
    do {
        cout << "\n1.Agregar 2.Ver inventario 3.Modificar 4.Eliminar un juego 5.Ordenar por precio 6.Analizar 7.Buscar 0.Salir\nOp: ";
        op = leerInt("");
        switch(op) {
            case 1: insertar(ElCientificoDeJuegos); break;
            case 2: mostrarTabla(ElCientificoDeJuegos); break;
            case 3: modificar(ElCientificoDeJuegos); break;
            case 4: eliminar(ElCientificoDeJuegos); break;
            case 5: ordenar(ElCientificoDeJuegos); break;
            case 6: analizarStruct(ElCientificoDeJuegos); break;
            case 7: buscarNombre(ElCientificoDeJuegos); break;
        }
    } while (op != 0);
    return 0;
}