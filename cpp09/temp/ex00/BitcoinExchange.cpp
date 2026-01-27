/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:32:50 by ldick             #+#    #+#             */
/*   Updated: 2025/08/29 16:24:26 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchance.hpp"

btc::btc()
{
	std::cout << "btc: Default Constructor called" << std::endl;
}

btc::btc(btc const &copy)
{
	this->_data_bank_date = copy._data_bank_date;
	this->_data_bank_value = copy._data_bank_value;
	this->_input_data_date = copy._input_data_date;
	this->_input_data_value = copy._input_data_value;
	std::cout << "btc: Copy Constructor called" << std::endl;
}

btc &btc::operator =(btc const &copy)
{
	if (this != &copy)
	{
		this->_data_bank_date = copy._data_bank_date;
		this->_data_bank_value = copy._data_bank_value;
		this->_input_data_date = copy._input_data_date;
		this->_input_data_value = copy._input_data_value;
	}
	std::cout << "btc: Assignment operator called" << std::endl;
	return (*this);
}

btc::~btc()
{
	this->_data_bank_date.clear();
	this->_data_bank_value.clear();
	this->_input_data_date.clear();
	this->_input_data_value.clear();
	std::cout << "btc: Default Deconstructor called" << std::endl;
}

static std::string	check_date(std::string line)
{
	int index = 0;
	bool error = false;
	while(line[index] != '|' && line[index])
		index++;
	if (line[index] == '\0')
		error = true;
	if (index != 8)
		error = true;
	for (int i = 0; i > 8 ; i++)
		if (line[i] < '0' || line[i] > '9')
			error = true;
	int year = std::atoi(line.substr(0, 4).c_str());
	if (year < 2009 || year > 3000)
		error = true;
	int month = std::atoi(line.substr(4, 2).c_str());
	if (month > 12 || month < 1)
		error = true;
	int day = std::atoi(line.substr(6, 2).c_str());
	int daysinmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day < 1 || day > daysinmonth[month -1])
		error = true;
	if (error == true)
	{
		line.resize(16);
		line.replace(0, line.size(),"-999999 | -99999");
	}
	return (line);
}

void	btc::add_databank(std::string line)
{
	this->_data_bank_date.push_back(std::atoi(line.substr(0, 8).c_str()));
	this->_data_bank_value.push_back(std::atof(line.substr(9).c_str()));
}

int btc::Check_Data_Bank(const char * data)
{
	std::ifstream databank(data);
	if (!databank.is_open())
		return (1);
	std::string line;
	std::getline(databank, line);
	while(std::getline(databank, line))
	{
		line.erase(std::remove(line.begin(), line.end(), '-'), line.end());
		line.append(1, '\n');
		this->add_databank(line);
	}
	return (0);
}

static std::string check_value(std::string line)
{
	int i = 9;
	bool error = false;
	for (;line[i] != '\n'; i++)
		if ((line[i] < '0' || line[i] > '9') && line[i] != '.')
			error = true;
	int value = std::atof(line.substr(9).c_str());
	if (value < 0 || value > 1000)
		error = true;
	if (error == true)
	{
		line.resize(21);
		line.replace(0, line.size(),"-99999999 | -99999999");
	}
	return (line);
}

void	btc::add_input(std::string line)
{
	if (line != "-9999999|-9999999\n")
	{
		line = check_date(line);
		if (line != "-999999 | -99999")
			line = check_value(line);
	}
	this->_input_data_date.push_back(std::atoi(line.substr(0, line.find("|")).c_str()));
	this->_input_data_value.push_back(std::atof(line.substr(line.find("|") + 1).c_str()));
}

int	btc::Check_input(char *data)
{
	std::ifstream input_data(data);
	if (!input_data.is_open())
		return (1);
	std::string line;
	std::getline(input_data, line);
	while(std::getline(input_data, line))
	{
		if (std::count(line.begin(), line.end(), '|') != 1)
		{
			line.resize(20);
			line.replace(line.begin(), line.end(), "-9999999 | -9999999");
		}
		line.erase(std::remove(line.begin() + 1, line.begin() + 10, '-'), line.begin() + 10);
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		line.append(1, '\n');
		this->add_input(line);
	}
	return (0);
}

void btc::calculate(void)
{
	//find coresponding date in databank
	unsigned long int i = 0;
	int correct_date_position;
	int date_to_find;
	std::vector<int>::iterator finder;
	while(i < this->_input_data_date.size())
	{
		if (this->_input_data_date[i] == -999999 || this->_input_data_value[i] == -999999)
		{
			std::cerr << "incorrect date at position " << i << " in input list\t\t" << this->_input_data_date[i] << " | " << this->_input_data_value[i] << std::endl;
			i++;
			continue ;
		}
		if (this->_input_data_value[i] == -99999999 || this->_input_data_date[i] == -99999999)
		{
			std::cerr << "incorrect value at position " << i << " in input list\t\t" << this->_input_data_date[i] << " | " << this->_input_data_value[i] << std::endl;
			i++;
			continue ;
		}
		if (this->_input_data_date[i] == -9999999 || this->_input_data_value[i] == -9999999)
		{
			std::cerr << "incorrect input at position " << i << " in input list\t\t" << std::endl;
			i++;
			continue ;
		}
		date_to_find = this->_input_data_date[i];
		while(1)
		{
			if (date_to_find > 20220329)
			{
				correct_date_position = this->_data_bank_date.size() - 1;
				break ;
			}
			finder = std::find(this->_data_bank_date.begin(), _data_bank_date.end(), date_to_find);
			if (finder != this->_data_bank_date.end())
			{
				correct_date_position = finder - this->_data_bank_date.begin();
				break ;
			}
			else
				date_to_find--;
		}
		std::ostringstream oss;
		oss << this->_input_data_date[i];
		std::string date = oss.str();
		date.insert(4, "-");
		date.insert(7, "-");
		std::cout << date << " => " << this->_input_data_value[i] << " = " << this->_input_data_value[i] * this->_data_bank_value[correct_date_position] << std::endl;
		i++;
	}
	
}