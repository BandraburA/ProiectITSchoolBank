#pragma once
#include"ContBancar.h"
#include<vector>
#include<iostream>
#include "FileManager.h"
class ManagerConturi
{
private:
	std::vector<ContBancar*> m_listaConturi;
	std::string CreateIban(); //todo: bug iban ul nu este unic
	ContBancar* FindAccount();
	FileManager* m_fileManager;
public:
	void adaugareCont();

	int GetNumarConturi(); 
	  
	void printAllConturi();

	void EraseAccount();

	void Eliberare_Depunere();

	ManagerConturi();
	~ManagerConturi();
};

