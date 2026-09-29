#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;





int main()
{
	ifstream infile;
	ofstream outfile;
	
	vector<string> words;
	string word;
	char cha;
	
	infile.open("input.txt");

	if (!infile)
	{
		cout << "Error opening input file." << endl;
		return 1;
	}


	while (infile.get(cha))
	{

		word += cha;
	}


	int pos = 0;
	while ((pos = word.find("//", pos)) != std::string::npos)
		{
		int end = word.find('\n', pos);
		if (end == std::string::npos)
			end = word.length();

		word.replace(pos, end - pos, "");
	}


	pos = 0;
	while ((pos = word.find("/*", pos)) != std::string::npos)
			{
		int end = word.find("*/", pos);
		if (end == std::string::npos)
			end = word.length();
		else
			end += 2;

		word.replace(pos, end - pos, "");
			}

	for (int i = 0; i < word.length(); i++)
			{
		if (word[i] == '\n' || word[i] == '\t')
		{
			word[i] = ' ';
		}
		if (word[i] == '/' || word[i] == '*' || word[i] == '+' || word[i] == '-' || word[i] == '(' || word[i] == ')')
		{
			word.insert(i + 1, " ");
		}
		if ((isdigit(word[i]) || isalpha(word[i])) && word[i + 1] == ')')
		{
			word.insert(i + 1, " ");
		}
		if (isalpha(word[i]) && isdigit(word[i + 1])) // handles a1 a2 ect
		{
			word.insert(i + 2, " ");

			}

		if (word[i] == ':' && word[i + 1] == '=')
		{
			word.insert(i + 2, " ");
		}
		if ((isalpha(word[i])) && (word[i+1] == ':'))
		{

			word.insert(i + 1, " ");
		}

	}

	stringstream ss(word);
	while (ss >> word)
		{
		if (word == "sum"||word == "read" || word == "write" || word == ":=" || word == "+" || word == "-" || word == "*" || word == "/" || word == "(" || word == ")")
			{
			words.push_back(word);
			}
		else
			{
			words.push_back(word);
		}
			}
	outfile.open("Output.txt");
	for (const auto& w : words)
	{
		cout << w << endl;
		outfile << w << endl;
		}

	outfile.close();
	infile.close();
}
		//cout << words.size() << endl;

	// we now have a full gone throught words vector.
		//Expressions may contain identifiers, numbers, parentheses, addition, subtraction, multiplication,
	//and division.The complete grammar for the language appears later in this document.
	/*
	program → stmt list
    stmt list → stmt stmt list | ϵ
    stmt → id := expr | read id | write expr
expr → term term tail
term tail → add op term term tail | ϵ
term → factor fact tail
fact tail → mult op fact fact tail | ϵ
factor → ( expr ) | id | number
add op → + | -
mult op → * | /
	
	*/





/*
Input using read.
• Output using write.
• Assignment using :=

*/