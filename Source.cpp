#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;

class Freq_counter {
public:
	string word;
	int count;

	bool operator < (const Freq_counter& check) const
	{
		return (count < check.count);
	}
};

string to_lower(string str)
{
	for (char& c : str) c = tolower(c);
	return str;
}

int main(int argc, char** args) {
	if (argc != 2) {
		cout << "No!\n";
		return 1;
	}
	string fname = args[1];
	cout << "You want file: " << fname << "\n";
	ifstream input(fname);
	if (!(input.is_open())) { cout << "No\n"; return 1; }
	vector <Freq_counter> topten;
	vector <string> result;
	string word;
	Freq_counter obj;
	while (input >> word) {
		result.push_back(to_lower(word));
	}

	sort(result.begin(), result.end());
	int curr_count = 1;
	int max_count = 1;
	for (int i = 1; i < result.size(); i++) {
		if (result[i] == result[i - 1]) ++curr_count;
		else
		{
			obj.word = result[i - 1];
			obj.count = curr_count;
			topten.push_back(obj);
			curr_count = 1;
		}
	}

	if (curr_count > max_count)
	{
		obj.word = result[result.size()];
		obj.count = curr_count;
		topten.push_back(obj);
	}
	sort(topten.begin(), topten.end());
	reverse(topten.begin(), topten.end());

	cout << "Top 10 frequent words are: " << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << ". " << topten[i].word << " : " << topten[i].count << endl;
	}

	system("pause");
	return 0;
}

