#pragma once
using namespace System;

ref class Pokemon
{
private:
	String^ nom_Pokemon;
	String^ gen;
public:
	String^ obtener_Nombre();
	String^ obtener_Gen();

	void establecer_Nombre(String^ _nom_Pokemon);
	void establecer_Gen(String^ _gen);
};

