#pragma once
using namespace System;

ref class Pokemon
{
private:
	String^ nom_Pokemon;
	String^ gen;
	String^ tipo;
public:
	String^ obtener_Nombre();
	String^ obtener_Gen();
	String^ obtener_Tipo();

	void establecer_Nombre(String^ _nom_Pokemon);
	void establecer_Gen(String^ _gen);
	void establecer_Tipo(String^ _tipo);
};

