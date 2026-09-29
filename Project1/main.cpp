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

		word += cha; // reading whole file to a string of words.
	}


	int pos = 0;
	while ((pos = word.find("//", pos)) != std::string::npos) // finding // comments and making sure they actually exist. 
	{
		int end = word.find('\n', pos);
		if (end == std::string::npos) // if we cant find the a newline character we have to assume that it goes to the end of the file instead.
			end = word.length();

		word.replace(pos, end - pos, ""); // getting rid of all of it
	}


	pos = 0;
	while ((pos = word.find("/*", pos)) != std::string::npos) // making sure there is a multiline comment start. 
	{
		int end = word.find("*/", pos); // finding the multilines ending position. 
		if (end == std::string::npos) // if we cant find its ending, we should really of displayed an error here but for the sake of error handling we will just say it goes to the end of the file. 
			end = word.length();
		else
			end += 2; // making sure we get rid of the */ characters!

		word.replace(pos, end - pos, "");
	}

	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == '\n' || word[i] == '\t') // getting rid of newlines and tab overs.
		{
			word[i] = ' ';
		}
		if (word[i] == '/' || word[i] == '*' || word[i] == '+' || word[i] == '-' || word[i] == '(' || word[i] == ')') 
		{
			word.insert(i + 1, " "); // making spaces between these key identifiers for kicking them out. 
		}
		if ((isdigit(word[i]) || isalpha(word[i])) && word[i + 1] == ')')
		{
			word.insert(i + 1, " "); // handling the ending case for ), as in it was getting 33) , instead of 33 ) .
		}
		if (word[i] == ':' && word[i + 1] == '=')
		{
			word.insert(i + 2, " ");
		}
		if ((isalpha(word[i])) && (word[i + 1] == ':')) // ie sum: so now its sum :
		{

			word.insert(i + 1, " ");
		}
		if (isalpha(word[i])) // handles a1 a2 a121a ect
		{
			int nextCheck = i + 1;
			while (nextCheck < word.length() && (isdigit(word[nextCheck]) || isalpha(word[nextCheck])))
			{
				nextCheck++; // so now its i + 2
			}
			// if it was a122+, we would have a = i, 1 = i + 1, 2 = i + 2, 2 = i + 3, nextcheck will now equal i + 4, and inserting here will split
			// it up in a122 + how amazing huh
			word.insert(nextCheck, " "); // ie a1234+ = a1234 + 22 (a1234 +) is the main point
			i = nextCheck; // fixing the loop due to us using a while loop above to handle identifiers such as a1 a1212 a1aa1 etc.
		}


	}

	stringstream ss(word);
	while (ss >> word) 
	{
		if (word == "sum")
			words.push_back("SUM");
		else if (word == "read")
			words.push_back("READ");
		else if (word == "write")
			words.push_back("WRITE");
					// just hard showing read write and sum now
		else if (/*word == "sum" || word == "read" || word == "write" ||*/ word == ":=" || word == "+" || word == "-" || word == "*" || word == "/" || word == "(" || word == ")")
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