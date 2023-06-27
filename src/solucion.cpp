#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <chrono>
#include <thread>
#include "../lib/saColor.h"

using namespace std;

const int saIntentosMax = 3;

void saIniciarSesion() {
    string saNombreUsuario;
    string saContrasena;
    int intentos = 0;

    string saNombreUsuarioRegistrado1 = "stalin";
    string saContrasenaRegistrada1 = "1755168232";
    string saNombreUsuarioRegistrado2 = "profe";
    string saContrasenaRegistrada2 = "1234";

    setTextColor(textColorGreen);
    cout << "\n=== Inicio de sesion ===" << endl;
    setTextColor(textColorRed);
    cout << "Posee 3 intentos" << endl << endl;
    while (intentos < saIntentosMax) {
        setTextColor(textColorYellow);
        cout << "Nombre de usuario: ";
        cin >> saNombreUsuario;
        cout << "Contrasena: ";
        cin >> saContrasena;

        if ((saNombreUsuario == saNombreUsuarioRegistrado1 || saNombreUsuario == saNombreUsuarioRegistrado2) && (saContrasena == saContrasenaRegistrada1 || saContrasena == saContrasenaRegistrada2))
        {
            for (char& saC : saNombreUsuario)
            {
                saC = toupper(static_cast<unsigned char>(saC));
            }
            setTextColor(textColorBlack);
            cout << "\n\nInicio de sesion exitoso. [+] Bienvenido, " << saNombreUsuario << "!" << endl;
            return;
        }
        
        else
        {
            setTextColor(textColorBlack);
            cout << "Nombre de usuario o contrasena incorrectos. Inicio de sesion fallido." << endl;
            intentos++;
        }
    }
    setTextColor(textColorRed);
    cout << "Ha excedido el numero maximo de intentos. El programa termino." << endl;
    exit(0);
}

bool saValidarEstado(const bool caperucita, const bool lobo, const bool uvas) {
    // Verifica si la caperucita y las uvas están en el mismo lado sin la lobo
    if (caperucita == uvas && caperucita != lobo)
        return false;

    return true;
}

bool saVerificarFinal(const bool caperucita, const bool lobo, const bool uvas) {
    // Verifica si todos los elementos están en el otro lado del rio
    return !caperucita && !lobo && !uvas;
}

void saClearPantallazo() {
    // Limpia la pantalla
    cout << "\033[2J\033[1;1H";
}

void saAnimarMov(const string& elemento, const string& direccion) {
    // Simula el movimiento de un elemento hacia el otro lado del rio
    saClearPantallazo();
    cout << "Moviendo " << elemento << " hacia " << direccion << "..." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    saClearPantallazo();
    cout << elemento << " movido hacia " << direccion << " con exito!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
}

void saMostrarMenu() {
    setTextColor(textColorBlue);
    cout << "----Navegante----" << endl;
    cout << "1. Mover la caperucita" << endl;
    cout << "2. Mover el lobo" << endl;
    cout << "3. Mover las uvas" << endl;
    cout << "4. Salir" << endl;
}

void saJuego() {
    bool caperucita = true;
    bool lobo = true;
    bool uvas = true;
    setTextColor(textColorGreen);
    cout << "Bienvenido al juego de la caperucita, el lobo y las uvas" << endl;

    while (true) {
        cout << endl;
        cout << "Estado actual: ";

        if (caperucita) cout << "caperucita ";
        else cout << "- ";

        if (lobo) cout << "lobo ";
        else cout << "- ";

        if (uvas) cout << "uvas";
        else cout << "-";

        cout << endl << endl;

        if (saVerificarFinal(caperucita, lobo, uvas)) {
            setTextColor(textColorYellow);
            cout << "Felicidades Has llevado con exito a todos los elementos al otro lado del rio." << endl;
            break;
        }

        saMostrarMenu();

        int opcion;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (caperucita)
                {
                    saAnimarMov("la caperucita", "el otro lado");
                    caperucita = false;
                }
                else
                {
                    cout << "La caperucita ya se encuentra en el otro lado del rio." << endl;
                }
                break;
            case 2:
                if (lobo)
                {
                    saAnimarMov("el lobo", "el otro lado");
                    lobo = false;
                }
                else
                {
                    cout << "El lobo ya se encuentra en el otro lado del rio." << endl;
                }
                break;
            case 3:
                if (uvas)
                {
                    saAnimarMov("el uvas", "el otro lado");
                    uvas = false;
                }
                else
                {
                    cout << "El uvas ya se encuentra en el otro lado del rio." << endl;
                }
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                return;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
                break;
        }

        if (!saValidarEstado(caperucita, lobo, uvas)) {
            cout << "Has perdido. La caperucita y el uvas se quedaron solos en el mismo lado del rio." << endl;
            break;
        }
    }
}

int main()
{
    setTextColor(textColorRed);
    printf ("\n[+] Datos: ");
    setTextColor(textColorBlue);
    printf("\n- CEDULA: 1755168232\n- CORREO: stalin.anrango@epn.edu.ec\n- NOMBRE: STALIN RENE ANRANGO BURGA\n");

    saIniciarSesion();
    saJuego();

    return 0;
}