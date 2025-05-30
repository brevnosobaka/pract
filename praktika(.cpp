#include "AEROFLOT.h"
#include "Myarr.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int m = 7;

void createHashTable(int hashTable[][2], Myarr<AEROFLOT>& arr) {//Нужна для создания хеш-таблицы: hashTable[][0] - ключ (номер рейса), hashTable[][1] - индекс в исходном массиве
    for (int i = 0; i < m; i++) {
        hashTable[i][0] = -1;
        hashTable[i][1] = -1;
    }

    for (int i = 0; i < arr.size(); i++) {
        AEROFLOT& a = arr[i];
        int key = a.flight_number;
        int hash = key % m;
        int i1 = 0;

        while (true) {
            int j = (hash + i1 * i1) % m;
            if (hashTable[j][0] == -1) {
                hashTable[j][0] = key;
                hashTable[j][1] = i;
                break;
            }
            i1++;
        }
    }
}

int searchHashTable(int hashTable[][2], int key) {// Нужна для быстрого поиска индекса рейса по номеру
    int hash = key % m;
    int i1 = 0;
    int j;

    while (true) {
        j = (hash + i1 * i1) % m;
        if (hashTable[j][0] == key) return hashTable[j][1];
        if (hashTable[j][0] == -1) return -1;
        i1++;
    }
}

AEROFLOT readFromBin(ifstream& in, int index) {// Нужна для прямого чтения рейса из бинарного файла по индексу// Использует seekg для позиционирования в файле
    AEROFLOT flight;
    in.seekg(index * sizeof(AEROFLOT));
    in.read((char*)&flight, sizeof(AEROFLOT));
    return flight;
}
/////////////////////////////////////////
int main() {
    Myarr<AEROFLOT> arr; //создание массива
    ifstream in("text.txt"); //открывает и читает данные из текстового файла
    if (!in) {
        cout << "\nne otkryvaetsya\n";
        return 1;
    }

    in >> arr; //загружает рейсы из текстового файла
    cout<<"ishodny:\n\n "<<arr;

    ofstream outbin("a.bin", ios::binary);
    arr.writeBin(outbin);//создает бинарную версию данных
    outbin.close(); //закрывает файл

    int hashTable[m][2];
    createHashTable(hashTable, arr); //создает хеш-таблицу из массива
 cout <<"\n\nhashtable:\n";
  
 cout << "  nomer reisa"<<" |  nomer v massive\n";
    for (int i = 0; i < m; i++) {
       
        cout << i << ": " << hashTable[i][0]<<"                " << hashTable[i][1] << "\n";
    }


    ifstream inbin("a.bin", ios::binary); //открывает бинарный файл
    if (!inbin) {
        cout << "\noshibka otkrytiya failа\n";
        return 1;
    }

    int flightNumber;
    cout << "\nvvedite nomer reisa: ";
    cin >> flightNumber;

    int index = searchHashTable(hashTable, flightNumber);//поиск рейса по номеру через хеш-таблицу
    if (index != -1) {
        AEROFLOT found = readFromBin(inbin, index);
        cout << "naydeny reis:\n";
        cout << found << "\n";
    }
    else {
        cout << "\nreis ne naiden\n";
    }

    inbin.close(); //закрытие файла завершение работы
    return 0;
}