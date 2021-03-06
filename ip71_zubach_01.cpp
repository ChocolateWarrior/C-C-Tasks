#include <string>
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]) {
	string filename;
	cout << "Enter filename: ";
	cin >> filename;
	ifstream fin(filename.c_str());
	ofstream fout("ip71_zubach_01_output.txt");
	int length;
	fin >> length;
	int arr[length];
	for (int i = 0; i < length; i++) {
		fin >> arr[i];
	}

	for (int el = 0; el < length; el++) {
		for (int ev = 0; ev < length; ev++) {
			if (arr[ev] % 2 == 0) {
				int temp = arr[ev];
				if (ev > 0 && arr[ev - 1] % 2 == 0) {
					if (arr[ev] < arr[ev - 1]) {
						arr[ev] = arr[ev - 1];
						arr[ev - 1] = temp;
					}
				}
				else {
					if (ev - 1 != -1) {
						arr[ev] = arr[ev - 1];
						arr[ev - 1] = temp;
					}
				}
			}
		}
	}

	for (int el = length - 1; el >= 0; el--) {
		for (int odd = length - 1; odd > 0; odd--) {
			if (arr[odd] % 2 == 0) {
				break;
			}
			if (arr[odd] > arr[odd - 1]) {
				int temp = arr[odd];
				arr[odd] = arr[odd - 1];
				arr[odd - 1] = temp;
			}
		}
	}

	cout << "Size: " << length << endl;

	for (int o = 0; o < length; o++) {
		fout << ' ' << arr[o] << endl;
	}
	cout << "Did all" << endl;
}


