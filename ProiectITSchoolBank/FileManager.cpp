#include "FileManager.h"


 void FileManager::WriteToCSV(std:: string nume, std::string prenume, std::string iban, float sold)
{
	std::fstream csv_file;
	csv_file.open("ConturiDataBase.csv", std::ios::out | std::ios::app);
	if (csv_file.is_open())
	{
		csv_file << nume << ',' << prenume << ',' << iban << ',' << sold << '\n';
	}
	else
	{
		std::cout << "Error, file not open\n";
	}
	csv_file.close();
}
 std::vector<ContBancar*> FileManager::ReadContBancarFromCSV()
 {
	 std::fstream fileInput("ConturiDataBase.csv");
	 //fileInput.open("ConturiDatabase.csv", std::ios::in);
	 std::vector<ContBancar*> conturiDinCsv;
	 std::vector<std::string> randuri;
	 std::string linie;
	 if (!fileInput.is_open())
	 {
		 std::cout << "Error file cannot be accesed\n";
	 }

	 //parsam toate liniile din fisier
	 while (std::getline(fileInput, linie))
	 {
		 randuri.push_back(linie);
	 }
	 //parsam rand cu rand si spargem in cuvinte
	 //instantam conturile si le push.uim in vectorul nostru
	 std::vector<std::string> cuvinte;
	 for (auto& rand : randuri)
	 {
		 cuvinte.clear();
		 std::string nume, prenume, iban, cuvant;
		 float sold;
		 std::stringstream s(rand);
		 while (std::getline(s, cuvant, ','))
		 {
			 if(!cuvant.empty())
			 cuvinte.push_back(cuvant);
		 }
		 if (!cuvinte.empty()) {
			 ContBancar* cont = new ContBancar(cuvinte[0], cuvinte[1], cuvinte[2]); // todo: mai un constructor pentru sold pentru ContBancar
			 conturiDinCsv.push_back(cont);
		 }

	 }
	 return conturiDinCsv;
 }