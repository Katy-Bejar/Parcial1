#include<iostream>
#include <string>
#include<bits/stdc++.h>
#include <ctime> 
#include <tuple>
#include <random>


using namespace std;

class EmptyStack : public runtime_error {
    public:
        EmptyStack(const string& msg = "") : runtime_error(msg) {}
};

template <class T>
class Node{
    public:
        T m_Data;
        Node<T> *m_pNext;
    public:
        Node(T d){
        m_Data = d;
        m_pNext = 0;
        }
};

template <class T>
class Stack{
    public:
        Node<T> * m_pTop;
    public:
        Stack(){
            m_pTop = 0;
        }

        void push(T d){
            Node<T> *pNew = new Node<T>(d);
            if (!m_pTop){
                m_pTop = pNew;
            } else {
                pNew->m_pNext = m_pTop;
                m_pTop = pNew;
            }
        }

        T pop(){
            if (!m_pTop){
                throw EmptyStack("No hay elementos");
            }
            Node<T> *tmp = m_pTop;
            m_pTop = tmp->m_pNext;
            T data = tmp->m_Data;
            delete(tmp);
            return data;
        }

        T top(){
            if (!m_pTop){
                throw EmptyStack("No hay elementos");
            }
            return m_pTop->m_Data;
        }

        bool isEmpty(){
            return m_pTop == 0;
        }

        void print(){
            Node<T> * tmp = m_pTop;
            while(tmp!=0){
                cout<<tmp->m_Data<<" ";
                tmp = tmp->m_pNext;
            }
            cout<<endl;
        }
};

class Point{
    public:
        float m_X;
        float m_Y; 
        float m_Z;
    public:
        Point(){
            m_X = m_Y = m_Z = 0.0;
        }
        Point(float x, float y, float z){
            m_X = x;
            m_Y = y;
            m_Z = z;
        }

        float distance(Point p2){
            // Implementar la funcion distancia euclidiana
        }

        friend ostream& operator<<(ostream& os, const Point& p)
        {
            os << "("<<p.m_X<<", "<<p.m_Y<<", "<<p.m_Z<<")";
            return os;
        }

};

class PointStack{
    public:
        Point m_Point;
        bool (*m_compFunc) (Point, Point, Point);
        Stack<Point> m_S;
        Stack<Point> m_auxS;
    public:
        PointStack(){
            m_compFunc = 0;
        }
        PointStack(Point p, bool (*compFunc) (Point, Point, Point)){
            m_Point = p;
            m_compFunc = compFunc;
        }

        void push(float x, float y, float z){
        // Implmentar un push a nuestras pilas

        }

        bool isEmpty(){
            return m_S.isEmpty();
        }

        tuple<Point, Point>  pop(){
            // Pueden cambiar a voluntad esta funcion 
            // en el caso de no cambiarlo, una tupla puede ser evaluada usando get<index>(variable tuple), por ejemplo:
            // tuple<point, point> mytuple= make_tuple(p1, p2), donde,
            // get<0>(mytuple) me irá a retornar el valor de p1
            return make_tuple(m_S.pop(), m_auxS.pop());
        }

        float meanDistanceFromN(int n){
            // Implementar una funcion que me determina la diferencia en la distancia promedio de los n ultimos elementos
            // (hacer push de n elementos) y el top de la pila auxiliar después de haber sacado estos n elementos.
            // La diferencia es un valor absoluto. 
        }

        void print(){
            cout<<"S:"<<endl;
            m_S.print();
            cout<<"Aux S"<<endl;
            m_auxS.print();
        }
};

// Implementar 2 funciones extras para determinar si son cercanos o lejanos los puntos en relación a un punto de referencia.
//bool func1(Point pref, Point p1, Point p2)
//bool func2(Point pref, Point p1, Point p2)
void cercanos(){

}

void lejanos(){
    
}
int MINNUMBER = 1;
int MAXNUMBER = 10;

int NUMBER_POP = 8;
int NUMBER_INSERTIONS = NUMBER_POP*10;


// Prueba 3: Evalua si se implementó dos instancias  para almacenar los puntos mas cercanos y mas distances.
// 8 Puntos  (4 si es correcto para puntos cercanos y 4.5 para mas distantes)

void test(PointStack points, bool (*func)(Point, Point, Point)){
  mt19937 mt_x(2012);
  mt19937 mt_y(2016);
  mt19937 mt_z(2018);

  float x = MINNUMBER + (mt_x()%MAXNUMBER);
  float y = MINNUMBER + (mt_y()%MAXNUMBER);
  float z = MINNUMBER + (mt_z()%MAXNUMBER);

  Point mainPoint(x,y,z);
  points = PointStack(mainPoint, func);


  for(int i=0; i<NUMBER_INSERTIONS; i++)
  {
    float x = MINNUMBER + (mt_x()%MAXNUMBER);
    float y = MINNUMBER + (mt_y()%MAXNUMBER);
    float z = MINNUMBER + (mt_z()%MAXNUMBER);

    points.push(x,y,z);
  }
  
  for(int i = 0; i < 3; i++){
    cout<<"Test "<<i<<":"<<endl;
    cout<<points.meanDistanceFromN(NUMBER_POP)<<endl;
  }
}

int main()
{
    cout<<"_____Min Points___"<<endl;
    PointStack pmin;
    test(pmin, TU_FUNCION);

    cout<<"_____Max Points____"<<endl;
    PointStack pmax;
    test(pmax, TU_FUNCION);
    
    return 1;
}
