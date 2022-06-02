#include<poly/poly.h>
#include<iostream>
#include<sstream>
#include<cmath>
#include<stdexcept>
using namespace std;
std::ostream& Poly::writeTo(std::ostream& ostrm) const
{
    if (rank == 1 && element[0] == 0)
        ostrm << 0;
    else
    for (int i = rank-1; i >= 0; i--)
    {
        if (element[i] == 0) continue;
        else if (i == 0)
        {
            if (element[i] > 0) ostrm << "+" << element[i];
            else ostrm << element[i];
        }
        else if (i == 1)
        {
            if (element[i] > 0) ostrm << "+" << element[i] << "X";
            else ostrm << element[i] << "X";
        }
        else if (i > 1)
        {
            if (element[i] > 0) ostrm << "+" << element[i] << "X^" << i;
            else ostrm << element[i] << "X^" << i;
        }
    }
    ostrm << endl;
    return ostrm;      
}
std::ostream& operator<<(ostream& ostrm, const Poly& temp)
{
    return temp.writeTo(ostrm);
}
std::istream& Poly::readFrom(std::istream& istrm)
{
    int pow;
    std::cout << "Stepen -> ";
    istrm >> pow;
    element = new double[pow + 1];
    rank = pow + 1;
    for (int i = pow; i >= 0; i--)
    {
        std::cout << i << "-àya stepen -> ";
        istrm >> element[i];
    }
    return istrm;
}
std::istream& operator >> (istream& istrm, Poly& temp)
{
    return temp.readFrom(istrm);
}
// Mthods
Poly::Poly(int rank_, double element_[])
{
    rank = rank_;
    element = new double[rank];
    for (int i = 0; i < rank; i++)
    {
        element[i] = element_[i];
    }
}
Poly::Poly(int rank_)
{
    rank = rank_;
    element = new double[rank];
    for (int i = 0; i < rank; i++)
    {
        element[i] = 0;
    }
}
Poly::Poly(const Poly& lhs)
{
    element = new double[lhs.rank];
    for (int i = 0; i < lhs.rank; i++)
        element[i] = lhs.element[i];
    rank = lhs.rank;
}
Poly::Poly()
{
    rank = 1;
    element = new double[1];
    element[0] = 0;
}
void Poly::ChangeRank(int new_rank)
{
    if (new_rank > rank)
    {
        double* mem = new double[new_rank];
        for (int i = 0; i < rank; i++)
            mem[i] = element[i];
        for (int i = rank; i < new_rank; i++)
            mem[i] = 0;
        delete[] element;
        element = mem;
        rank = new_rank;
    }
}
void Poly::Optimize()
{
    int new_rank=0;
    for (int i = rank - 1; i >= 0; i--)
    {
        if (element[i] != 0)
        {
            new_rank = i + 1;
            break;
        }
    }
    double* mem = new double[new_rank];
    for (int i = 0; i < new_rank; i++)
        mem[i] = element[i];
    delete[] element;
    element = mem;
    rank = new_rank;   
}
int Poly::GetRank()
{
    return rank - 1;
}
void Poly::GradeUp(int grade)
{
    if (grade >= 1)
    {
        Poly mem;
        mem = *this;
        for (int i = 2; i <= grade; i++)
        {
            *this = *this * mem;
        }
    }
    else if (grade == 0)
    {
        Poly mem = Poly();
        *this = mem;
    }
    else
        throw std::invalid_argument("Degree < 0");
}
void Poly::PrintSolve()
{
    Poly temp = *this;
    Poly rout(2);
    while (temp.rank > 3)
    {
        bool pass = false;
        double tmp = 0;
        for (int i = -100; i <= 100; i++)
        {
            double sum = 0;
            for (int j = temp.rank - 1; j >= 0; j--)
            {
                sum += temp.element[j] * pow(i, j);
            }
            if (sum == 0)
            {
                tmp = i;
                pass = true;
                break;
            }
        }
        if (pass == false)
            break;
        else if (pass)
        {
            std::cout << "(X-(" << tmp << "))";
            rout.element[1] = 1; rout.element[0] = -tmp;
            temp /= rout;
        }       
    }
    if (temp.rank > 3)
        std::cout << "(" << temp << ")";
    else if (temp.rank == 3)
    {
        double a1, a2, d;
        d = temp.element[1] * temp.element[1] - 4 * temp.element[0] * temp.element[2];
        if (d < 0)
            std::cout << "(" << temp << ")";
        else
        {
            a1 = (-temp.element[1] - sqrt(d)) / 2 / temp.element[2];
            a2 = (-temp.element[1] + sqrt(d)) / 2 / temp.element[2];
            std::cout << "(X-(" << a1 << "))";
            std::cout << "(X-(" << a2 << "))";
        }
    }
    else if (rank == 2)
    {
        std::cout << "X = " << -temp.element[0] / temp.element[1];
    }
    else if (rank == 1)
        std::cout << "X -> R";
}
//Operations
Poly Poly::operator+=(const Poly& lhs) noexcept
{
    if (rank >= lhs.rank)
    {
        for (int i = 0; i < lhs.rank; i++)
            element[i] += lhs.element[i];
    }
    else
    {
        ChangeRank(lhs.rank);
        for (int i = 0; i < lhs.rank; i++)
            element[i] += lhs.element[i];
    }
    Optimize();
    return *this;
}
Poly Poly::operator-=(const Poly& lhs) noexcept
{
    if (rank >= lhs.rank)
    {
        for (int i = 0; i < lhs.rank; i++)
            element[i] -= lhs.element[i];
    }
    else
    {
        ChangeRank(lhs.rank);
        for (int i = 0; i < lhs.rank; i++)
            element[i] -= lhs.element[i];
    }
    Optimize();
    return *this;
}

Poly Poly ::operator*=(const Poly& lhs)noexcept
{
    if (lhs.rank == 1 && lhs.element[0] == 0)
    {
        Poly nul(1);
        *this = nul;
        return *this;
    }
    double mem;
    double* temp = new double[rank + lhs.rank-1];
    for (int i = 0; i < rank + lhs.rank-1; i++)
        temp[i] = 0;
    for (int i = rank - 1; i >= 0; i--)
    {
        for (int j = lhs.rank - 1; j >= 0; j--)
        {
            mem = lhs.element[j] * element[i];
            temp[i + j] += mem;
        }
    }
    delete[] element;
    element = temp;
    rank = rank + lhs.rank-1;
    Optimize();
    return *this;
}
Poly Poly::operator/=(const Poly& lhs) noexcept
{
    if (rank < lhs.rank)
    {
        Poly nul(1); *this = nul; return *this;
    }
    else
    {
        Poly temp = *this;
        int rrank = temp.rank - lhs.rank + 1;
        Poly res(rrank);
        for (int i = 0; i < rrank; i++) {
            res.element[rrank - i - 1] = temp.element[temp.rank - i - 1] / lhs.element[lhs.rank - 1];
            for (int j = 0; j < lhs.rank; j++) {
                temp.element[temp.rank - j - i - 1] -= lhs.element[lhs.rank - j - 1] * res.element[rrank - i - 1];
            }
        }
        *this = res;
        Optimize();
        return *this;
    }
}
Poly operator+(const Poly& lhs, const Poly& rhs)noexcept
{
    Poly sum(lhs);
    sum += rhs;
    return sum;
}
Poly operator-(const Poly& lhs, const Poly& rhs)noexcept
{
    Poly mines(lhs);
    mines -= rhs;
    return mines;
}
Poly operator*(const Poly& lhs, const Poly& rhs)noexcept
{
    Poly multiply(lhs);
    multiply *= rhs;
    return multiply;
}
Poly operator/(const Poly& lhs, const Poly& rhs)noexcept
{
    Poly diff(lhs);
    diff /= rhs;
    return diff;
}
Poly Poly::operator=(const Poly& lhs)
{
    rank = lhs.rank;
    element = new double[rank];
    for (int i = 0; i < rank; i++)
    {
        element[i] = lhs.element[i];
    }
    return *this;
}
bool Poly::operator==(const Poly& lhs) const
{
    bool p = true;
    if (rank == lhs.rank)
    {
        if (sizeof(element) == sizeof(lhs.element))
        {
            for (int i = 0; i < rank; i++)
                if (element[i] != lhs.element[i])
                {
                    p = false;
                    break;
                }
                    
        }
    }
    if (rank == lhs.rank && p == true) return true;
    else return false;
}
