#pragma once
#include <string>
enum class TipMoneda
{
	RON,
	EUR

};

class ContBancar
{
	std::string m_nume;
	std::string m_prenume;
	float m_sold;
	std::string m_IBAN;
	TipMoneda m_tipSold;
public:
	ContBancar(std::string nume, std::string prenume, std::string iban);

	std::string getNume() const;
	std::string getPrenume() const;
	std::string getIban() const;
	float getSold() const;
};

