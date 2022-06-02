#ifndef POLY_POLY_H_16122021
#define POLY_POLY_H_16122021
#include<iosfwd>
#include<string>
#include<sstream>
//! \class Poly poly.h poly/poly.h
//! \brief класс полином
class Poly
{
private:
    int rank=0; //!< размер массива(число элементов)
    double* element; //!< данные об коэффициентах полинома
public:
    //! \brief умолчательный конструктор
    //! создает массив с одним элементом
    Poly();

    //! \brief конструктор для создания полинома
    //! \param[in] rank - количество элементов полинома
    //! \paran[in] double element[] - данные о коэффициентах
    Poly(int rank, double element[]);

    //! \brief конструкстор для создания полинома с нулевыми коеффициентами
    //! \post все элементы инициализируются нулем
    //! \param[in] rank - количество элементов полинома
    Poly(int rank);

    //! \brief конструктор копирования
    Poly(const Poly& lhs);

    //! \brief деструктор
    ~Poly() = default;

    //! \brief метод для изменения размера массива коэффициентов
    //! \pre изменить можно только в большую сторону
    //! \param[in] new_rank - размер нового массива
    void ChangeRank(int new_rank);

    //! \brief Получание степени полинома
    int GetRank();

    //! \brief Возведение полинома в степень
    //! \throws std::invalid_argiment - при попытке возведения в отрицательную степень
    //! \param[in] - степень возведения
    void GradeUp(int grade);

    //! \brief Оптимизация длинны массива при операциях
    //! 
    //! Оптимизирует длину массива до первой ненулевой старшей степени
    void Optimize();

    //! \brief Вывод корней уравнения
    //! 
    //! Вывод корней в качестве разложения на множители
    //! 
    //! При отстутствии корней выводится исходный многочлен
    void PrintSolve();

    //! \brief Перегруженный оператор ==
    bool operator==(const Poly& rhs) const ;

    //! \brief Сложение многочлена с многочленом
    Poly operator+=(const Poly& lhs)noexcept;

    //! \brief Вычитание многочлена из многочлена
    Poly operator-=(const Poly& lhs)noexcept;

    //! \brief Умножение многочлена на многочлен
    Poly operator*=(const Poly& lhs)noexcept;

    //! \brief Деление многочлена на многочлен
    //! 
    //! В качестве частного выступает целая часть от деления
    Poly operator/=(const Poly& lhs) noexcept;

    //! \brief Оператор присваивания
    Poly operator= (const Poly& lhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);
};

//! \brief Сложение многочлена с многочленом
Poly operator+(const Poly& lhs, const Poly& rhs)noexcept;

//! \brief Вычитание многочлена из многочлена
Poly operator-(const Poly& lhs, const Poly& rhs)noexcept;

//! \brief Умножение многочлена на многочлен
Poly operator*(const Poly& lhs, const Poly& rhs)noexcept;

//! \brief Оператор деления многочленов
Poly operator/(const Poly& lhs, const Poly& rhs)noexcept;

//! \brief Форматорованный вывод из потока ostrm полинома
//! Poly::writeTo
std::ostream& operator << (std::ostream& a, const Poly& temp);

//! \brief Форматорованный ввод из потока istrm полинома
//! Poly::readFrom
std::istream& operator >> (std::istream& istrm, Poly& temp);
#endif
