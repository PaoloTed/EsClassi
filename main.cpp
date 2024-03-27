#include <iostream>

class A {
public:
    void funz1() { std::cout << "funz1 A" << std::endl; }//metodo normale della classe A

    virtual void funz2() { std::cout << "funz2 A" << std::endl; }//posso ridefinire

    virtual void funz3() final { std::cout << "funz3 A" << std::endl; }//non posso ridefinire


};

class B : public A {
public:
    void funz1() { std::cout << "funz1 B" << std::endl; } //non un override ma un oscuramento

    void funz2() override { std::cout << "funz2 B" << std::endl; }//override classico

    //void funz3() { std::cout << "funz3 B" << std::endl; } essendo final non posso ridefinire

    void funz4() { std::cout << "funz4 B" << std::endl; }//metodo aggiunto

};

int main() {
    B b;
    b.funz1();//chiama la funzione della classe B
    b.funz2();//chiama la funzione della classe B
    b.funz3();//chiama la funzione della classe A
    b.funz4();//chiama la funzione della classe B
    std::cout << std::endl;

    A a1;
    a1.funz1();//chiama la funzione della classe A
    a1.funz2();//chiama la funzione della classe A
    a1.funz3();//chiama la funzione della classe A
    //a1.funz4(); non posso chiamare un metodo della classe B
    std::cout << std::endl;

    A a2 = b;
    a2.funz1();//chiama la funzione della classe A
    a2.funz2();//chiama la funzione della classe A
    a2.funz3();//chiama la funzione della classe A
    //a2.funz4(); non posso chiamare un metodo della classe B

    A *pointerA = &b;
    pointerA->funz1();//chiama la funzione della classe A
    pointerA->funz2();//chiama la funzione della classe B essendo un puntatore alla classe A e funz2 + virtual
    pointerA->funz3();//chiama la funzione della classe A
    //pointerA->funz4(); non posso chiamare un metodo della classe B

    //Il motivo per cui un puntatore alla classe `A` con un riferimento a un oggetto della classe `B`
    //non può accedere a `funz4` è perché `funz4` non è un membro della classe `A`.
    //In C++, quando un puntatore della classe base punta a un oggetto della classe derivata,
    //può accedere solo ai metodi presenti nella classe base, non a quelli esclusivi della classe derivata.
    //Questo perché la classe base non ha informazioni sui metodi o membri aggiunti nella classe derivata.
    //In questo caso, `funz4` è un metodo della classe `B` e non della classe `A`.
    //Pertanto, un puntatore di tipo `A` non può accedere a `funz4`, anche se punta a un oggetto della classe `B`.
    //Il puntatore della classe base può essere utilizzato per chiamare metodi sovrascritti nella classe derivata,
    //ma non può accedere ai metodi che esistono solo nella classe derivata.
    std::cout << std::endl;
    return 0;
}
