#include "Keeper.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

// Converts a three-letter month ("Jan".."Dec") to 1..12, or 0 if invalid.
// Complexity: O(1)
int Keeper::monthToNumber(const string& month) {
    static const string names[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; i++) {
        if (names[i] == month) {
            return i + 1;
        }
    }
    return 0;
}

// Builds a number that orders records chronologically (MMDDhhmmss).
// Complexity: O(1)
long long Keeper::makeKey(int month, int day, int hour, int minute, int second) {
    return month * 100000000LL + day * 1000000LL + hour * 10000LL + minute * 100LL + second;
}

// Rebuilds the original log line of a record.
// Complexity: O(1)
string Keeper::format(const Record& r) {
    return r.month + " " + to_string(r.day) + " " + r.time + " " + r.ip + " " + r.reason;
}

// Opens the input file, reads it line by line and stores every record in the vector.
// Complexity: O(n), n = number of lines
bool Keeper::read(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Could not open " << fileName << endl;
        return false;
    }

    records.clear();
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        istringstream ss(line);
        Record r;
        ss >> r.month >> r.day >> r.time >> r.ip;
        getline(ss >> ws, r.reason);

        int hour = 0, minute = 0, second = 0;
        char colon;
        istringstream ts(r.time);
        ts >> hour >> colon >> minute >> colon >> second;

        r.key = makeKey(monthToNumber(r.month), r.day, hour, minute, second);
        records.push_back(r);
    }
    file.close();
    return true;
}

// Sorts the records by date and time using Merge Sort.
// Complexity: O(n log n)
void Keeper::sorting() {
    if (records.size() < 2) {
        return;
    }
    vector<Record> temp(records.size());
    mergeSort(0, records.size() - 1, temp);
}

// Recursively splits the range [left, right] and merges the sorted halves.
// Complexity: O(n log n)
void Keeper::mergeSort(int left, int right, vector<Record>& temp) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(left, mid, temp);
    mergeSort(mid + 1, right, temp);
    merge(left, mid, right, temp);
}

// Merges the sorted ranges [left, mid] and [mid + 1, right].
// Complexity: O(n)
void Keeper::merge(int left, int mid, int right, vector<Record>& temp) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (records[i].key <= records[j].key) {
            temp[k++] = records[i++];
        } else {
            temp[k++] = records[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = records[i++];
    }
    while (j <= right) {
        temp[k++] = records[j++];
    }
    for (int x = left; x <= right; x++) {
        records[x] = temp[x];
    }
}

// Binary search: index of the first record with key >= the given key.
// Complexity: O(log n)
int Keeper::lowerBound(long long key) const {
    int low = 0, high = records.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (records[mid].key < key) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

// Binary search: index of the first record with key > the given key.
// Complexity: O(log n)
int Keeper::upperBound(long long key) const {
    int low = 0, high = records.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (records[mid].key <= key) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

// Asks the user for a date in the format "Mon D" (e.g. "Jun 1") until it is valid.
// Complexity: O(1) per attempt
bool Keeper::askDate(const string& label, int& month, int& day) const {
    while (true) {
        cout << "Enter the " << label << " date (e.g. Jun 1): ";
        string monthText;
        if (!(cin >> monthText >> day)) {
            if (cin.eof()) {
                return false;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid date, try again." << endl;
            continue;
        }
        month = monthToNumber(monthText);
        if (month == 0 || day < 1 || day > 31) {
            cout << "Invalid date, try again." << endl;
            continue;
        }
        return true;
    }
}

// Asks for a start and end date, finds every record in that range with
// binary search and shows it on screen. Found records are kept in results.
// Complexity: O(log n + k), k = number of records found
void Keeper::searchRecords() {
    results.clear();

    int startMonth, startDay, endMonth, endDay;
    if (!askDate("start", startMonth, startDay) || !askDate("end", endMonth, endDay)) {
        return;
    }

    long long startKey = makeKey(startMonth, startDay, 0, 0, 0);
    long long endKey = makeKey(endMonth, endDay, 23, 59, 59);
    if (startKey > endKey) {
        cout << "The start date is after the end date." << endl;
        return;
    }

    int first = lowerBound(startKey);
    int last = upperBound(endKey);
    for (int i = first; i < last; i++) {
        results.push_back(records[i]);
        cout << format(records[i]) << endl;
    }
    cout << results.size() << " records found." << endl;
}

// Writes the results of the last search to the output file.
// Complexity: O(k), k = number of records found
bool Keeper::store(const string& fileName) const {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Could not create " << fileName << endl;
        return false;
    }
    for (const Record& r : results) {
        file << format(r) << '\n';
    }
    file.close();
    cout << "Results saved to " << fileName << endl;
    return true;
}

// Returns how many records were read.
// Complexity: O(1)
int Keeper::size() const {
    return records.size();
}
