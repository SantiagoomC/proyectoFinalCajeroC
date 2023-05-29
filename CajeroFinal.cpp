#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//Validar prefijo FIJO Y CELULAR
bool validarPrefijo(const string& numeroCelular) {
	string prefijo = numeroCelular.substr(0, 3);
	
	return (prefijo == "301" || prefijo == "313" || prefijo == "321" || prefijo == "250" || prefijo == "251" || prefijo == "260" );
}

bool validarNumero (string numeroAValidar ){
	bool datoValido, datoValidoAcumulado, bandera, validarEdad;
	int posiCaracter, contador;
	string subCaracter;
	datoValidoAcumulado = true;
	
	for (posiCaracter=0;posiCaracter<=numeroAValidar.size()-1;posiCaracter++){
		subCaracter = numeroAValidar.substr(posiCaracter,posiCaracter-posiCaracter+1);
		datoValido = (subCaracter=="0") || (subCaracter=="1") || (subCaracter=="2") || (subCaracter=="3") || (subCaracter=="4") || (subCaracter=="5") || (subCaracter=="6") || (subCaracter=="7") || (subCaracter=="8") || (subCaracter=="9");
		datoValidoAcumulado = datoValido;
	}
	// (numeroAValidar.size()==7 && datoValidoAcumulado==true)||(numeroAValidar.size() == 10 && datoValidoAcumulado==true)||(numeroAValidar.size() == 5 && datoValidoAcumulado==true)
	if (datoValidoAcumulado == true) {
		return true;
	} else {
		return false;
	}
}

//CONVERTIR A TEXTO
string convertiratexto(float f) {
	stringstream ss;
	ss << f;
	return ss.str();
}

// PRUEBA: Valida si tiene s�lo texto el CIN.
bool contieneSoloLetras(const string& texto) {
	for (char c : texto) {
		if (!isalpha(c)) {
			return false;
		}
	}
	return true;
}
	
//PUREBAS
//VALIDACI�N DE NOMBRE
string validarNombre()
{
	string nombreUsuario;
	cout << "Nombre: ";
	cin >> nombreUsuario;
	
	if (!contieneSoloLetras(nombreUsuario) || nombreUsuario.size() < 2) {
		cout << "El nombre debe contener solo letras y tener m�s de una letra. Reiniciando el registro." << endl;
		return "";
	}
	
	return nombreUsuario;
}

//VALIDACI�N DE APELLIDO
string validarApellido()
{
	string apellidoUsuario;
	cout << "Apellido: ";
	cin >> apellidoUsuario;
	
	if (!contieneSoloLetras(apellidoUsuario) || apellidoUsuario.size() < 2) {
		cout << "El nombre debe contener solo letras y tener m�s de una letra. Reiniciando el registro." << endl;
		return "";
	}
	
	return apellidoUsuario;
}

		
string validarCedula(){
	string numeroCedula;
	int intentos = 0;
	
	do {
		cout << "N�mero de c�dula: ";
		cin >> numeroCedula;
		
		if (validarNumero(numeroCedula) && numeroCedula.size()==7) {
			return numeroCedula;
		} else {
			intentos++;
			cout << "El n�mero de la c�dula debe contener solo n�meros y tener 7 d�gitos. Int�ntelo nuevamente." << endl;
			cout << "Intentos restantes: " << 3 - intentos << endl;
		}
	} while (intentos < 3);
	
	cout << "Se agotaron los intentos. Reiniciando el registro.\n" << endl;
	return "";
}

// VALIDAR N�MERO DE CELULAR
string validarCelular() {
	string numeroCelular;
	int intentos = 1;
	
	while (intentos <= 3) { 
		cout << "N�mero de celular: ";
		cin >> numeroCelular;
		
		if (validarNumero(numeroCelular) && validarPrefijo(numeroCelular) && numeroCelular.size() == 10) {
			break;
		}
		
		cout << "El n�mero de celular debe contener s�lo n�meros, tener 10 d�gitos, y el prefijo debe ser 301, 313 o 321." << endl;
		
		intentos++;
		
		if (intentos > 3) {
			cout << "Ha alcanzado el n�mero m�ximo de intentos. Por seguridad debe reiniciar el proceso." << endl;
			return "";
		}
	}
	
	return numeroCelular;
}
	

// VALIDAR EL N�MERO FIJO
string validarNumeroFijo() {
	string numeroFijo;
	int intentos = 1;
	cout << "N�mero fijo: ";
	cin >> numeroFijo;
	
	while ((!validarNumero(numeroFijo)) || !validarPrefijo(numeroFijo) || !(numeroFijo.size() == 7)) {
		cout << "El n�mero fijo debe contener s�lo n�meros, tener 7 d�gitos, y el prefijo debe ser 250, 251 o 260." << endl;
		cout << "Int�ntelo nuevamente: ";
		cin >> numeroFijo;
		//return "";
		intentos++;
		
		if (intentos > 3) {
			cout << "Ha alcanzado el n�mero m�ximo de intentos. Por seguridad debe de reiniciar el proceso." << endl;
			break;
		}
	}
	return numeroFijo;
}

//VALIDAR CIUDAD 
string validarCiudad(){
	int opcion; 
	string ciudad;
	
	cout << "�Cu�l es su ciudad de residencia?\n 1. Medell�n\n 2. Cali\n 3. Barranquilla\n Ingrese una opcion: ";
	cin >> opcion;
	
	switch (opcion){
		case 1:
			ciudad = "Medell�n";
			return ciudad;
		case 2:
			ciudad = "Cali";
			return ciudad;
		case 3:
			ciudad = "Barranquilla";
			return ciudad;
		default:
			cout << "Ingrese un valor valido";
	}
	return "";
}

//VALIDACION DE CORREO:
	
	

// VALIDAR NUMERO DE CUENTA
	bool numeroCuentaExistente(const string& numeroCuenta, const vector<string>& listaNumeroCuenta) {
		for (const string& cuenta : listaNumeroCuenta) {
			if (cuenta == numeroCuenta) {
				return true; // El n�mero de cuenta ya existe en la lista
			}
		}
		return false; // El n�mero de cuenta no existe en la lista
	}
	
	string validarNumeroCuenta() {
		string numeroCuenta;
		cout << "N�mero de 5 d�gitos para asignar a la cuenta: ";
		cin >> numeroCuenta;
		
		while (!validarNumero(numeroCuenta) || numeroCuenta.size() != 5) {
			cout << "Recuerda que la cuenta debe contener solo n�meros y tener 5 d�gitos. Adem�s, no puede estar repetida. Int�ntelo nuevamente: ";
			cin >> numeroCuenta;
		}
		
		return numeroCuenta;
	}
	

// VALIDAR CONTRASE�A
string validarContrasenna(){
	string contrasennaUsuario;
	cout << "Contrase�a para la cuenta: ";
	cin >> contrasennaUsuario;
	
	if (contrasennaUsuario.size() == 5){
		return contrasennaUsuario;
	}
	return "";
	
}

	//

int main(int argc, char *argv[]) {
	int otroUsuario, contadorPosicion, opcion, i, saldoApertura, intentosApertura, opcionApertura;
	
	//Variables de prueba:
	string valorABuscar;
	//
	
	bool encontrado;
	
//	string nombreUsuario, ciudadUsuario, correoUsuario, apellidoUsuario, celularUsuario;
//	string cedulaUsuario, telefonoUsuario, numeroDeCuentaUsuario, contrasennaUsuario;
	
	
	string listaNombre[4] = {};
	string listaApellidos[4] = {};
	string listaCedula[4] = {};
	string listaCelular[4] = {};
	string listaTelefono[4] = {};
	string listaCiudad[4] = {};
	string listaCorreo[4] = {};
	string listaNumeroCuenta[4] = {};
	string listaContrasenna[4] = {};
	int listaSaldos[4] = {};
	contadorPosicion = 0;
	
	
	
	do {
		
		cout << "�Qu� desea hacer?\n";
		cout << "1. Ingresar a mi cuenta bancaria.\n";
		cout << "2. Crear una cuenta.\n";
		cout << "3. Cajero.\n";
		cout << "4. Salir.\n";
		
		cout << "\nIngrese una opci�n: ";
		cin >> opcion;

		switch (opcion){
		case 1:
			validarNumeroFijo();
			break;
		case 2:
			
			if (contadorPosicion <= 3){
				while(contadorPosicion <= 3){
					cout << "\nVamos a proceder con el registro, digite los siguientes campos solicitados:\n\n";
					
					//NOMBRE
					listaNombre[contadorPosicion] = validarNombre();
					if (listaNombre[contadorPosicion].empty()) {
						contadorPosicion = contadorPosicion;
						break; 
					}
					//APELLIDO
					listaApellidos[contadorPosicion] = validarApellido();
					if (listaApellidos[contadorPosicion].empty()) {
						contadorPosicion = contadorPosicion;
						break;
					}
					//CEDULA
					listaCedula[contadorPosicion] = validarCedula();
					if (listaCedula[contadorPosicion].empty()) {
						contadorPosicion = contadorPosicion;
						break;
					}
					
					//CELULAR
					listaCelular[contadorPosicion] = validarCelular();
					if (listaCelular[contadorPosicion].empty()) {
						contadorPosicion = contadorPosicion; 
						break;
					}
					
					//TELEFONO
					listaTelefono[contadorPosicion] = validarNumeroFijo();
					if (listaTelefono[contadorPosicion].empty()) {
						contadorPosicion = contadorPosicion;
						break;
					}
					//CIUDAD
					listaCiudad[contadorPosicion] = validarCiudad();
					if (listaCiudad[contadorPosicion].empty()) {
						contadorPosicion = contadorPosicion;
						break;
					}
//					//CORREO
//					listaCorreo[contadorPosicion] = {};
//					if (listaCorreo[contadorPosicion].empty()) {
//						contadorPosicion = contadorPosicion;
//						break;
//					}
					//NUMERO DE CUENTA
					listaNumeroCuenta[contadorPosicion] = validarNumeroCuenta();
					if (listaNumeroCuenta[contadorPosicion].empty()) {
						contadorPosicion = contadorPosicion;
						break;
					}
					//CONTRASENNA
					listaContrasenna[contadorPosicion] = validarContrasenna();
					if (listaContrasenna[contadorPosicion].empty()) {
						contadorPosicion = contadorPosicion;
						break;
					}
					
					//SALDO APERTURA;
					intentosApertura = 1;
					while (intentosApertura <= 3){
						cout << "Por �ltimo, para aperturar la cuenta debes de ingresar un monto m�nimo de $30.000 en adelante.\n�Cu�nto dinero vas a ingresar?: ";
						cin >> saldoApertura;
						if (saldoApertura >= 30000){
							listaSaldos[contadorPosicion] = saldoApertura;
							intentosApertura = 4;
						} else {
							cout << "Lo sentimos el monto ingresado es inferior al requerido.\n";
							
							if (intentosApertura == 3){
								cout << "Ha culminado los intentos disponibles para la transacci�n, por seguridad debe hacer nuevamente el proceso\n\n";
								break;
							}
						}
						intentosApertura++;
					}
					
					//FINAL;
					cout << "\nExcelente su registro se ha realizado con �xito con los siguientes datos:\n\n";
					cout << "Nombre: " << listaNombre[contadorPosicion] << endl;
					cout << "Apellido: " << listaApellidos[contadorPosicion] << endl;
					cout << "Cedula: " << listaCedula[contadorPosicion] << endl;
					cout << "Celular: " << listaCelular[contadorPosicion] << endl;
					cout << "Telefono: " << listaTelefono[contadorPosicion] << endl;
					cout << "Ciudad: " << listaCiudad[contadorPosicion] << endl;
					cout << "Correo: " << listaCorreo[contadorPosicion] << endl;
					cout << "N�mero de cuenta: " << listaNumeroCuenta[contadorPosicion] << endl;
					cout << "Contrase�a: *****" << endl;
					cout << "Saldo de apertura: " << listaSaldos[contadorPosicion] << endl << endl;
					cout << "S� los datos son correctos puede marcar 1. Para finalizar o 2.Realizar el registro nuevamente.\n\nIngrese una opci�n: ";
					cin >> opcionApertura;
					cout << "\n";
					
					if(opcionApertura == 1){
						cout << "�Desea registrar otro usuario? 1. S� - 2. No : ";
						cin >> otroUsuario;
						if(otroUsuario == 1){
							contadorPosicion++;
							if (contadorPosicion > 3){
								cout << "Lo sentimos, ya no tenemos m�s cupos disponibles\n\n";
								break;
							}
						}else if (otroUsuario == 2){
							contadorPosicion++;
							break;
						} else {
							cout << "Ingrese una opci�n valida\n"; 
						}
//							}else {
//								cout << "Lo sentimos ya no tenemos m�s cupo para el registro de cuentas\n\n";
//							}
					} else if (opcionApertura == 2){
						contadorPosicion = contadorPosicion;
						continue;
					} else {
						cout << "Ingrese una opci�n valida";
					}
				}
			}
			break;
		case 3:
			encontrado = false;
			cout << "\nVamos a buscar un valor dentro de las listas :";
			cin >> valorABuscar;
			cout << "Usuarios en la lista de nombres: ";
			for (int i = 0; i <= 3; i++) {
				cout << listaNombre[i] << " ";
			}
			cout << "\nValor a buscar: " << valorABuscar << endl;
			
			for (int i = 0; i <= 3; i++) {
				if (listaNombre[i] == valorABuscar) {
					encontrado = true;
					break;
				}
			}
			
			if (encontrado) {
				cout << "El nombre: "+ valorABuscar +" s� se encuentra";
			} else {
				cout << "El valor buscado no est� en el arreglo\n\n";
			}
			break;
		case 4:
			cout << "\nHasta luego, que vuelva pronto.\n\n";
			break;
		default:
			cout << "\nIngrese una opci�n valida\n\n";
		}
	
	}while (opcion != 4);
	return 0;
}
