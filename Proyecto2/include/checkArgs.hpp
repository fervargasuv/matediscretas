#ifndef _CHECKARGS_H_
#define _CHECKARGS_H_

#include <unistd.h>

extern char *optarg;
extern int optind, opterr, optopt;

class checkArgs {
private:
	// 1) Modificar esta sección -> lo minimo está para que funcione
	const std::string optString = "T:G:P:h";

	const std::string opciones = " -T <nro>  -P <nro>  -G <nro> [-h]";

	const std::string descripcion = "Parámetros:\n"
									"\t-T   : Tamaño del tablero.\n"
									"\t-P   : Probabilidad inicial de que una célula esté viva.\n"
									"\t-G   : Cantidad de iteraciones.\n"
									"\t[-h] : muestra la ayuda de uso y termina.\n";

	typedef struct args_t{
		int32_t tamTablero;
		double proCelulasVivas;
		int32_t cantIteraciones;
	} args_t;

	// 2) Modificar constructor si necesita mas variables
	// 3) Modificar ciclo "getopt" en método checkArgs::getArgs(), si necesita mas variables
	// 4) Recuerde que para compilar nuevamente, y por tratarse
	//    de un archivo header, debe hacer primero un make clean

	args_t  parametros;

	int argc;
	char **argv;


public:
	checkArgs(int _argc , char **_argv);
	~checkArgs();
	args_t getArgs();

private:
	void printUsage();


};

checkArgs::checkArgs(int _argc , char **_argv){
	parametros.tamTablero = 0;
	parametros.proCelulasVivas = 0;
	parametros.cantIteraciones = 0;
		argc = _argc;
	argv = _argv;

}

checkArgs::~checkArgs(){

}
/* 
* Si agregó una nueva varible, debe modificar la siguiente sección.
*/
checkArgs::args_t checkArgs::getArgs(){
	int opcion;
	while ((opcion = getopt (argc, argv, optString.c_str())) != -1){
		switch (opcion) {
			case 'T':
				parametros.tamTablero = atoi(optarg);
				break;
			case 'P':
				parametros.proCelulasVivas = double(atof(optarg));
				break;
			case 'G':
				parametros.cantIteraciones = atoi(optarg);
				break;
			case 'h':
			default:
					printUsage();
					exit(EXIT_FAILURE);
		}
	}

	/*
	* Aquí ebe sentenciar los input, para no ingresar datos incorrectos.
	* Debe devolver :
	*    printUsage();
	*	 exit(EXIT_FAILURE); 
	*/

	return(parametros);
}

void checkArgs::printUsage(){
	std::cout << "Uso: " <<
		argv[0] << " " << opciones << " " << descripcion << std::endl;
}



#endif
