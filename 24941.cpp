// Uncompress
// uva 245
// AC

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> word_list;
	string buf;
	while (getline(cin, buf) && buf[0] != '0') {
		int num = 0, state = 0; // 2:number, 1:letter, 0:others

		string word;
		for (int i = 0; i < buf.size(); i++) { 
			if (isalpha(buf[i])) {
				word = "";
				while (isalpha(buf[i]))
					word += buf[i++]; // get word
                i--;

				word_list.push_back(word);

				cout << word;
			} 
            else if (isdigit(buf[i])) {
				num = 0;
				while (isdigit(buf[i])) {
					num *= 10;
					num += buf[i++] - '0';
				}
                i--;

                int idx = word_list.size() - num; // the order is reversed (the newer, the backer)
				word = word_list[idx];
                auto newIt = word_list.end() - num;
				word_list.erase(newIt);

	        	word_list.push_back(word);
	        	
				cout << word;
			} 
            else 
				cout << buf[i]; // space, comma...etc
		}

		cout << '\n';
	}

    return 0;
}