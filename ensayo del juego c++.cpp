// JUEGO CRAPS--------SEBASTIAN LLIVE-SEBASTIAN MORA.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

struct Jugador {
    string nombre;
    int puntaje;
};

void mostrarPuntajes(Jugador jugadores[], int cantidadJugadores) {
    cout << "Puntajes de los jugadores:" << endl;
    for (int i = 0; i < cantidadJugadores; i++) {
        cout << jugadores[i].nombre << ": " << jugadores[i].puntaje << endl;
    }
}

void mostrarDibujoDado(int valor) {
    switch (valor) {
        case 1:
            cout << "\t\t\t  +-------+\n";
            cout << "\t\t\t  |       |\n";
            cout << "\t\t\t  |   *   |\n";
            cout << "\t\t\t  |       |\n";
            cout << "\t\t\t  +-------+\n";
            break;
        case 2:
            cout << "\t\t\t  +-------+\n";
            cout << "\t\t\t  | *     |\n";
            cout << "\t\t\t  |       |\n";
            cout << "\t\t\t  |     * |\n";
            cout << "\t\t\t  +-------+\n";
            break;
        case 3:
            cout << "\t\t\t  +-------+\n";
            cout << "\t\t\t  | *     |\n";
            cout << "\t\t\t  |   *   |\n";
            cout << "\t\t\t  |     * |\n";
            cout << "\t\t\t  +-------+\n";
            break;
        case 4:
            cout << "\t\t\t  +-------+\n";
            cout << "\t\t\t  | *   * |\n";
            cout << "\t\t\t  |       |\n";
            cout << "\t\t\t  | *   * |\n";
            cout << "\t\t\t  +-------+\n";
            break;
        case 5:
            cout << "\t\t\t  +-------+\n";
            cout << "\t\t\t  | *   * |\n";
            cout << "\t\t\t  |   *   |\n";
            cout << "\t\t\t  | *   * |\n";
            cout << "\t\t\t  +-------+\n";
            break;
        case 6:
            cout << "\t\t\t  +-------+\n";
            cout << "\t\t\t  | *   * |\n";
            cout << "\t\t\t  | *   * |\n";
            cout << "\t\t\t  | *   * |\n";
            cout << "\t\t\t  +-------+\n";
            break;
    }
}

void jugar(Jugador jugadores[], int cantidadJugadores) {
    const string black = "\033[30m";
    const string bright_red = "\033[91m";
    const string bright_cyan = "\033[96m";
    const string bg_magenta = "\033[45m";
    const string bg_white = "\033[47m";
    const string reset = "\033[0m";

    int dado1, dado2, suma, punto;
    string nombreJugadorActual;
    bool esPrimerTiro = true;

    for (int i = 0; i < cantidadJugadores; i++) {
        nombreJugadorActual = jugadores[i].nombre;
        cout << "   \t\t       " << black << bg_white << "Turno de " << nombreJugadorActual << reset << endl << endl;
        punto = 0;
        esPrimerTiro = true;
        int primerDado1, primerDado2, primerSuma;

        do {
            cout << "Presione cualquier tecla para tirar los dados...\n";
            getch();  // Espera a que el usuario presione una tecla
            dado1 = rand() % 6 + 1;
            dado2 = rand() % 6 + 1;
            suma = dado1 + dado2;

            cout << bright_cyan << "Dado 1: " << reset << dado1 << endl;
            mostrarDibujoDado(dado1);
            cout << bright_cyan << "Dado 2: " << reset << dado2 << endl;
            mostrarDibujoDado(dado2);
            cout << bright_red << "Suma: " << reset << suma << endl << endl;

            if (esPrimerTiro) {
                primerDado1 = dado1;
                primerDado2 = dado2;
                primerSuma = suma;

                if (suma == 7 || suma == 11) {
                    jugadores[i].puntaje += 10;
                    cout << "Gano 10 puntos!\n" << endl;
                    break;
                } else if (suma == 2 || suma == 3 || suma == 12) {
                    jugadores[i].puntaje -= 5;
                    cout << "\nPerdio 5 puntos!\n" << endl;
                    break;
                } else {
                    punto = suma;
                    esPrimerTiro = false;
                    cout << "\nPuntos establecidos: " << punto << endl << endl;
                }
            } else {
                if (suma == punto) {
                    jugadores[i].puntaje += 10;
                    cout << "Gano 10 puntos!\n" << endl;
                    break;
                } else if (suma == 7) {
                    jugadores[i].puntaje -= 5;
                    cout << "Perdio 5 puntos!\n" << endl;
                    break;
                }
            }
        } while (true);

        cout << "Primer tiro ---> Dado 1: " << primerDado1 << " \t Dado 2: " << primerDado2 << " ---> Suma: " << primerSuma << endl;
        cout << endl;
    }
}

void mostrarCreditos() {
    cout << "\n                                       \t\t  CREDITOS:" << endl;
    cout << "\n                                            Integrantes del grupo:" << endl;
    cout << "                                      - Sebastian Eduardo Mora Guerrero." << endl;
    cout << "                                      - Sebastian Alexander Llive Pallo.\n" << endl;
}

int main() {
    const string magenta = "\033[35m";
    const string cyan = "\033[36m";
    const string reset = "\033[0m";

    srand(time(0));
    int cantidadJugadores;

    do {
        cout << "Ingrese la cantidad de jugadores (max 10): ";
        cin >> cantidadJugadores;
        cout << endl;
        if (cantidadJugadores < 1 || cantidadJugadores > 10) {
            cout << "Cantidad invalida. Intente nuevamente.\n" << endl;
            cout << "__________________________________________________" << endl;
        }
    } while (cantidadJugadores < 1 || cantidadJugadores > 10);

    Jugador jugadores[cantidadJugadores];

    for (int i = 0; i < cantidadJugadores; i++) {
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> jugadores[i].nombre;
        jugadores[i].puntaje = 0;
    }

    int opcion;
    do {
        cout << "\n<=================================================================================================================>" << endl;
        cout << magenta << "\t\t\t\t\t----------JUEGO CRAPS----------" << reset << endl;
        cout << cyan << "1. Jugar" << endl;
        cout << "2. Puntajes" << endl;
        cout << "3. Salir" << endl;
        cout << "4. Creditos" << reset << endl;
        cout << "\nIngrese su opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1:
                jugar(jugadores, cantidadJugadores);
                break;
            case 2:
                mostrarPuntajes(jugadores, cantidadJugadores);
                break;
            case 3:
                cout << "Saliendo del juego..." << endl;
                break;
            case 4:
                mostrarCreditos();
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 3);

    return 0;
}
