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
	m_fileManager->WriteToCSV(nume, prenume, iban,cont -> getSold());

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

void ManagerConturi::EraseAccount()
{
	std::cout << "Introduceti datele pentru contul ce urmeaza sa fie sters\n";

	ContBancar* cont = FindAccount();
	std::vector<ContBancar*>::iterator it = std::find(m_listaConturi.begin(), m_listaConturi.end(), cont);
	m_listaConturi.erase(it);
	delete cont;
	
}

void ManagerConturi::Eliberare_Depunere()
{
	ContBancar* cont = FindAccount();
	if (cont != nullptr)
	{
		float valoare;
		std::cout << "Introdu valoare: \n";
		std::cin >> valoare;
		cont->manipulareSold(valoare);
	}
	else
	{
		std::cout << " Contul este inexistent \n";
	}
}

std::string ManagerConturi::CreateIban()
{
	int iban = 11111 + (std::rand() % (99999));
	std::string stringIban = std::to_string(iban);
	std::cout << "IBAN generat: " << stringIban << std::endl;
	std::string stringIbanComplet = "RO44ItSchool" + stringIban;
	return stringIbanComplet;
}

ContBancar* ManagerConturi::FindAccount()
{
	std::cout << "Numele Titularului: \n";
	std::string nume;
	std::cin >> nume;
	//TODO trebuie extins, fie facem o metoda ce accepta Nume sau Prenume, fie facem cumva in aceasta metoda

	for (auto& cont : m_listaConturi)
	{
		if (cont->getNume() == nume)
			return cont;
	}
	std::cout << "Titularul nu a fost gasit \n";
	return nullptr;
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
	//todo: iteram m_lista_conturi si stergem fiecare cont in parte dupa care clearuim
}
