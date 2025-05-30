//////����� ��� �������� � ��������� ������ �� ����������///////
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
    /////���������//////////////////////////////////////
    char destination[20] = "";                          // ����� ����������
    int flight_number = 0;                              // ����� �����
    char paircraft_type[10] = "";                       // ��� ��������
    /////������������///////////////////////////////////
    AEROFLOT();                                                  // ����������� �� ��������� �������� ����
    AEROFLOT(const char* n, int f, const char* p);               // ��������
    AEROFLOT(const AEROFLOT& m);                                 // ����������� �����������
    /////������ ���������///////////////////////////////
    static bool compNumber(AEROFLOT& a, AEROFLOT& b);       // ��������� �� ������
    static bool compDestination(AEROFLOT& a, AEROFLOT& b);  // ��������� �� ������
    bool operator==(const AEROFLOT& w) const;               // �������� ��������� // �������� ��������� ���� �����
    bool operator<(const AEROFLOT& m);                      // �������� ������
    bool operator>(const AEROFLOT& m);                      // �������� ������
    
   /////��������� �����/������/////////////////////////
    friend ostream& operator<<(ostream& os, const AEROFLOT& m);     // �����
    friend istream& operator>>(istream& is, AEROFLOT& m);           // ���� // ������ �� ������
  
};