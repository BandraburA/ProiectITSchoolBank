#pragma once
#include"ContBancar.h"
#include<vector>
#include<iostream>
#include "FileManager.h"
class ManagerConturi
{
private:
	std::vector<ContBancar*> m_listaConturi;
	std::string CreateIban();
	FileManager* m_fileManager;
public:
	void adaugareCont();

	int GetNumarConturi(); 

	void printAllConturi();

	ManagerConturi();
	~ManagerConturi();
};

