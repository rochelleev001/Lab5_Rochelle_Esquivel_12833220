#include "Pokemon.h"

String^ Pokemon::obtener_Nombre() {
	return nom_Pokemon;
}

String^ Pokemon::obtener_Gen() {
	return gen;
}

String^ Pokemon::obtener_Tipo() {
	return tipo;
}

void Pokemon::establecer_Nombre(String^ _nom_Pokemon) {
	this->nom_Pokemon = _nom_Pokemon;

}
void Pokemon::establecer_Gen(String^ _gen) {
	this->gen = _gen;

}
void Pokemon::establecer_Tipo(String^ _tipo) {
	this->tipo = _tipo;

}
