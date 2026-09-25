#ifndef KEEPER_H
#define KEEPER_H

#include <string>
#include <vector>

// One line of the log: "Mon D HH:MM:SS IP:PORT reason"
struct Record {
    std::string month;
    int day;
    std::string time;
    std::string ip;
    std::string reason;
    long long key;  // numeric date/time used for sorting and searching
};

class Keeper {
private:
    std::vector<Record> records;  // every record read from the file
    std::vector<Record> results;  // records found by the last search

    static int monthToNumber(const std::string& month);
    static long long makeKey(int month, int day, int hour, int minute, int second);
    static std::string format(const Record& r);

    void mergeSort(int left, int right, std::vector<Record>& temp);
    void merge(int left, int mid, int right, std::vector<Record>& temp);
    int lowerBound(long long key) const;
    int upperBound(long long key) const;
    bool askDate(const std::string& label, int& month, int& day) const;

public:
    bool read(const std::string& fileName);
    void sorting();
    void searchRecords();
    bool store(const std::string& fileName) const;

    int size() const;
};

#endif
