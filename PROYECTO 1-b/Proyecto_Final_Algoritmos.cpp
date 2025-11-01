#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <limits>
#include <chrono>
#include <thread>
using namespace std;

string nombreCapitan; //NOMBRE DEL USUARIO PARA LA AVENTURA
int combustible=30, oxigeno=50, suministros=40, integridadNave=100, dia=1; //VARIABLES DONDE SE GUARDAN LO ESENCIAL Y SON GLOBALES PARA TODO EL PROGRAMA

//TODOS LOS PROCEDIMIENTOS Y FUNCIONES PARA LA LIMPIEZA DEL MAIN Y LAS FUNCIONES DEL PROGRAMA
void mostrarTituloInicio(string nombreCapi);
void limpiarConsola();
void explorarPlaneta();
void mostrarEstado();
void mostrarTitulo(string titulo);
void noche();
void eventoNocturno();
void enviarSenales();
void rendirse();
void gameOver();
void win();
void maquina_escribir(const string& texto, int tiempo=200);
bool reparaNave();
int mostrarMenuPrincipal();
//MAIN
int main(){
    srand(time(NULL)); //SEMILLA PARA REALIZAR EL RANDOM

    string name="Por favor Capitan, ingrese su nombre: \n";//INGRESO DEL NOMBRE DEL USUARIO
    maquina_escribir(name,50);//EFECTO MAQUINA DE ESCRIBIR
    getline(cin, nombreCapitan); //PERMITE INGRESAR CADENAS DE CARACTERES CON ESPACIOS
    this_thread::sleep_for(chrono::milliseconds(20));
    string load="Loading...";
    maquina_escribir(load,80);
    this_thread::sleep_for(chrono::milliseconds(2000));
    system("cls");

    mostrarTituloInicio(nombreCapitan);//PROCEDIMIENTO PARA DARLE LA BIENVENIDA AL PROGRAMA

    while(dia <= 10 && combustible>0 && oxigeno>0 && integridadNave>0){//CICLO DEL PROGRAMA

    //MENU DE OPCIONES
    int menuPrincipal = mostrarMenuPrincipal();
    system("cls");

    bool accionValida = true;//VARIABLE QUE NOS SERVIR  PARA SALIRNOS DE UNA OPCION DEL MENU

    switch (menuPrincipal){//MENU PRINCIPAL
    case 1:
        explorarPlaneta();//PRODECIMIENTO PARA EXPLORAR PLANETA
        this_thread::sleep_for(chrono::milliseconds(3000));
        system("cls");
      break;
    case 2:
        accionValida = reparaNave();//FUNCION QUE MUESTRA REPARAR NAVE
        this_thread::sleep_for(chrono::milliseconds(3000));
        system("cls");
      break;
    case 3:
        enviarSenales();//PROCEDIMIENTO PARA ENVIAR SE ALES DE AYUDA
        this_thread::sleep_for(chrono::milliseconds(3000));
        system("cls");
      break;
    case 4:
      rendirse();//PROCEDIMIENTO CUANDO EL USUARIO SE RINDE
      return 0;
    }
    // VALIDACI N QUE MUESTRA EL PROCEDIMIENTO DE NOCHE Y QUE PASE AL DIA SIGUIENTE SOLO SI LA VARIABLE QUE RETORNA LA FUNCION ES VERDADERA
    if(accionValida == true){
        noche();
        this_thread::sleep_for(chrono::milliseconds(3000));
        system("cls");
        dia += 1;
    }
    //VALIDACION QUE HACE QUE SE MUESTRO EL PROCEDIMIENTO GAME OVER
    if(combustible <= 0 || oxigeno <= 0 || integridadNave <= 0){
        gameOver();
        return 0;
    }
  }
  //PROCEDIMIENTO QUE MUESTRA UN MENSAJE CUANDO EL USUARIO GANA
  win();
  return 0;
}

//-----------------------------PROCEDIMIENTO WIN----------------------------------------------------
void win(){
    mostrarTitulo(" MISION COMPLETADA!");

    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "\033[1;36m";
    string winner="Capitan "+nombreCapitan+", ha logrado sobrevivir al implacable vacio del espacio.\n"
    "Su nave se mantiene firme, su tripulacion esta a salvo y la galaxia conoce su nombre.\n"
    "Las estrellas ahora llevan su historia... un verdadero heroe estelar.\n";
    maquina_escribir(winner,20);
    cout << "\033[0m";

    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "\n\033[1;32m";
    string felicitar="*** FELICIDADES, CAPITAN. MISION EXITOSA ***";
    maquina_escribir(felicitar,20);
    cout<<"\033[0m\n";
}
//-----------------------------PROCEDIMIENTO GAME OVER----------------------------------------------
void gameOver(){
    cout << "\033[1;31m"; // rojo brillante
    string titulo="\n============================================================\n"
    "                    G  A  M  E    O  V  E  R                \n"
    "============================================================\n";
    maquina_escribir(titulo,10);
    this_thread::sleep_for(chrono::milliseconds(400));
    cout<<"   _____                        ____                       \n";
    cout<<"  / ____|                      / __ \\                      \n";
    cout<<" | |  __  __ _ _ __ ___   ___ | |  | |_   _____ _ __       \n";
    cout<<" | | |_ |/ _` | '_ ` _ \\ / _ \\| |  | \\ \\ / / _ \\ '__|      \n";
    cout<<" | |__| | (_| | | | | | |  __/| |__| |\\ V /  __/ |         \n";
    cout<<"  \\_____|\\__,_|_| |_| |_|\\___| \\____/  \\_/ \\___|_|         \n";
    this_thread::sleep_for(chrono::milliseconds(400));
   string linea= "============================================================\n";
    maquina_escribir(linea,20);
    cout << "\033[0m\n";

    this_thread::sleep_for(chrono::milliseconds(1500));

    cout << "\033[1;33m";
    string texto_final="El eco del fracaso resuena en la inmensidad del cosmos...\n"
                       "Tu nave ha quedado a la deriva, perdida entre las estrellas.\n"
                       "Nadie respondera a tus senales. Nadie sabra tu historia.\n"
                       "Solo el silencio del espacio recordara tu ultimo intento.\n";
    maquina_escribir(texto_final,60);
    cout << "\033[0m";

    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "\n\033[1;31m";
    string final_ms="*** FIN DE LA MISION, CAPITAN "+nombreCapitan+" ***";
    maquina_escribir(final_ms,20);
    cout <<"\033[0m\n";
}
//-----------------------------PROCEDIMIENTO PATRA RENDIRSE-----------------------------------------
void rendirse(){
    mostrarTitulo("RENDICION DEL CAPITAN");
    cout << "\033[1;33m";
    string rendir="El silencio del espacio envuelve tu nave...\n"
        "Las luces parpadean por ultima vez antes de apagarse.\n"
    "Has decidido poner fin a tu mision, capitan "+nombreCapitan+".\n"
    "La galaxia seguira girando... pero sin ti al mando.\n\n";
    maquina_escribir(rendir,50);
    cout << "\033[0m";
    cout << "\n\033[1;31m";
    string fin="*** FIN DE LA MISION ***";
    maquina_escribir(fin,20);
    cout<<"\033[0m\n";
}
//-----------------------------PROCEDIMIENTO PARA MOSTRAR EL MENU PRINCIPAL-------------------------
int mostrarMenuPrincipal(){
    int opcion;//VARIABLE DONDE SE GUARDARA EL DATO DEL USUARIO PARA PORTEIOR VALIDARLO
    bool flag = false;//VARIABLE QUE NOS SERVIR  PARA VERIFICAR SI EL BUCLE SIGUE O NO

    do{ //BUCLE PARA VALIDAR SI EL DATO QUE INGRESA EL USUARIO ES EL CORRECTO
        flag = true; //ASUMINOS QUE LA VARIABLE EN ESTE CASO EL DATO ES EL CORRECTO
        mostrarEstado();
        string menu="\n=============================\n"
        "       MENU DE ACCIONES      \n"
        "=============================\n"
        "1. Explorar planeta\n"
        "2. Reparar la nave\n"
        "3. Enviar senales\n"
        "4. Rendirse\n"
        "Elija una opcion: ";
        maquina_escribir(menu,10);
        cin>>opcion;

        if (cin.fail()) { //VALIDA SI EL DATO NO ES NUMERICO
            cin.clear(); // LIMPIA EL ESTADO DE ERROR
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // LIMPIA TODO EL BUFFER
            mostrarTitulo("ADVERTENCIA");//PROCEDIMIENTO CREADO PARA MOSTRAR TITULOS
            cout << "\033[1;33m";
            string ms1="***DEBE INGRESAR UN NUMERO VALIDO (NO UN CARACTER)***\n";
            maquina_escribir(ms1,10);
            cout<< "\033[0m";
            flag = false;//CAMBIA EL VALOR PARA QUE SE VUELVA A REPETIR
            this_thread::sleep_for(chrono::milliseconds(3000));
            system("cls");
            continue; // SALTA A LA SIGUIENTE ITERACION DEL BUCLE
        }
        else if(opcion < 1 || opcion > 4){
            mostrarTitulo("ADVERTENCIA");
            cout<<"\033[1;33m";
            string ms2="***DEBE INGRESAR UN NUMERO DEL 1 AL 4***\n";
            maquina_escribir(ms2,10);
            cout<<"\033[0m";
            flag=false;
            this_thread::sleep_for(chrono::milliseconds(3000));
            system("cls");
        }

    }while(!flag);//SE REPITE EL BUCLE MIENTRAS LA VARIABLE FLAG SEA NEGATIVA OSEA FALSE
    return opcion;//RETORNA EL DATO YA VALIDADO PARA EL MENU PRINCIPAL
}
//-----------------------------PROCEDIMIENTO PARA LIMPIAR LA PANTALLA-------------------------------
void limpiarConsola(){
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
    system("cls");
}
//-----------------------------PROCEDIMIENTO PARA MOSTRAR EL TITULO DEL INICIO----------------------
void mostrarTituloInicio(string nombreCapi) { //SE INGRESA EL NOMBRE DEL USUARIO Y SE IMPRIME LA IMNFORMACION
    system("cls");
    cout <<"\033[1;32m";
    string mision="============================================================\n"
    "           MISION ESPACIAL: SUPERVIVENCIA GALACTICA   \n"
    "============================================================\n\n";
    maquina_escribir(mision,8);
    cout<<"\033[0m";
    cout <<"\033[1;36m";
    string bienvenida="Capitan "+nombreCapitan+", preparese para la aventura.\n"
    "Mantenga su nave funcional a lo largo de esta mision,conserve oxigeno,\n"
    "busque recursos, supere los eventos nocturnos y sobre todo cuide\n"
    "el consumo de combustible, nuestro recurso mas preciado.\n\n"
    "Si su mision es un exito nos veremos en 10 dias en el destino final.\n\n"
    "BUENA SUERTE!";
    maquina_escribir(bienvenida,70);
    cout<<"\033[0m";
    this_thread::sleep_for(chrono::milliseconds(2000));
    system("cls");
}
//-----------------------------PROCEDIMIENTO PARA MOSTRAR LOS TITULOS-------------------------------
void mostrarTitulo(string titulo){
    int ancho = 60; //ANCHO TOTAL DEL "MARCO"
    int longitud = titulo.length(); //VARIABLE QUE GUARDA LA CANTIDAD DE CARACTERES DEL TEXTO
    int padding = (ancho - longitud) / 2; //VARIABLE QUE GUARDA EL RELLENO PARA QUE EL TEXTO QUEDE CENTRADO

    cout << "\n";
    cout << string(ancho, '=') << endl; // LINEA SUPERIOR
    cout << setw(padding + longitud) << titulo << endl; // TEXTO CENTRADO
    cout << string(ancho, '=') << endl; // LINEA INFERIOR
    cout << "\n";
}
//-----------------------------MOSTRAR EL ESTADO CADA DIA-------------------------------------------
void mostrarEstado(){
    string status="\n====== ESTADO DE LA NAVE DIA "+to_string(dia)+" ======\n"
    +"|COMBUSTIBLE: "+to_string(combustible)+" unidades|\n"
    +"|OXIGENO: "+to_string(oxigeno)+" unidades|\n"
    +"|SUMINISTROS: "+to_string(suministros)+" unidades|\n"
    +"|INTEGRIDAD DE LA NAVE: "+to_string(integridadNave)+"%|\n";//MUESTRA EL ESTADO DE LAS VARIABLES GLOBALES POR CADA DIA QUE PASA
    maquina_escribir(status,20);
}
//-----------------------------PROCEDIMIENTO PARA EXPLORAR PLANETA----------------------------------
void explorarPlaneta(){
    mostrarTitulo("EXPLORANDO PLANETA");//PROCEDIMIENTO PARA CREAR EL TITULO
    combustible -= 15;
    string op1="HAS GASTADO 15 UNIDADES DE COMBUSTIBLE\n"
    "COMBUSTIBLE = ";
    maquina_escribir(op1,20);
    cout<<"\033[1;31m";
    string op1_1="-15 unidades\n";
    maquina_escribir(op1_1,20);
    cout<<"\033[0m";

    int probabilidad = rand() % 100 + 1; //NUMEROS ALEATORIOS ENTRE EL 1 AL 100

    if(probabilidad <= 34){//PROBABILIDAD DEL 60% QUE SUCEDA
        int oxigenoEncontrado = rand() % (40 - 20 +1) +20;//VARIABLE QUE ALMACENA LA PROBABILIDAD DE ENCONTRAR ENTRE 20 A 40 UNIDADES DE OXIGENO
        string ox="\nCAPITAN "+nombreCapitan+":\n"
        "Has encontrado "+to_string(oxigenoEncontrado)+" unidades de oxigeno\n"
        "OXIGENO = ";
        maquina_escribir(ox,20);
        cout<<"\033[1;32m";
        string ox1="+"+to_string(oxigenoEncontrado)+" unidades\n";
        maquina_escribir(ox1,20);
        cout<<"\033[0m";
        oxigeno += oxigenoEncontrado;
    }
    else if(probabilidad <= 47){//PROBABILIDAD DEL 25% QUE SUCEDA
        int combustibleEncontrado = rand() % (30 -10 +1) +10;
        string com="\nCAPITAN "+nombreCapitan+":\n"//VARIABLE QUE ALMACENA LA PROBABILIDAD DE ENCONTRAR ENTRE 10 A 30 UNIDADES DE COMBUSTIBLE
        "Has encontrado "+to_string(combustibleEncontrado)+" unidades de combustible\n"
        "COMBUSTIBLE = ";
        maquina_escribir(com,20);
        cout<<"\033[1;32m";
        string com2="+"+to_string(combustibleEncontrado)+" unidades\n";
        maquina_escribir(com2,20);
        cout<<"\033[0m";
        combustible += combustibleEncontrado;
    }
    else if(probabilidad <= 74){//PROBABILIDAD DEL 50% QUE SUCEDA
        int suministrosEncontrados = rand() % (100 - 30 + 1) + 30;//VARIABLE QUE ALMACENA LA PROBABILIDAD DE ENCONTRAR ENTRE 30 A 100 UNIDADES DE SUMINISTROS
        string sum="\nCAPITAN "+nombreCapitan+":\n"
        "Has encontrado "+to_string(suministrosEncontrados)+" unidades de suministros\n"
        "SUMINISTROS = ";
        maquina_escribir(sum,20);
        cout<<"\033[1;32m";
        string sum1="+"+to_string(suministrosEncontrados)+" unidades\n";
        maquina_escribir(sum1,20);
        cout<<"\033[0m";
        suministros += suministrosEncontrados;
    }
    else if(probabilidad <= 87){//PROBABILIDAD DEL 25% QUE SUCEDA
        int navedano = rand() % (20 - 10 +1) +10;//VARIABLE QUE ALMACENA LA PROBABILIDAD DE QUE LA NAVE RECIBA DA O, ENTRE 10% A 20%
        string storm="\nCAPITAN "+nombreCapitan+":\n"
        "Debido a una TORMENTA ELECTRICA...\n"
        "La integridad de la nave ha disminuido un "+to_string(navedano)+"%\n"
        "INTEGRIDAD DE LA NAVE = ";
        maquina_escribir(storm,60);
        cout<<"\033[1;31m";
        string storm2="-"+to_string(navedano)+"% de integridad\n";
        maquina_escribir(storm2,60);
        cout<<"\033[0m";
        integridadNave -= navedano;
    }
    else{//PROBABILIDAD DEL 25% QUE SUCEDA
        int dano = rand() % (20 - 10 +1) +10;//VARIABLE QUE ALMACENA LA PROBABILIDAD DE QUE LA NAVE RECIBA DA O, ENTRE 10% A 20%
        string des="\nCAPITAN "+nombreCapitan+":\n"
        "Debido a una DESVIACION DE LA TRAYECTORIA...\n"
        "Se tuvo que realizar un ATERRIZAJE FORZADO...\n"
        "La integridad de la nave ha disminuido un "+to_string(dano)+"%\n"
        "INTEGRIDAD DE LA NAVE = ";
        maquina_escribir(des,50);
        cout<<"\033[1;31m";
        string des1="-"+to_string(dano)+"% de integridad\n";
        maquina_escribir(des1,50);
        cout<<"\033[0m";
        integridadNave -= dano;
    }

    if(oxigeno < 0) oxigeno = 0;
    if(combustible < 0) combustible = 0;
    if(suministros < 0) suministros = 0;
    if(integridadNave < 0) integridadNave = 0;
    if(integridadNave > 100) integridadNave = 100;//LAS DELIMITACIONES DEL PORGRAMA, PARA QUE NO SE PASEN DE LO PREDEFINIDO

    cout<<"\033[1;36m";
    string ms3="\nLA EXPLORACION HA TERMINADO POR EL DIA DE HOY...\n";
    maquina_escribir(ms3,20);
    cout<<"\033[0m";
}
// ----------------------------FUNCION PARA REPARAR NAVE -------------------------------------------
bool reparaNave(){
    bool flag= false;//VARIABLE PARA EL CICLO
    int porcentaje = 0, costo = 0;//VARIABLES QUE NOS AYUDAR N A CALCULAR EL COSTO DE SUMINISTROS Y EL PORCENTAJE QUE EL USUARIO QUIERE REPARAR

    if(integridadNave == 100){//VALIDACION SI EL USUARIO ELIGE ESTA OPCION, SI LA INTEGRIDAD DE LA NAVE ESTA AL 100, LO REGRESA AL MENU PRINCIPAL
        mostrarTitulo("ADVERTENCIA");
        cout<<"\033[1;33m";
        string estadoms="\n***LA INTEGRIDAD DE LA NAVE ESTA AL 100%***\n";
        maquina_escribir(estadoms,20);
        cout<<"\033[0m";
        cout<<"\033[1;36m";
        string regresoms="\nREGRESANDO AL MENU PRINCIPAL...\n";
        maquina_escribir(regresoms,20);
        cout<<"\033[0m";
        return false;//RETORNA FALSE
    }
    else if(suministros <= 9){//SI NO TIENE SUFICIENTES SUMINISTROS EL USUARIO, TAMBI N LO REGRESA
        mostrarTitulo("ADVERTENCIA");
        cout<<"\033[1;33m";
        string estado1ms="\n***NO TIENES SUFICIENTES SUMINISTROS***\n";
        maquina_escribir(estado1ms,30);
        cout<<"\033[0m";
        cout<<"\033[1;36m";
        string regreso1ms="\nREGRESANDO AL MENU PRINCIPAL...\n";
        maquina_escribir(regreso1ms,20);
        cout<<"\033[0m";
        return false;
    }

    do{//CICLO PARA LA VALIDACI N DEL DATO QUE INGRESE EL USUARIO
        mostrarTitulo("REPARAR LA NAVE");
        cout<<"\033[1;33m";
        string estado3="|INTEGRIDAD ACTUAL DE LA NAVE: "+to_string(integridadNave)+"%|\n"
        "|SUMINISTROS DISPONIBLES: "+to_string(suministros)+" unidades|\n";
        maquina_escribir(estado3,40);
        cout<<"\033[0m";
        string question="\nPORCENTAJE QUE DESEA REPARAR?: ";
        maquina_escribir(question,30);
        cin>>porcentaje;

        costo = porcentaje * 10;
        flag = true;

        if (cin.fail()) {//VALIDA SI EL DATO NO ES NUMERICO
            cin.clear();//LIMPIA EL ESTADO DE ERROR
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//LIMPIA TODO EL BUFFER
            mostrarTitulo("ADVERTENCIA");//PROCEDIMIENTO PARA CREAR LOS TITULOS
            cout << "\033[1;33m";
            string validacion="***DEBE INGRESAR UN NUMERO VALIDO (NO UN CARACTER)***\n";
            maquina_escribir(validacion,20);
            cout<< "\033[0m";
            flag = false;//CAMBIA EL VALOR PARA QUE SE VUELVA A REPETIR
            this_thread::sleep_for(chrono::milliseconds(3000));
            system("cls");
            continue;//SALTA A LA SIGUIENTE ITERACION DEL BUCLE
        }
        else if(porcentaje <= 0){// SI EL USUARIO INGRESA UN NUMERO MENOR O IGUAL A CERO, LE VUELVE A PREGUNTAR
            mostrarTitulo("ADVERTENCIA");
            cout<<"\033[1;33m";
            string validacion1="***DEBE INGRESAR UN NUMERO MAYOR A 0***\n";
            maquina_escribir(validacion1,20);
            cout<<"\033[0m";
            flag=false;
            this_thread::sleep_for(chrono::milliseconds(3000));
            system("cls");
        }
        else if(costo > suministros){//SI EL USUARIO QUIERE REPARAR M S DE LO QUE PUEDEN SUS SUMINISTROS, LE VUELVE A PREGUNTAR
            mostrarTitulo("ADVERTENCIA");
            cout<<"\033[1;33m";
            string info="CAPITAN "+nombreCapitan+" NO TIENE SUFICIENTES SUMINISTROS...\n";
            maquina_escribir(info,30);
            cout<<"\033[0m";
            string info1="Necesita ";
            cout<<"\033[1;33m";
            string info_2=""+to_string(costo)+" UNIDADES ";
            maquina_escribir(info_2,20);
            cout<<"\033[0m";
            string info_3=", pero solo tiene ";
            maquina_escribir(info_3,20);
            cout<<"\033[1;33m";
            string info_4=""+to_string(suministros)+" UNIDADES";
            maquina_escribir(info_4,20);
            cout<<"\033[0m";
            flag = false;
            this_thread::sleep_for(chrono::milliseconds(4000));
            system("cls");
        }
        else if(integridadNave + porcentaje > 100){//SI EL USUARIO QUIERE REPARAR M S DEL 100% QUE ES LO MAXIMO
            mostrarTitulo("ADVERTENCIA");
            cout<<"\033[1;33m";
            string advertencia="***SOLO PUEDES REPARAR HASTA EL 100%***\n";
            maquina_escribir(advertencia,20);
            cout<<"\033[0m";
            flag = false;
            this_thread::sleep_for(chrono::milliseconds(3000));
            system("cls");
        }
    }while(!flag);//VALIDACION DEL BUCLE, CONTINUA SOLO SI FLAG ES VERDADERO

    suministros -= costo;
    integridadNave += porcentaje;//SE HACEN LOS RESPECTIVOS CAMBIOS DE LA REPARACION
    cout<<"\033[1;32m";
    string completado="\n------REPARACION COMPLETADA------\n";
    maquina_escribir(completado,20);
    cout<<"\033[0m";
    cout<<"\033[1;33m";
    string nuevo_estado="|NUEVA INTEGRIDAD DE LA NAVE: "+to_string(integridadNave)+"%|\n"
    "|SUMINISTROS RESTANTES: "+to_string(suministros)+" unidades|\n";
    cout<<"\033[0m";
    return true;//RETORNA VERDADERA PARA QUE ASE DE D A Y QUE MUESTRE EL EVETO DE NOCHE
}
//-----------------------------FUNCION PARA ENVIAR SEÑALES------------------------------------------
void enviarSenales(){
    int probabilidad = rand() % 2 + 1;//VARIABLE QUE GUARDE EL NUMERO ALEATORIO
    mostrarTitulo("ENVIAR SENALES");//PRODECIMIENTO QUE CREA EL TITULO
    cout<<"\033[1;36m";
    string senal="CAPITAN "+nombreCapitan+" HAS ENVIADO SENALES PARA PEDIR AYUDA...";
    maquina_escribir(senal,20);
    cout<<"\033[0m";
    this_thread::sleep_for(chrono::milliseconds(3000));
    system("cls");

    if (probabilidad == 1){//VALIDACION QUE MUESTRA A LOS VIAJEROS ESPACIALES
        mostrarTitulo("VIAJEROS ESPACIALES");
        cout<<"\033[1;36m";
        string respuesta="Las senales han interceptado a unos VIAJEROS y te han ayudado\n";
        maquina_escribir(respuesta,20);
        cout<<"\033[0m";
        string respuesta1_1="COMBUSTIBLE = ";
        maquina_escribir(respuesta1_1,20);
        cout<<"\033[1;32m";
        string respuesta1_2="+60 unidades\n";
        maquina_escribir(respuesta1_2,20);
        cout<<"\033[0m";
        combustible += 60;//SE LE SUMA LA CANTIDAD A LA VARIABLE GLOBAL
    }
    else if (probabilidad == 2){//VALIDACION DE QUE MUESTRA A LOS PIRATAS ESPACIALES
        mostrarTitulo("PIRATAS ESPACIALES");
        cout<<"\033[1;36m";
        string piratas="Las senales han interceptado a unos PIRATAS ESPACIALES\n"
        "Los PIRATAS ESPACIALES han asaltado la nave\n";
        maquina_escribir(piratas,60);
        cout<<"\033[0m";
        string integridad="INTEGRIDAD DE LA NAVE = ";
        maquina_escribir(integridad,20);
        cout<<"\033[1;31m";
        string integridad_1="-15% de integridad\n";
        maquina_escribir(integridad_1,20);
        cout<<"\033[0m";
        string sum="SUMINISTROS = ";
        maquina_escribir(sum,20);
        cout<<"\033[1;31m";
        string sum1="-20 unidades\n";
        maquina_escribir(sum1,20);
        cout<<"\033[0m";
        integridadNave -= 15;//SE LE RESTA LA CANTIDAD A LA VARIABLE GLOBAL
        suministros -= 20;//SE LE RESTA LA CANTIDAD A LA VARIABLE GLOBAL
    }
}
//-----------------------------PROCEDIMIENTO PARA ENTRAR A LA NOCHE---------------------------------
void noche(){
    int probaEventoNocturno = rand() % 100 + 1;//VARIABLE QUE ALMACENA EL DATO RANDOM
    //LO DEL EVENTO DE NOCHE SIEMPRE ES FIJO POR D A, POR LO QUE SE LE RESTAN ESAS CANTIDADES A ESAS VARIABLES GLOBALES
    mostrarTitulo("HA LLEGADO LA NOCHE");
    cout << "\033[1;33m";
    string recursosms="  RECURSOS REDUCIDOS";
    maquina_escribir(recursosms,20);
    cout<< "\033[0m";
    string oxms="  OXIGENO = ";
    maquina_escribir(oxms,20);
    cout<< "\033[1;31m";
    string oxms1= "-20 unidades";
    maquina_escribir(oxms1,20);
    cout<<"\033[0m" << endl;
    string summs="  SUMINISTROS = ";
    maquina_escribir(summs,20);
    cout<< "\033[1;31m";
    string summs1="-30 unidades";
    maquina_escribir(summs1,20);
    cout<< "\033[0m" << endl;
    oxigeno -= 20;
    suministros -= 30;
    this_thread::sleep_for(chrono::milliseconds(4000));
    system("cls");

    if(dia == 1){//EL EVENTO NOCTURNO SIEMPRE PASA EL PRIMER DIA, YA QEU LA PROBABILIDAD DE QUE PASE ES MUY BAJA
        eventoNocturno();
    }
    else if(probaEventoNocturno <= 15){//EL EVENTO NOCTURNO PASA CON UNA PROBABILIDAD DEL 15%
        eventoNocturno();//PROCEDIMIENTO PARA QUE MUESTRE EL EVENTO NOCTURNO
    }
}
//-----------------------------PROCEDIMIENTO PARA LOS EVENTOS NOCTURNOS-----------------------------
void eventoNocturno(){
    int accion = rand() % 3 + 1;//VARIABLE QUE GUARDA EL DATO RANDOM PARA QUE SUCEDAN LOS DIFERENTES EVENTOS NOCTURNOS

    if(accion == 1){//VALIDACION PARA QUE SUCEDA LA TORMENTA COSMICA
        mostrarTitulo("TORMENTA COSMICA");//MUESTRA EL TITULO
        cout<<"\033[1;36m";
        string cosmica="Mientras descansabas ha ocurrido una TORMENTA COSMICA...\n";
        maquina_escribir(cosmica,60);
        cout<<"\033[0m";
        string cosmica1="OXIGENO = ";
        maquina_escribir(cosmica1,20);
        cout<<"\033[1;31m";
        string cosmica2="-10 unidades";
        maquina_escribir(cosmica2,20);
        cout<<"\033[0m";
        oxigeno -= 10;//SE LE RESTA A LA VARIABLE GLOBAL
    }
    else if(accion == 2){//VALIDACION PARA QUE SUCEDA EL ENCUENTRO ALIENIGENA
        int encuentroAlie = rand() % 2 + 1;//VARIABLE QUE GUARDA EL DATO RANDOM DE QUE SEAN BUENOS O MALOS
        mostrarTitulo("ENCUENTRO ALIENIGENA");
        cout<<"\033[1;36m";
        string encuentro="Mientras descansabas, unos ALIENIGENAS han aparecido...\n";
        maquina_escribir(encuentro,20);
        cout<<"\033[0m";

        if(encuentroAlie == 1){//VALIDACION PARA QUE LOS ALIENIGENAS SEAN BUENOS
            mostrarTitulo("ALIENIGENAS BUENOS");
            cout<<"\033[1;36m";
            string buenos="Los alienigenas resultaron ser buenos...\n"
            "Has adquirido +20 unidades de combustible\n";
            maquina_escribir(buenos,60);
            cout<<"\033[0m";
            string buenos1="COMBUSTIBLE = ";
            maquina_escribir(buenos1,20);
            cout<<"\033[1;32m";
            string buenos2="+20 unidades";
            maquina_escribir(buenos2,20);
            cout<<"\033[0m";
            combustible += 20;// SE LE SUMA A LA VARIABLE GLOBAL
        }
        else if(encuentroAlie == 2){//VALIDACION PARA QUE LOS ALIENIGENAS SEAN MALOS
            mostrarTitulo("ALIENIGENAS MALOS");
            cout<<"\033[1;36m";
            string malos="Los alienigenas resultaron ser malos...\n"
            "Han danado un 10% de la integridad de la nave\n";
            maquina_escribir(malos,60);
            cout<<"\033[0m";
            string malos1="INTEGRIDAD DE LA NAVE = ";
            maquina_escribir(malos1,20);
            cout<<"\033[1;31m";
            string malos2="-10% de integridad";
            maquina_escribir(malos2,20);
            cout<<"\033[0m";
            integridadNave -= 10;//SE LE RESTA A LA VARIABLE GLOBAL
        }
    }
    else if(accion == 3){//VALIDACION DE QUE SUCEDA EL EVENTO DE METEORITOS
        int opcion;//VARIABLE QUE GUARDA EL DATO QUE INGRESA EL USUARIO
        bool flag = false;//VARIABLE PARA LA VALIDACION DEL BUCLE

        do{
            flag=true;
            mostrarTitulo("METEORITOS");
            cout<<"\033[1;33m";
            string choose="ELIJE LA ACCION A REALIZAR\n";
            maquina_escribir(choose,30);
            cout<<"\033[0m";
            cout<<"\033[1;36m";
            string choose1="1. MANIOBRAR";
            maquina_escribir(choose1,30);
            cout<<"\033[0m";
            string choose1_1="(-10 a -30 unidades de combustible)\n";
            maquina_escribir(choose1_1,30);
            cout<<"\033[1;36m";
            string choose2="2. RECIBIR IMPACTO";
            maquina_escribir(choose2,30);
            cout<<"\033[0m";
            string choose2_2="(-15% a -25% integridad de la nave)\n"
            "Elije una opcion: ";
            maquina_escribir(choose2_2,30);
            cin>>opcion;//SE GUARDA EL DATO DEL USUARIO

            if (cin.fail()){// VALIDA QUE SEA NUMERICO Y SI NO LO ES ENTRA EN ESTE BLOQUE DE CODIGO
            cin.clear(); // LIMPIA EL ERROR DEL ESTADO
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //LIMPIA TODO EL BUFFER
            mostrarTitulo("ADVERTENCIA");
            cout << "\033[1;33m";
            string validacionms="***DEBE INGRESAR UN NUMERO VALIDO (NO UN CARACTER)***\n";
            maquina_escribir(validacionms,20);
            cout<< "\033[0m";
            flag = false;//CAMBIA LA VARIABLE PARA QUE VUELVA A REPETIR EL BUCLE
            this_thread::sleep_for(chrono::milliseconds(3000));
            system("cls");
            continue; //SALTA A LA SIGUIENTE ITERACION DEL BUCLE
            }
            else if(opcion != 1 && opcion != 2){//VALIDA SI EL DATO ES DIFERENTE A LAS OPCIONES QUE SE LE PROPORCION  AL USUARIO
                mostrarTitulo("ADVERTENCIA");
                cout<<"\033[1;33m";
                string validacion1="***DEBE INGRESAR 1 0 2***\n";
                maquina_escribir(validacion1,20);
                cout<<"\033[0m";
                flag=false;
                this_thread::sleep_for(chrono::milliseconds(3000));
                system("cls");
            }
        }while(!flag);//VALIDACION DEL BUCLE PARA QUE CONTIN E

        switch(opcion){//LA ELECCI N DEL USUARIO YA VALIDADO EL DATO
            case 1: {
                int combusPerdido = rand() % (30 - 10 + 1) +10;//VARIABLE QUE ALMACENA LA CANTIDAD DE COMBUSTIBLE QUE PIERDE
                mostrarTitulo("MANIOBRAR");
                cout<<"\033[1;36m";
                string op1="Gracias a las maniobras has evitado los meteoritos...\n"
                "Has perdido "+to_string(combusPerdido)+" unidades de combustible...\n";
                maquina_escribir(op1,50);
                cout<<"\033[0m";
                string op1_1="COMBUSTIBLE = ";
                maquina_escribir(op1_1,20);
                cout<<"\033[1;31m";
                string op1_2="-"+to_string(combusPerdido)+" unidades";
                maquina_escribir(op1_2,20);
                cout<<"\033[0m";
                combustible -= combusPerdido;//SE LE RESTA A LA VARIABLE GLOBAL
                break;
            }
            case 2: {
                int integridadPerdida = rand() % (25 - 15 + 1) +15;//VARIABLE QUE ALMACENA EL PORCENTAJE DE INTEGRIDAD QUE PIERDE
                mostrarTitulo("RECIBIR IMPACTO");
                cout<<"\033[1;36m";
                string op2="Has recibido el impacto de los meteoritos...\n"
                "Has perdido "+to_string(integridadPerdida)+"% de la integridad de la nave...\n";
                maquina_escribir(op2,50);
                cout<<"\033[0m";
                string op2_1="INTEGRIDAD DE LA NAVE = ";
                maquina_escribir(op2_1,20);
                cout<<"\033[1;31m";
                string op2_2="-"+to_string(integridadPerdida)+"% integridad de la nave";
                maquina_escribir(op2_2,20);
                cout<<"\033[0m";
                integridadNave -= integridadPerdida;//SE LE RESTA A LA VARIABLE GLOBAL
                break;
            }
        }
    }

}
//----------------------------------ESCRITURA MAQUINA DE ESRIBIR------------------------------
void maquina_escribir(const string& texto, int tiempo){
  for(char c : texto) {
    cout << c << flush; //imprime el caracter sin necesidad de dar enter
    this_thread::sleep_for(chrono::milliseconds(tiempo)); //tiempo entre caracter
}
}

