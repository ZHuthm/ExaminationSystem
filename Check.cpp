#include "Check.h"

void Check::createCheck(std::string nm)
{
	type temp;
	temp.name = nm;
	if (table.size() == 0) {
		temp.rate = 1.0;
		table.push_back(temp);
	}
	else {
		table.push_back(temp);
		Check::resetRate();
	}
}

void Check::deleteCheck(int index)
{
	std::vector<type>::iterator it;
	if (findIndexPos(index, it)) {
		table.erase(it);
		std::cout << "ɾ����ɣ��밴��ʾ�������ñ�����" << std::endl;
		Check::resetRate();
	}
	else std::cout << "δ�ҵ���ؿ�����Ϣ!\n";
}

void Check::enrollScore(int index, double sc)
{
	std::vector<type>::iterator it;
	if (findIndexPos(index, it)) {
		it->score.push_back(sc);
	}
	else std::cout << "δ�ҵ���ؿ�����Ϣ!\n";
}

void Check::deleteScore(int index, int n)
{
	Check::operateScore(index, n);
}

void Check::resetScore(int index, int n, double sc)
{
	Check::operateScore(index, n, sc);
}

void Check::resetRate()
{
	double r;
	std::vector<double> temp;
	std::vector<type>::iterator it;
	if (table.empty()) { std::cout << "���޿�����Ŀ��������ӣ�" << std::endl; return; }//CZH��
	while (1) {
		std::cout << "�������������ռ�ֱȣ�" << std::endl;
		for (it = table.begin(); it != table.end(); it++) {
			std::cout << it->name << ":";
			std::cin >> r;
			temp.push_back(r);
		}
		if (checkRate(temp)) {
			std::vector<double>::iterator itemp = temp.begin();
			for (it = table.begin(); it != table.end(); it++, itemp++) {
				it->rate = *itemp;
			}
			break;
		}
		else {
			std::cout << "����ı����ۺϲ���1�����������룺\n";
			temp.clear();
			continue;
		}
	}
}

void Check::showCheck(int index)
{
	std::vector<type>::iterator it;
	if (findIndexPos(index, it)) {
		printCheck(it);
	}
	else std::cout << "δ�ҵ���ؿ�����Ϣ\n";
}

void Check::showTableInfo()
{
	std::cout << std::left;
	std::vector<type>::iterator it;
	if (table.empty()) {
		std::cout << "���޿�����Ŀ��������ӣ�" << std::endl;
	}
	else {
		for (it = table.begin(); it != table.end(); it++) {
			std::cout << std::setw(4) << (it - table.begin() + 1);
			std::cout << std::setw(15) << it->name;
			std::cout << "ռ�ܷ֣�" << it->rate * 100 << "%";
			std::cout << std::endl;
		}
	}
	std::cout << std::right;
}

void Check::showTable()
{
	std::vector<type>::iterator it;
	for (it = table.begin(); it != table.end(); it++) {
		std::cout << it - table.begin()+1<<"  ";
		printCheck(it);
	}
}

double Check::getAllScore()
{
	double score = 0.0, temp;
	std::vector<type>::iterator it;
	std::vector<double>::iterator isc;
	for (it = table.begin(); it != table.end(); it++) {
		temp = 0.0;
		for (isc = it->score.begin(); isc != it->score.end(); isc++) {
			temp += *isc;
		}
		score += it->rate * (temp / it->score.size());
	}
	return score;
}

bool Check::checkRate(std::vector<double> temp)
{
	int all = 0;
	std::vector<double>::iterator it;
	for (it = temp.begin(); it != temp.end(); it++) {
		all += int((*it) * 10000);
	}
	if (all == 10000) return true;
	else return false;
}

void Check::operateScore(int index, int n, double sc)
{
	std::vector<type>::iterator it;
	if (findIndexPos(index, it)) {
		std::vector<double>::iterator isc;
		isc = it->score.begin() + n - 1;
		*isc = sc;
	}
	else std::cout << "δ�ҵ���ؿ�����Ϣ!\n";
}

bool Check::findIndexPos(int index, std::vector<type>::iterator & it)
{
	if (index < 0) return false;
	for (it = table.begin(); it != table.end(); it++) 
		if (it - table.begin() == index) 
			return true;
	return false;
}

void Check::printCheck(std::vector<type>::iterator it)
{
	std::cout << it->name << std::endl;
	if (it->score.size() == 0) {
		std::cout << "����Ŀ�ɼ�δ�Ǽ�\n";
	}
	else {
		std::vector<double>::iterator isc;
		for (isc = it->score.begin(); isc != it->score.end(); isc++) {
			std::cout << *isc << " ";
		}
		std::cout << std::endl;
	}
}
int Check::getCheckNum()
{
	return this->table.size();
}

std::string Check::getCheckName(int index)
{
	return table[index].name;
}

double Check::getCheckRate(int index)
{
	return table[index].rate;
}

void Check::initialCheck(std::string name[], double rate[], int size)
{
	for (int i = 0; i < size; i++) {
		type temp;
		temp.name = name[i];
		temp.rate = rate[i];
		table.push_back(temp);
	}
}

double Check::getScore(int index, int cindex)
{
	return table[index].score[cindex];
}

int Check::getScoreNum(int index)
{
	return table[index].score.size();
}

void Check::insertScore(int index, double sc)
{
	table[index].score.push_back(sc);
}
