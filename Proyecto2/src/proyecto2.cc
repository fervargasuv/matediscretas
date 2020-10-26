#include <global.h>
#include <checkArgs.hpp>


uint32_t tamTablero;
int32_t cantIteraciones;
float proCelulasVivas;

int main(int argc, char** argv){

	std::shared_ptr<checkArgs> argumentos = (std::shared_ptr<checkArgs>) new checkArgs(argc, argv);

	tamTablero = argumentos->getArgs().tamTablero;
	cantIteraciones = argumentos->getArgs().cantIteraciones;
	proCelulasVivas = argumentos->getArgs().proCelulasVivas;

	std::cout << tamTablero << ":" << cantIteraciones << ":" << proCelulasVivas << "\n";

	return 0;
}
