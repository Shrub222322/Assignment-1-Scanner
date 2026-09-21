#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;





int main()
{
	ifstream infile;
	ofstream outfile;
	
	vector<string> words;
	
	infile.open("input.txt");

	if (!infile)
	{
		cout << "Error opening input file." << endl;
		return 1;
	}
	while (!infile.eof())
	{
		string line;
		getline(infile, line);
		//cout << "Read line: " << line << endl;
		//doing great here
		// now break down the line into words.
		for (	int i = 0; i < line.length(); i++)
		{
			if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			{
				line.erase(i, 1);
				i--;
			}
			if( line[i] == '/' && line[i + 1] == '/')
			{
				line.erase(i, line.length() - i);
				break;
			}

		}
		words.push_back(line);


	}
		bool comment = false;
		for (int i = 0; i < words.size(); i++)
		{
			cout << words[i] << endl;

			/*if (line[i] == '/' && line[i + 1] == '/')
			{
				// Found a comment, ignore the rest of the line
				cout << "Found comment at index: " << i << endl;
				break;
			}
			if (line[i] == '/' && line[i + 1] == '*')
			{
				
				
			}
			cout << line << endl;*/
		}


	



}

/*
Input using read.
• Output using write.
• Assignment using :=

*/