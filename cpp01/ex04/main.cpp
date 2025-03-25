/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:36:40 by rwegat            #+#    #+#             */
/*   Updated: 2025/03/25 21:42:23 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceOccurrences(const std::string& inputFile, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
	{
        std::cerr << "Error: The string to replace (s1) cannot be empty." << std::endl;
        return ;
    }
    std::ifstream inFile(inputFile);
    if (!inFile)
	{
        std::cerr << "Error: Could not open the file " << inputFile << std::endl;
        return ;
    }
    std::string outputFile = inputFile + ".replace";
    std::ofstream outFile(outputFile);
    if (!outFile)
	{
        std::cerr << "Error: Could not create the file " << outputFile << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(inFile, line))
	{
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
		{
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outFile << line << std::endl;
    }
    std::cout << "File processed successfully. Output written to " << outputFile << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    replaceOccurrences(filename, s1, s2);

    return 0;
}