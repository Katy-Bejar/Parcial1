
#include<iostream>
#include <string>
#include <cmath>
//#include<bits/stdc++.h>
#include <ctime> 
#include <random>

using namespace std;

class NodeTerm{
    public:
        long int m_Coeff;
        int m_Exp;
        NodeTerm *m_pNext;
        NodeTerm *m_pPrev;
    public:
        NodeTerm(long int c, int e){
            m_Coeff = c;
            m_Exp = e;
            m_pNext = 0;
            m_pPrev = 0;
        }

        long int calculate(int x){
        return m_Coeff*pow(x,m_Exp);
        }
};

class Polinomy{
public:
    NodeTerm * m_pHead;
	NodeTerm * m_pLast;
public:
    Polinomy(){
        m_pHead = m_pLast = 0;

    }

    void addTermAtLast(long int coeff, int exp)
    {
    //Implementar una funcion que me permita insertar al final del polinomio
        if(!m_pHead){
                m_pHead = new NodeTerm(coeff, exp);
            }
            else {
                NodeTerm* tmp = new NodeTerm(coeff, exp);
                while(tmp->m_pNext != nullptr){
                    tmp = tmp->m_pNext;
                }
                tmp->m_pNext = new NodeTerm(coeff, exp);
                //m_pHead = NodeTerm;
                tmp->m_Coeff = coeff;
                tmp->m_Exp = exp;
            }
    }


    void addTerm(long int coeff, int exp){
    // Implementar una funcion que inserte un nuevo termino en el polinomio de manera ordenanda (el mayor grado va a la izquierda o en la cabeza).
    // Si se tienen dos terminos con el mismo grado, estos se combinan por medio de la adición.

        if(!m_pHead){
            m_pHead = new NodeTerm(coeff, exp); 
        }
        else{
            NodeTerm* tmp = new NodeTerm(coeff, exp); 
            //la cabeza es mas grande
            if(tmp->m_Exp >= m_pHead->m_Exp){
                if(tmp->m_Exp == m_pHead->m_Exp){
                    long int x = tmp->m_Coeff + m_pHead->m_Coeff;
                    m_pHead->m_Coeff = x;
                    delete tmp;
                }
                else{
                    tmp->m_pNext = m_pHead;
                    m_pHead = tmp;
                }
            }

            else if(tmp->m_Exp < m_pHead->m_Exp){
                NodeTerm* tmp2 = m_pHead;
                while(tmp2->m_pNext != nullptr && tmp2->m_pNext->m_Exp > tmp->m_Exp){
                    tmp2 = tmp2->m_pNext;
                }// 4x7 -> 3x3 -> 9x2 -> 
                // 
                // 3x (7)
                if(tmp->m_Exp == tmp2->m_Exp){
                    long int x = tmp->m_Coeff + tmp2->m_Coeff;
                    tmp2->m_Coeff = x;
                    delete tmp;
                }
                else{
                    tmp->m_pNext = tmp2->m_pNext;
                    tmp2->m_pNext = tmp;
                }
            }
        }
    }

    long int calculate(int x){
    // Implementar método que calcula el valor final del polinomio si reemplazamos la variable independiente X.
        long long int y = 0;
        NodeTerm* tmp2 = m_pHead;
        while(tmp2 != nullptr){
            y = y + ((pow(x, tmp2->m_Exp)) * tmp2->m_Coeff);
            tmp2 = tmp2->m_pNext;
        }
        return y;
    }

    Polinomy operate(Polinomy p2){
    // Implementar un método que opera sobre dos polinomios y me genera uno nuevo.
        
    }

    void print()
    {
    NodeTerm * tmp = m_pHead;
    while(tmp!=0)
    {
        cout<<tmp->m_Coeff<<"X^"<<tmp->m_Exp<<" ";
        tmp = tmp->m_pNext;
    }
    cout<<endl;
    }
};


int MINNUMBER = 1;
int MAXNUMBER = 10;
int NUMBER_INSERTIONS = 100;


//Prueba 1: Se evalua si después de varias inserciones el polinomio calcula el valor correcto. (6 puntos)
void Test1(Polinomy p){
    mt19937 mt_coeff(2012);
    mt19937 mt_exp(2016);
    for(int i=0; i < NUMBER_INSERTIONS; i++){
        p.addTerm(MINNUMBER + (mt_coeff()%MAXNUMBER), MINNUMBER +(mt_exp()%MAXNUMBER));
    }

    long int result = 0;
    mt19937 mt_x(2000);
    for(int i=0; i<3; i++){
        int x = MINNUMBER + (mt_x()%MAXNUMBER);
        cout<<"X = "<<x<<endl;
        result = p.calculate(x);
        cout<<"Operation "<<i<<":"<<result<<endl;
    }
}

// Prueba 2: Se comprueba si al hacer varias inserciones sobre 2 polinomios y el reemplezar la variable independiente sobre el resultado de combinar
// estos dos polinomios, el resultado es el correcto. (6 Puntos)
void Test2(Polinomy p1, Polinomy p2){ 
  mt19937 mt_coeff(2012);
  mt19937 mt_exp(2016);
  for(int i=0; i < NUMBER_INSERTIONS; i++){
    p1.addTerm( MINNUMBER + (mt_coeff()%MAXNUMBER), MINNUMBER + (mt_exp()%MAXNUMBER));
    p2.addTerm( MINNUMBER + (mt_coeff()%MAXNUMBER), MINNUMBER + (mt_exp()%MAXNUMBER));
  }

  Polinomy p3 = p1.operate(p2);

  p3.print();
  long  result = 0;
  mt19937 mt_x(2000);
  for(int i=0; i<3; i++){
    int x = MINNUMBER + (mt_x()%MAXNUMBER);
    cout<<"X = "<<x<<endl;
    result = p3.calculate(x);
    cout<<"Operation "<<i<<":"<<result<<endl;
  }
}

int main()
{
    Polinomy p1, p2, p3;
    cout<<"Test 1"<<endl;
    Test1(p1);
    cout<<"Test 2"<<endl;
    Test2(p2,p3);

    return 1;
}