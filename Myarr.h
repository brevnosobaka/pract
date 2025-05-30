//Шаблонный класс для работы с динамическими массивами
#pragma once
#include<fstream>
using namespace std;

template <class T>
class Myarr
{
private:
	/////Поля класса/////определяют состояние объекта и хранят информацию, которая характеризует экземпляр класса(у меня номер рейса, тип самолета, пункт нзначения)
	T* arr;		// Указатель на массив элементов типа T
	int n;		// Текущий размер массива
public:

	//Конструкторы и деструктор////////////////////
	Myarr();	//по умолчанию
	Myarr(int n);	//конструктор с параметром
	Myarr(const Myarr& a);	//конструктор копирования
	~Myarr();//деструктор
	//перегрузки//
	Myarr<T>& operator=(const Myarr<T>& a);
	friend ostream& operator<<(ostream& os, const Myarr<T> a) {//Перегрузка оператора вывода для печати всего массива
		for (int i = 0; i < a.n; i++)
			os << a[i] << "\n ";
		return os;
	} 
	friend istream& operator>>(istream& os, Myarr<T>& a) {//Перегрузка оператора ввода для чтения массива из потока.
		int n;
		os >> n;
		a.n = n;
		a.arr = new T[n];
		for (int i = 0; i < a.n; i++)
			os >> a[i];
		return os;
	}
	///Методы доступа////
	int size() const //геттер.Возвращает количество элементов в массиве(n). Позволяет безопасно получить размер массива вне класса
	{ 
		return n; }
	T& operator[](int i);// Нужен для доступа к элементу с проверкой границ
	T& operator[](int i) const; //Константная версия оператора доступа к элементам массива.

	
	///Методы работы с файлами///
	void writeBin(ofstream& os);// Нужен для бинарной записи всего массива в файл
	void readBin(ifstream& os);// Нужен для чтения массива из бинарного файла
	
};

template<class T>
inline Myarr<T>::Myarr()
{
	n = 0;
	arr = nullptr;
}

template<class T>
inline Myarr<T>::Myarr(int n)
{
	this->n = n;
	arr = new T[this->n];
}

template<class T>
inline Myarr<T>::Myarr(const Myarr& a)
{
	this->n = a.n; 
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = a.arr[i];
}

template<class T>
inline Myarr<T>& Myarr<T>::operator=(const Myarr<T>& a)
{
	delete[]arr;
	this->n = a.n; 
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = a.arr[i];
	return*this;
}

template<class T>
inline T& Myarr<T>::operator[](int i)
{
	if (i >= n)throw "index error";
	return arr[i];
}

template<class T>
inline T& Myarr<T>::operator[](int i) const
{
	if (i < 0 || (i >= n))throw "index error";
	return arr[i];
}

template<class T>
inline void Myarr<T>::writeBin(ofstream& os)
{
	os.write((char*)arr, sizeof(T) * n);
	os.close();
}

template<class T>
inline void Myarr<T>::readBin(ifstream& os)
{
	os.seekg(0, os.end);
	int n = os.tellg() / sizeof(T);
	delete[]arr;
	arr = new T[n];
	this->n = n;
	os.seekg(0, os.beg);
	os.read((char*)arr, sizeof(T) * n);
	os.close();
}

template<class T>
inline Myarr<T>::~Myarr()
{
	delete[]arr;
	n = 0;
	arr = nullptr;
}
