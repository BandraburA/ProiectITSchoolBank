#include "ManagerConturi.h"

void ManagerConturi::adaugareCont()
{
	std::string nume, prenume, iban;
	std::cout << "Introduceti numele persoanei: \n";
	std::cin >> nume;
	std::cout << "Introduceti prenumele persoanei: \n";
	std::cin >> prenume;
	iban = CreateIban();
	ContBancar* cont = new ContBancar(nume, prenume, iban);

	m_listaConturi.push_back(cont);
	m_fileManager->WriteToCSV(nume, prenume, iban);

	system("cls");
}

int ManagerConturi::GetNumarConturi()
{
	int numarConturi = m_listaConturi.size();
	return numarConturi;
}

void ManagerConturi::printAllConturi()
{
	for (auto& cont : m_listaConturi)
	{
		std::cout << "Nume: " << cont->getNume() << std::endl;
		std::cout << "Prenume: " << cont->getPrenume() << std::endl;
		std::cout << "IBAN: " << cont->getIban() << std::endl;
		std::cout << "Sold: " << cont->getSold() << std::endl;

	}
	std::cout << "Apasati tasta 0 pentru a va intoarce\n";
	char back;
	std::cin >> back;

}

std::string ManagerConturi::CreateIban()
{
	int iban = 11111 + (std::rand() % (99999));
	std::string stringIban = std::to_string(iban);
	std::cout << "IBAN generat: " << stringIban << std::endl;
	std::string stringIbanComplet = "RO44ItSchool" + stringIban;
	return stringIbanComplet;
}

ManagerConturi::ManagerConturi()
{
	m_fileManager = new FileManager();
	// populam lista conturi cu ce se afla in .csv
	m_listaConturi = m_fileManager->ReadContBancarFromCSV();
}

ManagerConturi::~ManagerConturi()
{
	delete m_fileManager;
}
