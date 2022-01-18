#pragma once
#include <string>
enum class TipMoneda
{
	RON,
	EUR,

};

class ContBancar
{
	std::string m_nume;
	std::string m_prenume;
	float m_sold;
	std::string m_IBAN;
	//TODO: tipul soldului va trebui sa fei modificat intr.un enum 0=RON,1=EUR
	TipMoneda m_tipSold;
public:
	ContBancar(std::string nume, std::string prenume, std::string iban);

	std::string getNume() const;

};

