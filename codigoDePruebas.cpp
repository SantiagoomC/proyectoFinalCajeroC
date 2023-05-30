#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

bool saldoDisponible (int saldo, int listaSaldos[],int indiceCuentaEncontrado){

//int listaSaldos[4], indiceCuentaEncontrado;


if (listaSaldos[indiceCuentaEncontrado] >= saldo){
return true;
}
return false;
}



bool validarCorreo(const string& correo) {
size_t posicionArroba = correo.find("@");

if (posicionArroba == string::npos || posicionArroba == 0 || posicionArroba == correo.length() - 1) {
return false;
}

string dominio = correo.substr(posicionArroba + 1);

return (dominio == "gmail.com" || dominio == "yahoo.com");
}

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

// PRUEBA: Valida si tiene sólo texto el CIN.
bool contieneSoloLetras(const string& texto) {
for (char c : texto) {
if (!isalpha(c)) {
return false;
}
}
return true;
}

//CONVERTIR A MINUSCULAS
string convertirAMinuscula(const string& str) {
string result = str;

for (size_t i = 0; i < result.length(); i++) {
if (isupper(result[i])) {
result[i] = tolower(result[i]);
}
}

return result;
}

//PRIMERA LETRA EN MAYUSCULA
string primeraLetraMayuscula(const string & input) {
if (input.empty()) {
return input;
}

string result = input; 

result[0] = toupper(result[0]);

return result;
}


//PUREBAS
//VALIDACIÓN DE NOMBRE
string validarNombre(){
int intentos = 1;
string nombreUsuario;


while (intentos <= 3){
cout << "Nombre: ";
cin >> nombreUsuario;
nombreUsuario = convertirAMinuscula(nombreUsuario);
nombreUsuario = primeraLetraMayuscula(nombreUsuario);

if (contieneSoloLetras(nombreUsuario) && nombreUsuario.size() >= 4) {
break;
}

cout << "El nombre debe contener solo letras y tener más de una letra. Intentelo nuevamente.\n";

intentos++;

if(intentos > 3){
cout << "\nHa alcanzado el número máximo de intentos. Por seguridad debe reiniciar el proceso.\n" << endl;
return "";
}
}

return nombreUsuario;
}

//VALIDAR APELLIDO
string validarApellido(){
int intentos = 1;
string apellidoUsuario;


while (intentos <= 3){
cout << "Apellido: ";
cin >> apellidoUsuario;
apellidoUsuario = convertirAMinuscula(apellidoUsuario);
apellidoUsuario = primeraLetraMayuscula(apellidoUsuario);

if (contieneSoloLetras(apellidoUsuario) && apellidoUsuario.size() >= 4) {
break;
}

cout << "El apellido debe contener solo letras y tener más de una letra. Intentelo nuevamente.\n";

intentos++;
if(intentos > 3){
cout << "\nHa alcanzado el número máximo de intentos. Por seguridad debe reiniciar el proceso.\n" << endl;
return "";
}

}
return apellidoUsuario;
}


string validarCedula(){
string numeroCedula;
int intentos = 0;

do {
cout << "Número de cédula: ";
cin >> numeroCedula;

if (validarNumero(numeroCedula) && numeroCedula.size()==7) {
return numeroCedula;
} else {
intentos++;
cout << "El número de la cédula debe contener solo números y tener 7 dígitos. Inténtelo nuevamente." << endl;
cout << "Intentos restantes: " << 3 - intentos << endl;
}
} while (intentos < 3);

cout << "Se agotaron los intentos. Reiniciando el registro.\n" << endl;
return "";
}

// VALIDAR NÚMERO DE CELULAR
string validarCelular() {
string numeroCelular;
int intentos = 1;

while (intentos <= 3) { 
cout << "Número de celular: ";
cin >> numeroCelular;

if (validarNumero(numeroCelular) && validarPrefijo(numeroCelular) && numeroCelular.size() == 10) {
	break;
}

cout << "El número de celular debe contener sólo números, tener 10 dígitos, y el prefijo debe ser 301, 313 o 321." << endl;

intentos++;

if (intentos > 3) {
	cout << "\nHa alcanzado el número máximo de intentos. Por seguridad debe reiniciar el proceso.\n" << endl;
	return "";
}
}

return numeroCelular;
}


// VALIDAR EL NÚMERO FIJO
string validarNumeroFijo() {
string numeroFijo;
int intentos = 1;
cout << "Número fijo: ";
cin >> numeroFijo;

while ((!validarNumero(numeroFijo)) || !validarPrefijo(numeroFijo) || !(numeroFijo.size() == 7)) {
cout << "El número fijo debe contener sólo números, tener 7 dígitos, y el prefijo debe ser 250, 251 o 260." << endl;
cout << "Inténtelo nuevamente: ";
cin >> numeroFijo;
//return "";
intentos++;

if (intentos > 3) {
	cout << "\nHa alcanzado el número máximo de intentos. Por seguridad debe de reiniciar el proceso.\n" << endl;
	break;
}
}
return numeroFijo;
}

//VALIDAR CIUDAD 
string validarCiudad(){
int opcion; 
string ciudad;

cout << "¿Cuál es su ciudad de residencia?\n 1. Medellín\n 2. Cali\n 3. Barranquilla\nIngrese una opcion: ";
cin >> opcion;

switch (opcion){
case 1:
ciudad = "Medellín";
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
string validarCorreo() {
string correo;
int intentos = 1;


while (intentos <= 3){
	cout << "Correo electrónico: ";
	cin >> correo;
	correo = convertirAMinuscula(correo);
	
	if(validarCorreo(correo)) {
		break;
	}
	
	cout << "El correo electrónico no es válido. Inténtelo nuevamente.\n";
	intentos++;
	
	if(intentos > 3){
		cout << "\nHa alcanzado el número máximo de intentos. Por seguridad debe reiniciar el proceso.\n" << endl;
		return "";
	}
}
return correo;
}


// VALIDAR NUMERO DE CUENTA
bool numeroCuentaExistente(const string& numeroCuenta, const vector<string>& listaNumeroCuenta) {
for (const string& cuenta : listaNumeroCuenta) {
	if (cuenta == numeroCuenta) {
		return true; // El número de cuenta ya existe en la lista
	}
}
return false; // El número de cuenta no existe en la lista
}

string validarNumeroCuenta() {
string numeroCuenta;
cout << "Número de 5 dígitos para asignar a la cuenta: ";
cin >> numeroCuenta;

while (!validarNumero(numeroCuenta) || numeroCuenta.size() != 5) {
	cout << "Recuerda que la cuenta debe contener solo números y tener 5 dígitos. Además, no puede estar repetida. Inténtelo nuevamente: ";
	cin >> numeroCuenta;
}

return numeroCuenta;
}


// VALIDAR CONTRASEÑA
string validarContrasenna(){
string contrasennaUsuario;
cout << "Contraseña para la cuenta: ";
cin >> contrasennaUsuario;

if (contrasennaUsuario.size() == 5){
	return contrasennaUsuario;
}
return "";

}

//

int main(int argc, char *argv[]) {
	int otroUsuario, contadorPosicion, opcion, i, saldoApertura, intentosApertura, opcionApertura, opcionesCajero, saldo;
	
	//Variables de prueba:
	string cuentaABuscar, contrasennaABuscar;
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
		
		cout << "¿Qué desea hacer?\n";
		cout << "1. Ingresar a mi cuenta bancaria.\n";
		cout << "2. Crear una cuenta.\n";
		cout << "3. Cajero.\n";
		cout << "4. Salir.\n";
		
		cout << "\nIngrese una opción: ";
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
					//CORREO
					listaCorreo[contadorPosicion] = validarCorreo();
					if (listaCorreo[contadorPosicion].empty()) {
						contadorPosicion = contadorPosicion;
						break;
					}
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
						cout << "Por último, para aperturar la cuenta debes de ingresar un monto mínimo de $30.000 en adelante.\n¿Cuánto dinero vas a ingresar?: ";
						cin >> saldoApertura;
						if (saldoApertura >= 30000){
							listaSaldos[contadorPosicion] = saldoApertura;
							intentosApertura = 4;
						} else {
							cout << "Lo sentimos el monto ingresado es inferior al requerido.\n";
							
							if (intentosApertura == 3){
								cout << "Ha culminado los intentos disponibles para la transacción, por seguridad debe hacer nuevamente el proceso\n\n";
								break;
							}
						}
						intentosApertura++;
					}
					
					//FINAL;
					cout << "\nExcelente su registro se ha realizado con éxito con los siguientes datos:\n\n";
					cout << "Nombre: " << listaNombre[contadorPosicion] << endl;
					cout << "Apellido: " << listaApellidos[contadorPosicion] << endl;
					cout << "Cedula: " << listaCedula[contadorPosicion] << endl;
					cout << "Celular: " << listaCelular[contadorPosicion] << endl;
					cout << "Telefono: " << listaTelefono[contadorPosicion] << endl;
					cout << "Ciudad: " << listaCiudad[contadorPosicion] << endl;
					cout << "Correo: " << listaCorreo[contadorPosicion] << endl;
					cout << "Número de cuenta: " << listaNumeroCuenta[contadorPosicion] << endl;
					cout << "Contraseña: *****" << endl;
					cout << "Saldo de apertura: " << listaSaldos[contadorPosicion] << endl << endl;
					cout << "Sí los datos son correctos puede marcar 1. Para finalizar o 2.Realizar el registro nuevamente.\n\nIngrese una opción: ";
					cin >> opcionApertura;
					cout << "\n";
					
					if(opcionApertura == 1){
						cout << "¿Desea registrar otro usuario? 1. Sí - 2. No : ";
						cin >> otroUsuario;
						if(otroUsuario == 1){
							contadorPosicion++;
							if (contadorPosicion > 3){
								cout << "Lo sentimos, ya no tenemos más cupos disponibles\n\n";
								break;
							}
						}else if (otroUsuario == 2){
							contadorPosicion++;
							break;
						} else {
							cout << "Ingrese una opción valida\n"; 
						}
						//							}else {
						//								cout << "Lo sentimos ya no tenemos más cupo para el registro de cuentas\n\n";
						//							}
					} else if (opcionApertura == 2){
						contadorPosicion = contadorPosicion;
						continue;
					} else {
						cout << "Ingrese una opción valida";
					}
				}
			}
			break;
		case 3:
			encontrado = false;
			cout << "\nModo Cajero.\nIngrese por favor número de cuenta: ";
			cin >> cuentaABuscar;
			
			if (cuentaABuscar.size() == 5 && !contieneSoloLetras(cuentaABuscar)){
				
				//cout << "\nCuenta a buscar: " << cuentaABuscar << endl;
				int indiceCuentaEncontrado = -1;
				int indiceContrasennaEncontrado = -1;
				int intentosContrasenna = 1;
				
				for (int i = 0; i <= 3; i++) {
					if (listaNumeroCuenta[i] == cuentaABuscar) {
						indiceCuentaEncontrado = i;
						encontrado = true;
						
						while (intentosContrasenna <= 3) {
							cout << "Ingrese por favor la contraseña: ";
							cin >> contrasennaABuscar;
							
							bool contrasennaEncontrada = false;
							
							for (int i = 0; i <= 3; i++) {
								if (listaContrasenna[i] == contrasennaABuscar) {
									indiceContrasennaEncontrado = i;
									contrasennaEncontrada = true;
									intentosContrasenna = 4;
									break;
								}
							}
							
							if (contrasennaEncontrada) {
								break;
							} else {
								cout << "La contraseña no coincide con la que tenemos en la base de datos. Inténtalo nuevamente.\n";
								if (intentosContrasenna == 3) {
									cout << "Ha culminado los intentos disponibles, por seguridad reiniciaremos el proceso.\n\n";
									break;
								}
							}
							intentosContrasenna++;
						}
					}
				}
				
				if (indiceCuentaEncontrado != -1 && indiceContrasennaEncontrado != -1 && encontrado) {
					cout << "\n  Bienvenido " + listaNombre[indiceCuentaEncontrado] << endl;
					do {
						cout << "\n";
						cout << "	¿Qué desea hacer?\n";
						cout << "	1. Retirar dinero.\n";
						cout << "	2. transferir Dinero.\n";
						cout << "	3. Adicionar dinero.\n";
						cout << "	4. Salir.\n";
						
						cout << "\nIngrese una opción: ";
						cin >> opcionesCajero;
						
						switch (opcionesCajero){
						case 1:
							listaSaldos[indiceCuentaEncontrado];
							cout << "Ingrese el valor a retirar o transferir: ";
							cin >> saldo;
							if(saldoDisponible(saldo, listaSaldos, indiceCuentaEncontrado)){
								cout << "Funcionó :0";
								cout << listaSaldos[indiceCuentaEncontrado] - saldo;
							} else {
								cout << "Paila";
							}
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							cout << "Hasta luego " << listaNombre[indiceCuentaEncontrado] << " que vuelva pronto.";
							break;
						default:
							cout << "Ingrese un opción valida.\n";
						}
					} while (opcionesCajero != 4); //while (indiceEncontrado != -1 && encontrado);
					//break;
				} else {
					cout << "\nLa cuenta que ingresaste no está en nuestro sistema.\n\n";
				}
			} else {
				cout << "Recuerda que las cuentas son de 5 digitos y sólo deben de contener números.\n\n";
			}
			
			
			
			break;
		case 4:
			cout << "\nHasta luego, que vuelva pronto.\n\n";
			break;
		default:
			cout << "\nIngrese una opción valida\n\n";
		}
		
	}while (opcion != 4);
	return 0;
}

