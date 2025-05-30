//////Класс для хранения и обработки данных об авиарейсах///////
#pragma once
#include <iostream>
#include <fstream>
#include <ios>
#include <cstring>
#include <string.h>
using namespace std;

const int a = 7; 
class AEROFLOT 
{
public: 
    /////Структура//////////////////////////////////////
    char destination[20] = "";                          // Пункт назначения
    int flight_number = 0;                              // Номер рейса
    char paircraft_type[10] = "";                       // Тип самолета
    /////Конструкторы///////////////////////////////////
    AEROFLOT();                                                  // Конструктор по умолчанию обнуляет поля
    AEROFLOT(const char* n, int f, const char* p);               // Параметр
    AEROFLOT(const AEROFLOT& m);                                 // Конструктор копирования
    /////Методы сравнения///////////////////////////////
    static bool compNumber(AEROFLOT& a, AEROFLOT& b);       // Сравнение по номеру
    static bool compDestination(AEROFLOT& a, AEROFLOT& b);  // Сравнение по пункту
    bool operator==(const AEROFLOT& w) const;               // Оператор равенства // Проверка равенства всех полей
    bool operator<(const AEROFLOT& m);                      // Оператор меньше
    bool operator>(const AEROFLOT& m);                      // Оператор больше
    
   /////Операторы ввода/вывода/////////////////////////
    friend ostream& operator<<(ostream& os, const AEROFLOT& m);     // Вывод
    friend istream& operator>>(istream& is, AEROFLOT& m);           // Ввод // Чтение из потока
  
};
